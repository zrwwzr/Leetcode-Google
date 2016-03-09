class Solution {
public:
    vector<int> getMax(const vector<int> &nums, int k){
    	vector<int> res;
    	size_t n = nums.size();
    	for(int i = 0; i < n; ++i){
    		while(!res.empty() && res.size() + n - i > k && res.back() < nums[i])
    			res.pop_back();
    		if(res.size() < k)
    			res.push_back(nums[i]);
    	}
    	return res;
    }
    bool larger(int i, int j, vector<int> &v1, vector<int> &v2){
    	for(; i < v1.size() && j < v2.size(); ++i, ++j){
    		if(v1[i] > v2[j]) return true;
    		else if(v1[i] < v2[j]) return false;
    	}
    	return i != v1.size();
    }
    vector<int> merge(vector<int> &nums1, vector<int> &nums2){
    	int i = 0, j = 0, val1, val2;
    	vector<int> res;
    	while(i < nums1.size() || j < nums2.size())
    		res.push_back(larger(i, j, nums1, nums2) ? nums1[i++] : nums2[j++]); 
    	return res;
    }
    
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
    	const size_t m = nums1.size(), n = nums2.size();
    	vector<int> res, left, right, temp;
    	for(int i = 0, j; i <= m; ++i){
    		j = k - i;
    		if(j >= 0 && j <= n){
    			left = getMax(nums1, i);
    			right = getMax(nums2, j);
    			temp = merge(left, right);
    			if(larger(0, 0, temp, res))
    				res.swap(temp);
    		}
    	}
    	return res;
    }
};
