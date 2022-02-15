#include <stdio.h>
int main()
{
  int number1, number2;
  printf("Enter a number:\n");
  scanf("%d",&number1);
  printf("Enter a second number:\n");
  scanf("%d",&number2);
  int number3 = (number1%number2);
  printf("%d mod %d = %d\n",number1,number2,number3);
  number3 = (number1/number2);
  printf("%d div %d = %d\n",number1,number2,number3);
  return 0;
}
