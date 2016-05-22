# Given an input string, reverse the string word by word.

# For example,
# Given s = "the sky is blue",
# return "blue is sky the".

# Clarification:
# What constitutes a word?
# A sequence of non-space characters constitutes a word.
# Could the input string contain leading or trailing spaces?
# Yes. However, your reversed string should not contain leading or trailing spaces.
# How about multiple spaces between two words?
# Reduce them to a single space in the reversed string.


import re

class Solution:
    # @param s, a string
    # @return a string
    def reverseWords(self, s):
    	s = s.strip()
    	words = re.split(r'\s+', s)
    	words.reverse()
    	return " ".join(words)


if __name__ == '__main__':
	s = Solution()
	print s.reverseWords(" the sky  is blue  ")