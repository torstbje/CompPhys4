import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
import warnings

warnings.filterwarnings("ignore" )


for temperature in ["1.0","2.4"]:
	fig, ax = plt.subplots(nrows=1, ncols=2, figsize=(8,4))
	for align in ["aligned","unaligned"]:

		filename = "textfiles/burn_" + align + "_" + temperature + ".txt"
		
		data = pd.read_csv(filename,header=None)
		energy = data[0]
		magnetization = data[1]
		n_cycles = np.arange(len(energy))

		ax[0].plot(n_cycles, energy, label = align)
		ax[1].plot(n_cycles, magnetization, label = align)


	ax[0].set_title(r"""$\langle \epsilon \rangle$ vs number of cycles
T = """ + temperature)
	ax[0].set_xlabel("Number of cycles")
	ax[0].set_ylabel("Energy: [J]")
	ax[0].legend()



	ax[1].set_title(r"""$\langle |m| \rangle$ vs number of cycles
T = """ + temperature)
	ax[1].legend()
	ax[1].set_xlabel("Number of cycles")
	ax[1].set_ylabel("Magnetization")

	plt.savefig("plots/burn_" + temperature +".pdf")
	plt.show()
	plt.close()
