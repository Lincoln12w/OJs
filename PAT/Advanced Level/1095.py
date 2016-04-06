def gettime(time):
    (hh,mm,ss) = [int(n) for n in time.split(':')]
    return hh * 3600 + mm * 60 + ss

(K, N) = [int(n) for n in raw_input().split()]

cars = {}

for i in range(0, K):
    record = raw_input().split()
    ID = record[0]
    record = [record[1],record[2]]
    if cars.has_key(ID):
        cars[ID].append(record)
    else:
        cars[ID] = [record]

longestTime = 0
longestCar = []
times = {}
for ID in cars:
    record = sorted(cars[ID])
    n = len(record)
    parktime = 0
    i = 0
    while i < n:
        if i + 1 < n and record[i][1] == 'in' and record[i+1][1] == 'out':
            tin = record[i][0]
            tout = record[i+1][0]
            parktime += gettime(tout) - gettime(tin)
            times[tout] = times[tout] - 1 if times.has_key(tout) else -1
            times[tin] = times[tin] + 1 if times.has_key(tin) else 1
            i += 2
        else:
            i += 1
    if parktime == longestTime:
        longestCar.append(ID)
    if parktime > longestTime:
        longestCar = [ID]
        longestTime = parktime

sortTime = sorted([item for item in times])

# o(N)
for i in range(0, N):
    time = raw_input()
    beg = 0
    prenum = 0
    while beg < len(times):
        if sortTime[beg] > time:
            print prenum
            break;
        prenum += times[sortTime[beg]]
        beg += 1
    if beg == len(times):
        print prenum

longestCar.sort()
for car in longestCar:
    print car,
print "%02d:%02d:%02d" %(longestTime / 3600, (longestTime % 3600) / 60, longestTime % 60)
