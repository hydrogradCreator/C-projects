#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include  <sys/stat.h>

//pedir argv no main
//varer o argv e colocar condições para as fubnções
//funções recebem param2

struct Q{

    //criei outro vetor para receber o valor para testar 
            
            int codigo;
            char codigo1[100];
            
            char nome[2000];
            char nome1[3000];
            
            char qntd;
            char qntd1[200];
            
            char preco1[200];
            float preco;
            
            char estado[1000];
            char estado1[1000];

};

struct Q estoque[4000];



//fazer fubção que recebe os parametros
int main(int argc, char *argv[]){

    setlocale(LC_ALL,"Portuguese");
    
    char buffer[3000];///buffer recebe as linhas do arquivo

    FILE *p;
    p = fopen("/home/r_alexandre/Documentos/Tp/test0.txt","r");

    int i=0;

        while(fgets(buffer,2000,p)!=NULL){

            if(i==0){
                //o sizeof le o tamanho do que vamos armazenar na variavel codigo1
                //a partir do que se recebe do arquivo p.
                //depois, armazenamos essa leitura de bytes no struct codigo
                //em teoria, está correto.
            //fgets(estoque[i].codigo1,sizeof(buffer),p);
            estoque[i].codigo = atoi(buffer);
            }

            if(i==1){
            //fgets(estoque[i].nome1, sizeof(buffer),p);
            strcpy(estoque[i].nome,buffer);
            estoque[i].nome[strlen(estoque[i].nome) - 1] = '\0';
            }

            if(i==2){
            //fgets(estoque[i].qntd1, sizeof(buffer),p);
            estoque[i].qntd = atoi(buffer);
            }

            if(i==3){
            //fgets(estoque[i].preco1, sizeof(buffer),p);
            estoque[i].preco = atof(buffer);
            }

            if(i==4){
            //fgets(estoque[i].estado1, sizeof(buffer),p);
            strcpy(estoque[i].estado,buffer);
            estoque[i].estado[strlen(estoque[i].estado)] = '\0';

            }       
                //printf("%d\n",estoque[i].codigo);
                //printf("%s\n",estoque[i].nome);                 //coloquei aqui pra ir vendo o que imprime
                //printf("%d\n",estoque[i].qntd);
                //printf("%.2f\n",estoque[i].preco);
                //printf("%s\n",estoque[i].estado);

            i++;

            if(i==5){
                i=0;
                printf("%d\n",estoque[i].codigo);
                printf("%s\n",estoque[i].nome);
                printf("%d\n",estoque[i].qntd);
                printf("%.2f\n",estoque[i].preco);
                printf("%s\n",estoque[i].estado);
            }                               
        }      //zerar se chegar a 5...
        
    fclose(p);
    
    
   
    return 0;
}