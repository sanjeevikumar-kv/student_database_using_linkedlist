#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Student
{
  char name[50];
  int age;
  int clg_year;
  float gpa;
  float cgpa;
  int roll;
  struct Student *next;
};

struct Student * createNode (char name[], int age, int clg_year, float gpa, float cgpa,
	    int roll)
{
  struct Student *newNode =
    (struct Student *) malloc (sizeof (struct Student));
  strcpy (newNode->name, name);
  newNode->age = age;
  newNode->clg_year = clg_year;
  newNode->gpa = gpa;
  newNode->cgpa = cgpa;
  newNode->roll = roll;
  newNode->next = NULL;
  return newNode;
}
void insertStudent(struct Student **head, char name[], int age, int clg_year, float gpa, float cgpa, int roll)
{
    struct Student *newNode = createNode(name, age, clg_year, gpa, cgpa, roll);
    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        struct Student *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}
void displaySpecificStudent (struct Student *head, char username[], int password)
{
  struct Student *temp = head;
  int found = 0;
  while (temp != NULL)
    {
      if (strcmp (temp->name, username) == 0 && temp->roll == password)
	{
	  printf ("Student Details:\n");
	  printf ("Name: %s\n", temp->name);
	  printf("Roll No:%d\n",temp->roll);
	  printf ("Age: %d\n", temp->age);
	  printf ("College Year: %d\n", temp->clg_year);
	  printf ("GPA: %.2f\n", temp->gpa);
	  printf ("CGPA: %.2f\n", temp->cgpa);
	  found = 1;
	  break;
	}
      temp = temp->next;
    }
  if (!found)
    {
      printf("Details not Found.\n");
    }
}
void login(struct Student *head, char username[], int password)
{
  struct Student *temp = head;
  int found = 0;
  while (temp != NULL)
    {
      if (strcmp (temp->name, username) == 0 && temp->roll == password)
	{
	  printf ("Login Successfully.\n");
	  found = 1;
	  break;
	}
      temp = temp->next;
    }
  if (!found)
    {
      printf
	("Invalid username or password.\n");
    }
}
void editStudentDetails(struct Student *head, char username[], int password, int roll) {
  struct Student *temp = head;
  int found = 0;
  while (temp != NULL) {
    if (strcmp(temp->name, username) == 0 && temp->roll == password) {
      found = 1;
      break;
    }
    temp = temp->next;
  }
  if (found) {
    while (temp != NULL) {
      if (temp->roll == roll) {
        printf("Enter Name: ");
        scanf("%s", temp->name);
        
        printf("Enter Age: ");
        scanf("%d", &temp->age);
        
        printf("Enter College Year: ");
        scanf("%d", &temp->clg_year);
        
        printf("Enter GPA: ");
        scanf("%f", &temp->gpa);
        
        printf("Enter CGPA: ");
        scanf("%f", &temp->cgpa);
        
        printf("Student Details Updated Successfully.\n");
        break;
      }
      temp = temp->next;
    }
  } else {
    printf("Invalid username or password.\n");
  }
}
int main ()
{
    char name[50];
    int age,clg_year;
    float gpa,cgpa; int roll;
  struct Student *head = NULL;
    int password,n=1,c,i=0;
  char username[50];
      insertStudent (&head, "Kumar", 23, 4, 3.7, 3.5, 123);
    insertStudent (&head, "Raja", 21, 4, 3.7, 3.5, 101);
  insertStudent (&head, "Raju", 20, 3, 3.5, 3.2, 102);
  while(n){
  printf(" >>Student Database<<\n");
  printf("Options\n");
  printf("------------------------------");
  if(i==0)
  printf("\n   1,Login");
  printf("\n   2,Display Student Details.\n   3,Insert Student Details.\n   4,Edit Student Details.\n");
  if(i==1)
  printf("   5,Logout\n");
    printf("------------------------------");
  printf("\nEnter Your Choice:");scanf("%d",&c);
  switch(c){
      
      case 1:
  printf ("Enter your username: ");
  scanf ("%s", username);
  printf ("Enter your password : ");
  scanf ("%d", &password);
  login(head,username,password);i=1;
  break;
  
  case 2:
  if(i==1){
          printf ("Enter Student Name: ");
  scanf ("%s", username);
  printf ("Enter Student Roll No: ");
  scanf ("%d", &password);
  displaySpecificStudent (head, username, password);
  
  }else {
      printf("Login to Display Student Details.\n");
      printf ("Enter your username: ");
  scanf ("%s", username);
  printf ("Enter your password: ");
  scanf ("%d", &password);
  login(head,username,password);i=1;
  }break;
  case 3:
  if(i==1){
  printf("Enter Name of Student:");
  scanf("%s",name);
  printf("Enter Age:");
  scanf("%d",&age);
  printf("Enter College Year:");
  scanf("%d",&clg_year);
  printf("Enter GPA:");
  scanf("%f",&gpa);
  printf("Enter CGPA:");
  scanf("%f",&cgpa);
  printf("Enter Roll No:");
  scanf("%d",&roll);
insertStudent (&head, name,age, clg_year,gpa,cgpa, roll);
    printf("Student detail Inserted to Database.\n");

}
else {
      printf("Login to Insert Student Details.\n");
      printf ("Enter your username: ");
  scanf ("%s", username);
  printf ("Enter your password: ");
  scanf ("%d", &password);
  login(head,username,password);i=1;
  }break;
  case 4:
  if(i==1){
      printf("Enter Student Roll No:");
      
      scanf("%d",&roll);
       editStudentDetails(head, username, password, roll);
  } else {
    printf("Login to Edit Student Details.\n");
    printf ("Enter your username: ");
  scanf ("%s", username);
  printf ("Enter your password: ");
  scanf ("%d", &password);
    login(head, username, password);i=1;
    i = 1;
  }
  break;
  case 5:
  i=0;
  printf("Logout Successfully!\n");
  break;
  default:
  printf("Invalid Choice");
  }
  printf("To continue Enter 1 otherwise 0:");
  scanf("%d",&n);
}
return 0;
}

