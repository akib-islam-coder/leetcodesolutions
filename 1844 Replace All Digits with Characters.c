char shift(char c, char x)
{
    int num = x - '0';
    char ret_val = c + num;
    return ret_val;
}

char * replaceDigits(char * s)
{
    int i=0;
    
    while(s[i]!='\0')
    {
        if(i%2 != 0)
        {
            s[i] = shift(s[i-1], s[i]);
        }
        i++;
    }
    return s;
}