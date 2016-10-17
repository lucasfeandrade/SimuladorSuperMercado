// <Copyright Owner> Lucas Fernandes Andade
// <Copyright Owner> Lucas Castelan Prado

#ifndef CLIENTE_H
#define CLIENTE_H

class cliente {
private:
  //! tChegadaSuper_;
  /*!
      Atributo do tipo unsigned int, tempo de chegada no supermercado.
  */
  unsigned int tChegadaSuper_;
  //! tSaidaFila_
  /*!
      Atributo do tipo unsigned int, tempo de saida do caixa.
  */
  unsigned int tSaidaFila_;
  //! qtdItens_
  /*!
      Atributo do tipo unsigned int, quantidade de itens que o cliente compra.
  */
  unsigned int qtdItens_;
  //! pagamentoDinheiro_
  /*!
      Atributo do tipo bool, indica se cliente paga em cartao ou dinheiro.
  */
  bool pagamentoDinheiro_;
  //! gastosTotais_
  /*!
      Atributo do tipo unsigned int, gastos totais do cliente no supermercado.
  */
  unsigned int gastosTotais_;
  //! tipoDeCliente_
  /*!
      Atributo do tipo bool, indica se cliente procura caixa com menor fila
      ou com fila com menos itens. True eh menor fila.
  */
  bool tipoDeCliente_;
  //! desistencia_
  /*!
      Atributo do tipo bool, indica se o cliente desistiu e saiu do supermercado
      ou nao. True eh sim.
  */
  bool desistencia_;
  //! pagarEmDinheiro()
  /*!
      Metodo que decide se clientes pegarao em cartao ou dinheiro. 20 por cento
      sera dinheiro.
      \return bool
  */
  bool pagarEmDinheiro();
  //! gerarGastosTotais()
  /*!
      Metodo que gera gastos totais do cliente.
      \return unsigned int
  */
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
