def ID(num):
	id = 0
	while(num):
		id += num % 10
		num /= 10
	return id

N = int(raw_input())

numbers = raw_input().split()

IDs = {}

for i in range(N):
	num = int(numbers[i])
	id = ID(num)
	IDs[id] = 1

print len(IDs)

for id in sorted(IDs):
	print id,

