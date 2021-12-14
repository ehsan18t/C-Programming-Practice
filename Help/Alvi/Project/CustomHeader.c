#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

ArrayList_Contact *createList(int capacity)
{
    ArrayList_Contact *list = (ArrayList_Contact *)malloc(sizeof(ArrayList_Contact));
    Contact *arr = (Contact *)malloc(sizeof(Contact) * capacity);
    list->head = arr;
    list->size = 0;
    list->capacity = capacity;
    return list;
}

Contact *createContact(char *name, char *phone, char *email)
{
    Contact *newContact = (Contact *)malloc(sizeof(Contact));
    strcpy(newContact->name, name);
    strcpy(newContact->phone, phone);
    strcpy(newContact->email, email);
    return newContact;
}

void recreateList(ArrayList_Contact *list)
{
    Contact *temp = list->head;
    Contact *newArr = (Contact *)malloc(sizeof(Contact) * (list->capacity + (list->capacity * 0.5)));
    memcpy(newArr, temp, sizeof(Contact) * list->capacity);
    list->capacity += (list->capacity * 0.5);
    list->head = newArr;
    free(temp);
}

// O(1
void add_contact(ArrayList_Contact *list, Contact *contact)
{
    if (list->capacity == list->size)
    {
        recreateList(list);
    }
    Contact *index = list->head + list->size;
    memcpy(index, contact, sizeof(Contact));
    free(contact);

    list->size++;
}

// O(log n)
int bin_search_contact(ArrayList_Contact *list, char *name)
{
    int left = 0;
    int right = list->size - 1;
    int mid;
    Contact *contact;
    while (left <= right)
    {
        mid = (left + right) / 2;
        contact = list->head + mid;
        if (stricmp(contact->name, name) == 0)
        {
            return mid;
        }
        else if (stricmp(contact->name, name) > 0)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return -1;
}

// ideally O(n)
void add_contact_at(ArrayList_Contact *list, Contact *contact, int index)
{
    if (index < 0 || index > list->size)
    {
        printf("Index out of range\n");
        return;
    }

    if (list->capacity == list->size)
        recreateList(list);

    // right shift
    for (int i = list->size; i > index; i--)
        list->head[i] = list->head[i - 1];

    // place new contact
    list->head[index] = *contact;
    list->size++;
    free(contact);
}

// O(n)
void add_contact_sorted(ArrayList_Contact *list, Contact *contact)
{
    if (list->capacity == list->size)
        recreateList(list);

    int i = 0;

    // ascending sorted
    while (i < list->size && stricmp(list->head[i].name, contact->name) < 0)
        i++;
    add_contact_at(list, contact, i);
    write_contacts("contacts.txt", list);
}

// ideally O(n)
void remove_contact_at(ArrayList_Contact *list, int index)
{
    if (index < 0 || index > list->size)
    {
        printf("Index out of range\n");
        return;
    }

    if (list->size == 0)
    {
        printf("List is empty\n");
        return;
    }

    // left shift
    for (int i = index; i < list->size; i++)
        list->head[i] = list->head[i - 1];
    list->size--;
    sort_contact_asc(list);
    write_contacts("contacts.txt", list);
}

// O(1) -- Because the loop will run once
void remove_contact(ArrayList_Contact *list)
{
    remove_contact_at(list, list->size - 1);
    sort_contact_asc(list);
    write_contacts("contacts.txt", list);
}

// O(1)
void replace_contact_at(ArrayList_Contact *list, Contact *contact, int index)
{
    list->head[index] = *contact;
    free(contact);
    sort_contact_asc(list);
    write_contacts("contacts.txt", list);
}

// O(1)
void swap_contact(ArrayList_Contact *list, Contact *contact1, Contact *contact2)
{
    Contact *temp = contact1;
    if (contact1 == NULL || contact2 == NULL)
    {
        printf("Contact is NULL\n");
        return;
    }
    if (contact1 == contact2)
    {
        printf("Contact is same\n");
        return;
    }

    contact1 = contact2;
    contact2 = temp;
}

// O(1)
Contact get_contact(ArrayList_Contact *list, int index)
{
    if (index < 0 || index >= list->size)
    {
        printf("Index out of range\n");
        return list->head[0];
    }
    return *(list->head + index);
}

// O(1)
void clear_contacts(ArrayList_Contact *list)
{
    memset(list->head, 0, sizeof(Contact) * list->capacity);
    free(list->head);
    free(list);
    list = createList(10);
}

// O(n)
void print_contacts_range(ArrayList_Contact *list, int start, int end)
{
    Contact temp;

    for (int i = start; i < end; i++)
    {
        temp = get_contact(list, i);
        printf("[%.3d] %s\n", i + 1, temp.name);
        printf("      %s\n", temp.phone);
        printf("      %s\n\n", temp.email);
    }
}

// O(n)
void print_contacts(ArrayList_Contact *list)
{
    print_contacts_range(list, 0, list->size);
}

// replacement Sort --- O(n^2)
int sort_contact_asc(ArrayList_Contact *list)
{
    int flag = 0;
    Contact temp;
    for (int i = 0; i < list->size - 1; i++)
    {
        for (int j = i + 1; j < list->size; j++)
        {
            if (stricmp(list->head[i].name, list->head[j].name) > 0)
            {
                flag = 1;
                temp = list->head[i];
                list->head[i] = list->head[j];
                list->head[j] = temp;
            }
        }
    }
    return flag;
}

// O(n)
ArrayList_Contact *read_contacts(char *filename)
{
    ArrayList_Contact *list = createList(10);
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        fclose(file);
        file = fopen(filename, "w");
        fclose(file);
        return list;
    }
    Contact *contact;
    char line[100];
    char *token;

    while (fscanf(file, "%s", line) != EOF)
    {
        contact = (Contact *)malloc(sizeof(Contact));

        token = strtok(line, ",");
        strcpy(contact->name, token);
        token = strtok(NULL, ",");
        strcpy(contact->phone, token);
        token = strtok(NULL, ",");
        strcpy(contact->email, token);
        token = strtok(NULL, ",");

        // adding contact to list
        add_contact(list, contact);
    }
    fclose(file);
    int flag = sort_contact_asc(list);
    if (flag)
    {
        write_contacts("contacts.txt", list);
        printf("Sorted\n");
    }
    return list;
}

// O(n)
void write_contacts(char *filename, ArrayList_Contact *list)
{
    FILE *file = fopen(filename, "w");
    Contact *contact = list->head;
    int i = 0;
    while (i < list->size)
    {
        fprintf(file, "%s,%s,%s\n", contact[i].name, contact[i].phone, contact[i].email);
        i++;
    }
    fclose(file);
}

void clearBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

void clearScreen()
{
    // clearBuffer();
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void invalidInput()
{
    printf("Invalid input!\n");
}

void add_contact_screen(ArrayList_Contact *list)
{
    char name[20];
    char phone[20];
    char email[20];
    printf("Enter Name: ");
    clearBuffer();
    gets(name);
    printf("Enter Phone: ");
    scanf("%s", phone);
    printf("Enter Email: ");
    scanf("%s", email);
    add_contact_sorted(list, createContact(name, phone, email));
    printf("Contact Added!\n\n");
}

int *search_contact(ArrayList_Contact *list, char *name)
{
    int flag = 0;
    int *index = (int *)malloc(sizeof(int) * 2);
    Contact *temp = list->head;
    for (int i = 0; i < list->size; i++)
    {
        if (stricmp(name, temp[i].name) == 0)
        {
            if (flag == 0)
                index[0] = i;
            index[1] = i;
            flag = 1;
        }
    }
    return index;
}

void search_contact_screen(ArrayList_Contact *list)
{
    int len;
    char name[20];
    printf("Enter Name: ");
    clearBuffer();
    gets(name);
    // multiple contacts can be found
    printf("\n");
    int *contacts = search_contact(list, name);
    print_contacts_range(list, contacts[0], contacts[1] + 1);
}

void modify_contact_screen(ArrayList_Contact *list)
{
    char name[20];
    char phone[20];
    char email[20];
    int serial;
    printf("Enter Contact Serial: ");
    scanf("%d", &serial);
    printf("Enter New Name: ");
    clearBuffer();
    gets(name);
    printf("Enter New Phone: ");
    scanf("%s", phone);
    printf("Enter New Email: ");
    scanf("%s", email);
    replace_contact_at(list, createContact(name, phone, email), serial - 1);
    printf("Contact Modified!\n\n");
}

void delete_contact_screen(ArrayList_Contact *list)
{
    int serial;
    printf("Enter Contact Serial: ");
    scanf("%d", &serial);
    remove_contact_at(list, serial - 1);
    printf("Contact Deleted!\n\n");
}

void pause_screen()
{
    printf("Press any key to continue...");
    getch();
}