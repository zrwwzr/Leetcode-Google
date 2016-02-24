class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        if(nums.empty()) return res;
        int start = 0;
        for(int end = 0; end < nums.size(); ++end){
            if(end == nums.size() - 1 || nums[end] + 1 != nums[end + 1]){
                if(start == end)
                    res.push_back(to_string(nums[end]));
                else
                    res.push_back(to_string(nums[start]).append("->").append(to_string(nums[end])));
                start = end + 1;
            }
        }
        return res;
    }
};
