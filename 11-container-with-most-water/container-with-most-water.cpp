class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int maxArea = 0;

        int l = 0;
        int r = height.size()-1;

        while(l < r){
            int smallestHeight =  min(height[l], height[r]);
            int currentArea = smallestHeight * (r-l);

            maxArea = currentArea > maxArea ? currentArea : maxArea;

            if(height[l] > height[r]){
                r--;
            } else {
                l++;
            }
        }
        return maxArea;

    }
};