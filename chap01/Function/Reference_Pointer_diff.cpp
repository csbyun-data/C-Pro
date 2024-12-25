// Reference Variable과 Pointer Variable의 차이
#include <iostream>

using namespace std;

struct demo {
  int a;
};

int main()
{
  int x = 5;
  int y = 6;
  demo d;
  
  int *p;    // Pointer Variable 선언
  p = &x;
  p = &y; 		// 1. Pointer reinitialzation allowd
  
  int &r= x;		// &r = y; 1. Compile Error, Reference Variable 선언
  r = y;			// 1. x value becomes 6
  p = NULL;		// &r = y; 2. Compile Error, 포인터 변수는 NULL이 대입 됨, 참조 변수는 NULL이 입력안됨, 문법이 Error나지 않게 정해짐
  
  //3. Pointers to next memory location
  p++;
  
  //3. x values becomes 7
  r++;
  
  cout << &p << " " << &x << '\n'; 	//4. Different address 
  cout << &r << " " << &x << '\n';	//4. Same address
  
  demo* q	 = &d;
  demo& qq = d;
  
  q->a = 8;		// q.a = 8; 5.Comple Error
  qq.a = 8;		// qq->a = 8; 5. Comple Error
  
  // 6. Prints the address
  cout << p << '\n';
  // 6. Print the value of x
  cout << r << '\n';
  
  return 0;
}

//run Result
//0x6ffde8 0x6ffe04
//0x6ffe04 0x6ffe04
//0x4
//7
