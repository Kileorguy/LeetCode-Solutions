class Solution {
public:

    bool dfs(vector<vector<int>> &graph, vector<int> &visit, vector<int> &ans,int course){
        if(visit[course] == 0) {
            return false;
            }
        if(visit[course] == 1){

            return true;
        }

        visit[course] = 0;
        for(int n : graph[course]){
            if(!dfs(graph,visit, ans,n)) return false;
        }
        ans.push_back(course);

        visit[course] = 1;
        return true;
   }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ans;
        vector<vector<int>> graph(numCourses, vector<int>());
        vector<int> visit(numCourses, -1);

        for(vector<int> &pair: prerequisites){
            graph[pair[1]].push_back(pair[0]);
        }

        for(int i=0;i<numCourses;i++){
            if(visit[i]==-1){
                if(!dfs(graph, visit, ans, i)) return {};
            }
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};