#include <stdio.h>
#include <stdlib.h>

//structure to store info
typedef struct UserInfo {
    int age;
    float height;
    char name[24];
} s_Userinfo;

//function to get user info
s_Userinfo Getinfo(void) {
    s_Userinfo info = {0}; // structure variable
    printf("\n\n Enter User age = ");
    scanf("%d",&info.age);
    printf("\n\n Enter User height = ");
    scanf("%f",&info.height);
    printf("\n\n Enter User name = ");
    scanf("%s",info.name);
    return info;
}

int main()
{
    //structure variable
    s_Userinfo info = {0};
  
    //Get user info
    info = Getinfo();
    printf("\n User age = %d",info.age);
    printf("\n User height = %f",info.height);
    printf("\n User name = %s",info.name);

    return 0;
}

// run result
// Enter User age = 10
// Enter User height = 180
// Enter User name = C.S.Byun

// User age = 10
// User height = 180.000000
// User name = C.S.Byun
