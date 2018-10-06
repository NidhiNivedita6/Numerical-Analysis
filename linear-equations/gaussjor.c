#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/********* DEFINED CONSTANTS *********/
#define MAX        15
#define MAXC       0

/********* FUNCTION DECLARATION *********/
void gaussj(float co[MAX][MAX+1], float con[MAX], int n);

/********* MAIN STARTS HERE *********/
int main(void)
{
   int         i = 0, j, n;             //Declaration of variables in int
   float       co[MAX][MAX+1], con[MAX]; //Declaration of arrays in float

   // Input Section
   printf("Enter the order of matrix:- ");
   scanf("%d", &n);

   while (i < n)  //Check condition
   {
      printf("Enter Equation no. %d\n", i+1);
      for (j = 0; j < n; j++)
      {
         printf("Enter the co-efficient of x%d:- ", j+1);
         scanf("%f", &co[i][j]);
      }
      printf("Enter the value:- ");
      scanf("%f", &con[i]);
      printf("\n");
      i++;  // Incrementing i
   }

   gaussj(co, con, n);  //Calling function
   exit(0);
}

void gaussj(float co[MAX][MAX+1], float con[MAX], int n)
{
   int        i, j, k = 0; //Declaration of variables in int
   float      sol[MAX];    //Declaration of arrays in float
   float      val;         //Declaation of variables in float

   for (i = 0; i < n; i++)
   {
      co[i][n] = con[i];
   }

   while (k < n)
   {
      for (i = 0; i < n; i++)
      {
         if (i == k)
         {
            continue;
         }
         val = co[i][k]/co[k][k];
         for (j = 0; j < n+1; j++)
         {
            co[i][j] = (co[i][j]-val*co[k][j]);
         }
      }
      k++;
   }

   for (i = 0; i < n; i++)
   {
      sol[i] = co[i][3]/co[i][i];
      printf("Value of x%d is %f\n", i+1, sol[i]);
   }
   return ;
}
