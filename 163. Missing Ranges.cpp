class Solution {
public:
    string getString(int lower, int upper){
        return lower == upper ? to_string(lower) : to_string(lower).append("->").append(to_string(upper));
    }
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        const size_t n = nums.size();
        vector<string> res;
        if(n == 0) res.push_back(getString(lower, upper));
        for(int i = 0; i < n; ++i){
            if(i == 0 && lower < nums[i])
                res.push_back(getString(lower, nums[i] - 1));
            if(i > 0 && nums[i - 1] + 1 != nums[i])
                res.push_back(getString(nums[i - 1] + 1, nums[i] - 1));
            if(i == n - 1 && nums[i] < upper)
                res.push_back(getString(nums[i] + 1, upper));
           
        }
        return res;
    }
};
