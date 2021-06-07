#define STACK_SIZE 10000

typedef struct stack
{
    char arr[STACK_SIZE];
    int top;
}Stack;

int isStackEmpty(Stack * par_stack)
{
    if(par_stack->top == -1)
        return 1;
    else 
        return 0;
}

int isStackFull(Stack * par_stack)
{
    if(par_stack->top == STACK_SIZE - 1)
        return 1;
    else 
        return 0;
}

void push(Stack * par_stack, char element)
{
    if(isStackFull(par_stack))
        return;
    
    par_stack->arr[++(par_stack->top)] = element;
}

char pop(Stack * par_stack)
{
    if(isStackEmpty(par_stack))
        return;
    
    char ret_element = par_stack->arr[par_stack->top];
    (par_stack->top)--;
    return ret_element;
}

char * removeOuterParentheses(char * s)
{
    if(s == "")
        return s;
    
    Stack par_stack;
    par_stack.top = -1;
    memset(&par_stack.arr, '\0', sizeof(par_stack.arr));
    
    char * ret_str = (char *)malloc(sizeof(char)*STACK_SIZE);
    int ret_str_index = 0;
    
    int i=0;
    
    while(s[i]!='\0')
    {     
        if(i==0)
        {
            push(&par_stack.arr, s[i]);
        }
        else
        {
            if(s[i] == '(')
            {
                if(!isStackEmpty(&par_stack.arr))
                { 
                    ret_str[ret_str_index++] = s[i];
                }
                
                push(&par_stack.arr, s[i]);           
                
            }
            else if(s[i] == ')')
            {
                char pop_element = pop(&par_stack.arr);
                if(!isStackEmpty(&par_stack.arr))
                {
                     ret_str[ret_str_index++] = s[i];
                }
                    
            }        
        }       
        i++;
    }
    ret_str[ret_str_index] = '\0';
    return ret_str;
}




