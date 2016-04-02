temp = raw_input().split()

N = int(temp[0])
e = float(temp[1])
D = int(temp[2])

maybe = 0.0
mustbe = 0.0

for i in range(0, N):
    temp = raw_input().split()
    total = int(temp[0])
    empty = 0
    for j in range(1, total + 1):
        if float(temp[j]) < e:
            empty += 1
    if empty > (total / 2):
        if total > D:
            mustbe += 1
        else:
            maybe += 1

print "%.1f%% %.1f%%" %(maybe * 100 / N, mustbe * 100 / N)


