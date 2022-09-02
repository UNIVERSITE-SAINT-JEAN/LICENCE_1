#include <stdio.h>
#include <stdlib.h>


typedef struct NbRationnel{
    int num;
    int den;
}NbRationnel;

void printRationnel(NbRationnel r){
    printf("%d/%d, ",r.num,r.den);
}

int estValide(NbRationnel r){
    if(r.den==0){
        return 0;
    }else{
        return 1;
    }
}

int compareRationnel(NbRationnel p, NbRationnel q){
    float x=(float)p.num/p.den;
    float y= (float) q.num/q.den;
    if(x<y){
        return -1;
    }else{
        if(x==y){
            return 0;
        }else{
            return 1;
        }
    }
}

float addRationnel(NbRationnel p, NbRationnel q){
    float x,y;
    x=(float)p.num/p.den;
    y= (float) q.num/q.den;
    return (x+y);
}


float multiplyRationnel(NbRationnel p, NbRationnel q){
   float x,y;
     x=(float)p.num/p.den;
     y= (float) q.num/q.den;
    return (x*y);
}


float divideRationnel(NbRationnel p, NbRationnel q){
    float x,y;
     x=(float)p.num/p.den;
     y= (float) q.den/q.num;
    return (x/y);
}


float maxRationnel(NbRationnel tab[], int N){
    int i;
        float max=(float)tab[0].num/tab[0].den;
    for(i=0;i<N;i++){
        if(max<(float)(tab[i+1].num/tab[i+1].den)){
            max=(float)(tab[i+1].num/tab[i+1].den);
        }
    }
    return max;
}


int main()
{
    NbRationnel tab[5],exem1,exem2;
    printf("entrer le numerateur du 1 nbre Rationnel: ");
        scanf("%d",&exem1.num);
        printf("entrer le denominateur du 1 nbre Rationnel: ");
        scanf("%d",&exem1.den);
        printf("entrer le numerateur du 2 nbre Rationnel: ");
        scanf("%d",&exem2.num);
        printf("entrer le denominateur du 2 nbre Rationnel: ");
        scanf("%d",&exem2.den);
        if(exem2.den==0 || exem1.den==0){
        printf("l un de vos  nombre rationnel est invalide\n");
    }else{
        printf("vos nombres rationnel sont valide\n");
        printf("la somme donne %.2f\n\n",addRationnel(exem1,exem2));
        printf("la multiplication donne %.2f\n\n",multiplyRationnel(exem1,exem2));
        printf("la division donne %.2f\n\n",divideRationnel(exem1,exem2));
    }
    printf("\n");
    int i;
    printf("Entrer vos 5 nombres rationnel: \n\n");
    for(i=0;i<5;i++){
        printf("entrer le numerateur du %d Rationnel: ",i+1);
        scanf("%d",&tab[i].num);
        printf("entrer le denominateur du %d Rationnel: ",i+1);
        scanf("%d",&tab[i].den);
    }
    printf("\n");
    printf("vos nombre rationnel entrer sont: \n\n");
    for(i=0;i<5;i++){
        printRationnel(tab[i]);
    }
    float min=(float)tab[0].num/tab[0].den, max;
    for(i=0;i<5;i++){
        if(min>(float)(tab[i+1].num/tab[i+1].den)){
            min=(float)(tab[i+1].num/tab[i+1].den);
        }else{
            max=(float)(tab[i+1].num/tab[i+1].den);
        }
    }
    printf("le plus petit nombre rationnel du table est %.2f",min);
    printf("le plus grand nombre rationnel du table est %.2f",max);
    for(i=0;i<5;i++){
        compareRationnel(tab[i],tab[i+1]);
    }
    return 0;
}
