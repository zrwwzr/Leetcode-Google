class Solution {
public:
    int maxCoins(vector<int>& nums) {
    	if(nums.empty()) return 0;
    	nums.insert(nums.begin(), 1);
    	nums.push_back(1);
    	const size_t n = nums.size();
    	vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
    	for(int len = 1; len < n - 1; ++len){
    		for(int i = 1, j; i < n - len; ++i){
    			j = i + len - 1;
    			for(int k = i; k <= j; ++k){
    				dp[i][j] = max(dp[i][j], nums[i - 1] * nums[k] * nums[j + 1] + dp[i][k -1] + dp[k + 1][j]);
    			}
    		}
    	}
      return dp[1][n - 2];
    }
};
