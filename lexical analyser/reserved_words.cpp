/*
    O compilador deve aceitar palavras escritas em minúsculas ou maiúsculas
    Exemplo de palavras reservadas aceitas (notou-se de acordo com o exemplo):
        MOVA (todas as letras maiúsculas)
        Mova (apenas primeira letra maiúscula)
        mova (todas as letras minúsculas)
    Utilizar expressão regular para não precisar inserir as três formas para cada palavra reservada.
*/
#include <bits/stdc++.h>
void create_reserved_words(list <string> &reserved_words){

    reserved_words.push_back("programainicio");
    reserved_words.push_back("execucaoinicio");
    reserved_words.push_back("fimprograma");
    reserved_words.push_back("definainstrucao");
    reserved_words.push_back("como");
    reserved_words.push_back("inicio");
    reserved_words.push_back("fim");
    reserved_words.push_back("repita");
    reserved_words.push_back("vezes");
    reserved_words.push_back("fimrepita");
    reserved_words.push_back("enquanto");
    reserved_words.push_back("faca");
    reserved_words.push_back("fimpara");
    reserved_words.push_back("se");
    reserved_words.push_back("entao");

}