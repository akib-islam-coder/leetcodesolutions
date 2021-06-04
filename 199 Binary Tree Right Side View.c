/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#define MAX_NODES 100

typedef struct queue
{
    struct TreeNode * arr[MAX_NODES];
    int arr_level[MAX_NODES];
    int front;
    int rear;
}Queue;

int isQueueEmpty(Queue * level_queue)
{
    if(level_queue->front == -1)
        return 1;
    else 
        return 0;
}

int isQueueFull(Queue * level_queue)
{
    if(level_queue->rear == MAX_NODES-1)
        return 1;
    else 
        return 0;
}

void enqueue(Queue * level_queue, struct TreeNode * element, int level)
{
    if(isQueueFull(level_queue))
        return;
    
    level_queue->arr[++(level_queue->rear)] = element;
    level_queue->arr_level[level_queue->rear] = level;
    
    if(level_queue->front == -1)
    {
        level_queue->front = 0;
    }
    return;
}

struct TreeNode * dequeue(Queue * level_queue, int * level)
{
    struct TreeNode * ret_element = NULL;
    
    if(isQueueEmpty(level_queue))
        return ret_element;
    
    ret_element = level_queue->arr[(level_queue->front)];
    *level = level_queue->arr_level[level_queue->front];
    
    if(level_queue->front == level_queue->rear)
    {
        level_queue->front = -1;
        level_queue->rear = -1;
    }
    else
    {
        level_queue->front++;
    }
    return ret_element;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* rightSideView(struct TreeNode* root, int* returnSize)
{
    int * ret_arr = (int *)malloc(sizeof(int)*MAX_NODES);
    int ret_arr_index = 0;
    
    if(root == NULL)
    {
        *returnSize = ret_arr_index;
        return ret_arr;
    }       
    
    struct TreeNode * trav_ptr = root;
    struct TreeNode * prev_level_ptr = NULL;
    int current_level = 1;
    int prev_level = 1;

    
    Queue level_queue;
    level_queue.front = -1;
    level_queue.rear = -1;
    memset(&level_queue.arr, NULL, sizeof(level_queue.arr));
    memset(&level_queue.arr_level, 0, sizeof(level_queue.arr_level));
    
    //Level Order Traversal
    enqueue(&level_queue, trav_ptr, current_level);
    
    while(!isQueueEmpty(&level_queue))
    {
        trav_ptr = dequeue(&level_queue, &current_level);

        
        if(current_level != prev_level)
        {
            ret_arr[ret_arr_index++] = prev_level_ptr->val;
            prev_level = current_level;
            prev_level_ptr = trav_ptr;       
        }
        else if(current_level == prev_level)
        {
            prev_level_ptr = trav_ptr;
        }       
        
        if(trav_ptr->left)
        {
            enqueue(&level_queue, trav_ptr->left, current_level+1);
        }
        
        if(trav_ptr->right)
        {
            enqueue(&level_queue, trav_ptr->right, current_level+1);
        }       
        
    }
    ret_arr[ret_arr_index++] = prev_level_ptr->val;
    *returnSize = ret_arr_index;
    return ret_arr;
    
    
    
}