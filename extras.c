#include <stdio.h>
#include <string.h>
#include "extras.h"

// Function: sort()
// Input: record - array of Record
// Output: none
// - Bubble sorting names in ascending order
void sort(Record *records, int *stuNum){

  int i,j;
  Record temp;
  
  for(i=0; i<(*stuNum); i++){
    for(j=0; j<(*stuNum)-i-1; j++){
      if(strcmp(records[j].studentName, records[j+1].studentName) > 0){
        temp=records[j];
        records[j]=records[j+1];
        records[j+1]=temp;
      }
    }
  }
  printf("done!\n\n");
}

// Function: find_student()
// Input: record - array of Records
// Output: none
// - find specific student information
void find_student(Record records[], int *stuNum){
  
  char find_info[32];
  int count=0;
  int check=1;

  do{

    printf("Enter the name of student: ");
    scanf("%s", find_info);
    getchar();

    printf("%s %-15s%-25s%-15s%-30s\n", "Student ID", "Student Name", "Major", "Phone Number", "E-mail");
    printf("-----------------------------------------------------------------------------------------\n");
      // find students in records[]
      for(int i=0; i<(*stuNum); i++){
        if(strcmp(find_info, records[i].studentName) == 0){
          printf("[%s] %-15s%-25s%-15s%-30s\n", records[i].studentId, records[i].studentName,  records[i].major, records[i].phoneNum, records[i].email);
          count++;
        }
       }
    printf("-----------------------------------------------------------------------------------------\n");
    // check the data exist
    if(count == 0)
      printf("No data!\n");
    else
      printf("%d student exist \n", count);
    count=0;
    // check that the user will continue to use this feature
    printf("Find more?(press any key or 0 to quit) ");
    scanf("%d", &check);
    getchar();
  }while(check != 0);

  printf("\n");
}

