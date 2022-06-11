class Solution {
public:
    int res=0;
    void merge(vector<int> &nums, int l, int m, int r){
        int n1 = m-l+1;
        int n2 = r-m;
        vector<int> left(n1);
        vector<int> right(n2);
        for(int i=0; i<n1; i++) left[i]=nums[l+i];
        for(int i=0; i<n2; i++) right[i]=nums[m+i+1];
        int i=0,j=0,k=l;
        while(j<n2 && i<n1){
            if(left[i]> 2L*right[j]){
                res+=n1-i;
                j++;
            } 
            else{
                i++;
            }
        }
        i=0,j=0;
        while(i<n1 && j<n2){
            if(left[i]<=right[j]){
                nums[k++] = left[i++];
            }
            else{
                nums[k++] = right[j++];
            }
        }
        while(i<n1) nums[k++]=left[i++];
        while(j<n2) nums[k++]=right[j++];
    }
    void mergeSort(vector<int> &nums, int l, int r){
        if(l>=r) return;
        int m = (l+r)/2;
        mergeSort(nums,l,m);
        mergeSort(nums,m+1,r);
        merge(nums,l,m,r);
    }
    int reversePairs(vector<int>& nums) {
        mergeSort(nums, 0,nums.size()-1);
        // for(auto i: nums) cout<<i<<" ";
        return res;
    }
};