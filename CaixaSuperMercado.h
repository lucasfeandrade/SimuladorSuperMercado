#ifndef CAIXA_SUPER_MERCADO_H_
#define CAIXA_SUPER_MERCADO_H_

class CaixaSuperMercado {
private:
    structures::ArrayQueue<Cliente> filaClientes_{10u};
    Cliente primeiroDaFila;    //para informar para o supermercado o primeiro da fila
    unsigned int numClientesFila_;
    unsigned int numClientesAtendidos_;
    unsigned int tempoMedioDeEspera_;
    unsigned int faturamentoTotal_;
    unsigned int faturamentoMedio_;
    unsigned int salarioHora_;
    unsigned int eficiencia_;
    unsigned int salario_;
    unsigned int id_;
    bool caixaExtra;

public:
    unsigned int calculaSalario();
    unsigned int calculaTempoSaida();
    Cliente removerPrimeiroCliente();
    Cliente primeiraDaFila();

}

#endif
