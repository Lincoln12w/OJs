n = int(raw_input())

scores = {}

for num in raw_input().split():
    if scores.has_key(num):
        scores[num] += 1
    else:
        scores[num] = 1
temp = raw_input().split()

for i in range(1, len(temp)):
    num = temp[i]
    if scores.has_key(num):
        print scores[num],
    else:
        print 0,
