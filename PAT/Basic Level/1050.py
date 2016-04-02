N = int(raw_input())
numbers = [int(num) for num in raw_input().split()]
numbers.sort(reverse=True)

for m in range(int((N - 1) ** 0.5) + 1, N + 1):
	if N % m == 0:
		n = N / m
		break
matrix = N * [0]

directions = [[1,0],[0,1],[-1,0],[0,-1]]
direction = 0 
posx = -1
posy = 0
for index in range(0, N):
	while True:
		a = posx + directions[direction][0]
		b = posy + directions[direction][1]
		pos = a + b * n
		if a < n and b < m and matrix[pos] == 0: 
			break
		direction = (direction + 1) % 4
	posx = a
	posy = b
	matrix[pos] = numbers[index]

for i in range(0, N):
	if (i + 1) % n == 0:
		print matrix[i]
	else:
		print matrix[i],
