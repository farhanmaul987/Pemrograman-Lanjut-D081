#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <unistd.h>
#include <windows.h>

#define a 10
int lvlppkm(int x);
char cari[50];
struct data {
    char prov[50];
    char kotkab[50];
    int pendtotal;
    int lansia;
    int penduduk_vaksin;
    int lansia_vaksin;
    int levelppkm;
};
data daerah[a] = {
                    {"Riau", "Pekanbaru", 1500000, 75000, 50000, 20000, lvlppkm(0)},
                    {"Jawa Timur", "Surabaya", 1000000, 200000, 800000, 10000, lvlppkm(1)},
                    {"Papua", "Timika", 2000000, 50000, 10000, 9000, lvlppkm(2)},
                    {"Banten", "Serang", 700000, 25000, 650000, 25000, lvlppkm(3)},
                    {"Jawa Timur", "Jombang", 1300000, 150000, 1400000, 90000, lvlppkm(4)},
                    {"Jawa Tengah", "Magelang", 1500000, 700000, 900000, 30000, lvlppkm(5)},
                    {"Sumatera Selatan", "Palembang", 1700000, 900000, 1200000, 750000, lvlppkm(6)},
                    {"Jawa Timur", "Sumenep", 1000000, 10000, 500000, 8500, lvlppkm(7)},
                    {"Nusa Tenggara Timur", "Kupang", 500000, 50000, 450000, 30000, lvlppkm(8)},
                    {"Bali", "Denpasar", 900000, 50000, 800000, 35000, lvlppkm(9)}
};
data pencarian[10];
int n;

void garis1(int panjang) {
	int i;
	for(i = 0; i < panjang; i++) {
		printf("-");
	}
	printf("\n");
}

void garis2(int panjang) {
	int i;
	for(i = 0; i < panjang; i++) {
		printf("=");
	}
	printf("\n");
}

void bio() {
    puts("NAMA  : M. Farhan Maulana");
    puts("KELAS : D081");
    puts("NPM   : 20081010159");
}

void tampilcari() {
	int i, j;
    garis2(15);
	printf("HASIL PENCARIAN\n");
    garis2(15);
    printf("\n");
	for (i = 0; i < n; i++) {
		j = j + 1;
        
        garis1(18);
		printf(" Data Ke: %i\n",j);
        garis1(18);
        printf("Provinsi                : %s\n",pencarian[i].prov);
        printf("Kota/Kabupaten          : %s\n",pencarian[i].kotkab);
        printf("Jml. Penduduk           : %i\n",pencarian[i].pendtotal);
        printf("Jml. Lansia             : %i\n",pencarian[i].lansia);
        printf("Penduduk Sudah Vaksin   : %i\n",pencarian[i].penduduk_vaksin);
        printf("Lansia Sudah Vaksin     : %i\n",pencarian[i].lansia_vaksin);
        printf("Level PPKM              : %i\n\n", pencarian[i].levelppkm);
		printf("\n");
	}
}

void seq_provinsi() {
	int m;
	printf("CARI BERDASARKAN PROVINSI");
	printf("\nNama Provinsi: ");
	fflush(stdin);
    gets(cari);
	n = 0;
    for(m = 0; m < a; m++) {
        if((strcmp (cari, daerah[m].prov) == 0)) {
            pencarian[n] = daerah[m];
            n++;
        }
    }
    if(n > 0) {
    	tampilcari();
	} else {
		printf("\nData Tidak Ditemukan!\n");
	}
}

void seq_kabkota() {
	int m;
	printf("CARI BERDASARKAN KABUPATEN/KOTA\n");
	printf("\nNama Kabupaten/Kota: ");
	fflush(stdin);
    gets(cari);
	n = 0;
    for(m = 0; m < a; m++) {
        if((strcmp (cari, daerah[m].kotkab) == 0)) {
            pencarian[n] = daerah[m];
            n++;
        }
    }
    if(n > 0) {
    	tampilcari();
	} else {
		printf("\nData Tidak Ditemukan!\n");
	}
}

int urut_ascending() {
 	int f;
 	int g;
 	data temp;
 	int min;
	for (f = 0; f < (a-1); f++) {
 		min = f;
	 	for (g = f+1; g < a; g++) {
	 		if (daerah[min].levelppkm > daerah[g].levelppkm) {
	 			min = g;
	 		}
	 	}
	 	temp = daerah [f];
 		daerah [f] = daerah [min];
 		daerah [min] = temp;
	}
}

void urut_descending() {
 	int f;
 	int g;
 	data temp;
 	int min;
	for (f = 0; f <= a-1; f++) {
 		min = f;
	 	for (g = f+1; g < a; g++) {
	 		if (daerah[min].levelppkm < daerah[g].levelppkm) {
	 			min = g;
	 		}
	 	}
	 	temp = daerah [f];
 		daerah [f] = daerah [min];
 		daerah [min] = temp;
	}
}

int lvlppkm(int x) {
    int l1vak = 0.7 * daerah[x].pendtotal;
    int l1lan = 0.6 * daerah[x].lansia;
    int l2vak = 0.5 * daerah[x].pendtotal;
    int l2lan = 0.6 * daerah[x].lansia;
    if (daerah[x].penduduk_vaksin > l1vak && daerah[x].lansia_vaksin > l1lan)
    {
        return 1;
    } else if (daerah[x].penduduk_vaksin > l2vak && daerah[x].lansia_vaksin > l2lan)
    {
        return 2;
    } else
    {
        return 3;
    }
}

void showdata() {
    int i, j;
    garis2(11);
    printf("TAMPIL DATA\n");
    garis2(11);
    printf("\n");
    j = 0;
    for (i = 0; i < a; i++)
    {
        j = j + 1;
        garis1(18);
        printf("Data ke: %i\n", j);
        garis1(18);
        printf("Provinsi                : %s\n",daerah[i].prov);
        printf("Kota/Kabupaten          : %s\n",daerah[i].kotkab);
        printf("Jml. Penduduk           : %i\n",daerah[i].pendtotal);
        printf("Jml. Lansia             : %i\n",daerah[i].lansia);
        printf("Penduduk Sudah Vaksin   : %i\n",daerah[i].penduduk_vaksin);
        printf("Lansia Sudah Vaksin     : %i\n",daerah[i].lansia_vaksin);
        printf("Level PPKM              : %i\n\n", daerah[i].levelppkm);
    }
}

void sort () {
    garis1(7);
	printf("SORTING\n");
	garis1(7);
	puts("Pilih Menu Sort:");
    puts("[1] Ascending");
    puts("[2] Descending");
	puts("Pilihanmu:");
    switch(getch()){
	        case '1' : urut_ascending();
	        printf("\nData Telah Diurutkan!\n");
	        break;
	        case '2' : urut_descending();
	        printf("\nData Telah Diurutkan!\n");
	        break;
	}
}

void cariin () {
    garis1(4);
	printf("CARI\n");
	garis1(4);
	puts("Pilih Menu Cari:");
    puts("[1] Provinsi");
    puts("[2] Kabupaten/Kota");
	puts("Pilihanmu:");
    switch(getch()){
	        case '1' : seq_provinsi();
	        printf("\nData Telah Diurutkan!\n");
	        break;
	        case '2' : seq_kabkota();
	        printf("\nData Telah Diurutkan!\n");
	        break;
	}
}

int main(int argc, char *argv[]) {
    do {
        system("cls");
        garis2(34);
        printf("UTS MATA KULIAH PEMROGRAMAN LANJUT\n");
        garis2(34);
        bio();
        printf("\n");
        garis1(20);
        puts("Pilih Menu Di Bawah:");
        puts("[1] Tampilkan Data");
        puts("[2] Urutkan Data");
        puts("[3] Search Data");
        puts("\n[0]  Exit\n");
		puts("Pilihanmu:\n");
    	switch(getch()) {
    	    case '1' : showdata();
    	    break;
    	    case '2' : sort();
    	    break;
    	    case '3' : cariin();
    	    break;
	        case '0' :
	            return 0;
		    break;
		    default :
			printf("Pilihan Tidak Ditemukan!");
		    break;
        }
    }
    while(getch()!=27);
    return 0;
}
