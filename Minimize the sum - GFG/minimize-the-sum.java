//{ Driver Code Starts
//Initial Template for Java

import java.util.*;
import java.lang.*;
import java.io.*;


// } Driver Code Ends
//User function Template for Java

class Solution {
    long minimizeSum(int N, int arr[]) {
        // code here
        Arrays.sort(arr);
        PriorityQueue<Long> queue= new PriorityQueue<>();
        for(long element: arr){
            queue.add(element);
        }
        long result = 0;
        while(queue.size()>1){
            long x=queue.poll();
            long y=queue.poll();
            long add=x+y;
            queue.add(add);
            result+=add;
        }
        return result;
    }
}


//{ Driver Code Starts.

public class GFG
{
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        
        int t = sc.nextInt();
        while (t-- > 0)
        {
            int n = sc.nextInt();
            int A[] = new int[n];
            
            for (int i = 0; i < n;i++)
            {
                A[i] = sc.nextInt();
            }
            Solution obj = new Solution();
            long ans = obj.minimizeSum(n, A);
            System.out.println(ans);
        }
    }
}
// } Driver Code Ends