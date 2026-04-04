class Solution {
public:
    bool isAnagram(string s, string t) {
        
        if(s.size()!=t.size()) return false;

        int tracked_values[26];

        for(int i=0; i<s.size() ;i++){
            tracked_values[s[i] -'a'] += 1;
            tracked_values[t[i] - 'a'] -= 1;
        }

        for(int check: tracked_values){
            if(check != 0){
                return false;
            }
        }
        return true;
    }
};