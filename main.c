#include <stdio.h>
#include <string.h>
#include "base.h"
#include "extras.h"
#include "record.h"

#define MAX_RECORDS 1000
Record **rec;

// function prototypes
void input_handler(char[], Record[], int*);
void display_menu();

// main function
int main(){

	Record records[MAX_RECORDS];
  Initialize(rec, MAX_RECORDS);
  int person=0;
  
	char user_input[64] = "";
	while(strcmp(user_input, "0") != 0){
		display_menu();
		printf("\nSelect a menu> ");
		fgets(user_input, 64, stdin);
		user_input[strlen(user_input)-1] = '\0';
		input_handler(user_input, records, &person);
	}
  deallocate_m(rec, MAX_RECORDS);
	return 0;
}

// Function: input_handler()
// Input: record - array of Records; this may contain empty elements in the middle
// Output: none
// - Handles the user input and invokes functions that correspond to the user input
void input_handler(char input[], Record records[], int* person){
  
	// TODO: Modify this function as you need
	if(!strcmp(input, "1"))
		add_a_new_stduent(records, person);
  else if(!strcmp(input, "2"))
    print_list(records, person);
	else if(!strcmp(input, "3"))
		save_list(records, person);
  else if(!strcmp(input, "4"))
		find_student(records, person);	
	else if(!strcmp(input, "5"))
		update_student_info(records, person);
	else if(!strcmp(input, "6"))
		delete_student_info(records, person);
  else if(!strcmp(input, "7"))
    load_file(records, person);
  else if(!strcmp(input, "8"))
    sort(records, person);
	else if(!strcmp(input, "0"))
		printf("Terminating... bye!\n"); // Quit - no operation (an empty statement with a semi-colon)
	else
		printf("Unknown menu: %s \n\n", input);
}

// Function: display_menu()
// Input: none
// Output: none
// - Leave a brief information about the function
void display_menu(){

	// TODO: Modify this function as you need
	printf("*******************************************\n");
	printf("           < Handong University >\n"); 
  printf("   Student information management system\n");
	printf("*******************************************\n");
	printf(" 1. Add a new Student\n");
  printf(" 2. List all Students\n");
	printf(" 3. save list\n");
	printf(" 4. Find Student\n");
  printf(" 5. Update a student information(Not yet implemented)\n");
	printf(" 6. Delete a student information(Not yet implemented)\n");
	printf(" 7. load file\n");
	printf(" 8. Sort(names in ascending order)\n");
  printf(" 0. Quit\n");
}
