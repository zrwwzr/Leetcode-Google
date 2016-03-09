/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    struct cmp{
        bool operator ()(ListNode* a, ListNode* b){
            return a->val > b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
        for(int i = 0; i < lists.size(); ++i)
            if(lists[i])
                pq.push(lists[i]);
        ListNode* dummy = new ListNode(0), *cur = dummy;
        while(!pq.empty()){
            cur->next = pq.top(), pq.pop();
            cur = cur->next;
            if(cur->next)
            pq.push(cur->next);
        }
        return dummy->next;
    }
};
