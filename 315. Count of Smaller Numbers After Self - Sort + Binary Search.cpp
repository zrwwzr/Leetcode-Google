class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        const size_t n = nums.size();
        vector<int> cnt(n, 0), sorted;
        if(n == 0) return cnt;
        sorted.push_back(nums[n - 1]);
        int left, right, mid;
        for(int i = n - 2; i >= 0; --i){
            left = 0, right = sorted.size() - 1;
            while(left <= right){
                mid = (left + right) / 2;
                if(sorted[mid] < nums[i])
                    left = mid + 1;
                else right = mid - 1;
            }
            sorted.insert(sorted.begin() + left, nums[i]);
            cnt[i] = left;
        }
        return cnt;
    }
};
