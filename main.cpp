// <Copyright Owner> Lucas Fernandes Andade
// <Copyright Owner> Lucas Castelan Prado

#include <iostream>
#include <cstdint>
#include <stdexcept>
#include <stdlib.h>

#include "supermercado.h"


int main(int argc, const char * argv[]) {

    auto salario = 1000u;
    supermercado* Super = new supermercado("Super da Hora", 15,28800);   //simulando por 8 horas

    //Gerando todos os caixas: (Mudar os 5 primeiros para 0 default)
    Super->gerarCaixa( salario, 1, "Roberto Justus", false);
    Super->gerarCaixa( salario, 2, "Claudia Raia ", false);
    Super->gerarCaixa( salario, 1, "Roberta Miranda", false);
    Super->gerarCaixa( salario, 2, "Paula Fernandes", false);
    Super->gerarCaixa( salario, 1, "Bob Esponja", false);
    Super->gerarCaixa( salario, 2, "Faustão", false);
    Super->gerarCaixa( salario, 2, "Péricles", false);
    Super->gerarCaixa( salario, 3, "Pelé", false);
    Super->gerarCaixa( salario, 3, "Edson Arantes do Nascimento", false);

    while (Super->relogioInterno() < Super->tempoDeSimulacao())
    {
        Super->gerarCliente();
        Super->TirarCliente();
        Super->chamarCaixaExtra(10u,salario,2u,"CaixaExtra");

    }

    Super->calcularEstatistica();
}
