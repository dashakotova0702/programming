#include <stdio.h>
#include <math.h>
float z(float x, float a);

int main ()
{
float a=2.0;
float x=1.0;
float hx=1.3;
float ha=1.3;
float z1;
while (x<=3.0)
	{
	while (a<=4.0)
		{
		z1=z(x,a);
		printf ("f(%.2f,%.2f)=%.2f\n", x, a, z1);
		a+= ha;
		}
	x+= hx;
	a= 2.0;
	}
return 0;
}
float z(float x, float a){
	float u, minu, minz, z1;
	if (tan(a/x)<x*sin(a*a))
		minu= tan(a/x);
	else
                minu= x*sin(a*a);
	u= minu;
        if (sqrt(u)*a<sin(a)/x)
                minz= sqrt(u)*a;
        else
                minz= sin(a)/x;
        z1= minz;
	return z1;
}


