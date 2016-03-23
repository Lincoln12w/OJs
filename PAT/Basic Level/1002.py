numbers = ["ling","yi","er","san","si","wu","liu","qi","ba","jiu"]
number = list(raw_input())

sum = 0
for n in number:
    sum += int(n) - int('0')

digits = list(str(sum))
for digit in digits:
    print numbers[int(digit) - int(0)], # add , to avoid change line
