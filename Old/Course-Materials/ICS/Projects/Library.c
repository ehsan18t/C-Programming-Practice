#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

///Book Structure

struct Book
{
    char title[40];
    char writer[40];
    float price;
};
///Global Variable.

int count = 0;
int size;
char bookTitle[40];

void addBooks();
void viewBooks();
void searchbook();
void removeBook();
void editBook();



///Main Function

int main()
{
    int n;
    struct Book*book;
    printf("\t\t\t\tWelcome To Library\n");
    system("color 7");
    printf("\n\t\t\t\t   1.Add Book.\n\t\t\t\t   2.View All Books.\n\t\t\t\t   3.Search Book.\n\t\t\t\t   4.Edit Book.\n\t\t\t\t   5.Remove Book.\n\t\t\t\t   6.Return.\n");
    scanf("%d",&n);
    switch(n)
    {
        case 1:
            addBooks();
            break;
        case 2:
            viewBooks();
            break;
        case 3:
            searchbook();
            break;
        case 4:
            editBook();
            break;
        case 5:
            removeBook();
            break;
        case 6:
            return 0;
        default:
            return 0;
    }
    getch();
}





//Add New Books.

void addBooks()
{
    int n;
    printf("Press 1 to Main Menu  : \nPress 2 to Add Book  : \n");
    scanf("%d",&n);
    switch(n)
    {
        case 1:
            system("cls");
            main();
            break;
        case 2:
            system("cls");
    }
    struct Book *book = NULL;
    system("cls");
    // system("color 18");
    printf("\n############## Add New Books ##############\n");
    printf("Enter Book Title : \n");
    fflush(stdin);
    fgets(book[count].title, 40,stdin);
    fflush(stdout);
    ///getch();
    printf("\nEnter Book Writer : \n");
    fflush(stdin);
    fgets(book[count].writer,40,stdin);
    fflush(stdout);
    ///getch();
    printf("\nEnter Book Price : \n");
    scanf("%f",&book[count].price);
    count++;
}


//View All Books

void viewBooks()
{
    int n;
    printf("Press 1 to Main Menu  : \nPress 2 to View Books  : \n");
    scanf("%d",&n);
    switch(n)
    {
        case 1:
            system("cls");
            main();
            break;
        case 2:
            system("cls");
    }
    int i;
    system("cls");
    system("color 58");
    printf("\n\n\n\t\t\t********* Books Details *********");
    printf("\n\n\t\t--------------------------------------");
    printf("\n\t\tBOOK TITLE\t\tBOOK WRITER\t\tBOOK PRICE\t\n\n");
    for(i = 0; i<count; i++)
    {
        struct Book*book;
        printf("\n\t\t%s",book[i].title);
        printf("\t\t%s",book[i].writer);
        printf("\t\t%.2f\n",book[i].price);
    }
}


///Search Book

void searchbook()
{
    //char bookTitle[40];
    int n;
    printf("Press 1 to Main Menu  : \nPress 2 to Search Book  : \n");
    scanf("%d",&n);
    switch(n)
    {
        case 1:
            system("cls");
            main();
            break;
        case 2:
            system("cls");
    }

    printf("\nEnter Book Title for Search : \n");
    gets(bookTitle);
    struct Book*book;
    for(int i=0; i<count; i++)
    {
        if(strcmp(book[i].title,bookTitle)==0)
        {
            system("cls");
            system("color 44");
            printf("\n\n\n\t\t\t@@@@@@@@@ Search Book Details @@@@@@@@@");
            printf("\n\t\t\tBook Title  :  %s",book[i].title);
            printf("\n\t\t\tBook Writer  :  %s",book[i].writer);
            printf("\n\t\t\tBook Title  :  %.2f\n",book[i].price);
        }
    }
}

///Remove Book

void removeBook()
{
    ///char bookTitle[40];
    int n;
    printf("Press 1 to Main Menu  : \nPress 2 to Remove Book  : \n");
    scanf("%d",&n);
    switch(n)
    {
        case 1:
            system("cls");
            main();
            break;
        case 2:
            system("cls");
    }
    struct Book*book;
    printf("\nEnter Book Title for Remove Book : \n");
    gets(bookTitle);
    for(int i=0; i<count; i++)
    {
        if(strcmp(book[i].title,bookTitle)==0)
        {
            system("cls");
            system("color 27");
            printf("\n\n\n\t\t\t Remove Book Details : ");
            printf("\n\t\t\t Book Title  :  %s",book[i].title);
            printf("\n\t\t\t Book Writer  :  %s\n",book[i].writer);
            ///Overwrite The value for Sequence.
            for(int j =i; j<count-1; j++)
            {
                book = book+1;
            }
            count--;
            main();
        }
    }
}



///Edit Book
void editBook()
{
    ///char bookTitle[40];
    int n;
    printf("Press 1 to Main Menu  : \nPress 2 to Edit Book  : \n");
    scanf("%d",&n);
    switch(n)
    {
        case 1:
            system("cls");
            main();
            break;
        case 2:
            system("cls");
    }

    struct Book *book = NULL;
    printf("\nEnter Book Title To Edit : ");
    gets(bookTitle);
    for(int i=0; i<count; i++)
    {
        if(strcmp(book[i].title,bookTitle)==0)
        {
            system("cls");
            system("color 19");
            printf("\n\n\n\t\t\t ********* Book Details *********");
            printf("\n\n\n\t\t\t Book Title  :  %s",book[i].title);
            printf("\n\t\t\t Book Writer  :  %s",book[i].writer);
            printf("\n\t\t\t Book Price  :  %f",book[i].price);



            ///Add Book



            printf("\n**********Add New Book Details *********");
            printf("\nEnter Book Title  :  ");
            gets(book[i].title);
            printf("\nEnter Book Writer  :  ");
            //fflush(stdin);
            gets(book[i].writer);
            printf("\nEnter Book Price  :  ");
            scanf("%f",&book[i].price);
        }
    }
}
