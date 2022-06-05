class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> dict;
        dict[0]=0;
        dict[1]=0;
        dict[2]=0;
        for(int i=0; i<n; i++){
            dict[nums[i]]+=1;
        }
        int i=0;
        while(dict[0]){
            nums[i]=0;
            dict[0]--;
            i++;
        }
        while(dict[1]){
            nums[i]=1;
            dict[1]--;
            i++;
        }
        while(dict[2]){
            nums[i]=2;
            dict[2]--;
            i++;
        }
    }
};