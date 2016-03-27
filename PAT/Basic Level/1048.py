digits = ['0','1','2','3','4','5','6','7','8','9','J','Q','K']

(numberA, numberB) = raw_input().split()
numberC = ''

a = len(numberA)
b = len(numberB)
if b > a:
    numberC = numberB[0:b - a]
else:
	if b < a:								# consider this situation Bad PAT!!!
		temp = (a - b) * '0' + numberB
		numberB = temp
		b = a

for i in range(min(a, b), 0, -1):
    digitA = int(numberA[a - i])
    digitB = int(numberB[b - i])
    if i % 2:
        numberC += digits[(digitA + digitB) % 13]
    else:
        numberC += str((digitB - digitA + 10) % 10)

print numberC
