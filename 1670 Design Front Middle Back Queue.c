typedef struct node
{
    int val;
    struct node * next;
}Node;


typedef struct 
{
  Node * front;
  Node * middle;
  Node * rear;
  int count;
} FrontMiddleBackQueue;


FrontMiddleBackQueue* frontMiddleBackQueueCreate() 
{
    FrontMiddleBackQueue * queue = (FrontMiddleBackQueue *)malloc(sizeof(FrontMiddleBackQueue));
    queue->front = NULL;
    queue->rear = NULL;
    queue->middle = NULL;
    queue->count = 0;
    return queue;
}

void frontMiddleBackQueuePushFront(FrontMiddleBackQueue* obj, int val) 
{
    Node * new_node = (Node *)malloc(sizeof(Node));
    new_node->val = val;
    
    new_node->next = obj->front;
    obj->front = new_node;
    
    //Only if the insertion at front is first insertion
    if(obj->rear == NULL)
    {
        obj->rear = obj->front;
    }
    
    obj->count++;
   
}

void frontMiddleBackQueuePushMiddle(FrontMiddleBackQueue* obj, int val) 
{
    Node * slow_ptr = obj->front;
    
    if(slow_ptr == NULL)    //First element
    {
       Node * new_node = (Node *)malloc(sizeof(Node));
       new_node->val = val; 
       new_node->next = NULL;
        
       obj->front = new_node;
       obj->rear = new_node;
       obj->count++;
       return;
    }
    
    else if(slow_ptr->next == NULL) //Only one element in queue
    {
        Node * new_node = (Node *)malloc(sizeof(Node));
        new_node->val = val;
        
        obj->front = new_node;
        new_node->next = slow_ptr;
        obj->count++;
        return;
    }
    
    Node * prev_slow_ptr = NULL;
    Node * fast_ptr = obj->front->next;
    
    while(fast_ptr != NULL)
    {
        prev_slow_ptr = slow_ptr;
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next;
        
        if(fast_ptr != NULL)
            fast_ptr = fast_ptr->next;
    }
    
    Node * new_node = (Node *)malloc(sizeof(Node));
    new_node->val = val;
    
    prev_slow_ptr->next = new_node;
    new_node->next = slow_ptr;   
    
    obj->count++;
}

void frontMiddleBackQueuePushBack(FrontMiddleBackQueue* obj, int val)
{
    Node * new_node = (Node *)malloc(sizeof(Node));
    new_node->val = val;  
    
    if(obj->rear != NULL)
    {
        obj->rear->next = new_node; 
    }
    else    //First Node
    {
        obj->front = new_node;
    }
    obj->rear = new_node;    
    new_node->next = NULL;
    
    obj->count++;
}

int frontMiddleBackQueuePopFront(FrontMiddleBackQueue* obj) 
{
    if(obj->front == NULL)
        return -1;
    
    int ret_val = obj->front->val;    
    Node * del_node = obj->front;    
    obj->front = obj->front->next;
    free(del_node);
    
    if(obj->front == NULL)  //Queue is empty
    {
        obj->rear = NULL;
    } 
    
    obj->count--;
    return ret_val;
}

int frontMiddleBackQueuePopMiddle(FrontMiddleBackQueue* obj) 
{

    Node * slow_ptr = obj->front;
    int ret_val;
    
    if(slow_ptr == NULL)
        return -1;
    
    if(slow_ptr->next == NULL)  //Only 1 element
    {
        printf("Here");
        ret_val = slow_ptr->val;
        obj->front = NULL;
        obj->rear = NULL;
        obj->count--;
        free(slow_ptr);
        return ret_val;
    }
    
    Node * prev_slow_ptr = NULL;
    Node * prev_prev_slow_ptr = NULL;
    Node * fast_ptr = obj->front->next;
    
    while(fast_ptr != NULL)
    {
        prev_prev_slow_ptr = prev_slow_ptr;
        prev_slow_ptr = slow_ptr;
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next;
        
        if(fast_ptr!=NULL)
            fast_ptr = fast_ptr->next;
    }
    
    if((obj->count)%2 == 0) //Even number of nodes
    {
        ret_val = prev_slow_ptr->val;
        if(obj->count == 2)
        {
            free(prev_slow_ptr);
            obj->front = slow_ptr;        
        }
        else
        {
            prev_prev_slow_ptr->next = slow_ptr;
            free(prev_slow_ptr);
        }       
    }
    else    //Odd number of nodes
    {
        ret_val = slow_ptr->val;
        prev_slow_ptr->next = slow_ptr->next;
        free(slow_ptr);
    }
    
    obj->count--;
    return ret_val;
}

int frontMiddleBackQueuePopBack(FrontMiddleBackQueue* obj) 
{
    if(obj->rear == NULL)
        return -1;
    
    int ret_val = obj->rear->val;
    Node * trav_ptr = obj->front;    
    if(trav_ptr == obj->rear)   //Only one element
    {
        obj->front = NULL;
        obj->rear = NULL;
        free(trav_ptr);
    }
    else
    {
        while(trav_ptr->next != obj->rear)
        {
            trav_ptr = trav_ptr->next;
        }
        trav_ptr->next = NULL;
        free(obj->rear);
        obj->rear = trav_ptr;
    }
    obj->count--;
    return ret_val;
}

void frontMiddleBackQueueFree(FrontMiddleBackQueue* obj)
{
    Node * trav_ptr = obj->front;
    Node * del_ptr = NULL;
    
    while(trav_ptr != NULL)
    {
        del_ptr = trav_ptr;
        trav_ptr = trav_ptr->next;
        free(del_ptr);
    }
    
    obj->front = NULL;
    obj->rear = NULL;
    obj->count = 0;
    
}

/**
 * Your FrontMiddleBackQueue struct will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = frontMiddleBackQueueCreate();
 * frontMiddleBackQueuePushFront(obj, val);
 
 * frontMiddleBackQueuePushMiddle(obj, val);
 
 * frontMiddleBackQueuePushBack(obj, val);
 
 * int param_4 = frontMiddleBackQueuePopFront(obj);
 
 * int param_5 = frontMiddleBackQueuePopMiddle(obj);
 
 * int param_6 = frontMiddleBackQueuePopBack(obj);
 
 * frontMiddleBackQueueFree(obj);
*/