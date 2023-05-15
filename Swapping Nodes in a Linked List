class Solution {
public:
    int x = 0;
    ListNode* q;
    void solve(ListNode* p, int &k){
        if(p==NULL){
            x = -1;
            return;
        }
        solve(p->next,k);
        k--;
        if(k==0){
            swap(p->val,q->val);
            return;
        }
        q = q->next;

    }
    ListNode* swapNodes(ListNode* head, int k) {
        q = head;
        solve(head,k);
        return head;
    }
};
