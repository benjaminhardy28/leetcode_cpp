class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> frequency_map;

        for(auto num: nums){
            frequency_map[num] += 1;
        }

        vector<int> bucket_count[nums.size()+1];

        for (const auto& [key, value] : frequency_map) {
            bucket_count[value].push_back(key);
        }

        vector<int> result;
        int num_found = 0;
        // loop from where i = nums.size() since the maximum possible frequency
        // of an item is the size of the input array, which is an index of the size+1
        for(int i=nums.size(); i>=0; i--){

            if(num_found == k){
                break;
            }

            if(bucket_count[i].size() > 0){
                for(int val: bucket_count[i])
                {
                    result.push_back(val);
                    num_found++;
                }
            }
        }
        return result;
    }
};