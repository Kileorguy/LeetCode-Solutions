class Solution {
public:

    int manhattanDist(pair<int,int> a, pair<int,int> b){
        return(abs(a.first-b.first) + abs(a.second - b.second));
    }

    int topMostParent(vector<int> &parents, int u){
        if(parents[u] == -1) return u;
        return topMostParent(parents, parents[u]);
    }

    bool connectV2U(vector<int> &parents, int u, int v){
        int uP = topMostParent(parents, u);
        int vP = topMostParent(parents, v);

        if(uP != vP){
            parents[vP] = uP;
            parents[v] = uP;
            return true;
        }

        return false;
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        
        int n = points.size();
        vector<int> parents(n, -1);
        vector<vector<int>>  edges;
        // dist, u, v
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                edges.push_back({manhattanDist(
                    {points[i][0], points[i][1]},
                    {points[j][0], points[j][1]}
                ), i,j});
            }
        }

        auto cmp = [](const vector<int>& a, const vector<int>& b) {
            return a[0] > b[0];
        };

        make_heap(edges.begin(), edges.end(), cmp);
        int ans = 0;
        while(!edges.empty()){
            vector<int> e = edges.front();
            pop_heap(edges.begin(), edges.end(), cmp);
            edges.pop_back();

            if(connectV2U(parents, e[1], e[2])) ans+=e[0];
        }

        return ans;
        
    }
};