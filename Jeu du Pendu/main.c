#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

void welcome ();

int choix_adv();

mot_rand(char* s_mot);

mot_input(char* s_mot);

int mot_lenght(char* s_mot);

print_state1 (char* s_mot, char* s_guess, char c_guess, int mot_lenght);

print_state2 (char* s_mot, char* s_guess, char c_guess, int mot_lenght, int *vie, int *c_found);

ask_letter ();

char lireCaractere();

print_vie(int *p_vie, char c_guess);

int main()
{

int replay = 1;

while (replay == 1)
{
    int mode = 0;
    int lenght =0;
    int vie = 6;
    int c_found = 0;

    int p_vie = &vie;
    int p_c_found = c_found;

    char c_guess = 0 ;

    char s_mot[50] = {0};
    char s_guess[50]= {0};


        welcome();
        mode = choix_adv();
            if (mode==1)
            {mot_rand(s_mot);
            }
            else if (mode==2)
            {
                mot_input(s_mot);
                printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");  //Hiding the word in input
            }
        lenght = mot_lenght (s_mot);

        print_state1 (s_mot, s_guess, c_guess, lenght);

        while (vie != 0 && c_found != lenght)
        {
        print_state2 (s_mot, s_guess, c_guess, lenght, &vie, &c_found);
        //printf("Lenght : %d\nC_Found : %d\nVie : %d\n", lenght, c_found, vie);
        }

        if (vie == 0)
        {
            printf("\n\n\nPERDU\nPERDU PERDU\nPERDU PERDU PERDU\nPERDU PERDU PERDU PERDU\nPERDU PERDU PERDU PERDU\nPERDU PERDU PERDU PERDU PERDU\n\n\n\n");
        }

        if (c_found == lenght)
        {
            printf("\n\t\t_________________________________________________________\n\t\t*********************************************************\n\t\tTOUTES MES FILICITATIONS POUR CETTE SUBLIME VICTOIRE !!!!\n\t\t*********************************************************\n\t\t_________________________________________________________\n\n\n\n");
        }


        printf("\n\n\n\t\t\t\tSouhaitez vous rejouer?\n");
        printf("\n\n\n\t\t\t\t\tNON : 0\n");
        printf("\n\n\n\t\t\t\t\tOUI : 1\n\n");
        scanf("%d", replay);
        printf("\n\n\n\n\n");
        //replay = reaplay_game(replay, vie);

        //printf("MAIN : %s\n", s_mot);
        //printf("MAIN : %s\n", s_guess);
}
        return 0;
}


void welcome ()
{
    printf("\n\tBienvenue dans LE JEU DU PENDU\n\n");
}

int choix_adv()
{
    int vs = 0;

        while (vs!=1 || vs!=2)
            {
                printf("Merci de selectionner votre mode de jeu\n\t1 : Choix au hasard du mot par l'ordinateur\n\t2 : Entree manuelle du mot\n");
                scanf("%d", &vs);

                    if (vs == 1)
                        {
                        printf("\nLe mot a ete choisi, bon courage !\n");
                        return(1);
                        }

                    else if (vs == 2)
                        {
                        printf("\nMerci de rentrer maintenant le mot EN MAJUSCULES au clavier\n");
                        return(2);
                        }
            }
}

mot_input(char* s_mot)
{
    scanf("%s", s_mot);
}

mot_rand(char* s_mot)
{
int i = 0;
    s_mot[i] = 'M';
    s_mot[1] = 'A';
    s_mot[2] = 'R';
    s_mot[3] = 'R';
    s_mot[4] = 'O';
    s_mot[5] = 'N';
    s_mot[6] = '\0';

    //printf("%s\n", s_mot);
}

int mot_lenght (char* s_mot)
{
    int mot_lenght = 0;
    int i = 0;
        do
        {
            i++;
        }
        while (s_mot[i] != '\0');
        //printf("Le mot fait %d caracteres de long\n", i);
        return(i);

}

print_state1 (char* s_mot, char* s_guess, char c_guess,int lenght)
{
int i =0;
c_guess = 0;

        do
        {
        if (c_guess == s_mot[i])
        {
            s_guess[i] = s_mot[i];
        }
        else
        {
            s_guess[i] = '*';
        }
        i++;
        } while (i<lenght);

        printf("\t\t\t\t\t\tOOOOOOOOOOOOOOOOOOOOOOOOOOO\n\n", s_guess);
        printf("\t\t\t\t\t\t\t%s\n\n", s_guess);
        printf("\t\t\t\t\t\tOOOOOOOOOOOOOOOOOOOOOOOOOOO\n\n\n", s_guess);
        return(0);

}


int print_state2 (char* s_mot, char* s_guess, char c_guess,int lenght, int *vie, int *c_found)
{
int i =0;
c_guess = 0;
int did_c_found = 0;

    //printf("1%c\n", c_guess);
    scanf("%c", &c_guess);              //Un bug resolu en dédoublant scanf, possible tentative d'entrée de /n
    scanf("%c", &c_guess);
    //printf("2%c\n", c_guess);
            //printf("P_S2\n");

        do
        {
        if (c_guess == s_mot[i])
        {
            s_guess[i] = s_mot[i];
            (*c_found)++;
            did_c_found = 1;
            printf("\t\t\t\t\t\t\t\t\t\t     / )       \n");
            printf("\t\t\t\t\t\t\t\t\t\t    ' /       \n");
            printf("\t\t\t\t\t\t\t\t\t\t---' (_____    \n");
            printf("\t\t\t\t\t\t\t\t\t\t...... ((__)\n");
            printf("\t\t\t\t\t\t\t\t\t\t.... _ ((___) \n");
            printf("\t\t\t\t\t\t\t\t\t\t.... -'((__)\n");
            printf("\t\t\t\t\t\t\t\t\t\t--.___((_)     \n\n\n");
        }
        i++;
        } while (i<lenght);

        if (did_c_found == 0)
        {
            (*vie)--;
            print_vie(vie, c_guess);
            //printf("MAUVAIS CARACTERE DANS P_S2\n");
        }


        printf("\t\t\t\t\t\tOOOOOOOOOOOOOOOOOOOOOOOOOOO\n\n", s_guess);
        printf("\t\t\t\t\t\t\t%s\n\n", s_guess);
        printf("\t\t\t\t\t\tOOOOOOOOOOOOOOOOOOOOOOOOOOO\n\n\n", s_guess);
        return(0);

}

char lireCaractere()
{
    char caractere = 0;

    printf("Merci d'entrer une lettre :\t");

    caractere = getchar(); // On lit le premier caractère
    caractere = toupper(caractere); // On met la lettre en majuscule si elle ne l'est pas déjà

    printf("\n");

    // On lit les autres caractères mémorisés un à un jusqu'au \n (pour les effacer)
    while (getchar() != '\n') ;

    return caractere; // On retourne le premier caractère qu'on a lu
}

print_vie(int *vie, char c_guess)
{
    printf("\t\t\t\t\t\t\t\t\t\tLa lettre %c ne fait pas partie du mot !\n\n", c_guess);

    switch (*vie)
    {
        case (5) :
            printf("\t\t\t\t\t\t\t\t\t\t  _______\n\t\t\t\t\t\t\t\t\t\t  |/  |\n\t\t\t\t\t\t\t\t\t\t  |   5\n\t\t\t\t\t\t\t\t\t\t  |   \n\t\t\t\t\t\t\t\t\t\t  |  \n\t\t\t\t\t\t\t\t\t\t__|________\n\n\n");
            break;
        case (4) :
            printf("\t\t\t\t\t\t\t\t\t\t  _______\n\t\t\t\t\t\t\t\t\t\t  |/  |\n\t\t\t\t\t\t\t\t\t\t  |  _4\n\t\t\t\t\t\t\t\t\t\t  |   \n\t\t\t\t\t\t\t\t\t\t  |  \n\t\t\t\t\t\t\t\t\t\t__|________\n\n\n");
            break;
        case (3) :
            printf("\t\t\t\t\t\t\t\t\t\t  _______\n\t\t\t\t\t\t\t\t\t\t  |/  |\n\t\t\t\t\t\t\t\t\t\t  |  _3_\n\t\t\t\t\t\t\t\t\t\t  |   \n\t\t\t\t\t\t\t\t\t\t  |  \n\t\t\t\t\t\t\t\t\t\t__|________\n\n\n");
            break;
        case (2) :
            printf("\t\t\t\t\t\t\t\t\t\t  _______\n\t\t\t\t\t\t\t\t\t\t  |/  |\n\t\t\t\t\t\t\t\t\t\t  |  _2_\n\t\t\t\t\t\t\t\t\t\t  |   |\n\t\t\t\t\t\t\t\t\t\t  |  \n\t\t\t\t\t\t\t\t\t\t__|________\n\n\n");
            break;
        case (1) :
            printf("\t\t\t\t\t\t\t\t\t\t  _______\n\t\t\t\t\t\t\t\t\t\t  |/  |\n\t\t\t\t\t\t\t\t\t\t  |  _1_\n\t\t\t\t\t\t\t\t\t\t  |   |\n\t\t\t\t\t\t\t\t\t\t  |  / \n\t\t\t\t\t\t\t\t\t\t__|________\n\n\n");
            break;
        case (0) :
            printf("\t\t\t\t\t\t\t\t\t\t  _______\n\t\t\t\t\t\t\t\t\t\t  |/  |\n\t\t\t\t\t\t\t\t\t\t  |  _0_\n\t\t\t\t\t\t\t\t\t\t  |   |\n\t\t\t\t\t\t\t\t\t\t  |  / \\\n\t\t\t\t\t\t\t\t\t\t__|________\n\n\n");
            break;
    }

}

/*ask_letter ()
{
    int i =0;

    char c_guess = 0;

    do
    {
    if (c_guess == s_mot[i])
    {
        s_guess[i] = s_mot[i];
    }
    else
    {
        s_guess[i] = '*';
    }
    i++;
    } while (i<lenght);

    printf("PRINT STATE %s\n", s_guess);
    return(0);
}*/

/*
\t  _______\n
\t  |/  |\n
\t  |  _0_\n
\t  |   |\n
\t  |  / \\\n
\t__|________\n
*/


