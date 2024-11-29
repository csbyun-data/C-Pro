//COS Pro1 4-4예제

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

const int n = 4;

typedef struct {
    int first;
    int second;
} _pair;

int* find_not_exist_nums(int matrix[][n]) {
    int *nums = (int*)malloc(sizeof(int)*(2));
    int nums_n = 0;
    bool exist[n * n + 1] = {false};
    int i, j;
  
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (matrix[i][j] != 0) {
                exist[matrix[i][j]] = true;
            }
        }
    }
    for (i = 1; i <= n * n; i++) {
        if (!exist[i]) {
            nums[nums_n++] = i;
        }
    }
    return nums;
}

_pair *find_blank_coords(int matrix[][n]) {
    _pair* coords = (_pair*)malloc(sizeof(_pair)*(2));
    int coords_n = 0;
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (matrix[i][j] == 0) {
                coords[coords_n].first = i;
                coords[coords_n++].second = j;
            }
        }
    }
    return coords;
}

bool is_magic_square(int matrix[][n]) {
    int i, j;
    int sum = 0;
    for (i = 1; i <= n * n; i++) {
        sum += i;
    }
    sum = sum / n;
    for (i = 0; i < n; i++) {
        int row_sum = 0;
        int col_sum = 0;
        for (j = 0; j < n; j++) {
            row_sum += matrix[i][j];
            col_sum += matrix[j][i];
        }
        if (row_sum != sum) {
            return false;
        }
        if (col_sum != sum) {
            return false;
        }
    }
    int main_diagonal_sum = 0;
    int skew_diagonal_sum = 0;
    for (i = 0; i < n; i++) {
        main_diagonal_sum += matrix[i][i];
        skew_diagonal_sum += matrix[i][n-1-i];
    }
    if (main_diagonal_sum != sum) {
        return false;
    }
    if (skew_diagonal_sum != sum) {
        return false;
    }
    return true;
}

int* solution(int matrix[][n]) {
    int* answer = (int*)malloc(sizeof(int) * 6);
    int ans_n = 0;

    _pair* coords = find_blank_coords(matrix);
    int* nums = find_not_exist_nums(matrix);

    matrix[coords[0].first][coords[0].second] = nums[0];
    matrix[coords[1].first][coords[1].second] = nums[1];
    if (is_magic_square(matrix)) {
        for (int i = 0; i <= 1; i++) {
            answer[ans_n++] = coords[i].first + 1;
            answer[ans_n++] = coords[i].second + 1;
            answer[ans_n++] = nums[i];
        }
    } else {
        matrix[coords[0].first][coords[0].second] = nums[1];
        matrix[coords[1].first][coords[1].second] = nums[0];
        for (int i = 0; i <= 1; i++) {
            answer[ans_n++] = coords[1-i].first + 1;
            answer[ans_n++] = coords[1-i].second + 1;
            answer[ans_n++] = nums[i];
        }
    }
    return answer;
}

int main() {
    int matrix[4][4] = {{16,2,3,13},{5,11,10,0},{9,7,6,12},{0,14,15,1}};
    int* ret = solution(matrix);
    
    for (int i = 0; i < 6; i++) {
        if (i != 0) printf(", ");
        printf("%d", ret[i]);
    }
}

//solution 함수의 반환 값은 {4, 1, 4, 2, 4, 8} 입니다.
