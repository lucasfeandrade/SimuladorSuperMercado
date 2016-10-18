// <Copyright Owner> Lucas Fernandes Andade
// <Copyright Owner> Lucas Castelan Prado

#ifndef CAIXA_SUPER_MERCADO_H_
#define CAIXA_SUPER_MERCADO_H_

#include <string>
#include "array_queue.h"
#include "cliente.h"
//! Classe CaixaSuperMercado
/*!
    Classe que implementa o comportamento de um caixa de super mercado.
*/
class CaixaSuperMercado {
private:
    //! structures::ArrayQueue<Cliente> filaClientes_{10u}
    /*!
        Atributo do tipo ArrayQueue<Cliente> Fila de clientes.
    */
    structures::ArrayQueue<cliente> filaClientes_{10u};
    //! primeiroDaFila
    /*!
        Atributo do tipo Cliente, primeiro cliente da fila.
    */
    cliente primeiroDaFila_;
    //! numClientesFila_
    /*!
        Atributo do tipo unsigned int, indica tamanho da fila.
    */
    unsigned int numClientesFila_;
    //! numClientesAtendidos_
    /*!
        Atributo do tipo unsigned int, indica num de clientes atendidos do caixa.
    */
    unsigned int numClientesAtendidos_;
    //! tempoMedioDeEspera_
    /*!
        Atributo do tipo unsigned int, indica tempo medio de espera na fila
        do caixa.
    */
    unsigned int tempoMedioDeEspera_;
    //! faturamentoTotalCaixa_
    /*!
        Atributo do tipo unsigned int, indica faturamento total do caixa.
    */
    unsigned int faturamentoTotalCaixa_;
    //! faturamentoMedio_
    /*!
        Atributo do tipo unsigned int, indica faturamento medio do caixa.
    */
    unsigned int faturamentoMedio_;
    //! eficiencia_
    /*!
        Atributo do tipo unsigned int, indica eficiencia do caixa. 1 é ruim,
        2 é medio e 3 é bom.
    */
    unsigned int eficiencia_;
    //! salario_
    /*!
        Atributo do tipo unsigned int, salario do caixa.
    */
    unsigned int salario_;
    //! id_
    /*!
        Atributo do tipo std::string, identificador do caixa (nome).
    */
    std::string id_;
    //! caixaExtra
    /*!
        Atributo do tipo bool, identifica se o caixa eh extra ou regular.
    */
    bool caixaExtra_;


public:
  //!   CaixaSuperMercado(unsigned int, unsigned int,
  //              unsigned int, unsigned int,
  //              unsigned int, unsigned int,
  //              unsigned int, String, bool)
  /*!
      Enfileira cliente.
  */
  CaixaSuperMercado(unsigned int, unsigned int,
                    std::string, bool);
    //! adicionarFaturamento(unsigned int)
    /*!
        Adiciona faturamento ao caixa (entrada do metodo).
    */
    void adicionarFaturamento(unsigned int);
    //! adicionarClienteFila()
    /*!
        Enfileira cliente.
    */
    void adicionarClienteFila(cliente);
    //! calculaSalario()
    /*!
        Calcula salario do caixa e o retorna.
        \return unsigned int
    */
    unsigned int calculaSalario();
    //! calculaTempoSaida()
    /*!
        Calcula tempo de saida da fila e o retorna.
        \return unsigned int
    */
    unsigned int calculaTempoSaida();
    //! removerPrimeiroCliente()
    /*!
        Remove primeiro cliente da fila e o retorna.
        \return cliente
    */
    cliente removerPrimeiroCliente();
    //! primeiroDaFila()
    /*!
        Retorna primeiro cliente da fila.
        \return cliente
    */
    cliente primeiroDaFila();
    //! filaClientes()
    /*!
        Gera fila de clientes.
        \return structures::ArrayQueue<cliente>
    */
    structures::ArrayQueue<cliente> filaClientes();
    //! caixaLotado()
    /*!
        Verifica se caixa esta lotado.
        \return bool
    */
    bool caixaLotado();
    //! faturamentoTotalCaixa()
    /*!
        Getter do faturamento total do caixa.
        \return unsigned int
    */
    unsigned int faturamentoTotalCaixa();
    //! id()
    /*!
        Getter do identificador do caixa.
        \return std::string
    */
    std::string id();
};

#endif
