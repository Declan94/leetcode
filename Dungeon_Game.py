class Solution:
    # @param dungeon, a list of lists of integers
    # @return a integer
    def calculateMinimumHP(self, dungeon):
        minHp = [[1 for y in x] for x in dungeon]
        height = len(dungeon)
        width = len(dungeon[0])
        for i in xrange(height-1, -1, -1):
        	for j in xrange(width-1, -1, -1):
        		if i == height-1 and j == width-1:
        			v1 = 1
        		else:
        			v1 = 9999999
        		if j + 1 < width:
        			v1 = minHp[i][j+1]
        		v2 = 9999999
        		if i + 1 < height:
        			v2 = minHp[i+1][j]
        		minHp[i][j] = max(1, min(v1, v2) - dungeon[i][j])
        return minHp[0][0]

if __name__ == '__main__':
	s = Solution()
	print s.calculateMinimumHP([[-2, -3, 3], [-5, -10, 1], [10, 30, -5]])
        	