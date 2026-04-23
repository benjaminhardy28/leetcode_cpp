class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0) return 0;

        unordered_map<char, int> last_index;
        int l = 0;
        int r = 1;
        int maxLength = 1;

        last_index[s[0]] = 0;

        for(int r=1; r<s.size(); r++){
            char cur = s[r];

            cout << "pass l: " << l << s[l] << " r: " << r << s[r] << "\n";

            if(last_index.contains(cur) && last_index[cur] > -1){
                cout << "problem l: " << l << s[l] << " r: " << r << s[r] << "\n";
                l = max(l, last_index[cur] + 1);
                cout << "new l: " << l << s[l] << " r: " << r << s[r] << "\n";
            }
            last_index[cur] = r;

            maxLength = maxLength > (r - l + 1) ? maxLength : (r - l + 1);
            cout << "max length" << maxLength << "\n";

        }
        return maxLength;
    }
};