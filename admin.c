//For admin part of things.
//Snehaa Completion part.

int admin_interface()
{
    pattern();
    printf("\tWelcome -- Abhishek--\n\t1) Edit movies and their details\n\t2) Edit price of the ticket\n\t3) View current shows\n\t4) Logout\n\t5) Exit\n");
    pattern();
    int a = 0, n;
    while (a != 5)
    {
        scanf("%d", &n);
        switch(n) 
        {
            case 1:
                edit_movies();
                a = 5;
                break;
            case 2:
                edit_price();
                a = 5;
                break;
            case 3: 
                view_current_shows();
                a = 5; 
                break;
            case 4:
                logout();
                a = 5; 
                break;
            case 5:
                a = 5;
                break;
            default: 
                printf("INVALID INPUT\n");
                break;
        }
    }
    return 0;
}
int edit_price()
{
    pattern();
    printf("\t\tLumin Cineplex\n\tEdit the price of the ticket\n\tThe current price of the ticket is %d", ticket_price);
    printf("\n\tEnter the new price of ticket: \t");
    int new_price;
    scanf("%d", &new_price);
    printf("\n\tAre you sure you want to change the price?(Y/N)?\t");
    char decision;
    scanf(" %s", &decision);
    if ((decision == 'Y') || (decision == 'y'))
    {
        ticket_price = new_price;
        printf("\n\tPrice changed successfully!!!");
        admin_interface();
    }
}
int edit_movies()
{
    pattern();
    printf("\tLumin Cineplex\n\tThe current movies in listing are: \n");
    for (int i = 0; i < movies_count; i++)
    {
        printf("\t%d) %s\n", i + 1, film[i].name);
    }
    int n;
    printf("\tEnter the number of movies that you want to enter:\n");
    scanf("%d", &n);
    if ((n+movies_count) < 1 || (n+movies_count) > MAX_MOVIES)
    {
        printf("We cannot show more that %d movies.", MAX_MOVIES);
        edit_movies();
    }
    printf("\tEnter the new movie that you want to broadcast\n");
    printf("\tName of the movie: \t");
    scanf(" %[^\n]", film[n].name);
    printf("\n\tStarting time: \t");
    scanf("%d", &film[n].starting_time);
    printf("\n\tLength of the movie(in minutes): \t");
    scanf("%d", &film[n].length);
    printf("\n\tBroadcasting date: \t");
    scanf("%d", &film[n].screening_day);
    printf("\n\tBroadcasting month: \t");
    scanf("%s", film[n].screening_month);
    printf("\n\tGenre: \t");
    scanf(" %[^\n]s", film[n].genre);
    printf("\n\tDirectors: \t");
    scanf(" %[^\n]s", film[n].director);
    printf("\tData taken successfully!!!");

    addMoviesToFile(film);
    loadMoviesFromFile();
    admin_interface();
    return 0;
}
int view_current_shows()
{
    pattern();
    printf("\tLumin Cineplex\n");
    printf("\tThe current shows in the listing are: \n");
    for (int i = 0; i < movies_count; i++)
    {
        printf("\t%d) %s: Length: %d(minutes)\n \t\tGenre: %s\n\t\tDirectors: %s\n\t\tScreening on: %d'th of %s\n",i+1, film[i].name, film[i].length, film[i].genre, film[i].director, film[i].screening_day, film[i].screening_month);
    }
    printf("\tDo you want to change the listing?(Y/N)\t");
    char change;
    scanf(" %c", &change);
    if ((change == 'y') || (change == 'Y'))
    {
        edit_movies();
        return 0;
    }
    admin_interface();
    return 0;
}
int logout(void)
{
    main();
    return 0;
}