// Cabeçalho obrigatório na criação / declaração do arquivo das Classes
#ifndef FORM_HPP
#define FORM_HPP

// Declaração das Bibliotecas internas do C++ 
#include <iostream>
#include <string>
#include <vector>
#include <ctime>

// Tamanho padrão para armazenar a string que obtivermos do horário.
// #define DATE_SIZE 100
// Padrões usados para a entradas do Menu, e tudo relacionado.
#define CREATE "Criar um novo registro de CI"
#define SELECT "Listar/Localizar um registro de CI"
#define UPDATE "Atualizar um registro de CI"
#define DELETE "Apagar um registro de CI"

// Uso refinado do Escopo STD
using std::string;
using std::vector;

// Declaração da Classe Form (Formulário de manipulação de dados)
class Form {
  private:
    // Declaração da Classe FormData que será nossa base de dados 
    class FormData {
      private:
        int idCI;
        string senderCI;
        string recipientCI;
        string subjectCI;
        const char *dateCI;
        string messageCI;
      
      public:
        // Construtor/Destrutor da Classe FormData
        FormData(int idCI, string senderCI, string recipientCI, string subjectCI, const char &dateCI, string messageCI);
        ~FormData();
        // Métodos da Classe FormData
        void setIdCI();
        void setSenderCI(string senderCI);
        void setRecipientCI(string recipientCI);
        void setSubjectCI(string subjectCI);
        void setDateCI();
        void setMessageCI(string menssageCI);
        int getIdCI();
        string getSenderCI();
        string getRecipientCI();
        string getSubjectCI();
        const char *getDateCI();
        string getMessageCI();
    };
    // Tornando nossa base de dados uma estrutrua de dados do tipo Vector 
    vector<FormData> Data;

  public:
    // Construtor/Destrutor da Classe FormData
    Form();
    ~Form();
    // Métodos da Classe Form (Basicamente farão as operações do CRUD)
    void formCreate(string senderCI, string recipientCI, string subjectCI, string messageCI);
    void formSelect(int idCI);
    void formUpdate(int idCI);
    void formDelete(int idCI);
};
  
#endif
