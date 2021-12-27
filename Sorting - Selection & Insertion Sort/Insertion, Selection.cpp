#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

struct data {
	char npm[20];
	char nama[50];
	char kelas[10];
};
data maks[50];
int a, b, c, d;

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void garis1(int x) {
	int y;
	for(y = 0; y < x; y++) {
		printf("=");
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
	garis1(16);
	printf("MENU TAMBAH DATA\n");
	garis1(16);
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
	garis1(14);
	printf("MENU EDIT DATA\n");
	garis1(14);
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

void selnpm_asc(data total []) {
 	int f;
 	int g;
 	data temp;
 	int min;
	for (f = 0; f < a; f++) {
 		min = f;
	 	for (g = f; g < a; g++) {
	 		if ((strcmp ((total + min)-> npm,(total + g) -> npm)) > 0) {
	 			min = g;
	 		}
	 		temp = total [f];
	 		total [f] = total [min];
	 		total [min] = temp;
	 	}
	}
}

void selnpm_desc(data total []) {
 	int f;
 	int g;
 	data temp;
 	int min;
	for (f = 0; f < a; f++) {
 		min = f;
	 	for (g = f; g < a; g++) {
	 		if ((strcmp ((total + min)-> npm,(total + g) -> npm)) < 0) {
	 			min = g;
	 		}
	 		temp = total [f];
	 		total [f] = total [min];
	 		total [min] = temp;
	 	}
	}
}

void selnama_asc(data total []) {
 	int f;
 	int g;
 	data temp;
 	int min;
	for (f = 0; f < a; f++) {
 		min = f;
	 	for (g = f; g < a; g++) {
	 		if ((strcmp ((total + min)-> nama,(total + g) -> nama)) > 0) {
	 			min = g;
	 		}
	 		temp = total [f];
	 		total [f] = total [min];
	 		total [min] = temp;
	 	}
	}
}

void selnama_desc(data total []) {
 	int f;
 	int g;
 	data temp;
 	int min;
	for (f = 0; f < a; f++) {
 		min = f;
	 	for (g = f; g < a; g++) {
	 		if ((strcmp ((total + min)-> nama,(total + g) -> nama)) < 0) {
	 			min = g;
	 		}
	 		temp = total [f];
	 		total [f] = total [min];
	 		total [min] = temp;
	 	}
	}
}

void insnpm_asc(data total []) {
	int f;
 	int g;
 	data temp;
 	for (f = 0; f < a; f++){
        g = f;
        while(g > 0 && (strcmp (total[g-1].npm, total[g].npm) > 0)){
            temp = total [g];
            total [g] = total [g-1];
            total [g-1] = temp;
            g--;
        }
    }
}

void insnpm_desc(data total []) {
	int f;
 	int g;
 	data temp;
 	for (f = 0; f < a; f++){
        g = f;
        while(g > 0 && (strcmp (total[g-1].npm, total[g].npm) < 0)){
            temp = total [g];
            total [g] = total [g-1];
            total [g-1] = temp;
            g--;
        }
    }
}

void insnama_asc(data total []) {
	int f;
 	int g;
 	data temp;
 	for (f = 0; f < a; f++){
        g = f;
        while(g > 0 && (strcmp (total[g-1].nama, total[g].nama) > 0)){
            temp = total [g];
            total [g] = total [g-1];
            total [g-1] = temp;
            g--;
        }
    }
}

void insnama_desc(data total []) {
	int f;
 	int g;
 	data temp;
 	for (f = 0; f < a; f++){
        g = f;
        while(g > 0 && (strcmp (total[g-1].nama, total[g].nama) < 0)){
            temp = total [g];
            total [g] = total [g-1];
            total [g-1] = temp;
            g--;
        }
    }
}

void selectionsort() {
	garis1(14);
	printf("SELECTION SORT\n");
	garis1(14);
	puts("Pilih Menu:");
	puts("[1] Menurut NPM (Ascending)");
	puts("[2] Menurut NPM (Descending)");
	puts("[3] Menurut Nama (Ascending)");
	puts("[4] Menurut Nama (Descending)");
	switch (getch()) {
		case '1': selnpm_asc(maks);
		printf("\nData Telah Diurutkan!\n\n");
		break;
		case '2': selnpm_desc(maks);
		printf("\nData Telah Diurutkan!\n\n");
		break;
		case '3': selnama_asc(maks);
		printf("\nData Telah Diurutkan!\n\n");
		break;
		case '4': selnama_desc(maks);
		printf("\nData Telah Diurutkan!\n\n");
		break;
	}
}

void insertionsort() {
	garis1(14);
	printf("INSERTION SORT\n");
	garis1(14);
	puts("Pilih Menu:");
	puts("[1] Menurut NPM (Ascending)");
	puts("[2] Menurut NPM (Descending)");
	puts("[3] Menurut Nama (Ascending)");
	puts("[4] Menurut Nama (Descending)");
	switch (getch()) {
		case '1': selnpm_asc(maks);
		printf("\nData Telah Diurutkan!\n\n");
		break;
		case '2': selnpm_desc(maks);
		printf("\nData Telah Diurutkan!\n\n");
		break;
		case '3': selnama_asc(maks);
		printf("\nData Telah Diurutkan!\n\n");
		break;
		case '4': selnama_desc(maks);
		printf("\nData Telah Diurutkan!\n\n");
		break;
	}
}

void ngesortdata() {
	garis1(14);
	printf("MENU URUT DATA\n");
	garis1(14);
	puts("Pilih Menu Pengurutan Data:");
    puts("[1] Selection Sort");
    puts("[2] Insertion Sort\n");
    switch(getch()){
	        case '1' : selectionsort();
	        break;
	        case '2' : insertionsort();
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
		puts("NOTE	: Terkadang muncul bug yang membuat angka pertama pada NPM tidak muncul dan tidak bisa disort");
		puts("          maka data kedua dan seterusnya bagian NPM harus diberi spasi 1x baru masukkan NPM");
		puts("          atau bisa juga dengan menggunakan edit data.");
	    puts("\nPilih Menu Di Bawah:");
	    puts(" [1]  Tambah Data");
	    puts(" [2]  Tampilkan Data");
	    puts(" [3]  Ubah Data");
	    puts(" [4]  Urutkan Data");
	    puts(" [0]  Exit\n");
	    switch(getch()){
	        case '1' : adddata();
	        break;
	        case '2' : showdata();
	        break;
	        case '3' : editdata();
	        break;
	        case '4' : ngesortdata();
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
