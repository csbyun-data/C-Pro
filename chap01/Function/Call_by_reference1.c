// call by reference ( pass by reference)
// C 사용안됨, C++에서 사용함
void swap( int &x, int &y) {
  int temp;
  temp = x;
  x = y;
  y = temp;
}

int main() 
{
  int a=10;
  int b=20;

  swap(a, b);
}
