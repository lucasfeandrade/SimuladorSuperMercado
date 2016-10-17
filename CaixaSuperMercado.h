#ifndef CAIXA_SUPER_MERCADO_H_
#define CAIXA_SUPER_MERCADO_H_

#include <string.h>
#include "array_queue.h"
#include "./cliente.h"

class CaixaSuperMercado {
private:
    structures::ArrayQueue<cliente> filaClientes_{10u};
    cliente primeiroDaFila;    //para informar para o supermercado o primeiro da fila
    unsigned int numClientesFila_;
    unsigned int numClientesAtendidos_;
    unsigned int tempoMedioDeEspera_;
    unsigned int faturamentoTotalCaixa_;
    unsigned int faturamentoMedio_;
    unsigned int eficiencia_;
    unsigned int salario_;
    std::string id_;
    bool caixaExtra;


public:
    CaixaSuperMercado();
    void adicionarFaturamento(unsigned int); //Mudado
    void adicionarClienteFila();
    unsigned int calculaSalario();
    unsigned int calculaTempoSaida();
    cliente removerPrimeiroCliente();
    cliente primeiroDaFila();
    structures::ArrayQueue<cliente> filaClientes();
    bool caixaLotado();
    unsigned int faturamentoTotalCaixa();
    std::string id();
};

#endif
