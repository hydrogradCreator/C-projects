#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//fazer função de ordenação de strings
// se strcmp retorna 1, entao a palavra a esquerda, é maior
//se restorna 0 ==  sao strings iguais;
//se retorna -1 ==  a segunda palavra, é maior

int comparacao(recebe numero de itens){
    

    //criar variaveis auxiliares para fazer a troca de posição de todos os elementos dos itens
    char nomeAux[200];
    char estAux[200];
    int codAux;
    float precoAux;
    int qntAux;

    //criar variaveis auxiliares para os loops
    int i=0;
    int j=0;
    int result;
    
    //checar o que acontece quando se comparar a string i+2 como maior string
    //o contrario de checar se a string seguinte, é maior, e sim, checar se a anterior é menor

    for(; i <= j; i++){
        
        //o j começa no 1, porque ele é responsavel por pegar a string seguinte ---------------------

        for(j= i+1 ; j <=i;j++){
            strcmp(estoque[i].nome,estoque[j].nome);

            if(strcmp(estoque[i].nome,estoque[j].nome) > 0){                    //se o valor for maior que 0, a primeira string é maior que 
                                                                                //a segunda, entao passa-la para frente
                strcpy(nomeAux,estoque[i].nome);
                strcpy(estoque[i].nome,estoque[j].nome);
                strcpy(estoque[j].nome, nomeAux);

                codAux = estoque[i].codigo                          //auxiliar recebe a string maior
                estoque[i].codigo = estoque[j].codigo               //a posição de string maior, recebe a string menor
                estoque[j].codigo = codAux;                         //e a posição que era da string maior, agora recebe a string de menor valor

                qntAux = estoque[i].qntd;
                estoque[i].qntd = estoque[j].qntd;
                estoque[j].qntd = qntAux;

                strcpy(estAux, estoque[i].estado);
                strcpy(estoque[i].estado, estoque[j].estado);
                strcpy(estoque[j].estado,estAux);

                precoAux = estoque[i].preco;
                estoque[i].preco = estoque[j].preco;
                estoque[j].preco = precoAux;
            }
        }
    }
    //imprimir em ordem
    //imprimir i+1 que é a posição que o item agora ocupa
    for(int i = 0; i < numero de itens; i++){
        printf("%d\n",estoque[i].codigo);
        printf("%s\n",estoque[i].nome);
        printf("%d\n",estoque[i].qntd);
        printf("%f\n",estoque[i].preco); 
        printf("%s\n".estoque[i].estado);
    }


}



int main(){


}