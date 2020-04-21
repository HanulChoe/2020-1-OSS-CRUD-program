#ifndef _BASE_H_
#define _BASE_H_

#include "record.h"

// function prototypes
void Initialize(Record **rec,int max);
void add_a_new_stduent(Record[], int *stuNum);
void print_list(Record records[], int *stuNum);
void save_list(Record[], int *stuNum);
void update_student_info(Record[], int *stuNum);
void delete_student_info(Record[], int *stuNum);

void load_file(Record[], int *stuNum);
Record str2student(char *line);

void deallocate_m(Record **rec, int max);

#endif
