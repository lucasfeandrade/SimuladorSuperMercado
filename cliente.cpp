#include cliente.h
#include <stdio.h>    // printf, NULL
#include <stdlib.h>   // srand, rand
#include <time.h>     // time

cliente() {
  horaChegadaSuper  // No construtor inicializa (?) Deve pegar horario do super mercado, relogio interno OLHAR ESSE
  horaSaidaFila  // Acho que nao inicializa no construtor, e deve pegar horario do relogio interno do super OLHAR ESSE
  qtdItens = gerarQtdItens();
  pagamentoDinheiro = pagarEmDinheiro();  // Metodo com 20% de chance dinheiro e 80% cartao
  gastosTotais = gerarGastosTotais();
  tipoDeCliente = escolherFila(); // Iniciliza aleatoriamente? Ta bom isso?
  desistencia = false;
}

unsigned int gerarGastosTotais(int quantidade) {
  srand((unsigned)time(NULL));  //seed rand()
  gastosTotais = 0;
  int precoProduto;
  for (int i = 0; i < qtdItens; i++) {
    precoProduto = rand() % 90 + 1;  // rand() % 90 gera numero de 0 a 89 (90 numeros)
    gastosTotais = gastosTotais + precoProduto;
  }
  return gastosTotais;
}

unsigned int gerarQtdItens() {
  srand((unsigned)time(NULL));  //seed rand()
  auto itens = rand() % 99 + 2;  // rand() % 99 gera numero de 0 a 98 (99 numeros)
  return itens;
}

bool verificarDesistencia() {
  return desistencia; // tem que mudar se nao houver fila com menos de 10 pessoas
}

unsigned int faturamentoPerdido() {
  if (desistencia)
    return 3*gastosTotais;
  return 0;
}

bool escolherFila() {
  srand((unsigned)time(NULL));
  return rand() % 2;
}

bool pagarEmDinheiro() {
  srand((unsigned)time(NULL));
  auto chance = rand() % 100;
  if (chance >= 20)
    return false;
  return true;
}

unsigned int qtdItens() {
  return qtdItens;
}

unsigned int pagamentoDinheiro() {
  return pagamentoDinheiro;
}

bool tipoDeCliente() {
  return tipoDeCliente;
}
