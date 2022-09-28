#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

int func(int *a, int n){
int i;
int h=0;
for (i=1; i<n; i++){
        if (a[i-1]<a[i])
                h++;
        }
return h;
}

void main (){
int n, i, v;
int *a;
printf ("Введите размер массива: ");
scanf ("%d", &n);
a = (int*)malloc(n * sizeof(int));
for (i=0; i<n; i++){
	printf("a[%d] = ", i);
	scanf("%d", &a[i]);
	}
v=func(a, n);
if (v==n-1)
	printf ("Массив строго упорядочен по возрастанию\n");
else 
	printf ("Массив не упорядочен по возрастанию\n");
free(a);
getchar();
}

//Алла -зайчик
