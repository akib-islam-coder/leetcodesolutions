#define MAX_ELEMENTS 10000

typedef struct stack
{
    char arr[MAX_ELEMENTS];
    int top;
}Stack;

int isStackEmpty(Stack * s_stack)
{
    if(s_stack->top == -1)
        return 1;
    else
        return 0;
}

int isStackFull(Stack * s_stack)
{
    if(s_stack->top == MAX_ELEMENTS-1)
        return 1;
    else 
        return 0;
}

void push(Stack * s_stack, char element)
{
    if(isStackFull(s_stack))
        return;
    
    s_stack->arr[++(s_stack->top)] = element;
}

char pop(Stack * s_stack)
{
    if(isStackEmpty(s_stack))
        return '\0';
    
    char ret_val = s_stack->arr[s_stack->top];
    --(s_stack->top);
    return ret_val;
}

bool isValid(char * s)
{
    Stack s_stack;
    s_stack.top = -1;
    memset(s_stack.arr, NULL, sizeof(s_stack.arr));
    
    int i=0;
    while(s[i]!='\0')
    {
        if((s[i] == '(') || (s[i] == '{') || (s[i] == '['))
        {
            push(&s_stack, s[i]);
            i++;
        }
        else if((s[i] == ')') || (s[i] == '}') || (s[i] == ']'))
        {
            char pop_element = pop(&s_stack);
            
            if(((s[i] == ')') && (pop_element == '(')) || ((s[i] == '}') && (pop_element == '{')) || ((s[i] == ']') && (pop_element == '['))) 
            {
                i++;
            }
            else
            {
                return false;
            }
        }
    }
    
    if(isStackEmpty(&s_stack))
        return true;   
    else
        return false;
}