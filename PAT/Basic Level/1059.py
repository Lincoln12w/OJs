#import numpy
import math

def is_prime(num):
	if num == 1:
		return False
	if num == 2:
		return True
	#print num, int(math.sqrt(num)) + 1, range(2, int(math.sqrt(num)) + 1)
	for i in range(2, int(math.sqrt(num)) + 1):
		#print num, i
		if num % i == 0:
			return False
	return True

N = int(raw_input())

ranks = {}
checked = []

for i in range(N):
	ID = raw_input()
	ranks[ID] = i + 1
	checked.append(1)

M = int(raw_input())

for i in range(M):
	ID = raw_input()
	if not ranks.has_key(ID):
		print ID + ": Are you kidding?"
		continue
	rank = ranks[ID]
	if not checked[rank-1]:
		print ID + ": Checked"
		continue
	if rank == 1:
		print ID + ": Mystery Award"
	elif is_prime(rank):
		print ID + ": Minion"
	else:
		print ID + ": Chocolate"
	checked[rank-1] = 0

	rank = ranks[ID]