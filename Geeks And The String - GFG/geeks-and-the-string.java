//{ Driver Code Starts
import java.io.*;
import java.util.*;

class GFG {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t;
        t = Integer.parseInt(br.readLine());
        while(t-- > 0){
            
            String s; 
            s = br.readLine();
            
            Solution obj = new Solution();
            String res = obj.removePair(s);
            
            System.out.println(res);
            
        }
    }
}

// } Driver Code Ends




class Solution {
    public static String removePair(String s) {
        // code here
        
        String curr = s;
        
        boolean duplicate = true;
        
        while(duplicate){
            int idx = -1;
            int n = curr.length();
            for(int i=0;i+1<n;i++){
                if(curr.charAt(i)==curr.charAt(i+1)){
                    idx = i;
                    break;
                }
            }
            if(idx<0){
                duplicate = false;
                break;
            }
            //remove the element at idx
            curr = curr.substring(0,idx)+((idx+2<n)?curr.substring(idx+2,n):"");
        }
        
        return curr.length()>0?curr:"-1";
    }
}
        
        
