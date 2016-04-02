mars = ["tret","jan","feb","mar","apr","may","jun","jly","aug","sep","oct","nov","dec","tam","hel","maa","huh","tou","kes","hei","elo","syy","lok","mer","jou"]

n = int(raw_input())

for i in range(0, n):
	temp = raw_input()
	if temp.isdigit():
		num = int(temp)
		if num % 13:
			if num / 13:
				print mars[num / 13 + 12],
			print mars[num % 13]
		else:
			if num / 13:
				print mars[num / 13 + 12]
			else:
				print mars[0]
	else:
		nums = temp.split()
		index = mars.index(nums[0])
		num = 0
		if index > 12:
			num += (index - 12) * 13
		else:
			num += index
		if len(nums) == 2:
			num += mars.index(nums[1])
		print num

