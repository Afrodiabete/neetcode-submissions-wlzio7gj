class Solution {
public:
    int trap(vector<int>& height) {
        int pivot= 0, result= 0;
        vector<int> water(height.size(), 0);
        if(height.size()== 1) return 0;
        for(int i=0; i< height.size(); i++){
            if(height[i] >= height[pivot]){
                pivot= i;
            }
            water[i]= height[pivot]- height[i];
        }
        int rev_pivot= height.size()- 1;
        for(int i=height.size()-1; i!= pivot; i--){
            if(height[i] >= height[rev_pivot]){
                rev_pivot= i;
            }
            water[i]= height[rev_pivot]- height[i];
        }
        for(int i=0; i<water.size(); i++){
            result+= water[i];
        }
        return result;
    }
};
