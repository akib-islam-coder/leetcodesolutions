

int numberOfSteps(int num)
{
    int no_of_steps = 0;
    
    while(num!=0)
    {
        if(num%2)   //Odd
        {
            num -= 1;    
            no_of_steps++;
        }
        
        if(num == 0)
        {
            break;
        }
        
        num /= 2;
        no_of_steps++;            
    }
    return no_of_steps;
}