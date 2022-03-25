class Solution {
public:
    string reverseWords(string s) {
        string::iterator ptr;
        string::iterator ls = s.begin();
        for(ptr = s.begin(); ptr<s.end(); ptr++){
            if(*ptr==' '){
                reverse(ls,ptr);
                ls = ptr+1;
            }
        }
        reverse(ls,s.end());
        return s;
    }
};