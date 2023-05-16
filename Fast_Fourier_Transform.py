#  Recursive Fast Fourier Transform (FFT) applied
# to polynomial multiplication. The basic algorithm proceeds
# as followes:
# 1. Add n higher-order zero coefficients to A(x) and B(x)
# 2. Evaluate A(x) and B(x) using FFT for 2n points
# 3. Pointwise multiplication of point-value forms
# 4. Interpolate C(x) using FFT to compute inverse DFT
# FFT can perform Discrete Transform and Inverse Discrete
# Transform (IDFT) in average O(n log n) time.

from math import sin,cos,pi

# Recursive function of FFT
def fft(a):

	n = len(a)

	# if input contains just one element
	if n == 1:
		return [a[0]]

	# For storing n complex nth roots of unity
	theta = -2*pi/n
	w = list( complex(cos(theta*i), sin(theta*i)) for i in range(n) )
	
	# Separe coefficients
	Aeven = a[0::2]
	Aodd = a[1::2]

	# Recursive call for even indexed coefficients
	Yeven = fft(Aeven)

	# Recursive call for odd indexed coefficients
	Yodd = fft(Aodd)

	# for storing values of y0, y1, y2, ..., yn-1.
	Y = [0]*n
	
	middle = n//2
	for k in range(n//2):
		w_yodd_k = w[k] * Yodd[k]
		yeven_k = Yeven[k]
		
		Y[k]		 = yeven_k + w_yodd_k
		Y[k + middle] = yeven_k - w_yodd_k
	
	return Y


# Driver code
if __name__ == '__main__':

	a = [1, 2, 3, 4]
	b = fft(a)
	for B in b:
		print(B)
