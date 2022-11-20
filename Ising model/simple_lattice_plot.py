import numpy as np
import matplotlib.pyplot as plt
import pandas as pd

datas = []
for temperature in temperatures:
	datas.append(pd.read_csv("textfiles/simple_mcmc.txt"))


for data in datas:
	n_cycles = len(data[0])
	eps = data[0]
	e_eps = data[1]
	e_abs_m = data[2]
	c_v = data[3]
	chi = data[4]


plt.plot()