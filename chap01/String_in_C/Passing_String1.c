// Passing string to a Function
void displayString(char str[]);

int main()
{
  char str[50];
  printf("Enter string: ");
  fgets(str, sizeof(str), stdin);

  displayString(str); // Passing string to a function
}

void displayString( char str[]) {
  printf("String Output: ");
  puts(str);
}
