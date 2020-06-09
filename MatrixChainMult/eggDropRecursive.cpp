#include <bits/stdc++.h>
using namespace std;

int eggDrop(int egg, int floor)
{
  if (egg == 1)
    return floor;

  if (floor == 0 || floor == 1)
    return floor;

  int ans = INT_MAX;

  for (int k = 1; k <= floor; k++)
  {
    int temp = 1 + max(eggDrop(egg - 1, k - 1), eggDrop(egg, floor - k));
    ans = min(ans, temp);
  }
  return ans;
}

int main()
{
  int egg = 3;
  int floor = 7;

  cout << eggDrop(egg, floor);
}