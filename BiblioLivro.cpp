#include <stdio.h>
#include <stdlib.h>

struct Livro{
    char titulo[100], autor[100];
    int numP;
    int total;

    void ler(){
        printf("Digite o titulo: ");
        scanf("%[^\n]%*c", titulo);
        printf("Digite o autor: ");
        scanf("%[^\n]%*c", autor);
        printf("Digite o numero de paginas: ");
        scanf("%d%*c", &numP);
    }

    void imprimir(){
        printf("Titulo: %s\n", titulo);
        printf("Autor: %s\n", autor);
        printf("Paginas: %d\n", numP);
    }
};

struct Biblioteca{
    Livro livros[10];
    int quant;
    int total;
    int maior;

    void resetLivro(){
        quant = 0;
    }

    void ler(){
        printf("Digite a quantidade de livros: ");
        scanf("%d%*c", &quant);
        if(quant > 10){
            printf("Desculpe o limite de livros nessa biblioteca eh 10");
            exit(1);
        }

        for (int i = 0; i < quant; i++){
            livros[i].ler();
        }
    }

    void imprimirTotalLivros(){
        printf("\nTotal de livros: %d\n", quant);
        for(int i = 0; i < quant; i++){
            printf("%s\n", livros[i].titulo);
       //     livros[i].imprimir();
        }
       // printf("Todos os livros: \n", total); ja que n usou a variavel total n é preciso.
    }

    void totalLivros(){
        total = 0;
        for(int i = 0; i < quant; i++){
            livros[i].total = livros[i].numP;
            total += livros[i].numP;
        }
    }

    void numPag(){
        maior = 0;
        for (int i = 0; i < quant; i++){
            if (livros[i].numP > livros[maior].numP){
                maior = i;
            }
        }
    }

    void imprimirMaiorPagina(){
        printf("\nLivro com mais paginas: \n");
        livros[maior].imprimir();
    }


};

int main(){
    Biblioteca biblioteca;
    biblioteca.ler();
    biblioteca.totalLivros();
    biblioteca.numPag();
    biblioteca.imprimirTotalLivros();
    biblioteca.imprimirMaiorPagina();

    return 0;
}

//TAD = struct diferente
// dentro da struct de biblioteca ter uma funcao para começar com 0

// Venda(){
//  qtd = 0;
//  total = 0;
//}
