#include <array>
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<map<int,bool>> column(9);
        vector<map<int,bool>> row(9);
        vector<map<int,bool>> square(9);
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j] != '.'){
                    if(column[i][board[i][j]]== true){
                        return false;
                    }
                    column[i][board[i][j]]= true;
                    if(row[j][board[i][j]]== true){
                        return false;
                    }
                    row[j][board[i][j]]= true;
                }
            }
        }
        vector<array<int, 2>> points = {
            {0,0}, {0,3}, {0,6},
            {3,0}, {3,3}, {3,6},
            {6,0}, {6,3}, {6,6}
        };
        for(int k=0; k<9; k++){
            for(int i=0; i<3; i++){
                for(int j=0; j<3; j++){
                    if(board[i+points[k][0]][j+points[k][1]] != '.'){
                        if(square[k][board[i+points[k][0]][j+points[k][1]]]== true){
                            return false;
                        }
                        square[k][board[i+points[k][0]][j+points[k][1]]]= true;
                    }
                }
            }
        }
        return true;
    }
};
