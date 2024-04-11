class Solution {
public:
    string removeKdigits(string num, int k) {
        // left se increasing order toh push karo nhi toh pop karo

        int n = num.size();
        stack<char> myStack;
        for(char c: num){

            while(!myStack.empty() && k>0 && myStack.top() > c){
                myStack.pop();   
                k--;
            }

            if(!myStack.empty() || c!='0'){
                myStack.push(c);
            }

        }

        while(!myStack.empty() && k--){
            myStack.pop();
        }

        if(myStack.empty()) return "0";

        while(!myStack.empty()){
            num[n-1] = myStack.top();
            myStack.pop();
            n--;
        }
       return num.substr(n);
    }
};