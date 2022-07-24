class Solution {
public:
    string multiply(string num1, string num2) {
        int n1 = num1.length();
        int n2 = num2.length();
        if(num1=="0" || num2=="0") return "0";
        vector<int> ans(n1+n2,0);
        for(int i=n1-1; i>=0; i--){
            for(int j=n2-1; j>=0; j--){
                int temp = (num1[i]-'0')*(num2[j]-'0');
                ans[i+j+1]+=temp%10;
                ans[i+j]+=temp/10;
            }
        }
        string a="";
        for(int i=n2+n1-1; i>=0; i--){
            if(ans[i]>=10){
                ans[i-1]+=ans[i]/10;
                ans[i]=ans[i]%10;
            }
            a=to_string(ans[i]) + a;
        }
        int idx=0;
        while(a[idx]=='0'){
            idx++;
        }
        return a.substr(idx,n1+n2);
    }
};