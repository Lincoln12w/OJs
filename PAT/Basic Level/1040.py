pats = raw_input()

numP = 0
numPA = 0
numPAT = 0

for i in range(0, len(pats)):
    if pats[i] == 'P':
        numP += 1
    if pats[i] == 'A':
        numPA += numP
        numPA %= 1000000007
    if pats[i] == 'T':
        numPAT += numPA
        numPAT %= 1000000007

print numPAT
