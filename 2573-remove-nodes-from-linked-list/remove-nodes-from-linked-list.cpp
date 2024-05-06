/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode *reverse(ListNode *head){
        ListNode *curr = head;
        ListNode *next = NULL;
        ListNode *prev = NULL;
        while(curr!=NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
        return head;
    }

    ListNode* removeNodes(ListNode* head) {
        stack<ListNode*> st;
        ListNode *temp = head;
        while(temp!=NULL){

            while(!st.empty() && temp->val > st.top()->val){
                    st.pop();
            }
            st.push(temp);
            temp=temp->next;

        }

        ListNode *newHead = NULL;
       ListNode *tail = NULL;
        while(!st.empty()){
            if(newHead == NULL){
              newHead = st.top();
              tail = newHead;
            }
            tail->next = st.top();;
            tail = tail->next;
            st.pop();
            
        }
        tail->next = NULL;
        ListNode* ans = reverse(newHead);
        return ans;

    }
};