def gcd(x, y):
    if x % y == 0:
        return y
    return gcd(y, x % y)

shift = int(raw_input().split()[1])

temp = raw_input().split()
numbers = [int(i) for i in temp]
n = len(numbers)

shift %= n

for i in range(0, gcd(shift, n)):
    indexf = (i - shift) % n
    indexr = i
    number = numbers[i]
    while indexf != i:
        numbers[indexr] = numbers[indexf]
        indexr = indexf
        indexf = (indexf - shift) % n
    numbers[indexr] = number

for i in range(0, n):
    print numbers[i],
