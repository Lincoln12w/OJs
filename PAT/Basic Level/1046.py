n = input()

A = 0
B = 0

for i in range(0, n):
    rounds = [int(num) for num in raw_input().split()]
    total = rounds[0] + rounds[2]
    a = int(rounds[1])
    b = int(rounds[3])

    if a == total and b == total:
        continue
    if a == total:
        B += 1
    if b == total:
        A += 1

print "%d %d" %(A, B)

