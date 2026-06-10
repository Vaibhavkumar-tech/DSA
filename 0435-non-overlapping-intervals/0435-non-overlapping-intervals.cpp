class Solution {
public:
    
    static bool comp(vector<int>& a, vector<int>& b){
        return a[1] < b[1];
    }
    
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        int n = intervals.size();
        
        // Sort according to ending time
        sort(intervals.begin(), intervals.end(), comp);
        int count = 0;
        int lasttime = INT_MIN;
        
        // Select maximum non-overlapping intervals
        for(int i = 0; i < n; i++){
            
            if(intervals[i][0] >= lasttime){
                
                count++;
                lasttime = intervals[i][1];
            }
        }
        
        // Intervals to remove
        return n - count;
    }
};