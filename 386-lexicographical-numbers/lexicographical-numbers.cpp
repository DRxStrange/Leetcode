class Solution {
public:
    // Using DFS
    // we have to select num 1 to 9  call for dfs and 
    // than selected num*10 and check it num greater than target value return 
    void dfs(int currNum, int n, vector<int> &ans){
        if(currNum > n){
          return ;
        }
        ans.push_back(currNum);

        for(int i =0;i<=9;i++){
            dfs(currNum*10+i,n,ans);
        }
    }

    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        for(int i =1;i<=9;i++){
             dfs(i,n,ans);
        }
        return ans;
    }
};