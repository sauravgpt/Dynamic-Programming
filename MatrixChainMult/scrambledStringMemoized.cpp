#include <bits/stdc++.h>
using namespace std;

unordered_map<string, bool> T;
int y = 0;
bool solve(string a, string b)
{
  y++;
  if (a.compare(b) == 0)
    return true;
  if (a.length() <= 1)
    return false;

  bool flag = false;

  string x = a + " " + b;
  if(T.find(x) != T.end())
    return T[x];

  int n = a.length();
  for (int i = 1; i < n; i++)
  {
    bool conditionA = solve(a.substr(0, i), b.substr(n - i, i)) && solve(a.substr(i, n - i), b.substr(0, n - i));
    bool conditionB = solve(a.substr(0, i), b.substr(0, i)) && solve(a.substr(i, n - i), b.substr(i, n - 1));

    if (conditionA || conditionB)
    {
      flag = true;
      break;
    }
  }
  return T[x] = flag;
}

int main()
{
  string a, b;
  cin >> a >> b;
  if (a.length() != b.length())
    cout << false;
  if (a.length() == 0 || b.length() == 0)
    cout << false;

  cout << solve(a, b) << " " << y << endl;
}