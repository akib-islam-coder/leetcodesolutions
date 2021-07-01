#define MAX_NODES 100

typedef struct
{
    char arr[MAX_NODES];
    int top;
}Stack;

int isStackEmpty(Stack * tmp_stack)
{
    if(tmp_stack->top == -1)
        return 1;
    else
        return 0;
}

int isStackFull(Stack * tmp_stack)
{
    if(tmp_stack->top == MAX_NODES-1)
        return 1;
    else
        return 0;
}

void push(Stack * tmp_stack, char * element)
{
    if(isStackFull(tmp_stack))
        return;
    
    tmp_stack->arr[++(tmp_stack->top)] = element;
}

char * pop(Stack * tmp_stack)
{
    if(isStackEmpty(tmp_stack))
        return '\0';
    
    return tmp_stack->arr[(tmp_stack->top)--];
}

char peek(Stack * tmp_stack, int index)
{
    return tmp_stack->arr[index];
}

char * makeGood(char * s)
{
    Stack tmp_stack;
    tmp_stack.top = -1;
    
    int i=0;
    while(s[i] != '\0')
    {
        push(&tmp_stack, s[i]);
        
        if(tmp_stack.top != 0)
        {
            char pop_element = peek(&tmp_stack, tmp_stack.top - 1);
            
            if(s[i] >= 'a' && s[i] <= 'z')
            {
                if( pop_element == s[i] - ('a' - 'A'))
                {
                    pop(&tmp_stack);
                    pop(&tmp_stack);
                }
            }
            else if(s[i] >= 'A' && s[i] <= 'Z')
            {
                if( pop_element == s[i] + ('a' - 'A'))
                {
                    pop(&tmp_stack);
                    pop(&tmp_stack);
                }
            }
        }
        
        i++;
    }
    
    char * ret_str = (char *)malloc(sizeof(char) * (tmp_stack.top + 2));
    int ret_str_index = 0;
    i=0;
    for(i=0; i<=tmp_stack.top;i++)
    {
        ret_str[ret_str_index++] = peek( &tmp_stack ,i);
    }
    ret_str[ret_str_index] = '\0';
    return ret_str;
}