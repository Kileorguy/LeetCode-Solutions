class Solution {
public:

    int topMostParent(unordered_map<int,int> &parent, int i){
        if(parent.count(i) == 0) return i;
        return topMostParent(parent, parent[i]);
    }

    bool conRight2Left(unordered_map<int, int> &parent, int u, int v){
        int parentU = topMostParent(parent, u);
        int parentV = topMostParent(parent, v);
        if(parentU != parentV){
            parent[parentU] = parentV;
            return true;
        }
        return false;

    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        unordered_map<int,int> parent;
        vector<int> ans;

        for(vector<int> &pair: edges){
            if(!conRight2Left(parent, pair[0], pair[1])) ans = pair;
        }

        return ans;

    }
};