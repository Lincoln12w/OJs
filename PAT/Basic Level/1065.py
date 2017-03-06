
N = int(raw_input())

couples = {}

for i in range(N):
	[male, female] = raw_input().split()
	couples[male] = female
	couples[female] = male

M = int(raw_input())

singles = {}

guests = raw_input().split()

for i in range(M):
	guest = guests[i]
	if not couples.has_key(guest):
		singles[guest] = 1
	else:
		if singles.has_key(couples[guest]):
			del singles[couples[guest]]
		else:
			singles[guest] = 1

print len(singles)

for dog in sorted(singles):
	print dog,
