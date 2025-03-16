#include <stdio.h>
#define n 10

int main()

{ 
    system("chcp 65001");
    int mas[n], i, k, s; 
float sa;

puts ("Введіть елементи масиву\n"); 

for ( i = 0; i < n; i += 1)
{
    scanf ("%i", &mas[i]); 
    
}

k=0; s=0; 

for ( i = 0; i < n; i += 1)


if ( mas[i]<0 )

{ s += mas[i];

k += 1;}

if( k){ 

sa= (float)s/k;

printf ("Середнє арифметичне від'ємних елементів масиву %f\n", sa);

}

else

printf ("Кількість елементів < 0= %i\n", k);

}