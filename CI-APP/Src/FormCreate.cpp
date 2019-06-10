// Declaração das Bibliotecas internas do C++ 
#include <iostream>
#include <string>
#include <ctime> // Biblioteca interna do C++ para usar padrões de data hora do sistema
#include <cctype> // Biblioteca interna do C++ para usar "isdigit"

// Declaração das Bibliotecas internas do Projeto (declação das Classes)
#include "../Include/Form.hpp"

// Uso refinado do Escopo STD
using std::cout;
using std::cin;
using std::getline;
using std::endl;
using std::string;

// Conversão de tipo data para string
const char *Form::getSystemDate() {
  // "t_Date" será nossa váriavel para passagem de referênica dos valores de data
  time_t t_Date;

  // "tm" é um estrutura interna do C++ que indica atributos do tipo TIME
  struct tm *timeInfo;

  // "buffer" será nosso retorno com data formatada
  char buffer[DATE_SIZE];

  // Usando a função "time" (Interna do C++) passando como referência "t_Date"
  time(&t_Date);

  // Usando a função "localtime", e passando nossa "t_Date", para "timeInfo",
  // que é onde temos a entrada da data sem formatação 
  timeInfo = localtime(&t_Date);

  // "strftime", converte nosso tipo de data para uma string, que nosso caso é o "buffer"
  strftime(buffer, DATE_SIZE, "%d/%m%/Y", timeInfo);

  // retornamos nossa string, para que seja usada no restante do programa
  return buffer;
}

// Validação de entrada de dados no formulário
string Form::validateInput(string inputData, int optCheckIn) {
  // Aqui, primeiramente verifica qual campo está entrando e depois, valida o mesmo
  if (optCheckIn == 10) {
    inputData.length() == SENDER_RECIPIENT_SUBJECT_SIZE;

    if ((inputData.empty()) || (isdigit(inputData[0])) || (isdigit(inputData[1])) || (isdigit(inputData[2])) || (isdigit(inputData[3])) || (!inputData.length())) {
      cout << endl << inputData << " não é um [remetente] válido! " << "Digite novamente: ";
      getline(cin, inputData);
      cin.ignore();
      validateInput(inputData, 10);
    }
    else
      return inputData;
  } 
  
  if (optCheckIn == 20) {
    inputData.length() == SENDER_RECIPIENT_SUBJECT_SIZE;
    
    if ((inputData.empty()) || (isdigit(inputData[0])) || (isdigit(inputData[1])) || (isdigit(inputData[2])) || (isdigit(inputData[3])) || (!inputData.length())) {
      cout << endl << inputData << " não é um [destinatário] válido! " << "Digite novamente: ";
      getline(cin, inputData);
      cin.ignore();
      validateInput(inputData, 20);
    }
    else
      return inputData;
  } 

  if (optCheckIn == 30) {
    inputData.length() == SENDER_RECIPIENT_SUBJECT_SIZE;
    
    if ((inputData.empty()) || (isdigit(inputData[0])) || (isdigit(inputData[1])) || (isdigit(inputData[2])) || (isdigit(inputData[3])) || (!inputData.length())) {
      cout << endl << inputData << " não é um [assunto] válido! " << "Digite novamente: ";
      getline(cin, inputData);
      cin.ignore();
      validateInput(inputData, 30);
    }
    else
      return inputData;
  } 

  if (optCheckIn == 40) {
    inputData.length() == MENSSAGE_SIZE;
    
    if ((inputData.empty()) || (isdigit(inputData[0])) || (isdigit(inputData[1])) || (isdigit(inputData[2])) || (isdigit(inputData[3])) || (!inputData.length())) {
      cout << endl << inputData << " não é uma [mensagem] válida! " << "Digite novamente: ";
      getline(cin, inputData);
      cin.ignore();
      validateInput(inputData, 40);
    }
    else
      return inputData;
  } 
}

void Form::formCreate() {
  // Váriaveis para inserção no Formulário
  int idCI;
  string senderCI; // optCheckIn == 10;
  string recipientCI; // optCheckIn == 20;
  string subjectCI; // optCheckIn == 30;
  string dateCI; 
  string messageCI; // optCheckIn == 40;

  // Entrada de dados
  cout << endl << "\tMódulo de Cadastro - Inserir uma CI" << endl;
  cout << endl << "\t\tObs.: Nenhum dado pode ser omitido!" << endl;
  cout << endl << "De (nome do remetente): ";
  getline(cin, senderCI);
  
  // Verificar se os dados de não estão vazios
  senderCI = validateInput(senderCI);

  // Inicialização das Váriaveis dataCI
  dateCI = getSystemDate();

  // cin.ignore();

  // Criar rotina de utilizar do crudCreate
}

void Form::crudCreate(int idCI, string senderCI, string recipientCI, string subjectCI, string dateCI, string messageCI) {
  // Verificação da Posição a ser inserido, e inserção
  // Insere no início, quando a estrutura de dados está vazia
  if (Data.empty())
    Data.insert(Data.begin(), FormData(idCI, senderCI, recipientCI, subjectCI, dateCI, messageCI));

  // Insere no final, quando já existir algum registro na estrtutura de dados
  else
    Data.push_back(FormData(idCI, senderCI, recipientCI, subjectCI, dateCI, messageCI));

}
