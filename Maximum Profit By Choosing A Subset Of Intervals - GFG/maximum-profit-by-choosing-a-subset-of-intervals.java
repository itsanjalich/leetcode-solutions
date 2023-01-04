//{ Driver Code Starts
import java.io.*;
import java.util.*;

class IntMatrix {
    public static int[][] input(BufferedReader br, int n, int m) throws IOException {
        int[][] mat = new int[n][];

        for (int i = 0; i < n; i++) {
            String[] s = br.readLine().trim().split(" ");
            mat[i] = new int[s.length];
            for (int j = 0; j < s.length; j++)
                mat[i][j] = Integer.parseInt(s[j]);
        }

        return mat;
    }

    public static void print(int[][] m) {
        for (var a : m) {
            for (int e : a) System.out.print(e + " ");
            System.out.println();
        }
    }

    public static void print(ArrayList<ArrayList<Integer>> m) {
        for (var a : m) {
            for (int e : a) System.out.print(e + " ");
            System.out.println();
        }
    }
}

class GFG {
    public static void main(String[] args) throws IOException {
        BufferedReader br =
            new BufferedReader(new InputStreamReader(System.in));
        int t;
        t = Integer.parseInt(br.readLine());
        while (t-- > 0) {

            int n;
            n = Integer.parseInt(br.readLine());

            int[][] intervals = IntMatrix.input(br, n, 3);

            Solution obj = new Solution();
            int res = obj.maximum_profit(n, intervals);

            System.out.println(res);
        }
    }
}

// } Driver Code Ends




class Solution {
    public static int maximum_profit(int n, int[][] intervals) {
        // code here
        Arrays.sort(intervals,(a,b) -> (a[1]-b[1]));
        
        int dp[] = new int[n];
        dp[0] = intervals[0][2];
        

        for(int i = 1; i < n; i++){
            int ind = findInd(intervals,i);
            if(ind == -1) dp[i] = Math.max(dp[i-1],intervals[i][2]);
            else dp[i] = Math.max(dp[i-1],dp[ind] + intervals[i][2]);
        }
        
        return dp[n-1];
    }
    
    static int findInd(int intervals[][],int ind){
        int s = 0, e = ind-1;
        int res = -1;
        
        while(s <= e){
            int m = s + (e-s)/2;
            if(intervals[m][1] > intervals[ind][0]) e = m-1;
            else{
                res = m;
                s = m+1;
            }
        }
        
        return res;
    }
}
