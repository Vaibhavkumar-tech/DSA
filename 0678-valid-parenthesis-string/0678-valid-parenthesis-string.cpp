class Solution {
public:
    bool checkValidString(string s) {
        int n=s.size();
        int mino=0;
        int maxi=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                mino++;
                maxi++;
            }
            else if(s[i]==')'){
                mino--;
                maxi--;
            }
            else{
                mino--;
                maxi++;
            }
            if(maxi<0){
                return false;
            }
            mino=max(mino,0);
        }
        return mino == 0;
    }
};