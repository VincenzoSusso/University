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
*  Name : ExamsManagement.h                                                                                                                          *
*  Purpose : The purpose of this header is to store function prototypes of the program "ExamsManagement.c".                                          *
*  Date : 04/01/2019                                                                                                                                 *
*                                                                                                                                                    *
*****************************************************************************************************************************************************/

// -- Libraries --
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// -- Constants --
#define MAXSTRING 20 //Maximum character of string

#define MINCANDIDATES 0 //Minimun number of candidates
#define MAXCANDIDATES 300 //Maximum number of candidates

#define MINYEAR 0 //Minimum year
#define MAXYEAR 9999 //Maximum year

#define MINGRADE 0 //Minimum grade of the exam
#define MAXGRADE 30 //Maximum grade of the exam

#define PATH "ExamsManagement.txt" //Path file
#define ENDFORMATFILE '\n' //End format file
#define FORMATFILE "%s - %s - %d - %d - %d\n" //Format of the file


// -- Data type user defined --
typedef enum {INSERT_CANDIDATES = 1, READ_CANDIDATES, LOAD_CANDIDATES_FILE, //Used to define the choose of the menu -- Start from 1
              SAVE_CANDIDATES_FILE, SEARCH_GRADE_CANDIDATE, 
              SEARCH_GRADE_CANDIDATE_LESS, EXIT} Choose_t;

typedef enum {COMPUTER_SCIENCE, DIGITAL_COMUNICATION} Course_t; //Used to define the courses that the candidates has taken

typedef struct //Used to store informations about candidates
{
     char name[MAXSTRING];
     char surname[MAXSTRING];
     Course_t course;
     int year_exam;
     int grade;
} Candidate_t; 

// -- Functions Prototypes --
void menu(void); //Used to print the menu
Choose_t getChooseMenu(void); //Used to select an option of the menu
int setGradeSearch(void); //Used to set the grade to search

int setNCandidates(void); //Used to set the number of candidates
void setCandidates(Candidate_t candidate[], const int size); //Used to set information about candidates
void getCandidates(const Candidate_t candidate[], const int size); //Used to print information about candidates

void sortCandidates(Candidate_t candidate[], const int size); //Used to sort the candidates
void getCandidateGrade(const Candidate_t candidate[], const int size, const int grade); //Used to get the information about candidates that have got a specified grade
void getCandidateLessGrade(const Candidate_t candidate[], const int size, const int grade); //Used to get the information about candidates that have got less than a specified grade

void resetFile(void); //Used to reset the file
void writeFile(const Candidate_t candidate[], const int size); //Used to write the vector of candidate in a file
int getSizeFile(void); //Used to read the dimension of the vector from the file
void readFile(Candidate_t candidate[], const int size); //Used to read the vector of candidate from the file

// -- Functions --
void menu(void) //Used to print the menu
{
     printf("\n---------------------------------------------");
     printf("\n---------------------------------------------");
     printf("\n               --- Menu ---");
     printf("\n1 --> Insert candidates");
     printf("\n2 --> Read candidates");
     printf("\n3 --> Load candidates from the file");
     printf("\n4 --> Save candidates into the file");
     printf("\n5 --> Search candidates by grade");
     printf("\n6 --> Search candidates by grade (Less than the grade choosen)");
     printf("\n7 --> Exit");
     printf("\n---------------------------------------------");
     printf("\n---------------------------------------------");
}

Choose_t getChooseMenu(void) //Used to select an option of the menu
{
     Choose_t choose = EXIT; //Exit default
     do
     {
          printf("\n\nInsert an option: ");
          scanf("%d", &choose);
     }
     while((choose < INSERT_CANDIDATES) || (choose > EXIT));

     return choose;
}

int setGradeSearch(void) //Used to set the grade to search
{
     int grade = 0;
     do //Check if the grade is correct
     {
          printf("\nInsert the candidates'grade that you want to seach (0 / 30): ");
          scanf("%d", &grade);
     }
     while((grade < MINGRADE) || (grade > MAXGRADE));

     return grade;
}

int setNCandidates(void) //Used to set the number of candidates
{
     int n_candidates = MINCANDIDATES; //Used to store the number of candidates

     do
     {
          printf("\nInsert the number of candidates that has done the exams: ");
          scanf("%d", &n_candidates);
     }
     while((n_candidates < MINCANDIDATES) || (n_candidates > MAXCANDIDATES));

     return n_candidates;
}

void setCandidates(Candidate_t candidate[], const int size) //Used to set information about candidates
{
     for(int i = 0; i < size; i++)
     {
          printf("\nInsert the name of the %d^ candidate: ", i+1);
          scanf("%s", candidate[i].name);

          printf("Insert the surname of the %d^ candidate: ", i+1);
          scanf("%s", candidate[i].surname);

          do //Check if the course is correct
          {
               printf("Insert the course of the %d^ candidate(0 -> Computer Science / 1 -> Digital Comunication): ", i+1);
               scanf("%d", &candidate[i].course);
          }
          while((candidate[i].course != COMPUTER_SCIENCE) && (candidate[i].course != DIGITAL_COMUNICATION));

          do //Check if the year is correct
          {
               printf("Insert when the %d^ candidate has done the exam: ", i+1);
               scanf("%d", &candidate[i].year_exam);
          }
          while((candidate[i].year_exam < MINYEAR) || (candidate[i].year_exam > MAXYEAR));

          do //Check if the grade is correct
          {
               printf("Insert the grade that the %d^ candidate has get (0 / 30): ", i+1);
               scanf("%d", &candidate[i].grade);
          }
          while((candidate[i].grade < MINGRADE) || (candidate[i].grade > MAXGRADE));
     }
}

void getCandidates(const Candidate_t candidate[], const int size) //Used to print information about candidates
{
     for(int i = 0; i < size; i++)
     {    
          printf("\n---------------------------------------------");
          printf("\nInformation about %d^ candidate: ", i+1);
          printf("\nThe name of %d^ candidate is: %s", i+1, candidate[i].name);
          printf("\nThe surname of %d^ candidate is: %s", i+1, candidate[i].surname);
          if(candidate[i].course == COMPUTER_SCIENCE)
          {
               printf("\nThe %d^ candidate's course is: Computer Science", i+1);
          }
          else
          {
               printf("\nThe %d^ candidate's course is: Digital Comunication", i+1);
          }
          printf("\nThe %d^ candidate has done the exam in: %d", i+1, candidate[i].year_exam);
          printf("\nThe %d^ candidate's grade is: %d", i+1, candidate[i].grade);
          printf("\n---------------------------------------------");
     }
     printf("\n\n");
}

void sortCandidates(Candidate_t candidate[], const int size) //Used to sort the candidates
{
     for(int i = 0; i < size; i++)
     {
          int min = candidate[i].grade, position = i; /* 1 --> Used to store the minimum of the array
                                                         2 --> Used to store the position of the minimum */
          Candidate_t temp; //Used to change switch 2 candidate position
          for(int j = i+1; j < size; j++)
          {
               if(candidate[j].grade < min)
               {
                    min = candidate[j].grade;
                    position = j;
               }
          }

          if(i != position)
          {
               temp = candidate[position]; //Switch 2 candidate
               candidate[position] = candidate[i];
               candidate[i] = temp;
          }
     }
     printf("\nNow the candidates are sorted by grade!\n");
}

void getCandidateGrade(const Candidate_t candidate[], const int size, const int grade) //Used to get the information about candidates that have got a specified grade
{
     printf("\n\nThe candidates who has got %d are: ", grade);
     for(int i = 0; i < size; i++)
     {
          if(candidate[i].grade == grade)
          {
               printf("\n---------------------------------------------");
               printf("\nInformation about %d^ candidate who has got %d: ", i+1, grade);
               printf("\nThe name of %d^ candidate is: %s", i+1, candidate[i].name);
               printf("\nThe surname of %d^ candidate is: %s", i+1, candidate[i].surname);
               if(candidate[i].course == COMPUTER_SCIENCE)
               {
                    printf("\nThe %d^ candidate's course is: Computer Science", i+1);
               }
               else
               {
                    printf("\nThe %d^ candidate's course is: Digital Comunication", i+1);
               }
               printf("\nThe %d^ candidate has done the exam in: %d", i+1, candidate[i].year_exam);
               printf("\nThe %d^ candidate's grade is: %d", i+1, candidate[i].grade);
               printf("\n---------------------------------------------");
          }
     }
     printf("\n\n");
}

void getCandidateLessGrade(const Candidate_t candidate[], const int size, const int grade) //Used to get the information about candidates that have got less than a specified grade
{
     printf("\n\nThe candidates who has got less than %d are: ", grade);
     for(int i = 0; i < size; i++)
     {
          if(candidate[i].grade < grade)
          {
               printf("\n---------------------------------------------");
               printf("\nInformation about %d^ candidate who has got %d: ", i+1, candidate[i].grade);
               printf("\nThe name of %d^ candidate is: %s", i+1, candidate[i].name);
               printf("\nThe surname of %d^ candidate is: %s", i+1, candidate[i].surname);
               if(candidate[i].course == COMPUTER_SCIENCE)
               {
                    printf("\nThe %d^ candidate's course is: Computer Science", i+1);
               }
               else
               {
                    printf("\nThe %d^ candidate's course is: Digital Comunication", i+1);
               }
               printf("\nThe %d^ candidate has done the exam in: %d", i+1, candidate[i].year_exam);
               printf("\nThe %d^ candidate's grade is: %d", i+1, candidate[i].grade);
               printf("\n---------------------------------------------");
          }
     }
     printf("\n\n");
}

void resetFile(void)  //Used to reset the file
{
     FILE *file; //Used to point to the file

     file = fopen(PATH,"w");
     if(file == NULL)
     {
          printf("\n--- ERROR WHILE OPENING THE FILE ---\n\n");
     }

     fprintf(file,""); //Reset the file
     fflush(file);
     fclose(file);
     printf("\n\"%s\" has been reset\n", PATH);
}

void writeFile(const Candidate_t candidate[], const int size) //Used to write the vector of candidate in a file
{
     FILE *file; //Used to point to the file

     resetFile();

     file = fopen(PATH,"a+"); //Used to open the file
     if(file == NULL)
     {
          printf("\n--- ERROR WHILE OPENING THE FILE ---\n\n");
     }

     
     for(int i = 0; i < size; i++)
     {
          fprintf(file, FORMATFILE, candidate[i].name, candidate[i].surname, candidate[i].course, candidate[i].year_exam, candidate[i].grade);
     }
     fflush(file);
     fclose(file);
     printf("\n\"%s\" has been written.\n", PATH);
}

int getSizeFile(void) //Used to read the dimension of the vector from the file
{
     int size = 0; //Used to return the size of the array
     char ch = ' '; //Used to store the characters of the file
     FILE *file; //Used to point to the file

     file = fopen(PATH,"r"); //Used to open the file
     if(file == NULL)
     {
          printf("\n--- ERROR WHILE OPENING THE FILE ---\n\n");
          exit(EXIT_FAILURE);
     }

     for(ch = getc(file); ch != EOF; ch = getc(file))
     {
          if(ch == ENDFORMATFILE) //When the file reaches '\n' it means that has reached a record
          {
               size++;
          }
     }

     fflush(file);
     fclose(file);

     return size;
}

void readFile(Candidate_t candidate[],const int size) //Used to read the vector of candidate from the file 
{
     FILE *file; //Used to point to the file

     file = fopen(PATH,"r"); //Used to open the file
     if(file == NULL)
     {
          printf("\n--- ERROR WHILE OPENING THE FILE ---\n\n");
          exit(EXIT_FAILURE);
     }

     for(int i = 0; i < size; i++)
     {
          fscanf(file, FORMATFILE, candidate[i].name, candidate[i].surname, &candidate[i].course, &candidate[i].year_exam, &candidate[i].grade);
     }

     fflush(file);
     fclose(file);
     printf("\n\"%s\" has been read.\n", PATH);
}