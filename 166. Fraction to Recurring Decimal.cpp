class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string str = "";
        unordered_map<int, int> map;
        if(denominator == 0) return str;
        if((numerator > 0 && denominator < 0) || (numerator < 0 && denominator > 0))
            str.append(1, '-');
        long long n = abs((long long)numerator), d = abs((long long)denominator), m = n % d;
        str.append(to_string(n / d));
        if(m == 0) return str;
        str.append(1, '.');
        while(m > 0){
            if(map.find(m) == map.end()){
                map[m] = str.length();
                m *= 10;
                str.append(to_string(m / d));
                m %= d;
            }else{
                str.insert(str.begin() + map[m], '(');
                str.append(1, ')');
                break;
            }
        }
        return str;
    }
};
