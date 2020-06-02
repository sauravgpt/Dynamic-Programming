#include <iostream>
using namespace std;

int coin(int arr[], int A, int n)
{
  int T[n + 1][A + 1];
  for (int i = 0; i < n + 1; i++)
  {
    for (int j = 0; j < A + 1; j++)
    {
      if (i == 0)
        T[i][j] = 0;
      else if (j == 0)
        T[i][j] = 1;
      else if (arr[i - 1] <= j)
        T[i][j] = T[i][j - arr[i - 1]] + T[i - 1][j];
      else
        T[i][j] = T[i - 1][j]; 
    }
  }
  return T[n][A];
}

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
      cin >> arr[i];
    int A;
    cin >> A;
    cout << coin(arr, A, n) << "\n";
  }
  return 0;
}