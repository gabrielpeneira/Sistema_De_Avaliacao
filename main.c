#include <stdio.h>
#include <stdlib.h>
#include "afinidade.h"
int main()
{
    Pessoas pessoa;
    int opcao;

    do{
       printf(" ========================================\n");
         printf("SISTEMA DE AFINIDADES\n");
        printf("========================================\n");
        printf("1 - Cadastrar pessoas\n");
        printf("2 - Exibir pessoas e preferencias\n");
        printf("3 - Buscar pessoa pelo nome\n");
        printf("4 - Comparar duas pessoas\n");
        printf("5 - Encontrar pessoa mais semelhante\n");
        printf("6 - Exibir ranking de afinidade\n");
        printf("7 - Analisar preferências de duas pessoas\n");
        printf("0 - Encerrar\n");
        printf("Opcao:\n ");
        scanf("%d",&opcao);

        switch(opcao){
            case 1:CadastraPessoas(&pessoa);
                break;
            case 2:ExibePessoas(&pessoa);
                break;
            case 3:printf("\n");
                break;
            case 4:printf("\n");
                break;
            case 5:printf("\n");
                break;
            case 6:printf("\n");
                break;
            case 7:printf("\n");
                break;
            case 0:printf("\n");

                break;
            default:printf("essa opcao nao existe");
        }

    }while(opcao!=0);

    return 0;
}
