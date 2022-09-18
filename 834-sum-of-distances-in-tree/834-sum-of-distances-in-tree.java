class Solution {
    List<Integer> []graph;
    int[] res, count;
    public int[] sumOfDistancesInTree(int n, int[][] edges) {
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
        
        // preorder dfs
        dfs(0, -1);
        
        // postorder dfs
        dfs2(0, -1, n);
        
        return res;
    }
    
    void dfs2(int node, int parent, int n){
        for(int chNode : graph[node]){
            if(chNode == parent){
                continue;
            }
            
            res[chNode] = res[node] - count[chNode] + n - count[chNode];
            dfs2(chNode, node, n);
        }
    }
    
    void dfs(int node, int parent){
        for(int chNode : graph[node]){
            if(chNode == parent) {
                continue;
            }
            
            dfs(chNode, node);
            count[node] += count[chNode];
            res[node] += res[chNode] + count[chNode]; // res[chNode] : result of subtree whith root chNode and count[chNode] will give the answer of node as the increment is count of all nodes of chNode subtree
        }
        count[node] += 1;
    }
}