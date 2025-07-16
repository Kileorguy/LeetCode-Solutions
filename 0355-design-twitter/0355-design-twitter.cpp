#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <queue>
#include <algorithm>

class Twitter {
public:
    using userId = int;
    using tweetId = int;
    
    unordered_map<userId, unordered_set<userId>> followTable; 
    unordered_map<userId, deque<pair<int, tweetId>>> tweetTable; 
    
    long long time;

    Twitter() {
        time = 0;
    }

    void postTweet(int userId, int tweetId) {
        tweetTable[userId].push_front({(int)time++, tweetId});
    }
    
    void follow(int followerId, int followeeId) {
        followTable[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followTable[followerId].erase(followeeId);
    }

    vector<int> getNewsFeed(int userId) {
        vector<int> feed;
        feed.reserve(10);

        priority_queue<pair<int, int>> maxHeap;

        if (tweetTable.count(userId)) {
            for (const auto& tweet : tweetTable[userId]) {
                maxHeap.push(tweet);
            }
        }
        int iterCount = 0;
        if (followTable.count(userId)) {
            for (const auto& followeeId : followTable[userId]) {
                if (tweetTable.count(followeeId)) {
                    iterCount = 0;
                    for (const auto& tweet : tweetTable[followeeId]) {
                        if(iterCount == 10) break;
                        maxHeap.push(tweet);
                        iterCount++;
                    }
                }
            }
        }

        int count = 0;
        while (!maxHeap.empty() && count < 10) {
            feed.push_back(maxHeap.top().second);
            maxHeap.pop();
            count++;
        }
        
        return feed;
    }
};