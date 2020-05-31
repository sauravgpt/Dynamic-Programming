#include <bits/stdc++.h>
using namespace std;

string LCS(string a, string b, int n, int m)
{
  int T[n + 1][m + 1];
  for (int i = 0; i < n + 1; i++)
  {
    for (int j = 0; j < m + 1; j++)
    {
      if (i == 0 || j == 0)
        T[i][j] = 0;
      else if (a[i - 1] == b[i - 1])
        T[i][j] = 1 + T[i - 1][j - 1];
      else
        T[i][j] = max(T[i - 1][j], T[i][j - 1]);
    }
  }
  string res = "";

  int i = n, j = m;
  while (i > 0 && j > 0)
  {
    if (a[i - 1] == b[i - 1])
    {
      res = a[i - 1] + res;
      i--;
      j--;
    }
    else
    {
      if (T[i - 1][j] > T[i][j - 1])
        i--;
      else
        j--;
    }
  }

  return res;
}

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    string a, b;
    int n, m;
    cin >> n >> m;
    cin >> a >> b;
    cout << LCS(a, b, n, m) << "\n";
  }
  return 0;
}