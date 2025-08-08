class Solution {
public:
    unordered_map<Node*, Node*> um;

    void iter(Node *curr){
        if (!curr || um.count(curr)) return;

        um[curr] = new Node(curr->val);

        for (Node *neighbor : curr->neighbors) {
            if (!um.count(neighbor)) {
                iter(neighbor); 
            }
            um[curr]->neighbors.push_back(um[neighbor]);
        }
    }

    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;

        iter(node);
        return um[node];
    }
};
