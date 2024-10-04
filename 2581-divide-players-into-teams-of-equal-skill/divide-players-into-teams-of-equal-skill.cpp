class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();
        // int sum = 0;
        // Bruteforce
        //  sort(skill.begin(),skill.end());
        //  int target = skill[0]+skill[n-1];
         
        //  int left=0, right = n-1;
        //  long long ans = 0;
        //  for(int i=0;i<n/2;i++){
        //      int currSum = skill[i] + skill[n-i-1];
        //      if(currSum != target) return -1;
        //      ans += (long)skill[i] * (long)skill[n-i-1];
        //  }
        long long sum = 0, ans=0;
        vector<int> mp(1001,0);
        for(int i=0;i<n;i++){
            sum += skill[i];
             mp[skill[i]]++;
        }
        if((sum % (n/2)) != 0) return -1;
        int target = (sum / (n/2));
        for(auto it : skill){
            int rem = target - it;
            if(mp[rem] == 0) return -1;
            
            ans += (long long )it * (long long)rem;
            mp[rem]--;
        }
         return ans/2;
    }
};