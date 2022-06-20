class Solution {
public:
    vector<vector<string>> ans;
    bool validate(string s){
        bool flag=true;
        int n = s.length(), i=0;
        while(i<n){
            if(s[i]!=s[n-i-1]){
                flag=false;
                break;
            }
            i++;
        }
        return flag;
    }
    void util(string s, int N, vector<string> arr){
        if(N==0){
            reverse(arr.begin(),arr.end());
            ans.push_back(arr);
            return;
        }
        for(int i = N-1; i>=0; i--){
            string x = s.substr(i,N-i);
            if(validate(x)){
                vector<string> temp = arr;
                temp.push_back(x);
                util(s,i,temp);
            }
        }
    }
    vector<vector<string>> partition(string s) {
        util(s,s.size(),{});
        return ans;
    }
};