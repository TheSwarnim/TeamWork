class Solution {
    public boolean isValidSerialization(String preorder) {
        int diff = 1;
        String[] nodes = preorder.split(",");
        for(String node : nodes){
            if(--diff < 0) return false;
            if(!node.equals("#")) {
                diff += 2;
            }
        }
        return diff == 0;
    }
}