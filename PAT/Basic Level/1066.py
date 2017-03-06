temp = raw_input().split()

M = int(temp[0])
N = int(temp[1])
beg = int(temp[2])
end = int(temp[3])
val = int(temp[4])

for i in range(M):
	line = raw_input().split()
	for j in range(N-1):
		pixel = int(line[j])
		if pixel >= beg and pixel <= end:
			print "%03d" % val,
		else:
			print "%03d" % pixel,
	pixel = int(line[N-1])
	if pixel >= beg and pixel <= end:
		print "%03d" % val
	else:
		print "%03d" % pixel