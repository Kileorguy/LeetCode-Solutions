class Solution {
public:

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<vector<pair<int,int>>> graph(n+1);
        
        for(vector<int> t: times){
            graph[t[0]].push_back({t[2], t[1]});
            // weight, destination
        }

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<int> dist(n+1, INT_MAX);
        dist[k] = 0;

        pq.push({dist[k], k});

        while(!pq.empty()){

            int currDest = pq.top()[1]; pq.pop();

            for(pair<int,int> g: graph[currDest]){
                int d = g.second;
                int w = g.first;

                cout << d << " " << w << endl;

                if(dist[d] > dist[currDest] + w){
                    dist[d] = dist[currDest] + w;
                    pq.push({dist[d], d});
                }
            }
        }

        int ans = INT_MIN;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX) return -1;
            ans = max(ans, dist[i]);
        }
        return ans;
    }
};