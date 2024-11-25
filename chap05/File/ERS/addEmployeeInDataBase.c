void addEmployeeInDataBase()
{
    s_EmployeesInfo addEmployeeInfoInDataBase = {0};
    FILE *fp = NULL;
    int status = 0;
    fp = fopen(FILE_NAME,"ab+");
    if(fp == NULL)
    {
        printf("File is not opened\n");
        exit(1);
    }
    headMessage("ADD NEW EMPLOYEES");
    printf("\n\n\t\t\tENTER YOUR DETAILS BELOW:");
    printf("\n\t\t\t---------------------------------------------------------------------------\n");
    printf("\n\t\t\tEmployee ID  = ");
    fflush(stdin);
    scanf("%u",&addEmployeeInfoInDataBase.employee_id);
    do
    {
        printf("\n\t\t\tFather Name  = ");
        fflush(stdin);
        fgets(addEmployeeInfoInDataBase.fatherName,MAX_FATHER_NAME,stdin);
        status = isNameValid(addEmployeeInfoInDataBase.fatherName);
        if (!status)
        {
            printf("\n\t\t\tName contain invalid character. Please enter again.");
        }
    }
    while(!status);
    do
    {
        printf("\n\t\t\tEmployee Name  = ");
        fflush(stdin);
        fgets(addEmployeeInfoInDataBase.employeeName,MAX_EMPLOYEE_NAME,stdin);
        status = isNameValid(addEmployeeInfoInDataBase.employeeName);
        if (!status)
        {
            printf("\n\t\t\tName contain invalid character. Please enter again.");
        }
    }
    while(!status);
    do
    {
        printf("\n\t\t\tEmployee Address  = ");
        fflush(stdin);
        fgets(addEmployeeInfoInDataBase.employeeAddr,MAX_FATHER_NAME,stdin);
        status = isNameValid(addEmployeeInfoInDataBase.employeeAddr);
        if (!status)
        {
            printf("\n\t\t\tName contain invalid character. Please enter again.");
        }
    }
    while(!status);
    printf("\n\t\t\tEmployee Salary  = ");
    fflush(stdin);
    scanf("%f",&addEmployeeInfoInDataBase.employeeSalary);
    do
    {
        //get date year,month and day from user
        printf("\n\t\t\tEnter date in format (day/month/year): ");
        scanf("%d/%d/%d",&addEmployeeInfoInDataBase.employeeJoiningDate.dd,&addEmployeeInfoInDataBase.employeeJoiningDate.mm,&addEmployeeInfoInDataBase.employeeJoiningDate.yyyy);
        //check date validity
        status = isValidDate(&addEmployeeInfoInDataBase.employeeJoiningDate);
        if (!status)
        {
            printf("\n\t\t\tPlease enter a valid date.\n");
        }
    }
    while(!status);
    fwrite(&addEmployeeInfoInDataBase,sizeof(addEmployeeInfoInDataBase), 1, fp);
    fclose(fp);
}
