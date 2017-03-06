
def gcd(a, b):
	if a < b:
		[a,b] = [b,a]
	if a % b == 0:
		return b
	return gcd(b, a%b)


temp = raw_input().split()

[numerator1, denominator1] = temp[0].split('/')
[numerator2, denominator2] = temp[1].split('/')
N = int(temp[2])

if N == 1:
	exit(-1)

multiple = int(denominator1) * int(denominator2)

beg = int(numerator1) * int(denominator2) * N
end = int(numerator2) * int(denominator1) * N 

if beg > end:
	[beg, end] = [end, beg]

beg = beg / multiple + 1
end = (end + multiple - 1) / multiple

#if end % multiple:
#	end = end / multiple + 1
#else:
#	end = end / multiple

for n in range(beg, end):
	if gcd(N, n) == 1:
		print str(n) + '/' + str(N),