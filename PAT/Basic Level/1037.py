temp = raw_input().split()

cost = [int(num) for num in temp[0].split('.')]
paid = [int(num) for num in temp[1].split('.')]

totalcost = (cost[0] * 17 + cost[1]) * 29 + cost[2]
totalpaid = (paid[0] * 17 + paid[1]) * 29 + paid[2]

left = totalpaid - totalcost

output = ''

if left < 0:
	output += '-'
	left *= -1
output += str(left / (17 * 29))
left %= (17 * 29)
output += '.'
output += str(left / 29)
left %= 29
output += '.'
output += str(left)

print output