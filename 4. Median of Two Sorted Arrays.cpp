class Solution {
public:
    double median(const vector<int> &nums){
        const size_t m = nums.size();
        if(m % 2 == 0) return median(nums[m / 2], nums[m / 2 - 1]);
        else return nums[m / 2];
    }
    double median(int a, int b){
        return (a + b) * 0.5;
    }
    double median(int a, int b, int c){
        int min_val = min(a, min(b, c));
        int max_val = max(a, max(b, c));
        return a + b + c - min_val - max_val;
    }
    double median(int a, int b, int c, int d){
        int min_val = min(a, min(b, min(c, d)));
        int max_val = max(a, max(b, max(c, d)));
        return (a + b + c + d - min_val - max_val) * 0.5;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        const size_t m = nums1.size(), n = nums2.size();
        if(m > n) return findMedianSortedArrays(nums2, nums1);
        else if(m == 0 || n == 0) return m == 0 ? median(nums2) : median(nums1);
        else if(m == 1){
            if(n == 1) return median(nums1[0], nums2[0]);
            else if(n % 2 != 0) return median(nums2[n / 2], median(nums2[n / 2 - 1], nums1[0], nums2[n / 2 + 1]));
            else return median(nums2[n / 2 - 1], nums1[0], nums2[n / 2]);
        }else if(m == 2){
            if(n == 2) return median(nums1[0], nums1[1], nums2[0], nums2[1]);
            if(n % 2 != 0) return median(max(nums1[0], nums2[n / 2 - 1]), nums2[n / 2], min(nums1[1], nums2[n / 2 + 1]));
            else return median(max(nums1[0], nums2[n / 2 - 2]), nums2[n / 2 - 1], nums2[n / 2], min(nums1[1], nums2[n / 2 + 1]));
        }
        int mid1 = (m - 1) / 2, mid2 = (n - 1) / 2;
        if(nums1[mid1] <= nums2[mid2]){
            nums1 = vector<int>(nums1.begin() + mid1, nums1.end());
            nums2 = vector<int>(nums2.begin(), nums2.end() - mid1);
        }else{
            nums1 = vector<int>(nums1.begin(), nums1.end() - mid1);
            nums2 = vector<int>(nums2.begin() + mid1, nums2.end());
        }
        return findMedianSortedArrays(nums1, nums2);
    }
};
