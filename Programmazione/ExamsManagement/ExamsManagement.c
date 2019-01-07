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
*  Name : ExamsManagement.c                                                                                                                          *
*  Purpose : The purpose of this program is to manage the exams of two degree courses (Computer Science / Digital Comunication). To each candidates  *
*            the program should store informations about name, surname, course, the grade of the exam and the year when the candidate has done the   *
*            exam than the program should sort the students using the grade. The program should store informations into a file and should give the   *
*            possibility to the user to search the candidates that has get a grade specified in input or to search the candidates that has get a     *
*            grade lower than a grade specified in input.                                                                                            *
*  Date : 04/01/2019                                                                                                                                 *
*                                                                                                                                                    *
*****************************************************************************************************************************************************/

// -- Libraries --
#include <stdlib.h>
#include <stdio.h>
#include "Introduction.h"
#include "ExamsManagement.h"

// -- Main --
int main(void)
{
    int n_candidates = 0, grade = 0; /* 1 -->Used to store the number of candidates
                                        2 --> Used to store the grade to search */
    Candidate_t candidate[MAXCANDIDATES]; //Used to store an array of candidates

    introduction(); //Used to print the introduction

    do
    {
        menu(); //Used to print the menu
        switch(getChooseMenu()) //Used to select an option of the menu
        {
            case INSERT_CANDIDATES:
                printf("\n--- INSERT CANDIDATES ---\n");
                n_candidates = setNCandidates(); //Used to set the number of candidates
                setCandidates(candidate, n_candidates); //Used to set information about candidates
                sortCandidates(candidate, n_candidates); //Used to sort the candidates
            break;

            case READ_CANDIDATES:
                printf("\n--- READ CANDIDATES ---\n");
                getCandidates(candidate, n_candidates); //Used to print information about candidates
            break;

            case LOAD_CANDIDATES_FILE:
                printf("\n--- LOAD CANDIDATES FROM FILE ---\n");
                n_candidates = getSizeFile(); //Used to read the dimension of the vector from the file
                readFile(candidate, n_candidates); //Used to read the vector of candidate from the file
            break;

            case SAVE_CANDIDATES_FILE:
                printf("\n--- SAVE CANDIDATES INTO A FILE ---\n");
                writeFile(candidate, n_candidates); //Used to write the vector of candidate in a file
            break;

            case SEARCH_GRADE_CANDIDATE:
                printf("\n--- SEARCH CANDIDATE'S GRADE ---\n");
                grade = setGradeSearch(); //Used to set the grade to search
                getCandidateGrade(candidate, n_candidates, grade); //Used to get the information about candidates that have got a specified grade
            break;

            case SEARCH_GRADE_CANDIDATE_LESS:
                printf("\n--- SEARCH CANDIDATE'S GRADE (LESS) ---\n");
                grade = setGradeSearch(); //Used to set the grade to search
                getCandidateLessGrade(candidate, n_candidates, grade); //Used to get the information about candidates that have got less than a specified grade
            break;

            case EXIT:
                printf("\n--- EXIT ---\n");
                exit(EXIT_SUCCESS);
            break;

            default:
                printf("\n--- ERROR EXIT ---\n");
                exit(EXIT_FAILURE);
            break;
        }

    }
    while(1);

    exit(EXIT_FAILURE);
}