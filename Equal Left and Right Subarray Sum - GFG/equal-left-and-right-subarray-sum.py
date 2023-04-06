# User function Template for python3

class Solution:
    # Complete this function
    
    #Function to find equilibrium point in the array.
    def equalSum(self,A, N):
        # Your code here
        if N == 1:
            return 1
        l ,r = 0, N-1
        s_l, s_r = A[l], A[r]
        
        ans = -1
        while l<r:
            if s_l == s_r and l+1 == r-1:
                ans = l+2
                break
            elif s_l<s_r:
                l += 1
                s_l += A[l]
            else:
                r -= 1
                s_r += A[r]
        return ans

#{ 
 # Driver Code Starts
# Initial Template for Python 3

import math


def main():

    T = int(input())

    while(T > 0):

        N = int(input())

        A = [int(x) for x in input().strip().split()]
        ob=Solution()

        print(ob.equalSum(A, N))

        T -= 1


if __name__ == "__main__":
    main()

# } Driver Code Ends