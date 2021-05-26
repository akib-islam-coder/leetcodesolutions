#define STR_SIZE 22

char * defangIPaddr(char * address)
{   
    char * ret_string = (char *)malloc(sizeof(char) * STR_SIZE);
    int ret_string_index = 0;
    
    int i=0;
    while(address[i] != '\0')
    {
        if(address[i] != '.')
        {
            ret_string[ret_string_index++] = address[i];

        }
        else
        {
            ret_string[ret_string_index++] = '[';
            ret_string[ret_string_index++] = address[i];
            ret_string[ret_string_index++] = ']';
        }
        i++;
    }
    
    ret_string[ret_string_index] = '\0';
    
    return ret_string;
    
}