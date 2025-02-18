#include <stdio.h>
#include <string.h>
#include "structfile.h"  // 이미 제공된 헤더 파일을 포함합니다

// 샘플 데이터로 블랙북 레코드 초기화
void initialize_blackbook_data(void) {
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
    
  int i;

  // 구조체 배열을 파일에 저장
  for (i = 0; i < 20; i++) {
    rec = sample_data[i];  // 현재 레코드를 샘플 데이터로 설정
    
    // 레코드를 파일에 추가
    if (datadd(&rec) == Success_) {
        printf("Record %d added successfully.\n", i + 1);
    } else {
        printf("Error adding record %d.\n", i + 1);
    }
  }
}

// 레코드를 파일에 추가하는 함수
int add_record(FILE *fsptr) {
  rec.delete_flag = 0;  // 활성 레코드 설정
  rec.recordnum = (int)(ftell(fsptr) / sizeof(struct blackbook));

  printf("Enter First Name: ");
  fgets(rec.firstname, sizeof(rec.firstname), stdin);
  rec.firstname[strcspn(rec.firstname, "\n")] = 0;

  printf("Enter Last Name: ");
  fgets(rec.lastname, sizeof(rec.lastname), stdin);
  rec.lastname[strcspn(rec.lastname, "\n")] = 0;

  printf("Enter Address: ");
  fgets(rec.addr, sizeof(rec.addr), stdin);
  rec.addr[strcspn(rec.addr, "\n")] = 0;

  printf("Enter City: ");
  fgets(rec.city, sizeof(rec.city), stdin);
  rec.city[strcspn(rec.city, "\n")] = 0;

  printf("Enter State: ");
  fgets(rec.state, sizeof(rec.state), stdin);
  rec.state[strcspn(rec.state, "\n")] = 0;

  printf("Enter Zip: ");
  fgets(rec.zip, sizeof(rec.zip), stdin);
  rec.zip[strcspn(rec.zip, "\n")] = 0;

  printf("Enter Phone: ");
  fgets(rec.phone, sizeof(rec.phone), stdin);
  rec.phone[strcspn(rec.phone, "\n")] = 0;

  if (fseek(fsptr, 0L, SEEK_END) != 0)
    return Error_;  // seek failure

  if (fwrite(&rec, sizeof(struct blackbook), 1, fsptr) != 1)
    return Error_;  // write error

  return Success_;
}

// 레코드를 수정하는 함수
int update_record(FILE *fsptr, long recnum) {
  if (data_read(recnum) != Success_)
    return Error_;

  printf("Modify Record %ld:\n", recnum);
  print_record(&rec);

  printf("Enter new First Name (or press Enter to keep current): ");
  fgets(rec.firstname, sizeof(rec.firstname), stdin);
  rec.firstname[strcspn(rec.firstname, "\n")] = 0;

  printf("Enter new Last Name (or press Enter to keep current): ");
  fgets(rec.lastname, sizeof(rec.lastname), stdin);
  rec.lastname[strcspn(rec.lastname, "\n")] = 0;

  printf("Enter new Address (or press Enter to keep current): ");
  fgets(rec.addr, sizeof(rec.addr), stdin);
  rec.addr[strcspn(rec.addr, "\n")] = 0;

  printf("Enter new City (or press Enter to keep current): ");
  fgets(rec.city, sizeof(rec.city), stdin);
  rec.city[strcspn(rec.city, "\n")] = 0;

  printf("Enter new State (or press Enter to keep current): ");
  fgets(rec.state, sizeof(rec.state), stdin);
  rec.state[strcspn(rec.state, "\n")] = 0;

  printf("Enter new Zip (or press Enter to keep current): ");
  fgets(rec.zip, sizeof(rec.zip), stdin);
  rec.zip[strcspn(rec.zip, "\n")] = 0;

  printf("Enter new Phone (or press Enter to keep current): ");
  fgets(rec.phone, sizeof(rec.phone), stdin);
  rec.phone[strcspn(rec.phone, "\n")] = 0;

  if (data_update() != Success_)
    return Error_;

  return Success_;
}

// 레코드를 삭제하는 함수
int delete_record(FILE *fsptr, long recnum) {
  if (data_read(recnum) != Success_)
    return Error_;

  rec.delete_flag = -1;  // 삭제된 레코드로 표시
  if (data_update() != Success_)
    return Error_;

  return Success_;
}

// 레코드를 조회하는 함수
void view_record(long recnum) {
  if (data_read(recnum) == Success_) {
    print_record(&rec);
  } else {
    printf("Record %ld not found.\n", recnum);
  }
}

int main(int argc, char *argv[])
{
  fsptr = open_file("blackbook.dat");
  if (fsptr == NULL) {
    printf("Error opening file.\n");
    return 1;
  }

  int choice;
  long recnum;

  while (1) {
    printf("\nMenu:\n");
    printf("0. Add 20 Records\n");        
    printf("1. Add Record\n");
    printf("2. View Record\n");
    printf("3. Update Record\n");
    printf("4. Delete Record\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    getchar();  // To consume newline character

    switch (choice) {
      case 0: 
        // 샘플 데이터를 초기화하여 파일에 저장
        initialize_blackbook_data();
        break;
      case 1:
        if (add_record(fsptr) == Success_)
            printf("Record added successfully.\n");
        else
            printf("Error adding record.\n");
        break;

      case 2:
        printf("Enter record number to view: ");
        scanf("%ld", &recnum);
        getchar();  // To consume newline character
        view_record(recnum);
        break;

      case 3:
        printf("Enter record number to update: ");
        scanf("%ld", &recnum);
        getchar();  // To consume newline character
        if (update_record(fsptr, recnum) == Success_)
          printf("Record updated successfully.\n");
        else
          printf("Error updating record.\n");
        break;

      case 4:
        printf("Enter record number to delete: ");
        scanf("%ld", &recnum);
        getchar();  // To consume newline character
        if (delete_record(fsptr, recnum) == Success_)
          printf("Record deleted successfully.\n");
        else
          printf("Error deleting record.\n");
        break;

      case 5:
        fclose(fsptr);
        return 0;

      default:
        printf("Invalid choice. Please try again.\n");
    }
  }

  return 0;
}
