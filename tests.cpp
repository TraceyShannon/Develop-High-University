#include <stdio.h>
#include <iostream>

#define MAX 1000

using namespace std;

struct people {
  string first_name;
  string last_name;
  int age;
};
void create_person      (void);
void delete_person      (void);
void display_person     (void);
void dis_all_users      (void);
void update_person      (void);
void dis_del_prsn       (void);
void enter_interface    (void);
int num_of_words        (string str);
int length              (string str);
string join             (string str[]);
int str_cmp             (string str_1, string str_2);
string join             (string str[], string add_str);
int arr_of_words        (string str, string str_arr[]);
string insert           (string usr_str, int i, string str_to_insrt);
string replace          (string usr_str, int i, int c, string wrd_to_add);

struct people city[20];
struct people deleted[20];
int dt =  0;
int del = 0;

int main(int argc, char const *argv[]) {

  /*
  string my_str = "Hello, World!";
  cout << my_str << '\n';
  my_str = insert(my_str, 5, " There Everybody And Welcome To The Show!");
  cout << my_str << '\n';

  string my_str_arr[MAX];
  string my_str_2 = "This Is My String.";
  string my_str_3 = "This Is My String.";
  int res = str_cmp(my_str_2, my_str_3);
  int res_2 = arr_of_words(my_str_3, my_str_arr);
  cout << my_str_2 << '\n';
  cout << res << '\n';
  cout << num_of_words(my_str_3) << '\n';
  res = str_cmp(my_str_2, my_str_3);
  cout << res << '\n';
  for (int i = 0; i < res_2; i++) {
    cout << my_str_arr[i] << '\n';
  }
  string my_str_4 = join(my_str_arr);
  string my_str_5 = join(my_str_arr, " ");
  cout << my_str_4 << '\n';
  cout << my_str_5 << '\n';

  string my_str_6 = "Well Ain't This About A String";
  cout << my_str_6 << '\n';
  my_str_6 = replace(my_str_6, 16, 21, "Bitch");
  cout << my_str_6 << '\n';
  */

  enter_interface();


  return 0;
}

string join(string str[], string add_str) {
  string my_str = "";
  int i = 0;

  while (str[i][0] != false) {
    my_str += str[i];
    my_str += add_str;
    i++;
  }

  return my_str;
}

string join(string str[]) {

  string my_str = "";
  int i = 0;

  while (str[i][0] != false) {
    my_str += str[i];
    i++;
  }

  return my_str;
}

int arr_of_words(string str, string str_arr[]) {
  str += " ";
  string word = "";
  int a = 0;

  for (int i = 0; i < length(str); i++) {
    if (str[i] == ' ') {
      str_arr[a] = word;
      word = "";
      a++;
    } else {
      word += str[i];
      continue;
    }
  }

  return a;
}

int num_of_words(string str) {

  str += " ";
  string word = "";
  string words[MAX];
  int a = 0;

  for (int i = 0; i < length(str); i++) {
    word += str[i];
    if (str[i] == ' ') {
      words[a] = word;
      word = "";
      a++;
    } else {
      continue;
    }
  }

  return a;
}

int str_cmp(string str_1, string str_2) {

  int i = 0;
  int res_1 = 1;
  int res_2 = 1;
  int res_3 = 1;

  while (str_1[i] != '\0') {

    if (str_1[i] == str_2[i]) {
      i++;
      continue;
    } else {
      return 1;
    }

  }

  res_1 = 0;
  i = 0;

  while (str_2[i] != '\0') {

    if (str_2[i] == str_1[i]) {
      i++;
      continue;
    } else {
      return 1;
    }

  }

  res_2 = 0;

  if (res_1 == 0 && res_2 == 0) {
    res_3 = 0;
  } else {
    res_3 = 1;
  }

  return res_3;
}

int length(string str) {

  int i = 0;

  while (str[i] != '\0') {
    i++;
  }

  return i;
}

string replace(string usr_str, int i, int c, string wrd_to_add) {
  string str_start = "";
  string str_end = "";

  for (int v = 0; v < i; v++) {
    str_start += usr_str[v];
  }

  for (int x = c; x < length(usr_str); x++) {
    str_end += usr_str[x];
  }

  return str_start + wrd_to_add + str_end;
}

string insert(string usr_str, int i, string str_to_insrt) {

  // i = Starting index

  string str_start = "";
  string str_end = "";

  for (int v = 0; v < i; v++) {
    str_start += usr_str[v];
  }

  for (int x = i; x < length(usr_str); x++) {
    str_end += usr_str[x];
  }

  return str_start + str_to_insrt + str_end;

}

void enter_interface(void) {

  string create =   "11";
  string display =  "22";
  string update =   "33";
  string destroy =  "44";
  string shw_del =  "55";
  string dis_all =  "66";

  string user_input = "";

  while (str_cmp(user_input, "q") != 0) {

    cout << "\n\n11 To Create User" << '\n';
    cout << "22 To Display User" << '\n';
    cout << "33 To Update User" << '\n';
    cout << "44 To Delete User" << '\n';
    cout << "55 To Show Deleted" << '\n';
    cout << "66 To Show All Users" << "\n\n";

    cout << "q To Quit" << '\n';
    cout << " - - > ";
    cin >> user_input;

    if (str_cmp(user_input, create) == 0)       create_person();
    else if (str_cmp(user_input, update) == 0)  update_person();
    else if (str_cmp(user_input, destroy) == 0) delete_person();
    else if (str_cmp(user_input, display) == 0) display_person();
    else if (str_cmp(user_input, shw_del) == 0) dis_del_prsn();
    else if (str_cmp(user_input, dis_all) == 0) dis_all_users();
    else continue;
  }
}

void create_person(void) {

  string user_input = "";

  cout << "Please Enter First Name - - >  ";
  cin >> city[dt].first_name;
  cout << "Please Enter Last Name - - >   ";
  cin >> city[dt].last_name;
  cout << "Please Enter age - - >         ";
  cin >> city[dt].age;
  cout << "                               Your Account Has Been Setup" << '\n';
  cout << "Your Id Is - - >               " << dt << "\n\n";

  dt++;
}

void display_person(void)
{

  if (dt <= 0)
  {
    cout << "Sorry No Users" << '\n';
    return;
  }

  int du = -1;

  cout << "Please Enter Id - - > ";
  cin >> du;

  if (city[du].first_name[0] == false)
  {
    cout << "                    ** That User Does'nt Exist **" << '\n';
    return;
  }

  cout << "\n\nFirst Name - - >  " << city[du].first_name << '\n';
  cout << "Last Name - - >   " << city[du].last_name << '\n';
  cout << "Age - - >         " << city[du].age << "\n\n";
}

void update_person(void)
{

  string first = "11";
  string last = "22";
  string u_age = "33";

  if (dt <= 0)
  {
    cout << "Sorry No Users" << '\n';
    return;
  }

  string user_input = "";
  int du = -1;

  cout << "Please Enter Id - - > ";
  cin >> du;

  if (du >= dt)
  {
    cout << "That User Doesn't Exists\n";
    return;
  } else if (city[du].first_name[0] == false)
  {
    cout << "That User Doesn't Exists\n";
    return;
  }

  while (str_cmp(user_input, "q") != 0)
  {

    cout << "\n\nFirst Name - - >  " << city[du].first_name << '\n';
    cout << "Last Name - - >   " << city[du].last_name << '\n';
    cout << "Age - - >         " << city[du].age << "\n\n";

    cout << "11 To Change First Name" << '\n';
    cout << "22 To Change Last Name" << '\n';
    cout << "33 To Change age" << '\n';

    cout << "Type 'q' To Quit" << '\n';
    cin >> user_input;

    if (str_cmp(user_input, "q") == 0) break;
    else if (str_cmp(user_input, first) == 0)
    {
      cout << "Changing " << city[du].first_name << '\n';
      cin >> city[du].first_name;
      cout << "All Done!";
    } else if (str_cmp(user_input, last) == 0)
    {
      cout << "Changing " << city[du].last_name << '\n';
      cin >> city[du].last_name;
      cout << "All Done!";
    } else if (str_cmp(user_input, u_age) == 0)
    {
      cout << "Changing " << city[du].age << '\n';
      cin >> city[du].age;
      cout << "All Done!";
    }

  }

}

void delete_person(void)
{

  if (dt <= 0)
  {
    cout << "Sorry No Users" << '\n';
    return;
  }

  int du = -1;

  cout << "Please Enter Id - - > ";
  cin >> du;

  if (du >= dt)
  {
    cout << "That User Doesn't Exist";
    return;
  }

  deleted[del].first_name = city[du].first_name;
  deleted[del].last_name = city[du].last_name;
  deleted[del].age = city[du].age;

  city[du].first_name = "";
  city[du].last_name = "";
  city[du].age = 0;

  del++;

}

void dis_del_prsn(void) {

  for (int i = 0; i < del; i++)
  {
    cout << "First Name - - > " << deleted[i].first_name << endl;
    cout << "Last Name - - > " << deleted[i].last_name << endl;
    cout << "age Name - - > " << deleted[i].age << endl;
    cout << "** This Account Has Been Deleted **" << endl;
  }

}

void dis_all_users(void)
{

  if (dt <= 0)
  {
    cout << "Sorry No Users" << '\n';
    return;
  }



  for (int i = 0; i < dt; i++)
  {

    if (city[i].first_name[0])
    {
      cout << "User " << i << '\n';
      for (int a = 0; a < 40; a++) cout << "=";
      cout << "+" << endl;
      cout << "First Name - - > " << city[i].first_name << "  ||" << endl;
      cout << "Last Name - - > " << city[i].last_name << "  ||" << endl;
      cout << "age Name - - > " << city[i].age << "  ||" << endl;
      for (int a = 0; a < 40; a++) cout << "=";
      cout << "+" << endl;
    }
  }

}
