#include <stdbool.h> 
#include <stdio.h>   #include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

// Struktur ultra-singkat
typedef struct {int n; char jd[50], pn[30]; bool t; int s;} B; // s=stok

#define M 5 // Batas jenis buku

B L[M];
int C = 0; // Count

int eq(const char *s1, const char *s2) { // Case-insensitive compare
    if (strlen(s1) != strlen(s2)) return 0;
    for (int i = 0; s1[i]; i++) if (tolower(s1[i]) != tolower(s2[i])) return 0;
    return 1;
}

int main() {
    int p, i, n_c, s_t, f;
    char s_c[50];
    do {
        printf("\n-M-\n1.Info\n2.Tmb(+1)\n3.Penulis\n4.Hitung Judul\n5.Total\n6.Terbit(-1)\n0.Keluar\n> ");
        if (scanf("%d", &p) != 1) {while (getchar() != '\n'); p = -1; continue;}

        if (p == 1) { // Info (Nomor Akses)
            printf("No: "); if (scanf("%d", &n_c) != 1) {continue;}
            for(i=0; i<C; i++) if(L[i].n == n_c) {
                printf("Jd:%s, Pn:%s, St:%d, Trbt:%s\n", L[i].jd, L[i].pn, L[i].s, L[i].t ? "Ya" : "Tdk"); return 0;
            }
            printf("[!] Tdk ditemukan.\n");
        } 
        else if (p == 2) { // Tambah Buku (+1)
            printf("No: "); if (scanf("%d", &n_c) != 1) {continue;}
            for(i=0; i<C; i++) if(L[i].n == n_c) { // Tambah stok jika ada
                printf("Stok: "); if (scanf("%d", &s_t) == 1 && s_t > 0) L[i].s += s_t; else {printf("[!] Stok inv.\n");} return 0;
            }
            if (C < M) { // Tambah jenis baru
                B *b = &L[C]; b->n=n_c; while(getchar()!='\n');
                printf("Judul: "); fgets(b->jd, 50, stdin); b->jd[strcspn(b->jd, "\n")] = 0;
                printf("Penulis: "); fgets(b->pn, 30, stdin); b->pn[strcspn(b->pn, "\n")] = 0;
                printf("Stok Awal: "); if (scanf("%d", &b->s) == 1 && b->s > 0) { b->t=false; C++; printf("[+] OK.\n"); } else {printf("[!] Stok inv. Batal.\n");}
            } else {printf("[!] Penuh.\n");}
        } 
        else if (p == 3) { // Tampilkan oleh Penulis
            f=0; printf("Penulis: "); while(getchar()!='\n'); fgets(s_c, 50, stdin); s_c[strcspn(s_c, "\n")] = 0;
            for(i=0; i<C; i++) if(eq(L[i].pn, s_c)) {
                printf("- %s (Stok: %d)\n", L[i].jd, L[i].s); f=1;
            }
            if (!f) printf("[!] Tdk ada.\n");
        }
        else if (p == 4) { // Hitung Judul
            printf("Judul: "); while(getchar()!='\n'); fgets(s_c, 50, stdin); s_c[strcspn(s_c, "\n")] = 0;
            for(i=0; i<C; i++) if(eq(L[i].jd, s_c)) {
                printf("[INFO] Stok: %d\n", L[i].s); return 0;
            }
            printf("[!] Tdk ditemukan.\n");
        }
        else if (p == 5) { // Total Buku
            int t=0; for(i=0; i<C; i++) t+=L[i].s;
            printf("[INFO] Total: %d\n", t);
        }
        else if (p == 6) { // Terbitkan (-1)
            printf("No: "); if (scanf("%d", &n_c) != 1) {continue;}
            for(i=0; i<C; i++) if(L[i].n == n_c) {
                if (L[i].s > 0) {L[i].s--; L[i].t = true; printf("[+] Terbit OK. Sisa: %d\n", L[i].s);}
                else {printf("[!] Stok habis.\n");} return 0;
            }
            printf("[!] Tdk ditemukan.\n");
        }
    } while (p != 0);
    return 0;
}
struct Buku {
    int nomor_akses;        
    char nama_penulis[50];  
    char judul_buku[100];   
    bool is_diterbitkan;    
};
int main() {
    struct Buku buku_fiksi;
    buku_fiksi.nomor_akses = 4567;
    
    snprintf(buku_fiksi.nama_penulis, sizeof(buku_fiksi.nama_penulis), "Andrea Hirata");
    snprintf(buku_fiksi.judul_buku, sizeof(buku_fiksi.judul_buku), "Laskar Pelangi");
    buku_fiksi.is_diterbitkan = true;

    printf("Struktur berhasil didefinisikan dan digunakan.\n");
    printf("Judul: %s, Status Terbit: %s\n", 
           buku_fiksi.judul_buku, 
           buku_fiksi.is_diterbitkan ? "SUDAH" : "BELUM");

    return 0;
}
