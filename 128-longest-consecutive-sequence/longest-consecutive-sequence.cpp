class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> nums_set;

        for(int num: nums){
            nums_set.insert(num);
        }

        int largestLength = 0;
        for(int num: nums_set){

            if(!nums_set.contains(num-1)){
                int length = 1;
                int current = num;

                while(nums_set.contains(current+1)){
                    length++;
                    current = current+1;
                }

                if(length > largestLength) {
                    largestLength = length;
                }
            }
        }
        return largestLength;
    }
};