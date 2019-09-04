class FileSystem(object):

    def __init__(self):
        self.d = {'~':[{},None]}

    def create(self, path, value):
        """
        :type path: str
        :type value: int
        :rtype: bool
        """
        pl = ('~'+path).split('/')
        d = self.d
        for p in pl[:-1]:
            if len(p)==0:
                return False
            if (p not in d):
                return False
            d = d[p][0]
        if (pl[-1] in d):
            return False
        d[pl[-1]]=[{}, value]
        return True
        
        

    def get(self, path):
        """
        :type path: str
        :rtype: int
        """
        pl = ('~'+path).split('/')
        d = self.d
        for p in pl[:-1]:
            if len(p)==0:
                return -1
            if (p not in d):
                return -1
            d = d[p][0]
        if (pl[-1] not in d):
            return -1
        return d[pl[-1]][1]


# Your FileSystem object will be instantiated and called as such:
# obj = FileSystem()
# param_1 = obj.create(path,value)
# param_2 = obj.get(path)