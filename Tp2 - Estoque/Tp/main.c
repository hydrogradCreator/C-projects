#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

// struct
struct produto{
    int codigo;
    char nome[100];
    int qtd;
    float preco;
    char estado[5];
};

// vetor de struct - esse valor estrapolado pq nao sei das intenções do professor
struct produto produtos[2500];

// FUNÇÃO 1

void f1_ordena_produtos(int j){
    int x, y, r;
    //
    char aux_nome[80];
    char aux_estado[5];
    int aux_codigo;
    int aux_qtd;
    float aux_preco;


    for(x = 0; x <= j; x++){
        for(y = x+1; y <= j; y++){
            r = strcmp(produtos[x].nome, produtos[y].nome);
            if(r > 0){
                // NOME
                strcpy(aux_nome, produtos[x].nome);
                strcpy(produtos[x].nome, produtos[y].nome);
                strcpy(produtos[y].nome, aux_nome);
                // CODIGO
                aux_codigo = produtos[x].codigo;
                produtos[x].codigo = produtos[y].codigo;
                produtos[y].codigo = aux_codigo;
                // QTD
                aux_qtd = produtos[x].qtd;
                produtos[x].qtd = produtos[y].qtd;
                produtos[y].qtd = aux_qtd;
                // PRECO
                aux_preco = produtos[x].preco;
                produtos[x].preco = produtos[y].preco;
                produtos[y].preco = aux_preco;
                // ESTADO
                strcpy(aux_estado, produtos[x].estado);
                strcpy(produtos[x].estado, produtos[y].estado);
                strcpy(produtos[y].estado, aux_estado);

                
            }
        }
    }
    for (int i = 0; i < j; i++){
        printf("Produto: %d\n", i+1);
        printf("codigo: %d\n", produtos[i+1].codigo);
        printf("nome: %s\n", produtos[i+1].nome);
        printf("qtd: %d\n", produtos[i+1].qtd);
        printf("preco: %.2f\n", produtos[i+1].preco);
        printf("estado: %s\n", produtos[i+1].estado); 
    }
}

// MAIN
int main(int argc, char *argv[]){
    // mudar idioma do programa
    setlocale(LC_ALL,"Portuguese");

    // valor da funcao passada no parametro da função
    int funcao;
    int j = 0;

    // programa receberá 3 argumentos basicos: 1 = arquivo, 2 = funcao, 3 = filtro
    for(int i = 1; i < argc; i++){
        // Arquivo
        if(i == 1){
            // recebe arquivo que será colocado na struct
            FILE *file;
            file = fopen(argv[1], "r");

            // linha do fgets e auxiliares
            char linha[1000];
            int i = 0; 
            
            // está varrendo o arquivo txt e printando, enquanto pega todos os valores strings numericos e convete para inteiro
            while(fgets(linha, 1000, file) != NULL){
                if(i == 0){
                    produtos[j].codigo = atoi(linha);
                }
                if(i == 1){
                    strcpy(produtos[j].nome, linha);
                    produtos[j].nome[strlen(produtos[j].nome)-1] = '\0';
                }
                if(i == 2){
                    produtos[j].qtd = atoi(linha);
                }
                if(i == 3){
                    produtos[j].preco = atof(linha);
                }
                if(i == 4){
                    strcpy(produtos[j].estado, linha);
                    produtos[j].estado[strlen(produtos[j].estado)] = '\0';
                }

                i++;
                
                // quando o i percorrer todas as caracteristicas do produto ele reseta
                // j recebe mais um para armazenar no vetor da struct
                if(i==5){ 
                    i = 0;
                    j ++;
                }

            }
            // impressao de teste
            // for (i = 0; i < j; i++){
            //     printf("Produto: %d\n", i+1);
            //     printf("codigo: %d\n", produtos[i].codigo);
            //     printf("nome: %s\n", produtos[i].nome);
            //     printf("qtd: %d\n", produtos[i].qtd);
            //     printf("preco: %.2f\n", produtos[i].preco);
            //     printf("estado: %s\n", produtos[i].estado);    
            // }

            fclose(file);
        }
        // FUNÇÃO
        //funcao = atoi(argv[2]);
        if(i==2){
            if(atoi(argv[2]) == 1){
                printf("Função: 1 - Gerar relatório de estoque\n\n");
                f1_ordena_produtos(j);
            }
            if(atoi(argv[2]) == 2){
                printf("Função: 2 - Pesquisar por produto pelo código\n\n");
            }
            if(atoi(argv[2]) == 3){
                printf("Função: 3 - Listar dados do produto com menor quantidade\n\n");
            }
            if(atoi(argv[2]) == 4){
                printf("Função: 4 - Listar produtos por estado\n\n");
            }
            if(atoi(argv[2]) == 5){
                printf("Função: 5 - Encontrar produto com menor quantidade em estado\n\n");
            }
            if(atoi(argv[2]) == 6){
                printf("Função: 6 - Calcular quantidade total de itens no estoque\n\n");
            }
        }
        // FILTRO DO PROGRAMA
        if(i == 3){
            printf("%s\n", argv[i]);
        }

    }

    return 0;
}