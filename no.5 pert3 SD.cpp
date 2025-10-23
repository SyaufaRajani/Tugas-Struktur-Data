#include <stdio.h>
#include <string.h>
#include <stdbool.h>
typedef struct {
    int no_akses;
    char judul[100];
    char penulis[50];
    bool diterbitkan; 
    int jumlah_stok;  
} Buku;
#define MAX_JENIS_BUKU 10
Buku perpustakaan[MAX_JENIS_BUKU];
int count_jenis_buku = 0; 
void tampilkanMenu();
void tampilkanInfoBuku();
void tambahBuku();
void tampilkanBukuOlehPenulis();
void tampilkanJumlahJudul();
void tampilkanTotalBuku();
void terbitkanBuku();
void tampilkanTotalBuku() {
    int total = 0;
    for (int i = 0; i < count_jenis_buku; i++) {
        total += perpustakaan[i].jumlah_stok;
    }
    printf("\n[INFO] Jumlah total buku (stok fisik) di perpustakaan: %d\n", total);
}
void tampilkanInfoBuku() {
    int no_cari;
    printf("\n--- Tampilkan Info Buku ---\n");
    printf("Masukkan Nomor Akses buku: ");
    if (scanf("%d", &no_cari) != 1) {
        printf("[ERROR] Input tidak valid.\n");
        while (getchar() != '\n');
        return;
    }
    for (int i = 0; i < count_jenis_buku; i++) {
        if (perpustakaan[i].no_akses == no_cari) {
            printf("\nDetail Buku:\n");
            printf("  Nomor Akses: %d\n", perpustakaan[i].no_akses);
            printf("  Judul: %s\n", perpustakaan[i].judul);
            printf("  Penulis: %s\n", perpustakaan[i].penulis);
            printf("  Stok Tersedia: %d\n", perpustakaan[i].jumlah_stok);
            printf("  Status: %s\n", perpustakaan[i].diterbitkan ? "Sudah Diterbitkan (Pinjaman)" : "Tersedia");
            return;
        }
    }
    printf("[INFO] Buku dengan Nomor Akses %d tidak ditemukan.\n", no_cari);
}
void tambahBuku() {
    int no_cari;
    int stok_tambah;
    printf("\n--- Tambah Buku Baru/Stok ---\n");
    printf("Masukkan Nomor Akses buku yang akan ditambahkan: ");
    if (scanf("%d", &no_cari) != 1) {
        printf("[ERROR] Input tidak valid.\n");
        while (getchar() != '\n');
        return;
    }
    for (int i = 0; i < count_jenis_buku; i++) {
        if (perpustakaan[i].no_akses == no_cari) {
            printf("Masukkan jumlah stok yang ditambahkan: ");
            if (scanf("%d", &stok_tambah) != 1 || stok_tambah <= 0) {
                 printf("[ERROR] Jumlah stok tidak valid.\n");
                 while (getchar() != '\n');
                 return;
            }
            perpustakaan[i].jumlah_stok += stok_tambah;
            printf("[SUKSES] Stok buku '%s' bertambah %d. Total stok: %d\n",
                   perpustakaan[i].judul, stok_tambah, perpustakaan[i].jumlah_stok);
            return;
        }
    }
    
    // Jika belum ada, masukkan detail buku baru
    if (count_jenis_buku >= MAX_JENIS_BUKU) {
        printf("[ERROR] Kapasitas jenis buku unik sudah penuh!\n");
        return;
    }
    
    Buku *buku_baru = &perpustakaan[count_jenis_buku];
    buku_baru->no_akses = no_cari;
    
    printf("--- Input Detail Buku Baru ---\n");
    while (getchar() != '\n'); // Membersihkan buffer
    
    printf("Judul Buku: "); fgets(buku_baru->judul, sizeof(buku_baru->judul), stdin);
    buku_baru->judul[strcspn(buku_baru->judul, "\n")] = 0;

    printf("Nama Penulis: "); fgets(buku_baru->penulis, sizeof(buku_baru->penulis), stdin);
    buku_baru->penulis[strcspn(buku_baru->penulis, "\n")] = 0;

    printf("Jumlah Stok Awal: "); 
    if (scanf("%d", &buku_baru->jumlah_stok) != 1 || buku_baru->jumlah_stok <= 0) {
        printf("[ERROR] Jumlah stok tidak valid. Pembatalan penambahan buku.\n");
        return;
    }
    
    buku_baru->diterbitkan = false; // Status awal: Tersedia
    count_jenis_buku++;
    printf("[SUKSES] Buku unik baru berhasil ditambahkan.\n");
}

// 3. Tampilkan semua buku oleh penulis tertentu
void tampilkanBukuOlehPenulis() {
    char penulis_cari[50];
    int ditemukan = 0;
    
    printf("\n--- Cari Buku Oleh Penulis ---\n");
    while (getchar() != '\n'); // Membersihkan buffer
    printf("Masukkan Nama Penulis: ");
    fgets(penulis_cari, sizeof(penulis_cari), stdin);
    penulis_cari[strcspn(penulis_cari, "\n")] = 0;

    printf("\nDaftar Buku oleh '%s':\n", penulis_cari);
    for (int i = 0; i < count_jenis_buku; i++) {
        if (strcasecmp(perpustakaan[i].penulis, penulis_cari) == 0) { // strcasecmp untuk case-insensitive
            printf("  - %s (No. Akses: %d, Stok: %d)\n", perpustakaan[i].judul, perpustakaan[i].no_akses, perpustakaan[i].jumlah_stok);
            ditemukan++;
        }
    }

    if (ditemukan == 0) {
        printf("[INFO] Tidak ada buku ditemukan oleh penulis tersebut.\n");
    }
}

// 4. Menampilkan jumlah buku dengan judul tertentu
void tampilkanJumlahJudul() {
    char judul_cari[100];
    int jumlah_stok = 0;
    
    printf("\n--- Hitung Stok Berdasarkan Judul ---\n");
    while (getchar() != '\n'); // Membersihkan buffer
    printf("Masukkan Judul Buku: ");
    fgets(judul_cari, sizeof(judul_cari), stdin);
    judul_cari[strcspn(judul_cari, "\n")] = 0;
    
    for (int i = 0; i < count_jenis_buku; i++) {
        if (strcasecmp(perpustakaan[i].judul, judul_cari) == 0) {
            jumlah_stok = perpustakaan[i].jumlah_stok;
            printf("\n[INFO] Jumlah stok buku dengan judul '%s' adalah: %d\n", judul_cari, jumlah_stok);
            return;
        }
    }
    
    printf("[INFO] Buku dengan judul '%s' tidak ditemukan.\n", judul_cari);
}

void terbitkanBuku() {
    int no_cari;
    printf("\n--- Terbitkan Buku (Pinjam) ---\n");
    printf("Masukkan Nomor Akses buku yang akan diterbitkan: ");
    if (scanf("%d", &no_cari) != 1) {
        printf("[ERROR] Input tidak valid.\n");
        while (getchar() != '\n');
        return;
    }
    for (int i = 0; i < count_jenis_buku; i++) {
        if (perpustakaan[i].no_akses == no_cari) {
            if (perpustakaan[i].jumlah_stok > 0) {
                perpustakaan[i].jumlah_stok--; 
                perpustakaan[i].diterbitkan = true; 
                printf("[SUKSES] Buku '%s' berhasil diterbitkan/dipinjam. Stok tersisa: %d\n",
                       perpustakaan[i].judul, perpustakaan[i].jumlah_stok);
                return;
            } else {
                printf("[ERROR] Stok buku '%s' habis (0).\n", perpustakaan[i].judul);
                return;
            }
        }
    }
    printf("[INFO] Buku dengan Nomor Akses %d tidak ditemukan.\n", no_cari);
}
void tampilkanMenu() {
    printf("\n===================================\n");
    printf("   SISTEM MANAJEMEN PERPUSTAKAAN\n");
    printf("===================================\n");
    printf("1 - Menampilkan informasi buku (No. Akses)\n");
    printf("2 - Tambahkan buku baru/stok (Jumlah bertambah 1)\n");
    printf("3 - Tampilkan semua buku oleh penulis tertentu\n");
    printf("4 - Menampilkan jumlah buku dengan judul tertentu\n");
    printf("5 - Menampilkan jumlah total buku di perpustakaan\n");
    printf("6 - Terbitkan buku (Jumlah berkurang 1)\n");
    printf("0 - Keluar\n");
    printf("-----------------------------------\n");
}

int main() {
    int pilihan;

    do {
        tampilkanMenu();
        printf("Pilih opsi (0-6): ");
        if (scanf("%d", &pilihan) != 1) {
            printf("[ERROR] Pilihan tidak valid. Coba lagi.\n");
            while (getchar() != '\n');
            pilihan = -1;
            continue;
        }

        switch (pilihan) {
            case 1: tampilkanInfoBuku(); break;
            case 2: tambahBuku(); break;
            case 3: tampilkanBukuOlehPenulis(); break;
            case 4: tampilkanJumlahJudul(); break;
            case 5: tampilkanTotalBuku(); break;
            case 6: terbitkanBuku(); break;
            case 0: printf("\nProgram Selesai. Terima kasih.\n"); break;
            default: printf("[ERROR] Pilihan tidak ada dalam menu.\n");
        }
    } while (pilihan != 0);

    return 0;
}
