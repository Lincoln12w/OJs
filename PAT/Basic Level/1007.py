# varify each prime
'''
def isPrime(num):
    if num == 2:
        return True
    if num % 2 == 0:
        return False
    i = 3
    #while i * i <= num:
    a = num ** 0.5
    while i <= a:
        if num % i == 0:
            return False
        i += 2
    return True

number = int(raw_input())

if number == 2:
    print 0
else:
    primes = [2]
    i = 3
    while i <= number:
        if isPrime(i):
            primes.append(i)
        i += 2
    cnt = 0
    for i in range(0, len(primes) - 1):
        if primes[i+1] - primes[i] == 2:
            cnt += 1
    print cnt
'''

# remove out each not prime

number = int(raw_input())

if number == 2:
    print 0
else:
    numbers = []

    for i in range(0, number):
        numbers.append(i+1)

    numbers[0] = 0

    num = 2
    while num < number:
        for i in range(2, number / num + 1):
            numbers[i * num - 1] = 0
        num += 1
        while num < number and numbers[num - 1] == 0:
            num += 1

    '''
    primes = [numbers[i] for i in range(0, len(numbers)) if not numbers[i] == 0]
    cnt = 0
    for i in range(0, len(primes) - 1):
        if primes[i + 1] - primes[i] == 2:
            cnt += 1
    print cnt
    '''

    cnt = 0
    for i in range(0, len(numbers) - 2):
        if numbers[i] and numbers[i + 2]:
            cnt += 1
    print cnt


