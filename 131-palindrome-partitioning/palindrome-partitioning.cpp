class Solution {
public:
   bool isPalindrome(string &temp){
    int l = 0;
    int r = temp.size()-1;
    while(l<=r){
           if(temp[l]!=temp[r]){
            return false;
           }
           l++;
           r--;
       }
       return true;
   }
    void solve(int idx, string &s, vector<string> &ans, vector<vector<string>> &res){
        if(idx == s.size()){
            res.push_back(ans);
            return;
        }
           for(int i = idx;i<s.size();i++){
                string temp = s.substr(idx,i-idx+1);
                if(isPalindrome(temp)){
                    ans.push_back(temp);
                     solve(i+1,s,ans,res);
                     ans.pop_back();
                }
               
           }
           
    }
    vector<vector<string>> partition(string s) {
        vector<string> ans;
        vector<vector<string>> res;
        solve(0,s,ans,res);
        return res;
    }
};