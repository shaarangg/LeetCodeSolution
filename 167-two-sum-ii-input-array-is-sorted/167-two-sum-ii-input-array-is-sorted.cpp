class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i=0,j=numbers.size()-1;
        vector<int> ans(2);
        while(i<j){
            if(numbers[j]+numbers[i]==target){
                ans[0]=i+1;
                ans[1]=j+1;
                break;
            }
            else if(numbers[j]+numbers[i] > target){
                j--;
            }
            else i++;
        }
        return ans;
    }
};