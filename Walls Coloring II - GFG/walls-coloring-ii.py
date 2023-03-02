#User function Template for python3
#User function Template for python3
from typing import List
class Solution:
    def minCost(self, costs: List[List[int]]) -> int:

        # your code goes here

        N = len(costs)

        K = len(costs[0])

        if K == 1 and N>1:

            return -1

        if K==1 and N==1:

            return costs[0][0]

        rem = [0 for i in range(K)]

        min1 = [10 ** 7, 0]

        for j in range(K):

            rem[j] = costs[0][j]

            if min1[0] > rem[j]:

                min1[0] = rem[j]

                min1[1] = j

        min2 = 10 ** 7

        for j in range(K):

            if j == min1[1]:

                continue

            else:

                if min2 > rem[j]:

                    min2 = rem[j]

 

        for i in range(1, N):

            for j in range(K):

                if j == min1[1]:

                    rem[j] = costs[i][j] + min2

                else:

                    rem[j] = costs[i][j] + min1[0]

            min1 = [10 ** 7, 0]

            min2 = 10 ** 7

            for j in range(K):

                if min1[0] > rem[j]:

                    min1[0] = rem[j]

                    min1[1] = j

            for j in range(K):

                if j == min1[1]:

                    continue

                else:

                    if min2 > rem[j]:

                        min2 = rem[j]

        return min1[0]



#{ 
 # Driver Code Starts
#Initial Template for Python 3

from typing import List


class IntMatrix:
    def __init__(self) -> None:
        pass
    def Input(self,n,m):
        matrix=[]
        #matrix input
        for _ in range(n):
            matrix.append([int(i) for i in input().strip().split()])
        return matrix
    def Print(self,arr):
        for i in arr:
            for j in i:
                print(j,end=" ")
            print()


if __name__=="__main__":
    t = int(input())
    for _ in range(t):
        
        n, m = map(int, input().split())
        
        
        costs=IntMatrix().Input(n, m)
        
        obj = Solution()
        res = obj.minCost(costs)
        
        print(res)
# } Driver Code Ends