p = int(raw_input().split()[1])

temp = raw_input().split()
numbers = [int(i) for i in temp]
n = len(numbers)

numbers.sort()

max = 0

for i in range(0, n):
    cnt = 1
    for j in range(i + 1, n):
        if numbers[i] * p > numbers[j]:
            cnt += 1
    if cnt > max:
        max = cnt
    if cnt == n - i:
        break

print max

