temp = raw_input().split()
digits = [int(i) for i in temp]

if len(digits) == 2 and digits[1] == 0:
	print "0 0"								# do not forget
else:
	for i in range(0, len(digits), 2):
	    if digits[i + 1]:
	        print digits[i] * digits[i + 1],
	        print digits[i + 1] - 1,
