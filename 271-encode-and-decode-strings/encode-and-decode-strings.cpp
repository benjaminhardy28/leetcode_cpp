class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string encoded_string;
        for(string s: strs){
            int len = s.size();
            string len_string = to_string(len)+";";
            encoded_string.append(len_string);
            encoded_string.append(s);
        }
        return encoded_string;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> decoded_string;
        int i=0;

        while(i<s.size()){
            string string_digit;
            while(i<s.size() && isdigit(s[i])){
                string_digit += s[i];
                i++;
            }
            int digit = stoi(string_digit);
            i++; // skip semicolon
            string dec = s.substr(i,digit);
            decoded_string.push_back(dec);
            i=i+digit;
        }
    
        return decoded_string;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));