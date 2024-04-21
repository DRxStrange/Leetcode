class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_set<char> low;
        unordered_set<char> up;
        int n = word.size();
        for(int i=0;i<n;i++){
            if(word[i]>='a' && word[i]<='z'){
                low.insert(word[i]);
            }
            else if(word[i]>='A' && word[i]<='Z'){
                char c= tolower(word[i]);
                 up.insert(c);
            }
        }
        int count= 0;
        for(auto it : low){
             if(up.find(it)!=up.end()){
                count++;
             }
        }
        return count;
    }
};