brokenKeys = raw_input()
if brokenKeys.find('+') != -1:
	shiftBroken = True
else:
	shiftBroken = False

inputString = raw_input()
outputString = ''
for i in range(0, len(inputString)):
	key = inputString[i]
	if shiftBroken and key.isupper():
		continue
	if brokenKeys.find(key.upper()) != -1:
		continue
	outputString += key

print outputString

