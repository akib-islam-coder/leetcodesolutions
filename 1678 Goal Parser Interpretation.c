

char * interpret(char * command)
{
    char * ret_str = (char *)malloc(sizeof(char)*(strlen(command)+1));
    int ret_str_index = 0;
    
    int i=0;
    while(command[i] != '\0')
    {
        if(command[i] == 'G')
        {
            ret_str[ret_str_index++] = 'G';
            i++;;
        }
        else if(command[i] == '(')
        {
            i++;
            if(command[i] == ')')
            {
                ret_str[ret_str_index++] = 'o';
            }
            else
            {
                ret_str[ret_str_index++] = command[i++];
                ret_str[ret_str_index++] = command[i++];
            }
        }
        else
        {
            i++;
        }    
    }
    ret_str[ret_str_index] = '\0';

    return ret_str;
}