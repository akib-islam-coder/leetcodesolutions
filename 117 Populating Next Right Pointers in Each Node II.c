/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *left;
 *     struct Node *right;
 *     struct Node *next;
 * };
 */
#define MAX_NODES 6000

typedef struct
{
    struct Node * queue_arr[MAX_NODES];
    int level_arr[MAX_NODES];
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
    if(tmp_queue->rear == MAX_NODES - 1)
        return 1;
    else
        return 0;
}

void enqueue(Queue * tmp_queue, struct Node * element, int level)
{
    if(isQueueFull(tmp_queue))
        return;
    
    tmp_queue->queue_arr[++(tmp_queue->rear)] = element;
    tmp_queue->level_arr[tmp_queue->rear] = level;
    
    if(tmp_queue->front == -1)
        tmp_queue->front = 0;
    
    return;
}

struct Node * dequeue(Queue * tmp_queue, int * level)
{
    if(isQueueEmpty(tmp_queue))
        return NULL;
    
    struct Node * ret_node = tmp_queue->queue_arr[tmp_queue->front];
    *level = tmp_queue->level_arr[tmp_queue->front];
    
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

struct Node * peek(Queue * tmp_queue, int * level)
{
    if(tmp_queue->front == tmp_queue->rear)
    {
        return NULL;
    }
    else
    {
        struct Node * ret_ptr = tmp_queue->queue_arr[tmp_queue->front + 1];
        *level = tmp_queue->level_arr[tmp_queue->front + 1];
        return ret_ptr;
    }
    return NULL;
}

struct Node* connect(struct Node* root) 
{
    
    if(root == NULL)
        return root;
    
	Queue tmp_queue;
    tmp_queue.front = -1;
    tmp_queue.rear  = -1;
    
    int cur_level = 1;
    int prev_level = 1;
    
    struct Node * trav_ptr = root;
    enqueue(&tmp_queue, trav_ptr, cur_level);
    
    while(!isQueueEmpty(&tmp_queue))
    {  
        int peek_level;
        struct Node * peek_node;
        
        peek_node = peek(&tmp_queue, &peek_level);
        trav_ptr  = dequeue(&tmp_queue, &cur_level);
        
        if(peek_node != NULL)
        {
            if(peek_level == cur_level)
            {
                trav_ptr->next = peek_node;
            }
        }

        if(trav_ptr->left != NULL)
            enqueue(&tmp_queue, trav_ptr->left,  cur_level+1);
        
        if(trav_ptr->right != NULL)
            enqueue(&tmp_queue, trav_ptr->right, cur_level+1);
    }
    return root;
}