N = int(raw_input())

ropes = sorted([int(rope) for rope in raw_input().split()])

length = ropes[0]

for i in range(1,N):
	length = (length + ropes[i]) / 2.

print int(length)