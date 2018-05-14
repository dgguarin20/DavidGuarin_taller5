import numpy as np



L = 5
l = 2
d = 1
h = 5./512.

v0 = 100
N = 2*(L/h)*(L/h)

matriz = np.zeros((L/h,L/h))

size = int(L/h)

#initialize borders

for i in range(0,size):
    matriz[i,0]=0
    matriz[0,i]=0
    matriz[size-1,i]=0
    matriz[i,size-1]=0
    
#asignamos los valores de v0/2
calculo = ((5./2.)-1)/5
valor = int(size*calculo)
calculo = ((5./2.)-0.5)/5
valor2 = int(size*calculo)
valor3 = int(1./5)

for i in range(valor,size-valor):
    matriz[i,valor2] = v0/2
    matriz[i,valor2+valor3] =v0/2

#ya tenemos los valores de las placas. ya se inicializo los valores iniciales. 


    
    
