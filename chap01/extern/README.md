## 1.static, extern 사용 방법
### INDEX
* 1.static 변수 사용 [code](https://github.com/csbyun-data/C-Pro/blob/main/chap01/extern/static1.c)
  ```txt
  파일 내부에서 사용, 함수의 상태를 기록하기 위해 사용
  ```
* 2.extern 변수, 함수 사용 [[cnt.h](https://github.com/csbyun-data/C-Pro/blob/main/chap01/extern/cnt.h), [cnt.c](https://github.com/csbyun-data/C-Pro/blob/main/chap01/extern/cnt.c), [main.c](https://github.com/csbyun-data/C-Pro/blob/main/chap01/extern/main.c)]
  ```txt
  다른 파일에서 접근 가능하고, 전역 변수, 함수 접근 제공
  ```
* 3.static 변수, 함수, extern변수, 함수 사용 [[cnt1.h](https://github.com/csbyun-data/C-Pro/blob/main/chap01/extern/cnt1.h), [cnt1.c](https://github.com/csbyun-data/C-Pro/blob/main/chap01/extern/cnt1.c), [main1.c](https://github.com/csbyun-data/C-Pro/blob/main/chap01/extern/main1.c)]
  ```txt
  1) static 변수를 cnt2()함수는 함수가 선언된 파일 cnt.c 안에서 siCnt의 값은 변경
     main.c 파일 안에서 siCnt의 값은 변경하지 않는다
  2) static 변수가 선언된 "cnt.h"파일을 code파일에 포함해야 error가 발생하지 않는다
     error 예: [Error] 'siCnt' undeclared (first use in this function)
  ```
  
