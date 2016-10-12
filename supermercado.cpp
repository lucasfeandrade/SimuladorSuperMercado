#include cliente.h
#include <stdio.h>    // printf, NULL
#include <stdlib.h>   // srand, rand
#include <time.h>     // time

supermercado(int qtdCaixas, String nome) {
  //structures::CircularList<Cliente> ListaCaixas;
  String nomeSupermercado = nome;
  numCaixas = qtdCaixas;
  relogioInterno = 0;
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

void percorrerCaixas () {

}  // cada vez q o supermercado percorre a lista de caixas incrementa 1s no relogio

Cliente tirarCliente () {
    for (auto i = 0; i < ListaCaixas.size() - 1 ; i++ )
    {
        CaixaSuperMercado Caixa =  ListaCaixas.at(i);
        if ( Caixa.primeiroDaFila().horaSaidaFila() == relogioInterno )
            Cliente clienteRemovido = Caixa.removerPrimeiroCliente();   //Retira Cliente
    }
    return clienteRemovido;
}  // se tSaida == tAtual, atende cliente e tira da fila DEQUEUE?

void gerarCliente () {
  if (relogioInterno == horaChegadaFila) {
    cliente cliente = new cliente->cliente();
    if (!full && cliente->escolherFila()) {
      //procura caixa com menos gente
    } else if (!full && !cliente->escolherFila()) {
      //procura caixa com menos itens
    } else {

    }
  }
}  // se tAtual = tChegada, gera cliente com compras e lugar na fila. Calcula o proximo tempo de chegada CHECAR CONDICAO DE FULL
