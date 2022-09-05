/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(!root){
            return {};
        }
        queue<Node*> q;
        q.push(root);
        vector<vector<int>> res;
        while(!q.empty()){
            int size = q.size();
            vector<int> arr;
            for(int i =0 ;  i < size; i++){
                root = q.front();
                q.pop();
                arr.push_back(root->val);
                for(auto &child : root->children){
                    q.push(child);
                }
            }
            res.push_back(arr);
        }
        return res;
    }
};