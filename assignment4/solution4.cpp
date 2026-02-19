#include <stdio.h>
#include <string.h> // For strcmp to display the stored data and compare it with other
#define MAX_STUDENTS 50// STUDENTS ARE LIMIT TO 50 SO IF USER ADD >50 IT WILL CONVERTED INTO 10
#define MAX_COURSES 10  // I HAVE LIMIT MAX COURSE TO 10 IF USER ADD GREATER NUMBER IT WILL CONVERT INTO 10
                        

char course_id[MAX_COURSES][50]; // THESE  ARE GLOBAL VARIABLE SO THEY WILL MODIFY AND CAN USE EVERY WHERE 
char course_name[MAX_COURSES][50];
int max_marks[MAX_COURSES];
int credit_hours[MAX_COURSES];

char studentId[MAX_STUDENTS][50];
char student_name[MAX_STUDENTS][50];

int obtained_marks[MAX_STUDENTS][MAX_COURSES];
int Attendence[MAX_STUDENTS][MAX_COURSES];

float student_gpa[MAX_STUDENTS];

int num_courses;
int num_students;

// ---------------- GPA Calculation ----------------//
float calculate_gpa(int marks, int maxMarks, int credits)
{
    return ((float)marks / maxMarks) * 4;   // FORMULA GIVEN IN ASSIGMENT
}

// ---------------- Enter Attendance ----------------//
void enter_attendance()
{   
    printf("\n____________ENTER THE ATTENDENCE OF STUDENTS______________\n");
    for (int i = 0; i < num_students; i++)
        for (int j = 0; j < num_courses; j++)
        {
            int input = 0;
            while (!input)
            {
                printf("Enter attendance of %s in %s: ", studentId[i], course_id[j]);
                scanf("%d", &Attendence[i][j]);
                if (Attendence[i][j] >= 0 && Attendence[i][j] <= 100) input = 1;
                else printf("Invalid! Enter attendance 0–100.\n");
            }
        }
}

// ---------------- Enter Marks ----------------//
void enter_marks()
{
    for (int i = 0; i < num_students; i++)
    {
        printf("\nEnter marks for %s (%s):\n", studentId[i], student_name[i]);
        for (int j = 0; j < num_courses; j++)
        {
            int input = 0;
            while (!input) // INPUT VALIDATION IF USER ENTER WRONG NUMBBER IT ASK HIM TO RE-ENTER THE VALUE
            {
                printf("Enter obtained marks for %s: ", course_id[j]);
                scanf("%d", &obtained_marks[i][j]);
                if (obtained_marks[i][j] >= 0 && obtained_marks[i][j] <= max_marks[j]) input = 1;
                else printf("Invalid! Enter marks 0–%d.\n", max_marks[j]);
            }
        }
    }
}

// ---------------- Enter Courses ----------------
void enter_courses()
{   
    printf("\n__________________________\n");
    printf("\n__COURSE INFORMATION__\n");
    printf("\n__________________________\n");
    for (int i = 0; i < num_courses; i++)
    {
        printf("\nEnter course %d ID: ", i + 1);
        scanf("%s", course_id[i]);
        printf("Enter course %d name: ", i + 1);
        scanf("%s", course_name[i]);

        int input = 0;
        while (!input)// IINPUT VALIDATION
        {
            printf("Enter max marks of course %d: ", i + 1);
            scanf("%d", &max_marks[i]);
            if (max_marks[i] >= 1 && max_marks[i] <= 100) input = 1;
            else printf("Invalid! Enter marks 1–100.\n");
        }

        input = 0;
        while (!input) // CREDIT HOURS VALIDATION
        {
            printf("Enter credit hours: ");
            scanf("%d", &credit_hours[i]);
            if (credit_hours[i] >= 1) input = 1;
            else printf("Invalid! Enter credit hours >=1.\n");
        }
    }
}

// ---------------- Enter Students ----------------
void enter_students()
{ 
    printf("\n__________________________\n");
    printf("\n___ENTERING DATA...____\n");
    printf("\n__________________________\n");
    printf("\n___STUDENTS____\n");
    
    while (1)
    {
        printf("Enter number of students: ");
        scanf("%d", &num_students);
        if (num_students >= 1 && num_students <= MAX_STUDENTS) break;
        printf("Invalid! Enter number of students 1-%d\n", MAX_STUDENTS);
    }
    
    printf("\n___COURSES____\n");
    while (1)
    {
        printf("Enter number of courses: ");
        scanf("%d", &num_courses);
        if (num_courses >= 1 && num_courses <= MAX_COURSES) break;
        printf("Invalid! Enter number of courses 1-%d\n", MAX_COURSES);
    }

    printf("\n___STUDENTS INFORMATION____\n");
    for (int i = 0; i < num_students; i++)
    {
        printf("\nEnter student %d ID: ", i + 1);
        scanf("%s", studentId[i]);
        printf("Enter student %d name: ", i + 1);
        scanf("%s", student_name[i]);
    }

    enter_courses();
    enter_marks();
    enter_attendance();
}

// ---------------- Display Student Report ----------------
void display_data()
{
    printf("\n================= STUDENT REPORT =================\n");

    float best_gpa = -1;
    int best_index = 0;

    for (int i = 0; i < num_students; i++)
    {
        float total_weighted_gpa = 0;
        int total_credits = 0;

        printf("\n--------------------------------------------------\n");
        printf("Student ID   : %s\n", studentId[i]);
        printf("Student Name : %s\n", student_name[i]);
        printf("--------------------------------------------------\n");

        printf("%-10s %-10s %-8s %-8s %-5s %-7s\n",
               "CourseID", "Name", "Marks", "Max", "GPA", "Attend");
        printf("--------------------------------------------------\n");

        for (int j = 0; j < num_courses; j++)
        {
            float course_gpa = calculate_gpa(obtained_marks[i][j], max_marks[j], credit_hours[j]);
            total_weighted_gpa += course_gpa * credit_hours[j];
            total_credits += credit_hours[j];

            printf("%-10s %-10s %3d/%-6d %-5.2f %-7d\n",
                   course_id[j], course_name[j], obtained_marks[i][j],
                   max_marks[j], course_gpa, Attendence[i][j]);
        }

        float cgpa = total_weighted_gpa / total_credits;
        student_gpa[i] = cgpa;

        printf("--------------------------------------------------\n");
        printf("Cumulative GPA : %.2f\n", cgpa);

        if (cgpa > best_gpa) { best_gpa = cgpa; best_index = i; }
    }

    printf("\n================ TOP STUDENT ================\n");
    printf("%s (%s) | GPA = %.2f\n",
           studentId[best_index], student_name[best_index], best_gpa);
}

// ---------------- Display Course Report ----------------
void display_course_report()
{
    char cid[50];    //cid is temporary used to compare the enterd input with store
    int course_index = -1;

    printf("Enter Course ID: ");
    scanf("%s", cid);

    for (int j = 0; j < num_courses; j++)
        if (strcmp(cid, course_id[j]) == 0) course_index = j;

    if (course_index == -1) { printf("Course ID not found.\n"); return; }

    printf("\n=========== COURSE REPORT (%s - %s) ===========\n",
           course_id[course_index], course_name[course_index]);

    printf("%-12s %-12s %-8s %-8s %-5s\n", "StudentID", "Name", "Marks", "Attend", "GPA");
    printf("------------------------------------------------------\n");

    int highest = obtained_marks[0][course_index];
    int lowest = obtained_marks[0][course_index];
    float total_marks = 0, total_att = 0;

    for (int i = 0; i < num_students; i++)
    {
        int marks = obtained_marks[i][course_index];
        int att = Attendence[i][course_index];
        float gpa_val = calculate_gpa(marks, max_marks[course_index], credit_hours[course_index]);

        printf("%-12s %-12s %-8d %-8d %-5.2f\n",
               studentId[i], student_name[i], marks, att, gpa_val);

        if (marks > highest) highest = marks;
        if (marks < lowest) lowest = marks;

        total_marks += marks;
        total_att += att;
    }

    printf("------------------------------------------------------\n");
    printf("Highest Marks      : %d\n", highest);
    printf("Lowest Marks       : %d\n", lowest);
    printf("Average Marks      : %.2f\n", total_marks / num_students);
    printf("Average Attendance : %.2f%%\n", total_att / num_students);
}

// ---------------- Topper ----------------
void display_topper()
{
    float max_gpa = 0;
    for (int i = 0; i < num_students; i++)
        if (student_gpa[i] > max_gpa) max_gpa = student_gpa[i];

    printf("\nTopper(s):\n");
    for (int i = 0; i < num_students; i++)
        if (student_gpa[i] == max_gpa)
            printf("%s %s | GPA: %.2f\n", studentId[i], student_name[i], student_gpa[i]);
}

// ---------------- Attendance Warning ----------------
void attendance_warning_list()
{
    printf("\n=========== ATTENDANCE WARNING (<75%%) ===========\n");
    printf("%-12s %-12s\n", "StudentID", "Name");
    printf("-------------------------------------\n");

    for (int i = 0; i < num_students; i++)
    {
        int warn = 0;
        for (int j = 0; j < num_courses; j++)  // IF ANY STUDENTS ATTENDENCE IS LESS THEN 75//
            if (Attendence[i][j] < 75)        // IT WILL STORE HIS/HER NAME IN WARNING LIST//
            warn = 1;

        if (warn) printf("%-12s %-12s\n", studentId[i], student_name[i]);
    }
}

// ---------------- Search Student ----------------
void search_student()
{
    char key[50];
    printf("Enter Student ID or Name: ");
    scanf("%s", key);

    int found = 0;
    for (int i = 0; i < num_students; i++)
        if (strcmp(key, studentId[i]) == 0 || strcmp(key, student_name[i]) == 0)
        {
            printf("Found: %s %s\n", studentId[i], student_name[i]);
            found = 1;
        }
    if (!found) printf("Student not found.\n");
}

// ---------------- Search Course ----------------
void search_course()
{
    char key[50];
    printf("Enter Course ID or Name: ");
    scanf("%s", key);

    int found = 0;
    for (int j = 0; j < num_courses; j++)
        if (strcmp(key, course_id[j]) == 0 || strcmp(key, course_name[j]) == 0)
                                        //THIS WILL COMPARE THE STRING WITH THIS key TO FIND THE REQUIRED COURSE.
        {   
            printf("\t\t Finding Course....\n");
            printf("Found Course: %s %s\n", course_id[j], course_name[j]);
            found = 1;
        }
    if (!found) 
    {    printf("\t\t Finding Course....\n");
        printf("Course not found.\n");
    }
}

// ---------------- Edit Student ----------------
void edit_student()
{
    char id[50];
    printf("Enter Student ID to edit: ");
    scanf("%s", id);

    int i = -1;
    for (int s = 0; s < num_students; s++)
        if (strcmp(id, studentId[s]) == 0)
         { i = s; break; }

    if (i == -1)
     { printf("Student not found.\n");
         return; }

    int ch;
    printf("1.Edit Name  2.Edit Marks  3.Edit Attendance\nEnter: ");
    scanf("%d", &ch);

    if (ch == 1)
     { printf("New name: "); scanf("%s", student_name[i]); }
    else if (ch == 2)
    {
        int c; printf("Course (0-%d): ", num_courses - 1); scanf("%d", &c);
        if (c >= 0 && c < num_courses) 
        { printf("New marks: "); scanf("%d", &obtained_marks[i][c]); }
    }
    else if (ch == 3)
    {
        int c; printf("Course (0-%d): ", num_courses - 1); scanf("%d", &c);
        if (c >= 0 && c < num_courses)
         { printf("New attendance: "); scanf("%d", &Attendence[i][c]); }
    }
    else printf("Invalid choice!\n");
}

// ---------------- Sort Students by GPA ----------------
int total_marks(int s) {
    int sum = 0;
    for (int j = 0; j < num_courses; j++)
        sum += obtained_marks[s][j];
    return sum;
}

void calculate_all_gpa() {
    for (int i = 0; i < num_students; i++) {
        float total_weighted_gpa = 0;
        int total_credits = 0;
        for (int j = 0; j < num_courses; j++) {
            float course_gpa = calculate_gpa(obtained_marks[i][j], max_marks[j], credit_hours[j]);
            total_weighted_gpa += course_gpa * credit_hours[j];
            total_credits += credit_hours[j];
        }
        student_gpa[i] = total_weighted_gpa / total_credits;
    }
}

void sort_students_by_gpa() {
    calculate_all_gpa(); // ensure GPA is up-to-date

    for (int i = 0; i < num_students - 1; i++) {
        int best = i;
        for (int j = i + 1; j < num_students; j++)
            if (student_gpa[j] > student_gpa[best])
                best = j;

        if (best != i) {
            // swap GPA
            float tG = student_gpa[i];
            student_gpa[i] = student_gpa[best];
            student_gpa[best] = tG;

            // swap student IDs and names
            char temp[50];
            strcpy(temp, studentId[i]);
            strcpy(studentId[i], studentId[best]);
            strcpy(studentId[best], temp);

            strcpy(temp, student_name[i]);
            strcpy(student_name[i], student_name[best]);
            strcpy(student_name[best], temp);

            // swap marks and attendance
            for (int k = 0; k < num_courses; k++) {
                int t = obtained_marks[i][k];
                obtained_marks[i][k] = obtained_marks[best][k];
                obtained_marks[best][k] = t;

                t = Attendence[i][k];
                Attendence[i][k] = Attendence[best][k];
                Attendence[best][k] = t;
            }
        }
    }
    printf("\nStudents sorted by GPA (High → Low)\n");
    display_data();
}

// ---------------- Sort Students by Total Marks ----------------
void sort_students_by_total_marks() {
    for (int i = 0; i < num_students - 1; i++) {
        int best = i;
        for (int j = i + 1; j < num_students; j++)
            if (total_marks(j) > total_marks(best))
                best = j;

        if (best != i) {
            // swap student IDs and names
            char temp[50];
            strcpy(temp, studentId[i]);
            strcpy(studentId[i], studentId[best]);
            strcpy(studentId[best], temp);

            strcpy(temp, student_name[i]);
            strcpy(student_name[i], student_name[best]);
            strcpy(student_name[best], temp);

            // swap marks, attendance, and GPA
            for (int k = 0; k < num_courses; k++) {
                int t = obtained_marks[i][k];
                obtained_marks[i][k] = obtained_marks[best][k];
                obtained_marks[best][k] = t;

                t = Attendence[i][k];
                Attendence[i][k] = Attendence[best][k];
                Attendence[best][k] = t;
            }

            float tG = student_gpa[i];
            student_gpa[i] = student_gpa[best];
            student_gpa[best] = tG;
        }
    }
    printf("\nStudents sorted by TOTAL MARKS (High → Low)\n");
    display_data();
}

// ---------------- Menu ----------------
void display_menu()
{
    int choice;
    do
    {    // WE CAN ALSO DO THIS WITH SWITCH 
        printf("\n--------------------------------FLEX-------------------------------------\n");
        printf("1.|Enroll Students| \t\t2.|Display Student Reports|\n3.|Display Course Report|\t");
        printf("4.|Display Topper|\n5.|Attendance Warning List|\t6.|Search Student|\n");
        printf("7.|Search Course|\t\t8.|Edit the data|\n");
        printf("9.|Sort Students by GPA|\t10.| Sort Students by Total Marks|\n11. | Exit|\n");
        printf("||Enter choice||: \n");
        printf("-------------------------------------------------------------------------\n");
        scanf("%d", &choice);

        if (choice == 1) enter_students();
        else if (choice == 2) display_data();
        else if (choice == 3) display_course_report();
        else if (choice == 4) display_topper();
        else if (choice == 5) attendance_warning_list();
        else if (choice == 6) search_student();
        else if (choice == 7) search_course();
        else if (choice == 8) edit_student();
        else if (choice == 9) sort_students_by_gpa();
        else if (choice == 10) sort_students_by_total_marks();
        else if (choice == 11) printf("EXITING...\n");
        else printf("Invalid choice!\n");

    } while (choice != 11);
}
int main()
{   // this display_menu() function take you to the menu 
    //where i have used if-else if ledder to acess different functions
    display_menu();
    return 0;
}