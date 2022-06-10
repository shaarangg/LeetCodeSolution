class Solution {
public:
    double helper(double x, int n){
        if(n==0) return 1;
        double temp = helper(x,n/2);
        if(n%2==0) return temp*temp;
        else return x*temp*temp;
    }
    double myPow(double x, int n) {
        double res = helper(x, abs(n));
        if(n>=0) return res;
        else return res=double(1)/res;
    }
};