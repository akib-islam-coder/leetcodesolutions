typedef struct 
{
    char * arr_ptr;
    int top;
}Stack;

int len = 0;

int isStackEmpty(Stack * tmp_stack)
{
    if(tmp_stack->top == -1)
        return 1;
    else
        return 0;
}

int isStackFull(Stack * tmp_stack)
{
    if(tmp_stack->top == len-1)
        return 1;
    else
        return 0;
}

void push(Stack * tmp_stack, char element)
{
    if(isStackFull(tmp_stack))
        return;
    
    tmp_stack->arr_ptr[++(tmp_stack->top)] = element;
}

char pop(Stack * tmp_stack)
{
    if(isStackEmpty(tmp_stack))
        return '\0';
    
    return tmp_stack->arr_ptr[(tmp_stack->top)--];
}

char peek(Stack * tmp_stack)
{
    if(isStackEmpty(tmp_stack))
        return '\0';
    
    return tmp_stack->arr_ptr[tmp_stack->top];
}

char * removeDuplicates(char * s)
{
    Stack tmp_stack;
    tmp_stack.top = -1;
    
    len = strlen(s);
    tmp_stack.arr_ptr = (char *)malloc(sizeof(char)*(len+1));
    
    int i=0;
    while(s[i] != '\0')
    {
        char peek_element = peek(&tmp_stack);
        
        if((peek_element == '\0') || (peek_element != s[i]))
        {
            push(&tmp_stack, s[i]);   
        }
        else if(peek_element == s[i])
        {
            char pop_element = pop(&tmp_stack);       
        }    
        i++;
    }
           
    int ret_arr_len = (tmp_stack.top + 1);
    char * ret_arr = (char *)malloc(sizeof(char)*(ret_arr_len+1));
           
    for(i=0; i<=tmp_stack.top; i++)
    {
        ret_arr[i] = tmp_stack.arr_ptr[i];         
    }
    ret_arr[i] = '\0';
    return ret_arr;
    
    
}