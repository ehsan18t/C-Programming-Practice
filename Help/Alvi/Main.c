#include <stdio.h>
#include "CustomHeader.h"
#include "CustomHeader.c"

void main_menu();
void header();

int main()
{
    ArrayList_Contact *list;
    list = read_contacts("contacts.txt");
    int loop = 1;
    int choice;
    while (loop)
    {
        clearScreen();
        header();
        main_menu();
        printf("Enter Option: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            /* Add */
            clearScreen();
            header();
            add_contact_screen(list);
            pause_screen();
            break;
        case 2:
            /* view */
            clearScreen();
            header();
            print_contacts(list);
            pause_screen();
            break;
        case 3:
            /* search */
            clearScreen();
            header();
            search_contact_screen(list);
            pause_screen();
            break;
        case 4:
            /* modify */
            clearScreen();
            header();
            modify_contact_screen(list);
            pause_screen();
            break;
        case 5:
            /* Delete */
            clearScreen();
            header();
            delete_contact_screen(list);
            pause_screen();
            break;
        case 6:
            /* Exit */
            loop = 0;
            free(list);
            break;
        default:
            clearBuffer();
            invalidInput();
            pause_screen();
            break;
        }
    }
    return 0;
}

void main_menu()
{
    printf("[1] Add Record\n");
    printf("[2] View List In Ascending Order\n");
    printf("[3] Search Record\n");
    printf("[4] Modify Record\n");
    printf("[5] Delete Record\n");
}

void header()
{
    printf("*******************************************\n");
    printf("*                                         *\n");
    printf("*          PhoneBook Application          *\n");
    printf("*                                         *\n");
    printf("*******************************************\n\n");
}