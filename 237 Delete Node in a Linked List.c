/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void deleteNode(struct ListNode* node) 
{
    //Swap the values
    struct ListNode * del_node = node;
    
    int tmp_val = del_node->val;
    del_node->val = del_node->next->val;
    del_node->next->val = tmp_val;
    
    struct ListNode * new_del_node = del_node->next;
    del_node->next = new_del_node->next;
    new_del_node->next = NULL;
    free(new_del_node);
}