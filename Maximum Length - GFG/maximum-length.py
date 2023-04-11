#User function Template for python3

class Solution():
    def solve(self, a, b, c):
        #your code goes here
        li=[]
        li.append(a)
        li.append(b)
        li.append(c)
        k=max(li)
        s=a+b+c
        if k<=2*(s-k+1) :
            return s
        elif(a==0 or b==0 or c==0):
            return -1
        else:
            return -1


#{ 
 # Driver Code Starts
#Initial Template for Python 3

from collections import Counter
for _ in range(int(input())):
    a, b, c=map(int,input().split())
    obj = Solution()
    res = obj.solve(a, b, c)
    
    print(res)
# } Driver Code Ends