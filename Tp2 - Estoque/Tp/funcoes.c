#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Q{
    //criei outro vetor para receber o valor para testar           
            int codigo;
            
            char nome[2000];
            
            char qntd;
            
            float preco;
            
            char estado[1000];
            

};

struct Q estoque[4000];

//não está identificando o argumento 2



int main(int argc, char *argv[]){

    
    char nome1[200];
    char buffer[2000];

    //percorrer todos os argumentos de execução
    //colocar as ações correspondentes
    // arg 1 = arquivo
    //arg 2 = função
    //arg 3 = filtrar função 1,2,4,5;

    //int k=0;

    //loop enquanto j for menor que o contador de argumentos(ARGC)
    for(int k = 1;k< argc; k++){
    
        if(k==1){
        //recebe o arq no param1 no modo leitura
        FILE *p;
        p = fopen(argv[1],"r");

        //usar variavel k como contador;
        int i=0;

            while(fgets(buffer,4000,p)!=NULL){

                    if(i==0){
                    estoque[i].codigo = atoi(buffer);               //codigo
                    }

                    if(i==1){
                    strcpy(estoque[i].nome,buffer);
                    estoque[i].nome[strlen(estoque[i].nome)-1] = '\0';        //nome
                
                    }
                    
                    if(i==2){
                    estoque[i].qntd = atoi(buffer);
                    }

                    if(i==3){
                    estoque[i].preco = atof(buffer);
                    }
                    
                    if(i==4){
                    strcpy(estoque[i].estado,buffer);
                    estoque[i].estado[strlen(estoque[i].estado)] = '\0';     //aqui ta as duas formas que tentei pegar o estado
                    }                                        //'''''''''''''''''''
                    
                    i++;
                    if(i==5){
                        i=0;
                    }
                    //zerar se chegar a 5...
                }
                    

            fclose(p);
        }


        //usar tranformação de inteiros (atoi)?
        //sim, comparação entre ponteiro e inteiro.
    
        //quando o j estiver no param2   
        if (k == 2){
            //chamar as funções (quando criadas);
            if(atoi(argv[2]) == 1){
                printf("Relatório de estoque");
            }
            if(atoi(argv[2]) == 2){
                printf("pesquisar produto pelo codigo(Param3)");
            }
            if(atoi(argv[2]) == 3){
                printf("listar produto menor quantidade estoque");
            }
            if(atoi(argv[2]) == 4){
                printf("pesquisar produto pelo estado(param 3)");
            }
            if(atoi(argv[2]) == 5){
                printf("produto com menor quantidade em determinado estado");
            }
            if(atoi(argv[2]) == 6){
                printf("quantidade total de itens e preço");
            }
        }


        //quanto o j estiver no param3
        /*if(k == 3){
            printf("argumento 3: filtro, função 1,2,4,5");
            if(atoi(argv[2])==1){
                //nome do arquivo de saída
            }
            if(atoi(argv[2])==2){
                //codigo do produto desejado
            }
            if(atoi(argv[2])==4){
                //sigla do produto desejad(listart produtos por estado)
            }
            if(atoi(argv[2])==5){
                //sigra produto desejado(menor quantidade).
            }
        }*/
    }   
    return 0;

}