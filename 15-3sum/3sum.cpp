class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        int i=0;
        vector<vector<int>> res;

        while(i<nums.size()-1){

            // process trios with two of the same values once (when i and i+1)
            // But skip second time (when i and i-1)
            if(i > 0 && nums[i] == nums[i-1]){ 
                i++;
                continue;
            }

            int left = i+1;
            int right = nums.size()-1;

            while(left < right){
                if(nums[i] + nums[left] + nums[right] > 0){
                    right--;
                } else if (nums[i] + nums[left] + nums[right] < 0){
                    left++;
                } else {
                    res.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    while(left < right && nums[left] == nums[left-1]){
                        left++;
                    }
                }
            }
            i++;
        }
        return res;
    }
};