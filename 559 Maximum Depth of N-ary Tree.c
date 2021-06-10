/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     int numChildren;
 *     struct Node** children;
 * };
 */

int maxDepth(struct Node* root) 
{
    static int depth = 0;
    
    if(root == NULL)
    {
        return 0;
    }
    
    if(root->numChildren == 0)
    {
        return 1;
    }
    
    int * count = (int *)malloc(sizeof(int) * root->numChildren);
    int count_index = 0;
    
    int i=0;
    for(i=0; i<root->numChildren; i++)
    {
        count[count_index++] = maxDepth(root->children[i]);
    }
    
    int max = INT_MIN;
    i=0;
    for(i=0; i<root->numChildren; i++)
    {
        if(count[i] >= max)
        {
            max = count[i];
        }
    }
    free(count);
    return max+1;
    
}