class Solution(object):
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        """ divide into words ['the', 'sky', 'is', 'blue']"""
        """ then reverse the word ['blue', 'is', 'sky', 'the']"""

        words = s.split() 
        words.reverse()

        return " ".join(words)