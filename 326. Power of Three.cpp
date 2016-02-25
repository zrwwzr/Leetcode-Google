class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n <= 0) return false;
        double m = log10(n) / log10(3.0);
        return (int)floor(m) - m == 0; 
    }
};
