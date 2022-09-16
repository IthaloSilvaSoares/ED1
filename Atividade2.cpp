/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include<stdio.h>

typedef int dado;

struct Node {

    dado valor;
    Node *prox;

    Node() {
        prox = NULL;
    }

    Node(dado _valor) {
        valor = _valor;
        prox = NULL;
    }

    void print() {
        printf("%d -> ", valor);
    }

};

struct List {

    Node *cabeca, *cauda;
    int size;

    List() {
        cabeca = NULL;
        cauda = NULL;
        size = 0;
    }

    /*
        empty = testa se a lista está vazia ou não
        size = retorna o tamanho da lista
        pushFront = insere no inicio
        pushBack = insere no final
        popFront = remove no inicio
        popBack = remove no final
    */

    bool empty() { //O(1)
        return (cabeca == NULL) && (cauda == NULL);
    }

    Node* pushBack(dado valor) { //O(1)
        Node *novo = new Node(valor);
        if (empty()) {
            cabeca = novo;
            cauda = novo;
        } else {
            cauda->prox = novo;
            cauda = novo;
        }
        size++;
        return cauda;
    }

    Node* pushFront(dado valor) { //O(1)
        Node *novo = new Node(valor);
        if (empty()) {
            cabeca = novo;
            cauda = novo;
        } else {
            novo->prox = cabeca;
            cabeca = novo;
        }
        size++;
        return cabeca;
    }

    /*int size() { //O(n)
        int s = 0;
        Node *tmp = cabeca;
        while (tmp != NULL) {
            s++;
            tmp = tmp->prox;
        }
        return s;
    }*/

    void print() { //O(n)
        Node *tmp = cabeca;
        while (tmp != NULL) {
            tmp->print();
            tmp = tmp->prox;
        }
        printf("\n");
    }

    Node* popFront() { //O(1)
        if (!empty()) {
            if (cabeca == cauda) { // Apenas 1 elemento
                delete(cabeca);
                cabeca = NULL;
                cauda = NULL;
            } else {
                Node *tmp = cabeca;
                cabeca = cabeca->prox;
                delete(tmp);
            }
            size--;
        }
        return cabeca;
    }

    Node* popBack() { //O(n)
        if (!empty()) {
            if (cabeca == cauda) {
                delete(cabeca);
                cabeca = NULL;
                cauda = NULL;
            } else {
                Node *penultimo = cabeca;
                while (penultimo->prox != cauda) {
                    penultimo = penultimo->prox;
                }
                delete(cauda);
                cauda = penultimo;
                cauda->prox = NULL;
            }
            size--;
        }
        return cauda;
    }

    Node* find(dado x) { //O(n)
        Node *tmp = cabeca;
        while (tmp != NULL) {
            if (tmp->valor == x) {
                return tmp;
            }
            tmp = tmp->prox;
        }
        return NULL;
    }
    
    
/*
    void deleta_final(int num)
    {
        if(size<num)
        {
            while(!empty())
            {
                popBack();
            }
        }
        else
        {
            for(int i=0; i<num; i++)
            {
                popBack();
            }
        }
    }
    /*
    void deleta_item(int num)   //O(n)
    {
        if(num>1)
        {
            Node *tmp = cabeca;
            Node *tmp2;
            int tam=1;
            while (tmp != NULL)
            {
                if(tam==num)
                {
                    tmp2->prox = tmp->prox;
                    delete(tmp);
                    break;
                }
                ++tam;
                tmp2=tmp;
                tmp = tmp->prox;
            }
        }
    }
    /*
    void inclui_tamanho_final(int num)
    {
        pushBack(num);
    }
    /*
    void inclui_sequencia(int num)
    {
        for(int i=1; i<=num; ++i)
        {
            pushBack(i);
        }
    }
    /*

    void addValorPosicao(dado valor,int posi)//O(n)
    {
        Node *tmp = cabeca->prox;
        bool controller = false;
        int aux=1;
        if(posi>2&&posi<size)
        {
            while (controller == false)
            {
                aux++;
                if(aux==(size-(size-posi+1)))
                {
                    //printf("\n----%d\n",(size-(size-posi+1)));
                    Node* novo = new Node(valor);
                    novo->prox = tmp->prox;
                    tmp->prox = novo;
                    controller = true;
                }
                else
                {
                    tmp = tmp->prox;
                }
            }
        }
    }
    
*/
};

int main() {
    List l;
    int num;
    //List l;
    scanf("%d",&num);
    
    /*l.pushBack(50);
    l.pushBack(30);
    l.pushBack(10);
    l.pushFront(20);
    l.pushFront(10);
    l.popFront();
    l.popFront();
    l.popBack();
    l.popFront();
    l.popFront();
    l.popFront();
    l.popFront();
    l.popFront();
    l.popFront();
    l.print();
    printf("%d\n", l.size);*/
    

    //(questão 1) l.deleta_final(num);

    //(questão 2) l.deleta_item(2);

    //(questão 3) l.inclui_tamanho_final(l.size);
    
    //(questão 4) l.inclui_sequencia(10);

    //(questão 5) l.addValorPosicao(99,num);
    //(questão 6) l.deleta_item(num);


    l.print();
    printf("%d\n", l.size);
    
    return 0;
}