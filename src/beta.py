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
plt.xlabel(r" Temperature [$k_B$] ")
plt.ylabel(r" Energy [$J$] ")
plt.legend()
plt.show()

plt.plot(temperature,magnetization,label = "Predicted")
plt.title(r" Mean magnetization" + title_extension)
plt.xlabel(r" Temperature [$k_B$] ")
plt.ylabel(r" Magnetization ")
plt.legend()
plt.show()

plt.plot(temperature,c_V,label = "Predicted")
plt.title(r" $c_V$" + title_extension)
plt.xlabel(r" Temperature [$k_B$] ")
plt.ylabel(r" Energy [$J$] ")
plt.legend()
plt.show()

plt.plot(temperature,chi,label = "Predicted")
plt.title(r" chi" + title_extension)
plt.xlabel(r" Temperature [$k_B$] ")
plt.ylabel(r" $\chi$ [$J$] ")
plt.legend()
plt.show()