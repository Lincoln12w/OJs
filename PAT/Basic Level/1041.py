n = input()

students = {}

for i in range(0, n):
    ids = raw_input().split()
    ID = ids[0] + ' ' + ids[2]
    students[ids[1]] = ID

n = input()

checklist = raw_input().split()

for ID in checklist:
    print students[ID]
