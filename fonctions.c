#include <stdio.h>
#include <string.h>
#include"fonctions.h"
int ajouter_utilisateur(char * filename, utilisateur u)
{
FILE *f;
f=fopen(filename,"a+");
if (f!=NULL)
{
fprintf(f,"%s %s %s %s %d %d %d %s %s %s %d %d \n",u.cin,u.nom,u.prenom,u.genre,u.DDN.jour,u.DDN.mois,u.DDN.annee,u.conx.login,u.conx.mdp,u.role,u.vote,u.numbv);
fclose(f);
return 1 ;
}
else return 0 ;

}





    int modifier_utilisateur( char * filename,utilisateur nvu,char cin[])
{
    int tr=0;
    utilisateur u;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%s %s %s %s %d %d %d %s %s %s %d %d \n",u.cin,u.nom,u.prenom,u.genre,&u.DDN.jour,&u.DDN.mois,&u.DDN.annee,u.conx.login,u.conx.mdp,u.role,&u.vote,&u.numbv)!=EOF)
        {
            if(strcmp(cin,u.cin)==0)
            {
                fprintf(f2,"%s %s %s %s %d %d %d %s %s %s %d %d \n",nvu.cin,nvu.nom,nvu.prenom,nvu.genre,nvu.DDN.jour,nvu.DDN.mois,nvu.DDN.annee,nvu.conx.login,nvu.conx.mdp,nvu.role,nvu.vote,nvu.numbv);
                tr=1;
            }
            else
                fprintf(f2,"%s %s %s %s %d %d %d %s %s %s %d %d \n",nvu.cin,nvu.nom,nvu.prenom,nvu.genre,nvu.DDN.jour,nvu.DDN.mois,nvu.DDN.annee,nvu.conx.login,nvu.conx.mdp,nvu.role,nvu.vote,nvu.numbv);

        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return tr;

}



int supprimer_utilisateur(char * filename ,char cin[])
{



 FILE*F,*Fich;
    int tr ;
    utilisateur u ;
             F=fopen(filename,"r");
            Fich=fopen("temputil.txt","w");
            do
            {
                fscanf(F,"%s %s %s %s %d %d %d %s %s %s %d %d \n",u.cin,u.nom,u.prenom,u.genre,&u.DDN.jour,&u.DDN.mois,&u.DDN.annee,u.conx.login,u.conx.mdp,u.role,&u.vote,&u.numbv);
            if(strcmp(cin,u.cin)==0)
            {
               tr=1 ;
            }
else
    fprintf(Fich,"%s %s %s %s %d %d %d %s %s %s %d %d \n",u.cin,u.nom,u.prenom,u.genre,u.DDN.jour,u.DDN.mois,u.DDN.annee,u.conx.login,u.conx.mdp,u.role,u.vote,u.numbv);

            }while(!feof(F));
            fclose(F);
            fclose(Fich);
            remove(filename);
            rename("temputil.txt",filename);
            return tr ;

    }



utilisateur chercher_utilisateur(char * filename, char cin[])
{
    utilisateur u;
    int tr;
    FILE * f=fopen(filename, "r");
    if(f!=NULL)
    {
        while((tr==0)&& (fscanf(f,"%s %s %s %s %d %d %d %s %s %s %d %d \n",u.cin,u.nom,u.prenom,u.genre,&u.DDN.jour,&u.DDN.mois,&u.DDN.annee,u.conx.login,u.conx.mdp,u.role,&u.vote,&u.numbv)!=EOF))
        {
            if(strcmp(u.cin,cin)==0)
                tr=1;
        }
    }
    fclose(f);

    return u;
}


