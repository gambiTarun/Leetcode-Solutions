/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> mp;
        return dfs(node,mp);
    }
    
    Node* dfs(Node* root, unordered_map<Node*, Node*> &mp){
        if(!root)
            return NULL;
        
        Node* node = new Node(root->val);
        mp[root] = node;
        
        for(auto n:root->neighbors){
            if(mp.find(n)==mp.end())
                node->neighbors.push_back(dfs(n,mp));
            else
                node->neighbors.push_back(mp[n]);
        }
        
        return node;
        
    }
};