string = raw_input()

P = string.count('P')
A = string.count('A')
T = string.count('T')
e = string.count('e')
s = string.count('s')
t = string.count('t')

output = ''

while P + A + T + e + s + t:
	if P:
		output += 'P'
		P -= 1
	if A:
		output += 'A'
		A -= 1
	if T:
		output += 'T'
		T -= 1
	if e:
		output += 'e'
		e -= 1
	if s:
		output += 's'
		s -= 1
	if t:
		output += 't'
		t -= 1

print output
