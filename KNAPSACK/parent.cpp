#include <iostream>
using namespace std;

int knapsack(int wt[], int val[], int W, int n)
{
  // Base case - Think of smallest valid input
  if (n == 0 || W == 0)
    return 0;

  
}

int main()
{
  int wt[] = {};
  int val[] = {};
  int W = 7;
  int n = 4;
  cout << knapsack(wt, val, W, n);
}