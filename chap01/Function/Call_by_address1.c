// call by address (pass by address)
// C언어 호칭 Call by address (Call by reference)
// C++ 호칭 (Call by pointer) 방식

void swap( int *x, int *y) {
  int temp;
  temp = *x;
  *x = *y;
  *y = temp;
}

int main() 
{
  int a=10;
  int b=20;

  swap( &a, &b);
  
  printf("%d, %d", a, b);
}
