import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
import warnings

'''
Makes histogram plots for understanding distribution at given temperatures
'''


# Stop warnings
warnings.filterwarnings("ignore" )

# Collects data
data = pd.read_csv("textfiles/dist1.0.txt",header=None)

n_cycles = len(data[0])
energy1 = data[0]
data = pd.read_csv("textfiles/dist2.4.txt",header=None)

energy2 = data[0]


# Makes histograms
fig, ax = plt.subplots(nrows=1, ncols=2, figsize=(8,4.4))
ax[0].hist(energy1,density = True, stacked = True, color = "green", range = (-2,-1.9), bins = 5, label=r"T: $1.0$ J/$k_B$")
ax[1].hist(energy2,density = True, stacked = True, color = "green", range = (-2,-0.5), bins = 75, label=r"T: $2.4$ J/$k_B$")

ax[0].set_xlabel("Energy [ J ]")
ax[1].set_xlabel("Energy [ J ]")

ax[0].legend()
ax[1].legend()


plt.suptitle(r"Energy distribution of states at different temperatures"
"\n"
"("  + str(n_cycles) + r" cycles | $ 20\times 20 $ particles | Minumum $\Delta E: 0.02$J ) ")
plt.savefig("plots/distribution.pdf")
plt.close()
