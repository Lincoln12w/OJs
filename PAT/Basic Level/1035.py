def gcd(x, y):
	if x % y == 0:
		return y
	return gcd(y, x % y)

N = int(raw_input())

origin = [int(num) for num in raw_input().split()]
sortedn = [int(num) for num in raw_input().split()]

insertLen = 0
insert = False
common = 1
pre = 0

for i in range(0, len(sortedn) - 1):
	if sortedn[i] > sortedn[i + 1]:
		current = i - 0 + 1
		if common == 1:
			common = current
			insertLen = current
			pre = i + 1
		else:
			if gcd(common, current) == 1:
				insert = True
				break
			common = gcd(common, current)

if insert:
	print "Insertion Sort"
	num = sortedn[insertLen]
	flag = 1
	for i in range(0, insertLen):
		if flag and sortedn[i] > num:
			print num,
			flag = 0
		print sortedn[i],
	for i in range(insertLen + 1, N):
		print sortedn[i],
else:
	print "Merge Sort"
	a = 0
	b = common
	while N > b:
		i = 0
		j = 0
		while( i < common and j < min(N - b, common)):
			if sortedn[a+i] < sortedn[b+j]:
				print sortedn[a+i],
				i += 1
			else:
				print sortedn[b+j],
				j += 1
		for ii in range(i, common):
			print sortedn[a+ii],
		for jj in range(j, min(N - b, common)):
			print sortedn[b+jj],
		a += 2 * common
		b += 2 * common
	for i in range(a, N):
		print sortedn[i],

