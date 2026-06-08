class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int n=nums.size();
        long long first = LLONG_MIN;
        long long second = LLONG_MIN;
        long long third = LLONG_MIN;
        for(int i=0;i<n;i++){
            if(nums[i]==first || nums[i]==second || nums[i]==third){
                continue;
            }
            if(first<nums[i]){
                third=second;
                second=first;
                first=nums[i];
            }
            else if(second<nums[i]){
                third=second;
                second=nums[i];
            }
           else if(third<nums[i]){
                third=nums[i];
            }
        }
        if(third==LLONG_MIN){
            return first;
        }
        return third;
    }
};