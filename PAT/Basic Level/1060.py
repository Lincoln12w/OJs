N = int(raw_input())

days = sorted(raw_input().split(), key=lambda x:int(x), reverse=True)

i = 0

for i in range(N):
	if int(days[i]) <= i + 1:
		i = i - 1
		break
print i + 1