#ifndef CLIENTE_H
#define CLIENTE_H

class cliente {
private:
  unsigned int tChegadaSuper_;
  unsigned int tSaidaFila_;
  unsigned int qtdItens_;
  bool pagamentoDinheiro_;
  unsigned int gastosTotais_;
  bool tipoDeCliente_; //TRUE ESCOLHE A MENOR E FALSE ESCOLHE A COM MENOS QTD
  bool desistencia_;
  bool pagarEmDinheiro();
  unsigned int gerarGastosTotais();


public:
  cliente();
  unsigned int gerarQtdItens();
  void desistencia(bool); //mudar para protected
  bool verificarDesistencia();
  unsigned int faturamentoPerdido();
  unsigned int qtdItens();
  bool escolherFila();
  bool pagamentoDinheiro();
  bool tipoDeCliente();
  unsigned int tChegadaSuper();
  unsigned int tSaidaFila();
  void tSaidaFila(unsigned int); //mudar para protected
  unsigned int gastosTotais();  //MUDADO
};

#endif
