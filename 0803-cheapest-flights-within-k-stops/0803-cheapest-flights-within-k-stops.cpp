class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int, vector<pair<int,int>>> map;
        // pair -> cost, dst


        for ( vector<int>& flight : flights ) {
            map[flight[0]].emplace_back(flight[2],flight[1]);
        }

        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> pq;
        // cost, dst

        for (auto &pair : map[src]) {
            pq.push({pair.first, pair.second, 0});
        }

        vector<vector<int>> dist(n, vector<int>(k+2, INT_MAX));
        dist[src][0] = 0;


        while (!pq.empty()) {
            auto [cost,dest, iter] = pq.top(); pq.pop();
            // cout << cost << " " << dest << " " << iter << endl;

            if (dest == dst) return cost;
            if (iter >= k) continue;


            for (auto &pair : map[dest]) {
                int newCost = cost + pair.first;
                if (newCost < dist[pair.second][iter+1]) {
                    dist[pair.second][iter+1] = newCost;
                    pq.push({newCost, pair.second, iter+1});
                }
            }
        }
        return -1;
    }
};