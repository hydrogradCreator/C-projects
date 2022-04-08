#include <stdio.h>
#include <stdlib.h>
#include <string.h>



//primeiros passos: '''''''ver as aulas de equivo'''''
//entrada: 
//  QUANTIDADE (Q) de produtos da lista 1 < Q <1000 
//  DADOS DE CADA PRODUTO: sao 5 dados (para cada produto, portanto 5*Q) 
    //---> codigo
    //---> nome
    //---> quantidade
    //---> preço
    //---> estado


    // o codigo deve ser executado por parametros(pedidos na função), 3 obrigatórios --------> .\tp2 [param1] [param2] [param3]
    //----> param1 == nome do arquivo de entrada 

    //----> param2 == numero correspondente a função desejada (vai de 1 a 6, ou seja, criar essas funções)


    //o terceiro param é opcional. Por exemplo, podemos usar os parametros 1 para o input.txt(arquivo) 
                                                            //mais o numero da função desejada, e de forma opcional
                                                            //nas funções 1,2,4,5, especificar o nome do arquivo de saida, codigo de produto
                                                            //ou sigla do estado desejado


                                                            //com tres paramêtros:.\tp2 input.txt(nome do arquivo de entrada) 4 (função desejada) 
                                                            //e, opcionalmente, o param3, que nesse caso, vai ser algum estado

// a saida deve imprimir cada exigencia de cada função, estas EM ORDEM ALFABÉTICA, COM UM DADO POR LINHA
        // CODIGO,NOME, QUANTIDADE, PREÇO, ESTADO

        //a função 6 retorna a qtnd total de itens e o preço total de todos presentes no estoque
            //somar a quantidade de cada produto recebida no arquivo de entrada



    //usar os parametros de entrada, usar argv
    
    struct Q
        {
            int codigo;
            char nome[200];
            int qntd;
            float preco;
            char estado[10];
        };
    struct Q estoque[4000];



int main(int argc, char *argv[]){


    
    char buffer[4000];

    FILE *p;
    p = fopen("/home/r_alexandre/Documentos/Tp/test0.txt","r");

    int i=0;
    

        while(fgets(buffer,2000,p)!=NULL){

                
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
                estoque[i].estado[strlen(estoque[i].estado)] = '\0';                   //aqui ta as duas formas que tentei pegar o estado
                }                                        //'''''''''''''''''''
                
                i++;
                
                if(i==5){

                //coloquei para printar aqui, mas se colocar fora, também não está funfando
                printf("%d\n", estoque[i].codigo);
                printf("%s\n", estoque[i].nome);
                printf("%d\n", estoque[i].qntd);
                printf("%.2f\n", estoque[i].preco);
                printf("%s\n", estoque[i].estado);   
                
                i=0;
                }
                //zerar se chegar a 5...
            }
                 
    fclose(p);
    
    
    return 0;

}