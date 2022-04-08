#include <stdio.h>
#define tmax 14


int main(){

    int tamanho;
    char entrada[tmax];

    
    fgets(entrada,tmax,stdin);
    sscanf(entrada,"%d",&tamanho);

    char tabuleiro[tmax][tmax];


    //input do tabuleiro
    
        for( int i = 0;i < tamanho; i++){
            fgets(tabuleiro[i],tmax, stdin);
        }
        printf("\n");

    //salvar as pontuações das peças pretas e brancas
    int pontos_preta=0,pontos_branca=0;

    //caracteres e seus significados
    char pretaVazia = 'o', peca_preta = 'p', peca_branca = 'b', damaPreta = 'P', damaBranca = 'B';

    //coordenadas, sendo x0 e y0 valores iniciais
    int x0,y0,x1,y1;

    // se, ao iniciar, a bordas do tabuleiro x(0) e x(tamanho-1) (siginifica, por exemplo: 12-1(visto que começamos matriz e vetor, na linha 0) 
    //possuirem damas, esse loop irá troca-las de  posição: b por B e p por p.
    
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
    
    
    //Jogadas--------------------------------------
        
        
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

        
    //movimentos de captura peça PRETA:

        if(tabuleiro[x0][y0] == 'p'){
                
            if(tabuleiro[x1][y1] == 'o'){
                
                    tabuleiro[x0][y0] = 'o';    
                
                    tabuleiro[x1][y1] = 'p' ;
            
                
                // para a direita
                if(x0+1 == x1-1 && y0+1 == y1-1){
                        
                    if(tabuleiro[x1-1][y1-1] == 'b' || tabuleiro[x1-1][y1-1] == 'B' ){
                            
                            
                            tabuleiro[x1-1][y1-1] = 'o';
                            
                            tabuleiro[x1][y1] = 'p';    

                            pontos_preta+=1; 
                            
                    }

                }
                
                
                //movimentação para a esquerda
                else if(x0+1 == x1-1 && y0-1 == y1+1){
                    if(tabuleiro[x1-1][y1+1] == 'B' || tabuleiro[x1-1][y1+1] == 'b' ){
                            
                            tabuleiro[x1-1][y1+1] = 'o';
                            
                            tabuleiro[x1][y1] = 'p';    
                        
                            pontos_preta +=1;
                            
                            
                    }
                } 
                
                    //condição dama preta: 
                    if(tabuleiro[x1][y1] == tabuleiro[tamanho-1][y1]){
                    
                            tabuleiro[x1][y1] = damaPreta;
                        
                            pontos_preta +=1;
                    
                            tabuleiro[x0][y0] = 'o';

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
                            
                            tabuleiro[x1+1][y1-1] = 'o';
    
                            tabuleiro[x1][y1] = 'b'; 
                        
                            pontos_branca+=1;

                    }
                } 
                    //captura para esquerda
                else if(x0-1 == x1+1 && y0-1 == y1+1){
                        
                    if(tabuleiro[x1+1][y1+1] == 'p' || 'P'){
                            
                            tabuleiro[x1+1][y1+1] = 'o';
                            
                            tabuleiro[x1][y1] = 'b';
                        
                            pontos_branca+=1;   

                    }
                }
                    
                    // condição para a peça branca virar dama.
                if(tabuleiro[x1][y1] == tabuleiro[0][y1]){
                        
                        tabuleiro[x1][y1] = damaBranca;
                            
                        pontos_branca +=1;
                            
                        tabuleiro[x0][y0] = 'o';

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
                            
                            tabuleiro[x1+1][y1-1] = 'o';
                        
                            tabuleiro[x1][y1] = 'B'; 
                        
                            pontos_branca+=1;

                            
                        }
                    } 
                    else if(x0-1 == x1+1 && y0-1 == y1+1){
                        
                        if(tabuleiro[x1+1][y1+1] == 'p' || 'P'){
                            
                            tabuleiro[x1+1][y1+1] = 'o';
                            
                            tabuleiro[x1][y1] = 'B';
                        
                            pontos_branca+=1;   

                        }
                    }
                
                //captura da DAMA BRANCA como PEÇA PRETA-----------------
                    if(x0+1 == x1-1 && y0+1 == y1-1){
                        
                        if(tabuleiro[x1-1][y1-1] == 'p' || tabuleiro[x1-1][y1-1] == 'P' ){
                        
                            
                            tabuleiro[x1-1][y1-1] = 'o';
                            
                            tabuleiro[x1][y1] = 'B';    

                            pontos_branca+=1; 
                            
                        }

                    }

                    else if(x0+1 == x1-1 && y0-1 == y1+1){
                        
                        if(tabuleiro[x1-1][y1+1] == 'p' || tabuleiro[x1-1][y1+1] == 'P' ){
                            
                            tabuleiro[x1-1][y1+1] = 'o';
                            
                            tabuleiro[x1][y1] = 'B';    

                            pontos_branca +=1;
                        
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
                                
                                
                            tabuleiro[x1-1][y1-1] = 'o';
                                
                            tabuleiro[x1][y1] = 'p';    
                                
                            pontos_preta+=1; 
                                
                        }

                    }
                    else if(x0+1 == x1-1 && y0-1 == y1+1){
                        
                        if(tabuleiro[x1-1][y1+1] == 'B' || tabuleiro[x1-1][y1+1] == 'b' ){   //ESQUERDA
                                
                            tabuleiro[x1-1][y1+1] = 'o';
                                
                            tabuleiro[x1][y1] = 'P';    

                            pontos_preta +=1;
                                
                                
                        }
                    } 
                    //CAPTURA DAMA PRETA COMO PEÇA BRANCA(SUBINDO)---------------
                    if(x0-1 == x1+1 && y0+1 == y1-1 ){
                        
                        if(tabuleiro[x1+1][y1-1] == 'B' || 'b'){
                                                                                    //direita
                                
                            tabuleiro[x1+1][y1-1] = 'o';
                            
                            tabuleiro[x1][y1] = 'P';
                            
                            pontos_preta+=1;

                                
                        }
                    } 
                    else if(x0-1 == x1+1 && y0-1 == y1+1){
                            
                        if(tabuleiro[x1+1][y1+1] == 'b' || 'B'){                       //esquerda
                                
                            tabuleiro[x1+1][y1+1] = 'o';
                                
                            tabuleiro[x1][y1] = 'P';
                            
                            pontos_preta+=1;   

                                    
                        }
                    }
                }
            }
        
        //printar o tabuleiro--------------
        for(int i = 0; i < tamanho; i++){
            for(int j = 0; j < tamanho; j++){
                printf("%c ", tabuleiro[i][j]);
           }
            printf("\n");
        }
        
        
        
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
