class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        const int n = digits.size();
        int carry = 1, sum = 0;
        for(int i = n - 1; i >= 0; --i){
            sum = carry + (digits[i]);
            digits[i] = sum % 10;
            carry = sum / 10;
        }
        if(carry > 0) 
            digits.insert(digits.begin(), carry);
        return digits;
    }
};
