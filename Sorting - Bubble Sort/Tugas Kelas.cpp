#include <stdio.h>

int main() {
	int data[10] = {22, 10, 15, 3, 8, 2};
	int a, b, tmp, pilih;
  	int n = 6;
  	
	for(a= 0; a<n; a++) {
  		for(b = 0; b<n-1; b++) {
  			if(data[b] < data[b+1]) {
		  		tmp = data[b];
		  		data[b] = data[b+1];
				data[b+1] = tmp;
			}
		}
	}
	
	for(int a = 0; a < n; a++) {
		printf("Urutan data-data: %i\n", data[a]);
	}

}
