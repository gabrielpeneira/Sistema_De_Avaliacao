#ifndef AFINIDADE_H_INCLUDED
#define AFINIDADE_H_INCLUDED
#define MAX_PESSOAS 30
#define QTD_PREF 6

typedef struct{
    char nome[MAX_PESSOAS][50];
    float notas[MAX_PESSOAS][QTD_PREF];
    int qtdCadastrados;
} Pessoas;

void CadastraPessoas(Pessoas *pessoa);
void ExibePessoas(Pessoas *pessoa);
int BuscaPessoas(char nomes[][50], int quantidadePessoas);
void ComparaPessoas(Pessoas *pessoa,int quantidadePessoas);
float EncontraAfinidade(Pessoas *pessoa, int i, int j);
void ExibeRanking(Pessoas *pessoa, int quantidadePessoas);
void ComparaAfinidade(Pessoas *pessoa, int quantidadedePessoas);
void AnalisaPreferencia();


#endif // AFINIDADE_H_INCLUDED
