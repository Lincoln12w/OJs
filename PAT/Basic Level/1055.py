temp = raw_input().split()

N = int(temp[0])
n = int(temp[1])

lines = N / n
last = N - lines * n
graduates = []

for i in range(0, N):
    temp = raw_input().split()
    index = str(1300-int(temp[1])) + temp[0]
    graduates.append([index, temp[0]])

graduates.sort()

center = 0

for i in range(0,n):
    size = lines
    if i == 0:
        size += last
    half = size / 2
    for j in range(0, half):
        print graduates[center + 2 * (half - j) - 1][1],
    remain = size - half
    for j in range(0, remain - 1):
        print graduates[center + 2 * j][1],
    print graduates[center + 2 * (remain-1)][1]
    center += size
