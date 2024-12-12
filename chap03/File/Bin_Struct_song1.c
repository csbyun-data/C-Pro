// binary파일, 구조체를 이용한 입력, 저장
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TMAX 30
#define SMAX 15
#define AMAX 40

void main()
{
  struct {
    char title[TMAX];
    char singer[SMAX];
    char album[AMAX];
    char date[AMAX];
  }library;

  FILE* data, * binarydata;

  if ((data = fopen("song.in", "rt")) == NULL) {
    fprintf(stderr, "\nSON.IN not found!\n");
    exit(EXIT_FAILURE);
  }

  if ((binarydata = fopen("song.dat", "wb")) == NULL) {
    fprintf(stderr, "\nSONG.DAT can't be created!\n");
    exit(EXIT_FAILURE);
  }

  while (strlen(fgets(library.title, TMAX, data)) > 1) {     
    *strchr(library.title, '\n') = '\0';
    fgets(library.singer, SMAX, data);
    *strchr(library.singer, '\n') = '\0';
    fgets(library.album, AMAX, data);
    *strchr(library.album, '\n') = '\0';

    //fscanf(data, "%ld\n", &library.date);
    fgets(library.date, AMAX, data);
    *strchr(library.date, '\n') = '\0';

    if (fwrite(&library, sizeof(library), 1, binarydata) != 1) {
      fprintf(stderr, "\nDisk full!\n");
      exit(EXIT_FAILURE);
    }
  }
  exit(EXIT_SUCCESS);
}
