temp = raw_input()
string = temp.upper()

dicts = {}

maxc = ''
maxcnt = 0

for c in string:
    if c.isupper():
        if dicts.has_key(c):
            dicts[c] += 1
        else:
            dicts[c] = 1
        cnt = dicts[c]
        if cnt > maxcnt or (cnt == maxcnt and c < maxc):
            maxcnt = cnt
            maxc = c

print "%s %d" %(maxc.lower(), maxcnt)
