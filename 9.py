class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        if x<0:
            return False;
        s = str(x)
        n = len(s)
        for i in range(n):
            if (s[i]!=s[n-1-i]):
                return False
        return True;
        