#ifndef CLIENTE_H
#define CLIENTE_H
using namespace std;

class cliente {
private:
  unsigned int horaChegadaSuper;
  unsigned int horaSaidaFila;
  unsigned int qtdItens;
  bool pagamentoDinheiro;
  unsigned int gastosTotais;
  bool tipoDeCliente; //TRUE ESCOLHE A MENOR E FALSE ESCOLHE A COM MENOS QTD
  bool desistencia;
protected:
  //getters and setters if needed
public:
  cliente();
  unsigned int gerarGastosTotais(int);
  unsigned int gerarQtdItens();
  bool verificarDesistencia();
  unsigned int faturamentoPerdido();
  bool escolherFila();
  bool pagarEmDinheiro();
  unsigned int qtdItens();
  unsigned int pagarEmDinheiro();
  bool tipoDeCliente();
};
 
#endif
