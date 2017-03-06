temp = raw_input().split()

passwd = temp[0]
N = int(temp[1])

for i in range(N):
	try_passwd = raw_input()
	if try_passwd == passwd:
		print "Welcome in"
		exit(0)
	else:
		if try_passwd == '#':
			exit(0)
		print "Wrong password: " + try_passwd
print "Account locked"
exit(0)