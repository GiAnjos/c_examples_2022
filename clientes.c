// Clientes
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct cliente {
    char nome[31];
    int nasc;
    float montante;
};

// Limpaza do buffer do teclado
void limpabuffer(void){
	char c;
	while ((c = getchar()) != '\n' && c != EOF);
}

struct cliente ler_dados() {
    struct cliente temp;
    limpabuffer();
    printf("\n\n Nome ........... : ");
    scanf("%s", temp.nome);
    printf("\n Ano de nascimento: ");
    scanf("%d", &temp.nasc);
    printf("\n Montante do mes..: ");
    scanf("%f", &temp.montante);
    return temp;
}

void lista_cliente(struct cliente cli)  {
    printf("\n\n Nome....: %s", cli.nome);
    printf("\n Nasc....: %d", cli.nasc);
    printf("\n Montante: %.2f", cli.montante);
    printf("\n\n");
}

int main() {

    int op = 9;
    int tot = 0;    //total de clientes
    int tam = 10;   //tamanho do vetor
    char rem[31];
    int pos;
    float maior;
    struct cliente temp;

    // alocação inicial de espaço
    struct cliente *clientes;
    clientes = (struct cliente*)malloc(10 * sizeof(struct cliente));
    if (clientes == NULL) {
        printf("Erro de alocação!");
        return 1;
    }

    while (op != 0) {
        // Menu
        printf(" Cadastro de clientes\n\n");
        printf("\n 1 - Incluir");
        printf("\n 2 - Remover");
        printf("\n 3 - Zerar montantes");
        printf("\n 4 - Melhor cliente");
        printf("\n 5 - Exibir montante de cliente");
        printf("\n 6 - Listar todos clientes");
        printf("\n\n 0 - Sair\n\n  > ");
        scanf("%d", &op);
        if (op < 0 || op > 6) {
            printf("Escolha invalida.\n\n");
            // Aguarda 2 segundos antes de limpar a tela
            // >nul evita a mensagem padrão do timeout
            system("timeout /t 2 /nobreak >nul");
            system("cls");
        }
        system("cls");

        switch(op) {
            case 1:
                if (tot >= tam) {
                    // Aumento do tamanho do vetor clientes
                    clientes = (struct cliente*)realloc(clientes, 10 * sizeof(struct cliente));
                    if (clientes == NULL) {
                        printf("Erro de alocação!");
                        return 1;
                    }
                    tam = tam + 10;
                }

                temp = ler_dados();
                clientes[tot] = temp;
                tot++;
                system("pause");
                system("cls");
                break;
            case 2:
                pos = -1;
                printf("\n Digite o nome a ser removido: ");
                limpabuffer();
                scanf("%s", rem);
                for (int i = 0; i < tot; i++) {
                    if ( strcmp(clientes[i].nome, rem) == 0) {
                        pos = i;
                    }
                }
                if (pos == -1) {
                    printf("\n Cliente não encontrado. \n");
                    break;
                }
                else {
                    for (int i = pos; i < tot; i++) {
                        clientes[i] = clientes[i+1];
                    }
                    tot--;
                    printf("\n Cliente removido: %s \n", rem );
                }
                system("pause");
                system("cls");
                break;
            case 3:
                for (int i = 0; i < tot; i++) {
                    clientes[i].montante = 0;
                }
                system("pause");
                system("cls");
                break;
            case 4:
                maior = clientes[0].montante;
                pos = 0;
                for (int i = 1; i < tot; i++) {
                    if (clientes[i].montante > maior) {
                        maior = clientes[i].montante;
                        pos = i;
                    }
                }
                printf("\n\n Melhor cliente:\n");
                printf("\n Nome: %s", clientes[pos].nome);
                printf("\n Montante: %.2f\n", clientes[pos].montante);
                system("pause");
                system("cls");
                break;
            case 5:
                pos = -1;
                printf("\n Digite o nome a ser exibido: ");
                limpabuffer();
                scanf("%s", rem);
                for (int i = 0; i < tot; i++) {
                    if ( strcmp(clientes[i].nome, rem) == 0) {
                        pos = i;
                    }
                }
                if (pos == -1) {
                    printf("\n Cliente não encontrado. \n");
                    break;
                }
                else {
                    lista_cliente(clientes[pos]);
                }
                system("pause");
                system("cls");
                break;
            case 6:
                for (int i=0; i < tot; i++ ) {
                    lista_cliente(clientes[i]);
                }
                system("pause");
                system("cls");
                break;
            case 0:
                printf("Saindo... \n\n");
                break;
        }
    }
    free(clientes);
    return 0;
}

