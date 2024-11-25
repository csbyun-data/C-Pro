// search employee
void searchEmployee()
{
    int found = 0;
    int employeeId =0;
    s_EmployeesInfo addEmployeeInfoInDataBase = {0};
    FILE *fp = NULL;
    fp = fopen(FILE_NAME,"rb");
    if(fp == NULL)
    {
        printf("\n\t\t\tFile is not opened\n");
        exit(1);
    }
    headMessage("SEARCH EMPLOYEE");
    //put the control on employee detail
    if (fseek(fp,FILE_HEADER_SIZE,SEEK_SET) != 0)
    {
        fclose(fp);
        printf("\n\t\t\tFacing issue while reading file\n");
        exit(1);
    }
    printf("\n\n\t\t\tEnter employee ID NO to search:");
    fflush(stdin);
    scanf("%u",&employeeId);
    while (fread (&addEmployeeInfoInDataBase, sizeof(addEmployeeInfoInDataBase), 1, fp))
    {
        if(addEmployeeInfoInDataBase.employee_id == employeeId)
        {
            found = 1;
            break;
        }
    }
    if(found)
    {
        printf("\n\t\t\tEmployee id = %d\n",addEmployeeInfoInDataBase.employee_id);
        printf("\n\t\t\tEmployee name = %s",addEmployeeInfoInDataBase.employeeName);
        printf("\t\t\tEmployee Salary = %f\n",addEmployeeInfoInDataBase.employeeSalary);
        printf("\t\t\tFather Name = %s",addEmployeeInfoInDataBase.fatherName);
        printf("\n\t\t\tEmployee Address = %s",addEmployeeInfoInDataBase.employeeAddr);
        printf("\t\t\tEmployee Admission Date(day/month/year) =  (%d/%d/%d)",addEmployeeInfoInDataBase.employeeJoiningDate.dd,
               addEmployeeInfoInDataBase.employeeJoiningDate.mm, addEmployeeInfoInDataBase.employeeJoiningDate.yyyy);
    }
    else
    {
        printf("\n\t\t\tNo Record");
    }
    fclose(fp);
    printf("\n\n\n\t\t\tPress any key to go to main menu.....");
    fflush(stdin);
    getchar();
}
