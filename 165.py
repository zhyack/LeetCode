class Solution(object):
    def compareVersion(self, version1, version2):
        """
        :type version1: str
        :type version2: str
        :rtype: int
        """
        v1 = version1.split('.')
        v2 = version2.split('.')
        n1 = len(v1)
        n2 = len(v2)
        for i in range(min(n1, n2)):
            k1 = int(v1[i])
            k2 = int(v2[i])
            if (k1>k2):
                return 1
            elif (k1<k2):
                return -1
        if (n1>n2):
            for i in range(n2, n1):
                if (int(v1[i])>0):
                    return 1
        elif (n1<n2):
            for i in range(n1, n2):
                if (int(v2[i])>0):
                    return -1
        return 0