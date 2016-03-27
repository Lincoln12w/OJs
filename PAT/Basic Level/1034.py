def gcd(a, b):
    if a % b == 0:
        return b
    return gcd(b, a%b)

def printnumber(A, B):
    if B == 0:
        return 'Inf'
    if A == 0:
        return '0'
    num = ''
    negative = False
    if A * B < 0:
        num += '(-'
        negative = True
        if A < 0:
            A = -A
        else:
            B = -B
    gcdab = gcd(A, B)
    A /= gcdab
    B /= gcdab
    a = A / B
    b = A % B
    if a != 0:
        num += str(a)
    if b != 0:
        if a != 0:
            num += ' '
        num += str(b)
        num += '/'
        num += str(B)
    if negative:
        num += ')'
    return num

temp = raw_input()

numbers = []
index = 0
num = ''
while index < len(temp):
    digit = temp[index]
    if digit != '/' and digit != ' ':
        num += digit
    else:
        numbers.append(num)
        num = ''
    index += 1
numbers.append(num)
a1 = int(numbers[0])
b1 = int(numbers[1])
a2 = int(numbers[2])
b2 = int(numbers[3])

strsum = printnumber(a1,b1) + ' + ' + printnumber(a2,b2) + ' = '
suma = a1 * b2 + a2 * b1
sumb = b1 * b2
strsum += printnumber(suma,sumb)
print strsum

strsum = printnumber(a1,b1) + ' - ' + printnumber(a2,b2) + ' = '
suma = a1 * b2 - a2 * b1
sumb = b1 * b2
strsum += printnumber(suma,sumb)
print strsum

strsum = printnumber(a1,b1) + ' * ' + printnumber(a2,b2) + ' = '
suma = a1 * a2
sumb = b1 * b2
strsum += printnumber(suma,sumb)
print strsum

strsum = printnumber(a1,b1) + ' / ' + printnumber(a2,b2) + ' = '
suma = a1 * b2
sumb = b1 * a2
strsum += printnumber(suma,sumb)
print strsum

