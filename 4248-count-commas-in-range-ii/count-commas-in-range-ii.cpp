class Solution {
    long long dp[20][2][2][20];
    
    long long func(string &s, int idx, bool tight, bool lz, int len) {
        if (idx == s.length()) {
            if (lz) return 0; 
            return (len - 1) / 3; 
        }
        if (dp[idx][tight][lz][len] != -1) return dp[idx][tight][lz][len];

        int up = tight ? (s[idx] - '0') : 9;
        long long ans = 0;
        for (int i = 0; i <= up; i++) {
            bool newTight = tight && (i == up);
            bool newLz = lz && (i == 0);
            int newLen = newLz ? 0 : len + 1;   
            ans += func(s, idx + 1, newTight, newLz, newLen);
        }
        return dp[idx][tight][lz][len] = ans;
    }

public:
    long long countCommas(long long n) {
        memset(dp, -1, sizeof(dp));
        string s = to_string(n);
        return func(s, 0, 1, 1, 0); 
    }
};