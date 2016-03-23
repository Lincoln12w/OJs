# Assume aPbTc:
#   a * b = c & b >= 1

times = int(raw_input())

def varifyAnswer(answer):
    np = answer.count('P')
    if np != 1:         # XXXTxxx   xxxPxxPxxTxxx
        print 'NO'
        return
    p = answer.find('P')
    nt = answer.count('T')
    if nt != 1:         # xxxPxxx   xxxPxxTxxTxxx
        print 'NO'
        return
    t = answer.find('T')
    l = len(answer)
    na = answer.count('A')
    if na + 2 != l:     # UTAP
        print 'NO'
        return
    if t - p == 1:      # PT
        print 'NO'
        return
    if p * (t - p - 1) != (l - t - 1):
        print 'NO'      # not legal, xxxTxxxPxxx
        return
    print 'YES'

for i in range(0, times):
    answer = raw_input()
    varifyAnswer(answer)
