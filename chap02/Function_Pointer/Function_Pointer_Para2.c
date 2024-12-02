// 여러개의 함수들을 unitTest하기 위한 logic
// Use for unitest

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef void (*UnitTestFunction)(void);

static void test_1( void) {
  printf("run test_1\n");
}

static void test_2( void) {
  printf("run test_2\n");
}

static void run_test( UnitTestFunction test) {
  test();
}

void run_tests( UnitTestFunction *tests) {
  int i;

  for (i=0; tests[i] != NULL; ++i) {
    run_test(tests[i]);
  }
}

static UnitTestFunction tests[] = {
	test_1, test_2, NULL };

int main(int argc, char *argv[])
{
  run_tests(tests);
}
