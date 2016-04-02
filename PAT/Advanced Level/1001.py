(A,B) = raw_input().split()

C = int(A) + int(B)

output = ''

if C < 0:
	output += '-'
	C *= -1

c = str(C)
n = len(c)
if n < 3:
	output += c
else:
	k = n / 3
	left = n - 3 * k
	if left:
		for i in range(0, left):
			output += c[i]
		output += ','
	for i in range(0, k-1):
		base = left + i * 3
		output += (c[base] + c[base+1] + c[base+2] + ',')
	output += (c[n-3] + c[n-2] + c[n-1])

print output
