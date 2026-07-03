class Solution {
private:
    bool checkvalid (char c) {
        if ( (c >= 'a' && c<= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c<= '9') ) {
            return true;
        }
        else {
            return false;
        }
    }

    char lowercase (char c) {

        if (c >= 'A' && c <= 'Z') {
            return c - 'A' + 'a';
        }
        return c;
    }

    bool palindrome (string s) {

        int st = 0;
        int en = s.length() - 1;

        while (st<=en) {
            if (s[st] == s[en]) {
                st++;
                en--;
            }
            else {
                return false;
            }
        }
        return true;
    }

public:
    bool isPalindrome(string s) {
        
        string temp = "";

        for (int i=0; i<s.length(); i++) {
            if ( checkvalid(s[i]) ) {
                temp.push_back(s[i]);
            }
        }

        for (int i=0; i<temp.length(); i++) {
            temp[i] = lowercase(temp[i]);
        }

        return palindrome(temp);
    }
};
