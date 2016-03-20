class Solution {
public:
    int mergeSort(vector<long long>& nums, int begin, int end, const int &lower, const int &upper){
        if(begin < end){
            vector<long long> temp;
            int mid = (begin + end) / 2;
            int res = mergeSort(nums, begin, mid, lower, upper) + mergeSort(nums, mid + 1, end, lower, upper);
            int i = begin, j = mid + 1, left = mid + 1, right = mid + 1;
            while(i <= mid){
                while(left <= end && nums[left] - nums[i] < lower) left++;
                while(right <= end && nums[right] - nums[i] <= upper) right++;
                res += right - left;
                while(j <= end && nums[i] > nums[j]) temp.push_back(nums[j++]);
                temp.push_back(nums[i++]);
            }
            for(int i = 0; i < temp.size(); ++i) nums[i + begin] = temp[i];
            return res;
        }
        return 0;
    }
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        const size_t n = nums.size();
        vector<long long> sums(n + 1, 0);
        for(int i = 1; i <= n; ++i) sums[i] = sums[i - 1] + nums[i - 1];
        return mergeSort(sums, 0, n, lower, upper);
    }
};
