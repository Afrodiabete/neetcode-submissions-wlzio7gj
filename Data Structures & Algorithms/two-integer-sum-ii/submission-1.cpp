class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans(2,0);
        for(int i=0; i<numbers.size(); i++){
            int two= target- numbers[i];
            auto t= find(numbers.begin() + i + 1, numbers.end(), two);
            if(t != numbers.end()){
                ans[0]= i + 1;
                ans[1]= distance(numbers.begin(), t) + 1;
                return ans;
            }
        }
        return {0,0};
    }
};
