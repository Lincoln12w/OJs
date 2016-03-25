n = int(raw_input())

for i in range(0, n):
    temp = raw_input().split()
    numbers = [int(a) for a in temp]
    [a,b,c] = numbers
    print "Case #%d:" %(i+1),
    if a > 0 and b > 0:
        if c < 0:
            print 'true'
        else:
            if a > c - b:
                print 'true'
            else:
                print 'false'
    else:
        if a < 0 and b < 0:
            if c > 0:
                print 'false'
            else:
                if a > c - b:
                    print 'true'
                else:
                    print 'false'
        else:
            if a + b > c:
                print 'true'
            else:
                print 'false'
