class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)return false;
        long long rev = 0;
        long long front = x;
        while(x!=0){
          long long rem = x%10;
            x = x/10;
            rev = rev*10 + rem;
        }
         cout<<rev;
        if(front == rev) return true;
        return false;
    }
};