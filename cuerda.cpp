#include <iostream>
using namespace std;
#include <stdio.h>      /* printf */
#include <math.h>       /* pow */


int main()
{
	double T= 40;
	double p = 10;
	double L = 100;
	double u0[L];
	double dx = 1;
	double valor;
	valor = L*0.8;
	int i ;
	for (i = 0; i<L; i=i+1)
	{
		if(i<valor)
		{
			u0[i]= (1.25*i)/L;
			
		}
		else
		{
			u0[i]= (5-5*i)/L;
		}
		
	}
	double c = pow((T/p),0.5);
	double dt =1;
	double r = c*dt/dx;
	double tmax = 200;
	double tmin = 0;
	
	double unext[L];
	
	int j;
	
	for(i=tmin;i<tmax;i=i+1)
	{
		for(j=0;j<L;j=j+1)
		{
			if(j==0)
			{
				unext[j]=u0[j];
			}
			else
			{
				if(j==(L-1))
				{
					unext[j]=u0[j];
				}
				else
				{
					unext[j]=u0[j]+((r*r)/2)*(u0[j+1]-2*u0[j]+u0[j-1]);
				}
			}
		}
	}
	
	
	for (i=0; i<L;i=i+1)
	{
		cout << unext[i] << "\" ;
	}
	
	return 0;
}