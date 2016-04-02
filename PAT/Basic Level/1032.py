N = int(raw_input())

schools = {}

highID = ''
highscore = 0

for i in range(0, N):
    temp = raw_input().split()
    ID = temp[0]
    score = int(temp[1])
    if schools.has_key(ID):
        schools[ID] += score
    else:
    schools[ID] = score
    if schools[ID] > highscore:
        highID = ID
        highscore = schools[ID]

print "%s %d" %(highID, highscore)
