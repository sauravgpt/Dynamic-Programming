#include <iostream>
using namespace std;

int knapsack(int wt[], int val[], int W, int n)
{
  // Base case - Think of smallest valid input
  if (n == 0 || W == 0)
    return 0;

  // Implementing choice diamgram
  // /DP/KNAPSACK/parent_kanpsack_choice.png

  if (wt[n - 1] <= W)
    return max(val[n - 1] + knapsack(wt, val, W - wt[n - 1], n - 1),
               knapsack(wt, val, W, n - 1));

  else
    return knapsack(wt, val, W, n - 1);
}

int main()
{
  int val[] = {60, 100, 120};
  int wt[] = {10, 20, 30};
  int W = 50;
  int n = 3;
  cout << knapsack(wt, val, W, n);
}