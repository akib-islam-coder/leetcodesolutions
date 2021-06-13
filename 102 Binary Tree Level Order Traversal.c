/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#define QUEUE_SIZE 2000

typedef struct
{
    struct TreeNode * queue_arr[QUEUE_SIZE];
    int level_arr[QUEUE_SIZE];
    int rear;
    int front;
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
    if(tmp_queue->rear == QUEUE_SIZE-1)
        return 1;
    else 
        return 0;
}

void enqueue(Queue * tmp_queue, struct TreeNode * element, int level)
{
    if(isQueueFull(tmp_queue))
        return;
    
    tmp_queue->queue_arr[++(tmp_queue->rear)] = element;
    tmp_queue->level_arr[tmp_queue->rear] = level;
    
    if(tmp_queue->front == -1)
    {
        tmp_queue->front = 0;
    }
    return;
}

struct TreeNode * dequeue(Queue * tmp_queue, int * level)
{
    if(isQueueEmpty(tmp_queue))
        return NULL;
    
    struct TreeNode * ret_val = tmp_queue->queue_arr[tmp_queue->front];
    *level = tmp_queue->level_arr[tmp_queue->front];
    
    if(tmp_queue->front == tmp_queue->rear)
    {
        tmp_queue->front = -1;
        tmp_queue->rear = -1;
    }
    else
    {
        ++(tmp_queue->front);
    }
    return ret_val;
}

int height(struct TreeNode * root)
{
    if(root == NULL)
        return 0;
    
    int left_ht = height(root->left);
    int right_ht = height(root->right);
    
    if(left_ht >= right_ht)
        return (left_ht + 1);
    else
        return (right_ht + 1);
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes)
{   
    Queue tmp_queue;
    tmp_queue.rear = -1;
    tmp_queue.front = -1;
   
    
    int ht_of_tree = height(root);
    
    int ** ret_ptr = (int **)malloc(sizeof(int *) * ht_of_tree);
    int ret_ptr_index = -1;
    
    *returnColumnSizes = (int *)malloc(sizeof(int) * ht_of_tree);
    int index  = 0;
    
    *returnSize = ht_of_tree;
 
    if(root == NULL)
    {
        *returnSize = 0;
        return ret_ptr;
    }
    
    struct TreeNode * tmp_ptr = root;
    int prev_level = 0;
    int current_level = 1;
    
    int * arr = NULL;
    int arr_index = 0;
    
    enqueue(&tmp_queue, tmp_ptr, current_level);
    
    while(!isQueueEmpty(&tmp_queue))
    {
        tmp_ptr = dequeue(&tmp_queue, &current_level);
        
        if(current_level != prev_level)
        {    
            if(tmp_ptr != root)
            { 
                *(*returnColumnSizes + index) = arr_index;
                index++;          
            }

            arr_index = 0;
            
            arr = (int *)malloc(sizeof(int) * 1);
            arr[arr_index++] = tmp_ptr->val;
            
            ret_ptr[++ret_ptr_index] = arr;
        }
        else if(current_level == prev_level)
        {
            
            arr = realloc(arr, sizeof(int) * (arr_index+1));
            arr[arr_index++] = tmp_ptr->val;
            ret_ptr[ret_ptr_index] = arr;

        }
        
        if(tmp_ptr->left != NULL)
        {
            enqueue(&tmp_queue, tmp_ptr->left, current_level+1);
        }
        
        if(tmp_ptr->right != NULL)
        {
            enqueue(&tmp_queue, tmp_ptr->right, current_level+1);
        }    
        prev_level = current_level;            
    }

    *(*returnColumnSizes + index) = arr_index;
    
    return ret_ptr;
}