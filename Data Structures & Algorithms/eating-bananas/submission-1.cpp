class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int head= 0, tail= *max_element(piles.begin(), piles.end()), count, pivot;
        while(tail- head > 1){
            pivot= (tail+ head)/ 2;
            count= 0;
            for(auto p: piles){
                if(p% pivot != 0){
                    count+= ((p/ pivot)+ 1);
                }
                else{
                    count+= (p/ pivot);
                }
            }
            if(count> h){
                head= pivot;
            }
            else{
                tail= pivot;
            }
        }
        return tail;

    }
};
