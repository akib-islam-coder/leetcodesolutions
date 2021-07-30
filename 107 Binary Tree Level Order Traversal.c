/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#define MAX_NODES 2001
typedef struct
{
    struct TreeNode * queue[MAX_NODES];
    int level_queue[MAX_NODES];
    int front;
    int rear;
}Queue;

int isQueueEmpty(Queue * tmp_queue)
{
    if(tmp_queue->front == -1)
        return 1;
    else
        return 0;
}

int isQueueFull(Queue * tmp_queue)
{
    if(tmp_queue->rear == MAX_NODES - 1)
        return 1;
    else
        return 0;
}

void enqueue(Queue * tmp_queue, struct TreeNode * element, int level)
{
    if(isQueueFull(tmp_queue))
        return;
    
    tmp_queue->queue[++(tmp_queue->rear)] = element;
    tmp_queue->level_queue[tmp_queue->rear] = level;
    if(tmp_queue->front == -1)
        tmp_queue->front = 0;
}

struct TreeNode * dequeue(Queue * tmp_queue, int * level)
{
    if(isQueueEmpty(tmp_queue))
        return NULL;
    
    struct TreeNode * ret_element = tmp_queue->queue[tmp_queue->front];
    *level = tmp_queue->level_queue[tmp_queue->front];
    if(tmp_queue->front == tmp_queue->rear)
    {
        tmp_queue->front = -1;
        tmp_queue->rear = -1;
    }
    else
    {
        ++(tmp_queue->front);
    }
    return ret_element;
}

int find_height(struct TreeNode * root)
{
    if(root == NULL)
        return 0;
    
    int left = find_height(root->left);
    int right = find_height(root->right);
    
    if(left >= right)
        return left+1;
    else
        return right+1;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** levelOrderBottom(struct TreeNode* root, int* returnSize, int** returnColumnSizes)
{   
    
    if(root == NULL)
    {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }
    
    int height = find_height(root);
    
    int ** tmp_arr = (int **)malloc(sizeof(int *) * height);
    int tmp_arr_index = 0;
    
    int * col_arr = (int *)malloc(sizeof(int) * height);
    int col_arr_index = 0;
    
    Queue tmp_queue;
    tmp_queue.front = -1;
    tmp_queue.rear = -1;
    
    int cur_lev = 1;
    int prev_lev = 0;
    
    struct TreeNode * trav_ptr = root;
    enqueue(&tmp_queue, trav_ptr, cur_lev);
    
    int cur_level_index = 0;
    int * arr = NULL;
    
    while(!isQueueEmpty(&tmp_queue))
    {
        trav_ptr = dequeue(&tmp_queue, &cur_lev);
        
        if(cur_lev != prev_lev)
        {
            cur_level_index = 0;
            cur_level_index++;
            arr = (int *)malloc(sizeof(int) * cur_level_index);
            arr[0] = trav_ptr->val;
            tmp_arr[tmp_arr_index++] = arr;
            prev_lev = cur_lev;
            
            //Col arr
            col_arr[col_arr_index++] = cur_level_index;
        }
        else
        {
            cur_level_index++;
            arr = (int *)realloc(arr, sizeof(int) * cur_level_index);
            arr[cur_level_index - 1] = trav_ptr->val;
            tmp_arr[tmp_arr_index - 1] = arr;
            prev_lev = cur_lev;
            
            //Col arr
            col_arr[col_arr_index - 1] = cur_level_index;
        }
        
        if(trav_ptr->left)
        {
            enqueue(&tmp_queue, trav_ptr->left, cur_lev+1);
        }
        
        if(trav_ptr->right)
        {
            enqueue(&tmp_queue, trav_ptr->right, cur_lev+1);
        }
    }
    
    int ** ret_arr = (int **)malloc(sizeof(int *) * height);
    int ret_arr_index = 0;
    
    int i=0;
    for(i=tmp_arr_index-1; i>=0; i--)
    {
        ret_arr[ret_arr_index++] = tmp_arr[i];
    }
    free(tmp_arr);
    
    int * new_col_arr = (int *)malloc(sizeof(int) * height);
    int new_col_arr_index = 0;
    
    for(i=col_arr_index-1; i>=0; i--)
    {
        new_col_arr[new_col_arr_index++] = col_arr[i];
    }
    free(col_arr);
    
    *returnColumnSizes = new_col_arr;
    *returnSize = ret_arr_index;
    

    return ret_arr;
    
}