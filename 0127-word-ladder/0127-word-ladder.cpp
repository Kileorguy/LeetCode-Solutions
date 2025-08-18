class Solution {
public:
    int hammingDist(string beginWord, string word){
        int count = 0;
        for(int i=0;i<beginWord.length();i++){
            if(beginWord[i] != word[i]){
                count++;
            }
        }
        return count;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        unordered_map<string, vector<string>> graph;
        unordered_set<string> visit;
        bool check = false;

        wordList.push_back(beginWord);

        string a, b;

        for(int i=0;i<wordList.size();i++){
            a = wordList[i];
            for(int j=i+1;j<wordList.size();j++){
                b = wordList[j];
                if(hammingDist(a, b) == 1){
                    graph[a].push_back(b);
                    graph[b].push_back(a);
                }
                
            }

            if(wordList[i] == endWord){
                check = true;
            }
        }

        if(!check) return 0;


        int count = 0;
        queue<string> q;
        visit.insert(beginWord);
        for(string &s: graph[beginWord]){
            q.push(s);
            visit.insert(s);
        }

        while(!q.empty()){
            int iterCount = q.size();
            count++;
            
            for(int i=0;i<iterCount;i++){
                string front = q.front(); q.pop();
                if(front == endWord) return count+1;

                for(string &s: graph[front]){
                    if(visit.count(s) == 0){
                        q.push(s);
                    }
                    visit.insert(s);
                }
            }
        }
        
        return 0;

    }
};