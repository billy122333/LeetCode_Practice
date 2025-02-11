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

    Node* dfs(Node* node, unordered_map<Node*, Node*>& node_mp){
        vector<Node*> adj_clone;
        Node* clone = new Node(node->val);
        node_mp[node] = clone;
        for(auto adj_node: node->neighbors){
            if(node_mp.find(adj_node) != node_mp.end()){
                adj_clone.push_back(node_mp[adj_node]);
            }else{
                adj_clone.push_back(dfs(adj_node, node_mp));
            }
        }
        clone->neighbors = adj_clone;
        // cout << "clone:" << clone->val << endl;
        return clone;
    }

    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> node_mp;
        if (node==NULL)
            return NULL;
        if(node->neighbors.size()==0)
            return new Node(node->val);
        else
            return dfs(node, node_mp);
    }
};
