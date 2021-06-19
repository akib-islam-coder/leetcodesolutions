

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** flipAndInvertImage(int** image, int imageSize, int* imageColSize, int* returnSize, int** returnColumnSizes)
{
    
   int rows = 0, columns = 0;
   for(rows=0; rows<imageSize; rows++)
   {
       for(columns=0; columns<(*imageColSize/2); columns++)
       {
           int tmp_val = image[rows][columns];
           image[rows][columns] = image[rows][(*imageColSize-columns-1)];
           image[rows][(*imageColSize-columns-1)] = tmp_val;
       }
       
       for(columns=0; columns<(*imageColSize); columns++)
       {
           image[rows][columns] ^= 1;
       }
   }
    *returnSize = imageSize;
    
    
    *returnColumnSizes = (int *)malloc(sizeof(int) * imageSize);
    int returnColumnSizes_index = 0;
    int i=0;
    for(i=0; i<imageSize; i++)
    {
        *(*returnColumnSizes + returnColumnSizes_index++) = imageSize;
    }
    
     
    
    
    return image;
}