#ifndef SUPERMERCADO_H
#define SUPERMERCADO_H

class supermercado {
private:
  <ListaCircular>Caixa TodosCaixas
  string nomeSupermercado
  unsigned int numClientesDesistiram;
  unsigned int faturamentoTotal;
  unsigned int faturamentoPerdido;
  unsigned int numCaixas;
  unsigned int relogioInterno;
  unsigned int numCaixasExtras;
public:
  supermercado();
  void calculareEstatistica();  // QUE PORRA EH ESSA JESUS AMADO, FODEU ENFEAUNFEANfoearghrstubgosojhgvak;rflpaerncfo
  void chamarCaixa();
  void calcularFaturamento();
  void calcularFaturamentoPerdido();
  bool filasLotadas (); // se passar de X ele retorna true
  void percorrerCaixas ();  // cada vez q o supermercado percorre a lista de caixas incrementa 1s no relogio
  cliente tirarCliente ();  // se tSaida == tAtual, atende cliente e tira da fila DEQUEUE?
  cliente gerarCliente ();  // se tAtual = tChegada, gera cliente com compras e lugar na fila. Calcula o proximo tempo de chegada ENQUEUE?
};

#endif
