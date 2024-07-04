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
    ListNode* mergeNodes(ListNode* head) {
        head=head->next;
        ListNode* temp=head;
        ListNode* prev;
        int count=0;
        int sum=0;
        while(temp->next!=NULL){
            if(temp->val!=0){
                sum+=temp->val;
                temp=temp->next;
            }
            if(temp->val==0 && temp->next!=NULL){
                temp->val=sum;
                sum=0;
                if(count==0){
                    head=temp;
                    prev=temp;
                    count++;
                }
                else{
                    prev->next=temp;
                    prev=temp;
                }
                temp=temp->next;
            }
        }
        temp->val=sum;
        if(!count){
            head=temp;
            return head;
        }
        prev->next=temp;
        return head;
    }
};
