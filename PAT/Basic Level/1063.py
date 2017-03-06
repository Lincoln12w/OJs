import math

N = int(raw_input())

max_radius = 0

for i in range(N):
	[a, b] = raw_input().split()
	radius = math.sqrt(int(a)**2 + int(b)**2)
	if radius > max_radius:
		max_radius = radius
print '%.2f' % max_radius