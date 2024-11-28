
## 01. Sorting
### Index
* 1.Sorting 정리
  * 1.1 Bubble Sort in C [code](https://github.com/csbyun-data/C-Pro/blob/main/chap04/Sorting/BubbleSort1.c)
  * 1.2 Bubble Sort 최적화 [code](https://github.com/csbyun-data/C-Pro/blob/main/chap04/Sorting/BubbleSort2.c)
  ```c
  내부 loop문에서 교환하는 data가 없는 경우 외부loop를 중단해 최적화
  ```
  * 1.3 Iterative Quick Sort [code c++](https://github.com/csbyun-data/C-Pro/blob/main/chap04/Sorting/Iterative_Quick_Sort1.cpp), [code1 c](https://github.com/csbyun-data/C-Pro/blob/main/chap04/Sorting/Iterative_recursive_Quick_Sort1.c), [code1 c++](https://github.com/csbyun-data/C-Pro/blob/main/chap04/Sorting/Iterative_recursive_Quick_Sort1.cpp), [code1 java](https://github.com/csbyun-data/C-Pro/blob/main/chap04/Sorting/Iterative_recursive_Quick_sort1.java)
  * ([참조: geeksforgeeks.org/iterative-quick-sort](https://www.geeksforgeeks.org/iterative-quick-sort/) )
  * ([참조: geeksforgeeks.org/quick-sort-algorithm](https://www.geeksforgeeks.org/quick-sort-algorithm/) )
  
  ```txt
  1) 위의 구현은 마지막 인덱스를 피벗으로 사용합니다.이는 일반적으로 발생하는 경우인 이미 정렬된 배열에서 최악의 동작을
  일으킵니다.피벗에 대한 임의 인덱스를 선택하거나 파티션의 중간 인덱스를 선택하거나 피벗에 대한 파티션의 첫 번째, 중간
  및 마지막 요소의 중간값을 선택하면 문제를 해결할 수 있습니다.
  
  2) 재귀 깊이를 줄이려면 먼저 배열의 작은 절반에 대해 재귀하고 tail 호출을 사용하여 다른 절반으로 재귀합니다.
  3) 삽입 정렬은 작은 부분 배열에 더 잘 작동합니다.삽입 정렬은 이러한 작은 배열(즉, 길이가 실험적으로 결정된 임계값
  t보다 작은 경우)에 대한 호출에 사용할 수 있습니다.예를 들어, Quicksort의  이 라이브러리 구현은 크기 7 미만의
  삽입 정렬을 사용합니다.
    위의 최적화에도 불구하고 함수는 재귀적으로 유지되고 함수 호출 스택을 사용하여 l 및 h의 중간 값을 저장합니다.
    함수 호출 스택은 매개변수와 함께 다른 회계 정보를 저장합니다. 또한 함수 호출에는 호출자 함수의 활성화 레코드를
  저장한 다음 실행을 재개하는 것과 같은 오버헤드가 포함됩니다.
  위의 함수는 보조 스택의 도움으로 반복 버전으로 쉽게 변환할 수 있습니다. 다음은 위의 재귀 코드의 반복 구현입니다. 
  ```
  * 1.4 Advanced Quick Sort (Hybrid Algorithm)
  * ([참조: geeksforgeeks.org/advanced-quick-sort-hybrid-algorithm](https://www.geeksforgeeks.org/advanced-quick-sort-hybrid-algorithm/) )
  


