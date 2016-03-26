p = int(raw_input().split()[1])

temp = raw_input().split()
numbers = [int(i) for i in temp]
n = len(numbers)

numbers.sort()

max = 1
for i in range(0, n):
    a = numbers[i] * p
    j = i + max
    while j < n:
        if a < numbers[j]:
            break
        j += 1
    max = j - i

print max

