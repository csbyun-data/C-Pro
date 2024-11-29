//COS Pro1 1-3문제
// 123+12 결과값을 구함 구조체 반환 함수 활용법 점검
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include <string.h> //strlen()함수 활용

typedef struct Pair{
    int first_num;
    int second_num;
} Pair;

int func_a(int numA, int numB, char exp){
    if (exp == '+')
        return numA + numB;
    else if (exp == '-')
        return numA - numB;
    else
        return numA * numB;
}

int func_b(char* exp){
    int len = strlen(exp);
    for(int i = 0; i < len; ++i){
        char e = exp[i];
        if(e == '+' || e == '-' || e == '*')
            return i;
    }
    return -1;
}

Pair func_c(char* exp, int idx){
    Pair ret;
    char first_num[10] = {0};
    char second_num[10] = {0};
    strncpy(first_num, exp, idx);
    strncpy(second_num, exp+idx+1,strlen(exp) - idx);
    ret.first_num = atoi(first_num);
    ret.second_num = atoi(second_num);
    return ret;
}

int solution(char* expression) {
    int exp_index = func_b(expression);
    Pair numbers = func_c(expression, exp_index);
    int result = func_a(numbers.first_num, numbers.second_num, expression[exp_index]);
    return result;
}

// The following is main function to output testcase.
int main() {
    char expression[7] = "123+12";
    int ret = solution(expression);

    // Press Run button to receive output. 
    printf("Solution: return value of the function is %d .\n", ret);
}
​
