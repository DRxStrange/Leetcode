class Solution {
public:
    string shortestCompletingWord(string s, vector<string>& w) {
        int n = s.length();
        unordered_map<char,int> sm;
        // sort(w.begin(),w.end());
        string temp = "";
        for(int i=0;i<n;i++){
            char c = tolower(s[i]);
            if(c >='a' && c <='z'){
            sm[c]++;
            }
        }
         int count =INT_MAX;
         string ans = "";
        for(auto word: w){
           
             int m = word.size();
             int c = INT_MAX;
             c =  min(c,m);
            
            unordered_map<char,int> mp = sm;
             for(int i = 0;i<m;i++){
                if(mp[word[i]]>0){
                mp[word[i]]--;
                }
                
            }
            bool flag = 1;
            for(auto it:mp){
                if(it.second!=0){
                    flag =false;
                }
            }
            if(flag==1 && count > c) {
                count = c;
                ans = word;
            }
            mp.clear();
        }
        
        return ans;
    }
};