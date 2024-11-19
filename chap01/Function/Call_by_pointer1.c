// the pass by pointer in function

void modifyVal ( int *myptr) {
  *myptr = *myptr + 5;
}

int main() {
  int x=5;
  int *myptr = &x;

  modifyVal(myptr);

  printf("Modified value of x is : %d \n");
}
