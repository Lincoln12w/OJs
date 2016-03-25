number = int(raw_input())

bai = number / 100
number %= 100
shi = number / 10
number %= 10
strnum = bai * 'B'
strnum += shi * 'S'
for i in range(0, number):
    strnum += str(i+1)

print strnum
