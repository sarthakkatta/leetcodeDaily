class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        const int MOD = 1000000007;
        int m = r - l + 1;
        vector<long long> dp(m, 1);
        for (int i = 2; i <= n; i++) {
            vector<long long> pref(m);
            pref[0] = dp[0];
            for (int j = 1; j < m; j++) {
                pref[j] = (pref[j - 1] + dp[j]) % MOD;
            }
            vector<long long> newDp(m, 0);
            if (i % 2 == 0) {
                for (int j = 1; j < m; j++) {
                    newDp[j] = pref[j - 1];
                }
            } else {
                long long total = pref[m - 1];
                for (int j = 0; j < m - 1; j++) {
                    newDp[j] = (total - pref[j] + MOD) % MOD;
                }
            }
            dp = newDp;
        }
        long long ans = 0;
        for (long long x : dp) {
            ans = (ans + x) % MOD;
        }
        return ans * 2 % MOD;
    }
};
