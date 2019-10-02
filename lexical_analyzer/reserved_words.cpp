/*
    O compilador deve aceitar palavras escritas em minúsculas ou maiúsculas (especificação)
    Exemplo de palavras reservadas aceitas (notou-se de acordo com o exemplo):
        mova (todas as letras minúsculas)
        MOVA (todas as letras maiúsculas)
        Mova (apenas primeira letra maiúscula)
    obs.: implementar expressão regular para não precisar inserir as três formas para cada palavra reservada.
*/
#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<string> reserved_words;
    reserved_words = {

                    "programainicio","PROGRAMAINICIO", "Programainicio",
                    "execucaoinicio", "EXECUCAOINICIO", "Execucaoinicio",
                    "fimexecucao", "FIMEXECUCAO", "Fimexecucao",
                    "fimprograma", "FIMPROGRAMA", "Fimprograma",
                    "definainstrucao", "DEFINAINSTRUCAO", "Definainstrucao",
                    "como", "COMO", "Como",
                    "inicio", "INICIO", "Inicio",
                    "fim", "FIM", "Fim",
                    "repita","REPITA", "Repita",
                    "vezes", "VEZES", "Vezes",
                    "fimrepita", "FIMREPITA", "Fimrepita",
                    "enquanto", "ENQUANTO", "Enquanto",
                    "faca", "FACA", "Faca",
                    "fimpara", "FIMPARA", "Fimpara",
                    "se", "SE", "Se",
                    "entao", "ENTAO", "Entao",
                    "fimse", "FIMSE", "Fimse",
                    "senao", "SENAO", "Fimsenao",
                    "mova", "MOVA", "Mova",
                    "passos", "PASSOS", "Passos",
                    "vire para", "VIRE PARA", "Vire Para",
                    "pare", "PARE", "Pare",
                    "finalize", "FINALIZE", "Finalize",
                    "apague lampada", "APAGUE LAMPADA", "Apague Lampada",
                    "acenda lampada", "ACENDA LAMPADA", "Acenda Lampada",
                    "aguarde ate", "AGUARDE ATE", "Aguarde Ate",
                    "robo pronto", "ROBO PRONTO", "Robo Pronto",
                    "robo ocupada", "ROBO OCUPADO", "Robo Ocupado",
                    "robo parado", "ROBO PARADO", "Robo Parado",
                    "robo movimentando", "ROBO MOVIMENTANDO", "Robo Movimentando",
                    "frente robo bloqueada", "FRENTE ROBO BLOQUEADA", "Frente Robo Bloqueada",
                    "direita robo bloqueada", "DIREITA ROBO BLOQUEADA", "Direita Robo Bloqueada",
                    "esquerda robo bloqueada", "ESQUERDA ROBO BLOQUEADA", "Esquerda Robo Bloequada",
                    "lampada acessa a frente", "LAMPADA ACESSA A FRENTE", "Lampada Acessa a Frente",
                    "lampada apagada a frente", "LAMPADA APAGADA A FRENTE", "Lampada Apagada a Frente",
                    "lampada acessa a esquerda", "LAMPADA ACESSA A ESQUERDA", "Lampada Acessa a Esquerda",
                    "lampada apagada a esquerda", "LAMPADA APAGADA A ESQUERDA", "Lampada Apagada a Esquerda",
                    "lampada acessa a direita", "LAMPADA ACESSA A DIREITA", "Lampada Acessa a Direita",
                    "lampada apagada a direita", "LAMPADA APAGADA A DIREITA", "Lampada Apagada a Direita"
             
                    };
                    /* Testando a impressão das palavras reservadas
                    for(int i = 0; i < reserved_words.size(); i++)
                        cout << i << ". " << reserved_words[i] << endl;
                    */
}