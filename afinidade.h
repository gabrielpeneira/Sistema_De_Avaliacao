#ifndef AFINIDADE_H_INCLUDED
#define AFINIDADE_H_INCLUDED

#define QTD_PREF 6

typedef struct {
    char nome[50];
    float notas[QTD_PREF];
} Pessoa;

typedef struct {
    Pessoa *pessoas; 
    int qtdCadastrados;
} Sistema;

void CadastraPessoas(Sistema *sistema);
void ExibePessoas(Sistema *sistema);
int BuscaPessoas(Pessoa *pessoas, int quantidadePessoas); 
float EncontraAfinidade(Sistema *sistema, int i, int j);
void ComparaPessoas(Sistema *sistema);
void ComparaAfinidade(Sistema *sistema);
void ExibeRanking(Sistema *sistema);
void AnalisaPreferencia(Sistema *sistema);

#endif // AFINIDADE_H_INCLUDED
