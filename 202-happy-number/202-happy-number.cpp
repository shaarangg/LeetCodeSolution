class Solution {
public:
    int calc(int n){
        int s=0;
        while(n!=0){
            int t = n%10;
            s+=t*t;
            n=n/10;
        }
        return s;
    }
    bool isHappy(int n) {
        int slow=n;
        int fast=n;
        do{
            slow=calc(slow);
            fast=calc(fast);
            fast=calc(fast);
        }while(slow!=fast);
        if(slow==1) return 1;
        return 0;
    }
};