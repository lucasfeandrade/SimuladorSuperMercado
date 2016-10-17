#ifndef SUPERMERCADO_H
#define SUPERMERCADO_H

#include <string>
#include "circular_list.h"
#include "cliente.h"
#include "CaixaSuperMercado.h"

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


public:
  supermercado(std::string, unsigned int, unsigned int);
  unsigned int relogioInterno();
  void calcularEstatistica();
  void chamarCaixaExtra();
  unsigned int calcularFaturamento();
  void calcularFaturamentoPerdido();
  bool filasLotadas();  // se passar de X ele retorna true
  void percorrerCaixas();  // cada vez q o supermercado percorre a lista de caixas incrementa 1s no relogio
  void tirarCliente();  // se tSaida == tAtual, atende cliente e tira da fila DEQUEUE?
  void gerarCliente();  // se tAtual = tChegada, gera cliente com compras e lugar na fila. Calcula o proximo tempo de chegada ENQUEUE?
  void clientesAtendidos();
  void gerarCaixa(unsigned int, unsigned int, std::string, bool);
};


#endif
