#include <stdio.h>
#include <math.h>

double f (double x)
{
	return exp((-pow(x,2))/2);
}

double rectangledroite(double (*f)(double), double a,double b,int n)
{
	double h;
	h=(b-a)/n;
	double S=0;
	double x;
	x=a;
	for(int i=0;i<n;i++)
	{
		S+=f(x);
		x+=h;
	}
	return (h*S);

}

double rectanglegauche(double (*f)(double),double a,double b,int n)
{
	double h;
	h=(b-a)/n;
	double S=0;
	double x;
	x=a+h;
	for(int i=0;i<n;i++)
	{
		S+=f(x);
		x+=h;
	}
	return(h*S);

}

double trapeze(double (*f)(double), double a,double b,int n)
{
	double S;
	S=0.5*(f(a)+f(b));
	double h;
	h=(b-a)/n;
	double x;
	x=a+h;
	for(int i=0;i<n-1;i++)
	{
		S+=f(x);
		x=x+h;
	}
	return(h*S);

}

double simpson(double (*f)(double),  double a, double b, int n)
{
	double h;
	h=(b-a)/n;
	double z;
	z=(f(a)+f(b))/6;
	for(int i=1;i<n;i++)
		z=z+f(a+i*h)/3;
	for(int i=0;i<n;i++)
		z=z+f(a+(2*i+1)*h/2) *2/3;
	return h*z;
}

double nombrenecessaire(double(*f)(double),double a,double b, double(*methode)(double(*)(double),double,double,int), double err)
{
	double I=0.855624391892149;
	double n=1;
	while(fabs(methode(f,a,b,n)-I)>err)
	{
		n++;
	}
	return n;
}

int main()
{
	double a;
	printf("Donner a:\n");
	scanf("%lf",&a);
	double b;
	printf("donner b:\n");
	scanf("%lf",&b);
	double err=pow(10,-9);
	//double err=pow(10,-6);
	//double err=pow(10,-3);
	printf("%lf\n", nombrenecessaire(f,a,b,simpson,err));
}
