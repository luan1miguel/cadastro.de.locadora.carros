#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct DMA{
    int dia;
    int mes;
    int ano;
};
typedef struct DMA tp_data;
typedef struct DMA tp_data;

struct endereco{
    char rua[40];
    char cidade [40];
    char bairro[40];
    int numero [4];
    int cep [11];

}typedef ende;
struct cadastro_Carros{
    int marca[30];
    char cor[25];
    char placa [7];
    char modelo[40];

}typedef cad_carro;

struct CLIENTE{
    char nome[50];
    int cpf [15];
    int rg[10];
    int cnh [10];
    ende moradia;
    cad_carro Carros;
    tp_data dta_nasc;

}Cliente[50];

struct pessoa_juridica{
    char nfantasia[50];
    char rsocial[30];
    int cnpj[10];
    ende moradia;

}jur;

void menu(){

    system("cls");
    printf("---------- Sistema para cadastro carloc----------\n");
    printf("---------- Escolha a opção desejada ----------\n");
    printf("1 - Cadastro de Cliente \n");
    printf("2 - consulta de cliente cadastrado \n");
    printf("3 - Cadastro de empresas \n");
    printf("4 - consulta de empresa \n");
    printf("0 - sair\n");

}

void cad_cli(int pos){
    system("cls");
    printf("CADASTRO DE CLIENTE \n");//RECEBE O NOME COMPLETO
    printf("Nome:");
    fflush(stdin);
    fgets(Cliente[pos].nome, 40, stdin);
    fflush(stdin);
    printf("CPF:");
    scanf("%d", &Cliente[pos].cpf);//RECEBE O CPF
    fflush(stdin);
    printf("informe o RG:");
    scanf("%d",&Cliente[pos].rg);
    fflush(stdin);
    printf("informe a CNH:");
    scanf("%d",&Cliente[pos].cnh);
    fflush(stdin);
    printf("informe sua cidade:");
    fgets(Cliente[pos].moradia.cidade,40,stdin);
    fflush(stdin);
    printf("informe sua bairro:");
    fgets(Cliente[pos].moradia.bairro,40,stdin);
    fflush(stdin);
    printf("informe nome da sua rua:");
    fgets(Cliente[pos].moradia.rua,20,stdin);
    fflush(stdin);
    printf("CEP:");
    fgets(Cliente[pos].moradia.cep,20,stdin);
    fflush(stdin);
    printf("Numero:");
    fgets(Cliente[pos].moradia.numero,4,stdin);
    fflush(stdin);
    printf("DATA DE NASCIMENTO (DD MM YYYY):");
    scanf ("%d %d %d", &Cliente[pos].dta_nasc.dia, &Cliente[pos].dta_nasc.mes, &Cliente[pos].dta_nasc.ano);//RECEBE DATA NASCIMENTO
    fflush(stdin);
    printf("carro alugado:");
    fflush(stdin);
    scanf("%s",&Cliente[pos].Carros.marca);
    printf("placa do carro:");
    fflush(stdin);
    scanf("%s",&Cliente[pos].Carros.placa);

}

void pes_jur(int jus){

    system("cls");
    printf("nome fantasia de sua empresa: \n ");
    scanf("%s",jur.nfantasia);
    fflush(stdin);
    printf("informe a razao social: \n");
    fgets(jur.rsocial,30,stdin);
    printf("informe o CNPJ \n");
    scanf("%d",jur.cnpj);
    fflush(stdin);
    printf("informe a cidade de sua empresa:");
    fgets(jur.moradia.cidade,30,stdin);
    fflush(stdin);
    printf("informe o bairro da sua empresa:");
    fgets(jur.moradia.bairro,40,stdin);
    fflush(stdin);
    printf("Rua de sua empresa:");
    fgets(jur.moradia.rua,20,stdin);
    fflush(stdin);
    printf("CEP:");
    fgets(jur.moradia.cep,20,stdin);
    fflush(stdin);
    printf("Numero:");
    fgets(jur.moradia.numero,20,stdin);
    fflush(stdin);


}
void imp_cli(int pos){
    int i;
    system("cls");
    printf("CLIENTES CADASTRADOS \n");
    for(i=0; i<=pos;i++){
        printf("\n");
        printf("Nome: %s", Cliente[i].nome);
        printf("\n");
        printf("CPF: %d", Cliente[i].cpf);
        printf("\n");
        printf("RG: %d",Cliente[i].rg);
        printf("\n");
        printf("CNH: %d",Cliente[i].cnh);
        printf("\n");
        printf("Cidade situada: %s",Cliente[i].moradia.cidade);
        printf("\n");
        printf("Bairro: %s",Cliente[i].moradia.bairro);
        printf("\n");
        printf("Rua: %s",Cliente[i].moradia.rua);
        printf("\n");
        printf("CEP: %s",Cliente[i].moradia.cep);
        printf("\n");
        printf("Numero: %s",Cliente[i].moradia.numero);
        printf("\n");
        printf("DATA DE NASCIMENTO: %d/%d/%d \n", Cliente[i].dta_nasc.dia, Cliente[i].dta_nasc.mes, Cliente[i].dta_nasc.ano);
        printf("\n");
        printf("Carro alugado: %s",Cliente[i].Carros.marca);
        printf("\n");
        printf("Placa do carro: %s",Cliente[i].Carros.placa);
        printf("\n");
    }
    printf("\n");
    system("PAUSE");
}

void imp_jur(int ju){
    int y;
    system("cls");
    printf("empresas cadastradas \n");
    for (y=0; y<=ju;y++){
        printf("\n");
        printf("Nome da empresa: %s",jur.nfantasia);
        printf("\n");
        printf("CNPJ: %d",jur.cnpj);
        printf("\n");
        printf("Razao social: %s",jur.rsocial);
        printf("\n");
        printf("Cidade: %s",jur.moradia.cidade);
        printf("\n");
        printf("Bairro: %s",jur.moradia.bairro);
        printf("\n");
        printf("Cep: %d",jur.moradia.cep);
        printf("\n");
        printf("Numero: %s",jur.moradia.numero);
        printf("\n");


    }


}
int main()
{
    int opcao;
    int qtd_cliente=-1;
    int qtd_jur=-1;

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
            qtd_jur++;
            pes_jur(qtd_jur);
            break;
        case 4:
            imp_jur(qtd_jur);
            break;
        case 0:
            printf("Sistema finalizado!! \n");
            break;
        default:
            menu();
        }
    } while (opcao!=4);
    return 0;
}
