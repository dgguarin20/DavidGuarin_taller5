#include <iostream>
using namespace std;
#include <stdio.h>      /* printf */
#include <math.h>       /* pow */

double slopeP(double q1);
double slopeP2(double q1,double q2);

int main()
{
  double dt = 0.006;
  double t = 3000;
  double a = 1/(2*pow(2,0.5));
  double p1 = 0;
  double p2 = 0;
  double k1;
  double k2;
  double k3;
  double k4;
  double pant2;
  double q1 = a;
  double q2 = a*-1;
  double p1ant;
  double p2ant;
  
  int i ;
  // si es usando lo que se dijo entonces deberia ser i = i+dt pero por tiempo
  // se puso i = i+1
  for (i = 0; i<t;i = i +1)
    {

      k1 = slopeP(q1);
      k2 = slopeP(q1+(1/3)*p1);
      k3 = slopeP(q1+(2/3)*p1);
      k4 = slopeP(q1+p1);
      p1ant = q1;
      p1 = p1+(1/6*(k1+2*k2+2*k3+k4));
      
      k1 = slopeP2(q1,q2);
      k2 = slopeP2(q1,q2+(1/3)*p2);
      k3 = slopeP2(q1,q2+(2/3)*p2);
      k4 = slopeP2(q1,q2+p2);
      p2ant = q2;
      p2 = p2+(1/6*(k1+2*k2+2*k3+k4));
      
      q1 = q1+p1;
      q2 = q2+p2;
      
      if((p1ant<0 and q1>0))
	{
	  cout << q2 << " ";
	  cout << p2 << "\n";
	}
  
            
	
    }

}



double slopeP(double q1)
{
  double valor;
  valor = -2*q1;
  double e = 0.01;
  valor = valor/pow((4*q1*q1+e*e),1.5);
  return valor;
}
double slopeP2(double q1,double q2)
{double e= 0.01;
  double abajo;
  abajo = pow(((q1-q2)*(q1-q2)+(e*e)/4),1.5);
  double abajo2;
  abajo2 = pow(((q1+q2)*(q1-q2)+(e*e)/4),1.5);
  double retorno;
  retorno = (q1-q2)/abajo - (q1+q2)/abajo2;
  return retorno;
}
