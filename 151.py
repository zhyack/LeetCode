class Solution(object):
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        return ' '.join(k for k in reversed(s.strip().rstrip().split(' ')) if len(k))