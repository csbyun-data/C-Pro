/* 2.8-1 */
#include <stdio.h>
#include "increment.h"
#include "negate.h"

int main( void ) {
  printf("increment( 10 ) : %d\n", increment( 10 ));
  printf("increment( 0 ) : %d\n", increment( 0 ));
  printf("increment( -10 ) : %d\n", increment( -10 ));
  printf("negate( 10 ) : %d\n", negate( 10 ));
  printf("negate( 0 ) : %d\n", negate( 0 ));
  printf("negate( -10 ) : %d\n", negate( -10 ));
  return 0;
}
