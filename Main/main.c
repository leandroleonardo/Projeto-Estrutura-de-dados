#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <locale.h>
#include <conio.h>
#include <ctype.h>

typedef struct pets no;
typedef struct racas ra;
typedef struct animal_adotados ad;

void listagem_animais_adotados(no *inicio3);
void cores();
void deletar(ad **inicio3,no **inicio,ra **inicio2);
void mostrar_especies(ra *inicio2);
int verifica_especie(ra *inicio2,no *novo);
void busca_nome_especie(no *inicio);
void listagem_animais(no *inicio);
void incluir_animal(no **inicio,int *reg[],int *cont,ra **inicio2);
void contagem(no *inicio);
void busca_e_r(no *inicio);
void modificar(no *inicio);
void busca_especie_raca(no *inicio);
void busca_especie_raca_sexo(no *inicio);
void procura_adotados(ad *inicio3);
void reinserir_animal(no **inicio,ad **inicio3);

struct racas
{
    char rn[50]; //raca de animal
    int cont;
    struct racas *prox;
};

struct pets
{
    char nome[50];
    char especie[50];
    char raca[50];
    char sexo[1];
    int  idade;
    char cg[100];
    int id;
    int con; //condicao,1 adotado, 2 excluido, 0 em adocao

    struct pets *prox;
};

struct animal_adotados
{
    char nome[50];
    char especie[50];
    char raca[50];
    char sexo[1];
    int  idade;
    char cg[100];
    int  id;
    int  con; //condicao,1 adotado, 2 excluido e 0 em adocao

    struct animal_adotados *prox;
};

int main()
{
    system("COLOR F0");

    int n=44,idd=0000,reg[10000]={NULL},cont=0;
    no *inicio = NULL; //lista vazia
    ra *inicio2 = NULL; //lista de raca //lista vazia
    ad *inicio3 = NULL; //lista de animais apagados
    //menu
    do
    {
      setlocale(LC_ALL, "Portuguese"); //Usar acentuacao e sinais da lingua portuguesa

printf("                                                       \n"
       " \t\t\t ____________________MENU_______________________\n"
       " \t\t\t|                                               |\n"
       " \t\t\t| 1.Inclus�o de novos animais                   |\n"
       " \t\t\t| 2.Remo��o de animais                          |\n"
       " \t\t\t| 3.Altera��o de informa��es                    |\n"
       " \t\t\t| 4.Busca de animais por esp�cie ou nome        |         _____    _____   _______   ______  \n"
       " \t\t\t| 5.Busca de animais por esp�cie e ra�a         |        |  _  |  |  ___| |__   __| | _____| \n"
       " \t\t\t| 5.Busca de animais por esp�cie e ra�a         |        | |_| |  | |___     | |    | |____ \n"
       " \t\t\t| 6.Busca de animais por esp�cie, ra�a e sexo   |        |  ___|  |  ___|    | |    |_____ | \n"
       " \t\t\t| 7.Contagem (quantidade de animais)            |        | |      |  ___     | |     ____| | \n"
       " \t\t\t| 8.Contagem por esp�cie                        |        |_|      |_____|    |_|    |______| \n"
       " \t\t\t| 9.Listagem de todos os animais cadastrados    |\n"
       " \t\t\t| 10.configura��es(Diagramacao)                 |            __________________________        \n"
       " \t\t\t| 11.Animais j� adotados e exclu�dos            |\n"
       " \t\t\t| 12.Procurar animal j� adotado                 |\n"
       " \t\t\t| 13.Reinserir animal j� exclu�do ou adotado    |\n"
       " \t\t\t|_______________________________________________|\n"
       "\n\nEscolha: "
       );

    //funcao para ver se e um inteiro msm
        scanf("%d",&n);

    switch(n)
    {
        //teste

        case 1:
            incluir_animal(&inicio,&reg,&cont,&inicio2); //inclue novo animal
        break;

        case 2:
            deletar(&inicio3,&inicio,&inicio2);
        break;

        case 3:
            modificar(inicio); //altera informacao
        break;

        case 4:
            busca_nome_especie(inicio);
        break;

        case 5:
            busca_especie_raca(inicio);
        break;

        case 6:
            busca_especie_raca_sexo(inicio);
        break;

        case 7:
            contagem(inicio);
        break;

        case 8:
            mostrar_especies(inicio2);
        break;

        case 9:
            listagem_animais(inicio);
        break;

        case 10:
            cores();
        break;

        case 11:
            listagem_animais_adotados(inicio3);
        break;

        case 12:
            procura_adotados(inicio3);
        break;

        case 13:
            reinserir_animal(&inicio,&inicio3);
        break;
        }

    }while(n!=0);

    return 0;
}

void listagem_animais(no *inicio)
{
    system("cls"); //Limpa tela

    //se lista for vazia, printa a mensagem
    if(inicio == NULL)
    {
      printf("\n Nenhum animal cadastrado\n\n");
    }
    else
    {
        printf("\n> Listagem de animais\n");
        //mostra ao usuario os animais cadastrados
        while(inicio != NULL)
        {
            printf("\n Nome: %s\n",inicio->nome);
            printf(" Esp�cie: %s\n",inicio->especie);
            printf(" Ra�a: %s\n",inicio->raca);
            printf(" Sexo: %s\n",inicio->sexo);
            printf(" Idade: %d\n",inicio->idade);
            printf(" Caracter�sticas gerais : %s\n",inicio->cg);
            printf(" id: %d\n",inicio->id);
            printf("\n------------------------------------------\n");

            inicio = inicio -> prox;
        }
    }
    system("pause");
    system("cls");
}

void incluir_animal(no **inicio,int *reg[],int *cont,ra **inicio2)
{

    char letra;
    int qnt,i;

    printf("\n Quantidades de animais que voce quer adicionar: ");
    scanf("%d",&qnt);
    //apenas limpa a tela e retorna
    if(qnt == 0)
    {
        system("cls");
        return;
    }
    //le a quantidade de animais que o usuario escolheu
    for(i=0;i<qnt;i++)
    {
        system("cls");

        no *novo = malloc(sizeof(no));
        //se n conseguir alocar um *novo no na memoria ele da heapoverflow, entao ele apenas realiza o retorno
        if(novo==NULL)
        {
            return;
        }
        printf("\n Registro de animais \n");

        fflush(stdin);    //limpa buffer
        printf("\n Nome:");
        gets(novo->nome); //leitura de nome

        //deixa primeira letra grande
        letra = novo->nome[0];
        letra = toupper(letra);
        novo->nome[0] = letra;

        fflush(stdin); //limpar buffer
        printf(" Esp�cie: ");
        gets(novo->especie); //leitura de especie

        //deixa primeira letra grande
        letra = novo->especie[0];
        letra = toupper(letra);
        novo->especie[0] = letra;

        //verifica na struct especie se ja existe um cadastro de especie, se exister apenas zera
        if(verificar_especie(*inicio2,novo)==1)
        {
            ra *novo2 = malloc(sizeof(ra));

            strcpy(novo2->rn,novo->especie);
            novo2 -> cont = 1;

            novo2 -> prox = (*inicio2);
            (*inicio2) = novo2;
        }
        fflush(stdin); //limpa buffer
        printf(" Ra�a: ");
        gets(novo->raca); //leitura de especie

        //deixa primeira letra grande
        letra = novo->raca[0];
        letra = toupper(letra);
        novo->raca[0] = letra;

        //deixa primeira letra grande
        fflush(stdin);
        printf(" Sexo,(F)f�mea ou (M)Macho: ");
        gets(novo->sexo); //leitura de sexo

        //deixa primeira letra grande
        letra = novo->sexo[0];
        letra = toupper(letra); //toupper deixa carcacter grande
        novo->sexo[0] = letra; //leitra de sexo

        printf(" Idade: ");
        fflush(stdin);
        scanf("%d",&novo->idade);

        fflush(stdin);
        printf(" Caracter�sticas gerais: ");
        gets(novo->cg);

        novo->con=0;

        system("cls"); //limpa tela

        novo->id = 1;
        reg[*cont] = novo->id;

        //verifica se ID ja existe, ou ja foi cadastrado um dia
        for(int i=0;i<*cont;i++)
        {
            if(reg[i]==novo->id)
           {
                while(reg[i]==novo->id)
                {
                    novo->id++;
                    reg[*cont] = novo->id;
                }
            }
        }
        (*cont)++;

        //adiciona pet na lista
        novo -> prox = (*inicio);
        (*inicio) = novo;
     }
}

int verificar_especie(ra *inicio2,no *novo)
{
    while(inicio2!=NULL)
    {
        if(strcasecmp(novo->especie,inicio2->rn)==0)
        {
            inicio2 -> cont = (inicio2 -> cont)+1;
            return 0;
        }
        inicio2=inicio2->prox;
    }
    return 1;
}

void contagem(no *inicio)
{
    system("cls");
    int quantidade=0;

        while(inicio!=NULL)
        {
            inicio = inicio -> prox;
            quantidade++;
        }
        printf("\n Quantidade de animais cadastrados: %d\n\n",quantidade);

    system("pause");
    system("cls");
}

void busca_nome_especie(no *inicio)
{
    char nome[50],especie[50],letra;
    int  ret=9,cont=0,m=3,escolha=99;

    system("cls");

    printf("\n  | 1.Deseja procurar pelo nome     |\n"
           "  | 2.Deseja procurar pela especie: |\n"
           "  | 0.Sair                          |\n\n Escolha:");

    scanf("%d",&escolha);
    if(escolha == 0)
    {
        system("cls");
        return;
    }
    //realiza a busca pelo nome ou especie
    //deixando o primeiro caracter da palavra em maiusculo
    else if(escolha == 1)
    {
        printf("Nome do animal: ");
        fflush(stdin);
        gets(nome);
        letra = toupper(nome[0]);
        nome[0] = letra;
    }
    else if(escolha == 2)
    {
        printf("Especie do animal: ");
        fflush(stdin);
        gets(especie);
        letra = toupper(especie[0]);
        especie[0] = letra;
    }
    system("cls");

    if(inicio == NULL)
    {
        return;
    }

    while(inicio != NULL)
    {
        //verifica a saida do ret, que serve para comparar string
        if(escolha == 1)
        {
            ret = strcmp(inicio->nome,nome);
        }
        //se ele achar ele mostra o cadastro do animal para o usuario
        else
        if(escolha == 2)
        {
            ret = strcmp(inicio->especie,especie);
        }
            if(ret == 0)
            {
                printf("\n Nome: %s\n",inicio->nome);
                printf(" Esp�cie: %s\n",inicio->especie);
                printf(" Ra�a: %s\n",inicio->raca);
                printf(" Sexo: %s\n",inicio->sexo);
                printf(" Idade: %d\n",inicio->idade);
                printf(" Caracter�sticas gerais : %s\n",inicio->cg);
                printf(" ID:%d",inicio->id);
                printf("\n----------------------------------------\n");
                cont ++;
            }
            inicio = inicio -> prox;
    }
    system("pause");
    system("cls");
    //return;
}

void busca_e_r(no *inicio)
{
    char especie[40],letra;
    int ret=9,cont=0;

    printf("Especie do animal: ");
    fflush(stdin);
    gets(especie);

    letra = toupper(especie[0]);
    especie[0] = letra;

    system("cls");

    printf("\n Resultados de busca \n");
    while(inicio != NULL)
    {
        //ret = strcmp(inicio->especie,especie)&&strcmp(inicio->nome,nome);
        if(ret == 0)
        {
            printf("\n Nome: %s\n",inicio->nome);
            printf(" Esp�cie: %s\n",inicio->especie);
            printf(" Ra�a: %s\n",inicio->raca);
            printf(" Sexo: %s\n",inicio->sexo);
            printf(" Idade: %d\n",inicio->idade);
            printf(" Caracter�sticas gerais : %s\n",inicio->cg);
            printf("-----------------------------------------\n");
            cont ++;
        }
        inicio = inicio -> prox;
    }
    system("pause");
    system("cls");
}

void modificar(no *inicio)
{

    int id,es=0; //cria as variaves
    char letra;
    int ida,idd;

    printf("ID: ");
    scanf("%d",&id); //digita id que voce vai querer alterar

    //verifica se id existe

    system("cls"); //limpa tela
    while (inicio!= NULL) //anda com a lista
    {
            if(id == inicio -> id) //se ID for encontrado, ele compara no a no para achar
            {
                printf("\n Nome: %s\n",inicio->nome);
                printf(" Esp�cie: %s\n",inicio->especie);
                printf(" Ra�a: %s\n",inicio->raca);
                printf(" Sexo: %s\n",inicio->sexo);
                printf(" Idade: %d\n",inicio->idade);
                printf(" Caracter�sticas gerais : %s\n",inicio->cg);
                printf("-----------------------------------------\n");

                printf("\n |1.Modificar         |\n"
                         " |0.voltar ao menu    |\n"
                         "\n Escolha: ");
                scanf("%d",&es);

                if(es == 0) //se for igual a 0
                {
                    system("cls"); //lima a tela
                    return; //retorna para funcao principal
                }
                //Faz a releitura do NO, que no caso seria o cadastro
                if(es == 1)
                {
                    fflush(stdin);
                    printf("\n Nome:");
                    gets(inicio->nome);

                    letra = inicio->nome[0];
                    letra = toupper(letra);
                    inicio->nome[0] = letra;

                    fflush(stdin);
                    printf(" Esp�cie: ");
                    gets(inicio->especie);

                    letra = inicio->especie[0];
                    letra = toupper(letra);
                    inicio->especie[0] = letra;

                    fflush(stdin);
                    printf(" Ra�a: ");
                    gets(inicio->raca);

                    letra = inicio->raca[0];
                    letra = toupper(letra);
                    inicio->raca[0] = letra;

                    fflush(stdin);
                    printf(" Sexo,(F)f�mea ou (M)Macho: ");
                    gets(inicio->sexo);

                    letra = inicio->sexo[0];
                    letra = toupper(letra);
                    inicio->sexo[0] = letra;

                    fflush(stdin);
                    printf(" Idade: ");
                    scanf("%d",&ida);

                    inicio->idade = ida;

                    fflush(stdin);
                    printf(" Caracter�sticas gerais: ");

                    gets(inicio->cg);
                    fflush(stdin);

                    system("PAUSE\n");
                    system("cls");
                }
            }
            inicio = inicio -> prox;
    }
    system("cls");
    // verifica resposta 1: edicao do cadastro, 2: excluir, 0: return
}

void busca_especie_raca(no *inicio)
{
    char raca[50],especie[50],letra;
    int  ret1=9,ret=9,cont=0,m=3,escolha=99;

    printf("Nome do raca: ");
    fflush(stdin);
    gets(raca);
    letra = toupper(raca[0]);
    raca[0] = letra;

    printf("Especie do animal: ");
    fflush(stdin); //LIMPA BUFFER
    gets(especie); //Realiza a leitura
    letra = toupper(especie[0]); //armazena primeira letra em var letra, e a funcao toupper para deixar ela maiuscula
    especie[0] = letra; //retorma para a palavra agora com a letra grande

    system("cls");
    printf("\n\n _ Resultados de busca _ \n");

    while(inicio != NULL)
    {
        //verifica a saida do ret, que serve para comparar string
        ret = strcmp(inicio->especie,especie);
        ret1 = strcmp(inicio->raca,raca);
            if(ret == 0 && ret1 == 0 )
            {
                printf("\n Nome: %s\n",inicio->nome);
                printf(" Esp�cie: %s\n",inicio->especie);
                printf(" Ra�a: %s\n",inicio->raca);
                printf(" Sexo: %s\n",inicio->sexo);
                printf(" Idade: %d\n",inicio->idade);
                printf(" Caracter�sticas gerais : %s\n",inicio->cg);
                printf(" ID:%d",inicio->id);
                printf("\n----------------------------------------\n");
                cont ++;
            }
            inicio = inicio -> prox;
    }
    system("pause");
    system("cls");
}

void busca_especie_raca_sexo(no *inicio)
{
    char raca[50],especie[50],letra,sexo[02];
    int  ret1=9,ret=9,ret3=9,cont=0,m=3,escolha=99;

    printf("\nSexo: ");
    fflush(stdin);
    gets(sexo);
    letra = toupper(sexo[0]);
    sexo[0] = letra;

    printf("Ra�a: ");
    fflush(stdin);
    gets(raca);
    letra = toupper(raca[0]);
    raca[0] = letra;

    printf("Especie do animal: ");
    fflush(stdin);
    gets(especie);
    letra = toupper(especie[0]);
    especie[0] = letra;

    system("cls");
     printf("\n\n |  Resultados de busca  | \n\n\n");

    while(inicio != NULL)
    {
        //verifica a saida do ret, que serve para comparar string
        ret = strcmp(inicio->especie,especie);
        ret1 = strcmp(inicio->raca,raca);
        ret3 = strcmp(inicio->sexo,sexo);

            if(ret == 0 && ret1 == 0 && ret3 == 0)
            {
                printf("\n Nome: %s\n",inicio->nome);
                printf(" Esp�cie: %s\n",inicio->especie);
                printf(" Ra�a: %s\n",inicio->raca);
                printf(" Sexo: %s\n",inicio->sexo);
                printf(" Idade: %d\n",inicio->idade);
                printf(" Caracter�sticas gerais : %s\n",inicio->cg);
                printf(" ID:%d",inicio->id);
                printf("\n----------------------------------------\n");
                cont ++;
            }
            inicio = inicio -> prox;
    }
    system("pause");
    system("cls");
}

void mostrar_especies(ra *inicio2)
{
    system("cls");
    printf("                  Especies                             \n\n");

    while(inicio2!=NULL) //percorre a lista de racas
    {
        printf("\n\t| Especie: %s \ Quantidade: %d|\n",inicio2->rn,inicio2->cont);
        inicio2 = inicio2 -> prox; //anda com a lista para o proximo NO
    }
    printf("\n\n"); //pula linha
    system("pause"); //pausa o programa
    system("cls"); //limpa a tela
}

void deletar(ad **inicio3,no **inicio,ra **inicio2)
{
    int id,es=0,es1=1,ida,idd;
    char letra,condicao[15]="Adotado";
    int cont=0,ret=1;

    no *novo3 = malloc(sizeof(no));
    ad *novo33 = malloc(sizeof(ad));

    //cria ponteiro do tipo da struct e quarta a cabeca inicial, para a lista n perder nenhum NO
    no *aux;
    no *oldinicio = malloc(sizeof(no));
    ra *oldinicio2 = malloc(sizeof(no));

    //guarda inicio para nao perder a lista toda
    oldinicio = (*inicio);
    oldinicio2 = (*inicio2);

    //guarda ponteiro anterior e o proximo
    no *no_prox = malloc(sizeof(no));
    no *no_ant = malloc(sizeof(no));

    printf("ID: ");
    scanf("%d",&id);
    //verifica se id existe
    system("cls");
    //anda com a lista

    while ((*inicio)!= NULL)
    {
        no_prox = (*inicio)->prox;

            //se ID for encontrado, ele compara no a no para achar
            if(id == (*inicio) -> id)
            {
                printf("\n Nome: %s\n",(*inicio)->nome);
                printf(" Esp�cie: %s\n",(*inicio)->especie);
                printf(" Ra�a: %s\n",(*inicio)->raca);
                printf(" Sexo: %s\n",(*inicio)->sexo);
                printf(" Idade: %d\n",(*inicio)->idade);
                printf(" Caracter�sticas gerais : %s\n",(*inicio)->cg);
                printf("-----------------------------------------\n");
                //realiza a escolha, se deseja excluir mesmo
                printf("\n |1.Excluir           \n"
                         " |0.voltar ao menu    \n"
                         "\n Escolha: ");

                scanf("%d",&es);

                if(es == 0)
                {
                    system("cls");
                    (*inicio)=oldinicio;
                    return;
                }

                printf("\n\nO animal foi adotado ?\n\n"
                       " |1.Sim                \n"
                       " |2.N�o                \n"
                       "\nEscolher: ");

                scanf("%d",&es1);

                // Guarda o animal adotado e deletado
                if(es1 == 1 || es1 == 2)
                        {
                            //passa as informacoes de uma struct para outra

                            strcpy(novo3 -> nome,(*inicio)->nome);
                            strcpy(novo3 -> especie,(*inicio)->especie);
                            strcpy(novo3 -> raca,(*inicio)->raca);
                            strcpy(novo3 -> sexo,(*inicio)->sexo);
                            strcpy(novo3 -> cg,(*inicio)->cg);
                            novo3 -> idade = (*inicio)->idade;
                            novo3 -> id = (*inicio)->id;
                            if(es1 == 1) novo3 -> con = (*inicio)->con+1;
                            if(es1 == 2) novo3 -> con = (*inicio)->con+2;

                            //adiciona no a lista de adotados

                            novo3 -> prox = (*inicio3);
                            (*inicio3) = novo3;
                            //(*inicio3) = (*inicio3)->condicao;
                        }
                if(es == 1)
                {
                    system("cls");
                    //deleta o primeiro no da lista
                    if(cont == 0)
                    {
                        //ZERA a quantidade da especie
                        while((*inicio2)!=NULL)
                        {
                            if(ret = strcmp((*inicio2)->rn,(*inicio)->especie)==0)
                            {
                                (*inicio2)->cont = ((*inicio2)->cont)-1;
                                break;
                            }
                            (*inicio2)=(*inicio2)->prox;
                        }
                        //deleta ANIMAL na struct
                        oldinicio = (*inicio);
                        aux = (*inicio);
                        (*inicio)=(*inicio)->prox;
                        free(aux);
                        break;
                    }
                    //deleta no do meio e final da lista
                    if(cont > 0 && (*inicio)->id == id)
                    {
                        while((*inicio2)!=NULL)
                        {
                            if(ret = strcmp((*inicio2)->rn,(*inicio)->especie)==0)
                            {
                                (*inicio2)->cont = ((*inicio2)->cont)-1;
                                break;
                            }
                            (*inicio2)=(*inicio2)->prox;
                        }

                        printf("entrou");

                        aux = (*inicio);

                        (*inicio)= no_ant;
                        (*inicio)->prox = no_prox;

                        free(aux);
                        break;
                    }
                }
            }
             no_ant = (*inicio);
            (*inicio)=(*inicio)->prox;

            //contador para realizar a contagem em qual posicao o no esta
            cont++;
    }
    //caso nao for o primeiro,voltaremos a lista no inicio
    if(cont > 0)
    {
        (*inicio)=oldinicio;
    }

    (*inicio2)=oldinicio2;
    //inicio da lista e realocado novamente para o valor do come�o
}

void cores()
{
    system("cls");

    int es,cor;

    printf("\n\n > | 1.Mudar cor de letra |");
    //printf("\n   | 2.Mudar cor de letra |");
    printf("\n\nEscolha:");
    scanf("%d",&es);

    //escolha de cor
    if(es == 1)
    {
        printf("-----------------------------------------\n"
               "0 = Preto        8 = Cinza\n"
               "1 = Azul         9 = Azul claro\n"
               "2 = Verde        10 = Verde claro\n"
               "3 = Verde-�gua   11 = Verde-�gua claro\n"
               "4 = Vermelho     12 = Vermelho claro\n"
               "5 = Roxo         13 = Lil�s\n"
               "6 = Amarelo      14 = Amarelo claro\n"
               "7 = Branco\n"
               "-----------------------------------------\n\nEscolha:");
                scanf("%d",&cor);

               if(cor==0) system("COLOR F0");
               if(cor==1) system("COLOR F1");
               if(cor==2) system("COLOR F2");
               if(cor==3) system("COLOR F3");
               if(cor==4) system("COLOR F4");
               if(cor==5) system("COLOR F5");
               if(cor==6) system("COLOR F6");
               if(cor==7) system("COLOR F7");
               if(cor==8) system("COLOR F8");
               if(cor==9) system("COLOR F9");
               if(cor==10) system("COLOR FA");
               if(cor==11) system("COLOR FB");
               if(cor==12) system("COLOR FC");
               if(cor==13) system("COLOR FD");
               if(cor==14) system("COLOR FE");
               if(cor==15) system("COLOR FF");
    }

    system("cls");
}

void listagem_animais_adotados(no *inicio3)
{
    system("cls"); //Limpa tela

    if(inicio3 == NULL)
    {
      printf("\n Nenhum animal cadastrado\n\n");
    }
    else
    {
        printf("\n> Listagem de animais\n");
        while(inicio3 != NULL)
        {
            printf("\n Nome: %s\n",inicio3->nome);
            printf(" Esp�cie: %s\n",inicio3->especie);
            printf(" Ra�a: %s\n",inicio3->raca);
            printf(" Sexo: %s\n",inicio3->sexo);
            printf(" Idade: %d\n",inicio3->idade);
            printf(" Caracter�sticas gerais : %s\n",inicio3->cg);
            printf(" id: %d\n",inicio3->id);
            if (inicio3->con == 1) printf("\n\n Condi��o: Adotado");
            if (inicio3->con == 2) printf("\n\n Condi��o: Exluido");
            printf("\n------------------------------------------\n");


            inicio3 = inicio3 -> prox;
        }
    }
    system("pause");
    system("cls");
}

void procura_adotados(ad *inicio3)
{
    char raca[50],especie[50],letra,sexo[02],nome[50],condicao[50]="Adotado";
    int  ret1=9,ret=9,ret3=9,ret4=9,cont=0,m=3,escolha=99;

    //pesquisar pelo nome,sexo,raca e especie de animal
    //realiza a leitura

    printf("\nNome: ");
    fflush(stdin);
    gets(nome);
    letra = toupper(nome[0]);
    nome[0] = letra;

    printf("Sexo: ");
    fflush(stdin);
    gets(sexo);
    letra = toupper(sexo[0]);
    sexo[0] = letra;

    printf("Ra�a: ");
    fflush(stdin);
    gets(raca);
    letra = toupper(raca[0]);
    raca[0] = letra;

    printf("Especie do animal: ");
    fflush(stdin);
    gets(especie);
    letra = toupper(especie[0]);
    especie[0] = letra;

    system("cls");
    printf("\n\n |  Resultados de busca  | \n\n\n");

    //percorre a lista para ver se tem animais com os dados pesquisados
    while(inicio3 != NULL)
    {
        //verifica a saida do ret, que serve para comparar string
        ret = strcmp(inicio3->especie,especie);
        ret1 = strcmp(inicio3->raca,raca);
        ret3 = strcmp(inicio3->sexo,sexo);
        ret4 = strcmp(inicio3->nome,nome);
        //mostra informacoes de pet caso for encontrado
            if(ret == 0 && ret1 == 0 && ret3 == 0 && ret == 0);
            {
                printf("\n Nome: %s\n",inicio3->nome);
                printf(" Esp�cie: %s\n",inicio3->especie);
                printf(" Ra�a: %s\n",inicio3->raca);
                printf(" Sexo: %s\n",inicio3->sexo);
                printf(" Idade: %d\n",inicio3->idade);
                printf(" Caracter�sticas gerais : %s\n",inicio3->cg);
                printf(" ID:%d",inicio3->id);
                printf("\n----------------------------------------\n");
                //cont ++;
            }
            inicio3 = inicio3 -> prox;
    }
    system("pause");
    system("cls");

}

void reinserir_animal(no **inicio, ad **inicio3)
{
    int id,es=0,cont=0;
    ad *novo3 = malloc(sizeof(ad));

    //pesquisa ID
    printf("\nProcurar id: ");
    scanf("%d",&id);

    ad *aux = malloc(sizeof(ad));

    ad *oldhead = malloc(sizeof(ad));

    ad *no_prox = malloc(sizeof(ad));
    ad *no_ant = malloc(sizeof(ad));

    //guarda inicio lista
    oldhead = (*inicio3);

    //procura pet por ID
    while((*inicio3)!=NULL)
    {
        no_prox = (*inicio3)->prox;

        system("cls");
        if((*inicio3)->id == id)
        {
            printf("\n Nome: %s\n",(*inicio3)->nome);
            printf(" Esp�cie: %s\n",(*inicio3)->especie);
            printf(" Ra�a: %s\n",(*inicio3)->raca);
            printf(" Sexo: %s\n",(*inicio3)->sexo);
            printf(" Idade: %d\n",(*inicio3)->idade);
            printf(" Caracter�sticas gerais : %s\n",(*inicio3)->cg);
            printf(" ID:%d",(*inicio3)->id);
            if ((*inicio3)->con == 1) printf("\n\n Condi��o: Adotado");
            if ((*inicio3)->con == 2) printf("\n\n Condi��o: Exluido");

            printf("\n----------------------------------------\n");

            //verifica condicao e mostra para o usuario

            printf("\n|1.Realocar animal\n");
            printf("|2.N�o realocar\n");
            printf("\nEscolha:");

            scanf("%d",&es);

            //realoca para lista lista principal
            if(es == 1)
            {
            //Passa para um NO novo3, para n causar erros

                strcpy(novo3 -> nome,(*inicio3)->nome);
                strcpy(novo3 -> especie,(*inicio3)->especie);
                strcpy(novo3 -> raca,(*inicio3)->raca);
                strcpy(novo3 -> sexo,(*inicio3)->sexo);
                strcpy(novo3 -> cg,(*inicio3)->cg);
                novo3 -> idade = (*inicio3)->idade;
                novo3 -> id = (*inicio3)->id;
                novo3 -> con = 0;

                novo3 -> prox = (*inicio);
                (*inicio) = novo3;

                //DELETA NO do pet que foi REALOCADO
                if(cont == 0)
                {
                    (*inicio3) = (*inicio3)->prox;
                    aux = (*inicio3);
                    free(aux);
                    return;
                }
                //se for um NO do meio ou fim
                if(cont > 0)
                {
                    aux = (*inicio3);
                    (*inicio3)= no_ant;
                    (*inicio3)->prox = no_prox;
                    free(aux);
                }
            }
            if(es == 2) return;

            system("pause");
            system("cls");
        }
        no_ant = (*inicio3);

        (*inicio3)=(*inicio3)->prox;

        cont++;
    }
    (*inicio3) = oldhead;
    system("cls");
}
