#include <bits/stdc++.h>
using namespace std;

int T[1002][1002];

int x = 0;

bool isPalin(string a, int i, int j)
{
  while (i < j)
  {
    if (a[i] != a[j])
      return false;
    i++;
    j--;
  }

  return true;
}

int palindromePartitioning(string a, int i, int j)
{
  x++;
  if (i >= j)
    return 0;

  if (isPalin(a, i, j))
    return 0;

  if (T[i][j] != -1)
    return T[i][j];

  int ans = INT_MAX;
  for (int k = i; k < j; k++)
  {
    int left, right;
    if (T[i][k] == -1)
    {
      left = palindromePartitioning(a, i, k);
      T[i][k] = left;
    }
    else
      left = T[i][k];

    if (T[k + 1][j] == -1)
    {
      right = palindromePartitioning(a, k + 1, j);
      T[k + 1][j] = right;
    }
    else
      right = T[k + 1][j];

    int t = left + right + 1;
    ans = min(ans, t);
  }

  return T[i][j] = ans;
}

int main()
{
  memset(T, -1, sizeof(T));
  string a = "abaaa";
  cout << palindromePartitioning(a, 0, a.length() - 1) << endl;
  cout << x;
}
