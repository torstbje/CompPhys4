import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
import warnings
import sys


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
   

    ax[1][0].plot(temp, cv, label=label)
    

    ax[1][1].plot(temp, chi, label=label)
    

ax[0][0].set_title("Mean Energy vs Temperature")
ax[0][0].set_xlabel(r"Temperature $(J/k_B)$")
ax[0][0].set_ylabel(r"Mean Energy $(k_B)$")

ax[0][1].set_title("Mean Absolute Magnetisation vs Temperature")
ax[0][1].set_xlabel(r"Temperature $(J/k_B)$")
ax[0][1].set_ylabel(r"Mean Absolute Magnetisation $(1/J)$")

ax[1][0].set_title("Specific heat capacity vs Temperature")
ax[1][0].set_xlabel(r"Temperature $(J/k_B)$")
ax[1][0].set_ylabel(r"Specific heat capacity $(J)$")

ax[1][1].set_title("Magenetic susceptibility vs Temperature")
ax[1][1].set_xlabel(r"Temperature $(J/k_B)$")
ax[1][1].set_ylabel(r"Magenetic susceptibility $(unitless)$")

ax[0][0].legend()
ax[0][1].legend()
ax[1][0].legend()
ax[1][1].legend()

plt.savefig("plots/temp" + filetag + ".pdf")
plt.close()
