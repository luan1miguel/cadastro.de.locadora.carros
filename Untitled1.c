#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct DMA{
    int dia;
    int mes;
    int ano;
};
typedef struct DMA tp_data;

struct CLIENTE{
    char nome[50];
    char cpf [15];
    tp_data dta_nasc;
}Cliente[50];

void menu(){
    system("cls");
    printf("----------  Sistema de Cadastro para uma Rede de XXXXX  ----------\n");
    printf("----------              Escolha a opção desejada        ----------\n");
    printf("1 - Cadastro de Cliente \n");
    printf("2 - Imprime Clientes \n");
    printf("3 - Sair \n");
}

void cad_cli(int pos){
    system("cls");
    printf("CADASTRO DE CLIENTE \n");
    //RECEBE O NOME COMPLETO
    printf("Nome:");
    fflush(stdin);
    fgets(Cliente[pos].nome, 40, stdin);
    //RECEBE O CPF
    printf("CPF:");
    scanf("%s", &Cliente[pos].cpf);
    fflush(stdin);
    //RECEBE DATA NASCIMENTO
    printf("DATA DE NASCIMENTO (DD MM YYYY):");
    scanf ("%d %d %d", &Cliente[pos].dta_nasc.dia, &Cliente[pos].dta_nasc.mes, &Cliente[pos].dta_nasc.ano);
    fflush(stdin);
}

void imp_cli(int pos){
    int i;
    system("cls");
    printf("CLIENTES CADASTRADOS \n");
    for(i=0; i<=pos;i++){
        printf("\n");
        printf("Nome: %s", Cliente[i].nome);
        printf("CPF: %s", Cliente[i].cpf);
        printf("\n");
        printf("DATA DE NASCIMENTO: %d/%d/%d \n", Cliente[i].dta_nasc.dia, Cliente[i].dta_nasc.mes, Cliente[i].dta_nasc.ano);
        printf("\n");
    }
    printf("\n");
    system("PAUSE");
}

int main()
{
    int opcao;
    int qtd_cliente=-1;

    setlocale(LC_ALL, "Portuguese"); //Habilita a acentuação para o português
    menu();

    do{
        menu();
        scanf("%d", &opcao);
        switch(opcao){
        case 1:
            qtd_cliente++;
            cad_cli(qtd_cliente);
            break;
        case 2:
            imp_cli(qtd_cliente);
            break;
        case 3:
            printf("Sistema finalizado!! \n");
            break;
        default:
            menu();
        }
    } while (opcao!=3);
    return 0;
}
