#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <unistd.h>

#define maks 5
typedef char string[255];
typedef struct
{	string npm;
	string nama;
	string jurusan;
}data_mhs;

typedef struct{
    data_mhs data[maks];
}mhs;

void garis(int x) {
	int a;
	for(a = 0; a < x; a++) {
		printf("=");
	}
	printf("\n");
}


void init(mhs *m) {
	int i;
	for(i = 0; i < maks ; i++) {
        strcpy((*m).data[i].npm,"-");
        strcpy((*m).data[i].nama,"-");
        strcpy((*m).data[i].jurusan,"-");
    }
}

void addd(mhs *m) {
    int i, a;
    printf("\t\tMENU TAMBAH DATA\n\n");
    printf("Masukan Jumlah Data Yang Ingin Diinputkan : ");
    scanf("%i", &a);
    printf("\nMasukan Data Mahasiswa\n");
    for(i = 0; i < a ; i++) {
        fflush(stdin);
        printf("Data mahasiswa ke - %d\n",i+1);
        printf("NPM  : ");
		scanf("%s", &(*m).data[i].npm);
        printf("Nama : ");
		scanf("%s", &(*m).data[i].nama);
        printf("Jurusan : ");
		scanf("%s", &(*m).data[i].jurusan);
        printf("\n");
    }
}

void change(mhs *m, string npm) {
    int i;
    bool update = false;
    for(i = 0; i < maks ; i++) {
        if(strcmpi(npm, (*m).data[i].npm)==0) {
            printf("Ubah Data Mahasiswa %s \n", (*m).data[i].nama);
            fflush(stdin);
            printf("NPM  : ");
			scanf("%s", &(*m).data[i].npm);
	        printf("Nama : ");
			scanf("%s", &(*m).data[i].nama);
	        printf("Jurusan : ");
			scanf("%s", &(*m).data[i].jurusan);
	        printf("\n");
            update=true;
            break;
        }
    }
        if(!update) {
            printf("Data mahasiswa di temukan!\n");
    }
}

void show(mhs *m){
    int i;
    printf("\t\tMENU TAMPILKAN DATA\n\n");
    for(i = 0; i < maks ; i++) {
    	printf("Data mahasiswa ke - %i\n",i+1);
		printf("-------------------------\n");
        printf("NPM  : %s\n",(*m).data[i].npm);
        printf("Nama : %s\n",(*m).data[i].nama);
        printf("Jurusan : %s\n",(*m).data[i].jurusan);
        printf("\n");
    }
}

void deletedata(mhs *m) {
    int i, y, hps;
    printf("\t\tMENU HAPUS DATA\n\n");
    printf("Hapus Data Ke : ");
    scanf("%i", &hps);
    y = hps-1;
    for(i = y; i < maks; i++) {
        (*m).data[i] = (*m).data[i+1];
    }
}

int main() {
    mhs m;
    string input;
    init(&m);
    do {
        system("cls");
        puts("NAMA	: M. Farhan Maulana");
        puts("NPM	: 20081010159");
        puts("KELAS	: D081");
		garis(50);
        puts("\nPilih Menu:");
        puts("1.   Insert Data");
        puts("2.   Change Data");
        puts("3.   Show Data");
        puts("4.   Delete Data\n");
        puts("Esc. Exit\n");
	    switch(getch()){
	        case '1' : addd(&m);
	        garis(50);
	        break;
	        case '2' : fflush(stdin);
	        printf("\t\tMENU UBAH DATA\n\n");
			printf("Masukan NPM Mahasiswa yang akan diedit: ");
			gets(input);
	        change(&m, input);
	        garis(50);
	        break;
	        case '3' : show(&m);
	        garis(50);
	        break;
	        case '4' : deletedata(&m);
	        garis(50);
	        break;
	    }
	}
	while(getch()!=27);
	getch();
	return 0;
}



