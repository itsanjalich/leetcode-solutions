//{ Driver Code Starts
//Initial Template for Java

import java.util.*;
import java.lang.*;
import java.io.*;
class GFG
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out=new PrintWriter(System.out);
        int T = Integer.parseInt(br.readLine().trim());
        while(T-->0)
        {
            String str = br.readLine().trim();
            Solution ob = new Solution();
            int ans = ob.CountWays(str);
            out.println(ans);
        }
        out.close();
    }
}

// } Driver Code Ends





class Solution

{

    // public int CountWays(char[] str, int index, int length) {

    //     if(index == length){

    //         return 1;

    //     }

    //     if(index > length) return 0;

    //     if(str[index] == '0') return 0;

    //     int slice_one = CountWays(str, index+1, length);

    //     int slice_two = 0;

    //     if(index+1 < length) {

    //         int two_digit = (str[index] - '0') * 10 + (str[index + 1] - '0');

    //         if(two_digit <= 26){

    //             slice_two = CountWays(str, index+2, length);

    //         }

    //     }

    //     return slice_one + slice_two;

    // }

    int mod = 1_000_000_007;

    public int CountWays_memoization(char[] str, int index, int length, int[] dp) {

        if(index == length){

            return 1;

        }

        if(index > length) return 0;

        if(str[index] == '0') return 0;

        if(dp[index] != -1) return dp[index];

        int slice_one = CountWays_memoization(str, index+1, length, dp);

        int slice_two = 0;

        if(index+1 < length) {

            int two_digit = (str[index] - '0') * 10 + (str[index + 1] - '0');

            if(two_digit <= 26){

                slice_two = CountWays_memoization(str, index+2, length, dp);

            }

        }

        return dp[index] = (slice_one + slice_two)%mod;

    }

    public int CountWays(String str) {

        // code here

        int[] dp = new int[str.length()];

        Arrays.fill(dp, -1);

        return CountWays_memoization(str.toCharArray(), 0, str.length(), dp);

    }

}