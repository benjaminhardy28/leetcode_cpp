class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> grouped_nums;
        
        for (const auto& num : nums){
            if (!grouped_nums.insert(num).second){
                return true;
            }
        }
        return false;
    }
};