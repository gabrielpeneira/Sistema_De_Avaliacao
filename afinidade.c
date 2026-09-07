#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include "afinidade.h"

float leNotaValida(void){
    float nota;
    int valida=0;
    do {
       scanf("%f", &nota);
       if(nota < 0 || nota > 10){
            printf("nota invalida, digite de 0 - 10\n");
       }else{
            valida = 1;
       }
    } while(!valida);
    return nota;
}

void CadastraPessoas(Sistema *sistema){
    int qtdCadastros=0;
    
    printf("quantas pessoas serao cadastradas a seguir?\n");
    scanf("%d", &qtdCadastros);
    
    if(qtdCadastros < 1){
        printf("Quantidade invalida.\n");
        return;
    }

    if (sistema->pessoas != NULL) {
        free(sistema->pessoas);
    }

    sistema->pessoas = (Pessoa *)malloc(qtdCadastros * sizeof(Pessoa));

    if (sistema->pessoas == NULL) {
        printf("ERRO: Falta de memoria! A alocacao falhou.\n");
        sistema->qtdCadastrados = 0;
        return;
    }

    for(int i = 0; i < qtdCadastros; i++){
        printf("Qual o nome?\n");
        scanf(" %[^\n]", sistema->pessoas[i].nome); 
        printf("o nome escolhido foi %s\n", sistema->pessoas[i].nome);
        printf("qual nivel de afinidade com os seguintes topicos:");
        
        printf("\n1-Musica\n");
        sistema->pessoas[i].notas[0] = leNotaValida();
        
        printf("2-Cinema\n");
        sistema->pessoas[i].notas[1] = leNotaValida();
        
        printf("3-Jogos\n");
        sistema->pessoas[i].notas[2] = leNotaValida();
        
        printf("4-Esportes\n");
        sistema->pessoas[i].notas[3] = leNotaValida();
        
        printf("5-Leitura\n");
        sistema->pessoas[i].notas[4] = leNotaValida();
        
        printf("6-Programacao\n");
        sistema->pessoas[i].notas[5] = leNotaValida();
    }
    sistema->qtdCadastrados = qtdCadastros;
}

void ExibePessoas(Sistema *sistema){
    printf("=================================================================\n");
    printf("%-15s%-6s%-6s%-6s%-6s%-6s%-6s\n", "NOME", "MUS", "CIN", "JOG", "ESP", "LEI", "PROG");
    printf("=================================================================\n");
    for(int i = 0; i < sistema->qtdCadastrados; i++){
        printf("%-15s", sistema->pessoas[i].nome);
        for(int j = 0; j < QTD_PREF; j++){
            printf("%-6.1f", sistema->pessoas[i].notas[j]);
        }
        printf("\n");
    }
    printf("=================================================================\n");
}

int BuscaPessoas(Pessoa *pessoas, int quantidadePessoas) {
    char nomeProcurado[50];

    printf("Digite o nome do usuario que deseja encontrar: ");
    scanf(" %[^\n]", nomeProcurado);

    for (int i = 0; i < quantidadePessoas; i++) {
        if (strcmp(nomeProcurado, pessoas[i].nome) == 0) {
            return i;
        }
    }

    printf("\nUsuario não encontrado.\n");
    return -1;
}

float EncontraAfinidade(Sistema *sistema, int i, int j){
    float soma = 0;
    float diferenca = 0;

    for(int k = 0; k < QTD_PREF; k++){
        diferenca = (sistema->pessoas[i].notas[k] - sistema->pessoas[j].notas[k]);
        soma = soma + (diferenca * diferenca);
    }

    return sqrt(soma);
}

void ComparaPessoas(Sistema *sistema){
    int i, j;

    printf("Primeira pessoa:\n");
    i = BuscaPessoas(sistema->pessoas, sistema->qtdCadastrados);
    printf("Segunda pessoa:\n");
    j = BuscaPessoas(sistema->pessoas, sistema->qtdCadastrados);

    if(i == -1 || j == -1 || i == j){
        return;
    }
    printf("COMPARACAO DE PERFIS\n");
    printf("%s x %s\n", sistema->pessoas[i].nome, sistema->pessoas[j].nome);
    printf("distancia euclidiana: %.2f\n", EncontraAfinidade(sistema, i, j));
}

void ComparaAfinidade(Sistema *sistema){
    int i;
    printf("comparando todos os perfis\n");
    do{
        i = BuscaPessoas(sistema->pessoas, sistema->qtdCadastrados);
        if(i == -1){
            printf("nome invalido\n");
        }
    } while(i == -1);

    float menorDist = 0;
    float dist = 0;
    int indMenor = -1;

    for(int j = 0; j < sistema->qtdCadastrados; j++){
        if(i != j){
            dist = EncontraAfinidade(sistema, i, j);
            if(indMenor == -1 || menorDist > dist){
                menorDist = dist;
                indMenor = j;
            }
        }
    }
    if(indMenor == -1){
        printf("nao ha outra pessoa a ser comparada\n");
        return;
    }
    printf("\nPessoa analisada: %s\n", sistema->pessoas[i].nome);
    printf("Pessoa mais semelhante: %s\n", sistema->pessoas[indMenor].nome);
    printf("Distancia euclidiana: %.2f\n", menorDist);
}

void ExibeRanking(Sistema *sistema){
    int i;
    do{
        printf("\nEscolha a pessoa para gerar o ranking:\n");
        i = BuscaPessoas(sistema->pessoas, sistema->qtdCadastrados);
        if(i != -1){
            break;
        } else {
            printf("nome invalido\n");
        }
    } while(1);
    
    float *distancias = (float *)malloc(sistema->qtdCadastrados * sizeof(float));
    int *indices = (int *)malloc(sistema->qtdCadastrados * sizeof(int));
    
    if (distancias == NULL || indices == NULL) {
        printf("Erro de memoria ao gerar o ranking.\n");
        return;
    }

    int qtd = 0;
    for(int j = 0; j < sistema->qtdCadastrados; j++){
        if(i != j){
            distancias[qtd] = EncontraAfinidade(sistema, i, j);
            indices[qtd] = j;
            qtd++;
        }
    }
    
    for(int a = 0; a < qtd - 1; a++){
        for(int b = a + 1; b < qtd; b++){
            if(distancias[b] < distancias[a]){
                float auxDist = distancias[a];
                distancias[a] = distancias[b];
                distancias[b] = auxDist;
                
                int auxIndice = indices[a];
                indices[a] = indices[b];
                indices[b] = auxIndice;
            }
        }
    }
    
    printf("\n====================================\n");
    printf("RANKING DE AFINIDADE COM %s\n", sistema->pessoas[i].nome);
    printf("====================================\n");

    for(int j = 0; j < qtd; j++){
        printf("%d - %-20s distancia: %.2f\n",
               j + 1,
               sistema->pessoas[indices[j]].nome,
               distancias[j]);
    }

    printf("====================================\n");
    
    free(distancias);
    free(indices);
}

void AnalisaPreferencia(Sistema *sistema) {
    int i, j;

    printf("\n--- Selecao dos Perfis ---\n");
    printf("Primeira pessoa:\n");
    i = BuscaPessoas(sistema->pessoas, sistema->qtdCadastrados);
    
    printf("Segunda pessoa:\n");
    j = BuscaPessoas(sistema->pessoas, sistema->qtdCadastrados);

    if (i == -1 || j == -1) {
        return;
    }
    if (i == j) {
        printf("\nVoce deve selecionar duas pessoas diferentes.\n");
        return;
    }

    char *topicos[QTD_PREF] = {
        "Musica", "Cinema", "Jogos", "Esportes", "Leitura", "Programacao"
    };

    float diferencas[QTD_PREF];
    float menorDiferenca = 999.0;

    printf("\n===============================================\n");
    printf("ANALISE DE PERFIS\n");
    printf("===============================================\n");
    printf("%s x %s\n", sistema->pessoas[i].nome, sistema->pessoas[j].nome);
    printf("-----------------------------------------------\n");
    printf("%-15s %-8s %-8s %-10s\n", "Preferencia", sistema->pessoas[i].nome, sistema->pessoas[j].nome, "Diferenca");
    printf("-----------------------------------------------\n");

    for (int k = 0; k < QTD_PREF; k++) {
        float nota1 = sistema->pessoas[i].notas[k];
        float nota2 = sistema->pessoas[j].notas[k];
        
        float dif = fabs(nota1 - nota2);
        diferencas[k] = dif;

        if (dif < menorDiferenca) {
            menorDiferenca = dif;
        }

        printf("%-15s %-8.1f %-8.1f %-10.1f\n", topicos[k], nota1, nota2, dif);
    }

    printf("-----------------------------------------------\n");
    printf("Distancia euclidiana: %.2f\n\n", EncontraAfinidade(sistema, i, j));

    printf("Preferencias mais semelhantes:\n");
    for (int k = 0; k < QTD_PREF; k++) {
        if (fabs(diferencas[k] - menorDiferenca) < 0.0001) {
            printf("- %s\n", topicos[k]);
        }
    }
    printf("===============================================\n");
}
