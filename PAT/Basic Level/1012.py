numbers = raw_input().split()

A1 = 0
A2 = 0
a2flag = 1
a2null = True
A3 = 0
A4 = 0
a4cnt = 0
A5 = 0

for i in range(1, len(numbers)):
    num = int(numbers[i])
    digit = num % 5
    if digit == 0:
        if num % 2 == 0:
            A1 += num
    if digit == 1:
        A2 += num * a2flag
        a2null = False
        a2flag *= -1
    if digit == 2:
        A3 += 1
    if digit == 3:
        A4 += num
        a4cnt += 1
    if digit == 4:
        if num > A5:
            A5 = num

if A1 == 0:
    print 'N',
else:
    print A1,

if a2null:
    print 'N',
else:
    print A2,

if A3 == 0:
    print 'N',
else:
    print A3,

if A4 == 0:
    print 'N',
else:
    print "%.1f" %(A4 * 1.0 / a4cnt),

if A5 == 0:
    print 'N'
else:
    print A5


