#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

struct contact
{
    char name[20];
    char phone[20];
    char email[20];
} typedef Contact;

struct ArrayList
{
    int size;
    int capacity;
    Contact *head;
} typedef ArrayList_Contact;

ArrayList_Contact *createList(int capacity);

Contact *createContact(char *name, char *phone, char *email);

void recreateList(ArrayList_Contact *list);

// O(1
void add_contact(ArrayList_Contact *list, Contact *contact);

// O(log n)
int bin_search_contact(ArrayList_Contact *list, char *name);

// ideally O(n)
void add_contact_at(ArrayList_Contact *list, Contact *contact, int index);

// O(n)
void add_contact_sorted(ArrayList_Contact *list, Contact *contact);

// ideally O(n)
void remove_contact_at(ArrayList_Contact *list, int index);

// O(1) -- Because the loop will run once
void remove_contact(ArrayList_Contact *list);

// O(1)
void replace_contact_at(ArrayList_Contact *list, Contact *contact, int index);

// O(1)
void swap_contact(ArrayList_Contact *list, Contact *contact1, Contact *contact2);

// O(1)
Contact get_contact(ArrayList_Contact *list, int index);

// O(1)
void clear_contacts(ArrayList_Contact *list);

// O(n)
void print_contacts_range(ArrayList_Contact *list, int start, int end);

// O(n)
void print_contacts(ArrayList_Contact *list);

// replacement Sort --- O(n^2)
int sort_contact_asc(ArrayList_Contact *list);

// O(n)
ArrayList_Contact *read_contacts(char *filename);

// O(n)
void write_contacts(char *filename, ArrayList_Contact *list);

void clearBuffer();

void clearScreen();

void invalidInput();

void add_contact_screen(ArrayList_Contact *list);

int *search_contact(ArrayList_Contact *list, char *name);

void search_contact_screen(ArrayList_Contact *list);

void modify_contact_screen(ArrayList_Contact *list);

void delete_contact_screen(ArrayList_Contact *list);

void pause_screen();