#include <bits/stdc++.h>
using namespace std;

int minChange(int C[], int V, int n)
{
  int T[n + 1][V + 1];
  for (int i = 0; i < n + 1; i++)
  {
    for (int j = 0; j < V + 1; j++)
    {
      if (i == 0)
        T[i][j] = INT_MAX - 1;
      else if (j == 0)
        T[i][j] = 0;
      else if (C[i - 1] <= V)
      {
        T[i][j] = min(T[i][j - C[i - 1]] + 1, T[i - 1][j]);
      }
      else
        T[i][j] = T[i - 1][j];
    }
  }
  if (T[n][V] == INT_MAX - 1)
    return -1;
  return T[n][V];
}

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int V, n;
    cin >> V >> n;
    int C[n];
    for (int i = 0; i < n; i++)
      cin >> C[i];
    cout << minChange(C, V, n) << "\n";
  }
  return 0;
}