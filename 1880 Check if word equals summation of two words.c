

bool isSumEqual(char * firstWord, char * secondWord, char * targetWord)
{
    int sum = 0;   
    int num_val = 0;
    
    int i=0;
    while(firstWord[i] != '\0')
    {
        num_val = (num_val * 10) + (firstWord[i] - 'a');
        i++;
    }
    
    sum += num_val;
    
    i=0;
    num_val = 0;
    while(secondWord[i] != '\0')
    {
        num_val = (num_val * 10) + (secondWord[i] - 'a');
        i++;
    }
    
    sum += num_val;
    
    i=0;
    int target_sum = 0;
    
    while(targetWord[i] != '\0')
    {
        target_sum = (target_sum * 10) + (targetWord[i] - 'a');
        i++;
    }
    
    
    if(sum == target_sum)
        return true;
    
    return false;
    
}