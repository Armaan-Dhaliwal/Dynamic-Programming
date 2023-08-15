Given the dimension of a sequence of matrices in an array arr[], where the dimension of the ith matrix is (arr[i-1] * arr[i]), the task is to find the most efficient way to multiply these matrices together such that the total number of element multiplications is minimum.
 or 
Problem Statement: Matrix Chain Multiplication
Problem Level: HARD
Problem Description:
Given a chain of matrices A1, A2, A3,.....An, you have to figure out the most efficient way to multiply these matrices i.e. determine where to place parentheses to minimise the number of multiplications.
You will be given an array p[] of size n + 1. Dimension of matrix Ai is p[i - 1]*p[i]. You need to find minimum number of multiplications needed to multiply the chain.
Input Format :
Line 1 : Integer n i.e. number of matrices
Line 2 : n + 1 integers i.e. elements of array p[]

Output Format :
Line 1 : Minimum number of multiplication needed

Constraints :
1 <= n <= 100

Sample Input 1 :
3
10 15 20 25

Sample Output :
8000

Sample Output Explanation :
There are two ways to multiply the chain - A1*(A2*A3) or (A1*A2)*A3.
If multiply in order   A1*(A2*A3) then number of multiplications required are 15000.
If multiply in order   (A1*A2)*A3 then number of multiplications required are 8000.
Thus minimum number of multiplications required are 8000


