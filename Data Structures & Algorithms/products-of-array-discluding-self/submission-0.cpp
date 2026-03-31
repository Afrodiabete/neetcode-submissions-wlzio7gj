class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int total=1;
        vector<int> has_0;
        vector<int> ans;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]!=0) {
                total*=nums[i];
            }
            else{
                has_0.push_back(i);
            }
        }
        if(has_0.size()>1){
            ans.resize(nums.size(), 0);
        }
        else if(has_0.size()==0){
            for(int i=0; i<nums.size(); i++){
                ans.push_back(total/nums[i]);
            }
        }
        else{
            for(int i=0; i<nums.size(); i++){
                
                if(i == has_0[0]){
                    ans.push_back(total);
                }
                else{
                    ans.push_back(0);
                }
            }
        }
        return ans;
    }
};
