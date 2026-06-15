class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int miniDiff=INT_MAX;
        int result=nums[0]+nums[1]+nums[2];
        for(int i=0;i<n;i++){
            int l=i+1;
            int r=n-1;
            while(l<r){   //agar not equal to target huwa then it will give the closetv of one loop
                int sum=nums[l]+nums[r]+nums[i];
                if(sum==target){
                    return sum;
                }
                else if(sum>target){
                    r--;
                }
                else{
                    l++;
                }
            int Difference=abs(sum-target);
            if(Difference<miniDiff){
                result=sum;
                miniDiff=Difference;
            }
        }
    }
    return result;
}
};