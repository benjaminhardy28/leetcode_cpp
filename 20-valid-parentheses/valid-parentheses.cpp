class Solution {
public:
    bool isValid(string s) {
        
        if(s.size() % 2 != 0){
            return false;
        }

        int i = 0;

        unordered_map<char, char> paranthesis_map = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };

        stack<char> stack;

        while(i<s.size()){

            if(!paranthesis_map.contains(s[i])){
                stack.push(s[i]);
            } else {
                if(stack.size() == 0) return false;
                
                char top = stack.top();
                stack.pop();

                if(top != paranthesis_map[s[i]]){
                    return false;
                }
            }

            i++;
        }

        if(stack.size() != 0){
            return false;
        }

        return true; 
    }
};