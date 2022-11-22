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

ana_energy = -8*np.sinh(8/temperature)/(3 + np.cosh(8/temperature))
ana_magnetization = (4 + 2*np.exp(8/temperature))/(3 + np.cosh(8/temperature))
ana_c_V = 4/temperature**2
ana_chi = (7/16)/temperature


# Make subplot configuration
#fig, ax = plt.subplots(nrows=2, ncols=2, figsize=(8,8))

plt.plot(temperature,energy,label = "Predicted")
plt.plot(temperature,ana_energy,label = "Analytical")
plt.title(r" Mean energy for the $2\times 2$ lattice ")
plt.xlabel(r" Temperature [$k_B$] ")
plt.ylabel(r" Energy [$J$] ")
plt.legend()
plt.show()

plt.plot(temperature,magnetization,label = "Predicted")
plt.plot(temperature,ana_magnetization,label = "Analytical")
plt.title(r" Mean magnetization for the $2\times 2$ lattice ")
plt.xlabel(r" Temperature [$k_B$] ")
plt.ylabel(r" Magnetization ")
plt.legend()
plt.show()

plt.plot(temperature,c_V,label = "Predicted")
plt.plot(temperature,ana_c_V,label = "Analytical")
plt.title(r" $c_V$ for the $2\times 2$ lattice ")
plt.xlabel(r" Temperature [$k_B$] ")
plt.ylabel(r" Energy [$J$] ")
plt.legend()
plt.show()

plt.plot(temperature,chi,label = "Predicted")
plt.plot(temperature,ana_chi,label = "Analytical")
plt.title(r" Mean chi for the $2\times 2$ lattice ")
plt.xlabel(r" Temperature [$k_B$] ")
plt.ylabel(r" $\chi$ [$J$] ")
plt.legend()
plt.show()


