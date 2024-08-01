class Solution {
public:

    int countSeniors(vector<string>& details) {
         int size = details.size();
         int count = 0;
         for(int i=0;i<size;i++){
            int age = stoi(details[i].substr(11,2)); 
            cout<<age<<endl;
            if(age > 60) count++;
         }
         return count;
    }
};