digits = ['0','1','2','3','4','5','6','7','8','9','J','Q','K']

(numberA, numberB) = raw_input().split()
numberC = ''

a = len(numberA)
b = len(numberB)
if b > a:
    numberC = numberB[0:b-a]

c = min(a, b)
for i in range(0, c):
    digitA = int(numberA[a - c + i])
    digitB = int(numberB[b - c + i])
    if (c - i) % 2:
        numberC += digits[(digitA + digitB) % 13]
    else:
        num = (digitB - digitA + 10) % 10
        numberC += str(num)

while(numberC[0] == '0'):
    temp = numberC[1:]
    numberC = temp

print numberC
