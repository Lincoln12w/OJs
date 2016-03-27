import string

temp = raw_input()
temp += raw_input()
temp += raw_input()

sets = []
index = 0
cnt = len(temp)
while index < cnt:
	if temp[index] == '[':
		s = ''
		index += 1
		while temp[index] != ']':
			s += temp[index]
			index += 1
		sets.append(s)
	index += 1

n = int(raw_input())

for i in range(0, n):
	indexs = raw_input().split()
	flag = 0
	me = ''
	for j in range (0, 5):
		if int(indexs[j]) >= cnt:
			flag = 1
			break;
		me += temp[int(indexs[j])]
	if flag:
		print "Are you kidding me? @\/@"
	else:
		print me
