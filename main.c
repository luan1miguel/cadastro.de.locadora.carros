#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct DMA{
    int dia;
    int mes;
    int ano;
};
typedef struct DMA tp_data;
typedef struct DMA tp_data;/* define a estrutura de data com*/

struct endereco{
    char rua[40];
    char cidade [40];
    char bairro[40];
    int numero [4];
    int cep [11];

}typedef ende;/*define a estrutura de endere�o com */
struct cadastro_Carros{
    int marca[30];
    char cor[25];
    char placa [7];
    char modelo[40];

}typedef cad_carro;/*define as variaveis usadas para cadastro de carros*/

struct CLIENTE{
    char nome[50];
    int cpf [15];
    int rg[10];
    int cnh [10];
    ende moradia;
    cad_carro Carros;
    tp_data dta_nasc;

}Cliente[30];/*define as variaveis usadas para cadastro de clientes*/


struct pessoa_juridica{
    char nfantasia[50];
    char rsocial[30];
    int cnpj[10];
    ende moradia;

}jur;/*define as variaveis usadas para cadastro de clientes do tipo pessoa juridica*/

void menu();
void cad_cli(),pes_jur(),imp_cli(),imp_jur();/*chamas as fun��es que est�o definidas no final do codigo*/

int main()
{
    int opcao;
    int qtd_cliente=-1;
    int qtd_jur=-1;
    char resp;


    setlocale(LC_ALL, "Portuguese"); //Habilita a acentua��o para o portugu�s
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
            exit(1);
            break;
        default:
            menu();
        }
    } while (opcao!=4);
    return 0;//chama a fun��o menu e utiliza do case para especificar qual fun��o sera escolhida
}

void menu(){

    system("cls");
    printf("---------- Sistema para cadastro carloc----------\n");
    printf("---------- Escolha a op��o desejada ----------\n");
    printf("1 - Cadastro de Cliente \n");
    printf("2 - consulta de cliente cadastrado \n");
    printf("3 - Cadastro de empresas \n");
    printf("4 - consulta de empresa \n");
    printf("0 - sair\n");

}//fun��o de menu
void cad_cli(int pos){
    FILE **fp;//define o ponteiro para o arquivo
    fp =fopen("cadastro.txt","a");//abre o arquivo do tipo txt para salvar
    system("cls");
    printf("CADASTRO DE CLIENTE \n");//RECEBE O NOME COMPLETO
    printf("Nome:");
    gets(stdin);
    fgets(Cliente[pos].nome, 40, stdin);
    fprintf(fp,"%s",Cliente[pos].nome);// aponta o fp como local para grava��o do nome que sera digitado
    fflush(stdin);
    printf("CPF:");
    scanf("%d", &Cliente[pos].cpf);//RECEBE O CPF
    fprintf(fp,"%d",Cliente[pos].cpf);
    printf("informe o RG:");
    scanf("%d",&Cliente[pos].rg);
    fflush(stdin);
    fprintf(fp,"%d",Cliente[pos].rg);
    printf("informe a CNH:");
    scanf("%d",&Cliente[pos].cnh);
    fflush(stdin);
    fprintf(fp,"%d",Cliente[pos].cnh);
    printf("informe sua cidade:");
    fgets(Cliente[pos].moradia.cidade,40,stdin);
    fflush(stdin);
    fprintf(fp,"%s",Cliente[pos].moradia.cidade);
    printf("informe sua bairro:");
    fgets(Cliente[pos].moradia.bairro,40,stdin);
    fflush(stdin);
    fprintf(fp,"%s",Cliente[pos].moradia.bairro);
    printf("informe nome da sua rua:");
    fgets(Cliente[pos].moradia.rua,20,stdin);
    fflush(stdin);
    fprintf(fp,"%d",Cliente[pos].moradia.rua);
    printf("CEP:");
    fgets(Cliente[pos].moradia.cep,20,stdin);
    fflush(stdin);
    fprintf(fp,"%s",Cliente[pos].moradia.rua);
    printf("Numero:");
    fgets(Cliente[pos].moradia.numero,4,stdin);
    fflush(stdin);
    fprintf(fp,"%d",Cliente[pos].moradia.numero);
    printf("DATA DE NASCIMENTO (DD MM YYYY):");
    scanf ("%d %d %d", &Cliente[pos].dta_nasc.dia, &Cliente[pos].dta_nasc.mes, &Cliente[pos].dta_nasc.ano);//RECEBE DATA NASCIMENTO
    fflush(stdin);
    fprintf(fp,"%d %d %d",Cliente[pos].dta_nasc.dia, &Cliente[pos].dta_nasc.mes, &Cliente[pos].dta_nasc.ano);
    printf("carro alugado:");
    fflush(stdin);
    scanf("%s",&Cliente[pos].Carros.marca);
    fprintf(fp,"%d",Cliente[pos].Carros.marca);
    printf("placa do carro:");
    fflush(stdin);
    scanf("%s",&Cliente[pos].Carros.placa);
    fprintf(fp,"%d",Cliente[pos].Carros.placa);
    fclose(fp);//fecha o arquivo
}//fun��o criada para o cadastro de clientes
void pes_jur(int jus){
    FILE **fp;//define 1 arquivo com ponteiro
    fp= fopen("pesjur.txt","a+");//atraves do ponteiro indica a abertura de 1 arquivo txt, para grava��o de texto
    system("cls");
    printf("nome fantasia de sua empresa: \n ");
    scanf("%s",jur.nfantasia);
    fflush(stdin);
    fprintf(fp,"%s",jur.nfantasia);//indica atraves do ponteiro que onde o que sera gravado
    printf("informe a razao social: \n");
    fgets(jur.rsocial,30,stdin);
    fflush(stdin);
    fprintf(fp,"%s",jur.rsocial);
    printf("informe o CNPJ \n");
    scanf("%d",jur.cnpj);
    fflush(stdin);
    fprintf(fp,"%s",jur.cnpj);
    printf("informe a cidade de sua empresa:");
    fgets(jur.moradia.cidade,30,stdin);
    fflush(stdin);
    fprintf(fp,"%s",jur.moradia.cidade);
    printf("informe o bairro da sua empresa:");
    fgets(jur.moradia.bairro,40,stdin);
    fflush(stdin);
    fprintf(fp,"%s",jur.moradia.bairro);
    printf("Rua de sua empresa:");
    fgets(jur.moradia.rua,20,stdin);
    fflush(stdin);
    fprintf(fp,"%s",jur.moradia.rua);
    printf("CEP:");
    fgets(jur.moradia.cep,20,stdin);
    fflush(stdin);
    fprintf(fp,"%s",jur.moradia.cep);
    printf("Numero:");
    fgets(jur.moradia.numero,20,stdin);
    fflush(stdin);
    fprintf(fp,"%d",jur.moradia.numero);
    fclose(fp);//fecha o arquivo
}//fun��o de cadastro para pessoa juridica
void imp_cli(int pos){
    int i;
    FILE **fp;//ponteiro para o arquivo
    system("cls");
    printf("CLIENTES CADASTRADOS \n");
    for(i=0; i<=pos;i++){//looping nescessario para ler caracter a caracter do arquivo
        fp=fopen("pesjur.txt","r");//indica o arquivo que deve ser aberto para leitura
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
}//fun��o que ira mostrar na tela todo os cadastro.
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
