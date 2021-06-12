/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

typedef struct node
{
    int val;
    struct node * next;
}Node;

Node * hash_table[100] = {NULL};

int hash_index(int num)
{
    int ret_index = 0;
    if(num < 0)
    {
        num = (-1 * num);
        ret_index = (num % 100);
    }
    else
    {
        ret_index = (num % 100);
    }
    return ret_index;
}

bool hashtable_search(int element)
{
    bool search_success = false;
    
    int index = hash_index(element);
    if(hash_table[index] == NULL)
    {
        search_success = false;
    }
    else
    {
        Node * trav_ptr = hash_table[index];
        
        while(trav_ptr!=NULL)
        {
            if(trav_ptr->val == element)
            {
                search_success = true;
                break;
            }
            trav_ptr = trav_ptr->next;
        }
    }
    return search_success;
}

void hashtable_insert(int element)
{

    int index = hash_index(element);
    Node * new_node = (Node *)malloc(sizeof(Node));
    new_node->val = element;
    new_node->next = NULL;
    
    Node * trav_ptr = hash_table[index];
    
    if(trav_ptr == NULL)
    {
        hash_table[index] = new_node;
    }
    else
    {
        while(trav_ptr->next != NULL)
        {
            trav_ptr = trav_ptr->next;
        }
        
        trav_ptr->next = new_node;
    }
}

void preorder(struct TreeNode * root, int k, bool * target_found)
{
    if(root == NULL)
        return;
    
    int diff = k - root->val;
    
    bool element_found = hashtable_search(diff);
    if(element_found)
    {
        *target_found = true;
        return;
    }
    else
    {
        //Insert this element in the hashtable
        hashtable_insert(root->val);
        
        preorder(root->left, k, target_found);
        preorder(root->right, k, target_found);
    }
    return;
    
    
}

bool findTarget(struct TreeNode* root, int k)
{
    memset(hash_table, NULL, sizeof(hash_table));
    bool target_found = false;
    preorder(root, k, &target_found);
    return target_found;
}