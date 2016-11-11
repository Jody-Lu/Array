class Codec {
public:

    // Encodes a list of strings to a single string.
    // encoded = "len + @ + str"
    string encode(vector<string>& strs) {
        string encoded = "";

        for(string& str : strs) {
            int len = str.size();
            encoded += to_string(len) + "@" + str;
        }

        return encoded;
    }

    // Decodes a single string to a list of strings.
    // find_first_of : Searches the string for the first character that matches any of the characters specified in its arguments.
    vector<string> decode(string s) {
        vector<string> strs;
        int head = 0;
        while(head < s.size()) {
            int at_pos = s.find_first_of('@', head);
            int len = stoi(s.substr(head, at_pos - head));
            head = at_pos + 1;
            strs.push_back(s.substr(head, len));
            head += len;
        }

        return strs;
    }
};