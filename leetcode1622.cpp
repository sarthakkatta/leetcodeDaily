/*
Problem: LeetCode 1622 – Fancy Sequence

Approach:
1. Maintain two global transformations: multiplication (mul) and addition (sum).
2. Instead of updating all elements for addAll and multAll, store elements in a normalized form.
3. When appending a value, reverse the current transformation using modular inverse so that it fits the stored base form.
4. For addAll, update the global addition value.
5. For multAll, update both multiplication and addition accordingly.
6. When retrieving an index, apply the stored transformations to reconstruct the actual value.

Time Complexity: O(log MOD) for append (due to modular inverse), O(1) for other operations
Space Complexity: O(N)
*/

typedef long long ll;
class Fancy {
public:
    vector<int> v;
    ll sum = 0;
    ll mul = 1;
    ll mod = 1e9 + 7;

    ll power(ll base, ll exp){
        ll ans = 1;
        base %= mod;
        while(exp){
            if(exp & 1) ans = (ans * base) % mod;
            exp /= 2;
            base = (base * base) % mod;
        }
        return ans;
    }

    ll modInverse(ll n){
        return power(n, mod - 2);
    }

    Fancy() {}

    void append(int val){
        ll temp = val;
        ll base = ((temp - sum + mod) % mod * modInverse(mul)) % mod;
        v.push_back(base);
    }

    void addAll(int inc){
        sum = (sum + inc) % mod;
    }

    void multAll(int m){
        mul = (mul * m) % mod;
        sum = (sum * m) % mod;
    }

    int getIndex(int idx){
        if(idx >= v.size()) return -1;
        return (v[idx] * mul + sum) % mod;
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */
