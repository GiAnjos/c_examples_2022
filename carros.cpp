// Veículos
#include <iostream>
#include <string.h>
#include <cctype>

using namespace std;

struct veiculo {
    char marca[11];
    char modelo[21];
    int ano;
    char placa[9];
};

void lista(veiculo veic) {
        cout << veic.marca << "\n";
        cout << veic.modelo << "\n";
        cout << veic.ano << "\n";
        cout << veic.placa << "\n\n";
}

veiculo ler_dados(){
        veiculo temp;
        cout << "\n\n Marca do veiculo:  ";
        cin >> temp.marca;
        cout << "\n Modelo do veiculo.:  ";
        cin >> temp.modelo;
        cout << "\n Ano de fabricacao.:  ";
        cin >> temp.ano;
        cout << "\n Placa do veiculo (XXX-9999):  ";
        cin >> temp.placa;
        return(temp);
}

int main() {
    int op = 9;
    veiculo veic[10];
    veiculo temp;
    char modelo[21];
    int tot = 0;
    int ano, v;

    while (op != 0) {
        // Menu
        cout << " Cadastro de veiculos\n\n";
        cout << "\n" << "  1 - Inserir";
        cout << "\n" << "  2 - Listar todos";
        cout << "\n" << "  3 - Listar por ano";
        cout << "\n" << "  4 - Listar a partir de um ano";
        cout << "\n" << "  5 - Listar por modelo";
        cout << "\n\n" << "  0 - Sair\n\n  > ";
        cin >> op;
        if (op < 0 || op > 5) {
            cout << "Escolha invalida.";
            // Aguarda 2 segundos antes de limpar a tela
            // >nul evita a mensagem padrão do timeout
            system("timeout /t 2 /nobreak >nul");
            system("cls");
        }
        system("cls");
        switch(op) {
            case 1:
                if (tot >= 10) {
                    cout << "\n Cadastro cheio. \n";
                    break;
                }
                temp = ler_dados();
                // Inserção ordenada
                if (tot == 0){
                    veic[tot] = temp;
                }
                else {
                    for (v = 0; v < tot; v++) {
                        if (veic[v].ano > temp.ano) {
                            break;
                        }
                    }
                    for (int i = tot; i > v; i--){
                        veic[i] = veic[i-1];
                    }
                    veic[v] = temp;
                }
                cout << " Veiculo inserido: \n";
                lista(temp);
                tot++;
                system("pause");
                system("cls");
                break;
            case 2:
                for (int i=0; i<tot; i++) {
                    lista(veic[i]);
                }
                system("pause");
                system("cls");
                break;
            case 3:
                cout << "Digite o ano: ";
                cin >> ano;
                for (int i=0; i<tot; i++) {
                    if (veic[i].ano == ano) {
                        lista(veic[i]);
                    }
                }
                system("pause");
                system("cls");
                break;
            case 4:
                cout << "Digite o ano: ";
                cin >> ano;
                for (int i=0; i<tot; i++) {
                    if (veic[i].ano >= ano) {
                        lista(veic[i]);
                    }
                }
                system("pause");
                system("cls");
                break;
            case 5:
                cout << "Digite o modelo: ";
                cin >> modelo;
                for (int i=0; i<tot; i++) {
                    if (strcmp(veic[i].modelo, modelo) == 0) {
                        lista(veic[i]);
                    }
                }
                system("pause");
                system("cls");
                break;
            case 0:
                cout << "Saindo... \n\n";

        }
    }
}
