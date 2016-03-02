class Solution {
public:
    int maxProduct(vector<string>& words) {
        const size_t n = words.size();
        int max_product = 0;
        vector<int> bits(n, 0);
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < words[i].length(); ++j)
                bits[i] |= (1 << (words[i][j] - 'a'));
        for(int i = 0; i < n; ++i)
            for(int j = i + 1; j < n; ++j)
                if((bits[i] & bits[j]) == 0)
                    max_product = max(max_product, (int)(words[i].length() * words[j].length()));
        return max_product;
    }
};
