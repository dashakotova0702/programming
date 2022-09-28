#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <math.h>

int main ()
{
	float **a;
	int i, j, k, n;
	printf ("Введите количество строк массива: ");
	scanf ("%d", &k);
	printf ("Введите количество столбцов массива: ");
	scanf ("%d", &n);
	a = (float**)malloc(k*sizeof(float*));
        for (i=0; i<k; i++){
		a[i]=(float*)malloc(n*sizeof(float)); 
		for (j=0; j<n; j++){
			printf ("a[%d][%d] = ", i, j);
			scanf ("%f", &a[i][j]);
		}
	}
	printf("Массив: \n");
	for (i=0; i<k; i++){
                for (j=0; j<n; j++)
			printf("%.0f ", a[i][j]);
		printf("\n");
	}
	int c=0;
	if (i<=j) {
	for (i=0; i<k; i++)
		if (a[i][i]<0)
			c+=1;
	}
	else {
	for (j=0; j<n; j++)
                if (a[j][j]<0)
                        c+=1;
	}
	printf ("Число отрицательных элементов в главной диагонали: %d\n", c);
	float S;
	if (n<4) {
		for (j=0; j<n; j++)
			S+=sin(a[0][j]);
			S+=((a[0][j])/7);
		S = S*5;
	}
	else {
		for (j=0; j<4; j++)
                        S+=sin(a[0][j]);
			S+=((a[0][j])/7);
		S = S*5;
	}
	printf ("S = %.2f\n", S);
	if (i>=2){
		a[2][0] = S;
		printf("Измененный массив: \n");
        	for (i=0; i<k; i++){
                	for (j=0; j<n; j++)
                        	printf("%.2f ", a[i][j]);
                	printf("\n");
		}
	}
	else
		printf ("Элемента a[2][0] не существует. Массив остался прежним\n"); 
	for (i=0; i<k; i++)
        	free(a[i]);
	free(a);
	return 0;
}
