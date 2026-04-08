class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int head= 0, tail= k- 1;
        vector<int> ans;
        for(int i=0; i< nums.size()- k+ 1; i++){
            if(ans.size()== 0){
                ans.push_back(*max_element(nums.begin(), nums.begin()+ k));
            }
            else{
                if(nums[head- 1]== ans[i-1]){
                    ans.push_back(*max_element(nums.begin()+ head, nums.begin()+ head+ k));
                }
                else{
                    ans.push_back(max(ans[i-1], nums[tail]));
                }
            }
            head++;
            tail++;
        }
        return ans;
    }
};
