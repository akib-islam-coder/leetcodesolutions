#define MAX_SIZE 10000
typedef struct
{
    int queue[10000];
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
    if(tmp_queue->rear == MAX_SIZE-1)
        return 1;
    else
        return 0;
}

void enqueue(Queue * tmp_queue, int index)
{
    if(isQueueFull(tmp_queue))
        return;
    
    tmp_queue->queue[++(tmp_queue->rear)] = index;
    
    if(tmp_queue->front == -1)
        tmp_queue->front = 0;
}

int dequeue(Queue * tmp_queue)
{
    if(isQueueEmpty(tmp_queue))
        return INT_MIN;
    
    int ret_element = tmp_queue->queue[tmp_queue->front];
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

void moveZeroes(int* nums, int numsSize)
{
    Queue tmp_queue;
    tmp_queue.front = -1;
    tmp_queue.rear = -1;
    
    int i=0;
    
    for(i=0; i<numsSize; i++)
    {
        if(nums[i]!=0 && isQueueEmpty(&tmp_queue))
        {
            continue;
        }
        
        else if(nums[i]!=0 && !isQueueEmpty(&tmp_queue))
        {
            int index = dequeue(&tmp_queue);
            nums[index] = nums[i];
            nums[i] = 0;
            enqueue(&tmp_queue, i);
        }
        else if(nums[i] == 0)
        {
            enqueue(&tmp_queue, i);
        }       
    }
    return nums;
}