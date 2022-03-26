class Solution {
public:
    bool binarySearch(vector<int> &num, int target){
        int l=0;
        int h = num.size();
        while(l<=h){
            int mid = l + (h-l)/2;
            if(num[mid]==target) return true;
            else if(target > num[mid]) l = mid+1;
            else h=mid-1;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int c = matrix[0].size();
        for(int i=0; i<matrix.size(); i++){
            if(target<=matrix[i][c-1]) return binarySearch(matrix[i],target);
        }
        return false;
    }
};