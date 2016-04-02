def getinfo(poly):
	string = raw_input().split()
	for i in range(0, int(string[0])):
		ni = string[2*i+1]
		ki = float(string[2*i+2])
		if poly.has_key(ni):
			poly[ni] += ki
		else:
			poly[ni] = ki
		if poly[ni] == 0:
			poly.pop(ni)				# for == 0

polynomials = {}

getinfo(polynomials)
getinfo(polynomials)

print len(polynomials),
if len(polynomials):
	keys = polynomials.keys()
	keys.sort(reverse=True)

	for key in keys:
		print "%s %.1f" %(key,polynomials[key]),
