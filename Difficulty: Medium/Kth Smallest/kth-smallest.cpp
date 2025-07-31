// User function template for C++

class Solution {
  public:
    // arr : given array
    // k : find kth smallest element and return using this function
    
    int partition(int left, int right, int pivotIndex, vector<int> &arr){
        int pivot = arr[pivotIndex];
        swap(arr[left], arr[pivotIndex]);
        int ind = left +1 ;
        for(int i = left + 1; i <=right; i++){
            if(arr[i] < pivot) {
                swap(arr[ind], arr[i]);
                ind++;
            }
        }
        swap(arr[left], arr[ind-1]);
        return ind-1;
    }
    int randomIndex(int &left, int &right){
        int len = right - left + 1;
        
        return (rand() % len) + left;
    }
    int kthSmallest(vector<int> &arr, int k) {
        int n= arr.size();
        int left = 0;
        int right = arr.size() - 1;
        
        while(true) {
            int pivotIndex = randomIndex(left, right);
            pivotIndex = partition(left, right, pivotIndex, arr);
            
            if(k - 1 == pivotIndex) return arr[pivotIndex];
            else if(k - 1 < pivotIndex) {
                right = pivotIndex - 1;
            }
            else{
                left = pivotIndex + 1;
            }
        }
        return -1;
    }
};