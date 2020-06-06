#include <bits/stdc++.h>
using namespace std;

int T[201][201][2];

int solve(string s, int i, int j, bool isTrue)
{
  if (i > j)
    return false;

  if (i == j)
  {
    if (isTrue == true)
      return s[i] == 'T';
    else
      return s[i] == 'F';
  }

  if (T[i][j][isTrue] != -1)
    return T[i][j][isTrue];

  int ans = 0;

  for (int k = i + 1; k < j; k += 2)
  {
    int lT, rT, lF, rF;

    if (T[i][k - 1][true] != -1)
      lT = T[i][k - 1][true];
    else
    {
      lT = solve(s, i, k - 1, true);
      // T[i][k - 1][true] = lT;
    }

    if (T[i][k - 1][false] != -1)
      lF = T[i][k - 1][false];
    else
    {
      lF = solve(s, i, k - 1, false);
      // T[i][k - 1][false] = lT;
    }

    if (T[k + 1][j][true] != -1)
      rT = T[k + 1][j][true];
    else
    {
      rT = solve(s, k + 1, j, true);
      // T[k + 1][j][true] = lT;
    }

    if (T[k + 1][j][false] != -1)
      rF = T[k + 1][j][false];
    else
    {
      rF = solve(s, k + 1, j, false);
      // T[k + 1][j][false] = lT;
    }

    if (s[k] == '&')
      if (isTrue == true)
        ans += lT * rT;
      else
        ans += lT * rF + lF * rT + lF * rF;
    else if (s[k] == '|')
      if (isTrue == true)
        ans += lT * rT + lF * rT + lT * rF;
      else
        ans += lF * rF;
    else if (s[k] == '^')
    {
      if (isTrue == true)
        ans += lT * rF + lF * rT;
      else
        ans += lT * rT + lF * rF;
    }
  }
  T[i][j][isTrue] = ans % 1003;
  return T[i][j][isTrue];
}

int main()
{
  memset(T, -1, sizeof(T));
  string s = "T&T|F|F^F^T^T^T&T^F^T&F|F^F^F&F&F|F|F^F^T|T&T";
  cout << solve(s, 0, s.length() - 1, true);
}