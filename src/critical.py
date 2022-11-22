import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
import warnings

# Stop warnings
warnings.filterwarnings("ignore" )

dims = [20,40,60,80,100]

energies = []
magnetization = []
c_V = []
chi = []
temperature = []

title_extension  = " over temperature"

for dim in dims:
	data = pd.read_csv("textfiles/beta" + str(dim) + ".txt",header=None)
	energies.append(data[0])
	magnetization.append(data[1])
	c_V.append(data[2])
	chi.append(data[3])
	temperature.append(data[4])





for i in range(5):
	plt.plot(temperature[i],energies[i], label = "L: " + str(dims[i]))
plt.title(r" Mean energy" + title_extension)
plt.xlabel(r" Temperature [$J/k_B$] ")
plt.ylabel(r" Energy [$J$] ")

plt.legend()
plt.savefig("plots/critical_energy.pdf")
plt.close()


for i in range(5):
	plt.plot(temperature[i],magnetization[i], label = "L: " + str(dims[i]))
plt.title(r" Mean magnetization" + title_extension)
plt.xlabel(r" Temperature [$J/k_B$] ")
plt.ylabel(r" Magnetization ")

plt.legend()
plt.savefig("plots/critical_mag.pdf")
plt.close()


for i in range(5):
	plt.plot(temperature[i],c_V[i], label = "L: " + str(dims[i]))
plt.title(r" Specific heat capacity $c_V$" + title_extension)
plt.xlabel(r" Temperature [$J/k_B$] ")
plt.ylabel(r" $c_V$ [$J^{-1}$] ")

plt.legend()
plt.savefig("plots/critical_cv.pdf")
plt.close()


for i in range(5):
	plt.plot(temperature[i],chi[i], label = "L: " + str(dims[i]))
plt.title(r" Magnetic susceptibility" + title_extension)
plt.xlabel(r" Temperature [$J/k_B$] ")
plt.ylabel(r" $\chi$ [$k_B$] ")

plt.legend()
plt.savefig("plots/critical_chi.pdf")
plt.close()