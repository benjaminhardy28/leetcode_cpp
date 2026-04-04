class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for(auto &s: strs){

            // make a frequency map
            vector<int> freq(26, 0);

            for(char c: s){
                freq[c - 'a'] += 1;
            }

            // create a key for each string value
            string key;

            for(int i=0; i<26; i++){
                key.push_back(freq[i]);
            }

            mp[key].push_back(s);
        }

        // group key:value vectors to be returned
        vector<vector<string>> res;
        for(auto &[k,v] : mp){
            res.push_back(v);
        }

        return res;
    }
};