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
        printf("7 - Analisar preferencias de duas pessoas\n");
        printf("0 - Encerrar\n");
        printf("Opcao:\n ");
        scanf("%d",&opcao);

        switch(opcao){
            case 1:CadastraPessoas(&pessoa);
                break;
            case 2:ExibePessoas(&pessoa);
                break;
            case 3:BuscaPessoas(pessoa.nome, pessoa.qtdCadastrados);
                break;
            case 4:ComparaPessoas(&pessoa, pessoa.qtdCadastrados);
                break;
            case 5:ComparaAfinidade(&pessoa, pessoa.qtdCadastrados);
                break;
            case 6:ExibeRanking(&pessoa,pessoa.qtdCadastrados);
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
