import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
import warnings
import sys


filename = sys.argv[1]


warnings.filterwarnings("ignore" )

# for temperature in temperatures:
data = pd.read_csv(filename,header=None)



n_cycles = len(data[0])
eps = data[0]
e_eps = data[1]
e_abs_m = data[2]
c_v = data[3]
chi = data[4]


fig, ax = plt.subplots(nrows=1, ncols=2, figsize=(8,3))
ax[0].plot(np.arange(n_cycles), e_eps, label=r"$\langle \epsilon \rangle$")
ax[0].plot(np.arange(n_cycles), e_abs_m, label=r"$|m|$")
ax[0].set_title(r"$\langle \epsilon \rangle$ and $|m|$ vs number of cycles.")
ax[0].legend()

ax[1].hist(eps, label=r"Energies ($\epsilon$)")
ax[1].set_title(r"($\epsilon$) sample histogram")
plt.savefig("plots/" + filename[10:-4]+'.pdf')
plt.legend()
plt.close()
