# <p align="center"> Robot-L: Compilador para Simulação de Robô Móvel </p>  
## <p align="center"> (Projeto de Compiladores - 2019.2) </p> 

## Objetivo

Verificar e fortalecer os conhecimentos relacionados à técnica e à teoria para projeto e construção de compiladores, através do desenvolvimento de um compilador para uma linguagem de alto nível focada no controle de robô móvel.

## Descrição

A avaliação consiste no desenvolvimento de um compilador capaz de realizar a transformação de um programa fonte, escrito usando uma linguagem de alto nível, para um programa em linguagem de montagem.

## Cenário para uma linguagem de uso específico

A linguagem de alto nível foi especialmente projetada para um cenário muito específico, em que um robô móvel atua em um ambiente no qual precisa desviar de obstáculos e controlar a iluminação acendendo ou apagando lâmpadas.

## Descrição geral do Compilador

O compilador a ser construído deve possuir os seguintes blocos: analisador léxico, analisador sintático, analisador semântico e gerador de código em linguagem de montagem.

**Os blocos analisadores devem ser construídos seguindo os requisitos apresentados na Tabela 1**

<p align="center"> **Tabela 1 - Requisitos mínimos para os blocos de analisadores** </p>

<p align="center"><img src="imgs/Tabela1.png?raw=true" alt="Tabela 1 - Requisitos mínimos para os blocos de analisadores" title="Tabela 1 - Requisitos mínimos para os blocos de analisadores"><br></p>

## Descrição geral da Linguagem Robot L

A linguagem de programação Robot-L tem como propósito prover mecanismos simples para a manipulação de robôs móveis. Para tanto, a mesma é composta por uma sintaxe simples e declarações de alto nível. A especificação realizada é baseada na linguagem Karel^2 e é apresentada na Tabela 2.

- Os terminais estão descritos entre aspas duplas e em negrito.
- O símbolo * representa zero ou mais ocorrências do não-terminal à esquerda deste símbolo.
- Produções opcionais estão entre colchetes.
- O compilador deve aceitar palavras escritas em minúsculas ou maiúsculas.
- Comentários são definidos em linhas iniciadas com o símbolo “#”

<p align="center">  Tabela 2 - Especificação da gramática da Robot-L </p>

<p align="center"><img src="imgs/Tabela2.png?raw=true" alt="Tabela 2 - Especificação da gramática da Robot-L" title="Tabela 2 - Especificação da gramática da Robot-L"><br></p>


## Programa exemplo

Usando a gramática apresentada na seção anterior é possível compor o programa apresentado no Exemplo 1. O objetivo desse programa é acender uma lâmpada supondo a existência/conhecimento do mapa do ambiente no qual se encontra o robô.

<p align="center"><img src="imgs/Exemplo1.png?raw=true" alt="Exemplo 1 - Exemplo de Programa Usando a Robot-L" title="Exemplo 1 - Exemplo de Programa Usando a Robot-L"><br></p>

## Descrição das declarações

Maiores detalhes sobre as declarações da linguagem Robot-L podem ser encontrados na Tabela 3.

<p align="center">  Tabela 3 - Detalhes sobre as declarações da linguagem </p>

<p align="center"><img src="imgs/Tabela3.png?raw=true" alt="Tabela 3 - Detalhes sobre as declarações da linguagem" title="Tabela 3 - Detalhes sobre as declarações da linguagem"><br></p>

## Regras semânticas

As regras semânticas definidas para a linguagem não permite que:

- Existam duas declarações de instrução com o mesmo nome;
- Declarações ***Vire Para*** imediatamente subseqüentes tenham sentidos diferentes.

Exemplos:

<p align="center"><img src="imgs/Exemplos_2-a-6.png?raw=true" alt="Exemplos de Regras Semânticas" title="Exemplos de Regras Semânticas"><br></p>

- Uma vez que o robô é composto por dispositivos mecânicos, algumas instruções precisam ser concluídas para que novas instruções possam ser executadas, assim:

Após uma instrução ***Mova n*** , em que ***n*** representa o número de passos, deve ser precedida por uma instrução do tipo ***Aguarde Até Pronto***;

## Geração de código

Uma vez que o processamento léxico, sintático e semântico do código foi bem sucedido, o compilador deve traduzir o código fonte para um código intermediário em linguagem de montagem, seguindo o padrão Intel 8086.

O código *assembly* gerado pode ser executado usando o emulador de 8086, denominado emu8086. Nesse emulador, é considerada a possibilidade de comunicação com elementos externos através de portas de E/S (comandos *in* e *out*). O emulador suporta o *interfaceamento* com dispositivos virtuais que podem ser criados usando qualquer linguagem de programação que permita manipulação de arquivos.

O *interfaceamento* com tais dispositivos é feito usando um arquivo (*emu8086.io*) para comunicação com o dispositivo virtual. A
porta *0* é representa pelo *byte* zero no arquivo, a porta *1* pelo *byte* um, a porta *2* pelo *byte* dois, e assim por diante. Através do arquivo podem-se endereçar portas de *000000* a *0FFFFh* (*0* a *65535*).

No emu8086 existe a possibilidade de *interfaceamento* com um robô móvel (dispositivo virtual previamente disponível como exemplo no simulador).

O robô é controlado pelo envio de dados para a porta de E/S de número 9. Considerando os comandos da Tabela 4.

<p align="center">  Tabela 4 - Lista de comandos para o robô móvel </p>

<p align="center"><img src="imgs/Tabela4.png?raw=true" alt="Tabela 4 - Lista de comandos para o robô móvel" title="Tabela 4 - Lista de comandos para o robô móvel"><br></p>

Um exemplo de transformação pode ser vista no Exemplo 7.

<p align="center"><img src="imgs/Exemplo7.png?raw=true" alt="Exemplo 7 - Exemplo de transformação de código" title="Exemplo 7 - Exemplo de transformação de código"><br></p>

As informações sobre a execução do comando “examinar” enviado para o robô pode ser obtido através do registrador de dados (porta 10). Como pode ser visto na Tabela 5.

<p align="center">  Tabela 5 - Registrador de dados </p>

<p align="center"><img src="imgs/Tabela5.png?raw=true" alt="Tabela 5 - Registrador de dados" title="Tabela 5 - Registrador de dados"><br></p>

O registrador de estado atual do robô pode ser obtido usando o registrador de estado (porta 11), ver Tabela 6.

<p align="center">  Tabela 6 - Registrador de estado </p>

<p align="center"><img src="imgs/Tabela6.png?raw=true" alt="Tabela 6 - Registrador de estado" title="Tabela 6 - Registrador de estado"><br></p>

Maiores detalhes sobre o funcionamento do emulador e da biblioteca de instruções 8086 disponível para uso podem ser encontrados no manual^3 de funcionamento que vem junto com o programa instalador do emu8086.

## Considerações

- Os detalhes da simulação de robô móvel podem ser encontrados na seção “I/O ports and Hardware Interrupts” do manual do emu8086.
- Um código exemplo para a manipulação do robô pode ser encontrado no arquivo robot.asm, na pasta examples do simulador.
- Imagem do robô no simulador pode ser vista na figura abaixo.

<p align="center"><img src="imgs/Consideracoes.png?raw=true" alt="Imagem do robô no simulador" title="Imagem do robô no simulador"><br></p>

## Entrega e Pontuação

**Entrega do Código Final + Artigo**: **20/11/2019** (para todas as equipes).


**Apresentações**: nas aulas dos dias 25/11, 27/11 e 02/12 (ordem definida por sorteio no dia 20/11/2019).


**Documentação**: Todo código gerado deve estar devidamente documentado. Deve ser criado um Artigo em formato de artigos da SBC^4 relatando todo o projeto, as decisões tomadas pela equipe, e os trechos do código fonte que ilustrem as decisões. Devem ser incluídos exemplos dos erros considerados e como o compilador responde a cada tipo de erro.


**Critérios de Avaliação**


- considerará o uso das técnicas de projeto e desenvolvimento de compiladores vistos em sala de aula;
- Para cumprir com a avaliação considera-se a entrega dos produtos descritos na Tabela 7.
- **Atenção:** Programas que não compilam ou com cópias totais /parciais (plágio) terão nota zero.
- Entregas fora do prazo estabelecido terão desconto de 20% da nota por dia de atraso.
- As notas serão atribuídas de forma totalizada para todo o grupo, e o grupo decidirá como será feita a redistribuição interna.
Assim, um grupo de 3 pessoas pode receber a nota 24, e decidir que a nota do Aluno 1 é 10; Aluno 2 é 8 e Aluno 3 é 6.

<p align="center">  Tabela 7 - Produtos e Pontuação </p>

<p align="center"><img src="imgs/Tabela7.png?raw=true" alt="Tabela 7 - Produtos e Pontuação" title="Tabela 7 - Produtos e Pontuação"><br></p>


