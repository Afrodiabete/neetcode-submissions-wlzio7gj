class Solution {
public:
    int search(vector<int>& nums, int target) {
        int head= 0, tail= nums.size()-1, pivot;
        while((tail- head)> 1){
            pivot= (head+ tail)/ 2;
            if(nums[pivot]== target) return pivot;
            else if(nums[pivot]> target){
                if(nums[tail]<= nums[pivot] && nums[tail]>= target){
                    head= pivot;
                    
                }
                else{
                    tail= pivot;
                }
            }
            else{
                if(nums[head]>= nums[pivot] && nums[head]<= target){
                    tail= pivot;
                }
                else{
                    head= pivot;
                }
            }
        }
        if(nums[tail]== target) return tail;
        if(nums[head]== target) return head;
        return -1;
    }
};
