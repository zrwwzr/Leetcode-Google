class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        if(nums.empty()) return;
        const size_t n = nums.size();
        vector<int> temp;
        sort(nums.begin(), nums.end());
        int mid = n % 2 == 0 ? n / 2 : n / 2 + 1;
        int i = mid - 1, j = n - 1, k = 0;
        while(i >= 0 || j >= mid){
            if(k % 2 == 0 && i >= 0) temp.push_back(nums[i--]);
            else if(k % 2 != 0 && j >= mid) temp.push_back(nums[j--]);
            k++;
        }
        nums.swap(temp);
    }
};
