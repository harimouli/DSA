//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:

    // Function to return length of longest subsequence of consecutive integers.
    int longestConsecutive(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int longSubseq = 1;
        int count = 1;
        for(int i = 0; i<arr.size()-1; i++){
            if(arr[i] + 1 == arr[i+1] || arr[i] == arr[i+1]){
                if(arr[i] + 1 == arr[i+1]){
                    count += 1;
                }
                else{
                    count += 0;
                }
            }
            else{
                count = 1;
            }
            longSubseq = max(count, longSubseq);
            
        }
        return longSubseq;
     
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.longestConsecutive(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends