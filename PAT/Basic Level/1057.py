temp = list(raw_input().lower())

num = 0
for pos in range(len(temp)):
	cc = temp[pos]
	if cc >= 'a' and cc <= 'z':
		num += ord(cc) - ord('a') + 1

ones = 0
zeros = 0

while num:
	if num % 2:
		ones += 1
	else:
		zeros += 1
	num /= 2

print zeros, ones