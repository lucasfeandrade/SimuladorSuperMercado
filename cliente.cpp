// <Copyright Owner> Lucas Fernandes Andade
// <Copyright Owner> Lucas Castelan Prado

#include <stdio.h>    // printf, NULL
#include <stdlib.h>   // srand, rand
#include <time.h>     // time
#include "cliente.h"
cliente()
{
  tChegadaSuper_  =  supermercado.relogioInterno();
  qtdItens_ = gerarQtdItens();
  pagamentoDinheiro_ = pagarEmDinheiro();  // Metodo com 20% de chance dinheiro e 80% cartao
  gastosTotais_ = gerarGastosTotais();
  tipoDeCliente_ = escolherFila();
  desistencia_ = false;
}

unsigned int gerarGastosTotais()
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

unsigned int gerarQtdItens()
{
  srand((unsigned)time(NULL));  //seed rand()
  auto itens = rand() % 99 + 2;  // rand() % 99 gera numero de 0 a 98 (99 numeros)
  return itens;
}

unsigned int gastosTotais()     //MUDADO
{
    return gastosTotais_;
}

void desistencia(bool desistencia)
{
  desistencia_ = desistencia;
}

bool verificarDesistencia()
{
  return desistencia_; // tem que mudar se nao houver fila com menos de 10 pessoas
}

unsigned int faturamentoPerdido()
{
  if (desistencia_)
    return 3*gastosTotais_;
  return 0;
}

bool escolherFila()
{
  srand((unsigned)time(NULL));
  return rand() % 2;
}

bool pagarEmDinheiro()
{
  srand((unsigned)time(NULL));
  auto chance = rand() % 100;
  if (chance >= 20)
    return false;
  return true;
}

unsigned int qtdItens()
{
  return qtdItens_;
}

bool pagamentoDinheiro()
{
  return pagamentoDinheiro_;
}

bool tipoDeCliente()
{
  return tipoDeCliente_;
}

unsigned int tChegadaSuper()
{
  return tChegadaSuper_;
}

unsigned int tSaidaFila()
{
  return tSaidaFila_;
}

void tSaidaFila(unsigned int tSaidaFila)
{
  tSaidaFila_ = tSaidaFila;
}
