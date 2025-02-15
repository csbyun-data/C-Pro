#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "strucfil.h"  // 이미 제공된 헤더 파일을 포함합니다

// 파일을 열고 레코드를 읽어 새로운 파일에 복사하여 빈 공간을 없애는 함수
int remove_deleted_records(FILE *fsptr, const char *filename) {
    FILE *temp_file = fopen("temp.dat", "wb+");
    if (temp_file == NULL) {
        printf("Error opening temporary file.\n");
        return Error_;
    }

    struct blackbook temp_record;
    fseek(fsptr, 0L, SEEK_SET);  // 파일 처음으로 설정

    // 파일에서 모든 레코드를 읽어서 delete_flag가 0인 레코드만 새 파일로 복사
    while (fread(&temp_record, sizeof(struct blackbook), 1, fsptr) == 1) {
        if (temp_record.delete_flag == 0) {
            // 삭제되지 않은 레코드를 새 파일에 기록
            if (fwrite(&temp_record, sizeof(struct blackbook), 1, temp_file) != 1) {
                printf("Error writing to temporary file.\n");
                fclose(temp_file);
                return Error_;
            }
        }
    }

    // 기존 파일을 닫고, 새로 복사된 파일을 기존 파일로 덮어쓰기
    fclose(fsptr);
    fclose(temp_file);

    // 기존 파일을 삭제하고 새 파일을 기존 이름으로 변경
    if (remove(filename) != 0) {
        printf("Error removing the old file.\n");
        return Error_;
    }

    if (rename("temp.dat", filename) != 0) {
        printf("Error renaming temporary file.\n");
        return Error_;
    }

    printf("Deleted records removed successfully.\n");
    return Success_;
}

// 테스트용으로 데이터 추가 후 삭제된 레코드 제거하는 예시
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
        printf("2. Remove Deleted Records\n");
        printf("3. Exit\n");
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
                if (remove_deleted_records(fsptr, "blackbook.dat") == Success_)
                    printf("Deleted records removed and file size optimized.\n");
                else
                    printf("Error removing deleted records.\n");
                break;

            case 3:
                fclose(fsptr);
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
