/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#define MAX_NODES 10000

typedef struct
{
    struct TreeNode * queue_arr[MAX_NODES];
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
    
    tmp_queue->queue_arr[++(tmp_queue->rear)] = element;
    tmp_queue->level_queue[tmp_queue->rear] = level;
    
    if(tmp_queue->front == -1)
        tmp_queue->front = 0;
    
    return;
}

struct TreeNode * dequeue(Queue * tmp_queue, int * level)
{
    if(isQueueEmpty(tmp_queue))
        return NULL;
    
    struct TreeNode * ret_node = tmp_queue->queue_arr[tmp_queue->front];
    *level = tmp_queue->level_queue[tmp_queue->front];
    
    if(tmp_queue->front == tmp_queue->rear)
    {
        tmp_queue->front = -1;
        tmp_queue->rear = -1;
    }
    else
    {
        (tmp_queue->front)++;
    }
    return ret_node;
}

int find_height(struct TreeNode * root)
{
    if(root == NULL)
        return 0;
    
    int left = find_height(root->left);
    int right = find_height(root->right);
    
    if(left >= right)
        return (left + 1);
    else
        return (right + 1);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* largestValues(struct TreeNode* root, int* returnSize)
{
    
    if(root == NULL)
    {
        *returnSize = 0;
        return NULL;
    }
    
    Queue tmp_queue;
    tmp_queue.front = -1;
    tmp_queue.rear  = -1;
    
    struct TreeNode * tmp_ptr = root;
    int current_level = 1;
    
    int height = find_height(root);
    
    int * ret_arr = (int *)malloc(sizeof(int) * height);
    int ret_arr_index = 0;
    
    enqueue(&tmp_queue, tmp_ptr, current_level);
    
    int previous_level = 1;
    int max_element = INT_MIN;
    
    while(!isQueueEmpty(&tmp_queue))
    {
        tmp_ptr = dequeue(&tmp_queue, &current_level);
        if(current_level == previous_level)
        {
            if(tmp_ptr->val >= max_element)
            {
                max_element = tmp_ptr->val;
            }
        }
        else if(current_level != previous_level)
        {
            ret_arr[ret_arr_index++] = max_element;
            max_element = INT_MIN;
            previous_level = current_level;
            
            if(tmp_ptr->val >= max_element)
            {
                max_element = tmp_ptr->val;
            }
        }
        
        if(tmp_ptr->left != NULL)
            enqueue(&tmp_queue, tmp_ptr->left, current_level+1);
        
        if(tmp_ptr->right != NULL)
            enqueue(&tmp_queue, tmp_ptr->right, current_level+1);
    }
    ret_arr[ret_arr_index++] = max_element;
    
    *returnSize = ret_arr_index;
    return ret_arr;
    
}