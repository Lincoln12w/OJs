
def axis_is_leagal(size, axis):
	[X, Y] = size
	[x,y] = axis

	if x < 0 or x == X or y < 0 or y == Y:
		return False
	return True

def is_unique(pixels, pos, size, value, tol):
	[x,y] = pos
	bigger = True
	#print x, y
	for i in range(-1,2):
		for j in range(-1,2):
			nx = x + i - 1
			ny = y + j - 1
			if axis_is_leagal(size, [nx, ny]):
				if i != 0 or j != 0:
					# can be samller or bigger! Very tricky!!!
					bigger &= ((value - tol > int(pixels[nx][ny])) or (value + tol < int(pixels[nx][ny])))
	return bigger

temp = raw_input().split()

M = int(temp[0])
N = int(temp[1])
TOL = int(temp[2])

values = {}
result = {}
pixels = []

for i in range(N):
	rows = raw_input().split()
	pixels.append(rows)
	for j in range(M):
		pixel = rows[j]
		if not values.has_key(pixel):
			values[pixel] = [i+1, j+1]
		else:
			values[pixel] = [-1, -1]

for key in values:
	#print values[key]
	if (values[key] != [-1, -1]) and is_unique(pixels, values[key], [N, M], int(key), TOL):
		result[key] = values[key]

n = len(result)

if n == 0:
	print "Not Exist"
elif n > 1:
	print "Not Unique"
else:
	for key in result:
		[x, y] = result[key]
		print '(' + str(y) + ", " + str(x) + '): ' + key
