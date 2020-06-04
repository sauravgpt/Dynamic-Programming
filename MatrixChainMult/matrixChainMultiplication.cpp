#include <bits/stdc++.h>
using namespace std;

long T[501][501];

long MCM(int A[], int i, int j)
{

  long ans = LONG_MAX;

  if (i >= j)
    return 0;

  for (int k = i; k < j; k++)
  {
    
    long temp = MCM(A, i, k) + MCM(A, k + 1, j) + (A[i - 1] * A[k] * A[j]);
    ans = min(ans, temp);
  }
  return ans;
}

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    memset(T, -1, sizeof(T));
    int n;
    cin >> n;
    int arr[n];
    for (int &i : arr)
      cin >> i;
    cout << MCM(arr, 1, n - 1) << "\n";
  }
}