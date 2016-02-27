class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0, right = nums.size() - 1, mid;
        while(left < right){
            mid = (left + right) / 2;
            //Compare middle element with its neighbours (if neighbours exist)
            if((mid == 0 || nums[mid - 1] < nums[mid]) && (mid == nums.size() - 1 || nums[mid] > nums[mid + 1]))
                return mid;
            else if(mid > 0 && nums[mid - 1] > nums[mid])
                right = mid - 1;
            else
                left = mid + 1;
        }
        return left;
    }
};
