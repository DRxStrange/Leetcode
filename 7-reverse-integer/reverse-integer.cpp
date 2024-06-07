class Solution {
public:
    bool check(int num){
        if(num > INT_MAX / 10 || num < INT_MIN / 10) return true;
        return false;
    }
    int reverse(int x) {
        int reverseNumber = 0;
        while(x!=0){
            int digit = x%10;
            if(check(reverseNumber)){
                return 0;
            }
            reverseNumber = reverseNumber*10 + digit;
            x = x/10;
        }
        return reverseNumber;
    }
};