#User function Template for python3

#User function Template for python3
import re
class Solution:
    def checkCompressed(self, S, T):
        i = 0
        for x in re.split('(\D)', T):
            if not x:
                continue
            elif x.isdigit():
                i += int(x)
            elif i < len(S) and x == S[i]:
                i += 1
            else:
                return 0
        return int(i == len(S))

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__': 
    t = int (input ())
    for _ in range (t):
        S = input()
        T = input()
        
        ob = Solution()
        print(ob.checkCompressed(S,T))
# } Driver Code Ends