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
        int T = Integer.parseInt(br.readLine().trim());
        while(T-->0)
        {
            int n = Integer.parseInt(br.readLine().trim());
            Solution ob = new Solution();
            int ans = ob.compute_value(n);
            System.out.println(ans);
        }
    }
}

// } Driver Code Ends


//User function Template for Java

class Solution
{
    long inv(long n, long m){
        long mod=1000000007;

        if(m==0) 
            return 1;

        if((m&1)!=0) 
            return (n*1l*inv(n, m-1))%mod;

        long tmp=inv(n, m/2);

        return (tmp*1l*tmp)%mod;
    }
    
    int compute_value(int n) {
        // Code here
        long m = 1000000007;
        long fact2N=1, factN=1;

        for(int i=1; i<=2*n; i++) {
            fact2N *= i;
            fact2N %= m;

            if(i==n)
                factN=fact2N;
        }

        factN = (factN*factN)%m;

        return (int)((fact2N * 1l * inv(factN, m-2))%m);
    }
}