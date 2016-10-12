// <Copyright Owner> Lucas Fernandes Andade
// <Copyright Owner>


#include "CaixaSuperMercado.h"

#include "std"
    CaixaSuperMercado(  unsigned int numClientesFila, unsigned int numClientesAtendidos,
                        unsigned int tempoMedioDeEspera, unsigned int faturamentoTotal,
                        unsigned int faturamentoMedio, unsigned int salario,
                        unsigned int eficiencia, unsigned int id, bool caixaExtra)
        numClientesFila_ = numClientesFila;
        numClientesAtendidos_ = numClientesAtendidos;
        tempoMedioDeEspera_ = tempoMedioDeEspera;
        faturamentoTotal_ = faturamentoTotal;
        faturamentoMedio_ = faturamentoMedio;
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



    unsigned int calculaTempoSaida() {
        Cliente cliente;
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
        if ( eficiencia_ == 2 )
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
