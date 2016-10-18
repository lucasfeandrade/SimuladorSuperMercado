// <Copyright Owner> Lucas Fernandes Andade
// <Copyright Owner> Lucas Castelan Prado

#include "CaixaSuperMercado.h"

<<<<<<< HEAD
CaixaSuperMercado::CaixaSuperMercado( unsigned int salario, unsigned int eficiencia, std::string id, bool caixaExtra)
=======
CaixaSuperMercado(unsigned int salario, unsigned int eficiencia, std::string id, bool caixaExtra)
>>>>>>> 6567954c2e90f956136cfdf92abbdca9826b6167
{               //MUDADO
    numClientesFila_ = 0u;               //nao usamos
    numClientesAtendidos_ = 0u;          //nao usamos
    tempoMedioDeEspera_ = 0u;
    faturamentoTotalCaixa_ = 0u;
    faturamentoMedio_ = 0u;
    if (eficiencia>= 1 && eficiencia <=3)
        eficiencia_ = eficiencia;
    else
        throw std::out_of_range("Eficiência deve estar entre 1 e 3");
    id_ = id;
    caixaExtra_ = caixaExtra;
    if (caixaExtra)
        salario_ = 2*salario;
    else
        salario_ = salario;
}

bool CaixaSuperMercado::caixaLotado()
{
    return filaClientes_.full();
}

void CaixaSuperMercado::adicionarFaturamento(unsigned int faturamento)
{
    faturamentoTotalCaixa_ += faturamento;
}

cliente CaixaSuperMercado::removerPrimeiroCliente()
{
    return filaClientes_.dequeue();
}

void CaixaSuperMercado::adicionarClienteFila()
{
    filaClientes_.enqueue();
}

cliente CaixaSuperMercado::primeiroDaFila()
{
    return filaClientes_.front();
}

unsigned int CaixaSuperMercado::faturamentoTotalCaixa()
{
    return faturamentoTotalCaixa_;
}

unsigned int CaixaSuperMercado::calculaTempoSaida()
{
    cliente* cliente;
    auto tempoSaida = 0u;
    if (eficiencia_ == 1)
    {
        for (auto i = 0; i < filaClientes_->size(); i++)
        {
            cliente = filaClientes_->contents(i);
            if (cliente->pagamentoDinheiro())
                tempoSaida += eficiencia_*cliente->qtdItens();
            else
                tempoSaida += eficiencia_*cliente->qtdItens() + 10;
        }
    }
    if (eficiencia_ == 2)
    {
        for (auto i = 0; i < filaClientes_->size(); i++)
        {
            cliente = filaClientes_->contents(i);
            if (cliente->pagamentoDinheiro())
                tempoSaida += eficiencia_*cliente->qtdItens();
            else
                tempoSaida += eficiencia_*cliente->qtdItens() + 25;
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

structures::ArrayQueue<cliente> CaixaSuperMercado::filaClientes()
{
  return filaClientes_;
}

std::string CaixaSuperMercado::id_()
{
  return id_;
}
