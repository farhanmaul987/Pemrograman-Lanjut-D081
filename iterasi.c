#include <stdio.h>

int iter(int a,int b) {
	int hasil = 1;
	for (int i=1; i<=b; i++) {
    total = total * a;
	}
	return hasil;
}

int main()
{
	int a,b;
	printf("Masukkan Angka: ");
	scanf("%i", &a);
	printf("Masukkan Pangkat dari Angka: ");
	scanf("%i", &b);
  printf("Hasil Iterasi: %i\n", iterasi(a,b))
  
  return 0;
}
