class Solution:
    def licenseKeyFormatting(self, S: str, K: int) -> str:
        S = S.replace('-', '').upper()[::-1];
        if (len(S)==0):
            return S;
        ret = "";
        cnt = 0;
        for c in S:
            ret+=c;
            cnt+=1;
            if (cnt%K==0):
                ret+='-';
        if ret[-1]=='-':
            ret = ret[:-1]
        return ret[::-1];