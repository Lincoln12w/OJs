
temp = raw_input().split()

M = int(temp[0])
N = int(temp[1])
S = int(temp[2])

No = 1
winner = {}

for i in range(M):
	attender = raw_input()
	if No >= S and No % N == S % N:
		if not winner.has_key(attender):
			winner[attender] = 1
			print attender
		else:
			No -= 1
	No += 1
if M < S:
	print "Keep going..."