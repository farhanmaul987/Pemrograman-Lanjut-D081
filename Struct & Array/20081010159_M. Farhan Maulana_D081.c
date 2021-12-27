#include <stdio.h>
#include <stdlib.h>

#define maksimal 50

typedef struct mahasiswa
{
    int npm;
    char nama[31];
    char asal[51];
}data_mhs;

data_mhs mhs[maksimal];

int main() {
    int a, b;
    printf("Data Mahasiswa: ");
    scanf("%i", &b);
    printf("\n");

    for(a = 0; a < b; a++) {
        printf("Data Mahasiswa ke %i\n", a + 1);
        printf("\n");
        printf("NPM: ");
        scanf("%i",&mhs[a].npm);
        printf("Nama: "); fflush(stdin); gets(mhs[a].nama);
        printf("Asal: "); fflush(stdin); gets(mhs[a].asal);
        printf("\n\n");
    }

    for(a = 0; a < b; a++) {
        printf("Data Mahasiswa ke %i\n", a + 1);
        printf("\n");
        printf("NPM: %d\n", mhs[a].npm);
        printf("NAMA: %s\n", mhs[a].nama);
        printf("ASAL: %s\n", mhs[a].asal);
        printf("\n\n");
    }

    return 0;
}
