num = int(raw_input())
oldday = 18140906
today = 20140906
oldBirth = 20140907
youngBirth = 18140905
validCnt = 0

for i in range(0,num):
    people = raw_input().split()
    birth = 0
    for c in people[1]:
        if c != '/':
            birth *= 10
            birth += int(c)
    if birth >= oldday and birth <= today:
        validCnt += 1
        name = people[0]
        if birth < oldBirth:
            oldBirth = birth
            oldest = name
        if birth > youngBirth:
            youngBirth = birth
            youngest = name

if validCnt:
    print "%d %s %s" %(validCnt, oldest, youngest)
else:
    print 0

