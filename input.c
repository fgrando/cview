int addition(int num1, int num2)
{
     int sum
     /* Arguments are used here*/
     sum = num1+num2;

     /* function return type is integer so I should return some
     integer value */
     return sum
}

int main()
{
     int var1, var2;
     printf("enter number 1: ");
     scanf("%d",&var1);
     printf("enter number 2: ");
     scanf("%d",&var2);

     /* calling function – function return type is integer so I would be 
      * needing to store the returned value in some integer variable */
     int res = addition(var1, var2);
     printf ("Output: %d", res);

     return 0;
}