class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0;
        int r = s.size()-1;

        while(l < r){ // dont need to consider ==
            while(l < r && !isalnum(s[l])){
                l++;
            }
            while(l < r && !isalnum(s[r])){
                r--;
            }
            cout << s[l] << s[r] << "\n";
            if(tolower(s[l]) != tolower(s[r])){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};