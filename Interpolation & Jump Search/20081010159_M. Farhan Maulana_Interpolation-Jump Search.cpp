#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <cmath>
#include <windows.h>

int konversi(int x);
char carijudul[30];
int carikode;
int kunci;
int posisi;
int ditemukan;

struct data {
	int kode;
	char judul[30];
	char pengarang[20];
	int angka;
};
data buku[10] = {
					{3031, "C Programming", "James Lee", konversi(0)},
					{101, "Wordpress Expert", "Andrew Octa", konversi(1)},
					{8812, "Web From Zero to Hero", "David Guetta", konversi(2)},
					{790, "Laravel", "Hans Jackson", konversi(3)},
					{66, "Master Flutter", "Ozur Haskels", konversi(4)},
					{111, "CodeIgniter 4 the guide", "Gantz Patrick", konversi(5)},
					{678, "Raspberry Pi 4", "Tony Watts", konversi(6)},
					{901, "Building Robotic AI", "Leny Imelda", konversi(7)},
					{303, "Data Science with Python", "Ranya Sundar", konversi(8)},
					{4089, "Go Lang Introduction", "Brian Macakzie", konversi(9)},
};
data pencarian[10];
int n = sizeof(buku) / sizeof(buku[0]);

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void bio() {
    puts("NAMA  : M. Farhan Maulana");
    puts("KELAS : D081");
    puts("NPM   : 20081010159");
}

void garis2(int panjang) {
	int a;
	for(a = 0; a < panjang; a++) {
		printf("=");
	}
	printf("\n");
}

int konversi(int x) {
    int i, digit, hasil = 0;
    int pjg = strlen(buku[x].judul);
    for(i = 0; i < pjg; i++) {
        digit = buku[x].judul[i];
        hasil = hasil + digit;
    }
    return hasil;
}

int konvertcari(char string[]) {
    int digit, hasil = 0;
    int pjg = strlen(string);
    for(int i = 0; i < pjg; i++) {
        digit = string[i];
        hasil = hasil + digit;
    }
    return hasil;
}

void urut_judul() {
 	int f;
 	int g;
 	data temp;
 	int min;
	for (f = 0; f < 9; f++) {
 		min = f;
	 	for (g = f+1; g < 10; g++) {
	 		if (buku[min].angka > buku[g].angka) {
	 			min = g;
	 		}
	 	}
	 	temp = buku [f];
 		buku [f] = buku [min];
 		buku [min] = temp;
	}
}

void urut_kode() {
 	int f;
 	int g;
 	data temp;
 	int min;
	for (f = 0; f < 9; f++) {
 		min = f;
	 	for (g = f+1; g < 10; g++) {
	 		if (buku[min].kode > buku[g].kode) {
	 			min = g;
	 		}
	 	}
	 	temp = buku [f];
 		buku [f] = buku [min];
 		buku [min] = temp;
	}
}

void tampilcari() {
	int i;
	printf("\n");
	garis2(15);
	printf("HASIL PENCARIAN\n");
	garis2(15);
	for(i = 0; i < ditemukan; i++) {
		printf("Kode Buku\t: %i\n",pencarian[i].kode);
		printf("Judul Buku\t: %s\n",pencarian[i].judul);
		printf("Pengarang\t: %s\n",pencarian[i].pengarang);
	}
}

void jump_search(int kunci, int n) {
    int i;
	int mulai = 0;
	int selesai = sqrt(n);
	ditemukan = 0;
    urut_kode();
    while (buku[selesai].kode <= kunci && selesai < n) {
        mulai = selesai;
        selesai += sqrt(n);
        if (selesai > n-1) {
        	selesai = n;
		}
    }
    for(i = mulai; i < selesai; i++) {
    	if (buku[i].kode == kunci) {
    		pencarian[ditemukan] = buku[i];
        	ditemukan++;
		}
	}
	if(ditemukan > 0) {
    	tampilcari();
	} else {
		printf("\nHasil Pencarian: Data Tidak Ditemukan!\n\n");
	}
}

void interpolation_search(int bawah, int atas, int kunci) {
    int tengah;
    urut_judul();
    ditemukan = 0;
    while (bawah <= atas) {
        tengah = bawah + (atas - bawah)*((kunci-buku[bawah].angka)/(buku[atas].angka-buku[bawah].angka));
        if (kunci == buku[tengah].angka) {
        	pencarian[ditemukan] = buku[tengah];
        	ditemukan++;
		}
        if (kunci < buku[tengah].angka) {
            atas = tengah - 1;        	
		}
        else {
            bawah = tengah + 1;        	
		}
    }
    if(ditemukan > 0) {
    	tampilcari();
	} else {
		printf("\nHasil Pencarian: Data Tidak Ditemukan!\n\n");
	}
}

void tampildata() {
	int i, j = 0;
	system("cls");
	garis2(16);
	printf("MENU TAMPIL DATA\n");
	garis2(16);
	printf("\n");
	for(i = 0; i < 10; i++) {
		j = j + 1;
		printf("Data Buku Ke - %i\n", j);
		printf("Kode Buku\t: %i\n",buku[i].kode);
		printf("Judul Buku\t: %s\n",buku[i].judul);
		printf("Pengarang\t: %s\n",buku[i].pengarang);
		printf("Judul Angka\t: %i\n\n",buku[i].angka);
	}
}

void menujump() {
	system("cls");
	garis2(33);
	printf("PENCARIAN KODE BUKU - JUMP SEARCH\n");
	garis2(33);
	printf("\nMasukkan Kode Buku yang ingin Dicari: ");
	fflush(stdin);
	scanf("%i", &carikode);
	jump_search(carikode, n);
}

void menuinter() {
	system("cls");
	garis2(43);
	printf("PENCARIAN JUDUL BUKU - INTERPOLATION SEARCH\n");
	garis2(43);
	printf("\nMasukkan Judul Buku yang ingin Dicari: ");
	fflush(stdin);
	gets(carijudul);
	kunci = konvertcari(carijudul);
	interpolation_search(0, n-1, kunci);
}

int main() {
	do {
		system("cls");
		gotoxy(55,1);
		printf("MENU UTAMA\n");
		bio();
	    puts("\nPilih Menu dibawah ini untuk menjalankan aplikasi");
	    puts("[1] Tampilkan Data");
	    puts("[2] Pencarian Kode Buku - Jump Search");
	    puts("[3] Pencarian Judul Buku - interpolation Search");
	    puts("[0] Exit\n");
	    switch(getch()){
	        case '1' : tampildata();
	        break;
	        case '2' : menujump();
	        break;
	        case '3' : menuinter();
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
