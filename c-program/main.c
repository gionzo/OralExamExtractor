#include<string.h>
#include<stdlib.h>
#include<stdio.h>

int bisestile; //bisestile ? 1 : 0
char anno[10][31][20];

int meseMax(int i){
if(i==5)return (bisestile==1)?29:28;
if(i==0 || i==2 || i==7 || i==9)return 30;
return 31;}

const char *meseNome(int m){
if(m==0)return "Settembre";
if(m==1)return "Ottobre";
if(m==2)return "Novembre";
if(m==3)return "Dicembre";
if(m==4)return "Gennaio";
if(m==5)return "Febbraio";
if(m==6)return "Marzo";
if(m==7)return "Aprile";
if(m==8)return "Maggio";
return "Giugno";}

void calendarioToAnno(char str[20]){
char *token;
int i,j;
token=strtok(str,",");
i=atoi(token);
token=strtok(NULL,",");
j=atoi(token);
token=strtok(NULL,".");
strcpy(anno[(i<7)?i+3:i-9][--j],token);
return;}

void bisestileSetUp(){
FILE *fp=fopen("calendario.txt","r");
fscanf(fp,"%d",&bisestile);
bisestile = (bisestile%4 == 0) ? 1 : 0;
fclose(fp);}

void annoSetUp(){
FILE *fp=fopen("calendario.txt","r");
char *frase;
fgets(frase, 20, fp);
while(!feof(fp)){
    fgets(frase, 20, fp);
    calendarioToAnno(frase);}
fclose(fp);}

void setUp(){
bisestileSetUp();
annoSetUp();}

void stampaCalendario(){
int i,j;
printf("\n");
for(i=0;i<10;i++){printf("%s:\n\n",meseNome(i));
for(j=0;j<meseMax(i);j++){
if((j+1)<10)printf("0");
printf("%d",j+1);
printf(" - %s\n",(strcmp(anno[i][j],"")!=0)?anno[i][j]:"/");}
printf("\n\n");}}

void stampaAlunni(){
FILE *fp=fopen("alunni.txt","r");
int i,max=0;
char nome[30];
printf("\n");
fscanf(fp,"%d\n",&max);
for(i=0;i<max;i++){
    fgets(nome,29,fp);
    printf("%d : %s",i+1,nome);
}printf("\n\n");
fclose(fp);}

void aggiungiTurni(){
int num;
do{printf("Quanti turni vuoi aggiungere?\n");
scanf("%d",&num);
}while(num<3 || num>15);}

void menu(){
int scelta;
do{ printf("1 - stampa calendario;\n2 - stampa alunni;\n3 - aggiungi turni;\n4 - fine.\n");
    scanf("%d",&scelta);
    switch(scelta){
        case 1: {stampaCalendario();break;}
        case 2: {stampaAlunni();break;}
        case 3: {aggiungiTurni();break;}
        case 4: break;
        default: {printf("valore inserito non valido\n");break;}}
    }while(scelta!=4);}

int main(int argc, char ** argv){
setUp();
menu();
}