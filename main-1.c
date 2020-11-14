#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

typedef struct student
{
    char *f_l_name;
    int id, password;
} student;

typedef struct book
{
    char *name;
    int id;
} book;

int a = 0;
int b = 0;

void menu(int y);
void registerr(void);
void view_registered(void);
void add_book(void);
void view_books(void);
void search_book(void);

book books[9];
student students_list[9];

int main()
{
    SetConsoleTitle("SIC-Library");
    int y = 0;
    menu(y);
    return 0;
}

void add_book(void)
{
    //Function to add books using ID and Name
    int y = 0;
    char buff;
    scanf("%c",&buff);
    printf("Book name: ");
    char *n = malloc(40);
    scanf("%[^\n]",n);
    int i, x = strlen(n) + 1;
    books[a].name = malloc(x);
    for (i = 0; i < x; i++)
    {
        books[a].name[i] = n[i];
    }
    free(n);
    printf("Book ID: ");
    scanf("%d",&books[a].id);
    a++;
    menu(y);
}

void view_books(void)
{
    //Function to view all books
    int i, y = 0;
    printf("\nBook Name - ID\n");
    for (i = 0; i < a; i++)
    {
        printf("%s - %d\n",books[i].name,books[i].id);
    }
    menu(y);
}

void search_book(void)
{
    //Function to search for a book
    int i, id, n = 0, y = 0;
    char *s = malloc(40);
    char buff;
    printf("1) Search by name \t2) Search by ID \n");
    scanf("%d",&n);
    scanf("%c",&buff);
    if (n == 1)
    {
        printf("Enter book name: ");
        scanf("%[^\n]",s);
        int x = strlen(s) + 1;
        char *f = malloc(x);
        for (i = 0; i < x; i++)
        {
            f[i] = s[i];
        }
        for (i = 0; i < a; i++)
        {
            if (!strcmp(f, books[i].name))
            {
                printf("\nBook Name - ID\n");
                printf("%s - %d\n",books[i].name, books[i].id);
                break;
            }
        }
    }
    else if (n == 2)
    {
        printf("Enter book ID: ");
        scanf("%d",&id);
        scanf("%c",&buff);
        for (i = 0; i < a; i++)
        {
            if (id == books[i].id)
            {
                printf("\nBook Name - ID\n");
                printf("%s - %d\n",books[i].name, books[i].id);
                break;
            }
        }
    }
    else printf("You have to enter 1 or 2 only \n");
    menu(y);
}


void menu(int y)
{
    //Function to let the user choose one from the presented operation
    int z;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
    printf("Choose one of the the operations below : \n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
    printf("[0] Register \n");
    printf("[1] Registered students \n");
    printf("[2] Add a book \n");
    printf("[3] View books \n");
    printf("[4] Search for a book \n");
    printf("[5] Exit \n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE);
    scanf("%d", &y);
    if(y == 0)
    {
        registerr();
    }
    else if(y == 1)
    {
        view_registered();
    }
    else if(y == 2)
    {
        add_book();
    }
    else if(y == 3)
    {
        view_books();
    }
    else if(y == 4)
    {
        search_book();
    }
    else if(y == 5)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
        printf("We are sad that your are going :( \n");
        printf("Leave your feedback out of 5  : \n");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE);
        scanf("%d", &z);
        if(z > 0 && z <= 3)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
            printf("We will improve our service. \n");
            printf("Thank you for your feedback :) \n");
        }
        else if(z > 3 && z <= 5)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
            printf("Thank you for your feedback :) \n");
            printf("Hope you enjoyed our tour. \n");
        }
    }
    else
        printf("Invalid number. Try again! \n");
}

void registerr(void)
{
    //Function enables user to register
    int y = 0;
    char yy;
    printf("1- Enter your first and last name : ");
    char *n = malloc(40);
    if (b > 0)
        scanf("%c",&yy);
    scanf("%[^\n]",n);
    int i, x = strlen(n) + 1;
    students_list[b].f_l_name = malloc(x);
    for (i = 0; i < x; i++)
    {
        students_list[b].f_l_name[i] = n[i];
    }
    free(n);
    printf("\n2- Enter your id number :");
    scanf("%d",&students_list[b].id);
    b++;
    printf("3- Enter your password : ");
    scanf("%d",&students_list[b].password);
    b++;
    menu(y);
}

void view_registered(void)
{
    //Function to view all the stored users
    int i, y = 0;
    printf("\nFirst and last name - ID - Password\n");
    for (i = 0; i < b; i++)
    {
        printf("%s - %d - %d\n",students_list[i].f_l_name, students_list[i].id, students_list[i].password);
    }
    menu(y);
}

