#include <iostream>
#include <locale.h>
using namespace std;

class Data {
  private:
    int dia;
    int mes;
    int ano;

  public:
    Data(int dia, int mes, int ano) {
      this->dia = dia;
      this->mes = mes;
      this->ano = ano;
    }

    Data() {
      this->dia = 0;
      this->mes = 0;
      this->ano = 0;
    }

    void setDia(int dia) {
      this->dia = dia;
    }

    void setMes(int mes) {
      this->mes = mes;
    }

    void setAno(int ano) {
      this->ano = ano;
    }

    int getDia() {
      return this->dia;
    }

    int getMes() {
      return this->mes;
    }

    int getAno() {
      return this->ano;
    }

    string getData() {
      string sDia = to_string(this->dia);
      string sMes = to_string(this->mes);
      string sAno = to_string(this->ano);

      return sDia.insert(0, 2-sDia.size(),'0') + "/" + 
        sMes.insert(0, 2-sMes.size(),'0') + "/" + 
        sAno;
    }

    Data* dia_seguinte() { 
      Data *d1 = new Data(this->dia, this->mes, this->ano);
      int diasNoMes[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
      if (d1->ano % 4 == 0) {
        diasNoMes[1] = 29;
      }
      d1->dia++;
      if (d1->dia > diasNoMes[d1->mes-1]) {
        d1->dia = 1;
        d1->mes++;
        if(d1->mes > 12) {
          d1->mes = 1;
          d1->ano++;
        }
      }
      return d1;
    }
};

class Contato {
  private:
    string email;
    string nome;
    string telefone;
    Data dtnasc;

  public:
    Contato(string email, string nome, string telefone, Data dtnasc) {
      this->email = email;
      this->nome = nome;
      this->telefone = telefone;
      this->dtnasc = dtnasc;
    }

    Contato() {}

    void setEmail(string email) {
      this->email = email;
    }

    void setNome(string nome) {
      this->nome = nome;
    }

    void setTelefone(string telefone) {
      this->telefone = telefone;
    }

    void setDtnasc(int dia, int mes, int ano) {
      this->dtnasc.setDia(dia);
      this->dtnasc.setMes(mes);
      this->dtnasc.setAno(ano);
    }

    string getEmail() {
      return this->email;
    }

    string getNome() {
      return this->nome;
    }

    string getTelefone() {
      return this->telefone;
    }

    Data getDtnasc() {
      return this->dtnasc;
    }

    int idade(Data d) {
      Data dataAtual(1, 1, 2024);
      int idade = dataAtual.getAno() - d.getAno();
      return idade;
    }
};

int main(int argc, char** argv)
{
  setlocale(LC_ALL, "");

  Contato contatos[5];

  string email, nome, telefone;
  int dia, mes, ano;
  
  for (int i = 0; i < 5; i++) {
    cout << "Cadastre o contato " << i+1 << ":" << endl;
    
    cout << "Nome: ";
    cin >> nome;
    contatos[i].setNome(nome);
    
    cout << "Email: ";
    cin >> email;
    contatos[i].setEmail(email);
    
    cout << "Telefone: ";
    cin >> telefone;
    contatos[i].setTelefone(telefone);
    
    cout << "Data de nascimento (dd): ";
    cin >> dia;
    
    cout << "Data de nascimento (mm): ";
    cin >> mes;
    
    cout << "Data de nascimento (aaaa): ";
    cin >> ano;
    
    contatos[i].setDtnasc(dia, mes, ano);

    cout << endl;
  }

  cout << "Contatos cadastrados: \n" << endl;
  
  for (int i = 0; i < 5; i++) {
    cout << "Contato " << i+1 << ":" << endl;
    cout << "Nome: " << contatos[i].getNome() << endl;
    cout << "Email: " << contatos[i].getEmail() << endl;
    cout << "Telefone: " << contatos[i].getTelefone() << endl;
    cout << "Idade: " << contatos[i].idade(contatos[i].getDtnasc()) << endl;
    cout << endl;
  }

  return 0;
}
