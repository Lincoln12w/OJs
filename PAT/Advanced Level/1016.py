'''
input(N, records, beg, end, before, during, after):

for i in range(0,N):
	record = raw_input().split()
	name = record[0]
	record = [record[1],record[2]]
	if records.has_key(name):
	    records[name].append(record)
	else:
	    records[name] = [record]

for key in records:
	record = sorted(records[key])
	before()
	i = 0
	n = len(record)
	while i < n:
		if i + 1 < n and record[i][1] == beg and record[i+1][1] == end:
			during()
			i += 2
		else:
			i += 1
	after()
'''

def getbill(online, offline):
	(dd1, hh1, mm1) = [int(digit) for digit in online.split(':')]
	(dd2, hh2, mm2) = [int(digit) for digit in offline.split(':')]
	time = (dd2 - dd1) * 1440 + (hh2 - hh1) * 60 + mm2 - mm1
	bill = 0
	days = time / 1440
	minutes = time % 1440
	if days:
		bill += days * daybill
		dd2 -= days
	if minutes > 720:



	else:
		


	return (bill / 100.,time)


rates = [int(n) for n in raw_input().split()]

daybill = 0
for rate in rates:
	daybill += rate * 60

print daybill

N = input()

records = {}

for i in range(0,N):
	record = raw_input().split()
	name = record[0]
	record = [record[1],record[2]]
	if records.has_key(name):
	    records[name].append(record)
	else:
	    records[name] = [record]

keys = sorted(key for key in records)
for key in keys:
	record = sorted(records[key])
	n = len(record)
	i = 0
	total = 0
	print "%s %s" %(key, record[0][0].split(':')[0])
	while i < n:
		if i + 1 < n and record[i][1] == 'on-line' and record[i+1][1] == 'off-line':
			online = record[i][0][3:]
			offline = record[i+1][0][3:]
			(bill,time) = getbill(online, offline)
			total += bill
			print "%s %s %d $%.2f" %(online, offline, time, bill)
			i += 2
		else:
			i += 1

	print "Total amount: $%.2f" %(total)
