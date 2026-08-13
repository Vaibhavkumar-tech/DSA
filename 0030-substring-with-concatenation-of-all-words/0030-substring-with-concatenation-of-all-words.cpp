class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int>ans;
        int wordCount=words.size();
        int wordlen=words[0].size();
        int totallen=wordCount*wordlen;
        if(totallen>s.size()) return ans;
        unordered_map<string,int>need;
        for (string word : words) {
            need[word]++;
        }
        for(int i=0;i<wordlen;i++){
            int l=i;
            int r=i;
            int count=0;
            unordered_map<string,int>window;
            while(r+wordlen<=s.size()){
                string word=s.substr(r,wordlen);
                r+=wordlen;
                //not required word
                if(need.find(word)==need.end()){
                    window.clear();
                    l=r;
                    count=0;
                    continue;
                }
                window[word]++;
                count++;
                //for more than one repeation of words
                while(window[word]>need[word]){
                    string leftstr=s.substr(l,wordlen);
                    window[leftstr]--;
                    count--;
                    l+=wordlen;
                }
                if(count==wordCount){
                    ans.push_back(l);
                    string leftstr=s.substr(l,wordlen);
                    window[leftstr]--;
                    l+=wordlen;
                    count--;
                }
            }
        }
        return ans;
    }
};