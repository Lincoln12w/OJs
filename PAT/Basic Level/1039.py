shop = raw_input()
iwant = raw_input()

dicts = {}

for i in range(0, len(shop)):
    boll = shop[i]
    if dicts.has_key(boll):
        dicts[boll] += 1
    else:
        dicts[boll] = 1
buy = True
misscnt = 0
for i in range(0, len(iwant)):
    boll = iwant[i]
    if dicts.has_key(boll) and dicts[boll] > 0:
        dicts[boll] -= 1
    else:
        buy = False
        misscnt += 1

if buy:
    print "Yes %d" %(len(shop) - len(iwant))
else:
    print "No %d" %(misscnt) 
