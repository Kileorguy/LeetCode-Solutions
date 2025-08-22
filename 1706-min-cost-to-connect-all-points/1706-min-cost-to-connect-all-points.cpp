class Solution {
public:

    int manhattanDist(pair<int,int> a, pair<int,int> b){
        return(abs(a.first-b.first) + abs(a.second - b.second));
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int ans = 0;
        int n = points.size();

        vector<bool> visited(n, false);        
        vector<int> distance(n, INT_MAX);
        
        distance[0] = 0;

        for(int i=0;i<n;i++){
            int u = -1;
            for(int j=0;j<n;j++){
                if(!visited[j] && (u == -1 || distance[j] < distance[u])){
                    u = j;
                }
            }


            ans += distance[u];
            visited[u] = true;

            for(int j=0; j<n;j++){
                if(!visited[j]){
                    int dist = manhattanDist(
                        {points[u][0], points[u][1]},
                        {points[j][0], points[j][1]}
                    );
                    if(distance[j] > dist){
                        distance[j] = dist;
                    }
                }
            }
        }

        return ans;
    }
};