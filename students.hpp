#include <iostream>
#include <stdio.h>

using namespace std;

// ==== STRING FUNCTIONS ==== //
int str_length(string str);
int str_arr_length(string str[]);
int str_cmp(string str_1, string str_2);

string student_id_generator(student stud);
string student_email_generator(student stud);
void student_info(int s);

// ==== CRUD STUDENT FUNCTIONS ==== //
void create_student(void);
void display_student(void);
void update_student(void);
void delete_student(void);

void home_interface();
