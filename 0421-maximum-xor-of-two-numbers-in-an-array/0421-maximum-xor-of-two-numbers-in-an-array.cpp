
class Node {
    public: 

    Node* links[2] = {nullptr};


    void put(int bit , Node* node) {
        links[bit] = node;
    }   

     bool isContainsBit(int bit) {
        return links[bit] != nullptr;
     }

     Node* get(int bit){
        return  links[bit];
     }
};


class Trie {
    private: 
         Node* root;
    
    public:
        Trie() {
            root = new Node();
        }

        void insert(int num) {
            Node* node = root;
            

            for(int i = 31; i>= 0; i--){

                int bit = (num >> i) & 1;

                if(!node->isContainsBit(bit)){
                    node->put(bit, new Node());
                }
                node = node->get(bit);
            }
        }

      

        int getMax(int num){
            Node* node = root;
            int maxNum =0;
            for(int i = 31; i>=0; i--){
                int bit = (num >> i) & 1;

                if(node->isContainsBit(1 - bit)){
                    maxNum |= (1 << i);
                    node = node->get(1-bit);
                }
                else{
                    node = node->get(bit);
                }
            }
            return  maxNum;
        }


};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;

        int maxi  = 0;


        for(int num : nums){
            trie.insert(num);
        }


        for(int i = 0; i<nums.size(); i++) {
            maxi = max(maxi, trie.getMax(nums[i]));
        }

        return maxi;
    }
};