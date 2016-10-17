
#include <stdio.h>    // printf, NULL
#include <iostream>
#include <stdlib.h>   // srand, rand
#include <time.h>     // time

#include "supermercado.h"

supermercado(std::string nomeSupermercado, unsigned int tempoMedioProximoCliente,
             unsigned int tempoDeSimulacao)
{
  nomeSupermercado_ = nomeSupermercado;
  numCaixas_ = 0;
  relogioInterno_ = 0;
  faturamentoPerdido_ = 0;
  faturamentoTotal_ = 0;
  clientesAtendidos_ = 0;
  tempoMedioProximoCliente_ = tempoMedioProximoCliente;
  numClientesDesistiram_ = 0;
  tempoDeSimulacao_ = tempoDeSimulacao;
  tempoTotalClientesNaFila_ = 0;
}

unsigned int clientesAtendidos()
{
  return clientesAtendidos_;
}

unsigned int relogioInterno()
{
  return relogioInterno_;
}

void tempoTotalClientesNaFila(int tempoTotalClientesNaFila)
{
  tempoTotalClientesNaFila_ += tempoTotalClientesNaFila;
}

void calcularEstatistica()          //MUDADO MUITA COISA
{
  auto faturamentoTotal = calcularFaturamento();
  std::cout << "SIMULACAO DO SUPERMERCADO " << nomeSupermercado_ << "." <<
  std::endl << std::endl;
  std::cout << "O tempo de simulacao foi: " << relogioInterno_
  << " horas." << std::endl;
  std::cout << "O faturamento total do supermercado foi: " << faturamentoTotal
  << " reais." << std::endl;
  std::cout << "O faturamento medio por caixa foi: " << faturamentoTotal/numCaixas_
  << " reais." << std::endl;
  std::cout << "O faturamento de cada caixa foi: " << std::endl;
  for (auto i = 0; i < numCaixas_; i++)
  {
    std::cout << "  Caixa " << ListaCaixas.at(i).id() << " faturou " <<
    ListaCaixas.at(i).faturamentoTotalCaixa() << " reais." << endl;
  }
  std::cout << "O lucro de cada caixa foi: " << std::endl;
  for (auto i = 0; i < numCaixas_; i++)
  {
    std::cout << "  Com o caixa " << ListaCaixas.at(i).id() << " lucra-se " <<
    ListaCaixas.at(i).faturamentoTotalCaixa() - ListaCaixas.at(i).salarioHora() <<
    " reais." << endl;
  }
  std::cout << "O numero total de clientes que desistiram foi: " <<
  numClientesDesistiram_ << " clientes." << std::endl;
  std::cout << "O faturamento total deixado de ser realizado foi: " <<
  faturamentoPerdido_ << " reais." << std::endl;
}

//! Checar se precisa chamar novo caixa
/*!
    Se o tamanho de todas as filas ultrapassar um valor llimite
    (definido pelo usuário como parâmetro de simulação), o
    supermercado chamará mais um caixa para trabalhar.
    \return void
*/
void chamarCaixaExtra(unsigned int Limite, unsigned int salarioCaixa,
                unsigned int eficiencia, unsigned int id)
{
    auto counter = 0;
    for (auto i = 0; i < ListaCaixas.size() - 1; i++)
    {
        if(Limite <= ListaCaixas.at(i).size());    //Caso algum caixa não esteja lotado retorna falso
            counter++;
    }
    if (counter == ListaCaixas.size())
    {
        CaixaSuperMercado* CaixaExtra = new CaixaSuperMercado(  0, 0, 0, 0, 0, salarioCaixa, eficiencia, id, true);
        ListaCaixas.push_back(CaixaExtra);  //adiciona caixa extra nalista
        numCaixas_++;
    }
}

//! Calcula faturamento total
/*!
    Percorre toda a lista de caixas e soma o faturamento de cada caixa no
    atributo faturamentoTotal_. Cada vez que o metodo for executado ele
    zera o valor do faturamentoTotal_ antes de somar todos os valores.
    \return void
*/
unsigned int calcularFaturamento()
{
    faturamentoTotal_ = 0u;
    for (auto i = 0; i < ListaCaixas.size() - 1; i++)
        faturamentoTotal_ += ListaCaixas.at(i).faturamentoTotalCaixa();
    return faturamentoTotal_;
}


unsigned int calcularFaturamentoPerdido()
{
  return faturamentoPerdido_;
}

bool filasLotadas()
{
    for (auto i = 0; i < ListaCaixas.size() - 1; i++)
    {
        if(!ListaCaixas.at(i).caixaLotado())    //Caso algum caixa não esteja lotado retorna falso
            return false;
    }
    return true;
} // se passar de X ele retorna true

//! Remove cliente de um caixa
/*!
    Percorre todos os caixas e remove aqueles clientes cujo tempo seja igual ao
    tempo do relógio interno. De qualquer forma o relógio interno do supermercado
    é somado em 1.
    \return void
*/
void tirarCliente()
{
  for (auto i = 0; i < ListaCaixas.size() - 1 ; i++)
  {
      CaixaSuperMercado* Caixa =  &ListaCaixas.at(i);
      if (Caixa->primeiroDaFila()->tSaidaFila() == relogioInterno_)
      {
          cliente* clienteRemovido = &Caixa.removerPrimeiroCliente(); //Retira Cliente
          Caixa->adicionarFaturamento(cliente->gastosTotais());
      }
  }
  relogioInterno_++; //Toda vez que o método é executado o tempo aumenta em 1;
}  // se tSaida == tAtual, atende cliente e tira da fila

void gerarCaixa( unsigned int salario, unsigned int eficiencia, std::string id, bool caixaExtra)         //MUDADO
{
    CaixaSuperMercado* NovoCaixa = new CaixaSuperMercado(salario, eficiencia, id, caixaExtra );
    NovoCaixa.push_back();
    numCaixas_++;
}

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
void gerarCliente()
{
  if (relogioInterno_ == clienteTempoChegadaProximoFila_)
   {
    cliente* cliente = new cliente();
    if (!filasLotadas() && cliente.escolherFila())
    {
      auto menosGente = 0u; //indice de caixa com menos pessoas
      for (auto i = 1; i < ListaCaixas.size() - 1 ; i++) //percorre lista circular
      {
        CaixaSuperMercado* Caixa1 = &ListaCaixas.at(i);
        CaixaSuperMercado* Caixa2 = &ListaCaixas.at(menosGente);
        if (Caixa1->size() < Caixa2->size())
          menosGente = i;
      }
      CaixaSuperMercado* CaixaMenor = &ListaCaixas.at(menosGente);
      CaixaMenor->filaClientes()->enqueue(cliente);
      cliente->tSaidaFila(CaixaMenor->calculaTempoSaida());
    }
    else if (!filasLotadas() && !cliente.escolherFila())
    {
      auto menosItens = 0u;
      auto itensAnterior = 0u;
      for (auto i = 0; i < ListaCaixas->size() - 1 ; i++)  // percorre lista circular
      {
        auto itens = 0u;
        CaixaSuperMercado Caixa = &ListaCaixas.at(i);
        for (auto j = 0; j < Caixa->size(); j++)
        {  // percorre caixa (fila de clientes)
          itens = Caixa->filaClientes()->contents(j)->qtdItens() + itens;
        }
        if (itens < itensAnterior)
        {
          menosItens = i;
        }
        itensAnterior = itens; // atualiza anterior
      }
      CaixaSuperMercado* CaixaMenor = &ListaCaixas.at(menosItens);
      CaixaMenor->adicionarClienteFila();
      cliente->tSaidaFila(CaixaMenor->calculaTempoSaida());
    }
    else
    {
      cliente.desistencia(true);
      faturamentoPerdido_ += cliente.faturamentePerdido();
      numClientesDesistiram_++;
    }
    clienteTempoChegadaProximoFila();
  }
}  // se tAtual = tChegada, gera cliente com compras e lugar na fila. Calcula o proximo tempo de chegada CHECAR CONDICAO DE FULL

void clienteTempoChegadaProximoFila()
{
  srand((unsigned)time(NULL));
  clienteTempoChegadaProximoFila_ = rand() % (2*tempoMedioProximoCliente_) + relogioInterno_;
}
