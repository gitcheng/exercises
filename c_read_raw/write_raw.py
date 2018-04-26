import numpy as np

width, height = 80, 40

a = np.arange(width*height, dtype=np.uint16) * 3
a.tofile('data_80x40.raw')

