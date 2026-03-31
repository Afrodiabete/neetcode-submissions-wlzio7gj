class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<float, float>> data;
        for(int i=0; i<position.size(); i++){
            data.push_back(pair<float, float>{position[i], speed[i]});
        }
        sort(data.begin(), data.end(),[](pair<float, float>a, pair<float, float>b){return a.first > b.first;});
        stack<float> ans;
        for(int i=0; i<position.size(); i++){
            if(ans.empty()){
                ans.push((target- data[i].first)/ data[i].second);
            }
            else{
                float temp= (target- data[i].first)/ data[i].second;
                if(temp> ans.top()){
                    ans.push(temp);
                    
                }
            }
        }
        return ans.size();
    }
};
