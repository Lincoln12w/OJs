class problem:

	def __init__(self, s):
		temp = s.split()
		self._score = temp[0]
		self._total = temp[1]
		self._accurate = temp[2]
		self._options = temp[3:]
		self._error = 0

	@property
	def score(self):
		return self._score

	@property
	def total(self):
		return self._total

	@property
	def accuracy(self):
		return self._accurate

	@property
	def options(self):
		return self._options

	@property
	def error(self):
		return self._error

	@error.setter
	def error(self, e):
		self._error = e



temp = raw_input().split()

N = int(temp[0])
M = int(temp[1])

problems = []

for i in range(M):
	a = problem(raw_input())
	problems.append(a)

for i in range(N):
	student = raw_input()[1:-1].split(') (')
	score = 0
	for j in range(M):
		select = student[j].split()
		prob = problems[j]
		choose = select[0]
		if choose == prob.accuracy:
			#print select[1:]
			if select[1:] == prob.options:
				score += int(prob.score)
				continue
		prob.error = prob.error + 1
	print score

max_error = 0
max_list = []

for i in range(M):
	#print problems[i].error
	if problems[i].error == max_error:
		max_list.append(i+1)
	if problems[i].error > max_error:
		max_list = [i + 1]
		max_error = problems[i].error

if max_error == 0:
	print "Too simple"
else:
	print max_error,
	for n in max_list:
		print n,