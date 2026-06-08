class Solution {
public:
    bool checkValidString(string s) {
        int n=s.size();
        stack<int>open;
        stack<int>star;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                open.push(i);
            }
            else if(s[i]=='*'){
                star.push(i);
            }
            else{
                if(!open.empty()){
                    open.pop();
                }
                else if(!star.empty()){
                    star.pop();
                }
                else{
                    return false;
                }
            }
        }
        while(!open.empty() && !star.empty()){
            if(open.top()>star.top()){  //matlab * cannot be work close bracket
               return false;
            }
            star.pop();
            open.pop();
        }
        return open.empty();
    }
};