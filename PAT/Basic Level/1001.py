number = int(raw_input())
count = 0

while number != 1:
    if number % 2:
        number = number * 3 + 1
    number /= 2
    count += 1

print count
