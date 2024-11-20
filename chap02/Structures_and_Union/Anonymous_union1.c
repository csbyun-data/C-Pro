//익명의 union 사용
#include <stdio.h>
struct ColourCode {
  // Anonymous union
  union {
    char m_char;
    unsigned int m_asciiCode;
  };
};

int main()
{
  struct ColourCode asciiCode, ch;
  asciiCode.m_asciiCode = 65;
  ch.m_char = 'A';
  
  /*Note that members of union are
  accessed directly with struct name*/
  printf("ch.m_char = %c\n", ch.m_char);
  printf("asciiCode.m_asciiCode = %d",asciiCode.m_asciiCode);

  return 0;
}
// output:
// ch.m_char = A
// asciiCode.m_asciiCode = 65
