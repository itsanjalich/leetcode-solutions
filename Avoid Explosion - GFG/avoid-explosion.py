#User function Template for python3

class Solution:
    def avoidExlosion(self, mix, n, danger, m):
        #code here
        ds = list(range(n))
        def find(a):
            if ds[a] != a:
                ds[a] = find(ds[a])
            return ds[a]
        
        res = []
        for x, y in mix:
            x, y = find(x-1), find(y-1)
            for p, q in danger:
                p, q = find(p-1), find(q-1)
                if (x, y) == (p, q) or (x, y) == (q, p):
                    res.append('No')
                    break
            else:
                res.append('Yes')
                ds[x] = y
        
        return res



#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__=="__main__":
    for _ in range(int(input())):
        n, m = map(int, input().split())
        mix = [[0 for _ in range(2)] for _ in range(n)]
        danger = [[0 for _ in range(2)] for _ in range(m)]
        for i in range(n+m):
            if i < n:
                a,b = map(int, input().split())
                mix[i][0] = a
                mix[i][1] = b
            else:
                a,b = map(int, input().split())
                danger[i-n][0] = a
                danger[i-n][1] = b
        
        obj=Solution()
        print(*obj.avoidExlosion(mix, n, danger, m))
        
# } Driver Code Ends