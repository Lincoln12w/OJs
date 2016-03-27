def isPrime(num):
	for i in range(2, int(num ** 0.5) + 1):
		if num % i == 0:
			return False
	return True

edge = raw_input().split()

beg = int(edge[0])
end = int(edge[1])

if beg <= 2:
	print 2,
n = 3
primecnt = 1
while primecnt < end:
	if isPrime(n):
		primecnt += 1
		if primecnt >= beg:
			if (primecnt - beg + 1) % 10 == 0:
				print n
			else:
				print n,
	n += 2
        
