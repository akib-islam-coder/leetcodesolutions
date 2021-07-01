#define MAX_NODE 30000

typedef struct 
{
    int arr[MAX_NODE];   
    int top;
    int min;
} MinStack;

/** initialize your data structure here. */

MinStack* minStackCreate() 
{
    MinStack * min_stack = (MinStack *)malloc(sizeof(MinStack));
    min_stack->top = -1;
    min_stack->min = INT_MAX;
    return min_stack;
}

int isStackEmpty(MinStack *obj)
{
    if(obj->top == -1)
        return 1;
    else
        return 0;
}

int isStackFull(MinStack *obj)
{
    if(obj->top == MAX_NODE-1)
        return 1;
    else
        return 0;
}

void minStackPush(MinStack* obj, int val) 
{
    if(isStackFull(obj))
        return;
    
    obj->arr[++(obj->top)] = val;
    if(val <= obj->min)
    {
        obj->min = val;
    }
}

void minStackPop(MinStack* obj) 
{
    if(isStackEmpty(obj))
        return;
    
    int pop_element = obj->arr[(obj->top)--];
    if(pop_element == obj->min)
    {
        //Search for the new min
        int i=0;
        obj->min = INT_MAX;
        for(i=0; i<=obj->top; i++)
        {
            if(obj->arr[i] <= obj->min)
            {
                obj->min = obj->arr[i];
            }
        }
    }
}

int minStackTop(MinStack* obj) 
{
    return obj->arr[obj->top];
}

int minStackGetMin(MinStack* obj) 
{
    return obj->min;
}

void minStackFree(MinStack* obj) 
{
    free(obj);    
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, val);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/