/* You are given an array prices where prices[i] is the price of a given stock on the ith day.
You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock. 
Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0. */

#include <stdio.h>

int maxProfit(int prices[], int n) {
    int minPrice = prices[0];
    int maxProfit = 0;

    for(int i = 1; i < n; i++) {
        if(prices[i] < minPrice) {
            minPrice = prices[i];
        } else {
            int profit = prices[i] - minPrice;
            if(profit > maxProfit)
                maxProfit = profit;
        }
    }
    return maxProfit;
}

int main() {
    int n;
    printf("Enter number of days: ");
    scanf("%d", &n);

    int prices[n];
    printf("Enter stock prices:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &prices[i]);
    }

    printf("Maximum Profit = %d\n", maxProfit(prices, n));
    return 0;
}
