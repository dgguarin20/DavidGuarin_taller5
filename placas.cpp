#include <iostream>
using namespace std;
#include <stdio.h>      /* printf */
#include <math.h>       /* pow */


int main()
{
	double L = 5;
	double ll = 2;
	double d = 1;
	double h = 5/512;
	
	double v0 = 100;
	double N = 2*(L/h)*(L/h);
	
	double matriz [L/h][L/h];
	double size = (L/h);
	
	int i;
	for(i =0;i<size;i=i+1)
	{
		matriz[0][i]=0;
		matriz[i][0]=0;
		matriz[size-1][i]=0;
		matriz[i][size-1]=0;
	}
	double calculo = ((5/2)-1)/5;
	double valor = (int)size*calculo;
	calculo = ((5/2)-0.5)/5;
	double valor2 =(int)size*calculo;
	
	for(i = valor; i<(size-valor); i=i+1)
	{
		
		matriz[i][valor2] = v0/2;
		matriz[i][valor2+d] = v0/2; 
	}
	
	
	return 0;
}