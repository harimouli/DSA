class Solution {
  public:
    vector<int> printKClosest(vector<int> arr, int k, int x) {
         vector<pair<int, int>> diffList;

        for (int num : arr) {
            if (num == x) continue;
            diffList.push_back({abs(num - x), num});
        }

        // Sort by distance, then by value descending
        sort(diffList.begin(), diffList.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            if (a.first == b.first) return a.second > b.second;
            return a.first < b.first;
        });

        vector<int> result;
        for (int i = 0; i < k; ++i) {
            result.push_back(diffList[i].second);
        }

        return result;
        
    }
};