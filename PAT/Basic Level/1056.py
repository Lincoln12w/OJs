#import numpy as np

temp = raw_input().split()

N = int(temp[0])
num = 0;
duplicate = 0;

#digits = np.zeros(10)
digits = [0,0,0,0,0,0,0,0,0,0]


for i in range(0, N):
	digit = int(temp[i + 1])
	if(digits[digit] == 1):
		duplicate += 2 * digit
	if(digits[digit] == 0):
		num += digit
	digits[digit] += 1

print num * (N - 1) * 11 + duplicate