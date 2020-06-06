int ans = 0;

int function(int x, int y)
{
  return x + y;
}

int solve(int arr[], int i, int j)
{
  if (i <= j)
  {
    for (int k = i; k < j; k++)
    {
      int temp = solve(arr, i, k) + solve(arr, k + 1, j) cost(/* ------ */);
      ans = function(temp, ans);
    }
  }
}
