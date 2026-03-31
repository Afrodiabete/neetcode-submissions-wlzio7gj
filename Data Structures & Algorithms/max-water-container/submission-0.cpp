class Solution {
public:
    int maxArea(vector<int>& heights) {
        int head=0, tail= heights.size()- 1;
        int result=(tail- head)* min(heights[head], heights[tail]);
        while(head != tail){
            int t_result= (tail- head)* min(heights[head], heights[tail]);
            if(t_result> result){
                result= t_result;
            }
            if(heights[tail]< heights[head]){
                tail--;
            }
            else{
                head++;
            }
        }
        return result;
    }
};
