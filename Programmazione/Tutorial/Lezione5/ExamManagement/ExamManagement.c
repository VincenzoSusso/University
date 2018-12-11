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
} Students;

//Function Prototypes
void introduction(void); //Used to print the introduction
int set_number_candidates(void); //Used to set the number of candidates
void set_candidates(Students *candidate[], int n); //Used to set the information about candidates
void get_candidates(Students candidate[], int n); //Used to print information about students

//Main
int main(void)
{
    //Variable
    int n = 0; //Used to store the number of students that have done the exam
    
    introduction();

    n = set_number_candidates(); //Used to set the number of candidates

    Students candidate[n]; //Defining a new variable (array of candidate)

    printf("\n");
    set_candidates(&candidate, n); //Used to give information about students
    get_candidates(candidate, n); //Used to print information about students

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

void set_candidates(Students *candidate[], int n) //Used to set the information about the candidates
{
    for(int i = 0; i < n; i++)
    {
        printf("Insert the name of the %d^ candidate: ", i+1);
        scanf("%s", candidate[i] -> name);

        printf("Insert the surname of the %d^ candidate", i+1);
        scanf("%s", candidate[i] -> surname);

        printf("Insert the grade of the written test of the %d^ candidate (Min %d / Max %d): ", i+1, MIN_TEST, MAX_TEST);
        scanf("%d", &candidate[i] -> written_test);

        printf("Insert the grade of the oral test of the %d^ candidate (Min %d / Max %d): ", i+1, MIN_TEST, MAX_TEST);
        scanf("%d", &candidate[i] -> oral_test);

        printf("Insert the grade of the laboratory test of the %d^ candidate (Min %d / Max %d): ", i+1, MIN_TEST, MAX_TEST);
        scanf("%d", &candidate[i] -> laboratory_test);

        candidate[i] -> average_exam = (candidate[i] -> written_test + candidate[i] -> oral_test + candidate[i] -> laboratory_test) / TOTAL_TEST;
    }
}

void get_candidates(Students candidate[], int n) //Used to print information about students
{
    for(int i = 0; i < n; i++)
    {
        printf("--------------------------------------------------------------------------------------------------");
        printf("Information about %d student: ", i+1);
        printf("Name of %d student: %s",i+1, candidate[i].name);
        printf("Surname of %d student: %s",i+1, candidate[i].surname);
        printf("Grade of the written test of %d student: %d",i+1, candidate[i].written_test);
        printf("Grade of the oral test of %d student: %d",i+1, candidate[i].oral_test);
        printf("Grade of the laboratory test of %d student: %d",i+1, candidate[i].laboratory_test);
        printf("Average of the Exam of %d student: %d",i+1, candidate[i].oral_test);
        printf("--------------------------------------------------------------------------------------------------");
    }
}