class BinaryIndexedTree{
private:
    vector<int> sums;
public: 
    BinaryIndexedTree(int n){
        sums.resize(n + 1, 0);
    }
    void update(int index, int val){
        index++;
        while(index < sums.size()){
            sums[index] += val;
            index += (index & -index);
        }
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
};
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        const size_t n = nums.size();
        if(n == 0) return vector<int>();
        //optimization 1: remove duplicate
        unordered_set<int> set;
        for(int i = 0; i < n; ++i)
            set.insert(nums[i]);
        vector<int> temp(set.begin(), set.end()), res(n, 0);
        //sort the array in order for mapping temp to the range of [1, n]
        sort(temp.begin(), temp.end());
        //remapping
        for(int i = 0; i < n; ++i)
            nums[i] = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin() + 1;
        BinaryIndexedTree bit(n);
        for(int i = n - 1; i >= 0; --i){
            res[i] = bit.sum(nums[i] - 1);
            bit.update(nums[i], 1);
        }
        return res;
    }
};
