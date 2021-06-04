

char * toLowerCase(char * s)
{
    int i=0;
    
    while(s[i]!='\0')
    {
        if((s[i] >= 'A') && (s[i] <= 'Z'))
        {
            s[i] = s[i] + ('a' - 'A');
        }
        i++;
    }
    return s;
}