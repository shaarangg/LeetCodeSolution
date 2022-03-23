class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int l = cost.size();
        if(l<=1) return 0;
        int arr[l+1];
        arr[0] = 0;
        arr[1] = 0;
        for(int i=2; i<=l; i++){
            arr[i] = min(arr[i-2]+cost[i-2],arr[i-1]+cost[i-1]);
        }
        return arr[l];
    }
};