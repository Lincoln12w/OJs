n = int(raw_input())

numbers = raw_input().split()

# n * 1 + 2 * (n - 1) * 2 + 3 * (n - 2) * 3
sum = 0.00
for i in range(0, n):
    sum += float(numbers[i]) * (n - i) * (i + 1)

print "%.2f" %(sum)
