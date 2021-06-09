

int maxDepth(char * s)
{
    int current_depth = 0;
    int max_depth = 0;
    
    int i=0;
    while(s[i]!='\0')
    {
        if(s[i] == '(')
        {
            current_depth++;
        }
        
        else if(s[i] == ')')
        {
            if(current_depth > max_depth)
            {
                max_depth = current_depth;
            }
            current_depth--;
        }
        
        i++;
    }
    
    return max_depth;
    
   
}