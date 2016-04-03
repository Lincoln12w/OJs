(records, checktimes) = [int(n) for n in raw_input().split()]

times = {}
cars = {}

for i in range(0, records):
    record = raw_input().split()
    ID = record[0]
    (hh,mm,ss) = [int(n) for n in record[1].split(':')]
    time = hh * 3600 + mm * 60 + ss
    if record[2] == 'in':
        status = 1
    else:
        status = -1
    if times.has_key(time):
        times[time] += status
    else:
        times[time] = status
    if cars.has_key(ID):
        cars[ID].append([time, status])
    else:
        cars[ID] = [[time, status]]

longestTime = 0
longestCar = []
for ID in cars:
    record = sorted(cars[ID])
    n = len(record)
    parktime = 0
    i = 0
    while i < n:
        if i + 1 < n and record[i][1] == 1 and record[i + 1][1] == -1:
            parktime += record[i+1][0] - record[i][0]
            i += 2
            continue
        times.pop(record[i][0])
        i += 1
    if parktime == longestTime:
        longestCar.append(ID)
    if parktime > longestTime:
        longestCar = [ID]
        longestTime = parktime

sortTime = sorted([item for item in times])
ncar = 0
for time in sortTime:
    ncar += times[time]
    times[time] = ncar

for i in range(0, checktimes):
    (hh,mm,ss) = [int(n) for n in raw_input().split(':')]
    time = hh * 3600 + mm * 60 + ss
    for i in range(len(times) - 1, -1, -1):
        if sortTime[i] <= time:
            print times[sortTime[i]]
            break

for car in longestCar:
    print car,
print "%02d:%02d:%02d" %(longestTime / 3600, (longestTime % 3600) / 60, longestTime % 60)
