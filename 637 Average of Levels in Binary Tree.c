/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#define MAX_NODES 10000


typedef struct queue
{
    struct TreeNode * arr[MAX_NODES];
    int arr_level[MAX_NODES];
    int front;
    int rear;
}Queue;

int isQueueFull(Queue * avg_level_queue)
{
    if(avg_level_queue->rear == MAX_NODES-1)
        return 1;
    else
        return 0;
}

int isQueueEmpty(Queue * avg_level_queue)
{
    if(avg_level_queue->front == -1)
        return 1;
    else
        return 0;
}

void enqueue(Queue * avg_level_queue, struct TreeNode * element, int level)
{
    if(isQueueFull(avg_level_queue))
        return;
    
    avg_level_queue->arr[++(avg_level_queue->rear)] = element;
    avg_level_queue->arr_level[avg_level_queue->rear] = level;
    
    if(avg_level_queue->front == -1)
        avg_level_queue->front = 0;
}

struct TreeNode * dequeue(Queue * avg_level_queue, int * ret_level)
{
    if(isQueueEmpty(avg_level_queue))
        return NULL;
    
    struct TreeNode * ret_element = avg_level_queue->arr[avg_level_queue->front];
    *ret_level = avg_level_queue->arr_level[avg_level_queue->front];
    
    if(avg_level_queue->front == avg_level_queue->rear)
    {
        avg_level_queue->front = -1;
        avg_level_queue->rear = -1;
    }
    else
    {
        ++(avg_level_queue->front);
    }
    return ret_element;
}

int height(struct TreeNode * root)
{
    if(root == NULL)
        return 0;
    
    int left = height(root->left);
    int right = height(root->right);
    
    if(left>=right)
        return left+1;
    else
        return right+1;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
double* averageOfLevels(struct TreeNode* root, int* returnSize)
{
    Queue avg_level_queue;
    avg_level_queue.front = -1;
    avg_level_queue.rear  = -1;
    
    int height_of_tree = height(root);
    
    double * ret_ptr = (double *)malloc(sizeof(double) * height_of_tree);
    int ret_ptr_index = 0;
    
    int current_level = 1;
    int prev_level = 1;
    
    double cur_level_sum = 0;
    double no_of_nodes_in_cur_level = 0;
    
    struct TreeNode * trav_ptr = root;
    
    enqueue(&avg_level_queue, trav_ptr, current_level);
    
    while(!isQueueEmpty(&avg_level_queue))
    {
        trav_ptr = dequeue(&avg_level_queue, &current_level);
        
        if(current_level != prev_level)
        {
            ret_ptr[ret_ptr_index++] = (cur_level_sum/no_of_nodes_in_cur_level);
     
            cur_level_sum = (double)trav_ptr->val;
            no_of_nodes_in_cur_level = 1;
        }
        else
        {
            cur_level_sum += (double)trav_ptr->val;
            no_of_nodes_in_cur_level += 1;
        }
        prev_level = current_level;
        
        if(trav_ptr->left)
        {
            enqueue(&avg_level_queue, trav_ptr->left, current_level+1);
        }
        
        if(trav_ptr->right)
        {
            enqueue(&avg_level_queue, trav_ptr->right, current_level+1);
        }
        
    }
    ret_ptr[ret_ptr_index++] = (cur_level_sum/no_of_nodes_in_cur_level);
    *returnSize = height_of_tree;
    return ret_ptr;
    
    
}