#include <stdio.h>
#include <string.h>
#include "afinidade.h"

float leNotaValida(void){
    float nota;
    int valida=0;
    do{
       scanf("%f",&nota);
       if(nota < 0 || nota > 10){
            printf("nota invalida, digite de 0 - 10");
       }else{
            valida = 1;
       }
    }while(!valida);
    return nota;
}
void CadastraPessoas(Pessoas *pessoa){
    int qtdCadastros=0;
    do{
        printf("quantas pessoas serao cadastradas a seguir?\n");
        scanf("%d",&qtdCadastros);
        if(qtdCadastros<1||qtdCadastros>MAX_PESSOAS){
            printf("a quantidade deve estar no intervalo de %d",MAX_PESSOAS);
        }
    }while(qtdCadastros<1||qtdCadastros>MAX_PESSOAS);

    for(int i=0; i<qtdCadastros; i++){
        printf("Qual o nome?\n");
        scanf(" %[^\n]",pessoa->nome[i]);
        printf("o nome escolhido foi %s\n",pessoa->nome[i]);
        printf("qual nivel de afinidade com os seguintes topicos:");
        printf("\n1-Musica");
        pessoa->notas[i][0]= leNotaValida();
        printf("\n2-Cinema");
        pessoa->notas[i][1]= leNotaValida();
        printf("\n3-Jogos");
        pessoa->notas[i][2]= leNotaValida();
        printf("\n4-Esportes");
        pessoa->notas[i][3]= leNotaValida();
        printf("\n5-Leitura");
        pessoa->notas[i][4]= leNotaValida();
        printf("\n6-Programacao");
        pessoa->notas[i][5]= leNotaValida();
    }
    pessoa->qtdCadastrados = qtdCadastros;
    return;
}
void ExibePessoas(Pessoas *pessoa){
    printf("=================================================================\n");
    printf("%-15s%-6s%-6s%-6s%-6s%-6s%-6s\n", "NOME", "MUS", "CIN", "JOG", "ESP", "LEI", "PROG");
    printf("=================================================================\n");
    for(int i=0; i<pessoa->qtdCadastrados;i++){
        printf("%-15s",pessoa->nome[i]);
        for(int j=0;j<QTD_PREF;j++){
            printf("%-6.1f",pessoa->notas[i][j]);
        }
        printf("\n");
    }
    printf("=================================================================\n");
    return;
}

int BuscaPessoas(char nomes[][50], int quantidadePessoas) {
    char nomeProcurado[50];
    
    printf("Digite o nome do usuario que deseja encontrar: ");
    scanf(" %[^\n]", nomeProcurado); 

    for (int i = 0; i < quantidadePessoas; i++) {
        if (strcmp(nomeProcurado, nomes[i]) == 0) { 
            return i; 
        }
    }
    
    printf("\nUsuario não encontrado.\n");
    return -1; 
}
