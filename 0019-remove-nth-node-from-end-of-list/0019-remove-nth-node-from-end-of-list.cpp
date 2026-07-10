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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp=head;
        ListNode* copy =head;
        int  count =0;
        while (temp !=NULL){
         count ++;
         temp =temp->next;
        }

        for (int i=1; i<(count-n); i++){
            copy = copy ->next;
        }
        if(count ==1 && n==3){
            return NULL;
        }
        if(count == n){
            return copy->next;
        }

        copy-> next = copy -> next-> next;

        return head;
        
    }
};