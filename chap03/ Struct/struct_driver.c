#include <stdio.h>
#include <string.h>
#include "strucfil.h"  // 이미 제공된 헤더 파일을 포함합니다

// 데이터 파일을 여는 함수
FILE *open_file(char *filename) {
    FILE *fsptr = NULL;
    if (access(filename, 0) == 0)  // 파일이 있으면
        fsptr = fopen(filename, "rb+");  // 읽기/쓰기 모드
    else
        fsptr = fopen(filename, "wb+");  // 없으면 새로 생성
    return fsptr;
}

// 레코드를 출력하는 함수
void print_record(struct blackbook *record) {
    printf("Record Number: %d\n", record->recordnum);
    printf("First Name: %s\n", record->firstname);
    printf("Last Name: %s\n", record->lastname);
    printf("Address: %s\n", record->addr);
    printf("City: %s\n", record->city);
    printf("State: %s\n", record->state);
    printf("Zip: %s\n", record->zip);
    printf("Phone: %s\n", record->phone);
    printf("----------------------------\n");
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
void view_record(FILE *fsptr, long recnum) {
    if (data_read(recnum) == Success_) {
        print_record(&rec);
    } else {
        printf("Record %ld not found.\n", recnum);
    }
}

int main(void) {
    FILE *fsptr = open_file("blackbook.dat");
    if (fsptr == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    int choice;
    long recnum;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Add Record\n");
        printf("2. View Record\n");
        printf("3. Update Record\n");
        printf("4. Delete Record\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // To consume newline character

        switch (choice) {
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
                view_record(fsptr, recnum);
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
