inputs = raw_input().split()

number1 = inputs[0]
digit1 = inputs[1]
number2 = inputs[2]
digit2 = inputs[3]

num1 = 0
num2 = 0
for digit in number1:
    if digit == digit1:
        num1 *= 10
        num1 += int(digit)

for digit in number2:
    if digit == digit2:
        num2 *= 10
        num2 += int(digit)

print num1 + num2
