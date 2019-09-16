# <div style="text-align: justify"> Robot-L: Compilador para Simulação de Robô Móvel </div>  
## (Projeto de Compiladores 2019.2 - Bacharelado de Ciência da Computação UFBA)

## Objetivo

Verificar e fortalecer os conhecimentos relacionados à técnica e à teoria para projeto e construção de compiladores, através do desenvolvimento de um compilador para uma linguagem de alto nível focada no controle de robô móvel.

## Descrição

A avaliação consiste no desenvolvimento de um compilador capaz de realizar a transformação de um programa fonte, escrito usando uma linguagem de alto nível, para um programa em linguagem de montagem.

## Cenário para uma linguagem de uso específico

A linguagem de alto nível foi especialmente projetada para um cenário muito específico, em que um robô móvel atua em um ambiente no qual precisa desviar de obstáculos e controlar a iluminação acendendo ou apagando lâmpadas.

## Descrição geral do Compilador

O compilador a ser construído deve possuir os seguintes blocos: analisador léxico, analisador sintático, analisador semântico e gerador de código em linguagem de montagem.

**Os blocos analisadores devem ser construídos seguindo os requisitos apresentados na Tabela 1**

<div style="text-align: center"> Tabela 1 - Requisitos mínimos para os blocos de analisadores </div>

## Descrição geral da Linguagem Robot L

A linguagem de programação Robot-L tem como propósito prover mecanismos simples para a manipulação de robôs móveis. Para tanto, a mesma é composta por uma sintaxe simples e declarações de alto nível. A especificação realizada é baseada na linguagem Karel^2 e é apresentada na Tabela 2.

• Os terminais estão descritos entre aspas duplas e em negrito.
• O símbolo * representa zero ou mais ocorrências do não-terminal à esquerda deste símbolo.
• Produções opcionais estão entre colchetes.
• O compilador deve aceitar palavras escritas em minúsculas ou maiúsculas.
• Comentários são definidos em linhas iniciadas com o símbolo “#”

<div style="text-align: center"> Tabela 2 - Especificação da gramática da Robot-L </div>

## Programa exemplo

Usando a gramática apresentada na seção anterior é possível compor o programa apresentado no Exemplo 1. O objetivo desse programa é acender uma lâmpada supondo a existência/conhecimento do mapa do ambiente no qual se encontra o robô.

## Descrição das declarações

Maiores detalhes sobre as declarações da linguagem Robot-L podem ser encontrados na Tabela 3.

<div style="text-align: center"> Tabela 3 - Detalhes sobre as declarações da linguagem </div>

## Regras semânticas

As regras semânticas definidas para a linguagem não permite que:

• Existam duas declarações de instrução com o mesmo nome;
• Declarações imediatamente subseqüentes tenham sentidos diferentes.

Exemplos:

• Uma vez que o robô é composto por dispositivos mecânicos, algumas instruções precisam ser concluídas para que novas instruções possam ser executadas, assim:
Após uma instrução ***Mova n*** , em que ***n*** representa o número de passos, deve ser precedida por uma instrução do tipo ***Aguarde Até Pronto***;

## Geração de código

Uma vez que o processamento léxico, sintático e semântico do código foi bem sucedido, o compilador deve traduzir o código fonte para um código intermediário em linguagem de montagem, seguindo o padrão Intel 8086.

<div style="text-align: center"> Tabela 4 - Lista de comandos para o robô móvel </div>
 
## Entrega e Pontuação
