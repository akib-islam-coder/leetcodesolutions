

int minTimeToVisitAllPoints(int** points, int pointsSize, int* pointsColSize)
{
    int start_x_cor = 0;
    int end_x_cor = 0;
    
    int start_y_cor = 0;
    int end_y_cor = 0;
    
    int count = 0;
    
    int i=1;
    while(i<pointsSize)
    {
        start_x_cor = points[i-1][0];
        start_y_cor = points[i-1][1];
        
        end_x_cor = points[i][0];
        end_y_cor = points[i][1];
        
        
        bool flag = true;
        while(flag)
        {
            if((end_x_cor == start_x_cor) && (end_y_cor > start_y_cor))
            {

                count++;
                start_y_cor++;
            }
            
            else if((end_x_cor == start_x_cor) && (end_y_cor < start_y_cor))
            {
 
                count++;
                start_y_cor--;
            }
            
            else if((end_y_cor == start_y_cor) && (end_x_cor > start_x_cor))
            {
 
                count++;
                start_x_cor++;
            }
            
            else if((end_y_cor == start_y_cor) && (end_x_cor < start_x_cor))
            {

                count++;
                start_x_cor--;
            }
            
            else if((end_y_cor > start_y_cor) && (end_x_cor > start_x_cor))
            {
 
                count++;
                start_x_cor++;
                start_y_cor++;
            }
            
            else if((end_y_cor > start_y_cor) && (end_x_cor < start_x_cor))
            {
              
                count++;
                start_x_cor--;
                start_y_cor++;
            }
            
            else if((end_y_cor < start_y_cor) && (end_x_cor > start_x_cor))
            {
               
                count++;
                start_x_cor++;
                start_y_cor--;
            }
            
            else if((end_y_cor < start_y_cor) && (end_x_cor < start_x_cor))
            {
                
                count++;
                start_x_cor--;
                start_y_cor--;
            }
            
            else if((end_x_cor == start_x_cor) && (end_y_cor == start_y_cor))
            {
                
                flag = false;
            }
        }        
        i++;
    }
    return count;
}