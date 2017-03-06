
temp = raw_input().split()

N = int(temp[0])
M = int(temp[1])

scores = raw_input().split()
answer = raw_input().split()


for i in range(N):
	student = raw_input().split()
	score = 0
	for j in range(M):
		if student[j] == answer[j]:
			score += int(scores[j])
	print score
	
