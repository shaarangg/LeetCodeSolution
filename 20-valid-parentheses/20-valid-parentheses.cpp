class Solution {
public:
    bool isValid(string s) {
        int l = s.length();
        stack<int> st;
        for(int i=0; i<l; i++){
            if(!st.empty() && ((s[i]==')' && st.top()=='(') || (s[i]=='}' && st.top()=='{') || (s[i]==']' && st.top()=='['))) st.pop();
            else if(s[i]=='(' || s[i]=='{' || s[i]=='[') st.push(s[i]);
            else return false;
        }
        if(st.empty()) return true;
        return false;
    }
};