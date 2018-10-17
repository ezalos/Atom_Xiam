#include "struct.h"

t_picture access_data(t_picture )
{
   int n;
   t_picture picture;

   if ((fptr = fopen("D:\\C\\Neural Network\\train-images.idx3-ubyte","rb")) == NULL)
   {
       printf("\nError! opening file\n");
       // Program exits if the file pointer returns NULL.
       exit(1);
   }

   for(n = 1; n < 5; ++n)
   {
      fread(&num, sizeof(struct threeNum), 1, fptr);
      printf("n1: %d\tn2: %d\tn3: %d", num.n1, num.n2, num.n3);
   }
   fclose(fptr)

   return 0;
}


/*
size_t fread (const void *ptr, size_t size, size_t nmemb, FILE *stream);

ptr               pointeur sur le premier octet de la liste d'objets à charger.
size              L'espace mémoire pris par un membre de la liste d'objets à
                  charger.
nmemb             Le nombre de membres ayant la taille size dans la liste
                  d'objets à charger.
stream            Pointeur sur le flux (pointeur sur FILE dans notre cas).
Valeur retournée  La fonction fread retourne le nombre d'éléments qu'elle a
                  réussis à lire correctement dans le flux pointé par stream.
                  Il faut noter aussi que la fonction fread traite la fin du
                  fichier comme une erreur de lecture.
 */
