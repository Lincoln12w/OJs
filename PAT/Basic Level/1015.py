class Student:
    def __init__(self, index, ID, dscore, cscore):
        self.index = index
        self.ID = ID
        self.dscore = dscore
        self.cscore = cscore

def compare(a, b):
    if a.index < b.index:
        return 1
    #if a.index == b.index:
    #    if a.ID > b.ID:
    #        return 1
    return -1

temp = raw_input().split()

number = int(temp[0])
lowline = int(temp[1])
highline = int(temp[2])

firstClass = []     # c > H && d > H
secondClass = []    # c < H && d > H
thirdClass = []     # c < H && d < H && d > c
finalClass = []     # 

for i in range(0, number):
    student = raw_input().split()
    ID = int(student[0])
    dScore = int(student[1])
    cScore = int(student[2])
    index = long(((dScore + cScore) * 1000 + dScore + 1) * 100000000 - ID)
    if dScore >= lowline and cScore >= lowline:
        xman = Student(index, ID, dScore, cScore)
        if dScore >= highline:
            if cScore >= highline:
                firstClass.append(xman)
            else:
                secondClass.append(xman)
        else:
            if dScore >= cScore:
                thirdClass.append(xman)
            else:
                finalClass.append(xman)

firstClass.sort(compare)
secondClass.sort(compare)
thirdClass.sort(compare)
finalClass.sort(compare)

print len(firstClass) + len(secondClass) + len(thirdClass) + len(finalClass)
for student in firstClass:
    print "%d %d %d" %(student.ID, student.dscore, student.cscore)
for student in secondClass:
    print "%d %d %d" %(student.ID, student.dscore, student.cscore)
for student in thirdClass:
    print "%d %d %d" %(student.ID, student.dscore, student.cscore)
for student in finalClass:
    print "%d %d %d" %(student.ID, student.dscore, student.cscore)           
