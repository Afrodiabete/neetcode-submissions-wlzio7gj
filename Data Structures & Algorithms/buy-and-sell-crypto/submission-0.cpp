class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans= 0, m= 100;
        for(int i=0; i< prices.size(); i++){
            m= min(prices[i], m);
            ans= max(prices[i]- m, ans);
        }
        return ans;
    }
};
