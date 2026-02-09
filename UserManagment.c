#include<stdio.h>

#include<stdlib.h>

#include<string.h>

#include<stdbool.h>

 

typedef struct utilisateur

{

                char identifiant[30];

                char motdepasse[30];

                bool admin ;

               

}utl;

 

bool existe(utl u[] , int n ,char id[])

{

                int i;

                bool exist ;

                for (i = 0 ; i < n ; i++ )

                {

                               exist = false ;

                               if (strcmp(id,u[i].identifiant) == 0)

                                  {

                                               i = n ;

                                                exist =  true;

                                  }

                }

               

     return exist;

}

 

 

bool ajout( utl u[] , int n , char id[] , char mdp[] )

{

                int i ;

                if ( existe(u , n , id) == 0)

                    {

                    strcpy(u[n].identifiant,id);

                    strcpy(u[n].motdepasse,mdp);

                   

                               if (n==0)

                      u[n].admin = 1;

                    else

                      u[n].admin = 0 ;

                   

                    

                    return true ;

                               }

               

                return false ;

               

}

bool login( utl u[] , char id[] ,char mdp[] , int n )

{

   int i ,exist = false,   k  , x = 0;

   

                for (i = 0 ; i < n ; i++ )

                {

                               x = 0;

                               exist = false;

                              

                               if (strcmp(id,u[i].identifiant) == 0)

                                  {

                                               k = i ;

                                               i = n ;

                                                exist =  true;

                                                

                                  }

                }

              

    if (exist == true){

   

               

                  if ( strcmp(id,u[k].identifiant) == 0 && strcmp(mdp,u[k].motdepasse) == 0)

                   {

           x = 1 ;

        }

                               }

   

                 else{

       x = 0 ; }

      

       return x;

}

                 

 

bool changer_mdp( utl u[] , char id[] , int n , char nvmdp[] )

{

                int i ;

                for(i = 0 ; i < n ; i++)

                {

                               if(strcmp(id,u[i].identifiant) ==  0)

                               {

                                               strcpy(u[i].motdepasse , nvmdp);

                                               i = n ;

                                               return true ;

                               }

                              

                }

                return false ;

}

 

 

 

int main()

{

                int n = 0 ,x,choix3 , choix , choix2 , i, admin , log = 1 ;

                char id[100] , idm[100] , mdp[100] , nvmdp[100] ;

                utl uti[20];

                printf("----- creation de l'utilisateur principal (admin) -----\n");

                do {

               

                printf("entre l'identifiant :");

                scanf("%s",id);

                strcpy(idm,id);

                printf("entre le mot de passe :");

                scanf("%s",mdp);

               

                }while(ajout(uti, n ,id , mdp) == 0);

                   

               

               

               

                              

        n++ ;

                do{

                               log = 0 ;

               

                printf("\n>----- LOGIN -----<\n");

               do{

                              

                                printf("entre l'identifiant :");

                               scanf("%s",id);

                    printf("entre le mot de passe :");

                     scanf("%s",mdp);

                    

                   x = login(uti , id , mdp , n);

                   for(i = 0 ; i < n ; i++)

                     if(strcmp(id,uti[i].identifiant) == 0)

                        admin = uti[i].admin ;

                        if(!x)

                          printf(" \n--- erreur réessayer ---\n");

                          else

                             printf("\n --- identification reussi ---\n");

                       

                   }while( x == false);

 

  

   switch(admin)

   {

               case 0 :

                  

                   {

                               do{

                      do{

                                

                   printf("------ MENU UTILISATEUR ------ \n");

                    printf("entre 1 pour changer de mot de passe\n");

                     printf("entre 2 pour afficher les utilisateur\n");

                      printf("entre 3 pour vous logout\n");

                       printf("entre 0 pour sortir du programme \n");

                        printf("votre choix");

                       

                   scanf("%d",&choix3);

                   log = 0 ;

                   switch(choix3)

                   {

                  

                     case 1 :

                          printf("entre le mot nouveaux mot de passe \n");

                          scanf("%s",nvmdp);

                           x = changer_mdp(uti, id , n ,nvmdp);

                            if (x)

                                     printf("changement reussi\n");

                                      else

                                                                   ("le changement a echoue\n");

                               break;

                     case 2 :

                                   for( i = 0 ; i < n ; i++)

                                                  printf("%d) %s \n",i+1,uti[i].identifiant);

                                break;

                               case 3 :

                                    log = 1 ;

                                break;

                               case 4 :

                                              printf("\nvous avez quitter le programme \n");

                                              exit(1);

                                              break ;

                               default: printf("\n --- choix incorrect --- \n");break;       

                }

                  }while(choix3 != 3);

          }while(log != 1);

                  break; }

  

               case 1 :{

                              

                 

                   do{

                              

                   

                 

                               printf("\n------ MENU ADMIN ------ \n");

                               printf("entre 1 pour ajouter utilisateur\n");

                                 printf("entre 2 pour changer votre mot de passe \n");

                       printf("entre 3 pour changer le mot de passe d'un utilsateur\n");

                                   printf("entre 4 pour afficher la liste des utilisateur\n");

                                    printf("entre 5 pour vous logout\n");

                                     printf("entre 0 pour sortir du programme\n");

                                      printf("votre choix :");

                               scanf("%d",&choix);

                               switch(choix)

                               {

                              

                     case 1 :

                               if ( n < 20){

                              

                                       do{

                                                              

                                                               printf("entre l'identifiant ");

                  scanf("%s",id);

                  printf("\nentre le mot de passe ");

                    scanf("%s",mdp);

                    x = ajout(uti, n ,id , mdp);

                    if (!x)

                      printf("l'identifiant invalide(deja utiliser)\n");

                       else n++ ;

                }while( x == 0);

                                 }

                                 else printf("\n --- le nombre maximum d'utilisateur est ateint !!! --- \n");

                              

                                break;

                    

                     case 2 :

                               printf("entre le mot de passe ");

                                scanf("%s",nvmdp);

                                  x = changer_mdp(uti , idm , n , nvmdp);

                                   if (x)

                                     printf("changement reussi\n");

                                       else ("le changement a echoue\n");

                               break;

                     case 3 :

                              

                               do{

                                              

                               printf("entre l'identifiant de l'utilisateur auquel vous voulez changer de mot de passe \n");

                                scanf("%s",id);

                                 x = existe(uti,n,id);

                                  if (x ==  0 )

                                      printf("\nl'identifiant entre n'est pas disponile\n");

                     }while(x == 0 ) ;

                                  printf("entre le nouveau mot de passe \n");

                                   scanf("%s",nvmdp);

                                    x = changer_mdp(uti,id,n,nvmdp);

                                     if (x)

                                      printf("changement reussi\n");

                                       else ("le changement a echoue\n");

                               break;

                     case 4 :

                                printf("----- affichage des utilisateur -----\n");

                                 for(i=0 ; i< n ;i++)

                                  printf("%d ) %s\n",i+1,uti[i].identifiant);

                              

                                break;

                     case 5 :

                               log = 1;

                              

                                break;

                    

                                case 0 :

                               printf("\nvous avez quitter le programme \n");

                               exit(1);

                                                break;

                               default: printf("\n --- choix incorrect --- \n");break;                        

                 }

                                }while( log != 1);  }break;            

   }

   }while(log);

   return 0 ;}
