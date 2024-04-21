// Definition of standard libraries.
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include "extra.h"

#define MAX_SEATS 60
#define MAX_MOVIES 5
#define admin_username "Abhishek"
#define admin_password "pass"
int ticket_price = 500;
int movies_count = MAX_MOVIES;

struct movie
{
    char name[30];
    int starting_time;
    int length;
    int screening_day;
    char screening_month[8];
    char genre[40];
    char director[50];
    int seats[MAX_SEATS];
    int num_seats;
};

struct movie films[5] = {
    {"Avengers: Endgame", 2, 180, 28, "April", "action, drama", "Russo Brothers", {0}, 60},
    {"Inception", 5, 148, 29, "April", "Sci-fi, adventure", "Christopher Nolan", {0}, 60},
    {"FightClub", 8, 139, 29, "April", "Drama", "David Fincher", {0}, 60}, 
    {"Tumbbad", 6, 104, 28, "April", "Fantasy, Horror, Drama", "Rahi Anil Barve", {0}, 60},
    {"Whiplash", 2, 106, 30, "April", "Drama, Music", "Damien Cazelle", {0}, 60}
};

struct movie film[MAX_MOVIES];

void addMoviesToFile(struct movie film[])
{
    FILE *file = fopen("movies.txt", "w");
    if (file == NULL)
    {
        printf("Error opening file.\n");
        return;
    }
    for (int i = 0; i < movies_count; i++)
    {
        fwrite(&film[i], sizeof(film[i]), 1, file);
    }
    fclose(file);
}

void loadMoviesFromFile()
{
    FILE *file = fopen("movies.txt", "r");
    if (file == NULL)
    {
        printf("Error finding the file.\n");
        return;
    }
    movies_count = 0;
    while(fread(&film[movies_count], sizeof(film[movies_count]), 1, file))
    {
        movies_count++;
    }
}

// For user side of things.
int user_interface(char[]);
int see_shows(void);
int see_movies(int, char[]);
int display_seats(int[], int);
int book_seats(char[]);
int cineplex_details(void);
int see_price(void);
int logout(void);

// For admin side of things
int admin_interface();
int view_current_shows();
int edit_movies();
int edit_price();

// Login part
int registerUser();
int loginUser();
int admin_login();

// Main Function
int main()
{
    // Step 1: Authentication
    addMoviesToFile(films);
    loadMoviesFromFile();
    int n, a;
    while (a != 4)
    {
        n = first_choice();
        switch(n) 
        {
            case 1:
                admin_login();
                a = 4;
                break;
            case 2:
                registerUser();
                a = 4;
                break;
            case 3:
                loginUser();
                a = 4;
                break;
            case 4:
                a = 4;
                break;
            default: 
                printf("INVALID INPUT\n");
                break;
        }
    }
    return 0;
}

// User login part
// Prashan Rai.

#include "login.c"

int admin_login()
{
    pattern();
    char username[10], password[10];
    printf("\tWELCOME TO ADMIN LOGIN PAGE\n\n");
    printf("\tEnter your username: \t");
    scanf("%s", username);
    printf("\n\tEnter your password: \t");
    scanf("%s", password);
    if ((strcmp(username, admin_username) == 0) && (strcmp(password, admin_password)) == 0)
    {
        printf("\n\tYou are logged in successfully!!!\n");
        pattern();
        admin_interface();
    }
    else {
        printf("\n\tIncorrect password and/or username.Please try again");
        pattern();
        admin_login();
    }
}

// For admin's side of things
#include "admin.c"

// For user's part of things
#include "user.c"