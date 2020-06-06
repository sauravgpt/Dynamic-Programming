#include <iostream>
using namespace std;

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

  int ans = 0;



  for (int k = i + 1; k < j; k+=2)
  {
    int lT = solve(s, i, k - 1, true);
    int rT = solve(s, k + 1, j, true);
    int lF = solve(s, i, k - 1, false);
    int rF = solve(s, k + 1, j, false);

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

  return ans;
}

int main(){
  string s = "T^F&T";
  cout << solve(s, 0, s.length()-1, true);
}