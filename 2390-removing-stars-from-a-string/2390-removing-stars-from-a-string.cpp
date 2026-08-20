class Solution {
public:
    string removeStars(string s) {
        string result="";
        for(int i=0;i<s.size();i++){
            if(s[i]=='*' && result!=""){
                result.pop_back();
            }
            else if(s[i]!='*'){
                result.push_back(s[i]);
            }
        }
        return result;
    }
};