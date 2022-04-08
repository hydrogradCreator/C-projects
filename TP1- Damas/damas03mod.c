#include <stdio.h>
#define tmax 20



int main(){

    int tamanho;
    char entrada[tmax];

    //printf("Informe o tamanho do tabuleiro: "); //APAGAR
    
    fgets(entrada,tmax,stdin);
    sscanf(entrada,"%d",&tamanho);

    char tabuleiro[tmax][tmax];


    //input do tabuleiro
    //printf("Informe o tabuleiro: \n"); //APAGAR
    for( int i = 0;i < tamanho; i++){
        fgets(tabuleiro[i],tmax, stdin);
    }
    printf("------------------------\n");


    //salvar as pontuações das peças pretas e brancas
    int pontos_preta=0,pontos_branca=0;

    //caracteres e seus significados
    char pretaVazia = 'o', peca_preta = 'p', peca_branca = 'b', damaPreta = 'P', damaBranca = 'B';

    //coordenadas, sendo x0 e y0 valores iniciais
    int x0,y0,x1,y1;

    // Coloquei a condição para iniciar como dama aqui porque o primeiro output do tabuleiro ja aplica diretamente a condição"""
    for(int i = 0; i < tamanho; i++){
        
        if(tabuleiro[0][i] == 'b'){
            tabuleiro[0][i] = damaBranca;
        }

        if(tabuleiro[tamanho-1][i] == 'p'){
            tabuleiro[tamanho-1][i] = damaPreta;
        } 
        
    }
    //output do tabuleiro
    for(int i = 0; i < tamanho; i++){
        for(int j = 0; j < tamanho; j++){
            printf("%c ",tabuleiro[i][j]);
        }
        printf("\n");
    } 
    

    while(x0 + y0 + x1 + y1 != 0){
    //Jogadas:
        //Coloquei os prints para voce ver no terminal"""
        printf("----------------------------------\n");
        printf("Informe as jogadas: ");
        scanf("%d %d %d %d",&x0,&y0,&x1,&y1);


    //jogadas inválidas:


    //se a peça origem for p (PEÇA PRETA), e seu movimento destino, tiver linha destino menor que a origem, movimento inválido.
        if(tabuleiro[x0][y0] == 'p'){
            if(x1 < x0 ){
                continue;
            }
        }

    //se origem ==  peça branca, então sua linha vai sempre diminuir, caso contrário, movimento inválido
        if(tabuleiro[x0][y0] == 'b'){
            
            if(x1 > x0){
                
                continue;
            }
        }

    //não andar em espaçoes vazios:
        if(tabuleiro[x0][y0] == 'b' || 'p' || 'P' || 'B'){
            
            if(tabuleiro[x1][y1] == ' '){
                continue;
            }
        }


    
    //conição limite de tabuleiro (consertar isso) o meu codigo está logo abaixo, tenta reproduzir algo parecido
        //meu codigo - não sei se você vai precisar, mas ta ai como eu fiz.'''
        // if (tabuleiro[x0][y0] == 'b' || 'p' || ' ' || 'o'|| 'P' || 'B'){
        //     if(x0 < 0 || x0 > tamanho - 1|| x1 > tamanho -1 || y0 < 0 || x1 < 0 || y1 < 0 || y1 > tamanho - 1) {        // se o valor for excedente ao da matriz, o codigo irá invalidar

        //         continue;

        //     }

        // }
        
    //movimentos de captura peça PRETA:

        if(tabuleiro[x0][y0] == 'p'){
            if(tabuleiro[x1][y1] == 'o'){
                
                tabuleiro[x0][y0] = 'o';    
                tabuleiro[x1][y1] = 'p' ;
                
                //você estava fechando o if acima aqui e isso estava bugando suas capturas"""
                
                // direita
                    if(x0+1 == x1-1 && y0+1 == y1-1){
                        if(tabuleiro[x1-1][y1-1] == 'b' || tabuleiro[x1-1][y1-1] == 'B' ){
                            
                            printf("capturando para a direita\n");
                            
                            tabuleiro[x1-1][y1-1] = 'o';
                            
                            tabuleiro[x1][y1] = 'p';    
                            
                            tabuleiro[x0][y0] = 'o';

                            pontos_preta+=1; 
                            
                        }

                    }
                
                
                //movimentação para a esquerda
                    else if(x0+1 == x1-1 && y0-1 == y1+1){
                        if(tabuleiro[x1-1][y1+1] == 'B' || tabuleiro[x1-1][y1+1] == 'b' ){
                            
                            tabuleiro[x1-1][y1+1] = 'o';
                            
                            tabuleiro[x1][y1] = 'p';    
                            
                            tabuleiro[x0][y0] = 'o';

                            pontos_preta +=1;
                            
                            //printf("capturando para a esquerda\n");
                        }
                    } 
                
                    //condição dama preta: MUDEI AQUI TAMBEM :)
                    if(x1 == tamanho-1){
                    
                        tabuleiro[x1][y1] = damaPreta;
                        
                        pontos_preta +=1;
                    
                        printf("dama P\n");

                    } 
            } 
        }

        // peças brancas
        if(tabuleiro[x0][y0] == 'b'){
            
            if(tabuleiro[x1][y1] == 'o'){
                
                tabuleiro[x0][y0] = 'o';
                tabuleiro[x1][y1] = 'b';   
                    
                    
                //captura para direita
                    if(x0-1 == x1+1 && y0+1 == y1-1 ){
                    
                        if(tabuleiro[x1+1][y1-1] == 'p' || 'P'){
                            //printf("capturando para a direita. \n");
                            tabuleiro[x1+1][y1-1] = 'o';
                        
                            tabuleiro[x0][y0] = 'o';
                        
                            tabuleiro[x1][y1] = 'b'; 
                        
                            pontos_branca+=1;

                            
                        }
                    } 
                    //captura para esquerda
                    else if(x0-1 == x1+1 && y0-1 == y1+1){
                        if(tabuleiro[x1+1][y1+1] == 'p' || 'P'){
                            
                            tabuleiro[x1+1][y1+1] = 'o';
                            
                            tabuleiro[x0][y0] = 'o';
                            
                            tabuleiro[x1][y1] = 'b';
                        
                            pontos_branca+=1;   

                            printf("esquerda b\n");     
                        }
                    }
                    // condição para a peça branca virar dama.
                    if(x1 == 0){
                        
                            tabuleiro[x1][y1] = damaBranca;
                            
                            pontos_branca +=1;
                        
                            printf("dama Branca\n");

                    } 
            }
           
        }

        
        //DAMA BRANCA: ----------------------------------------
        if(tabuleiro[x0][y0] == 'B'){
            
            if(tabuleiro[x1][y1] == 'o'){
                
                tabuleiro[x0][y0] = 'o';
                
                tabuleiro[x1][y1] = 'B';

                //captura da dama branca como peça branca-------------------------
                    if(x0-1 == x1+1 && y0+1 == y1-1 ){
                    
                        if(tabuleiro[x1+1][y1-1] == 'p' || 'P'){
                            
                            printf("capturando para a direita. \n");
                            
                            tabuleiro[x1+1][y1-1] = 'o';
                        
                            tabuleiro[x0][y0] = 'o';
                        
                            tabuleiro[x1][y1] = 'B'; 
                        
                            pontos_branca+=1;

                            
                        }
                    } 
                    else if(x0-1 == x1+1 && y0-1 == y1+1){
                        
                        if(tabuleiro[x1+1][y1+1] == 'p' || 'P'){
                            
                            tabuleiro[x1+1][y1+1] = 'o';
                            
                            tabuleiro[x0][y0] = 'o';
                            
                            tabuleiro[x1][y1] = 'B';
                        
                            pontos_branca+=1;   

                            printf("esquerda b\n");     
                        }
                    }
                
                //captura da DAMA BRANCA como PEÇA PRETA-----------------
                    if(x0+1 == x1-1 && y0+1 == y1-1){
                        if(tabuleiro[x1-1][y1-1] == 'p' || tabuleiro[x1-1][y1-1] == 'P' ){
                            
                            printf("capturando para a direita\n");
                            
                            tabuleiro[x1-1][y1-1] = 'o';
                            
                            tabuleiro[x1][y1] = 'B';    
                            
                            tabuleiro[x0][y0] = 'o';

                            pontos_branca+=1; 
                            
                        }

                    }

                    else if(x0+1 == x1-1 && y0-1 == y1+1){
                        if(tabuleiro[x1-1][y1+1] == 'p' || tabuleiro[x1-1][y1+1] == 'P' ){
                            
                            tabuleiro[x1-1][y1+1] = 'o';
                            
                            tabuleiro[x1][y1] = 'B';    
                            
                            tabuleiro[x0][y0] = 'o';

                            pontos_branca +=1;
                            
                           printf("capturando para a esquerda\n");
                        }
                    } 
            }
        }

        //DAMA PRETA -------------------------------------
        if(tabuleiro[x0][y0] == 'P'){
            
            if(tabuleiro[x1][y1] == 'o'){
                tabuleiro[x0][y0] = 'o';
                tabuleiro[x1][y1] = 'P';

                //DAMA PRETA CAPTURANDO COMO PEÇA PRETA(PARA BAIXO)-----
                if(x0+1 == x1-1 && y0+1 == y1-1){
                        if(tabuleiro[x1-1][y1-1] == 'b' || tabuleiro[x1-1][y1-1] == 'B' ){      //DIREITA
                            
                            //printf("capturando para a direita DAMA PRETA\n");
                            
                            tabuleiro[x1-1][y1-1] = 'o';
                            
                            tabuleiro[x1][y1] = 'p';    
                            
                            tabuleiro[x0][y0] = 'o';

                            pontos_preta+=1; 
                            
                        }

                    }
                else if(x0+1 == x1-1 && y0-1 == y1+1){
                        if(tabuleiro[x1-1][y1+1] == 'B' || tabuleiro[x1-1][y1+1] == 'b' ){      //ESQUERDA
                            
                            tabuleiro[x1-1][y1+1] = 'o';
                            
                            tabuleiro[x1][y1] = 'P';    
                            
                            tabuleiro[x0][y0] = 'o';

                            pontos_preta +=1;
                            
                            //printf("capturando para a esquerda DAMA PRETA\n");
                        }
                    } 
                //CAPTURA DAMA PRETA COMO PEÇA BRANCA(SUBINDO)---------------
                if(x0-1 == x1+1 && y0+1 == y1-1 ){
                    
                        if(tabuleiro[x1+1][y1-1] == 'B' || 'b'){
                           
                            //printf("capturando para a direita DAMA PRETA \n");        //direita
                            
                            tabuleiro[x1+1][y1-1] = 'o';
                        
                            tabuleiro[x0][y0] = 'o';
                        
                            tabuleiro[x1][y1] = 'P';
                        
                            pontos_preta+=1;

                            
                        }
                    } 
                else if(x0-1 == x1+1 && y0-1 == y1+1){
                        
                        if(tabuleiro[x1+1][y1+1] == 'b' || 'B'){
                            
                            tabuleiro[x1+1][y1+1] = 'o';
                            
                            tabuleiro[x0][y0] = 'o';
                            
                            tabuleiro[x1][y1] = 'P';
                        
                            pontos_preta+=1;   

                            //printf("esquerda DAMA PRETA b\n");     
                        }
                    }

            }
        }

        for(int i = 0; i < tamanho; i++){
            for(int j = 0; j < tamanho; j++){
                printf("%c ", tabuleiro[i][j]);
            }
            printf("\n");
        }
        
        printf("PRETAS %d\n",pontos_preta);
        printf("BRANCAS %d\n",pontos_branca);
        
        x0 + y0 + x1 + y1;
    }

    printf("PRETAS %d\n",pontos_preta);
    printf("BRANCAS %d\n",pontos_branca);

    if(pontos_preta  ==  pontos_branca){
        printf("EMPATE");
    } 
    else if(pontos_preta > pontos_branca){
            printf("PRETAS VENCERAM");
    } 
    else {
        printf("BRANCAS VENCERAM");
    }


return 0;
}
