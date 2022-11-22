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
#fig, ax = plt.subplots(nrows=2, ncols=2, figsize=(8,8))

plt.plot(temperature,energy,label = "Predicted")
plt.plot(temperature,ana_energy,label = "Analytical")
plt.title(r" Mean energy for the $2\times 2$ lattice ")
plt.xlabel(r" Temperature [$J/k_B$] ")
plt.ylabel(r" Energy [$J$] ")
plt.legend()
plt.savefig("plots/simple_energy.pdf")
plt.close()

plt.plot(temperature,magnetization,label = "Predicted")
plt.plot(temperature,ana_magnetization,label = "Analytical")
plt.title(r" Mean magnetization for the $2\times 2$ lattice ")
plt.xlabel(r" Temperature [$J/k_B$] ")
plt.ylabel(r" Magnetization ")
plt.legend()
plt.savefig("plots/simple_mag.pdf")
plt.close()

plt.plot(temperature,c_V,label = "Predicted")
plt.plot(temperature,ana_c_V,label = "Analytical")
plt.title(r" Specific heat capacity for the $2\times 2$ lattice ")
plt.xlabel(r" Temperature [$J/k_B$] ")
plt.ylabel(r" $c_V$ [$k_B$] ")
plt.legend()
plt.savefig("plots/simple_cv.pdf")
plt.close()

plt.plot(temperature,chi,label = "Predicted")
plt.plot(temperature,ana_chi,label = "Analytical")
plt.title(r" Magnetic susceptibility for the $2\times 2$ lattice ")
plt.xlabel(r" Temperature [$J/k_B$] ")
plt.ylabel(r" $\chi$ [$J^{-1}$] ")
plt.legend()
plt.savefig("plots/simple_chi.pdf")
plt.close()


