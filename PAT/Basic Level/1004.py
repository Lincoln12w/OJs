class student:
    def __init__(self):
        self.name = ''
        self.ID = ''
        self.score = 0

number = int(raw_input())

best = student()
worst = student()
worst.score = 100

for i in range(0, number):
    stu = student()
    stu.name, stu.ID, score = raw_input().split()
    stu.score = int(score)
    if stu.score >= best.score:
        best = stu
    if stu.score <= worst.score:
        worst = stu

print "%s %s" %(best.name, best.ID)
print "%s %s" %(worst.name, worst.ID)

