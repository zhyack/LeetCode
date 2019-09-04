class Solution(object):
    def reverseWords(self, s):
        """
        :type s: List[str]
        :rtype: None Do not return anything, modify s in-place instead.
        """
        t = ''.join(s).strip().rstrip()
        t = ' '.join([k for k in reversed(t.split()) if len(k)]) 
        for i,c in enumerate(t):
            s[i]=c