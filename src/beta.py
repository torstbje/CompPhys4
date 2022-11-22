import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
import warnings
import sys

# Stop warnings
warnings.filterwarnings("ignore" )

filename = sys.argv[1]
L = filename[4:]
title_extension = r" for the $" + L + r"\times" + L + r"$ lattice "


# Collect data
data = pd.read_csv("textfiles/" + filename + ".txt",header=None)
energy = data[0]
magnetization = data[1]
c_V = data[2]
chi = data[3]
temperature = data[4]



plt.plot(temperature,energy,label = "Predicted")
plt.title(r" Mean energy" + title_extension)
plt.xlabel(r" Temperature [$J/k_B$] ")
plt.ylabel(r" Energy [$J$] ")
plt.savefig("plots/" + filename + "_energy.pdf")
plt.close()

plt.plot(temperature,magnetization,label = "Predicted")
plt.title(r" Mean magnetization" + title_extension)
plt.xlabel(r" Temperature [$J/k_B$] ")
plt.ylabel(r" Magnetization ")
plt.savefig("plots/" + filename + "_mag.pdf")
plt.close()

plt.plot(temperature,c_V,label = "Predicted")
plt.title(r" Specific heat capacity $c_V$" + title_extension)
plt.xlabel(r" Temperature [$J/k_B$] ")
plt.ylabel(r" $c_V$ [$1/J$] ")
plt.savefig("plots/" + filename + "_cv.pdf")
plt.close()

plt.plot(temperature,chi,label = "Predicted")
plt.title(r" Magnetic susceptibility" + title_extension)
plt.xlabel(r" Temperature [$J/k_B$] ")
plt.ylabel(r" $\chi$ [$k_B$] ")

plt.savefig("plots/" + filename + "_chi.pdf")
plt.close()