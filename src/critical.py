import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
import warnings
import sys

<<<<<<< Updated upstream
# Stop warnings
warnings.filterwarnings("ignore" )

dims = [40,60,80,100]

energies = []
magnetization = []
c_V = []
chi = []
temperature = []
=======
>>>>>>> Stashed changes

assert(len(sys.argv) > 1)
warnings.filterwarnings("ignore" )

fig, ax = plt.subplots(nrows=2, ncols=2, figsize=(12,10))

for i in range(1, len(sys.argv)):
    print(i)
    filetag = sys.argv[i]
    filename = "textfiles/t-cv-chi " + filetag + ".txt"
    label = filetag.split(" ")[2]
#    print(filetag.split(' '))
    data = pd.read_csv(filename,header=None)
    temp = data[0]
    mean_energy = data[1]
    mean_magnetisation = data[2]
    cv = data[3]
    chi = data[4]

    ax[0][0].plot(temp, mean_energy, label=label)
    

    ax[0][1].plot(temp, mean_magnetisation, label=label)
   

<<<<<<< Updated upstream
for i in range(4):
	plt.plot(temperature[i],energies[i], label = "L: " + str(dims[i]))
plt.title(r" Mean energy" + title_extension)
plt.xlabel(r" Temperature [$J/k_B$] ")
plt.ylabel(r" Energy [$J$] ")
=======
    ax[1][0].plot(temp, cv, label=label)
    
>>>>>>> Stashed changes

    ax[1][1].plot(temp, chi, label=label)
    

ax[0][0].set_title("Mean Energy vs Temperature")
ax[0][0].set_xlabel(r"Temperature $(J/k_B)$")
ax[0][0].set_ylabel(r"Mean Energy $(k_B)$")

<<<<<<< Updated upstream
for i in range(4):
	plt.plot(temperature[i],magnetization[i], label = "L: " + str(dims[i]))
plt.title(r" Mean magnetization" + title_extension)
plt.xlabel(r" Temperature [$J/k_B$] ")
plt.ylabel(r" Magnetization ")
=======
ax[0][1].set_title("Mean Absolute Magnetisation vs Temperature")
ax[0][1].set_xlabel(r"Temperature $(J/k_B)$")
ax[0][1].set_ylabel(r"Mean Absolute Magnetisation $(1/J)$")
>>>>>>> Stashed changes

ax[1][0].set_title("Specific heat capacity vs Temperature")
ax[1][0].set_xlabel(r"Temperature $(J/k_B)$")
ax[1][0].set_ylabel(r"Specific heat capacity $(J)$")

ax[1][1].set_title("Magenetic susceptibility vs Temperature")
ax[1][1].set_xlabel(r"Temperature $(J/k_B)$")
ax[1][1].set_ylabel(r"Magenetic susceptibility $(unitless)$")

<<<<<<< Updated upstream
for i in range(4):
	plt.plot(temperature[i],c_V[i], label = "L: " + str(dims[i]))
plt.title(r" Specific heat capacity $c_V$" + title_extension)
plt.xlabel(r" Temperature [$J/k_B$] ")
plt.ylabel(r" $c_V$ [$J^{-1}$] ")
=======
ax[0][0].legend()
ax[0][1].legend()
ax[1][0].legend()
ax[1][1].legend()
>>>>>>> Stashed changes

plt.savefig("plots/temp" + filetag + ".pdf")
plt.close()
<<<<<<< Updated upstream


for i in range(4):
	plt.plot(temperature[i],chi[i], label = "L: " + str(dims[i]))
plt.title(r" Magnetic susceptibility" + title_extension)
plt.xlabel(r" Temperature [$J/k_B$] ")
plt.ylabel(r" $\chi$ [$k_B$] ")

plt.legend()
plt.savefig("plots/critical_chi.pdf")
plt.close()
=======
>>>>>>> Stashed changes
