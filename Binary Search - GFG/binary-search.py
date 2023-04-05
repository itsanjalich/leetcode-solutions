#User function template for Python

class Solution:    
    def binarysearch(self, arr, n, k):
        # code here
        l = 0
        h = n-1
        while l<=h:
            mid = (int)(l + (h-l)/2)
            if(arr[mid]==k):
                return mid
            elif(arr[mid]<k):
                l = mid+1
            elif(arr[mid]>k):
                h = mid-1
            else:
                return -1
        return -1
            



#{ 
 # Driver Code Starts
#Initial template for Python

if __name__ == '__main__':
    t=int(input())
    for i in range(t):
        n=int(input())
        arr=list(map(int, input().strip().split(' ')))
        k=int(input())
        ob = Solution()
        print (ob.binarysearch(arr, n, k))


# } Driver Code Ends