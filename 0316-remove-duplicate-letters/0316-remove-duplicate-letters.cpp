class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int>lastIndex(26);
        int n=s.size();
        for(int i=0;i<n;i++){
            int idx=(s[i]-'a');
            lastIndex[idx]=i;
        }
        vector<bool>taken(26,false);
        string result="";
        for(int i=0;i<n;i++){
            int idx = s[i] - 'a';
            if(taken[idx]==true) continue;
            while(!result.empty() && result.back()>s[i] && lastIndex[result.back() - 'a']>i){
                taken[result.back() - 'a'] = false;
                result.pop_back();
            }
            taken[idx] = true;
            result.push_back(s[i]);
        }
        return result;
    }
};