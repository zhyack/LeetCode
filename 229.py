def findKthElement(nums, ll, rr, k):
    if (ll==rr):
        return nums[ll]
    l = ll
    r = rr
    m = (l+r+1)//2
    vm = nums[m]
    while(l<=r):
        while(nums[l]<vm):
            l+=1
        while(nums[r]>vm):
            r-=1
        if (l<=r):
            t = nums[l]
            nums[l] = nums[r]
            nums[r] = t
            l+=1
            r-=1
    if (r-ll+1<k):
        return findKthElement(nums, r+1, rr, k-(r-ll+1))
    else:
        return findKthElement(nums, ll, r, k)

def count(nums, t):
    ret = 0
    for i in nums:
        if i==t:
            ret+=1
    return ret

class Solution:
    def majorityElement(self, nums: List[int]) -> List[int]:
        ret = []
        n = len(nums)
        if (n==0):
            return ret
        t1 = findKthElement(nums, 0, n-1, n//3+1)
        t2 = findKthElement(nums, 0, n-1, n-n//3)
        if count(nums, t1)>n//3:
            ret.append(t1)
        if t2!=t1 and count(nums, t2)>n//3:
            ret.append(t2)
        return ret
            