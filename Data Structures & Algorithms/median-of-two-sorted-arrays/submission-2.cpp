class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int mid= (nums1.size()+ nums2.size())/ 2;
        int head=0, tail= mid, pivot_1= 0, pivot_2= mid- pivot_1;
        nums1.insert(nums1.begin(), -1000000);
        nums2.insert(nums2.begin(), -1000000);
        nums1.push_back(1000000);
        nums2.push_back(1000000);
        if(nums1.size()> nums2.size()){
            pivot_2= 0;
            pivot_1= mid- pivot_1;
        }
        while(tail> head){
            if(nums1[pivot_1]> nums2[pivot_2+ 1]){
                tail= pivot_1- 1;
                pivot_1= (head+ tail)/ 2;
                pivot_2= mid- pivot_1;
            }
            else if(nums1[pivot_1+ 1]< nums2[pivot_2]){
                head= pivot_1+ 1;
                pivot_1= (head+ tail)/ 2;
                pivot_2= mid- pivot_1;
            }
            else{
                break;
            }
            
        }
        cout << pivot_1 << " " << pivot_2;
        if((nums1.size()+ nums2.size())% 2!= 0){
            return min(nums1[pivot_1+ 1], nums2[pivot_2+ 1]);
        }
        else{
            double one= max(nums1[pivot_1], nums2[pivot_2]), 
                   two= min(nums1[pivot_1+ 1], nums2[pivot_2+ 1]);
            return (one+ two)/ 2;
        }
        return 0;
    }
};
