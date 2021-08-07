

int maxProfit(int* prices, int pricesSize)
{
    int i = 0;
    int buy_price = INT_MAX;
    int buy_index = 0;
    
    int sell_price = INT_MIN;
    int sell_index = 0;
    
    int profit = 0;
    
    for(i=0; i<pricesSize; i++)
    {
        if(i == 0)
        {
            buy_price = prices[i];
            continue;
        }
        else
        {
            if(prices[i] <= buy_price)
            {
                buy_price = prices[i];
                sell_price = 0;
            }
            else if(prices > buy_price)
            {
                sell_price = prices[i];
                
                if(sell_price - buy_price >= profit)
                {
                    profit = sell_price - buy_price;
                }
            }
        }  
    }
    return profit;
    
}