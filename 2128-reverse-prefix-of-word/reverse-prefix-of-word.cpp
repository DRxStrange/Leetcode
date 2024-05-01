class Solution {
public:
    string reversePrefix(string word, char ch) {
        int n = word.size();
        int ind= -1;
        for(int i=0;i<n;i++){
            if(ch==word[i]){
                ind = i;
                break;
            }
        }
        reverse(word.begin(),word.begin()+ind+1);
        return word;
    }
};