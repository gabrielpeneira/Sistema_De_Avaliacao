#include <stdio.h>
#include <stdlib.h>
#include "afinidade.h"

int main()
{
    Sistema sistema;
    sistema.pessoas = NULL;
    sistema.qtdCadastrados = 0;
    
    int opcao;

    do {
        printf("\n========================================\n");
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
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                CadastraPessoas(&sistema);
                break;
            case 2:
                ExibePessoas(&sistema);
                break;
            case 3: {
                int indice = BuscaPessoas(sistema.pessoas, sistema.qtdCadastrados);
                if (indice != -1) {
                    printf("\n=================================================================\n");
                    printf("%-15s%-6s%-6s%-6s%-6s%-6s%-6s\n", "NOME", "MUS", "CIN", "JOG", "ESP", "LEI", "PROG");
                    printf("=================================================================\n");
                    
                    printf("%-15s", sistema.pessoas[indice].nome);
                    for(int j = 0; j < QTD_PREF; j++) {
                        printf("%-6.1f", sistema.pessoas[indice].notas[j]);
                    }
                    printf("\n=================================================================\n\n");
                }
                break;
            }
            case 4:
                ComparaPessoas(&sistema);
                break;
            case 5:
                ComparaAfinidade(&sistema);
                break;
            case 6:
                ExibeRanking(&sistema);
                break;
            case 7:
                AnalisaPreferencia(&sistema);
                break;
            case 0:
                printf("\nEncerrando o sistema...\n");
                break;
            default:
                printf("Essa opcao nao existe.\n");
        }

    } while(opcao != 0);

    if (sistema.pessoas != NULL) {
        free(sistema.pessoas);
    }

    return 0;
}
