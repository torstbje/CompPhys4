import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
import warnings

# Stop warnings
warnings.filterwarnings("ignore" )


# Collect data
data = pd.read_csv("textfiles/simple.txt",header=None)
energy = data[0]
magnetization = data[1]
c_V = data[2]
chi = data[3]
temperature = data[4]

s = np.sinh(8/temperature)
c = np.cosh(8/temperature)
u = np.exp(8/temperature)

Z = 12 + 4*c
ana_energy = -8*s/Z
ana_magnetization = (4 + 2*u)/Z
ana_c_V = (16*12*c)/(temperature*Z)**2
ana_chi = ((2+2*u)*Z - 4*(4 + 4*u + u**2))/(temperature*Z**2)


# Make subplot configuration
fig, ax = plt.subplots(nrows=2, ncols=2, figsize=(12,12))

ax[0,0].plot(temperature,energy,label = "Predicted")
ax[0,0].plot(temperature,ana_energy,label = "Analytical")
ax[0,0].set_title(r" Mean energy ")
ax[0,0].set_xlabel(r" Temperature [$J/k_B$] ")
ax[0,0].set_ylabel(r" Energy [$J$] ")
ax[0,0].legend()

ax[0,1].plot(temperature,magnetization,label = "Predicted")
ax[0,1].plot(temperature,ana_magnetization,label = "Analytical")
ax[0,1].set_title(r" Mean magnetization")
ax[0,1].set_xlabel(r" Temperature [$J/k_B$] ")
ax[0,1].set_ylabel(r" Magnetization ")
ax[0,1].legend()

ax[1,0].plot(temperature,c_V,label = "Predicted")
ax[1,0].plot(temperature,ana_c_V,label = "Analytical")
ax[1,0].set_title(r" Specific heat capacity ")
ax[1,0].set_xlabel(r" Temperature [$J/k_B$] ")
ax[1,0].set_ylabel(r" $c_V$ [$k_B$] ")
ax[1,0].legend()

ax[1,1].plot(temperature,chi,label = "Predicted")
ax[1,1].plot(temperature,ana_chi,label = "Analytical")
ax[1,1].set_title(r" Magnetic susceptibility ")
ax[1,1].set_xlabel(r" Temperature [$J/k_B$] ")
ax[1,1].set_ylabel(r" $\chi$ [$J^{-1}$] ")
ax[1,1].legend()

plt.suptitle(r" Comparisons with analytical solutions for the $2 \times 2$ lattice ")
plt.savefig("plots/simple.pdf")
plt.show()


