class Solution {
public:
    int dp[1001][1001][3];

    int func(int i, int prev, int diff, vector<int>& nums) {

        if(i == nums.size())
            return 0;
        if(dp[i][prev + 1][diff + 1] != -1)
            return dp[i][prev + 1][diff + 1];

        int nt = func(i + 1, prev, diff, nums);

        int take = 0;

        if(prev == -1) {

            take = 1 + func(i + 1, i, 0, nums);

        }
        else {

            int val = nums[prev] - nums[i];
            if(diff == 0 && val != 0) {

                if(val < 0)
                    take = 1 + func(i + 1, i, 1, nums);
                else
                    take = 1 + func(i + 1, i, -1, nums);
            }
            else if(diff == 1 && val > 0) {

                take = 1 + func(i + 1, i, -1, nums);
            }
            else if(diff == -1 && val < 0) {

                take = 1 + func(i + 1, i, 1, nums);
            }
        }

        return dp[i][prev + 1][diff + 1] = max(take, nt);
    }

    int wiggleMaxLength(vector<int>& nums) {

        memset(dp, -1, sizeof(dp));

        return func(0, -1, 0, nums);
    }
};