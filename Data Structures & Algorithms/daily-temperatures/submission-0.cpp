class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> pos;
        vector<int> ans(temperatures.size());
        for(int i= 0; i< temperatures.size(); i++){
            while(!pos.empty()){
                if(temperatures[i]> temperatures[pos.top()]){
                    ans[pos.top()]= i- pos.top();
                    pos.pop();
                }
                else{
                    break;
                }
            }
            pos.push(i);
        }
        return ans;
    }
};
