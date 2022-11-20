import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
import warnings
import sys


filename = sys.argv[1]


warnings.filterwarnings("ignore" )
datas = []

# for temperature in temperatures:
datas.append(pd.read_csv(filename,header=None))



for data in datas:
	n_cycles = len(data[0])
	eps = data[0]
	e_eps = data[1]
	e_abs_m = data[2]
	c_v = data[3]
	chi = data[4]


	plt.plot(np.arange(n_cycles), e_eps, label=r"$\epsilon$")
	plt.plot(np.arange(n_cycles), e_abs_m, label=r"$|m|$")
	plt.legend()
	plt.show()