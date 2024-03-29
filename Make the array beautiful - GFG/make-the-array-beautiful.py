#User function Template for python3

from typing import List

class Solution:
    def makeBeautiful(self, arr: List[int]) -> List[int]:
        i = 0
        while i < len(arr)-1:
            if (arr[i]>=0 and arr[i+1]<0) or (arr[i]<0 and arr[i+1]>=0):
                arr.pop(i)
                arr.pop(i)
                i -= 1
                if i < 0: i = 0
            else: i += 1
        return arr

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__=="__main__":
    t = int(input())
    for _ in range(t):
        
        n = int(input())
        
        arr = list(map(int,input().split()))
        
        obj = Solution()
        res = obj.makeBeautiful(arr)
        print(*res)
# } Driver Code Ends