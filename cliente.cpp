// <Copyright Owner> Lucas Fernandes Andade
// <Copyright Owner> Lucas Castelan Prado

#include <stdio.h>    // printf, NULL
#include <stdlib.h>   // srand, rand
#include <time.h>     // time
#include "cliente.h"

cliente::cliente()
{
  qtdItens_ = gerarQtdItens();
  pagamentoDinheiro_ = pagarEmDinheiro();  // Metodo com 20% de chance dinheiro e 80% cartao
  gastosTotais_ = gerarGastosTotais();
  tipoDeCliente_ = escolherFila();
  desistencia_ = false;
}

unsigned int cliente::gerarGastosTotais()
{
  srand((unsigned)time(NULL));  //seed rand()
  gastosTotais_ = 0;
  int precoProduto;
  for (int i = 0; i < qtdItens_; i++)
  {
    precoProduto = rand() % 90 + 1;  // rand() % 90 gera numero de 0 a 89 (90 numeros)
    gastosTotais_ = gastosTotais_ + precoProduto;
  }
  return gastosTotais_;
}

unsigned int cliente::gerarQtdItens()
{
  srand((unsigned)time(NULL));  //seed rand()
  auto itens = rand() % 99 + 2;  // rand() % 99 gera numero de 0 a 98 (99 numeros)
  return itens;
}

unsigned int cliente::gastosTotais()     //MUDADO
{
    return gastosTotais_;
}

void cliente::desistencia(bool desistencia)
{
  desistencia_ = desistencia;
}

bool cliente::verificarDesistencia()
{
  return desistencia_; // tem que mudar se nao houver fila com menos de 10 pessoas
}

unsigned int cliente::faturamentoPerdido()
{
  if (desistencia_)
    return 3*gastosTotais_;
  return 0;
}

bool cliente::escolherFila()
{
  srand((unsigned)time(NULL));
  return rand() % 2;
}

bool cliente::pagarEmDinheiro()
{
  srand((unsigned)time(NULL));
  auto chance = rand() % 100;
  if (chance >= 20)
    return false;
  return true;
}

unsigned int cliente::qtdItens()
{
  return qtdItens_;
}

bool cliente::pagamentoDinheiro()
{
  return pagamentoDinheiro_;
}

bool cliente::tipoDeCliente()
{
  return tipoDeCliente_;
}

unsigned int cliente::tChegadaSuper()
{
  return tChegadaSuper_;
}

void cliente::tChegadaSuper(int tChegadaSuper)
{
    tChegadaSuper_ = tChegadaSuper;
}

unsigned int cliente::tSaidaFila()
{
  return cliente::tSaidaFila_;
}

void cliente::tSaidaFila(unsigned int tSaidaFila)
{
  tSaidaFila_ = tSaidaFila;
}
