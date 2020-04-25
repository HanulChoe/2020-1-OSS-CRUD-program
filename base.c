#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "base.h"

// Function: Initialize(Record **rec,int max))
// Input: **rec, int max
// Output: none
// - allocate memory spaces
void Initialize(Record **rec,int max)
{
     rec=(Record **)malloc(sizeof(Record *)*max);// dynamic allocation
     memset(rec, 0, sizeof(Record *)*max);// Initialize memorys    
}


// Function: add_a_txt_new_student(Record records[], int *stuNum)
// Input: record - array of Records; this may contain empty elements in the middle
// Output: none
// - create new student data from student.txt
void add_a_txt_new_stduent(Record records[], int *stuNum){

  FILE *fp;
  fp = fopen("student.txt", "r");
  printf("Open student data\n");
  
  printf("%s %s %-15s%-25s%-15s%-30s\n", "Index", "Student ID", "Student Name", "Major", "Phone Number", "E-mail");
  printf("----------------------------------------------------------------------------------------------\n");
  
  while(1)  {
   	char input_studentId[32];
    char input_studentName[32];
    char input_major[64];
    char input_phoneNum[32];
    char input_email[64];
    int count = 0;  

   fscanf(fp, "%s %s %s %s %s", input_studentId, input_studentName, input_major, input_phoneNum, input_email);
   if(feof(fp)) break;
   printf("%-6d%s   %-15s%-25s%-15s%-30s\n", count+1, input_studentId, input_studentName, input_major, input_phoneNum, input_email);

   strcpy(records[count].studentId ,input_studentId);
   strcpy(records[count].studentName , input_studentName);
   strcpy(records[count].major , input_major);
   strcpy(records[count].phoneNum , input_phoneNum);
   strcpy(records[count].email,input_email);
   count++;
   }
   printf("\n----------------------------------------------------------------------------------------------\n");
   fclose(fp);
   printf("Complete!! \n\n");
}

// Function: add_a_record()
// Input: record - array of Records; this may contain empty elements in the middle
// Output: none
// - Leave a brief information about the function
void add_a_new_stduent(Record records[], int *stuNum){

  // printf("[%d]\n", *stuNum);  
  printf("Enter a new student Id: ");
  fgets(records[*stuNum].studentId, 32, stdin);
  records[*stuNum].studentId[strlen(records[*stuNum].studentId)-1]='\0';
  printf("Enter a student name: ");
  fgets(records[*stuNum].studentName, 32, stdin);
  records[*stuNum].studentName[strlen(records[*stuNum].studentName)-1]='\0';
  printf("Enter a student major: ");
  fgets(records[*stuNum].major, 32, stdin);
  records[*stuNum].major[strlen(records[*stuNum].major)-1]='\0';
  printf("Enter a phone number: ");
  fgets(records[*stuNum].phoneNum, 32, stdin);
  records[*stuNum].phoneNum[strlen(records[*stuNum].phoneNum)-1]='\0';
  printf("Enter a new student E-mail: ");
  fgets(records[*stuNum].email, 32 , stdin);
  records[*stuNum].email[strlen(records[*stuNum].email)-1]='\0';
  (*stuNum)++;
  printf("Inserted!\n\n"); 
}
void print_list(Record records[], int *stuNum){
  
  int i;
  Record r;

  if(*stuNum == 0){
    printf("No data\n\n");
    return ;
  }
  printf("\n");
 
  printf("%s %s %-15s%-25s%-15s%-30s\n", "Index", "Student ID", "Student Name", "Major", "Phone Number", "E-mail");
  printf("-----------------------------------------------------------------------------------------\n");
  for(int i=0; i<(*stuNum); i++){
    r=records[i];
    printf("%-6d[%s] %-15s%-25s%-15s%-30s\n", i+1, r.studentId, r.studentName, r.major, r.phoneNum, r.email);
  }
  printf("\n-----------------------------------------------------------------------------------------\n");
  printf("\n\n");
}

// Function: save_list()
// Input: record -array of records 
// Output: none
// - save the array into txt file
void save_list(Record records[], int *stuNum){
	
	FILE *fp;
  fp=fopen("student.txt", "w");
  if(fp == NULL){
    printf("Error!");
    return ;
  }

  for(int i=0; i<*stuNum; i++){
    fprintf(fp, "%-10s", records[i].studentId);
    fprintf(fp, "%-15s", records[i].studentName);
    fprintf(fp, "%-25s", records[i].major);
    fprintf(fp, "%-15s", records[i].phoneNum);
    fprintf(fp, "%-30s", records[i].email);
    fprintf(fp, "\n");
  }
  fclose(fp);
}

// Function: update_student_info()
// Input: record - array of Records; this may contain empty elements in the middle
// Output: none
// - 
void update_student_info(Record records[], int *stuNum){
	// TODO: Modify this function as you need
	printf("Not implement\n\n");
}

// Function: delete_student_info()
// Input: record - array of Records; this may contain empty elements in the middle
// Output: none
// - 학생 이름이나 studentID 로 접근해서 수정하기
void delete_student_info(Record records[], int *stuNum){
	// TODO: Modify this function as you need
  printf("Not implement\n\n");
  // int num;
 
  // printf("Student number to delete: ");
  // scanf("%d", &num);
  
  // strcpy(records[num-1].studentId, "");
  // strcpy(records[num-1].studentName, "");
  // strcpy(records[num-1].major, "");
  // strcpy(records[num-1].phoneNum, "");
  // strcpy(records[num-1].email, "");

  // printf("Delete\n");
}

// Function: list_all_student_()
// Input: record - array of Records; this may contain empty elements in the middle
// Output: none
// - print student information
void load_file(Record records[], int *stuNum){
	
  FILE *fp;
  char *line=NULL;
  size_t len;

  fp = fopen("student.txt", "r");
  if(fp == NULL){
    printf("Error: No data\n");
    return ;
  }
  int stuCount=0;
  while(getline(&line, &len, fp) != EOF){
      records[stuCount++] = str2student(line);
  }
  *stuNum=stuCount;
  fclose(fp);
  printf("loading...done!\n");
}

// Function: str2student(char *line()
// Input: none
// Output: none
// - Save one line of received information divided by each information
Record str2student(char *line){

  Record rec;
  char *token;
  char temp[64];

  int i=0; 
  token = strtok(line, " ");
  while(token){
    strcpy(temp, token);
    temp[strlen(temp)]='\0';
    switch(i){
      case 0: strcpy(rec.studentId, temp); break;
      case 1: strcpy(rec.studentName, temp); break;
      case 2: strcpy(rec.major, temp); break;
      case 3: strcpy(rec.phoneNum, temp); break;
     case 4: strcpy(rec.email, temp); break;
     }
    i++;
    token=strtok(NULL, " ");
  }
  return rec;
}

// Function: deallocate(Record **rec,int max)
// Input: rec , max
// Output: none
// - deallocate memory spaces
void deallocate_m(Record **rec,int max){
  
  free(rec);
}

