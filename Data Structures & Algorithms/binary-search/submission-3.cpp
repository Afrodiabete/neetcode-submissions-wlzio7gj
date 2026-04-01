class Solution {
public:
    int search(vector<int>& nums, int target) {
        int head= 0, tail= nums.size(), pivot;

        while(tail- head > 1){
            pivot= (tail+ head)/ 2;
            cout << pivot << endl;
            if(nums[pivot]== target) return pivot;
            else if(nums[pivot]> target){
                tail= pivot;
            }
            else{
                head= pivot;
            }
        }
        if(nums[head]== target) return head;
        if(nums[tail]== target) return tail;
        return -1;
    }
};
