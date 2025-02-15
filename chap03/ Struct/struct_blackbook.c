#include <stdio.h>
#include <string.h>
#include "strucfil.h"  // 이미 제공된 헤더 파일을 포함합니다

// 샘플 데이터로 블랙북 레코드 초기화
void initialize_blackbook_data(void)
{
    // 샘플 데이터 20개의 blackbook 레코드를 초기화
    struct blackbook sample_data[20] = {
        {0, 1, "John", "Doe", "123 Elm St", "Springfield", "IL", "62701", "5551234567"},
        {0, 2, "Jane", "Smith", "456 Oak St", "Chicago", "IL", "60601", "5552345678"},
        {0, 3, "Alice", "Johnson", "789 Pine St", "New York", "NY", "10001", "5553456789"},
        {0, 4, "Bob", "Brown", "101 Maple St", "Los Angeles", "CA", "90001", "5554567890"},
        {0, 5, "Charlie", "Davis", "202 Birch St", "Houston", "TX", "77001", "5555678901"},
        {0, 6, "Diana", "Miller", "303 Cedar St", "Phoenix", "AZ", "85001", "5556789012"},
        {0, 7, "Eve", "Wilson", "404 Willow St", "Philadelphia", "PA", "19101", "5557890123"},
        {0, 8, "Frank", "Moore", "505 Redwood St", "San Antonio", "TX", "78201", "5558901234"},
        {0, 9, "Grace", "Taylor", "606 Fir St", "San Diego", "CA", "92101", "5559012345"},
        {0, 10, "Henry", "Anderson", "707 Elm St", "Dallas", "TX", "75201", "5550123456"},
        {0, 11, "Ivy", "Thomas", "808 Pine St", "Austin", "TX", "73301", "5551231234"},
        {0, 12, "Jack", "Jackson", "909 Oak St", "Seattle", "WA", "98101", "5552342345"},
        {0, 13, "Kathy", "White", "101 Maple St", "Miami", "FL", "33101", "5553453456"},
        {0, 14, "Leo", "Harris", "202 Cedar St", "Chicago", "IL", "60602", "5554564567"},
        {0, 15, "Mona", "Clark", "303 Birch St", "Atlanta", "GA", "30301", "5555675678"},
        {0, 16, "Nancy", "Lewis", "404 Redwood St", "Denver", "CO", "80201", "5556786789"},
        {0, 17, "Oscar", "Walker", "505 Fir St", "Boston", "MA", "02101", "5557897890"},
        {0, 18, "Paul", "Young", "606 Elm St", "Portland", "OR", "97201", "5558908901"},
        {0, 19, "Quincy", "King", "707 Pine St", "Dallas", "TX", "75202", "5559019012"},
        {0, 20, "Rachel", "Scott", "808 Oak St", "Chicago", "IL", "60603", "5550120123"}
    };

    // 구조체 배열을 파일에 저장
    for (int i = 0; i < 20; i++) {
        rec = sample_data[i];  // 현재 레코드를 샘플 데이터로 설정

        // 레코드를 파일에 추가
        if (datadd() == Success_) {
            printf("Record %d added successfully.\n", i + 1);
        } else {
            printf("Error adding record %d.\n", i + 1);
        }
    }
}

int main(void)
{
    // 파일을 여는 함수
    FILE *file = open_file("blackbook.dat");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    // 샘플 데이터를 초기화하여 파일에 저장
    initialize_blackbook_data();

    // 파일을 닫고 프로그램 종료
    fclose(file);

    return 0;
}
