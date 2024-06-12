#include "sistema.h"

int logins = 0;
int numUsuarios = 0;
struct usuario *clientes = NULL;
int horarios[31][12][10][24];
int numConsultas = 0;
void alocarClientes()
{
    clientes = (struct usuario *)realloc(clientes, (numUsuarios + 1) * sizeof(struct usuario));
}

void cadastrarUsuario()
{
    if (numUsuarios >= MAXU)
    {
        printf("Numero maximo de usuarios atingido.\n");
        return;
    }

    alocarClientes();

    printf("Digite o primeiro nome de usuario: ");
    scanf(" %s", clientes[numUsuarios].nome);
    printf("Digite o sobrenome: ");
    scanf(" %s", clientes[numUsuarios].sobrenome);
    printf("Digite a idade: ");
    scanf(" %d", &clientes[numUsuarios].idade);
    printf("Digite o login(Apenas caracteres sem espaco): ");
    scanf(" %s", clientes[numUsuarios].login);
    printf("Digite a senha(Apenas números sem espaco): ");
    scanf(" %s", clientes[numUsuarios].senha);

    numUsuarios++;

    printf("Cadastrando usuario ");
    printf(". ");
    sleep(1);
    printf(". ");
    sleep(1);
    printf(".\n");
    sleep(1);

    printf("Usuario registrado com sucesso!\n");
}

void login()
{
    char usuario[20];
    char senha[20];

    if (numUsuarios == 0)
    {
        printf("Nao ha usuarios cadastrados.\n");
        printf(" 1 - Cadastrar\n 2 - Sair\n");

        int opcao;
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            cadastrarUsuario();
            break;
        case 2:
            break;
        default:
            printf("Opçao invalida\n");
            break;
        }

        return;
    }

    printf("Digite o nome de usuario: ");
    scanf(" %s", usuario);
    printf("Digite a senha: ");
    scanf(" %s", senha);

    int i;
    for (i = 0; i < numUsuarios; i++)
    {
        if (strcmp(clientes[i].login, usuario) == 0 && strcmp(clientes[i].senha, senha) == 0)
        {
            printf("Verificando login ");
            printf(". ");
            sleep(1);
            printf(". ");
            sleep(1);
            printf(".\n");
            sleep(1);
            printf("Login bem-sucedido!\n");
            logins++;
            return;
        }
    }

    printf("Verificando login ");
    printf(". ");
    sleep(1);
    printf(". ");
    sleep(1);
    printf(".\n");
    sleep(1);
    printf("Usuario ou senha invalidos.\n");
    printf(" 1 - Tentar Novamente\n 2 - Cadastrar\n 3 - Sair\n");

    int opcao;
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
        break;
    default:
        printf("Opçao invalida\n");
        break;
    }
}

int dataValida(int dia, int mes, int ano)
{
    if ((dia < 1 || dia > 31 || mes < 1 || mes > 12) || ano < 2023)
    {
        printf("Data invalida\n");
        printf(" 1 - Tentar Novamente\n 2 - Sair\n");

        int opcao;
        scanf("%d", &opcao);

        if (opcao == 1)
        {
            printf("Digite o dia: ");
            scanf("%d", &dia);
            printf("Digite o mes: ");
            scanf("%d", &mes);
            printf("Digite o ano: ");
            scanf("%d", &ano);
            dataValida(dia, mes, ano);
        }
        else if (opcao == 2)
        {
            return 0;
        }
    }
    else if (mes == 2)
    {
        if ((ano % 4 == 0 && ano % 100 != 0) || ano % 400 == 0)
        {
            if (dia <= 29)
            {
                return 1;
            }
        }
        else if (dia <= 28)
        {
            return 1;
        }
    }
    else if ((mes == 4 || mes == 6 || mes == 9 || mes == 11) && dia <= 30)
    {
        return 1;
    }
    else if ((mes == 1 || mes == 3 || mes == 5 || mes == 7 ||
              mes == 8 || mes == 10 || mes == 12) &&
             dia <= 31)
    {
        return 1;
    }

    return 0;
}

void marcarConsulta()
{
    if (numUsuarios == 0)
    {
        printf("Nao ha usuarios cadastrados.\n");
        printf(" 1 - Cadastrar\n 2 - Sair\n");

        int opcao;
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            cadastrarUsuario();
            break;
        case 2:
            break;
        default:
            printf("Opçao invalida\n");
            break;
        }

        return;
    }

    if (logins == 0)
    {
        printf("Voce precisa estar logado para marcar uma consulta.\n");
        printf(" 1 - Fazer login\n 2 - Sair\n");

        int opcao;
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            login();
            break;
        case 2:
            break;
        default:
            printf("Opção invalida\n");
            break;
        }

        return;
    }

    if (numConsultas >= MAXC)
    {
        printf("Numero maximo de consultas atingido.\n");
        return;
    }

    int dia, mes, ano, hora;
    printf("Digite o dia: ");
    scanf("%d", &dia);
    printf("Digite o mes: ");
    scanf("%d", &mes);
    printf("Digite o ano: ");
    scanf("%d", &ano);

    if (dataValida(dia, mes, ano) == 1)
    {
        printf("Digite a hora: ");
        scanf("%d", &hora);

        if (hora >= 8 && hora <= 17)
        {
            if (horarios[dia][mes][2023 - ano][hora] == 0)
            {
                horarios[dia][mes][2023 - ano][hora] = 1; // 1 = horário ocupado
                printf("Realizando marcaçao de consulta ");
                printf(". ");
                sleep(1);
                printf(". ");
                sleep(1);
                printf(".\n");
                sleep(1);
                printf("Consulta marcada com sucesso!\n");
                numConsultas++;
            }
            else
            {
                printf(". ");
                sleep(1);
                printf(". ");
                sleep(1);
                printf(".\n");
                sleep(1);
                printf("Horario ja está ocupado.\n");
            }
        }
        else
        {
            printf(". ");
            sleep(1);
            printf(". ");
            sleep(1);
            printf(".\n");
            sleep(1);
            printf("Hora invalida\n");
        }
    }
    else
    {
        printf(". ");
        sleep(1);
        printf(". ");
        sleep(1);
        printf(".\n");
        sleep(1);
        printf("Data invalida\n");
    }
}

void cancelarConsulta()
{

    if (numUsuarios == 0)
    {
        printf("Nao ha usuarios cadastrados.\n");
        printf(" 1 - Cadastrar\n 2 - Sair\n");

        int opcao;
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            cadastrarUsuario();
            break;
        case 2:
            break;
        default:
            printf("Opçao invalida\n");
            break;
        }

        return;
    }

    if (logins == 0)
    {
        printf("Voce precisa estar logado para cancelar uma consulta.\n");
        printf(" 1 - Fazer login\n 2 - Sair\n");

        int opcao;
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            login();
            break;
        case 2:
            break;
        default:
            printf("Opçao invalida\n");
            break;
        }

        return;
    }

    int dia, mes, ano, hora;
    printf("Digite o dia: ");
    scanf("%d", &dia);
    printf("Digite o mês: ");
    scanf("%d", &mes);
    printf("Digite o ano: ");
    scanf("%d", &ano);
    printf("Digite a hora: ");
    scanf("%d", &hora);

    if (horarios[dia][mes][2023 - ano][hora] == 1)
    {
        horarios[dia][mes][2023 - ano][hora] = 0;
        printf("Realizando cancelamento de consulta ");
        printf(". ");
        sleep(1);
        printf(". ");
        sleep(1);
        printf(".\n");
        sleep(1);
        printf("Consulta cancelada com sucesso!\n");
        numConsultas--;
    }
    else
    {
        printf("Verificando horário ");
        printf(". ");
        sleep(1);
        printf(". ");
        sleep(1);
        printf(".\n");
        sleep(1);
        printf("Nao ha consulta marcada nesse horário.\n");
    }
}

