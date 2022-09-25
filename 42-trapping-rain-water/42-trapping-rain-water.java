class Solution {
    public int trap(int[] A) {
        int n = A.length;
        int[] pre = new int[n];
        int[] suff = new int[n];
        
        for(int i = 0; i < n; i++){
            pre[i] = i > 0 ? Math.max(A[i], pre[i-1]) : A[i];
        }
        
        for(int j = n-1; j >= 0; j--){
            suff[j] = j < n-1 ? Math.max(A[j], suff[j+1]) : A[j];
        }
        
        int res = 0;
        
        for(int i = 0; i < n; i++){
            res += Math.min(pre[i], suff[i]) - A[i];
        }
        
        return res;
    }
}

/*
        int n = A.length;
        
        Stack<Integer> st = new Stack<>();
        int[] suff = new int[n];
        
        for(int i = n-1; i >= 0; i--){
            while(!st.isEmpty() && A[st.peek()] <= A[i]){
                st.pop();
            }
            
            if(!st.isEmpty()){
                suff[i] = st.peek();
            } else {
                suff[i] = n;
            }
            
            st.push(i);
        }
        
        int[] pre = new int[n];
        st = new Stack<>();
        for(int i = 0; i < n; i++){
            while(!st.isEmpty() && A[st.peek()] <= A[i]){
                st.pop();
            }
            
            if(!st.isEmpty()){
                pre[i] = st.peek();
            } else {
                pre[i] = -1;
            }
            
            st.push(i);
        }
        
        // System.out.println(Arrays.toString(pre));
        // System.out.println(Arrays.toString(suff));
        
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(pre[i] != -1 && suff[i] != n){
                int val = Math.min(A[pre[i]], A[suff[i]]) - A[i];
                ans += val;
                System.out.println(i + " " + val + " " + pre[i] + " " + suff[i] + " " + );
            }
        }
        
        return ans;
*/