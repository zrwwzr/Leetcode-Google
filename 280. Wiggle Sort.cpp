class Solution {
public:
    void wiggleSort(vector<int>& nums){
        for(int i = 1; i < nums.size(); ++i)
            if(((1 & i) == 0 && nums[i] > nums[i - 1]) || ((1 & i) != 0 && nums[i - 1] > nums[i]))
                swap(nums[i], nums[i - 1]);
    }
};
