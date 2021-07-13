

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* numberOfLines(int* widths, int widthsSize, char * s, int* returnSize)
{
    int lines = 1;
    int current_pixel = 0;

    int i=0;
    while(s[i] != '\0')
    {
        int char_width = widths[s[i] - 'a'];
        
        if(char_width + current_pixel <= 100)
        {
            current_pixel += char_width;
            i++;
        }
        else
        {
            current_pixel = 0;
            lines++;
        }
    }
    
    int * ret_arr = (int *)malloc(sizeof(int) * 2);
    ret_arr[0] = lines;
    ret_arr[1] = current_pixel;
    *returnSize = 2;
    return ret_arr;
    
}