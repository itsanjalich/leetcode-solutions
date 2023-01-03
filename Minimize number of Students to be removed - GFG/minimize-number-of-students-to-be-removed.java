//{ Driver Code Starts
import java.io.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {
        BufferedReader read =
            new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while (t-- > 0) {
            int N = Integer.parseInt(read.readLine());
            
            String S[] = read.readLine().split(" ");
            int[] H = new int[N];
            
            for(int i=0; i<N; i++)
                H[i] = Integer.parseInt(S[i]);

            Solution ob = new Solution();
            System.out.println(ob.removeStudents(H,N));
        }
    }
}
// } Driver Code Ends


//User function Template for Java
class Solution {
    public int removeStudents(int[] H, int N) {
        // code here
        if(H.length == 0)
        return 0;
        
        int[] res = new int[H.length];
        int len = 1;
        res[0]=H[0];
        for(int i=1;i<H.length;i++){
            if(H[i]>res[len-1]){
                res[len++] = H[i];
            }else{
                int index = Arrays.binarySearch(res,0,len-1,H[i]);
                if(index<0)
                index = -1*index-1;
                res[index]=H[i];
            }
        }
        return (H.length-len);
    }
    
};