temp = raw_input().split()

n = int(temp[0])
c = temp[1]

a = (n + 1) / 2 - 2

print n * c
for i in range(0,a):
    print c + (n - 2) * ' ' + c
print n * c
