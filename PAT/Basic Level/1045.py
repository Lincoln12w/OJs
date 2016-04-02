# LCS

n = int(raw_input())
inputs = [int(num) for num in raw_input().split()]

sinputs = sorted(inputs)
cnt = 0
outputs = []
maxnum = 0

for i in range(0, n):
    num = inputs[i]
    if num == sinputs[i]:
        if num >= maxnum:
            cnt += 1
            outputs.append(num)
    maxnum = max(num, maxnum)

print cnt
if cnt:
    for n in outputs:
        print n,
else:
    print ''
