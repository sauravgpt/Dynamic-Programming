## General Format of MCM, right to change as per question's condition

func solve(A[], i, j){
  if(i>j) <!--May be change as per question requirement-->
    return 0;

  for(k=i; k<=j; k++){
    temp = solve(A, i, k) + solve(A, k+1, j) + (A[i-1] * A[k] * A[j]);
    answer = MAX/MIN(temp, answer);
  }
  return answer;
}

## Steps for MCM
1. Find right i and j values
2. Find right base condition
3. Move k -> i to j
4. Find extra cost (A[i-1] * A[k] * A[j])