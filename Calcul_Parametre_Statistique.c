#include<stdio.h>
#include<math.h>
#include<stdlib.h>

//ABAKAR OUMAR ABAKAR 21T2488

/*
Mon code est organise de la facon suivante :
-Declaration des fonctions
-La fonction principale main()
-Definition des differentes fonctions
*/


//Declaration des Mes Fonctions pour la variable Discrete
//Ces fonctions sont definis apres la fonction main()
void trier(float tab[],int tab2[],int n);
double my_pow(double x, int n);
double my_sqrt(double x);

//Declaratioon des mes Fonctions pour la variable continu
void tri_par_selection(int tab[], int size);
float calcul_moyenne(int inf[], int sup[], int freq[], int size);
float calcul_mediane(int inf[], int sup[], int freq[], int size);
float calcul_mode2(int inf[], int sup[], int freq[], int size);
float calcul_entendu(int inf[], int sup[], int size);
float calcul_Q1(int inf[], int sup[], int freq[], int size);
float calcul_Q3(int inf[], int sup[], int freq[], int size);
float calcul_intervalle_interquartile(int inf[], int sup[], int freq[], int size);
float calcul_coefficient_variation(int inf[], int sup[], int freq[], int size);
void tableau_ECC(int inf[], int sup[], int freq[], int size);
double my_sqrt(double x);
void tableau_Densite(int inf[], int sup[], int freq[], int size);
void tableau_FCC(int inf[], int sup[], int freq[], int size);

int main(){

    int choix;
    while (1){

   
    printf("..............................Voulez-vous réaliser une étude ?...................................\n\n");
    printf("1-Sur variable discrète ?\n\n");
    printf("2-Sur variable continue ?\n\n");
    printf("0-Quiter\n\n");
    printf("\n\nChoisissez le Type de Variable :");
    scanf("%d",&choix);
     system("clear");

if(choix==1){

    printf("................................Variable Discrète.....................................................\n");
        
int n;
    do
    {
        printf("\n\nEntrez le nombre des valeurs observees:");
    scanf("%d",&n);
    } while (n<0);
    
    float X[n];
    int effectifs[n];
    int i,j;
    //Lecture des valeurs et des effectifs
    for(i=0;i<n;i++){
       do
       {
         printf("Entrez la valeur %d :",i+1);
        scanf("%f",&X[i]);
       }while(X[i]<0);
        
        do
        {
           printf("Entrez l'effectif de %g :",X[i]);
        scanf("%d",&effectifs[i]);
       
        } while (effectifs[i]<0);
        
       
    }
      //Affichage de la matrice
      printf("\n\nMatrice\n\n");
      for(i=0;i<n;i++){
        printf("%5g\t",X[i]);
      }
       printf("\n");
      for(i=0;i<n;i++){
        printf("%5d\t",effectifs[i]);
      }
       printf("\n");
      //Tri des valeurs et effectifs dans l'ordre croissant des valeurs
      trier(X,effectifs,n);
      //Calcul des ECC et FCC
       int total=0;
      for(i=0;i<n;i++){
        total=total+effectifs[i];
      }
      float ECC[n],FCC[n];
      ECC[0]=effectifs[0];
      FCC[0]=effectifs[0]/(float)total;
     
      for(i=1;i<n;i++){
        ECC[i]=ECC[i-1]+effectifs[i];
        FCC[i]=FCC[i-1]+effectifs[i]/(float)total;
      }
      //Affichage du tableau des ECC
      printf("\n\nTABLEAU DES ECC :\n\n");
        printf("T1\t");
      for(i=0;i<n;i++){
        printf("%2g\t",ECC[i]);
      }

    //Affichage des Tableaux des FCC
    printf("\n\nTableaux des FCC :\n\n");
     printf("T2\t");
      for(i=0;i<n;i++){
        printf("%3g\t",FCC[i]);
      }

     //Calcul de la moyenne
     float somme =0;
     for ( i = 0; i < n; i++)
     {
        somme=somme+X[i]*effectifs[i];
     }
     float moyenne=somme/total;
     
    //calcul de la mediane
    float mediane;
    float nombre_avant=0;
    int nombre_apres=total;
    for(i=0;i<n;i++){
        nombre_apres=nombre_apres-effectifs[i];
        if(nombre_avant<=total/2 &&total/2<nombre_avant+effectifs[i]){
            if(effectifs[i]%2==0){
                //moyenne des deux valeurs du milieu
                int pos1=total/2-nombre_avant;
                int pos2=pos1-1;
                mediane=(X[i]+X[i-1])/2.0;

            }
            else{
                //valeur au milieu
                mediane=X[i];
            }
            break;
        }
        nombre_avant=nombre_avant+effectifs[i];
    }
     


//calcul du mode
float mode;
int max=0;
for(i=0;i<n;i++){
    if(effectifs[i]>max){
        max=effectifs[i];
        mode=X[i];
    }
}

//Calcul du Premier quartile Q1 et du toisieme quartile Q3

float Q1,Q3;
int quartile1=total/4;
int quartile3=3*total/4;
nombre_avant=0;
nombre_apres=total;
for(i=0;i<n;i++){
    nombre_apres=effectifs[i];
    if(nombre_avant<=quartile1 && quartile1<nombre_avant+effectifs[i]){
        int pos1=quartile1-nombre_avant;
          if(effectifs[i]%2==0){
            //moyenne des deux valeurs du milieu
            int pos2=pos1-1;
            Q1=(X[i]+X[i-1])/2.0;
          }
          else{
            //valeur du milieu
            Q1=X[i];
          }
    }
    if(nombre_avant<=quartile3 && quartile3 <nombre_avant+effectifs[i]){
        int pos1=quartile3-nombre_avant;
         if(effectifs[i]%2==0){
            //Moyenne des deux valeurs du milieu
            int pos2=pos1-1;
            Q3 = (X[i] + X[i-1]) / 2.0;

         }
         else{
          //c'est la valeur au milieu
          Q3=X[i];
         }
         break;
    }
    nombre_avant=nombre_avant+effectifs[i];
}

// // Calcul de l'écart-type
    float variance = 0;
    for (i = 0; i < n; i++) {
        variance += effectifs[i] * my_pow(X[i] - moyenne, 2);
    }
    variance =variance/total;
    float ecart_type = my_sqrt(variance);
    // Calcul de l'intervalle interquartile et de l'étendue
    float intervalle_interquartile = Q3 - Q1;
    float etendue = X[n-1] - X[0];
    // Calcul du coefficient de variation
    float coeff_variation = ecart_type / moyenne;
    // Affichage des résultats
    printf("\n\nVALEURS DE TENDANCE CENTRALE :\n\n");
    printf("Mode = %g\n", mode);
    printf("Moyenne = %g\n", moyenne);
    printf("Mediane = %g\n", mediane);
    printf("Q1 = %g\n", Q1);
    printf("Q2 = %g\n",mediane);
    printf("Q3 = %g\n", Q3);
    printf("\nVALEURS DE DISPERSION :\n\n");
    printf("Variance = %g\n", variance);
    printf("Ecart-type = %g\n", ecart_type);
    printf("Intervalle interquartile = %g\n", intervalle_interquartile);
    printf("Etendue = %g\n", etendue);
    printf("Coefficient de variation = %g soit  %g %%\n",coeff_variation,100*coeff_variation);


    }

    if(choix==2){
    printf("................................Variable Continue.....................................................\n");
    int size, i, j;
    printf("\n\nEntrez la taille de l'échantillon : ");
    scanf("%d", &size);

    int inf[size], sup[size], freq[size];
    for (i = 0; i < size; i++){
        printf("Enter la borne inferieur de la classe %d : ", i + 1);
        scanf("%d", &inf[i]);

        printf("Entrez la borne superieure de la classe %d : ", i + 1);
        scanf("%d", &sup[i]);

        printf("Entrez l'effectif de la classe %d : ", i + 1);
        scanf("%d", &freq[i]);
    }

    printf("\nMatrice : \n\n");

    // Affichage de la matrice
    for (i = 0; i < size; i++){
        printf("%-10d\t", inf[i]);
    }
    printf("\n");
    for (i = 0; i < size; i++){
        printf("%-10d\t",sup[i]);
    }
    printf("\n");
    for (i = 0; i < size; i++){
        printf("%-10d\t",freq[i]);
    }
    printf("\n");
 
    // Tri par sélection sur les bornes inférieurs
    tri_par_selection(inf, size);
    //calcul de la Densite
    printf("\nTableau des Densite :\n");
    tableau_Densite(inf, sup, freq, size);
    // Tableau des ECC
    printf("\nTableau des ECC :\n");
    tableau_ECC(inf, sup, freq, size);
    //Tableau des FCC
    printf("\nTableau des FCC :\n");
    tableau_FCC(inf, sup, freq, size);

    // Calcul de la moyenne
    float moyenne = calcul_moyenne(inf, sup, freq, size);
    printf("\nMoyenne =  %.2f\n", moyenne);

    // Calcul de la médiane
    float mediane = calcul_mediane(inf, sup, freq, size);
    printf("\nMediane =  %.3f\n", mediane);

     // Calcul du mode2
    float mode2 = calcul_mode2(inf, sup, freq, size);
    printf("\nMode =  %f\n", mode2);

    // Calcul de l'étendue
    float entendu = calcul_entendu(inf, sup, size);
    printf("\nEtendu =  %f\n", entendu);

    // Calcul de Q1
    float Q1 = calcul_Q1(inf, sup, freq, size);
    printf("\nQ1 = : %.2f\n", Q1);
    //Calcul de Q2
    float Q2 = calcul_mediane(inf, sup, freq, size);
    printf("\nQ2 =  %.2f\n", Q2);
    // Calcul de Q3
    float Q3 = calcul_Q3(inf, sup, freq, size);
    printf("\nQ3 =  %.2f\n", Q3);

    // Calcul de l'intervalle interquartile
    float intervalle_interquartile = calcul_intervalle_interquartile(inf, sup, freq, size);
    printf("\nIntervalle interquartile =  %.2f\n", intervalle_interquartile);

    // Calcul du coefficient de variation
    float coefficient_variation = calcul_coefficient_variation(inf, sup, freq, size);
    printf("\nCoefficient de variation = %g soit %.2f%%\n",coefficient_variation,100*coefficient_variation);

    }

    if(choix==0){
        break;
    }

    else{
         printf("Choix invalide. Veuillez choisir une option valide\n\n");
    }
    
    }
    
    

    return 0;

}  

//Fonction pour trier les valeurs et les effectifs
  void trier(float tab[],int tab2[],int n)
  {
    int i,j;
    float temp;
    int temp2;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(tab[j]>tab[j+1]){
                //echange des valeurs
                temp=tab[j];
                temp2=tab[j+1];
                tab[j+1]=temp;
                //echanges des effectifs corespondants
                temp2=tab2[j];
                tab2[j]=tab2[j+1];
                tab2[j+1]=temp2;

            }
        }
    }
}
double my_pow(double x, int n) {
    double result = 1.0;
    for (int i = 0; i < n; i++) {
        result *= x;
    }
    return result;
}
double my_sqrt(double x) {
    if (x < 0) {
        return NAN; // retourner NaN (Not a Number) si x est négatif
    }

    double guess = x / 2; // commencer avec une supposition raisonnable

    while (1) {
        double new_guess = (guess + x / guess) / 2; // calculer notre nouvelle supposition
        if (fabs(new_guess - guess) < 1e-6) { // vérifier si nous avons atteint la précision souhaitée
            return new_guess; // retourner notre meilleure estimation
        }
        guess = new_guess; // mettre à jour notre supposition
    }
}


void tri_par_selection(int tab[], int size)
{
    int i, j, min, tmp;
    for (i = 0; i < size - 1; i++){
        min = i;
        for (j = i + 1; j < size; j++){
            if (tab[j] < tab[min]){
                min = j;
            }
        }
        if (min != i){
            tmp = tab[i];
            tab[i] = tab[min];
            tab[min] = tmp;
        }
    }
}

float calcul_moyenne(int inf[], int sup[], int freq[], int size)
{
    int i, somme_freq = 0;
    float somme_classe_freq = 0;
    for (i = 0; i < size; i++){
        somme_freq += freq[i];
        somme_classe_freq += (inf[i] + sup[i]) / 2.0 * freq[i];
    }
    return somme_classe_freq / somme_freq;
}

float calcul_mediane(int inf[], int sup[], int freq[], int size)
{
    int i, somme_freq = 0, moitie_inf, moitie_sup;
     float Fcc[size];
    int total=0;
      for(i=0;i<size;i++){
        total=total+freq[i];
      }
    Fcc[0]=freq[0]/(float)total;
    for (i = 1; i < size; i++){
        Fcc[i]=Fcc[i-1]+freq[i]/(float)total;
        
       }
    for (i = 0; i < size; i++){
        somme_freq += freq[i];
    }
    moitie_inf = (somme_freq + 1) / 2;
    moitie_sup = somme_freq / 2 + 1;

    int classe_mediane;
    int cumul_freq = 0;
    for (i = 0; i < size; i++){
        cumul_freq += freq[i];
        if (cumul_freq >= moitie_sup){
            classe_mediane = i;
            break;
        }
    }
    int a=sup[classe_mediane]-inf[classe_mediane];
    float b=0.5-Fcc[classe_mediane-1];
    float c=Fcc[classe_mediane]-Fcc[classe_mediane-1];
    return inf[classe_mediane]+ a*(b/c);
    


}

void tableau_Densite(int inf[], int sup[], int freq[], int size)
{
    
    int i;
    float densite[size];
    for (i = 0; i < size; i++){
        densite[i]=freq[i]/(float)(sup[i]-inf[i]);
        
       }
        printf("T3");
       for(i=0;i<size;i++){
        printf("\t%g\t",densite[i]);
       }

}


float calcul_mode2(int inf[], int sup[], int freq[], int size)
{
    int i, max_freq = 0, classe_modale;
    float densite[size];
    for (i = 0; i < size; i++){
        densite[i]=freq[i]/(float)(sup[i]-inf[i]);
        
       }
       float Fcc[size];
    int total=0;
      for(i=0;i<size;i++){
        total=total+freq[i];
      }
    for (i = 0; i < size; i++){
        Fcc[i]=freq[i]/(float)total;
        
       }
    for (i = 0; i < size; i++){
        if (densite[i] > max_freq){
            max_freq = densite[i];
            classe_modale = i;
        }
    }
    int a=sup[classe_modale]-inf[classe_modale];
    float b=Fcc[classe_modale]-Fcc[classe_modale+1];
    float c=Fcc[classe_modale]-Fcc[classe_modale +1];
    float d=Fcc[classe_modale]-Fcc[classe_modale -1];
      return sup[classe_modale] - a*(b/(c+d));
}


float calcul_entendu(int inf[], int sup[], int size)
{
    return sup[size - 1] - inf[0];
}

float calcul_Q1(int inf[], int sup[], int freq[], int size)
{
    int i, somme_freq = 0, moitie_inf, moitie_sup;
     float Fcc[size];
    int total=0;
      for(i=0;i<size;i++){
        total=total+freq[i];
      }
    Fcc[0]=freq[0]/(float)total;
    for (i = 1; i < size; i++){
        Fcc[i]=Fcc[i-1]+freq[i]/(float)total;
        
       }
    for (i = 0; i < size; i++){
        somme_freq += freq[i];
    }
    moitie_inf = (somme_freq + 1) / 4;
    moitie_sup = somme_freq / 4 + 1;

    int classe_Q1;
    int cumul_freq = 0;
    for (i = 0; i < size; i++){
        cumul_freq += freq[i];
        if (cumul_freq >= moitie_sup){
            classe_Q1 = i;
            break;
        }
    }
        int a=sup[classe_Q1]-inf[classe_Q1];
    float b=0.25-Fcc[classe_Q1-1];
    float c=Fcc[classe_Q1]-Fcc[classe_Q1-1];
    return inf[classe_Q1]+ a*(b/c);
}

float calcul_Q3(int inf[], int sup[], int freq[], int size)
{
    int i, somme_freq = 0, moitie_inf, moitie_sup;
    float Fcc[size];
    int total=0;
      for(i=0;i<size;i++){
        total=total+freq[i];
      }
    Fcc[0]=freq[0]/(float)total;
    for (i = 1; i < size; i++){
        Fcc[i]=Fcc[i-1]+freq[i]/(float)total;
        
       }
    for (i = 0; i < size; i++){
        somme_freq += freq[i];
    }
    moitie_inf = 3 * (somme_freq + 1) / 4;
    moitie_sup = (3 * somme_freq) / 4 + 1;

    int classe_Q3;
    int cumul_freq = 0;
    for (i = 0; i < size; i++){
        cumul_freq += freq[i];
        if (cumul_freq >= moitie_sup){
            classe_Q3 = i;
            break;
        }
    }
    int a=sup[classe_Q3]-inf[classe_Q3];
    float b=0.75-Fcc[classe_Q3-1];
    float c=Fcc[classe_Q3]-Fcc[classe_Q3-1];
    return inf[classe_Q3]+ a*(b/c);
}



float calcul_intervalle_interquartile(int inf[], int sup[], int freq[], int size)
{
    return calcul_Q3(inf, sup, freq, size) - calcul_Q1(inf, sup, freq, size);
}

float calcul_coefficient_variation(int inf[], int sup[], int freq[], int size)
{   
   
    float moyenne = calcul_moyenne(inf, sup, freq, size);
    float ecart_type = 0, somme = 0;
    int i;
    float  fcc[size];
     int total=0;
      for(i=0;i<size;i++){
        total=total+freq[i];
        }
       for(i=0;i<size;i++){
        fcc[i]=freq[i]/total;
        } 

    for (i = 0; i < size; i++){
        somme += ((inf[i] + sup[i]) / 2.0) * ((inf[i] + sup[i]) / 2.0) *(freq[i]);
        somme=somme -(moyenne * moyenne);
    }

    ecart_type = my_sqrt(somme / (size - 1));
    return (ecart_type / moyenne);
}


void tableau_ECC(int inf[], int sup[], int freq[], int size)
{
    int i,Ecc[size];
    Ecc[0]=freq[0];
    for (i = 1; i < size; i++){
        Ecc[i]=Ecc[i-1]+freq[i];
        
       }
       printf("T4");
       for(i=0;i<size;i++){
        printf("\t%d\t",Ecc[i]);
       }

}
void tableau_FCC(int inf[], int sup[], int freq[], int size)
{
    
    int i;
    float Fcc[size];
    int total=0;
      for(i=0;i<size;i++){
        total=total+freq[i];
      }
    Fcc[0]=freq[0]/(float)total;
    for (i = 1; i < size; i++){
        Fcc[i]=Fcc[i-1]+freq[i]/(float)total;
        
       }
       printf("T5");
       for(i=0;i<size;i++){
        printf("\t%g\t",Fcc[i]);
       }

}
