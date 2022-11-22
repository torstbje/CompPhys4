import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
import warnings
import sys


filetags = sys.argv[1]
filename = "textfiles/t-cv-chi-" + filetag + ".txt"
warnings.filterwarnings("ignore" )

for filetag in filetags:
    filename = "textfiles/t-cv-chi-" + filetag + ".txt"
    
# for temperature in temperatures:
data = pd.read_csv(filename,header=None)

temp = data[0]
mean_energy = data[1]
mean_magnetisation = data[2]
cv = data[3]
chi = data[4]

fig, ax = plt.subplots(nrows=2, ncols=2, figsize=(10,10))

ax[0][0].plot(temp, cv)
ax[0][0].set_title("Specific heat capacity vs Temperature")
ax[0][0].set_xlabel(r"Tmepperature $(J/k_B)$")
ax[0][0].set_ylabel(r"Specific heat capacity $(k_B)$")

ax[0][1].plot(temp, chi)
ax[0][1].set_title("Magenetic susceptibility vs Temperature")
ax[0][1].set_xlabel(r"Tmepperature $(J/k_B)$")
ax[0][1].set_ylabel(r"Magenetic susceptibility $(1/J)$")

ax[1][0].plot(temp, mean_energy)
ax[1][0].set_title("Mean Energy vs Temperature")
ax[1][0].set_xlabel(r"Tmepperature $(J/k_B)$")
ax[1][0].set_ylabel(r"Mean Energy $(J)$")

ax[1][1].plot(temp, mean_magnetisation)
ax[1][1].set_title("Mean Absolute Magnetisation vs Temperature")
ax[1][1].set_xlabel(r"Tmepperature $(J/k_B)$")
ax[1][1].set_ylabel(r"Mean Absolute Magnetisation $(unitless)$")

plt.savefig("plots/temp" + filetag + ".pdf")
plt.close()
