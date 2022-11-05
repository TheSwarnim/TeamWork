class Solution {
    public List<String> findWords(char[][] board, String[] words) {
        TrieNode root = buildTrie(words);
        List<String> res = new ArrayList<>();
        
        for(int i = 0; i < board.length; i++){
            for(int j = 0; j < board[0].length; j++){
                dfs(board, i, j, root, res);
            }
        }
        
        return res;
    }
    
    private void dfs(char[][] board, int x, int y, TrieNode node, List<String> res){
        char c = board[x][y];
        if(c == '#' || node.next[c - 'a'] == null){
            return;
        }
        
        node = node.next[c - 'a'];
        if(node.word != null){ // find a word
            res.add(node.word);
            node.word = null;
        }
        
        board[x][y] = '#';
        if(x > 0) dfs(board, x-1, y, node, res);
        if(x < board.length - 1) dfs(board, x+1, y, node, res);
        if(y > 0) dfs(board, x, y-1, node, res);
        if(y < board[0].length - 1) dfs(board, x, y+1, node, res);
        
        board[x][y] = c;
    }
    
    private TrieNode buildTrie(String[] words){
        TrieNode root = new TrieNode();
        
        for(String w : words){
            
            TrieNode node = root;
            
            for(char c : w.toCharArray()){
                if(node.next[c - 'a'] == null) {
                    node.next[c - 'a'] = new TrieNode();
                }
                node = node.next[c - 'a'];
            }
            
            node.word = w;
            
        }
        
        return root;
    }
    
    private class TrieNode {
        TrieNode[] next = new TrieNode[26];
        String word;
    }
}