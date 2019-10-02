#include <bits/stdc++.h>
#include <iostream>

using namespace std;

struct keyword{
    string nome;
    string tipo;
};

int main (int argc, char **argv) {

  vector<char>buffer;
  keyword aux;
  bool error = 0;         //para checagem de erros
  char first = ' ';         //guarda o primeiro caracter de cada palavra
  int ascll_first;        //para determinar se o caracter � um numero ou letra
  vector<keyword> reserved_words;  //guarda palavras chave
  vector<string> tabela;
  stack<string> guarda; //guarda combina��es de palavras chave
  queue<string> inverte;
  int estado = 0;

  //============PALAVRAS CHAVE======================================================

  aux.nome = "programainicio", aux.tipo = "Programa", reserved_words.push_back(aux);
  aux.nome = "fimprograma", aux.tipo = "Programa", reserved_words.push_back(aux);
  aux.nome = "execucaoinicio", aux.tipo = "Pograma", reserved_words.push_back(aux);
  aux.nome = "fimexecucao", aux.tipo = "Programa", reserved_words.push_back(aux);
  aux.nome = "definainstrucao", aux.tipo = "Declaracao", reserved_words.push_back(aux);
  aux.nome = "como", aux.tipo = "Declaracao", reserved_words.push_back(aux);
  aux.nome = "inicio", aux.tipo = "Bloco", reserved_words.push_back(aux);
  aux.nome = "fim", aux.tipo = "Declaracao", reserved_words.push_back(aux);
  aux.nome = "repita", aux.tipo = "Iteracao", reserved_words.push_back(aux);
  aux.nome = "fimrepita", aux.tipo = "Iteracao", reserved_words.push_back(aux);
  aux.nome = "vezes", aux.tipo = "Iteracao", reserved_words.push_back(aux);
  aux.nome = "enquanto", aux.tipo = "Laco", reserved_words.push_back(aux);
  aux.nome = "faca", aux.tipo = "Laco", reserved_words.push_back(aux);
  aux.nome = "fimpara", aux.tipo = "Laco", reserved_words.push_back(aux);
  aux.nome = "se", aux.tipo = "Condicional", reserved_words.push_back(aux);
  aux.nome = "fimse", aux.tipo = "Condicional", reserved_words.push_back(aux);
  aux.nome = "entao", aux.tipo = "Condicional", reserved_words.push_back(aux);
  aux.nome = "senao", aux.tipo = "Condicional", reserved_words.push_back(aux);
  aux.nome = "fimsenao", aux.tipo = "Condicional", reserved_words.push_back(aux);
  aux.nome = "mova", aux.tipo = "Instrucao", reserved_words.push_back(aux);
  aux.nome = "passo", aux.tipo = "Instrucao", reserved_words.push_back(aux);
  aux.nome = "vire para", aux.tipo = "Instrucao", reserved_words.push_back(aux);
  aux.nome = "pare", aux.tipo = "Instrucao", reserved_words.push_back(aux);
  aux.nome = "finalize", aux.tipo = "Instrucao", reserved_words.push_back(aux);
  aux.nome = "apague lampada", aux.tipo = "Instrucao", reserved_words.push_back(aux);
  aux.nome = "acenda lampada", aux.tipo = "Instrucao", reserved_words.push_back(aux);
  aux.nome = "aguarde ate", aux.tipo = "Instrucao", reserved_words.push_back(aux);
  aux.nome = "robo pronto", aux.tipo = "Condicao", reserved_words.push_back(aux);
  aux.nome = "robo ocupado", aux.tipo = "Condicao", reserved_words.push_back(aux);
  aux.nome = "robo parado", aux.tipo = "Condicao", reserved_words.push_back(aux);
  aux.nome = "robo movimentando", aux.tipo = "Condicao", reserved_words.push_back(aux);
  aux.nome = "frente robo bloqueada", aux.tipo = "Condicao", reserved_words.push_back(aux);
  aux.nome = "direita robo bloqueada", aux.tipo = "Condicao", reserved_words.push_back(aux);
  aux.nome = "esquerda robo bloqueada", aux.tipo = "Condicao", reserved_words.push_back(aux);
  aux.nome = "lampada acesa a frente", aux.tipo = "Condicao", reserved_words.push_back(aux);
  aux.nome = "lampada apagada a frente", aux.tipo = "Condicao", reserved_words.push_back(aux);
  aux.nome = "lampada acesa a esquerda", aux.tipo = "Condicao", reserved_words.push_back(aux);
  aux.nome = "lampada apagada a esquerda", aux.tipo = "Condicao", reserved_words.push_back(aux);
  aux.nome = "lampada acesa a direita", aux.tipo = "Condicao", reserved_words.push_back(aux);
  aux.nome = "lampada apagada a direita", aux.tipo = "Condicao", reserved_words.push_back(aux);
  aux.nome = "esquerda", aux.tipo = "Sentido", reserved_words.push_back(aux);
  aux.nome = "direita", aux.tipo = "Sentido", reserved_words.push_back(aux);

  //================================================================================

    if (argc < 2){
        cout << "Insira o caminho do arquivo como argumento!\n";
        return -1;
    }

    int lin = 1, col= 0;
    char c;           //para ler caracter por caracter do arquivo
    string aux_palavra; //gera palavra
    ifstream myfile( argv[1] );//("example.txt");

    if(myfile.is_open()){
        myfile.get(c);
        while (!myfile.eof()){
            buffer.push_back(c);
            myfile.get(c);
        }
    }else{
        cout << "Impossível abrir arquivo!\n";
        return -1;
    }

    for (vector<char>::iterator it = buffer.begin(); it != buffer.end(); it++){
        if ((*it >= 'A') && (*it <= 'Z')){
            *it = *it + 32; 
        }
    }

    bool coment = 0;

    for(int k =0;k<buffer.size();k++){
      int ascll = buffer[k];
         if(buffer[k]!=' '&&((ascll>=65&&ascll<=90)||(ascll>=97&&ascll<=122)||(ascll>=48&&ascll<=57))) // buffer[k] � uma letra ou numero v�lido (tabela ascll)
         {
             if(ascll==35)//comentario
             coment = 1;

             if(first==' '&& coment==0) //se n�o salvei nada no primeiro caracter ainda
             {
                 ascll_first = buffer[k]; //vejo se � numero ou letra
                 first = buffer[k]; //salvo
                 aux_palavra = aux_palavra + buffer[k]; //armazena na palavra a ser gerada
             }
             else if(coment==0&&first!=' '&&((ascll_first>=65&&ascll_first<=90)||(ascll_first>=97&&ascll_first<=122))){ // first � uma letra, logo todo char valido continua valido
                aux_palavra  = aux_palavra +buffer[k]; //armazena na palavra a ser gerada
             }
             else if(coment==0&&first!=' '&&((ascll_first>=48&&ascll_first<=57)&&(ascll>=48&&ascll<=57))){// first � um numero, portanto c deve ser um numero
                aux_palavra  = aux_palavra +buffer[k]; //armazena na palavra a ser gerada
             }
             else{
                aux_palavra  = aux_palavra +c;
                bool error =1;
             }
         }
        if(buffer[k]==' '||buffer[k]=='\n'|| k == buffer.size()-1){//possivel palavra encontrada
            bool achou = 0;
            if (buffer[k]=='\n'){
                coment=0;
                lin++;
                col=0;
            }

            if(buffer[k]==' ')
                col++;
            if(aux_palavra.size()>0)//se foi gerada uma palavra
            {
              if(error==1){
                    cout<<"Caracter invalido na linha: "<<lin<<", coluna: "<<col;//<<endl;
                    estado=0;
                    while(guarda.size()>0)//se havia algo dependente a combinar
                    {
                        if(guarda.top()=="direita"||guarda.top()=="esquerda"){
                            cout<<guarda.top()<<"  Sentido";//<<endl;
                            guarda.pop();
                        }
                        else{
                            tabela.push_back(guarda.top());
                            cout<<guarda.top()<<"  ID";//<<endl;
                            guarda.pop();
                        }
                    }
                }

              else
             {
                for(vector<keyword>::iterator it=reserved_words.begin();it!=reserved_words.end();it++){
                    if(aux_palavra==(*it).nome && aux_palavra!= "esquerda" && aux_palavra !="direita"){ //esquerda/direita causa conflito
                        while(guarda.size()>0){
                                    while(guarda.size()>0)
                                    {
                                        inverte.push(guarda.top());
                                        guarda.pop();
                                    }
                                    while(inverte.size()>0)
                                    {
                                        guarda.push(inverte.front());
                                        inverte.pop();
                                    }
                                    while(guarda.size()>0)
                                    {
                                        cout<<guarda.top()<<" ";
                                        if(guarda.top()=="esquerda"||guarda.top()=="direita")
                                            cout<<" Sentido"<<endl;
                                        else
                                            cout<<" ID"<<endl;
                                        guarda.pop();
                                    }
                        }
                        cout<<(*it).nome<<"  "<<(*it).tipo<<endl;
                        achou=1;
                        aux_palavra ="";
                        first=' ';
                        bool error = 0;
                        estado=0;
                        break;
                    }
                }
              }

            if(achou!=1)
            {
              bool retorna=1;
              while(retorna==1){

                   if(estado==0 && buffer[k]==' '&& (aux_palavra=="lampada"||aux_palavra=="robo"||aux_palavra=="esquerda"||aux_palavra=="direita"||aux_palavra=="frente"||
                   aux_palavra=="acenda"||aux_palavra=="apague"||aux_palavra=="vire"||aux_palavra=="aguarde")) //possiveis palavras chave
                    {
                        guarda.push(aux_palavra); //coloca na fila
                        estado++; //avan�a estado
                        retorna=0;
                    }

                    else if((estado==0 &&(buffer[k]=='\n'||k==buffer.size()-1))|| (estado==0&&(aux_palavra!="lampada"&&aux_palavra!="robo"&&aux_palavra!="esquerda"&&aux_palavra!="direita"&&aux_palavra!="frente"&&
                    aux_palavra!="acenda"&&aux_palavra!="apague"&&aux_palavra!="vire"&&aux_palavra!="aguarde" )))
                    {

                        if(aux_palavra=="esquerda"||aux_palavra=="direita"){
                        cout<<aux_palavra<<"  Direcao"<<endl;
                        retorna=0;
                        estado=0;
                        }
                        else
                        {
                        tabela.push_back(aux_palavra);
                        cout<<aux_palavra<<"  ID"<<endl;
                        retorna=0;
                        estado=0;
                        }
                    }

                    else if(estado==1&&(aux_palavra=="apagada"||aux_palavra=="acesa"||aux_palavra=="robo"||aux_palavra=="movimentando"||aux_palavra=="parado"
                        ||aux_palavra=="ocupado"||aux_palavra=="pronto"||aux_palavra=="ate"||aux_palavra=="lampada"||aux_palavra=="para"))
                    {
                          if(guarda.top()=="lampada")
                          {
                              if(aux_palavra=="acesa"||aux_palavra=="apagada")
                              {
                                  if(buffer[k]!='\n'&&k<buffer.size()-1){ //da para continuar
                                    guarda.push(aux_palavra);
                                    estado++;
                                    retorna=0;
                                  }
                                  else{
                                    guarda.push(aux_palavra);
                                    while(guarda.size()>0)
                                    {
                                        inverte.push(guarda.top());
                                        guarda.pop();
                                    }
                                    while(inverte.size()>0)
                                    {
                                        guarda.push(inverte.front());
                                        inverte.pop();
                                    }
                                    while(guarda.size()>0)
                                    {
                                       if(guarda.top()!="esquerda"&&guarda.top()!="direita"){
                                            cout<<guarda.top()<<" ID"<<endl;
                                            tabela.push_back(guarda.top());
                                            guarda.pop();
                                        }
                                        else{
                                            cout<<guarda.top()<<" Direcao"<<endl;
                                            guarda.pop();
                                        }
                                    }
                                    estado=0;
                                    retorna=0;
                                  }
                              }
                              else//lampada eh id
                              {
                                  if(guarda.top()!="esquerda"&&guarda.top()!="direita")
                                    {
                                        cout<<guarda.top()<<" ID"<<endl;
                                        tabela.push_back(guarda.top());
                                    }
                                   else
                                        cout<<guarda.top()<<" Sentido"<<endl;
                                        guarda.pop();
                                  estado--; //volta 1 estado
                                  retorna=1; //nova possivel palavra
                              }
                          }

                          else if(guarda.top()=="robo")
                          {
                              if(aux_palavra=="pronto"||aux_palavra=="parado"||aux_palavra=="ocupado") //eh uma palavra reservada
                              {

                                  cout<<guarda.top()<<" "<<aux_palavra<<"  "<<"Condicao"<<endl;
                                  guarda.pop();
                                  retorna=0;
                                  estado=0; //reseta estado
                              }
                              else// robo eh id
                              {
                                  cout<<guarda.top()<<" ID"<<endl;
                                  tabela.push_back(guarda.top());
                                  guarda.pop();
                                  estado--; //volta 1 estado
                                  retorna=1; //nova possivel palavra
                              }
                          }

                          else if(guarda.top()=="acenda"||guarda.top()=="apague")
                          {

                              if(aux_palavra=="lampada")
                              {
                                  cout<<guarda.top()<<" "<<aux_palavra<<"  "<<"Instrucao"<<endl;
                                  guarda.pop();
                                  retorna=0;
                                  estado=0; //reseta estado
                              }
                              else
                              {
                                   cout<<guarda.top()<<" ID"<<endl;
                                   tabela.push_back(guarda.top());
                                   guarda.pop();
                                  estado--; //volta 1 estado
                                  retorna=1; //nova possivel palavra
                              }
                          }
                          else if(guarda.top()=="vire")
                          {
                               if(aux_palavra=="para")
                              {

                                  cout<<guarda.top()<<" "<<aux_palavra<<"  "<<"Instrucao"<<endl;
                                  guarda.pop();
                                  retorna=0;
                                  estado=0; //reseta estado
                              }
                              else
                              {
                                  cout<<guarda.top()<<" ID"<<endl;
                                   tabela.push_back(guarda.top());
                                   guarda.pop();
                                  estado--; //volta 1 estado
                                  retorna=1; //nova possivel palavra
                              }
                          }

                          else if(guarda.top()=="aguarde")
                          {
                             if(aux_palavra=="ate")
                             {
                                  cout<<guarda.top()<<" "<<aux_palavra<<"  "<<"Instrucao"<<endl;
                                  guarda.pop();
                                  retorna=0;
                                  estado=0; //reseta estado
                             }
                             else
                             {
                                   cout<<guarda.top()<<" ID"<<endl;
                                   tabela.push_back(guarda.top());
                                   guarda.pop();
                                  estado--; //volta 1 estado
                                  retorna=1; //nova possivel palavra
                             }
                           }
                          else if(guarda.top()=="esquerda"||guarda.top()=="direita")
                          {
                               if(aux_palavra=="robo")
                              {

                                 if(buffer[k]!='\n'&&k<buffer.size()-1){ //da para continuar
                                    guarda.push(aux_palavra);
                                    estado++;
                                    retorna=0;
                                  }
                                  else{
                                    guarda.push(aux_palavra);  //n�o da para alocar outra palavra na sequencia
                                     while(guarda.size()>0)
                                    {
                                        inverte.push(guarda.top());
                                        guarda.pop();
                                    }
                                    while(inverte.size()>0)
                                    {
                                        guarda.push(inverte.front());
                                        inverte.pop();
                                    }
                                    while(guarda.size()>0)
                                    {
                                        if(guarda.top()!="esquerda"&&guarda.top()!="direita"){
                                            cout<<guarda.top()<<" ID"<<endl;
                                            tabela.push_back(guarda.top());
                                            guarda.pop();
                                        }
                                        else{
                                            cout<<guarda.top()<<" Direcao"<<endl;
                                            guarda.pop();
                                        }
                                    }
                                    estado=0;
                                    retorna=0;
                                  }
                              }
                              else//lampada eh id
                              {
                                  if(guarda.top()!="esquerda"&&guarda.top()!="direita")
                                    {
                                        cout<<guarda.top()<<" ID"<<endl;
                                        tabela.push_back(guarda.top());
                                        guarda.pop();
                                    }
                                   else{
                                        cout<<guarda.top()<<" Sentido"<<endl;
                                        guarda.pop();
                                   }
                                  estado--; //volta 1 estado
                                  retorna=1; //nova possivel palavra
                              }
                         }

                         else if(guarda.top()=="frente")
                          {
                               if(aux_palavra=="robo")
                              {

                                  if(buffer[k]!='\n'&&k<buffer.size()-1){ //da para continuar
                                    guarda.push(aux_palavra);
                                    estado++;
                                    retorna=0;
                                  }
                                  else{
                                    guarda.push(aux_palavra);
                                    while(guarda.size()>0)
                                    {
                                        inverte.push(guarda.top());
                                        guarda.pop();
                                    }
                                    while(inverte.size()>0)
                                    {
                                        guarda.push(inverte.front());
                                        inverte.pop();
                                    }
                                    while(guarda.size()>0)
                                    {
                                         if(guarda.top()!="esquerda"&&guarda.top()!="direita"){
                                            cout<<guarda.top()<<" ID"<<endl;
                                            tabela.push_back(guarda.top());
                                            guarda.pop();
                                        }
                                        else{
                                            cout<<guarda.top()<<" Sentido"<<endl;
                                            guarda.pop();
                                        }
                                    }
                                    estado=0;
                                    retorna=0;
                                  }
                              }
                              else//lampada eh id
                              {
                                  if(guarda.top()!="esquerda"&&guarda.top()!="direita")
                                    {
                                        cout<<guarda.top()<<" ID"<<endl;
                                        tabela.push_back(guarda.top());
                                        guarda.pop();
                                    }
                                   else{
                                        cout<<guarda.top()<<" Sentido"<<endl;
                                        guarda.pop();
                                   }
                                  estado--; //volta 1 estado
                                  retorna=1; //nova possivel palavra
                              }
                        }
                }
                else if(estado==2&&(aux_palavra=="a"||aux_palavra=="bloqueada"))
                {
                    if(guarda.top()=="robo"){
                        if(aux_palavra=="bloqueada")
                        {
                            guarda.push(aux_palavra);
                            while(guarda.size()>0)
                            {
                                inverte.push(guarda.top());
                                guarda.pop();
                            }
                            while(inverte.size()>0)
                                {
                                guarda.push(inverte.front());
                                inverte.pop();
                                }
                                while(guarda.size()>0)
                                {
                                    cout<<guarda.top()<<" ";
                                    guarda.pop();
                                }
                                    cout<<"  Condicao"<<endl;
                                    retorna=0;
                                    estado=0;
                            }
                              else//primeiro da fila eh id, exceto esquerda e direta
                              {
                                  while(guarda.size()>0){
                                        inverte.push(guarda.top());
                                        guarda.pop();
                                  }
                                  while(inverte.size()>0){
                                    if(inverte.size()>1){
                                        guarda.push(inverte.front());
                                        inverte.pop();
                                    }
                                    else
                                    {
                                       if(inverte.front()!="esquerda"&&inverte.front()!="direita")
                                        {
                                            cout<<inverte.front()<<" ID"<<endl;
                                            tabela.push_back(inverte.front());
                                            inverte.pop();
                                        }
                                        else{
                                            cout<<inverte.front()<<" Sentido"<<endl;
                                            inverte.pop();
                                        }
                                    }
                                  }
                                  estado--;  //retorna 1 estado
                                  retorna=1; //nova possivel palavra
                              }
                        }

                    else if(guarda.top()=="acesa"||guarda.top()=="apagada")
                     {
                              if(aux_palavra=="a")
                              {

                                    if(buffer[k]!='\n'&&k<buffer.size()-1){ //da para continuar
                                    guarda.push(aux_palavra);
                                    estado++;
                                    retorna=0;
                                    }
                                    else//resto da fila eh id
                                    {
                                        guarda.push(aux_palavra);
                                        while(guarda.size()>0)
                                        {
                                            inverte.push(guarda.top());
                                            guarda.pop();
                                        }
                                        while(inverte.size()>0)
                                        {
                                            guarda.push(inverte.front());
                                            inverte.pop();
                                        }
                                        while(guarda.size()>0)
                                        {
                                            if(guarda.top()!="esquerda"&&guarda.top()!="direita"){
                                                cout<<guarda.top()<<" ID"<<endl;
                                                tabela.push_back(guarda.top());
                                                guarda.pop();
                                            }
                                            else{
                                                cout<<guarda.top()<<" Direcao"<<endl;
                                                guarda.pop();
                                            }
                                        }
                                        estado=0;
                                        retorna=0;
                                      }

                              }
                              else//primeiro da fila eh id, exceto esquerda e direta
                              {
                                  while(guarda.size()>0){
                                        inverte.push(guarda.top());
                                        guarda.pop();
                                  }
                                  while(inverte.size()>0){
                                    if(inverte.size()>1){
                                        guarda.push(inverte.front());
                                        inverte.pop();
                                    }
                                    else
                                    {
                                       if(guarda.top()!="esquerda"&&guarda.top()!="direita")
                                        {
                                            cout<<guarda.top()<<" ID"<<endl;
                                            tabela.push_back(guarda.top());
                                            guarda.pop();
                                        }
                                        else{
                                            cout<<guarda.top()<<" Sentido"<<endl;
                                            guarda.pop();
                                        }
                                    }
                                  }
                                  estado--;  //retorna 1 estado
                                  retorna=1; //nova possivel palavra
                              }
                      }

                }
                 else if(estado==3&&(aux_palavra=="direita"||aux_palavra=="esquerda"||aux_palavra=="frente")) //s� tem uma forma de chegar aqui
                 {
                            guarda.push(aux_palavra);

                                    while(guarda.size()>0)
                                    {
                                        inverte.push(guarda.top());
                                        guarda.pop();
                                    }
                                    while(inverte.size()>0)
                                    {
                                        guarda.push(inverte.front());
                                        inverte.pop();
                                    }
                                    while(guarda.size()>0)
                                    {
                                        cout<<guarda.top()<<" ";
                                        guarda.pop();
                                    }
                                    cout<<"  Condicao"<<endl;
                            retorna=0;
                            estado=0;
                 }
                else{
                    if(estado==0){ //id
                        if(aux_palavra!="esquerda"&&aux_palavra!="direita")
                        {
                            cout<<aux_palavra<<" ID"<<endl;
                            tabela.push_back(aux_palavra);
                        }
                        else
                            cout<<aux_palavra<<" Sentido"<<endl;
                        estado=0;
                        retorna=0;
                    }
                    else{ //n�o faz combina��o

                        while(guarda.size()>0){

                            inverte.push(guarda.top());
                            guarda.pop();
                        }
                        while(inverte.size()>0){ //imprimir o primeiro da sequencia que n�o deu certo como id/ exceto esquerda e direita
                                    if(inverte.size()>1){
                                        guarda.push(inverte.front());
                                        inverte.pop();
                                    }
                                    else
                                    {
                                       if(inverte.front()!="esquerda"&&inverte.front()!="direita")
                                        {
                                            cout<<inverte.front()<<" ID"<<endl;
                                            tabela.push_back(inverte.front());
                                            inverte.pop();
                                            estado--;  //retorna 1 estado
                                            retorna=1;

                                        }
                                        else{
                                            cout<<inverte.front()<<" Sentido"<<endl;
                                            inverte.pop();
                                            estado--;  //retorna 1 estado
                                            retorna=1;

                                        }
                                         while(guarda.size()>0){
                                            inverte.push(guarda.top());
                                            guarda.pop();
                                         }
                                         while(inverte.size()>0){
                                            guarda.push(inverte.front());
                                            inverte.pop();
                                         }
                                    }
                                  }
                        }
                    }
              }

                aux_palavra ="";
                first=' ';
                bool error = 0;
            }
         }
      }
          myfile.get(c);
    }

    myfile.close();
    return 0;
}

//converter tudo para minusculo!!
