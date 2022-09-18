class Solution {
    int[] res;
    int[] count;
    List<Integer>[] graph;
    
    public int[] sumOfDistancesInTree(int n, int[][] edges) {
        /*
        assume 0 as root,
        find solution for root,
        use re-rooting technique to find the solution for every node
        
        res -> store the result for ith node
        count -> store the count of nodes including itself
        that comes in this sub tree by assuming the root as 0
        */
        
        res = new int[n];
        count = new int[n];
        
        graph = new List[n];
        for(int i = 0; i < n; i++){
            graph[i] = new ArrayList<>();
        }
        for(int[] e : edges){
            graph[e[0]].add(e[1]);
            graph[e[1]].add(e[0]);
        }
        
        // this will find solution of node 0
        dfs(0, -1);
        
        // this will find the solution for all nodes
        // all parents will find the answer for thier childs
        // and all childs will find solution for there childs
        dfs2(0, -1, n);
        
        return res;
    }
    
    void dfs2(int node, int parent, int n){
        for(int chNode : graph[node]){
            if(chNode == parent) continue;
            
            res[chNode] = res[node] - count[chNode] + n - count[chNode];
            dfs2(chNode, node, n);
        }
    }
    
    void dfs(int node, int parent){
        for(int chNode : graph[node]){
            if(chNode == parent) continue;
            
            dfs(chNode, node);
            count[node] += count[chNode];
            res[node] += res[chNode] + count[chNode];
        }
        count[node] += 1;
    }
}