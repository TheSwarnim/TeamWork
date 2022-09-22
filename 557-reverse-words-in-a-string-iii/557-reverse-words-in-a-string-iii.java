class Solution {
    public String reverseWords(String s) {
        StringBuilder cur = new StringBuilder();
        StringBuilder res = new StringBuilder();
        for(char c : s.toCharArray()){
            if(c == ' '){
                res.append(cur.reverse() + " ");
                cur.setLength(0);
            } else {
                cur.append(c);
            }
        }
        res.append(cur.reverse());
        return res.toString();
    }
}