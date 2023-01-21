//{ Driver Code Starts
// Initial Template for Java

import java.util.*;
import java.io.*;
import java.lang.*;

class GFG {
    public static void main(String[] args) throws IOException {
        BufferedReader br =
            new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        int t =
            Integer.parseInt(br.readLine().trim()); // Inputting the testcases
        while (t-- > 0) {

            int a = Integer.parseInt(br.readLine().trim());
            int b = Integer.parseInt(br.readLine().trim());

            Solution ob = new Solution();
            out.println(ob.minVal(a, b));
        }
        out.flush();
    }
}
// } Driver Code Ends




// User function Template for Java

class Solution {
    
public static int minVal(int a, int b) {

        int a1=ct(a);

        int b1=ct(b);

        int ans=a;

        if(a1==b1){

            return a;

        }

       else if(a1<b1){

            int i=0;

            while(a1!=b1){

                

                if(a%2==0){

                    a1++;

                ans+=(1<<i);

                }

                i++;

                a/=2;

            }

        }

        else{

            int i=0;

             while(a1!=b1){

                

                if(a%2==1){

                    a1--;

                ans-=(1<<i);

                }

                i++;

                a/=2;

            }

        }

        return ans;

    }

        static int ct(int a){

            int ans=0;

            while(a>0){

                if(a%2!=0){

                    ans++;

                }

                a/=2;

            }

            return ans;

        }

}