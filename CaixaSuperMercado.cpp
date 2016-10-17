// <Copyright Owner> Lucas Fernandes Andade
// <Copyright Owner> Lucas Castelan Prado

#include "./CaixaSuperMercado.h"
#include <stdexcept>

CaixaSuperMercado( unsigned int salario, unsigned int eficiencia, String id, bool caixaExtra)
{               //MUDADO
    numClientesFila_ = 0;               //nao usamos
    numClientesAtendidos_ = 0;          //nao usamos
    tempoMedioDeEspera_ = 0;
    faturamentoTotal_ = 0;
    faturamentoMedio_ = 0;
    if (eficiencia>= 1 && eficiencia <=3)
        eficiencia_ = eficiencia;
    else
        throw std::out_of_range("Eficiência deve estar entre 1 e 3");
    id_ = id;
    caixaExtra_ = caixaExtra;
    if (caixaExtra)
        salario_ = 2*salario;
    else
        salario_ = salario
}

bool caixaLotado()
{
    return filaClientes_.full();
}

void adicionarFaturamento(unsigned int faturamento)
{
    faturamentoTotal_ +=faturamento;
}
cliente removerPrimeiroCliente()
{
    return filaClientes_.dequeue();
}

void adicionarClienteFila()
{
    filaClientes_.enqueue();
}

cliente primeiroDaFila()
{
    return filaClientes_.front();
}

unsigned int faturamentoTotalCaixa()
{
    return faturamentoTotalCaixa_;
}

unsigned int calculaTempoSaida()
{
    cliente cliente;
    auto tempoSaida = 0u;
    if (eficiencia_ == 1)
    {
        for (auto i = 0; i < filaClientes_->size(); i++)
        {
            cliente = filaClientes_->contents(i);
            if (cliente->pagamentoDinheiro())
                tempoSaida += eficiencia*cliente->qtdItens();
            else
                tempoSaida += eficiencia*cliente->qtdItens() + 10;
        }
    }
    if (eficiencia_ == 2)
    {
        for (auto i = 0; i < filaClientes_->size(); i++)
        {
            cliente = filaClientes_->contents(i);
            if (cliente->pagamentoDinheiro())
                tempoSaida += eficiencia*cliente->qtdItens();
            else
                tempoSaida += eficiencia*cliente->qtdItens() + 25;
        }
    }
    else
    {
        for (auto i = 0; i < filaClientes_->size(); i++)
        {
            cliente = filaClientes_->contents(i);
            if (cliente->pagamentoDinheiro())
                tempoSaida += 4*cliente->qtdItens();
            else
                tempoSaida += 4*cliente->qtdItens() + 60;
        }
    }
    return tempoSaida;
}

structures::ArrayQueue<cliente> filaClientes()
{
  return filaClientes_;
}

String id_()
{
  return id_;
}
