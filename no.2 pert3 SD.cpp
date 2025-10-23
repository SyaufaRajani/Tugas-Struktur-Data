#include <stdio.h>

struct Mahasiswa {
    int no_urut;
    char nama[30];
    int umur;
};

int main() {
    
    struct Mahasiswa daftar_mhs[] = {
        {1, "Andi Wijaya", 20},
        {2, "Budi Santoso", 21},
        {3, "Citra Dewi", 20},
        {4, "Dion Putra", 22},
        {5, "Eka Sari", 19}
    };

    printf("Detail Mahasiswa dengan No Urut 2:\n");
    printf("-----------------------------------\n");

    int indeks_target = 1; 

    printf("No Urut: %d\n", daftar_mhs[indeks_target].no_urut);
    printf("Nama   : %s\n", daftar_mhs[indeks_target].nama);
    printf("Umur   : %d tahun\n", daftar_mhs[indeks_target].umur);

    return 0;
}
