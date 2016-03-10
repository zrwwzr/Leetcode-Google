class BinaryIndexedTree{
public:
	BinaryIndexedTree(vector<int> &nums){
		const size_t n = nums.size();
		sums.resize(n + 1);
		for(int i = 0; i < nums.size(); ++i)
			update(i, nums[i]);
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
private:
	vector<int> sums;
};
