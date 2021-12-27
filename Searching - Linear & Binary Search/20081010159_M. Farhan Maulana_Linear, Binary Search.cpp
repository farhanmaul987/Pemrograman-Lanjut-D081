#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

char cari[50];
struct data {
	char npm[20];
	char nama[50];
	char kelas[10];
};
data maks[50];
data dicari[50];
int m, n, a, b, c, d;

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void garis1(int x) {
	int y;
	for(y = 0; y < x; y++) {
		printf("-");
	}
	printf("\n");
}

void garis2(int x) {
	int y;
	for(y = 0; y < x; y++) {
		printf("=");
	}
	printf("\n");
}

void adddata() {
	garis2(16);
	printf("MENU TAMBAH DATA\n");
	garis2(16);
	printf("Jumlah Data Yang Akan diinput: ");
	scanf("%i", &b);
	d = 0;
	for(c = 0; c < b; c++) {
		d = d+1;
		printf("\nData ke - %d\n", d);
		printf("NPM\t\t: ");
		getchar();
		gets(maks[a].npm);
		printf("Nama\t\t: ");
		gets(maks[a].nama);
		printf("Kelas\t\t: ");
		gets(maks[a].kelas);
		a++;
	}
}

void showdata() {
	int i, j;
	int x;
	printf("=========================MENU TAMPILKAN DATA=========================\n");
	garis2(69);
	printf("||  NO  ||\tNPM\t||\t\tNama\t\t||  Kelas  ||\n");
	j = 0;
	for(i = 0; i < a; i++) {
		j = j + 1;
		garis2(69);
		printf("||  %i", j);
		if (j < 10) {
			printf("   ");
		} else {
			printf("  ");
		}
		printf("||");
		printf("%s\t||",maks[i].npm);
		printf("%s",maks[i].nama);
		for(x = 0; x < 30-strlen(maks[i].nama); x++) {
			printf(" ");
		}
		printf("||");
		printf("%s",maks[i].kelas);
		for(x = 0; x < 9-strlen(maks[i].kelas); x++) {
			printf(" ");
		}

		printf("||");
		printf("\n");
	}
	garis2(69);
	printf("\n");
	getch();
}

void editdata() {
	int k, l;
	garis2(14);
	printf("MENU EDIT DATA\n");
	garis2(14);
	printf("Nomor Data yang Ingin Diedit: ");
	scanf("%i", &k);
	l = k-1;
	printf("NPM\t\t: ");
	getchar();
	gets(maks[l].npm);
	printf("Nama\t\t: ");
	gets(maks[l].nama);
	printf("Kelas\t\t: ");
	gets(maks[l].kelas);
	printf("\nData Ke - %i Berhasil Diubah!\n", k);
}

void showcari() {
	int i, x, z;
	printf("\n===========================HASIL PENCARIAN===========================\n");
    	garis2(69);
		printf("||  NO  ||\tNPM\t||\t\tNama\t\t||  Kelas  ||\n");
		z = 0;
		for(i = 0; i < n; i++) {
			z = z + 1;
			garis2(69);
			printf("||  %i", z);
			if (z < 10) {
				printf("   ");
			} else {
				printf("  ");
			}
			printf("||");
			//Panjang tabel NPM 14 karakter
			printf("%s",dicari[i].npm);
			for(x = 0; x < 14-strlen(dicari[i].npm); x++) {
				printf(" ");
			}
			printf("||");
			//Panjang tabel nama 30 karakter
			printf("%s",dicari[i].nama);
			for(x = 0; x < 30-strlen(dicari[i].nama); x++) {
				printf(" ");
			}
			printf("||");
			//Panjang tabel kelas 9 karakter
			printf("%s",dicari[i].kelas);
			for(x = 0; x < 9-strlen(dicari[i].kelas); x++) {
				printf(" ");
			}
			printf("||");
			printf("\n");
		}
		garis2(69);
		printf("\n");
}

void bnpm_asc(data total []) {
	int e, f;
 	data tmp;
	for(f = 0; f < (a-1); f++) {
        for(e = 0; e < a-f-1; e++) {
            if((strcmp (total[e].npm, total[e+1].npm) > 0)) {
                tmp = total [e];
		 		total [e] = total [e+1];
		 		total [e+1] = tmp;
            }
        }
    }
}

void bnama_asc(data total []) {
	int e, f;
 	data tmp;
	for(f = 0; f < (a-1); f++) {
        for(e = 0; e < a-f-1; e++) {
            if((strcmp (total[e].nama, total[e+1].nama) > 0)) {
                tmp = total [e];
		 		total [e] = total [e+1];
		 		total [e+1] = tmp;
            }
        }
    }
}

void lin_npm() {
	garis1(18);
	printf("LINEAR SEARCH: NPM\n");
	garis1(18);
	printf("Masukkan NPM yang ingin Dicari: ");
    gets(cari);
	n = 0;
    for(m = 0; m < a; m++) {
        if((strcmp (cari, maks[m].npm) == 0)) {
            dicari[n] = maks[m];
            n++;
        }
    }
    if(n > 0) {
    	showcari();
	} else {
		printf("\nData Tidak Ditemukan!\n");
	}
}

void lin_nama() {
	garis1(19);
	printf("LINEAR SEARCH: NAMA\n");
	garis1(19);
	printf("Masukkan  Nama yang ingin Dicari: ");
    gets(cari);
	n = 0;
    for(m = 0; m < a; m++) {
        if((strcmp (cari, maks[m].nama) == 0)) {
            dicari[n] = maks[m];
            n++;
        }
    }
    if(n > 0) {
    	showcari();
	} else {
		printf("\nData Tidak Ditemukan!\n");
	}
}

void bin_npm() {
	int bawah = 0;
	int atas = a;
	bnpm_asc(maks);
	garis1(18);
	printf("BINARY SEARCH: NPM\n");
	garis1(18);
	printf("Masukkan  Nama yang ingin Dicari: ");
    gets(cari);
	n = 0;
    while(bawah <= atas) {
    	m = (bawah + atas) / 2;
        if((strcmp (cari, maks[m].npm) == 0)) {
            dicari[n] = maks[m];
            n++;
            break;
        } else if((strcmp (cari, maks[m].npm) > 0)) {
        	bawah = m + 1;
    	} else {
    		atas = m - 1;
    	}
    }
    
    if(n > 0) {
    	showcari();
	} else {
		printf("\nData Tidak Ditemukan!\n");
	}
}

void bin_nama() {
	int bawah = 0;
	int atas = a;
	bnama_asc(maks);
	garis1(19);
	printf("BINARY SEARCH: NAMA\n");
	garis1(19);
	printf("Masukkan  Nama yang ingin Dicari: ");
    gets(cari);
	n = 0;
    while(bawah <= atas) {
    	m = (bawah + atas) / 2;
        if((strcmp (cari, maks[m].nama) == 0)) {
            dicari[n] = maks[m];
            n++;
            break;
        } else if((strcmp (cari, maks[m].nama) > 0)) {
        	bawah = m + 1;
    	} else {
    		atas = m - 1;
    	}
    }
    
    if(n > 0) {
    	showcari();
	} else {
		printf("\nData Tidak Ditemukan!\n");
	}
}

void caridata() {
	garis2(19);
	printf("MENU SEARCHING DATA\n");
	garis2(19);
	puts("Pilih Menu Metode Searching Data");
	puts("[1] Linear Search: NPM");
    puts("[2] Linear Search: Nama");
    puts("[3] Binary Search: NPM");
    puts("[4] Binary Search: Nama");
	switch(getch()){
		case '1' : lin_npm();
        break;
        case '2' : lin_nama();
        break;
        case '3' : bin_npm();
        break;
        case '4' : bin_nama();
        break;
	}
}

int main(int argc, char *argv[]) {
	do {
		system("cls");
		gotoxy(55,1);
		printf("MENU UTAMA\n");
		puts("NAMA	: Muhammad Farhan Maulana");
		puts("NPM	: 20081010159");
		puts("KELAS	: D081");
		puts("NOTE	: Terkadang muncul bug yang membuat angka pertama pada NPM tidak muncul, maka data kedua");
		puts("          dan seterusnya bagian NPM harus diberi spasi 1x baru masukkan NPM atau bisa juga");
		puts("          dengan menggunakan edit data.");
	    puts("\nPilih Menu Di Bawah:");
	    puts("[1] Tambah Data");
	    puts("[2] Tampilkan Data");
	    puts("[3] Ubah Data");
	    puts("[4] Search Data");
	    puts("[0] Exit\n");
	    switch(getch()){
	        case '1' : adddata();
	        break;
	        case '2' : showdata();
	        break;
	        case '3' : editdata();
	        break;
	        case '4' : caridata();
	        break;
			case '0' :
				return 0;
			break;
			default :
				printf("Pilihan Tidak Ditemukan");
			break;

	    }
	}
	while(getch()!=27);

    return 0;
}
