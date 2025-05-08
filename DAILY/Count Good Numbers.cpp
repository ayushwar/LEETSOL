// 08/05/2025
// Count Good Numbers
class Solution {
public:
 const int mod = 1e9 + 7;
    long long power(long long base, long long exp) {
    
        long long ans = 1;
        base %= mod;
        while (exp > 0) {
            if (exp % 2 == 1) {
                ans = (ans * base) % mod;
                // exp=exp-1;
            }
            base = (base * base) % mod;
            exp /= 2;
        }
        return ans;
    }
    int countGoodNumbers(long long n) {
        long long e = (n + 1) / 2;
        long long o = n / 2;

        long long even = power(5, e);
        long long odd = power(4, o);
        return (even * odd) %mod;
    }
};
