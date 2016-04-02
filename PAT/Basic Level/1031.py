n = int(raw_input())

weight = [7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2]
mask = ['1','0','X','9','8','7','6','5','4','3','2']

allPass = True

for i in range(0, n):
    number = raw_input()
    digits = number[:17]
    M = number[17]
    if digits.isdigit():
        checksum = 0
        for i in range(0,17):
            checksum += int(digits[i]) * weight[i]
        checksum %= 11
        if M == mask[checksum]:
            continue
    allPass = False
    print number

if allPass:
    print "All passed"


