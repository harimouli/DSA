class Solution {
public:

    string getNewWord(string word){
        string newWord = "";
        for(int i = 0; i<word.size(); i++){
            if(word[i] != 'z') newWord += word[i]+ 1;
            else  newWord+= 'a';
        }
        return newWord;
    }
    char kthCharacter(int k) {
        


        string word = "a";

        while(word.size() < k){
            word += getNewWord(word);
        }

        return word[k-1];
    }
};