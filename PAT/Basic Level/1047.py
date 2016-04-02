n = input()

teams = {}

highscore = 0
winner = ''

for i in range(0,n):
    member = raw_input().split()
    team = member[0].split('-')[0]
    if teams.has_key(team):
        teams[team] += int(member[1])
    else:
        teams[team] = int(member[1])
    score = teams[team]
    if score > highscore:
        highscore = score
        winner = team

print "%s %d" %(winner, highscore)
