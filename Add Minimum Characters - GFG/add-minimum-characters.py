#User function Template for python3

class Solution:
    def addMinChar (self, str1):
        # code here 
        n = len(str1)
        i,j,ans = 0,n-1,n-1
        
        while i<=j:
            if str1[i]==str1[j]:
                i+=1
                j-=1
            else:
                ans-=1
                i=0
                j = ans
                
        return n-ans-1



#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__': 
    t = int (input ())
    for _ in range (t):
        str1 = input()

        ob = Solution()
        print(ob.addMinChar(str1))

# } Driver Code Ends