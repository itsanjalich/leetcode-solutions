#User function Template for python3

class Solution:
    def uniquePaths(self, n, m, grid):
        if grid[0][0] == 0 or grid[n-1][m-1] == 0:
            return 0
            
        path = [[0]*m for _ in range(n)]
        path[0][0] = 1
        for r in range(n):
            for c in range(m):
                if grid[r][c] == 0:
                    continue
                if r-1 >= 0:
                    path[r][c] += path[r-1][c]
                if c-1 >= 0:
                    path[r][c] += path[r][c-1]
        return path[n-1][m-1]%(10**9+7)

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__': 
    t = int (input ())
    for _ in range (t):
        n,m=map(int,input().split())
        
        grid=[]
        for i in range(n):
            col = list(map(int,input().split()))
            grid.append(col)
        
        ob = Solution()
        print(ob.uniquePaths(n,m,grid))
# } Driver Code Ends