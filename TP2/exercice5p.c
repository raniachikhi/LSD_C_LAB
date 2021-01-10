#include <stdio.h>
#include <math.h>

double f (double x)
{
	return exp((-pow(x,2))/2);
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


double romberg(double (*f)(double), int  a, int  b, double err, int  nmax)
{
	double R[nmax][nmax];
	int n;
	int i,k;
	for(i=0;i<nmax;i++)
	{
		int N=pow(2,i);
		R[i][0]=trapeze(f,a,b,N);
		for(k=0;k<i;k++)
		{
			n=k+2;
			R[i][k+1]=1/(pow(4,n-1)-1)*(pow(4,n-1)*R[i][k]-R[i-1][k]);
			if(i>0)
			{
				if(fabs(R[i][k+1]-R[i][k])<err)
						return R[i][k+1];
			}
		}
	}
	return R[i][k+1];
}



int main()
{
	int a=0;
	int b=1;
	double err=pow(10,-9);
	int  nmax=3;
	printf("%lf\n",romberg(f,a,b,err,nmax));
}
