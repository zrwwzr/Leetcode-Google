struct node{
  int val, index, cnt;
  node(int v, int i) : val(v), index(i), cnt(0){};
  bool operator <= (const node &n) const{
      return val <= n.val;
  }
};
class Solution {
public:
    void merge(int l, int r, vector<node> &nodes){
        int m = (l + r) / 2, i = l, j = m + 1;
        vector<node> res;
        while(i <= m && j <= r){
            if(nodes[i] <= nodes[j])
                nodes[i].cnt += j - m - 1;
            res.push_back(nodes[i] <= nodes[j] ? nodes[i++] : nodes[j++]);
        }
        while(i <= m){
            nodes[i].cnt += j - m - 1;
            res.push_back(nodes[i++]);
        }
        while(j <= r) res.push_back(nodes[j++]);
        for(i = 0; i < res.size(); ++i) nodes[i + l] = res[i];
    }
    void mergeSort(int l, int r, vector<node> &nodes){
        if(l < r){
            int m = (l + r) / 2;
            mergeSort(l, m, nodes);
            mergeSort(m + 1, r, nodes);
            merge(l, r, nodes);
        }
    }
    vector<int> countSmaller(vector<int>& nums) {
        const size_t n = nums.size();
        vector<node> nodes;
        for(int i = 0; i < n; ++i)
            nodes.push_back(node(nums[i], i));
        mergeSort(0, n - 1, nodes);
        vector<int> res(n, 0);
        for(int i = 0; i < n; ++i)
            res[nodes[i].index] = nodes[i].cnt;
        return res;
    }
};
