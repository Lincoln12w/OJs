class Solution(object):
    def findPairs(self, nums, k):
    	#nums = list(set(nums))
    	nums = sorted(nums)
    	i = 0
    	j = i + 1
    	cnt = 0
    	#print nums
    	while(j < len(nums)):
    		#print i, j
    		if nums[i] + k == nums[j]:
    			cnt += 1
    			i += 1
    			while i < len(nums) and nums[i] == nums[i-1]:
    				i += 1
    			if i >= j:
    				j = i + 1
    		elif nums[i] + k > nums[j]:
    			j += 1
    		else:
    			i += 1
    			if i == j:
    				j += 1
    	return cnt

s = Solution()

print s.findPairs([3,1,4,1,5], 2)