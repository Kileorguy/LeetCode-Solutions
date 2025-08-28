class Solution {
public:
    double myPow(double x, int n) {
        long long exp = n;       
        long double base = x;
        long double result = 1.0;

        if (exp < 0) {
            base = 1.0 / base;    
            exp = -exp;
        }

        while (exp > 0) {
            if (exp & 1) {
                result *= base;
            }
            base *= base;
            exp >>= 1;
        }

        return (double)result;    
    }
};
