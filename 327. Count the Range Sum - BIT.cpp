class BinaryIndexedTree{
private:
	vector<int> sums;
public:
	BinaryIndexedTree(const int &n){
		sums.resize(n + 1, 0);
	}
	int sum(int index){
		index++;
		int ans = 0;
		while(index > 0){
			ans += sums[index];
			index -= (index & -index);
		}
		return ans;
	}
	void update(int index, int val){
		index++;
		while(index < sums.size()){
			sums[index] += val;
			index += (index & -index);
		}
	}
};
class Solution {
public:
    int countRangeSum(vector<int> &nums, int lower, int upper){
    	const size_t n = nums.size();
    	if(n == 0) return 0;
    	vector<long long> sums(nums.begin(), nums.end()), osums;
    	for(int i = 1; i < n; ++i)
    		sums[i] += sums[i - 1];
    	unordered_set<long long> set(sums.begin(), sums.end());
    	osums = vector<long long>(set.begin(), set.end());
    	sort(osums.begin(), osums.end());
    	BinaryIndexedTree BIT(osums.size());
    	int cnt = 0, left, right, cur;
    	for(int i = 0; i < n; ++i){
    		left = lower_bound(osums.begin(), osums.end(), sums[i] - upper) - osums.begin();
    		right = upper_bound(osums.begin(), osums.end(), sums[i] - lower) - osums.begin();
    		cur = lower_bound(osums.begin(), osums.end(), sums[i]) - osums.begin();
    		cnt += BIT.sum(right - 1) - BIT.sum(left - 1) + (lower <= sums[i] && sums[i] <= upper ? 1 : 0);
    		BIT.update(cur, 1);
    	}
    	return cnt;
    }
};
