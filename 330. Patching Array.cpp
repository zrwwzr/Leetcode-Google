class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int cnt = 0, i = 0;
        long long end = 1;
        while(end <= n){
            if(i < nums.size() && end >= nums[i]){
                end += nums[i++];
            }else{
                end *= 2;
                cnt++;
            }
        }
        return cnt;
    }
};
