n = raw_input()
numbers = raw_input().split()

totalsum = 0.0
validcnt = 0

for number in numbers:
    error = False
    firstDot = True
    value = 0.0
    tens = 0
    flag = 1
    num = number
    if number[0] == '-':
        num = number[1:]
        flag = -1;
    for digit in num:
        if digit.isdigit():
            value *= 10
            value += int(digit)
            if not firstDot:
                tens += 1
                if tens == 3:
                    error = True
                    break
            continue
        if digit == '.':
            if firstDot:
                firstDot = False
                continue
        error = True
        break
    if not error:
        value /= 10 ** tens
        value *= flag
        if value >= -1000 and value <= 1000:
            totalsum += value
            validcnt += 1
            continue
    print "ERROR: %s is not a legal number" %(number)

if validcnt:
    if validcnt == 1:
        print "The average of 1 number is %.2f" %(totalsum / validcnt)
    else:
        print "The average of %d numbers is %.2f" %(validcnt, totalsum / validcnt)
else:
    print "The average of 0 numbers is Undefined"
