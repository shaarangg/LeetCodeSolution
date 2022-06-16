class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> left(n);
        vector<int> right(n);
        left[0]=height[0];
        right[n-1]=height[n-1];
        int l=left[0],r=right[n-1];
        for(int i=1; i<n; i++){
            left[i] = max(l,height[i]);
            l = left[i];
        } 
        for(int i=n-2; i>=0; i--){
            right[i]=max(r,height[i]);
            r = right[i];
        } 
        int ans=0;
        for(int i=1; i<n-1; i++){
            ans+=min(left[i],right[i]) - height[i];
        }
        return ans;
    }
};