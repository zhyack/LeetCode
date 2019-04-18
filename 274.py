class Solution:
    def hIndex(self, citations: List[int]) -> int:
        n = len(citations)
        if (n==0):
            return 0
        nc = sorted(citations)
        nc = [-1]+nc
        ids = [-1]
        sums = [0]
        for i in range(1,n+1):
            if nc[i]!=nc[i-1]:
                ids.append(nc[i])
                sums.append(sums[-1])
            sums[-1]+=1;
        p = len(sums)-1
        for h in range(n,-1,-1):
            while(ids[p]>h):
                p-=1
            gt = n-sums[p]
            lt = sums[p]
            if (ids[p]==h):
                gt = n-sums[p-1]
            if (gt>=h and lt>=n-h):
                return h;

def stringToIntegerList(input):
    return json.loads(input)

def main():
    import sys
    import io
    def readlines():
        for line in io.TextIOWrapper(sys.stdin.buffer, encoding='utf-8'):
            yield line.strip('\n')

    lines = readlines()
    while True:
        try:
            line = next(lines)
            citations = stringToIntegerList(line);
            
            ret = Solution().hIndex(citations)

            out = str(ret);
            print(out)
        except StopIteration:
            break

if __name__ == '__main__':
    main()