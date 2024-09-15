#include <stdio.h>

#define FAIL_VAL -99999
#define SUCCESS_VAL 99999
#define MAX_USER 20
#define MAX_LEN 200

char emailArr[MAX_USER][MAX_LEN];
char passArr[MAX_USER][MAX_LEN];

char nameArr[MAX_USER][MAX_LEN];
char addressArr[MAX_USER][MAX_LEN];

int user_count = 0;

/****************************************
* MY CUSTOM CODES START
****************************************/

// Char array that contains the alphabet
char email_chars[] = "0123456789.@abcdefghijklmnopqrstuvwxyz";
char pass_chars[] = "0123456789.$#*@abcdefghijklmnopqrstuvwxyz";
char special_chars[] = "$#*@";

// ***************************************************************
// helper functions
// ***************************************************************

// Calculate length of string
int string_length(char input[])
{
    int i = 0;
    while (input[i] != '\0')
        i++;
    return i;
}

int check_at_the_rate(char str[])
{
    int i = 0;
    int count = 0;
    int index = 0;
    while (str[i] != '\0')
    {
        if (str[i] == '@')
        {
            index = i;
            count++;
        }
        i++;
    }
    if (count == 1)
        return index;
    else
        return FAIL_VAL;
}

int check_domain(char str[], int start_index)
{
    int i = start_index;
    int skip = 0;
    int count = 0;
    while (str[i] != '\0')
    {
        if (skip < 2) // start from the 2nd next index after @
        {
            skip++;
            continue;
        }

        if (str[i] == '.')
            if (str[i + 1] != '\0' && str[i + 2] != '\0') // domain should be at least 2 char
                return SUCCESS_VAL;
            else
                break;

        i++;
    }
    return FAIL_VAL;
}

int check_char(char email[], char allowed_chars[])
{
    int i = 0;
    while (email[i] != '\0')
    {
        int j = 0;
        int flag = FAIL_VAL;
        while (allowed_chars[j] != '\0')
        {
            if (email[i] == allowed_chars[j])
            {
                flag = SUCCESS_VAL;
                break;
            }
            j++;
        }
        if (flag == FAIL_VAL)
            return FAIL_VAL; // Invalid character
        i++;
    }
    return SUCCESS_VAL; // Valid chars
}

int is_contain(char str[], char ch)
{
    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] == ch)
            return SUCCESS_VAL;
        i++;
    }
    return FAIL_VAL;
}

int is_contain_special_char(char pass[])
{
    int i = 0;
    while (pass[i] != '\0')
    {
        if (is_contain(special_chars, pass[i]) == SUCCESS_VAL)
            return SUCCESS_VAL;
        i++;
    }
    return FAIL_VAL;
}

int is_contain_numbers(char pass[])
{
    int i = 0;
    while (pass[i] != '\0')
    {
        if (pass[i] >= '0' && pass[i] <= '9')
            return SUCCESS_VAL;
        i++;
    }
    return FAIL_VAL;
}

int is_contain_upper_case(char pass[])
{
    int i = 0;
    while (pass[i] != '\0')
    {
        if (pass[i] >= 'A' && pass[i] <= 'Z')
            return SUCCESS_VAL;
        i++;
    }
    return FAIL_VAL;
}

int is_contain_lower_case(char pass[])
{
    int i = 0;
    while (pass[i] != '\0')
    {
        if (pass[i] >= 'a' && pass[i] <= 'z')
            return SUCCESS_VAL;
        i++;
    }
    return FAIL_VAL;
}

int comapre_string(char str1[], char str2[])
{
    int i = 0;
    int str1_len = string_length(str1);
    int str2_len = string_length(str2);

    if (str1_len != str2_len)
        return FAIL_VAL;

    while (str1[i] != '\0' && str2[i] != '\0')
    {
        if (str1[i] != str2[i])
            return FAIL_VAL;
        i++;
    }
    return SUCCESS_VAL;
}

// Copy string
void string_copy(char input[], char output[])
{
    int i = 0;
    while (input[i] != '\0')
    {
        output[i] = input[i];
        i++;
    }
    output[i] = '\0';
}

// string concatanation
void name_concat(char input1[], char input2[], char output[])
{
    int i = 0;
    while (input1[i] != '\0')
    {
        output[i] = input1[i];
        i++;
    }

    output[i] = ' ';
    i++;
    int j = 0;
    while (input2[j] != '\0')
    {
        output[i] = input2[j];
        i++;
        j++;
    }
    output[i] = '\0';
}

// *******************************************************************
// Main functions
// *******************************************************************
int check_email(char email[])
{
    if (string_length(email) > MAX_LEN)
        return FAIL_VAL;

    if (check_char(email, email_chars) == FAIL_VAL)
        return FAIL_VAL; // Invalid email

    int at_index = check_at_the_rate(email);

    if (at_index == FAIL_VAL)
        return FAIL_VAL; // No @

    if (check_domain(email, at_index) == FAIL_VAL)
        return FAIL_VAL; // No domain

    return SUCCESS_VAL; // Valid email
}

int check_pass(char pass[])
{
    if (string_length(pass) < 8)
    {
        printf("Password must be at least 8 characters long\n");
        return FAIL_VAL;
    }

    if (is_contain_numbers(pass) == FAIL_VAL)
    {
        printf("Password must contain at least one number\n");
        return FAIL_VAL; // No numbers
    }

    if (is_contain_upper_case(pass) == FAIL_VAL)
    {
        printf("Password must contain at least one upper case letter\n");
        return FAIL_VAL; // No upper case
    }

    if (is_contain_lower_case(pass) == FAIL_VAL)
    {
        printf("Password must contain at least one lower case letter\n");
        return FAIL_VAL; // No lower case
    }

    if (is_contain_special_char(pass) == FAIL_VAL)
    {
        printf("Password must contain at least one special character\n");
        return FAIL_VAL; // No special char
    }

    return SUCCESS_VAL; // Valid pass
}

// sign up and login
int check_dup_email(char email[])
{
    int i = 0;
    while (i < user_count)
    {
        if (comapre_string(email, emailArr[i]) == SUCCESS_VAL)
            return i; // Duplicate index
        i++;
    }
    return SUCCESS_VAL; // not duplicate
}

// for login
int check_dup_pass(char pass[])
{
    int i = 0;
    while (i < user_count)
    {
        if (comapre_string(pass, passArr[i]) == SUCCESS_VAL)
            return i; // Duplicate index
        i++;
    }
    return SUCCESS_VAL; // not duplicate
}

/****************************************
* MY CUSTOM CODES END
****************************************/

int signupUser(char email[], char pass[])
{
    // checking
    if (check_dup_email(email) != SUCCESS_VAL)
    {
        printf("Email already exists!\n");
        return FAIL_VAL;
    }

    if (check_email(email) == FAIL_VAL)
    {
        printf("Invalid email!\n");
        return FAIL_VAL;
    }

    if (check_pass(pass) == FAIL_VAL)
    {
        printf("Invalid password!\n");
        return FAIL_VAL;
    }

    // signup
    string_copy(email, emailArr[user_count]);
    string_copy(pass, passArr[user_count]);
    user_count++;
    printf("Signup successful!\n");
    printf("Email: %s\n", emailArr[user_count - 1]);
    printf("You can now login!\n");
    return user_count - 1;
}

int loginUser(char email[], char pass[])
{
    // checking
    int index = check_dup_email(email);
    if (index == FAIL_VAL)
    {
        printf("User does not exist!\n");
        return FAIL_VAL;
    }

    if (comapre_string(pass, passArr[index]) != SUCCESS_VAL)
    {
        printf("Wrong password!\n");
        return FAIL_VAL;
    }
    else
    {
        printf("Login successful!\n");
        return index;
    }
}

int buildUserProfile(char email[], char firstName[], char lastName[], char address[])
{
    // checking
    int index = check_dup_email(email);
    if (index == FAIL_VAL)
    {
        printf("User does not exist!\n");
        return FAIL_VAL;
    }

    // build profile
    name_concat(firstName, lastName, nameArr[index]);
    string_copy(address, addressArr[index]);
}

void searchByName(char name[])
{
    printf("Searching...\n");
    int i = 0;
    while (i < user_count)
    {
        if (comapre_string(name, nameArr[i]) == SUCCESS_VAL)
        {
            printf("Email: %s\n", emailArr[i]);
            printf("Name: %s\n", nameArr[i]);
            printf("Address: %s\n", addressArr[i]);
        }
        i++;
    }
}

void searchByAddress(char address[])
{
    printf("Searching...\n");
    int i = 0;
    while (i < user_count)
    {
        if (comapre_string(address, addressArr[i]) == SUCCESS_VAL)
        {
            printf("Email: %s\n", emailArr[i]);
            printf("Name: %s\n", nameArr[i]);
            printf("Address: %s\n", addressArr[i]);
        }
        i++;
    }
}

int main()
{
    // freopen("in.txt", "r", stdin);  // debug
    while (1)
    {
        printf("*******************************************************************\n");
        printf("1. signup User. 2. login User. 3. build User Profile. 4.Search By Name. 5. Search By Address. 6.exit \n");

        int choice;
        scanf("%d", &choice);

        if (choice == 1)
        {
            char mail[MAX_LEN], pass[MAX_LEN];
            printf("give User Email :");
            scanf("\n%[^\n]s", mail);
            printf("give User Password :");
            scanf("\n%[^\n]s", pass);
            signupUser(mail, pass);
        }

        if (choice == 2)
        {

            char mail[MAX_LEN], pass[MAX_LEN];
            printf("give User Email :");
            scanf("\n%[^\n]s", mail);

            printf("give User Password :");
            scanf("\n%[^\n]s", pass);

            loginUser(mail, pass);
        }

        if (choice == 3)
        {

            char mail[MAX_LEN], fname[MAX_LEN], lname[MAX_LEN], address[MAX_LEN];
            printf("give User Email :");
            scanf("\n%[^\n]s", mail);
            printf("%s\n", mail);
            printf("give First Name :");
            scanf("\n%[^\n]s", fname);
            printf("%s\n", fname);
            printf("give Last Name :");
            scanf("\n%[^\n]s", lname);
            printf("%s\n", lname);
            printf("give Address :");
            scanf("\n%[^\n]s", address);
            printf("%s\n", address);

            buildUserProfile(mail, fname, lname, address);
        }

        if (choice == 4)
        {

            char name[MAX_LEN];
            printf("give User Name :");
            scanf("\n%[^\n]s", name);

            searchByName(name);
        }

        if (choice == 5)
        {

            char address[MAX_LEN];
            printf("give User Address :");
            scanf("\n%[^\n]s", address);

            searchByAddress(address);
        }
        if (choice == 6)
        {
            break;
        }
    }
}
