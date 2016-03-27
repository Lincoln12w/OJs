import math

def printComplex(A, B):
	if A == -0.00:
		A = 0.00
	if B == -0.00:
		B = 0.00
	if B < 0:
		print "%.2f%.2fi" %(A, B)
	else:
		print "%.2f+%.2fi" %(A, B)

(r1,p1,r2,p2) = raw_input().split()

R1 = float(r1)
R2 = float(r2)
P1 = float(p1)
P2 = float(p2)

a1 = R1 * math.cos(P1)
b1 = R1 * math.sin(P1)
a2 = R2 * math.cos(P2)
b2 = R2 * math.sin(P2)

A = round((a1 * a2 - b1 * b2) * 100) / 100
B = round((a1 * b2 + a2 * b1) * 100) / 100

'''
A = round((R1 * R2 * math.cos(P1 + P2)) * 100) / 100
B = round((R1 * R2 * math.sin(P1 + P2)) * 100) / 100
'''

printComplex(A, B)
