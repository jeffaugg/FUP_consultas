#include <stdio.h>
#include <unistd.h>
#include "sistema.h"
#include "funcoes.c"

int main()
{
    int opcao;
    do
    {
        printf("---- Sistema de Consultas ----\n\n");
        printf("1 - Login\n");
        printf("2 - Cadastrar usuario\n");
        printf("3 - Marcar consulta\n");
        printf("4 - Cancelar consulta\n");
        printf("5 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            login();
            break;
        case 2:
            cadastrarUsuario();
            break;
        case 3:
            marcarConsulta();
            break;
        case 4:
            cancelarConsulta();
            break;
        case 5:
            printf("Saindo ");
            printf(". ");
            sleep(1);
            printf(". ");
            sleep(1);
            printf(".\n");
            break;
        default:
            printf("Opçao invalida.\n");
            break;
        }
    } while (opcao != 5);

    return 0;
}