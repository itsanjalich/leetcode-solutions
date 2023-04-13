#User function Template for python3
class Solution:
    def minDifference(self, N, A): 
        def _split(L, R):
            LSUM = (acc[L-1] if L > 0 else 0)
            tot = acc[R] - LSUM
            goal = tot//2
            while L<R:
                m = (L+R)//2
                if acc[m] - LSUM < goal: L=m+1
                else: R=m
            v1, v2 = acc[L]-LSUM, tot-(acc[L]-LSUM)
            if L>0:
                v3, v4 = acc[L-1]-LSUM, tot-(acc[L-1]-LSUM)
                if abs(v2-v1) > abs(v4-v3): return (v3,v4)
            return (v1,v2) 
        
        from itertools import accumulate
        acc = list(accumulate(A))
        ans = 10**9
        for i in range(1, N-2):
            W, X = _split(0, i)
            Y, Z = _split(i+1, N-1)
            vs = sorted((W,X,Y,Z))
            ans = min( ans, vs[3]-vs[0] )
        return ans





#{ 
 # Driver Code Starts
#Initial Template for Python 3



if __name__ == '__main__': 
    t = int(input())
    for _ in range(t):
        N = int(input())
        A = list(map(int, input().strip().split()))
        ob = Solution()
        ans = ob.minDifference(N, A)
        print(ans)


# } Driver Code Ends