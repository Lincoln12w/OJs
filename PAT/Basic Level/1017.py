inputs = raw_input().split()

number = inputs[0]
divider = int(inputs[1])

if int(number) < divider:
    print "0 %d" %(int(number))
else:
	ans = ''
	flag = 0
	for i in range(0,len(number)):
		num = flag * 10 + int(number[i])
		if num < divider:
			flag = num
	  		if i != 0:
				ans += '0'
			continue
		flag = num % divider
		ans += str(num / divider)

	print "%s %s" %(ans, flag)
