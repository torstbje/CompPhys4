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
c_v = data[2]
chi = data[3]
temperature = data[4]


# Make subplot configuration
fig, ax = plt.subplots(nrows=2, ncols=2, figsize=(8,8))

ax[0,0].plot(energy,temperature)
ax[0,0].set_title(r"Mean energy per particle $\langle \epsilon \rangle$")
ax[0,0].set_ylabel(r"Temperature [$k_B$]")

ax[0,1].plot(magnetization,temperature)
ax[0,1].set_title(r"Mean magnetization per particle $\langle |m| \rangle$")
ax[0,1].set_ylabel(r"Temperature [$k_B$]")


ax[1,0].plot(c_v,temperature)
ax[1,0].set_title(r"Specific heat capacity $c_V$")
ax[1,0].set_ylabel(r"Temperature [$k_B$]")


ax[1,1].plot(chi,temperature)
ax[1,1].set_title(r"Magnetic susceptibility $\chi$")
ax[1,1].set_ylabel(r"Temperature [$k_B$]")

plt.suptitle(r" Statisctical quantities calculated for the $2\times2$ lattice over temperature")
plt.savefig("plots/simple.pdf")
plt.show()


plt.close()
