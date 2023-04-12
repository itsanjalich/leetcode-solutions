from typing import List


class Solution:
    def dominantPairs(self, n : int, arr : List[int]) -> int:
        from bisect import bisect

        arr = arr[:n//2] + sorted(arr[n//2:])
        ans = 0
        for i in range(n//2):
            i = bisect(arr, arr[i]//5, n//2, n)
            ans += i-n//2
        return ans
        


        





#{ 
 # Driver Code Starts
class IntArray:
    def __init__(self) -> None:
        pass
    def Input(self,n):
        arr=[int(i) for i in input().strip().split()]#array input
        return arr
    def Print(self,arr):
        for i in arr:
            print(i,end=" ")
        print()


if __name__=="__main__":
    t = int(input())
    for _ in range(t):
        
        n = int(input())
        
        
        arr=IntArray().Input(n)
        
        obj = Solution()
        res = obj.dominantPairs(n, arr)
        
        print(res)
        

# } Driver Code Ends