

char * truncateSentence(char * s, int k)
{
    int len = strlen(s);
    char * ret_str = (char *)malloc(sizeof(char)*(len+1));
    int ret_str_index = 0;
    
    int i=0;
    
    while(s[i] != '\0')
    {
        if(s[i] == ' ')
        {
            k--;
        }
        
        if(k > 0)
        {
            ret_str[ret_str_index++] = s[i]; 
        }
        else if(k==0)
        {
            break;
        }
        i++;
    }
    
    ret_str[ret_str_index] = '\0';
    return ret_str;
}