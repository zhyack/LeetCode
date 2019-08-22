class FileSystem(object):

    def __init__(self):
        self.d = {}

    def ls(self, path):
        """
        :type path: str
        :rtype: List[str]
        """
        path_list=path[1:].split('/');
        cd = self.d
        for p in path_list:
            if len(p):
                cd = cd[p]
        if (isinstance(cd, dict)):
            return sorted(cd.keys())
        else:
            return [path_list[-1]]
        

    def mkdir(self, path):
        """
        :type path: str
        :rtype: None
        """
        path_list=path[1:].split('/');
        cd = self.d;
        for p in path_list:
            if len(p) and p not in cd:
                cd[p] = {}
            cd = cd[p]
        

    def addContentToFile(self, filePath, content):
        """
        :type filePath: str
        :type content: str
        :rtype: None
        """
        path_list=filePath[1:].split('/');
        cd = self.d;
        for p in path_list[:-1]:
            if len(p) and p not in cd:
                cd[p] = {}
            cd = cd[p]
        if path_list[-1] not in cd:
            cd[path_list[-1]]=""
        cd[path_list[-1]]+=content;
        

    def readContentFromFile(self, filePath):
        """
        :type filePath: str
        :rtype: str
        """
        path_list=filePath[1:].split('/');
        cd = self.d;
        for p in path_list[:-1]:
            if len(p):
                cd = cd[p]
        return cd[path_list[-1]];


# Your FileSystem object will be instantiated and called as such:
# obj = FileSystem()
# param_1 = obj.ls(path)
# obj.mkdir(path)
# obj.addContentToFile(filePath,content)
# param_4 = obj.readContentFromFile(filePath)