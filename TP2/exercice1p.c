#include<stdio.h>
#include<math.h>
//question 1//
float f (float x)
{
	return pow(x,2);
}




float rectangledroite(float (*f)(float), float a,float b,int n)
{
	float h;
	h=(b-a)/n;
	float S=0;
	float x;
	x=a;
	for(int i=0;i<n;i++)
	{
		S+=f(x);
		x+=h;
	}
	return (h*S);

}



float rectanglegauche(float (*f)(float),float a,float b,int n)
{
	float h;
	h=(b-a)/n;
	float S=0;
	float x;
	x=a+h;
	for(int i=0;i<n;i++)
	{
		S+=f(x);
		x+=h;
	}
	return(h*S);

}




float trapeze(float (*f)(float), float a,float b,int n)
{
	float S;
	S=0.5*(f(a)+f(b));
	float h;
	h=(b-a)/n;
	float x;
	x=a+h;
	for(int i=0;i<n-1;i++)
	{
		S+=f(x);
		x=x+h;
	}
	return(h*S);

}






float simpson(float (*f)(float),  float a, float b, int n)
{
	float h;
	h=(b-a)/n;
	float x;
	x=a+h;
	float z;
	z=a+h/2;
	float S1;
	S1=0;
	float S2;
	S2=f(z);
	for(int i=0; i<n-1;i++)
	{
		z+=h;
		S1+=f(x);
		S2+=f(z);
		x+=h;
	}
	return((h/6)*(f(a)+f(b)+2*S1+4*S2));
}




int main()
{
	float a;
	printf("Donner a:\n");
	scanf("%f",&a);
	float b;
	printf("donner b:\n");
	scanf("%f",&b);
	int n;
	printf("donner n:\n");
	scanf("%d",&n);
	printf("%f\n",rectangledroite(f,a,b,n));
	printf("%f\n",rectanglegauche(f,a,b,n));
	printf("%f\n",trapeze(f,a,b,n));
	printf("%f\n",simpson(f,a,b,n));
}


