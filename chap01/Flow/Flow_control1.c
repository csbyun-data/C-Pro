#include <stdio.h>

int main()
{
  int n1, n2;
	
  printf("Enter two integers: ");
  scanf("%d %d", &n1, &n2);
	
  if(n1 == n2) {
    printf("n1 = n2"); 
  } else if(n1 > n2) {
    printf("n1 > n2");
  } else {
    printf("n1 < n2");
  }
  
  return 0;
}
