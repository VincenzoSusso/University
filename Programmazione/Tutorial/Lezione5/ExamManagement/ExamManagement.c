/*



 __          __  _____           ______
 \ \        / / |_   _|         |  ____|
  \ \  /\  / /    | |    _ __   | |__     _ __    ____   ___
   \ \/  \/ /     | |   | '_ \  |  __|   | '_ \  |_  /  / _ \
    \  /\  /     _| |_  | | | | | |____  | | | |  / /  | (_) |
     \/  \/     |_____| |_| |_| |______| |_| |_| /___|  \___/




*/

/*****************************************************************************************************************************************************
*                                                                                                                                                    *
*  Author : WinEnzo                                                                                                                                  *
*  Name : ExamManagement.c                                                                                                                           *
*  Purpose : The purpose of this program is to store and display information about each student that have done the Exam. To each student,            *
*            the exam should store information about the name, the surname, the grade of the written test, the grade of the oral test and            *     
*            the vote of the laboratory test.                                                                                                        *                        
*  Date : 11/12/2018                                                                                                                                 *
*                                                                                                                                                    *
*****************************************************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define MAX_STRING 100 //Max size of the strings
#define TOTAL_TEST 3 //The number of the total tests
#define MIN_CANDIDATES 0 //The number of the minimum candidates
#define MIN_TEST 0 //The grade minimum of the tests
#define MAX_TEST 30 //The grade maximum of the tests

//Data type user defined
typedef struct 
{
    char name[MAX_STRING];
    char surname[MAX_STRING];
    int written_test;
    int oral_test;
    int laboratory_test;
    int average_exam;
} Students_t;

//Function Prototypes
void introduction(void); //Used to print the introduction
int set_number_candidates(void); //Used to set the number of candidates
void set_candidates(const int n, Students_t candidate[]); //Used to set the information about candidates
void get_candidates(const int n, const Students_t candidate[]); //Used to print information about candidates

//Main
int main(void)
{
    //Variable
    int n = 0; //Used to store the number of students that have done the exam
    
    introduction();

    n = set_number_candidates(); //Used to set the number of candidates

    Students_t candidate[n]; //Defining a new variable (array of candidate)

    set_candidates(n, candidate); //Used to set informations about candidates
    get_candidates(n, candidate); //Used to print informations about candidates
    printf("\n");

    exit(EXIT_SUCCESS);
}

// -- Functions --
void introduction(void) //Used to print the introduction
{
    printf(
        " __          __  _____           ______\n"
        " \\ \\        / / |_   _|         |  ____|\n"
        "  \\ \\  /\\  / /    | |    _ __   | |__     _ __    ____   ___\n"
        "   \\ \\/  \\/ /     | |   | '_ \\  |  __|   | '_ \\  |_  /  / _ \\\n"
        "    \\  /\\  /     _| |_  | | | | | |____  | | | |  / /  | (_) |\n"
        "     \\/  \\/     |_____| |_| |_| |______| |_| |_| /___|  \\___/\n\n"
    );

    printf(
        "/********************************************************************************************************\n"
        "*  Author : WinEnzo                                                                                     *\n"
        "*  Name : ExamManagement.c                                                                              *\n"
        "*  Purpose : The purpose of this program is to store and display information about each student that    *\n"
        "*            have done the Exam. To each student, the exam should store information about the name,     *\n"
        "*            the surname, the grade of the written test, the grade of the oral test and the grade of    *\n"
        "*            the laboratory test.                                                                       *\n"
        "*  Date : 11/12/2018                                                                                    *\n"
        "********************************************************************************************************/\n\n"
    );
    //--------------------------------------

    //--------------------------------------
    printf("ExamManagement\n\n");
    //--------------------------------------
}

int set_number_candidates(void) //Used to set the number of candidates
{
    int n = 0;
    do
    {
        printf("Insert the number of student that have done the exam: ");
        scanf("%d", &n);
    }
    while(n < MIN_CANDIDATES);
    return n;
}

void set_candidates(const int n, Students_t candidate[]) //Used to set the information about the candidates
{
    for(int i = 0; i < n; i++)
    {
        printf("\n\aInsert the name of the %d^ candidate: ", i+1); //Input name
        scanf("%s", candidate[i].name);

        printf("Insert the surname of the %d^ candidate: ", i+1); //Input surname
        scanf("%s", candidate[i].surname);
        
        do //Input written test grade and check about the value of the variable
        {
            printf("Insert the grade of the written test of the %d^ candidate (Min %d / Max %d): ", i+1, MIN_TEST, MAX_TEST);
            scanf("%d", &candidate[i].written_test);
        }
        while((candidate[i].written_test < MIN_TEST) || (candidate[i].written_test > MAX_TEST));

        do //Input oral test grade and check about the value of the variable
        {
            printf("Insert the grade of the oral test of the %d^ candidate (Min %d / Max %d): ", i+1, MIN_TEST, MAX_TEST);
            scanf("%d", &candidate[i].oral_test);
        }
        while((candidate[i].oral_test < MIN_TEST) || (candidate[i].oral_test > MAX_TEST));

        do //Input laboratory test grade and check about the value of the variable
        {
            printf("Insert the grade of the laboratory test of the %d^ candidate (Min %d / Max %d): ", i+1, MIN_TEST, MAX_TEST);
            scanf("%d", &candidate[i].laboratory_test);
        }
        while((candidate[i].laboratory_test < MIN_TEST) || (candidate[i].laboratory_test > MAX_TEST));

        candidate[i].average_exam = (candidate[i].written_test + candidate[i].oral_test + candidate[i].laboratory_test) / TOTAL_TEST;
    }
}

void get_candidates(const int n,const Students_t candidate[]) //Used to print information about students
{
    for(int i = 0; i < n; i++)
    {
        printf("\n--------------------------------------------------------------------------");
        printf("\nInformation about %d^ student", i+1);
        printf("\nName of %d^ student: %s",i+1, candidate[i].name);
        printf("\nSurname of %d^ student: %s",i+1, candidate[i].surname);
        printf("\nGrade of the written test of %d^ student: %d",i+1, candidate[i].written_test);
        printf("\nGrade of the oral test of %d^ student: %d",i+1, candidate[i].oral_test);
        printf("\nGrade of the laboratory test of %d^ student: %d",i+1, candidate[i].laboratory_test);
        printf("\nAverage of the exam of %d^ student: %d",i+1, candidate[i].average_exam);
        printf("\n--------------------------------------------------------------------------");
    }
}