//{ Driver Code Starts
//Initial Template for Java

import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
    static class FastReader{ 
        BufferedReader br; 
        StringTokenizer st; 
  
        public FastReader(){ 
            br = new BufferedReader(new InputStreamReader(System.in)); 
        } 
  
        String next(){ 
            while (st == null || !st.hasMoreElements()){ 
                try{ st = new StringTokenizer(br.readLine()); } catch (IOException  e){ e.printStackTrace(); } 
            } 
            return st.nextToken(); 
        } 
  
        String nextLine(){ 
            String str = ""; 
            try{ str = br.readLine(); } catch (IOException e) { e.printStackTrace(); } 
            return str; 
        } 

        Integer nextInt(){
            return Integer.parseInt(next());
        }

        Long nextLong(){
            return Long.parseLong(next());
        }
    } 

    public static void main(String[] args) throws IOException {
        FastReader sc = new FastReader();        
        PrintWriter out = new PrintWriter(System.out);
        int testcases = sc.nextInt();

        while (testcases-- > 0) {
            int N = sc.nextInt();
            int A[] = new int[N];
            for(int i = 0; i < N; i++) A[i] = sc.nextInt();
            int Q = sc.nextInt();
            ArrayList<Integer> Queries[] = new ArrayList[Q];
            for(int i = 0; i < Q; i++){
                Queries[i] = new ArrayList<>();
                int x = sc.nextInt(), y = sc.nextInt();
                Queries[i].add(x);
                Queries[i].add(y);
                for(int j = 0; j < Queries[i].get(1); j++){
                    x = sc.nextInt();
                    Queries[i].add(x);
                }
            }
            Solution ob = new Solution();
            ArrayList<Integer> ans = ob.maximumToys(N, A, Q, Queries);
            for(int x : ans)
                out.print(x + " ");
            out.print("\n");
        }
        out.flush();
    }
}
// } Driver Code Ends


//User function Template for Java



//User function Template for Java



//User function Template for Java

class Solution {

    int fr[];

    

    class tree

    {

        int n;

        long bit[];

        tree(int n)

        {

            this.n = n;

            bit = new long[n];

        }

        

        void add(int x,int y)

        {

            for(;x<n;x+=(x&(-x)))

                bit[x]+=y;

        }

        

        long get(int x)

        {

            long y=0l;

            for(;x>0;x-=(x&(-x)))

                y+=bit[x];

            

            return y;

        }

    }

    ArrayList<Integer> maximumToys(int N, int A[], int Q, ArrayList<Integer> Queries[])

    {

        ArrayList<Integer> res = new ArrayList<>();

        fr = new int[1000*1000+5];

        for(int x : A) fr[x]++;

        tree obj1 = new tree(1000*1000+5);

        tree obj2 = new tree(1000*1000+5);

        for(int i=0;i<A.length;i++)

        {

            obj1.add(A[i],A[i]);

            obj2.add(A[i],1);

        }

        for(ArrayList<Integer> i : Queries)

        {

            long c = i.get(0);

            for(int j=2;j<i.size();j++)

            {

                obj1.add(A[i.get(j)-1],-A[i.get(j)-1]);

                obj2.add(A[i.get(j)-1],-1);

            }

            int l=1,h=1000*1000;

            int p=1000*1000;

            while(l<=h)

            {

                int m=l+(h-l)/2;

                if(obj1.get(m)>=c)

                {

                    p=m;

                    h=m-1;

                }

                else

                {

                    l=m+1;

                }

            }

            long result = obj2.get(p-1);

            long n = Math.min((c-obj1.get(p-1))/p,(long)fr[p]);

            result+=n;

            res.add((int)result);

            for(int j=2;j<i.size();j++)

            {

                obj1.add(A[i.get(j)-1],A[i.get(j)-1]);

                obj2.add(A[i.get(j)-1],1);

            }

        }

        

        return res;

    }

}