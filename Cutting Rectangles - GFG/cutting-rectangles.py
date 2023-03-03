#User function Template for python3

class Solution:
    def minimumSquares(self, L, B):
        # code here
        a = max(L,B)
        b = min(L,B)
        if a%b==0:
            return ( [a//b, b])
        else:
            while b:
                a,b=b,a%b
                
            temp = ((L//a)*(B//a))
            return([temp , a])


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        L, B = [int(x) for x in input().split()]
        
        ob = Solution();
        N, K = ob.minimumSquares(L, B)
        print(N,end=" ")
        print(K)
# } Driver Code Ends