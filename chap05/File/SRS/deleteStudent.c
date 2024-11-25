void deleteStudent()
{
    int found = 0;
    int studentDelete = 0;
    sFileHeader fileHeaderInfo = {0};
    s_StudentInfo addStudentInfoInDataBase = {0};
    FILE *fp = NULL;
    FILE *tmpFp = NULL;
    headMessage("Delete Student Details");
    fp = fopen(FILE_NAME,"rb");
    if(fp == NULL)
    {
        printf("File is not opened\n");
        exit(1);
    }
    tmpFp = fopen("tmp.bin","wb");
    if(tmpFp == NULL)
    {
        fclose(fp);
        printf("File is not opened\n");
        exit(1);
    }
    fread (&fileHeaderInfo,FILE_HEADER_SIZE, 1, fp);
    fwrite(&fileHeaderInfo,FILE_HEADER_SIZE, 1, tmpFp);
    printf("\n\t\t\tEnter Student ID NO. for delete:");
    scanf("%d",&studentDelete);
    while (fread (&addStudentInfoInDataBase, sizeof(addStudentInfoInDataBase), 1, fp))
    {
        if(addStudentInfoInDataBase.student_id != studentDelete)
        {
            fwrite(&addStudentInfoInDataBase,sizeof(addStudentInfoInDataBase), 1, tmpFp);
        }
        else
        {
            found = 1;
        }
    }
    (found)? printf("\n\t\t\tRecord deleted successfully....."):printf("\n\t\t\tRecord not found");
    fclose(fp);
    fclose(tmpFp);
    remove(FILE_NAME);
    rename("tmp.bin",FILE_NAME);
}
