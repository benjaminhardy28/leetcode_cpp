class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        int arrL[size];
        int arrR[size];

        int mult = 1;
        arrL[0] = 1;
        for(int i=1; i<size; i++){
            arrL[i] = nums[i-1]*mult;
            mult = nums[i-1]*mult;
        }

        mult = 1;
        arrR[size-1] = 1;
        for(int i=size-2; i>=0; i--){
            arrR[i] = nums[i+1]*mult;
            mult = nums[i+1]*mult;
        }

        vector<int> res;
        for(int i=0; i<size; i++){
            res.push_back(arrR[i]*arrL[i]);
        }
        return res;
    }
};

//       [1,2,3,4]
// left: [1,1,2,6]
// right:[24,12,4,1]