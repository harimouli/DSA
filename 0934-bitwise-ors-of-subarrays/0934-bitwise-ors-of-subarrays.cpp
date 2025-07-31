class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
                unordered_set<int> result;
                set<int> prev;

                for (int num : arr) {
                    set<int> curr;
                    curr.insert(num);

                    for (int val : prev) {
                        curr.insert(val | num);
                    }

                    for (int val : curr) {
                        result.insert(val);
                    }

                    prev = curr;
    }

    return result.size();
    }
};