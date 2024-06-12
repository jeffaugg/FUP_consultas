#ifndef SISTEMA_H
#define SISTEMA_H

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#define MAXC 10
#define MAXU 50

struct usuario
{
    char nome[20];
    char sobrenome[20];
    int idade;
    char login[20];
    char senha[20];
};

void alocarClientes();
void cadastrarUsuario();
void login();
int dataValida(int dia, int mes, int ano);
void marcarConsulta();
void cancelarConsulta();

#endif