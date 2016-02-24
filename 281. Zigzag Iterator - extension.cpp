class ZigzagIterator {
public: 
	ZigzagIterator(vector<vector<int>> &nums) {
		for(int i = 0; i < nums.size(); ++i){
			if(nums[i].size() == 0) continue; //skip empty arr
			iterators.push_back(make_pair(nums[i].begin(), nums[i].end()));
		}
		cnt = 0;
	}

	int next() {
		int k = (cnt++) % iterators.size(); 
		int rtn = *(iterators[k].first++);
		//remove empty arr
		if(iterators[k].first == iterators[k].second)
			iterators.erase(iterators.begin() + k);
		return rtn;
	}

	bool hasNext() {
		return iterators.size() > 0;
	}
private:
	vector<pair<vector<int>::iterator, vector<int>::iterator>> iterators;
	int cnt;
};
int main(){
	int arr1[] = {1,2,3};
	int arr2[] = {4,5,6,7};
	int arr4[] = {8,9};
	vector<vector<int>> nums;
	nums.push_back(vector<int>(arr1, arr1 + sizeof(arr1) / sizeof(int)));
	nums.push_back(vector<int>(arr2, arr2 + sizeof(arr2) / sizeof(int)));
	nums.push_back(vector<int>());
	nums.push_back(vector<int>(arr4, arr4 + sizeof(arr4) / sizeof(int)));
	ZigzagIterator zi(nums);
	while(zi.hasNext())
		cout<<zi.next()<<" "; 
	cout<<endl; 
	return 0;
}
