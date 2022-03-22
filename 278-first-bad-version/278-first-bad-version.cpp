// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        if(n==1) return n;
        int l = 1;
        int h = n;
        int last_idx=-1;
        while(l<=h){
            int m = l + (h-l)/2;
            if(isBadVersion(m)){
                last_idx = m;
                h = m-1;
            }
            else{
                l = m+1;
            }
        }
        return last_idx;
    }
};