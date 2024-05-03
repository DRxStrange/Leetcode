class Solution {
public: 
    vector<string> solve(string version1){
          stringstream ss(version1);
          string v = "";
          vector<string> ans;
          while(getline(ss, v,'.')){
              ans.push_back(v);
          }
          return ans;
    }
    int compareVersion(string version1, string version2) {
             vector<string> s1 = solve(version1);
             vector<string> s2 = solve(version2);
             int m = s1.size();
             int n = s2.size();
             int i =0;
             while(i < m || i < n){
                int a = (i<m) ? stoi(s1[i]) : 0; 
                int b = (i<n) ? stoi(s2[i]) : 0;
                if(a > b){
                    return 1;
                }else if(a < b){
                    return -1;
                }else{
                    i++;
                }
             }
           return 0;
    }
};