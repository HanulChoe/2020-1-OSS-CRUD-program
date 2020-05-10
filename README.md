Student's information management program (main.c)
========================================
Models
------

This is elementary CRUD program called Student's information management program.
There are 8 files to run this program. base.h, base.c, extras.h, extras.c, main.c, record.h Makefile.
When you compile these files you can get student.out file.
You can get the data file student.txt of student information, When you run the program.

* Create
   - add_a_txt_new_stduent
   - add_a_new_stduent
* Read
   - print_list
   - load_file
   - Record str2student 
* Update
* Delete
* Extras
   - sort
   - find_student

## 1. Create
### 1-1 add_a_txt_new_stduent (Create 1)

     When select option ‘2’ Program read ‘stduent.txt’ file. Then print the number of added students.
     When file does not exist the error message printed. The contents of “student.txt” can show.
  
### 1-2 add_a_new_stduent (Create 2)
 
    When selected the option ‘1’. add_a_new_student function implement.
    This function is to input student information into the Student structure from user’s keyboard.
    As a parameter, receive the record[] of the student structure and the pointer *stuNum, a variable of the student total number of students.
    The student's number, name, age, cell phone number and e-mail are entered and stored in each variable in the Student Structure.
    If insert is success print out “Inserted”

  
## 2. Read

### 2-1 void print_list
       When selected the option ‘3’ This function implement.
       This function shows the student information currently existing data in the student structure.
       Each variable is shown organized according to the name of each variable.
       If there are no data print out “No data”

  
 ### 2-2 void load_file
      When selected the option ‘8’ This function implement.
      This function reads student information from the existing student.txt file.
      get the line one by getline() function and divide it according to each information
      and put it back into the variable of the current structure. It has an other function is Record str2student(char*line).
      This function is assists load function. When load is completed print message.

 ###  2-3 Record str2student 
      The line taken from the load function is divided into each data and placed in the variables in the structure.
      This function assist the load function
 
 ###  2-4 save_list 
      When selected the option ‘4’ This function implement.
      This function stores information in the current structure in the computer as a study.txt file.
      If saving data succeed print out “saved txt”. After that student.txt is created.
      
 ## 3. Update
      When selected the option ‘6’ This function implement. Program print the message ‘select to update information option.
      And user input number to update Id , name, major, phone number, E-mail. Next, enter a index of student.
      Then print the message to update. Then print message ‘update the information

 ## 4. Delete
    When selected the option ‘7’ This function implement. This function receives the index number of students from the user.
    Each student data has an index and all student information is deleted according to input index number.
    next program print message. Then you can see the delete part. But now it has error. If you delete, save, and load.
    
 ## 5. Extra

### 5-1 Extra1
      When selected the option ‘9’ This function implement.
      Then The data that was in the order of input are sorted name by ascending order.
     
### 5-2 Extra2
     When selected the option ‘5’ This function implement. This function ask the name of finding student.
     And user enter the name then Shows the information of the corresponding student. If there are several students whose names match,
     show them all. If there is no data, print the ‘No data’
