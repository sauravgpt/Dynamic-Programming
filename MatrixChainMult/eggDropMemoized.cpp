#include <bits/stdc++.h>
using namespace std;

int T[102][100002];

int eggDrop(int egg, int floor)
{
  if (egg == 1)
    return floor;

  if (floor == 0 || floor == 1)
    return floor;

  if (T[egg][floor] != -1)
    return T[egg][floor];

  int ans = INT_MAX;

  for (int k = 1; k <= floor; k++)
  {

    int low, high;

    if (T[egg - 1][k - 1] != -1)
      low = T[egg - 1][k - 1];
    else
      low = eggDrop(egg - 1, k - 1);

    if(T[egg][floor-k] != -1)
      high = T[egg][floor-k];
    else
      high = eggDrop(egg, floor - k);

    int temp = 1 + max(low, high);
    ans = min(ans, temp);
  }
  return T[egg][floor] = ans;
}

int main()
{
  int egg = 3;
  int floor = 7;

  for (int i = 0; i <= egg; i++)
    for (int j = 0; j <= floor; j++)
      T[i][j] = -1;

  cout << eggDrop(egg, floor);
}