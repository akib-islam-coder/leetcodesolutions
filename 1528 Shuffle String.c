

char * restoreString(char * s, int* indices, int indicesSize)
{
    char * ret_str = (char *)malloc(sizeof(char) * (indicesSize + 1));
    
    int i=0;
    while(s[i] != '\0')
    {
        ret_str[indices[i]] = s[i];
        i++;
    }
    ret_str[i] = '\0';
    return ret_str;
    
}