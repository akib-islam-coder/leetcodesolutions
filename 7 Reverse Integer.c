

int reverse(int x)
{
    
    bool neg = false;
    if(x < 0)
    {
        neg = true;
        if(x == (-1*pow(2,31)))
        {
            return 0;
        }
        x *= -1;
    }
    
    int num = 0;
    
    while(x>0)
    {
        if(num > (pow(2,31)-1)/10)
        {
            num = 0;
            break;
        }
        
        num = (num*10) + (x%10);
        x /= 10;
    }
    
    if(neg)
    {
        num *= -1;
    }
    return num;
}