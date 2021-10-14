#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ANSI_COLOR_RESET "\e[0m"
#define ANSI_COLOR_WHITE "\e[0;37m"
#define ANSI_COLOR_RED "\e[0;31m"
#define ANSI_COLOR_GREEN "\e[0;32m"
#define ANSI_COLOR_YELLOW "\e[0;33m"

// Função principal

int main()
{
    char estado[3];
    int i = 0, j = 10;
    int estado_int = 0;
    int l = 0;
    int d[11];

// Preechendo os 8 primeiros digitos com valores aleatorios de 0 a 9

    system("clear");
    system("cls");

    srand(time(NULL));
    do
    {
        d[i] = rand() % 9;
        i++;
    } while (i < 8);

    i = 0;

// Entrar com qual estado (str[2])

    printf(ANSI_COLOR_YELLOW"");
    printf("\n----------------------------------------------------");
    printf("\n| GERADOR DE CPF | by https://github.com/JVSCirilo |");
    printf("\n----------------------------------------------------");
    printf(ANSI_COLOR_WHITE"");
    printf("\nExemplos RS, DF, GO etc..");
    printf("\nEstado: ");
    printf(ANSI_COLOR_YELLOW"");
    scanf("%s", estado);

// Converter as letras do estado e concatenar os valores

    estado_int = (((int)(estado[0]) * 100) + (int)(estado[1]));

// verificar o 9o digito

    switch (estado_int)
    {
        case 8283: // RS
        {
            d[8] = 0;
            break;
        }
        case 6870: // DF
        case 7179: // GO
        case 7784: // MT
        case 7783: // MS
        case 8479: // TO
        {
            d[8] = 1;
            break;
        }
        case 6577: // AM
        case 8065: // PA
        case 8282: // RR
        case 6580: // AP
        case 6567: // AC
        case 8279: // RO
        {
            d[8] = 2;
            break;
        }
        case 6769: // CE
        case 7765: // MA
        case 8073: // PI
        {
            d[8] = 3;
            break;
        }
        case 8066: // PB
        case 8069: // PE
        case 6576: // AL
        case 8278: // RN
        {
            d[8] = 4;
            break;
        }
        case 6665: // BA
        case 8369: // SE
        {
            d[8] = 5;
            break;
        }
        case 7771: // MG
        {
            d[8] = 6;
            break;
        }
        case 8274: // RJ
        case 6983: // ES
        {
            d[8] = 7;
            break;
        }
        case 8380: // SP
        {
            d[8] = 8;
            break;
        }
        case 8082: // PR
        case 8367: // SC
        {
            d[8] = 9;
            break;
        }
        default:
        {
            printf(ANSI_COLOR_RED"");
            printf("\nError! Estado invalido: %d, exit -1", estado_int);
            printf(ANSI_COLOR_RESET"\n\n");
            exit(-1);
        }
    }

// Coeficiente L

    do
    {
        l += (j * d[i]);
        i++;
        j--;

    } while (i != 9);

// Calcular 10o digito

    if (l % 11 == 0 || l % 11 == 1)
    {
        d[9] = 0;
    }
    else
    {
        d[9] = (11 - (l % 11));
    }

// Coeficiente M

    l = 0;
    i = 1;
    j = 10;

    do
    {
        l += (j * d[i]);
        i++;
        j--;
    } while (i != 10);

// 11o digito

    if (l % 11 == 0 || l % 11 == 1)
    {
        d[10] = 0;
    }
    else
    {
        d[10] = (11 - (l % 11));
    }

// Saida de dados

    printf(ANSI_COLOR_WHITE"");
    printf("CPF gerado: ");
    printf(ANSI_COLOR_GREEN"");
    i = 0;    
    do
    {
        printf("%d", d[i]);
        if (i == 2 || i == 5)
        {
            printf(".");
        }
        else
        {
            if (i == 8)
            {
                printf("-");
            }
        }
        i++;
    } while (i != 11);

    printf(ANSI_COLOR_RESET"\n\n");
 
    return 0;
}