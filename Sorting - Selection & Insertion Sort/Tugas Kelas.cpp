#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <math.h>
using namespace std;
float eth,x[20];
int i=-1;
float F(float x){
    return (x*x*x)-(x*x*2)-(3*x)-8;
}
float G(float x){
    return pow((x*x*2)+(3*x)+(8),(float)1/3);
}
int main ()
{
   
    cout << " Metode Iterasi Sederhana\n"<<endl;
    cout << " Masukkan Nilai Awal : ";
    cin >> x[0];
    cout << "\n\ Masukkan Batas Toleransi : ";
    cin >> eth;           

            printf(" \n\iterasi\t  x(i)\t\t akar\t\t fx(i+1)\n");
            do
            {
                i++;
                x[i+1]= G(x[i]);
                printf("\n\   %d\t %f\t %f\t %f\t\n",i+1,x[i],x[i+1],F(x[i+1]));
            }
            while (fabs(F(x[i+1])) > eth);
            printf("\n\ akar = %f \n",x[i+1]);
getch();       
}
