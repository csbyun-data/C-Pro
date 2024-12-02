#include <stdio.h>

typedef void(*ft)(void);
#define FUNCTYPE_LEN    3u

static ft fp = 0ul;

void f00(void) {
  fp = f00;
  printf("[info] f00 addr:0x%p\r\n", f00);
}

void f01(void) {
  fp = f01;
  printf("[info] f01 addr:0x%p\r\n", f01);
}

static ft ft_list[FUNCTYPE_LEN] = {
  f00, f01, (ft)NULL,
};

int main(int argc, char* argv[]) {
  for(unsigned int ui=0u; ui<FUNCTYPE_LEN; ui++) {
    fp = (ft)NULL;
    printf("[info] idx:%02u, in list func addr:0x%p\n", ui, ft_list[ui]);
        
    if(ft_list[ui] != (ft)NULL) {
      ft_list[ui]();
    } else {
      printf("[info] fp is NULL(=0x%p)\n", ft_list[ui]);
    }
        
    printf("[info] call function is \"%s\"\n", (fp == ft_list[ui]?"OK":"NOT OK"));
  }
  return 0;
}

// run result
// [info] idx:00, in list func addr:0x0000000000401530
// [info] f00 addr:0x0000000000401530
// [info] call function is "OK"
// [info] idx:01, in list func addr:0x0000000000401560
// [info] f01 addr:0x0000000000401560
// [info] call function is "OK"
// [info] idx:02, in list func addr:0x0000000000000000
// [info] fp is NULL(=0x0000000000000000)
// [info] call function is "OK"
