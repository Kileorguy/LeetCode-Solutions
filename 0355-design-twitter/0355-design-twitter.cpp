class Twitter {
public:
    using userId = int;
    using tweetId = int;
    unordered_map<userId, unordered_set<userId>> followTable; 
    unordered_map<userId, vector<pair<int, tweetId>>> tweetTable; 
    int tweet_count;
    Twitter(){
        tweet_count = 0;
    }

    struct Compare{

        bool operator()(const pair<int,int> &a, const pair<int,int> &b){
            return a.first > b.first;
        }
    };
    
    void postTweet(int userId, int tweetId) {
        vector<pair<int,int>> &vect = tweetTable[userId];
        vect.insert(vect.begin(), {tweet_count, tweetId});
        tweet_count++;
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, Compare> sort;
        vector<int> followedUsers;
        followedUsers.push_back(userId);
        
        unordered_set<int> &us = followTable[userId];

        for(auto it=us.begin(); it!=us.end(); ++it){
            followedUsers.push_back(*it);
        }

        for(int &id: followedUsers){
            vector<pair<int,int>> &tweets = tweetTable[id];
            for(pair<int,int> &t: tweets){
                
                if(sort.size() < 10){
                    sort.push(t);
                }else{
                    if(sort.top().first < t.first){
                        sort.pop();
                        sort.push(t);
                    }
                }
            }
        }

        vector<int> ans;
        while(!sort.empty()){
            ans.insert(ans.begin(),sort.top().second);
            sort.pop();
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        followTable[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followTable[followerId].erase(followeeId);
    }
};