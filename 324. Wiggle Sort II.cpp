class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        if(nums.empty()) return;
        const size_t n = nums.size();
        vector<int> temp(n);
        sort(nums.begin(), nums.end());
        int i = (n + 1) >> 1, j = n;
        for(int k = 0; k < n; ++k)
           temp[k] = k % 2 == 0 ? nums[--i] : nums[--j];
        nums.swap(temp);
    }
};
