#include <stdio.h>

struct Mhs {
    int no;
    char nama[30];
    int usia;
    float nilai;
};

int main() {
    struct Mhs data_mhs[] = {
        {1, "Ahmad Dani", 20, 85.5},
        {2, "Bella Sinta", 21, 90.0},
        {3, "Cakra Khan", 19, 78.25}
    };

    int jumlah = sizeof(data_mhs) / sizeof(data_mhs[0]);

    printf("=== Data Mahasiswa ===\n");
    printf("No | Nama               | Usia | Nilai\n");
    printf("---|--------------------|------|-------\n");
    
    for (int i = 0; i < jumlah; i++) {
        printf("%-2d | %-18s | %-4d | %.2f\n",
            data_mhs[i].no,
            data_mhs[i].nama,
            data_mhs[i].usia,
            data_mhs[i].nilai
        );
    }

    return 0;
}
