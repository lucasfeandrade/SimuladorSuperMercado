#include cliente.h
#include <stdio.h>    // printf, NULL
#include <stdlib.h>   // srand, rand
#include <time.h>     // time

supermercado() {
  structures::CircularList<Cliente> ListaCaixas;
  string nomeSupermercado;
  numClientesDesistiram;
  faturamentoTotal;
  faturamentoPerdido;
  numCaixas;
  relogioInterno = 0;
  numCaixasExtras;
}

void calculareEstatistica() {

}

void chamarCaixa() {

}

void calcularFaturamento() {

}

void calcularFaturamentoPerdido() {

}

bool filasLotadas () {

} // se passar de X ele retorna true

//! Remove cliente de um caixa
/*!
    Percorre todos os caixas e remove aqueles clientes cujo tempo seja igual ao
    tempo do relógio interno. De qualquer forma o relógio interno do supermercado
    é somado em 1.
    \return void
*/
void tirarCliente () {
    for (auto i = 0; i < ListaCaixas.size() - 1 ; i++ )
    {
        CaixaSuperMercado Caixa =  ListaCaixas.at(i);
        if ( Caixa.primeiroDaFila().tSaidaFila() == relogioInterno )
            Cliente clienteRemovido = Caixa.removerPrimeiroCliente();   //Retira Cliente
    }
    relogioInterno++; //Toda vez que o método é executado o tempo aumenta em 1;
}  // se tSaida == tAtual, atende cliente e tira da fila DEQUEUE?

void gerarCliente () {
  cliente cliente = new cliente->cliente();
  if (relogioInterno == cliente->horaChegadaFila()) {
    if (!full && cliente->escolherFila()) {
      //procura caixa com menos gente
    } else if (!full && !cliente->escolherFila()) {
      //procura caixa com menos itens
    } else {

    }
  }
}  // se tAtual = tChegada, gera cliente com compras e lugar na fila. Calcula o proximo tempo de chegada CHECAR CONDICAO DE FULL
