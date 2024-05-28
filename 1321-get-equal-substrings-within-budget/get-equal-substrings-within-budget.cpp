class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
      
       int n = s.size();
       int currSum=0;
       int i=0,j=0;
       int maxi = 0;
      while(j<n){
           currSum += abs(s[j]-t[j]);
            while(currSum > maxCost){
                currSum -= abs(s[i]-t[i]);
               i++;
            }
          maxi = max(maxi, j-i+1);
          j++;
      }
         return maxi;
    }
};