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
        cout << "enc" << encoded_string;
        return encoded_string;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> decoded_string;
        int i=0;

        while(i<s.size()){
            string string_digit;
            int start = i;
            while(i<s.size() && isdigit(s[i])){
                cout << "is digit apparently" << s[i] << "\n";
                string_digit += s[i];
                i++;
            }
            int digit = stoi(string_digit);
            i++; // skip semicolon
            cout << i << start << digit << "\n";
            string dec = s.substr(i,digit);
            decoded_string.push_back(dec);
            cout << "dec " << dec << "\n";
            i=i+digit;
        }
    
        return decoded_string;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));