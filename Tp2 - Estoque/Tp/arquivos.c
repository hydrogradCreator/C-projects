#include <stdio.h>


/*
coleçao de bytes armazenados em um dispositivo de armazenamento, em geral, um disco rigido
permitem armazenar grande quantidade de informação
persistencia de dados
acesso aos dados poder ser nao sequencial
mais de um programa pode usar os dados ao mesmo tempo(concorrendo aos dados)


dois tipos de arquivo(texto,binário)

ponteiro de arquivo
FILE *p ==> p é o ponteiro para arquivos que nos permitirá manipular arquivos

fechar um arquivo : fclose
        ler dados de um arquivo: fread
            escrever dados em um arquivo: fwrite


antes de ler ou escrever, precisamos abrir o arquivo 
        ==============> FILE *fopen(*nome do arquivo, *modo) nome determina qual arquivo vai ser aberto
                    FILE *fp
                    
                    fp = fopen(arquivo,modo);
                    comando
                    fclose(fp)
                    
                    modo determina o tipo de uso do arquivo


    função exit() retorna um codigo caso erro;

    porque usar um "buffer"?
    Eficiencia, ler e escrever ar   uivos no disco, posicionando a gravação em um ponto especifico do disco
    a gravação só é realizada quando há um volume razóavel de informações a serem gravadas ou quando o arquivo por fechado


    ===> Leitura e escrita de caracteres

     fputc() (put character)

     fputc(string,arquivo);

     fputc('*',stdout) grava * na tela do monitor

     também pode ler um unico caractere

     fgetc(FILE *fp) ===> fp aponta para um arquivo, fgetc lê o caractere atual no arquivo 
                        e se posiciuna para ler o prócimo caractere do arquivo(parecido com uma máquina de escrever)

    fgetc(stdin) = lê caractere do teclado

    feof(FILE *fp) =====>verifica se um arquivpo chegou ao fim



    leitura e escrita de strings

    char fputs(char *str,FILE *fp) ===> pont eiro de arquivo onde será escrito

    para se ler uma string de um arquivo======>
    char *fgets(char *str,int tamanho, FILE *fp) fp == ponteiro que está associado ao arquivo de onde a string será lida

    leitura e escrita de blocos de dados

    fwrite(buffer,numero_de_bytes,count,*fp) ===> escrita de um bloco de dados da memoria em um arquivo

    numero_de_bytes == tamanho de cada posição de memória a ser escrita

    count == total de unidades de memória que devem ser escritas

    fread(str,numero_de_bytes,count,*fp) ==> leitura de um bloco de dados em um arquivo,retorna o número de itens escritos
    esse valor será igual a count

    //lê de fp e armazena em str


    fprintf(fp,"texto",x) ==> grava no arquivo fp
    fscanf(fp,"texto",&x) ==> lê do arquivo fp(qual arquivo vai ler)

    fseek(FILE *fp,numbytes,int origem) buscas e acessps aleatórios em arquivos

    rewind()==>retorna o arquivo para o inicio

    remove(*nome do arquivo) ==> permite apagar arquivos do disco

*/





