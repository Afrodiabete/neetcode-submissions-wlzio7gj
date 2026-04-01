class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int first_head= 0, first_tail= matrix.size()- 1, first_pivot;
        while(first_tail- first_head> 1){
            first_pivot= (first_head+ first_tail)/ 2;
            if(matrix[first_pivot][0] > target){
                first_tail= first_pivot;
            }
            else{
                first_head= first_pivot;
            }
        }
        if(matrix[first_tail][0]<= target) first_pivot= first_tail;
        else first_pivot= first_head;
        int second_head= 0, second_tail= matrix[first_pivot].size(), second_pivot;
        while(second_tail- second_head> 1){
            second_pivot= (second_head+ second_tail)/ 2;
            if(matrix[first_pivot][second_pivot] == target) return true;
            else if(matrix[first_pivot][second_pivot] > target){
                second_tail= second_pivot;
            }
            else{
                second_head= second_pivot;
            }
        }
        if(matrix[first_pivot][second_head]== target || matrix[first_pivot][second_tail]== target) return true;
        return false;
    }
};
