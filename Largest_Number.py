class Solution:
    # @param num, a list of integers
    # @return a string
    def largestNumber(self, num):
        num_strs = ["%d" % x for x in num]
        def comp(s1, s2):
        	l1 = len(s1)
        	l2 = len(s2)
        	minl = min(l1, l2)
        	if s1[:minl] < s2[:minl]:
        		return 1
        	if s1[:minl] > s2[:minl]:
        		return -1
        	if l1 == l2:
        		return 0
        	if l1 > l2:
        		return comp(s1[l2:]+s2, s1)
        	else:
        		return comp(s2, s2[l1:]+s1)
        num_strs.sort(cmp=comp)
        while num_strs[0] == "0" and len(num_strs) > 1:
        	num_strs.remove("0")
        ret = "".join(num_strs)
        return ret

if __name__ == '__main__':
	s = Solution()
	print s.largestNumber([121, 12])
	print s.largestNumber([128, 12])
	print s.largestNumber([0, 0])