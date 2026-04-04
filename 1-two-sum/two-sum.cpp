class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int, int> desired_values;

        for(int i=0; i<nums.size(); i++){
            int desired = target - nums.at(i);
            if(desired_values.contains(desired)){
                return {desired_values[desired], i};
            }
            desired_values[nums.at(i)] = i;
        }
        return {};
    }
};