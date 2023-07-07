class Solution {
public:
    string src; 
    size_t ptr;

    string decodeString(string s) {
        src = s;
        ptr = 0;
        return getString();
    }
    
    string getString() {
        if (ptr == src.size() || src[ptr] == ']') {
            return "";
        }

        string ret;
        if(isdigit(src[ptr])) {
            // String -> Digits [ String ] String
            int repeat = getDigits(); 
            ++ptr; // [
            string str = getString(); 
            ++ptr; // ]
            while(repeat--) 
                ret += str; 
        } else if(isalpha(src[ptr])) {
            // String -> Char String
            ret = string(1, src[ptr]);
            ++ptr;
        }
        
        return ret + getString();
    }

    int getDigits() {
        int ret = 0;
        while (ptr < src.size() && isdigit(src[ptr])) {
            ret = ret * 10 + src[ptr] - '0';
            ptr++;
        }
        return ret;
    }
};
