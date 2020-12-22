
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 10

int main()
{
	double A[N][N],B[N],X[N];
	double C[N][N];
	int n;
	double S1,S2;
	double Y[N];
	//the size of the matrix//
	printf("donner la dimension de la matrice:");
	scanf("%d",&n);
	//filling the matrix A//
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
    			printf("A[%d][%d]=",i,j);
			scanf("%lf",&A[i][j]);
		}
 	}
	//filing the matrix B//
	for(int i=0;i<n;i++)
	{
		printf("B[%d]",i);
		scanf("%lf",&B[i]);
	}
	//Cholesky//
	C[0][0]=sqrt(A[0][0]);
	for(int i=1;i<n;i++)
		C[i][0]=A[i][0]/C[0][0];
	for(int j=1;j<n;j++)
	{
		for(int i=0;i<j-1;i++)
			C[i][j]=0;
                S1=0;
		for(int k=0;k<j;k++)
		{		
			S1=S1+pow(C[j][k],2);
		}
		
		C[j][j]=sqrt(A[j][j]-S1);
		for(int i=j+1;i<n;i++)
		{
                        S2=0;
			for(int k=0;k<j;k++)
			{
				S2=S2+C[i][k]*C[j][k];
			}
			C[i][j]=(1/C[j][j])*(A[i][j]-S2);
		}
	}
	//le calcul de CY=B//
	double M;
	Y[0]=B[0];
	for(int i=1;i<n;i++)
	{
		M=0;
		for(int j=0;j<i;j++)
		{
			M=M+C[i][j]*Y[j];
	        }           
		Y[i]=B[i]-M;
 	}
	//le calcul de transposee de C//
	double Tr[N][N];
          for(int i=0;i<n;i++)
          {
                 for(int j=0;j<n;j++)
                        Tr[i][j]=C[j][i];
          }
         printf("Tr: \n");
         for(int i=0;i<n;i++)
         {
                 for(int j=0;j<n;j++)
                         printf("%lf\t", Tr[i][j]);
                 printf("\n");
         }

	//Calcul de TrX=Y//
	double M1;
	X[n-1]=Y[n-1]/A[n-1][n-1];
	for(int i=n-2;i>=0;i--)
 	{
		M1=0;
		for(int j=i+1;j<n;j++)
		{
			M1=M1+A[i][j] * X[j];
		}
	X[i]=(Y[i]-M1)/A[i][i];
	}
	printf("\nThe resulting vector: [");
	  for (int i = 0; i < n; i++)
   		 printf("%lf%c", X[i], ",]"[i == n - 1]);
         
 return(0);
}


				   
  /* 
  ** What are you looking for ? \
  ** go ahead and code the solution by yourself. \
  ** you can always ask for help on slack.
  */

