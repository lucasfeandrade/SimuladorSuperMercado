#ifndef SUPERMERCADO_H
#define SUPERMERCADO_H

#include "CaixaSuperMercado.h"
#include "circular_list.h"

class supermercado {

private:
  structures::CircularList<cliente> TodosCaixas_;
  std::string nomeSupermercado_;
  unsigned int tempoMedioProximoCliente_;
  unsigned int numClientesDesistiram_;
  unsigned int faturamentoTotal_;
  unsigned int faturamentoPerdido_;
  unsigned int numCaixas_;
  unsigned int clientesAtendidos_;
  unsigned int relogioInterno_;
  unsigned int numCaixasExtras_;
  unsigned int tempoDeSimulacao_;
  unsigned int clienteTempoChegadaProximoFila_;
  unsigned int tempoTotalClientesNaFila_;
  void clienteTempoChegadaProximoFila();
  unsigned int clientesAtendidos();
  void tempoTotalClientesNaFila(int);


public:
  supermercado(std::string, unsigned int, unsigned int);
  unsigned int relogioInterno();
  void calcularEstatistica();
  //! Checar se precisa chamar novo caixa
  /*!
      Se o tamanho de todas as filas ultrapassar um valor llimite
      (definido pelo usuário como parâmetro de simulação), o
      supermercado chamará mais um caixa para trabalhar.
      \return void
  */
    void chamarCaixaExtra(unsigned int, unsigned int,
                          unsigned int, std::string);

  //! Calcula faturamento total
  /*!
      Percorre toda a lista de caixas e soma o faturamento de cada caixa no
      atributo faturamentoTotal_. Cada vez que o metodo for executado ele
      zera o valor do faturamentoTotal_ antes de somar todos os valores.
      \return void
  */
  unsigned int calcularFaturamento();
  void calcularFaturamentoPerdido();
  bool filasLotadas();  // se passar de X ele retorna true
  void percorrerCaixas();  // cada vez q o supermercado percorre a lista de caixas incrementa 1s no relogio
  //! Remove cliente de um caixa
  /*!
      Percorre todos os caixas e remove aqueles clientes cujo tempo seja igual ao
      tempo do relógio interno. De qualquer forma o relógio interno do supermercado
      é somado em 1.
      \return void
  */
  void tirarCliente();
  //! Gerar cliente
  /*!
      Verifica se ja eh hora do proximo cliente entrar na fila. Caso nao seja, o
      metodo nao faz nada. Caso seja, ele gera o cliente, o enfileira de acordo
      com o tipo de cliente e calcula o tempo de saida do cliente. Se nao houver
      espaco na fila, o cliente vai embora e eh calculado o prejuizo.
      Por fim, em ambos os casos, eh calculado o tempo de chegada do proximo
      cliente.
      \return void
  */
  void gerarCliente();
  unsigned int clientesAtendidos();
  void gerarCaixa(unsigned int, unsigned int, std::string, bool);
  unsigned int tempoDeSimulacao();
};


#endif
