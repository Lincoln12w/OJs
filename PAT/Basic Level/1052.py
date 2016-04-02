def getstr(temp):
	index = 0
	value = []
	cnt = len(temp)
	for index in range(0,cnt):
		if temp[index] == '[':
			s = ''
			index += 1
			while temp[index] != ']':
				s += temp[index]
				index += 1
			value.append(s)

	return value

temp = raw_input()
hands = getstr(temp)
nhands = len(hands)

temp = raw_input()
eyes = getstr(temp)
neyes = len(eyes)

temp = raw_input()
mouthes = getstr(temp)
nmouthes = len(mouthes)

n = int(raw_input())

for i in range(0, n):
	indexs = raw_input().split()
	me = ''
	lh = int(indexs[0]) - 1
	le = int(indexs[1]) - 1
	mo = int(indexs[2]) - 1
	re = int(indexs[3]) - 1
	rh = int(indexs[4]) - 1

	if lh in range(0,nhands) and le in range(0,neyes) and mo in range(0,nmouthes) and re in range(0,neyes) and rh in range(0,nhands):
		me = hands[lh] + '(' + eyes[le] + mouthes[mo] + eyes[re] + ')' + hands[rh]
		print me
	else:
		print "Are you kidding me? @\/@"
