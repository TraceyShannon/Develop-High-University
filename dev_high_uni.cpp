#include <iostream>
#include <curses.h>
#include <stdio.h>

using namespace std;

#define MAX 20

struct student {
  string first_name;
  string last_name;
  string user_name;
  string password;
  string day_of_birth;
  string month_of_birth;
  string year_of_birth;
  string school_email;
  string student_id;
  string email;
  int    id;
};

// ==== STRING FUNCTIONS ==== //
int str_length                 (string str);
int str_arr_length             (string str[]);
int str_cmp                    (string str_1, string str_2);

// ==== STUDENT INFO FUNCTIONS ==== //
string student_id_generator    (student stud);
string student_email_generator (student stud);
void student_info              (int s);

// ==== CRUD STUDENT FUNCTIONS ==== //
void create_student            (void);
void display_student           (void);
void update_student            (void);
void delete_student            (void);
void display_all_students      (void);

// ==== INTERFACE FUNCTIONS ==== //
void home_interface            (void);
int sign_in                    (void);

student dev_high[MAX];

int dt = 0; // { dt } This Stands For Database Tracker
string quit_l = "q";
string quit_U = "Q";

// ==== BEGIN MAIN FUNCTION ==== //
int main(int argc, char const *argv[])
{

  string enter_interface = "11";

  string user_input =      "x";

  while (str_cmp(user_input, quit_l) != 0 || str_cmp(user_input, quit_U) != 0)
  {
    cout << "\n\t\t\t**Welcome To The Devine High Common University Student Interface **" << "\n\n";
    cout << "\t\t\tIf You Would Like To Quit At Any Time Please Type q Or Q "
        << "And You Will Go To The Previous Screen.\n";
    cout << "\t\t\tOtherwise Please Proceed Using The Following Commands Followed By Enter!" << "\n\n";
    cout << "\n\t\t\tEnter Interface: 11" << "\n\n";

    cout << "\t\t\t - - > ";
    cin >> user_input;

    if (str_cmp(user_input, quit_l) == 0 || str_cmp(user_input, quit_U) == 0)
    {
      cout << "\n\t\t\tGoodBye!, See You Next Time!" << '\n';
      break;
    } else if (str_cmp(user_input, enter_interface) == 0)
    {
      home_interface();
    }

  }

  return 0;
}
// ==== END MAIN FUNCTION ==== //

// ==== STRING FUNCTIONS ==== //
int str_length(string str)
{

  int i = 0;

  while (str[i] != '\0')
  {
    i++;
  }

  return i;
}

int str_arr_length(string str[])
{

  int i = 0;

  while(str[i][0])
  {
    i++;
  }

  return i;
}

int str_cmp(string str_1, string str_2)
{

  int i =     0;
  int res_1 = 1;
  int res_2 = 1;
  int res_3 = 1;

  while (str_1[i] != '\0')
  {

    if (str_1[i] == str_2[i])
    {
      i++;
      continue;
    } else
    {
      return 1;
    }

  }

  res_1 = 0;
  i = 0;

  while (str_2[i] != '\0')
  {

    if (str_2[i] == str_1[i])
    {
      i++;
      continue;
    } else
    {
      return 1;
    }

  }

  res_2 = 0;

  if (res_1 == 0 && res_2 == 0)
  {
    res_3 = 0;
  } else
  {
    res_3 = 1;
  }

  return res_3;
}

// ==== CRUD STUDENT FUNCTIONS ==== //
// Create
void create_student(void)
{

  string user_input = "";

  cout << "\n\t\t\tPlease Type 'q' Or 'Q' And Hit Enter To Quit " << "\n\n";

  // First Name
  cout << "\t\t\tPlease Enter First Name: " << '\n';
  cout << "\n\t\t\t - - > ";
  cin >> user_input;

  if (str_cmp(user_input, quit_U) == 0 || str_cmp(user_input, quit_l) == 0)
  {
    return;
  }

  dev_high[dt].first_name = user_input;

  // Last Name
  cout << "\t\t\tPlease Enter Last Name: " << '\n';
  cout << "\n\t\t\t - - > ";
  cin >> user_input;

  if (str_cmp(user_input, quit_U) == 0 || str_cmp(user_input, quit_l) == 0)
  {
    return;
  }

  dev_high[dt].last_name = user_input;

  // Personal Email
  cout << "\t\t\tPlease Enter Email: " << '\n';
  cout << "\n\t\t\t - - > ";
  cin >> user_input;

  if (str_cmp(user_input, quit_U) == 0 || str_cmp(user_input, quit_l) == 0) return;

  dev_high[dt].email = user_input;

  // Student Username
  cout << "\t\t\tPlease Create A Username: " << '\n';
  cout << "\n\t\t\t - - > ";
  cin >> user_input;

  if (str_cmp(user_input, quit_U) == 0 || str_cmp(user_input, quit_l) == 0) return;

  dev_high[dt].user_name = user_input;

  // Student Password
  cout << "\t\t\tPlease Enter A Strong Password: " << '\n';
  cout << "\n\t\t\t - - > ";
  cin >> user_input;

  if (str_cmp(user_input, quit_U) == 0 || str_cmp(user_input, quit_l) == 0) return;

  dev_high[dt].password = user_input;

  // Month Of Birth
  cout << "\t\t\tPlease Enter Month Of Birth Two Digits(i.e. 07, 23, 14): " << '\n';
  cout << "\n\t\t\t - - > ";
  cin >> user_input;

  if (str_cmp(user_input, quit_U) == 0 || str_cmp(user_input, quit_l) == 0) return;

  dev_high[dt].month_of_birth = user_input;

  // Day Of Birth
  cout << "\t\t\tPlease Enter Day Of Birth Two Digits(i.e. 07, 23, 14): " << '\n';
  cout << "\n\t\t\t - - > ";
  cin >> user_input;

  if (str_cmp(user_input, quit_U) == 0 || str_cmp(user_input, quit_l) == 0) return;

  dev_high[dt].day_of_birth = user_input;

  // Year Of Birth
  cout << "\t\t\tPlease Enter Year Of Birth, Four Digits(i.e. 1999, 1995, 1984): " << '\n';
  cout << "\n\t\t\t - - > ";
  cin >> user_input;

  if (str_cmp(user_input, quit_U) == 0 || str_cmp(user_input, quit_l) == 0) return;

  dev_high[dt].year_of_birth = user_input;

  // Printing Student Info
  cout << "\n\n\t\t\t** Welcome " << dev_high[dt].first_name
      << " To Devine High Common University!! **\n\n";
  cout << "\t\t\tYour On Your Way To Being An Exceptional Citizen To Our Society!!\n";
  cout << "\t\t\tCurrently We're Generating All Your Student Information "
      << "For You To Begin Your Journey!!\n\n";

  dev_high[dt].school_email = student_email_generator(dev_high[dt]);
  cout << "\n\t\t\t" << dev_high[dt].first_name << "      Your New School Email Is - - > "
      << dev_high[dt].school_email;

  dev_high[dt].student_id = student_id_generator(dev_high[dt]);
  cout << "\t\t\tAnd Your New Student ID Is - - >            "
      << dev_high[dt].student_id << '\n';

  // Dictating The Number Of Users
  dt++;

}

// Read
void display_student(void)
{

  int direct_user = sign_in();

  if (direct_user == -1) return;

  student_info(direct_user);

}

void display_all_students(void)
{

  string interface_commands[6] = {
    "1. Display All Student Information:      11",
    "2. Display All Student Usernames:        22",
    "3. Display All Student Personal Emails:  33",
    "4. Display All Student Names:            44",
    "5. Display All Student Emails:           55",
    "6. Display All Student User IDs:         66"
  };

  string info = "11";
  string user = "22";
  string plem = "33";
  string name = "44";
  string stem = "55";
  string stid = "66";

  int student = 0;

  string admin_user = "admin123";
  string admin_pass = "password";
  string user_input = "";

  cout << "\n\t\t\tPlease Enter Admin Credentials" << "\n\n";
  cout << "\t\t\tEnter Username: " << '\n';
  cout << "\n\t\t\t - - > ";
  cin >> user_input;

  if (str_cmp(user_input, admin_user) == 0)
  {
    user_input = "";
    cout << "\n\t\t\tEnter Password: " << '\n';
    cout << "\n\t\t\t - - > ";
    cin >> user_input;
    if (str_cmp(user_input, admin_pass) == 0)
    {
      cout << "\n\t\t\t** Welcome Back Admin **" << '\n';
    } else
    {
      cout << "\n\t\t\t** Incorrect Password **" << '\n';
      return;
    }
  }

  while (str_cmp(user_input, quit_U) != 0 || str_cmp(user_input, quit_l) != 0)
  {

    cout << '\n';
    for (size_t i = 0; i < 6; i++) cout << "\t\t\t" << interface_commands[i] << '\n';

    cout << "\n\t\t\tPlease Type 'q' Or 'Q' To Quit" << '\n';
    cout << "\n\t\t\t - - > ";
    cin >> user_input;

    if (str_cmp(user_input, quit_U) == 0 || str_cmp(user_input, quit_l) == 0)
    {
      cout << "\n\t\t\tExiting Interface...." << '\n';
      cout << "\n\t\t\tGoodBye Admin!" << '\n';
      break;
    }

    if (str_cmp(user_input, info) == 0)
    {
      for (int i = 0; i < dt; i++) student_info(i);
      continue;
    } else if (str_cmp(user_input, user) == 0)
    {
      for (int i = 0; i < dt; i++) cout << "\n\t\t\t" << dev_high[i].user_name;
      cout << '\n';
      continue;
    } else if (str_cmp(user_input, plem) == 0)
    {
      for (int i = 0; i < dt; i++) cout << "\n\t\t\t" << dev_high[i].email;
      cout << '\n';
      continue;
    } else if (str_cmp(user_input, name) == 0)
    {
      for (int i = 0; i < dt; i++)
          cout << "\n\t\t\t" << dev_high[i].first_name << " " << dev_high[i].last_name;
      cout << '\n';
      continue;
    } else if (str_cmp(user_input, stem) == 0)
    {
      for (int i = 0; i < dt; i++) cout << "\n\t\t\t" << dev_high[i].school_email;
      cout << '\n';
      continue;
    } else if (str_cmp(user_input, stid) == 0)
    {
      for (int i = 0; i < dt; i++) cout << "\n\t\t\t" << dev_high[i].student_id;
      cout << '\n';
      continue;
    } else
    {
      cout << "\n\t\t\t** Sorry I don't Recognize That Command **" << '\n';
      continue;
    }

  }

}

// Update
void update_student(void)
{

  // du Stands For Direct User

  string interface_commands[8] = {
    "1. To Change First Name:       11",
    "2. To Change Last Name:        22",
    "3. To Change Personal Email:   33",
    "4. To Change Username:         44",
    "5. To Change Password:         55",
    "6. To Change Day Of Birth:     66",
    "7. To Change Month Of Birth:   77",
    "8. To Change Year Of Birth:    88"
  };

  string first_name = "11";
  string last_name =  "22";
  string email =      "33";
  string user_name =  "44";
  string password =   "55";
  string mob =        "66";
  string dob =        "77";
  string yob =        "88";

  int du = sign_in();
  string user_input =  "";
  string user_change = "";

  if (du == -1) return;

  while (str_cmp(user_input, quit_U) != 0 || str_cmp(user_input, quit_l) != 0)
  {

    cout << '\n';
    for (int i = 0; i < 8; i++) cout <<"\t\t\t" << interface_commands[i] << '\n';

    cout << "\n\t\t\tPlease Type 'q' Or 'Q' To Quit" << '\n';
    cout << "\t\t\t - - > ";
    cin >> user_input;

    if (str_cmp(user_input, quit_U) == 0 || str_cmp(user_input, quit_l) == 0)
    {
      cout << "\n\t\t\t** Saving Changes **" << '\n';
      break;
    }

    // First Name
    if (str_cmp(user_input, first_name) == 0)
    {
      cout << "\n\t\t\tOk Let's Change { " << dev_high[du].first_name << " } \n";
      cout << "\t\t\t - - > ";
      cin >> user_change;

      if (str_cmp(user_change, quit_U) == 0 || str_cmp(user_change, quit_l) == 0)
      {
        user_change = "";
        continue;
      } else
      {
        dev_high[du].first_name = user_change;
        continue;
      }
    }

    // Last Name
    if (str_cmp(user_input, last_name) == 0)
    {
      cout << "\n\t\t\tOk Let's Change { " << dev_high[du].last_name << " } \n";
      cout << "\t\t\t - - > ";
      cin >> user_change;

      if (str_cmp(user_change, quit_U) == 0 || str_cmp(user_change, quit_l) == 0)
      {
        user_change = "";
        continue;
      } else
      {
        dev_high[du].last_name = user_change;
        continue;
      }
    }

    // Email
    if (str_cmp(user_input, email) == 0)
    {
      cout << "\n\t\t\tOk Let's Change { " << dev_high[du].email << " } \n";
      cout << "\t\t\t - - > ";
      cin >> user_change;

      if (str_cmp(user_change, quit_U) == 0 || str_cmp(user_change, quit_l) == 0)
      {
        user_change = "";
        continue;
      } else
      {
        dev_high[du].email = user_change;
        continue;
      }
    }

    // Username
    if (str_cmp(user_input, user_name) == 0)
    {
      cout << "\n\t\t\tOk Let's Change { " << dev_high[du].user_name << " } \n";
      cout << "\t\t\t - - > ";
      cin >> user_change;

      if (str_cmp(user_change, quit_U) == 0 || str_cmp(user_change, quit_l) == 0)
      {
        user_change = "";
        continue;
      } else
      {
        dev_high[du].user_name = user_change;
        continue;
      }
    }

    // Password
    if (str_cmp(user_input, password) == 0)
    {
      cout << "\n\t\t\tOk Let's Change { " << dev_high[du].password << " } \n";
      cout << "\t\t\t - - > ";
      cin >> user_change;

      if (str_cmp(user_change, quit_U) == 0 || str_cmp(user_change, quit_l) == 0)
      {
        user_change = "";
        continue;
      } else
      {
        dev_high[du].password = user_change;
        continue;
      }
    }

    // Month Of Birth
    if (str_cmp(user_input, mob) == 0)
    {
      cout << "\n\t\t\tOk Let's Change { " << dev_high[du].month_of_birth << " } \n";
      cout << "\t\t\t - - > ";
      cin >> user_change;

      if (str_cmp(user_change, quit_U) == 0 || str_cmp(user_change, quit_l) == 0)
      {
        user_change = "";
        continue;
      } else
      {
        dev_high[du].month_of_birth = user_change;
        continue;
      }
    }

    // Day Of Birth
    if (str_cmp(user_input, dob) == 0)
    {
      cout << "\n\t\t\tOk Let's Change { " << dev_high[du].day_of_birth << " } \n";
      cout << "\t\t\t - - > ";
      cin >> user_change;

      if (str_cmp(user_change, quit_U) == 0 || str_cmp(user_change, quit_l) == 0)
      {
        user_change = "";
        continue;
      } else
      {
        dev_high[du].day_of_birth = user_change;
        continue;
      }
    }

    // Year Of Birth
    if (str_cmp(user_input, yob) == 0)
    {
      cout << "\n\t\t\tOk Let's Change { " << dev_high[du].year_of_birth << " } \n";
      cout << "\t\t\t - - > ";
      cin >> user_change;

      if (str_cmp(user_change, quit_U) == 0 || str_cmp(user_change, quit_l) == 0)
      {
        user_change = "";
        continue;
      } else
      {
        dev_high[du].year_of_birth = user_change;
        continue;
      }
    }

  }
}

// Destroy
void delete_student(void)
{

}

// ==== GENERATING STUDENT INFO ==== //
string student_id_generator(student stud)
{

  string id = "D";
  id += stud.first_name[0];

  for (int i = 0; i < str_length(stud.last_name) / 2; i++) id += stud.last_name[i];

  id += stud.year_of_birth;
  id += stud.day_of_birth;

  return id;
}

string student_email_generator(student stud)
{

  string email = "D";
  email += stud.first_name[0];
  email += stud.first_name[1];
  email += stud.first_name[2];

  for (int i = 0; i < str_length(stud.last_name) / 2; i++) email += stud.last_name[i];

  email += "_";
  email += stud.day_of_birth;
  email += "@devhigh.edu";

  return email;
}

void student_info(int s)
{

  cout << "\n\n\t\t\tStudents Name:             " << dev_high[s].first_name << ' ';
  cout << dev_high[s].last_name << '\n';
  cout << "\t\t\tStudents Username:         " << dev_high[s].user_name << "\n";
  cout << "\t\t\tStudents Password:         ";
  for (int i = 0; i < str_length(dev_high[s].password); i++) cout << '*';
  cout << '\n';
  cout << "\t\t\tStudents Date Of Birth:    " << dev_high[s].month_of_birth << "/";
  cout << dev_high[s].day_of_birth << "/";
  cout << dev_high[s].year_of_birth << '\n';
  cout << "\t\t\tStudents Personel Email:   " << dev_high[s].email << '\n';
  cout << "\t\t\tStudents School Email:     " << dev_high[s].school_email << '\n';
  cout << "\t\t\tStudents ID:               " << dev_high[s].student_id << '\n';

}

int sign_in(void)
{

  // du Stands For Direct User

  string user_name = "x";
  string password =  "x";
  int du =      0;
  int i =       0;
  int counter = 0;

  cout << "\t\t\tPlease Enter Username: " << '\n';
  cout << "\n\t\t\t - - > ";
  cin >> user_name;

  while (i < dt)
  {

      if (str_cmp(user_name, dev_high[i].user_name) == 0)
      {
        du = i; // This Is The Saved Integer From The Loop
        break;
      } else
      {
        i++;
        continue;
      }

  }

  if (str_cmp(user_name, dev_high[du].user_name) == 1)
  {
    cout << "\n\t\t\t**Sorry, We Couldn't Find A Student With That Username**" << "\n\n";
    du = -1;
    return du;
  }

  while (counter < 3)
  {
    cout << "\n\t\t\tPlease Enter Your Password: " << '\n';
    cout << "\n\t\t\t - - > ";
    cin >> password;

    if (str_cmp(password, dev_high[du].password) != 0)
    {
      cout << "\n\t\t\tIncorrect, Please Try Again..." << '\n';
      counter++;
    } else if (str_cmp(password, dev_high[du].password) == 0)
    {
      break;
    }
  }

  if (counter == 3) du = -1;

  return du;
}

// ==== USER INTERFACE FUNCTIONS ==== //
void home_interface()
{

  string crt_act = "11";
  string upt_act = "22";
  string del_act = "33";
  string dis_act = "44";
  string fgt_inf = "55";
  string dis_all = "66";

  string user_input = "x";

  string interface_commands[10] = {
    "Create Student Account:        11",
    "Update Student Account:        22",
    "Delete Student Account:        33",
    "Display Student Account:       44",
    "Forgot Student Information:    55",
    "Display All Students Accounts: 66"
  };

  while (str_cmp(user_input, quit_l) != 0 || str_cmp(user_input, quit_U) != 0)
  {

    cout << "\n\t\t\t** Welcome To The Control Center! **\n\n";
    cout << "\t\t\tHere Is Where You Can Create And/Or Edit The School"
        << " Wide Student Database!\n";
    cout << "\t\t\tPlease Continue By Typing In The Following Necessary"
        << " Commands Followed By Enter!\n\n";

    cout << '\n';
    for (int i = 0; i < str_arr_length(interface_commands); i++)
        cout << "\t\t\t" << i + 1 << ". " << interface_commands[i] << '\n';

    cout << "\n\t\t\t - - > ";
    cin >> user_input;

    if (str_cmp(user_input, quit_l) == 0 || str_cmp(user_input, quit_U) == 0)
    {
      cout << "\n\t\t\tExiting Interface..." << '\n';
      break;
    } else if (str_cmp(user_input, crt_act) == 0)
    {
      create_student();
    } else if (str_cmp(user_input, upt_act) == 0)
    {
      if (dt >= 1)
      {
        update_student();
      } else
      {
        cout << "\n\t\t\t** Sorry There Are No Students In This Database **" << '\n';
        continue;
      }
    } else if (str_cmp(user_input, del_act) == 0)
    {
      // delete_student();
    } else if (str_cmp(user_input, dis_act) == 0)
    {
      if (dt >= 1)
      {
        display_student();
      } else
      {
        cout << "\n\t\t\t** Sorry There Are No Students In This Database **" << '\n';
        continue;
      }
    } else if (str_cmp(user_input, dis_all) == 0)
    {
      if (dt >= 1)
      {
        display_all_students();
      } else
      {
        cout << "\n\t\t\t** Sorry There Are No Students In This Database **" << '\n';
        continue;
      }
    } else
    {
      cout << "\n\t\t\tSorry I don't Recognize That Command..." << '\n';
      continue;
    }

  }

}
