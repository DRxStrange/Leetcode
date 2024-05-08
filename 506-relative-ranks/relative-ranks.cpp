class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
          int n = score.size();
          vector<int> temp = score;
          sort(temp.begin(),temp.end(),greater<int>());
          int num=1;
          unordered_map<int,int> mp;
          for(auto it : temp){
              mp[it] = num;
              num++;
          }
          vector<string> ans;
         for(auto it: score){
            if(mp[it] == 1) ans.push_back("Gold Medal");
            else if(mp[it] == 2) ans.push_back("Silver Medal");
            else if(mp[it] == 3) ans.push_back("Bronze Medal");
            else {
                string s = to_string(mp[it]);
                ans.push_back(s);
                }
         }
           
           return ans;
    }
};