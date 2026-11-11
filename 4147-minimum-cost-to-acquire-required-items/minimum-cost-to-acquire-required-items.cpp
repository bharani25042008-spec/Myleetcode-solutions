class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
          long long mini=min(cost1+cost2 , costBoth);
          long long minimum_need=min(need1,need2);
          long long ans=0;
          long long rem1=need1-minimum_need;
          long long rem2=need2-minimum_need;
          long long c_type1_1=rem1*(min(mini,(long long)cost1));
          long long c_type2_2=rem2*(min(mini,(long long)cost2));
          ans+=minimum_need*mini;
          ans+=c_type1_1;
          ans+=c_type2_2;
          return ans;
    }
};