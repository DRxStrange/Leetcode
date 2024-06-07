class Solution {
public:
bool check(int num){
    if(num > INT_MAX /10 || num < INT_MIN/10) return true;
    return false;
}
    bool isPalindrome(int x) {
        if(x < 0) return false;
         int num = x;
         int reverseNumber = 0;
         while(x!=0){
            int digit = x%10;
            if(check(reverseNumber)) return false;
            reverseNumber = reverseNumber * 10 + digit;
            x = x/10;
         }
         if(reverseNumber == num) return true;
         return false;
    }
};