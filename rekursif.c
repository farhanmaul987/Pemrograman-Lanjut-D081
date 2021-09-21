#include <stdio.h>

int rekur(int a, int b){
	if (b == 0){
		return 1;
	}else
  {
		return a * rekur(a,(b-1));
	}
}

int main()
{
	int a,b;
	printf("Masukkan Angka: ");
	scanf("%i", &a);
	printf("Masukkan Pangkat dari Angka: ");
	scanf("%i", &b);
	printf("Hasil Rekursif: %i\n", rekur(a,b));
	
	return 0;
}
