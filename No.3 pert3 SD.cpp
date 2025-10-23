#include <stdio.h>

typedef struct {
    int n;
    char nama[12];
    int u;
    char a[30];
    float v;
} Mhs;

#define N 15

int main() {
    Mhs d[N] = {
        {1,"Ani",20,"Jl. Mawar 1",85.5}, {2,"Budi",21,"Jl. Melati 2",78.0}, 
        {3,"Citra",19,"Jl. Anggrek 3",92.3}, {4,"Dani",22,"Jl. Tulip 4",80.75},
        {5,"Eka",20,"Jl. Kamboja 5",88.9}, {6,"Fajar",21,"Jl. Kenanga 6",75.1},
        {7,"Gita",19,"Jl. Soka 7",95.0}, {8,"Hadi",22,"Jl. Dahlia 8",81.2},
        {9,"Intan",20,"Jl. Teratai 9",79.9}, {10,"Joko",21,"Jl. Matahari 10",84.4},
        {11,"Kiki",19,"Jl. Bulan 11",90.1}, {12,"Lina",22,"Jl. Bintang 12",77.5},
        {13,"Mamat",20,"Jl. Pelangi 13",83.3}, {14,"Nani",21,"Jl. Awan 14",86.8},
        {15,"Otto",19,"Jl. Udara 15",91.6}
    };

    printf("--- Data %d Mahasiswa ---\n", N);
    printf("No|Nama\t|Umur|Nilai|Alamat\n");
    for (int i = 0; i < N; i++)
        printf("%d |%-10s|%d\t|%.2f |%s\n",
            d[i].n, d[i].nama, d[i].u, d[i].v, d[i].a);

    return 0;
}
