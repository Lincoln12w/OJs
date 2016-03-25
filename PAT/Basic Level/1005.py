n = int(raw_input())                # no need this arguments

temp = raw_input().split()
numbers = [int(i) for i in temp]    # change list from str to int

i = 0
while i < len(numbers):
    flag = 1
    number = numbers[i]
    while number != 1:
        if number % 2:
            number = 3 * number + 1
        number /= 2
        if numbers.count(number):
            numbers.remove(number)
            flag -= 1               # remember how many elements removed
    i += flag

numbers.sort(reverse=True)
for i in range(0, len(numbers)):
    print numbers[i],
