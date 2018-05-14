
import sys
import numpy as np
import matplotlib.pyplot as plt
import random
from matplotlib import animation, rc

fig = plt.figure(figsize=(8, 8), facecolor='black')

ax = plt.subplot(111, frameon=False)


T = 40
p = 10
L = 100
u0 = np.zeros(L)
uv = []
dx =1
x = np.linspace(1,L,100)

#inicializar
for i in range(0,L):
    valor = L*0.8
    if(i<valor):
        u0[i]=(1.25*i)/L
        
    else:
        u0[i]= (5-5*i)/L

        
c = (T/p)**(0.5)  
dt = 1
r=c*dt/dx
tmax = 200
tmin = 0
lines = []
unext = np.zeros(L)
for i in range(tmin,tmax):
    for j in range(0,L):
        if (j==0):
            unext[j] = u0[j]
        else:
            if(j==L-1):
                unext[j] = u0[j]
            else:
                unext[j]= u0[j]+((r**2)/2)*(u0[j+1]-2*u0[j]+u0[j-1])
    uv.append(unext)

    for j in range(0,L):
        u0[j]=unext[j]

uv = np.asarray(uv)

plt.show

line, = ax.plot(x, uv[55], color="w")
   


def update(*args):
    ii = random.randint(0,100)
    valor = uv[ii]
    line.set_ydata(valor)
    return line,       
        
anim = animation.FuncAnimation(fig, update, interval=10)
anim.save('cuerda.gif', writer='imagemagick', fps=30)
plt.show()
