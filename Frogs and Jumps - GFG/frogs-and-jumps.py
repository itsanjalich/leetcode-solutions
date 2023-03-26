#User function Template for python3

class Solution:
    def unvisitedLeaves(self, N, leaves, frogs):
        # code here
        n=N
        m=leaves
        arr=[0]*(m+1)
        for step_size in set(frogs):
            if step_size==1:
                return 0
            for i in range(step_size,m+1,step_size):
                arr[i]=1
        arr[0]=1
        return m+1-sum(arr)
        



#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    
    T = int(input())
    while T > 0: 
        N, leaves = [int(i) for i in input().split()]
        frogs = [int(i) for i in input().split()]
        ob = Solution()
        print(ob.unvisitedLeaves(N, leaves, frogs))
        
        T -= 1
# } Driver Code Ends