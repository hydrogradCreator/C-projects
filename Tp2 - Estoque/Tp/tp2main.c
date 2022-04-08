#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>

#define T_max 3000
//tamanho maximo de linhas a serem lidos,definido

//struct que vai armazenar todos os itens do arquivo dado
struct Q {
    int codigo;
    char nome[200];
    int qntd;
    float preco;
    char estado[10];
};

struct Q estoque[T_max];

//função que organiza alfabeticamente, e cria um arquivo txt
void func_1(int qntd_itens, char nomeArq[]){
    
    
    char nomeAux[200];      //
    char estAux[200];       //
    int codAux;             //variáveis auxiliares que recebem dados do arquivo
    float precoAux;         //
    int qntdAux;            //

    int i=0;
    int k=0;
    int r;
    

    //recebe aqui, o nome do arquivo e abre no modo "w" == escrita;
    FILE *ordenados;
    ordenados = fopen(nomeArq,"w");

    //organiza os itens alfabeticamente
    //compara a string atual com a seguinte
    //se retornar um valor numérico menor que 0, entao 
    //atualiza o valor de "menor" como sendo a menor posição
    //fazer as trocas de posição
        for(int i=0; i< qntd_itens; i++){
            for(k=i+1; k < qntd_itens; k++){
                r = strcmp(estoque[i].nome,estoque[k].nome);
                if( r > 0){
                        strcpy(nomeAux, estoque[i].nome);
                        strcpy(estoque[i].nome, estoque[k].nome);
                        strcpy(estoque[k].nome, nomeAux);
                        
                        codAux = estoque[i].codigo;
                        estoque[i].codigo = estoque[k].codigo;
                        estoque[k].codigo = codAux;
                        
                        qntdAux = estoque[i].qntd;
                        estoque[i].qntd = estoque[k].qntd;
                        estoque[k].qntd = qntdAux;
                        
                        precoAux = estoque[i].preco;
                        estoque[i].preco = estoque[k].preco;
                        estoque[k].preco = precoAux;
                        
                        strcpy(estAux, estoque[i].estado);
                        strcpy(estoque[i].estado, estoque[k].estado);
                        strcpy(estoque[k].estado, estAux);
                }
            }
        }
    
        //enquanto o for estiver rodadndo, imprimir sua posição 
        for(int x = 0; x < qntd_itens; x++){
                fprintf(ordenados,"%d\n",estoque[x].codigo);
                fprintf(ordenados,"%s\n",estoque[x].nome);                     
                fprintf(ordenados,"%d\n",estoque[x].qntd);
                fprintf(ordenados,"%.2f\n",estoque[x].preco);
                fprintf(ordenados,"%s\n",estoque[x].estado);
            
        }
        //fechar arquivo;
        fclose(ordenados);
    }
    

//funcao que mostra o item por codigo, recebe qntd de itens, e param3
void func_2(int qntd_itens, int argumento3){

    int i=0;
    //se o param3 coincidir com algum codigo pedido, imprimi-lo
    for(; i< qntd_itens; i++){
        if(argumento3 == estoque[i].codigo){
            printf("%d\n",estoque[i].codigo);
            printf("%s\n",estoque[i].nome);
            printf("%d\n",estoque[i].qntd);
            printf("%.2f\n",estoque[i].preco);
            printf("%s\n",estoque[i].estado);
            break;                          //break caso haja dois itens com codigo iguai, imprimir o primeiro que encontrar;
        }
    }
}

//função que mostra os itens de menor quantidade.
void func_3(int qntd_itens){

    //inicialmente, atribuir algum valor a variável auxiliar
    //para ser comparada com a posiçõ i da struct estoque, e a cada iteração
    //atualiza o valor de qntd_menor
    //comparando de novo, com a condição seguinte
    int qntd_menor = 10000000;

    for (int i = 0; i < qntd_itens; i++){
        if(estoque[i].qntd < qntd_menor){
            qntd_menor = estoque[i].qntd;
        }
    }


    //ao fim do loop, verifica onde está o valor atualizado na variavel qntd_menor
    //e imprime seus itens
    for (int i = 0; i <= qntd_itens; i++){
        if(estoque[i].qntd == qntd_menor){
            printf("%d\n", estoque[i].codigo);
            printf("%s\n", estoque[i].nome);
            printf("%d\n", estoque[i].qntd);
            printf("%.2f\n", estoque[i].preco);
            printf("%s\n", estoque[i].estado);  
        }
    }

}



//função que organiza alfabeticamente, os estados recebidos no param3
void func_4(int qntd_itens, char estado[]){

    //auxiliares que vao receber e armazenar os itens
    char nomeAux[200];          
    char estAux[200];           
    int codAux;                 //mesma logica da função 1.
    float precoAux;             //primeiro organizaar em ordem alfabética
    int qntdAux;                //depois procurar pelo estado correspondente

    int i=0;
    int k=0;
    int r;

    //varrer a quantidade de itens, e comparar qual é menor e maior
    //armazenar e organizar
        for(int i=0; i< qntd_itens; i++){
            for(k=i+1; k < qntd_itens; k++){
                r = strcmp(estoque[i].nome,estoque[k].nome);
                if( r > 0){
                        strcpy(nomeAux, estoque[i].nome);
                        strcpy(estoque[i].nome, estoque[k].nome);
                        strcpy(estoque[k].nome, nomeAux);
                        
                        codAux = estoque[i].codigo;
                        estoque[i].codigo = estoque[k].codigo;
                        estoque[k].codigo = codAux;
                        
                        qntdAux = estoque[i].qntd;
                        estoque[i].qntd = estoque[k].qntd;
                        estoque[k].qntd = qntdAux;
                        
                        precoAux = estoque[i].preco;
                        estoque[i].preco = estoque[k].preco;
                        estoque[k].preco = precoAux;
                        
                        strcpy(estAux, estoque[i].estado);
                        strcpy(estoque[i].estado, estoque[k].estado);
                        strcpy(estoque[k].estado, estAux);
                }
            }
        }

    //a partir da organização, procurar itens pelo estado recebido no param3;
    //e printa-los.
    for(int i = 0; i < qntd_itens; i++ ){
        if(strcmp(estado, estoque[i].estado) == 0){

            printf("%d\n",estoque[i].codigo);
            printf("%s\n",estoque[i].nome);
            printf("%d\n",estoque[i].qntd);
            printf("%.2f\n",estoque[i].preco);
            printf("%s\n",estoque[i].estado);

        }
    }
}

//funcao que filtra menor produto em relação ao estado
void func_5(int qntd_itens, char estado[]){

    //inicialmente, atribuir algum valor a variável auxiliar
    //para ser comparada com a posiçõ i da struct estoque, e a cada iteração
    //atualiza o valor de qntd_menor
    //comparando de novo, com a condição seguinte
    //mesma logica da funcção 3...
    int qntd_item_menor = 1000000;
    

    for(int i=0; i<= qntd_itens; i++){
        if(strcmp(estado,estoque[i].estado) == 0){
            if(estoque[i].qntd < qntd_item_menor){
                qntd_item_menor = estoque[i].qntd;
            }
        } 
    }
    //varrer toda a struct procurando pelo item armazenado como menor quantidade
    //imprimi-lo.
     for (int i = 0; i <= qntd_itens; i++){
        if(estoque[i].qntd == qntd_item_menor){
            printf("%d\n", estoque[i].codigo);
            printf("%s\n", estoque[i].nome);
            printf("%d\n", estoque[i].qntd);
            printf("%.2f\n", estoque[i].preco);
            printf("%s\n", estoque[i].estado);  
        }
    }       
}

//funcao que retorna o total de itens e soma dos precos dos itens
void func_6(int qntd_itens){

//recebe a quatidade de itens
//varre toda a struct, somando o vetor "estoque.qntd"
    int soma_itens=0;

    for(int i = 0; i<= qntd_itens;i++){
        
        soma_itens += estoque[i].qntd;
    }
    //imprime seu total
    printf("%d\n",soma_itens);
}

                                //---------------MAIN -------------

int main(int argc, char *argv[]){

    setlocale(LC_ALL,"Portuguese");
    
    //contador de itens do arquivo
    int cont_itens=0;
    //contador para os argumentos 
    int k=0;
    //tamanho do buffer que armazena as linhas do arquivo
    char buffer[T_max]; //recebe o tamanho das strings do arquivo
    int i=0;

    //enquanto k receber os paramêtros...
    //iniciar o programa.
    for(k=1; k<=argc; k++){
        
        if(k == 1){
            //o primeiro argumento recebe o arquivo
            FILE *p;
            char *fpath;        //fpath recebe o argumento 1;
            fpath = argv[1];
            p = fopen(fpath,"r");   //abre o fpath no modo de leitura

            //se existir erro ao abrir o arquivo -----
            if(p ==  NULL){
                perror("Erro ao abrir o arquivo");
                return EXIT_FAILURE;
            }

            //enquanto não perceber o fim de arquivo
            while(fgets(buffer,T_max,p) != NULL){


                if(i == 0){                                   //o arquivo gerado vem com um numero acima do começo do arquivo
                    i++;                                      //por isso ignora-lo e começar pela linha 1;
                    continue;
                }
                
                if(i==1){
                    (estoque[cont_itens].codigo) = atoi(buffer);            //converter para inteiro o valor lido, com atoi
        
                }
                if(i==2){
                    (strcpy(estoque[cont_itens].nome,buffer));
                    estoque[cont_itens].nome[strlen(estoque[cont_itens].nome)-1] = '\0';      //retirar o '\n'
                    
                }
                if(i==3){
                    estoque[cont_itens].qntd = (atoi(buffer));
                
                }
                if(i==4){
                    estoque[cont_itens].preco = (atof(buffer));                 //transformar em float a linha que foi lida
                    
                }
                if(i==5){
                    strcpy(estoque[cont_itens].estado,buffer);
                    estoque[cont_itens].estado[strlen(estoque[cont_itens].estado)-1] = '\0';
                }

                i++;
                    
                //toda vez que o i == 6, reiniciar o contador, e adicionando a variavel contador de itens
                //já que o arquivo é padronizado, e cada item contem 5 linhas...
                //significando que contabilizou um item
                if(i==6){
                    cont_itens++;
                    i=1;
                }
            }
            fclose(p);
        }
        
        //receber o argumento 2, que chama as funções criadas
        if(k==2){
            if(atoi(argv[2]) == 1){
                char *fpath1 = argv[3];
                char nomeArq[40];
                strcpy(nomeArq,fpath1);
                func_1(cont_itens,nomeArq);
            }
            if(atoi(argv[2]) == 2){
                char *fpath = argv[3];
                int codigo = atoi(fpath);
                func_2(cont_itens,codigo); 
            }
            if(atoi(argv[2]) == 3){
                func_3(cont_itens);
            }
            if(atoi(argv[2]) == 4){
                char *fpath = argv[3];
                func_4(cont_itens,fpath);
            }
            if(atoi(argv[2]) == 5){
                char *fpath2 = argv[3];
                func_5(cont_itens,fpath2);
            }
            if(atoi(argv[2]) == 6){
                func_6(cont_itens);
            }
        }
    }        
    return EXIT_SUCCESS;
    //fim do programa
}
