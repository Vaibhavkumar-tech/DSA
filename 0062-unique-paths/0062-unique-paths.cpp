
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int>prev(n,0); //dummy
        for(int i=0;i<m;i++){
            vector<int>curr(n,0); //curr;
            for(int j=0;j<n;j++){
                if(i==0 && j==0){
                    curr[j]=1;
                }
                else{
                    int up=0;
                    int left=0;
                        if(i > 0) {
                            up = prev[j];
                        }

                        // Current row
                        if(j > 0) {
                            left = curr[j-1];
                        }
                    curr[j] = up + left;
                }

            }
            prev=curr;
        }
       return prev[n-1];
    }
};
