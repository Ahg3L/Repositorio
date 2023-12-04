#include "Libreria.h"

struct nodo {
    int dato;
    nodo *izq;
    nodo *der;
    int altura; 
};

int altura(nodo *n) {
    if (n==NULL) {
        return 0;
    }
    return n->altura;
}

int maximo(int a,int b) {
    return (a>b)?a:b;
}

nodo *crear(int n){
    nodo *nuevo=new nodo();
    nuevo->dato=n;
    nuevo->izq=NULL;
    nuevo->der=NULL;
    nuevo->altura = 1;
    return nuevo;
}

int obtenerBalance(nodo *n){
    if (n ==NULL) {
        return 0;
    }
    return altura(n->izq)- altura(n->der);
}

nodo *rotarDerecha(nodo *y){
    nodo *x=y->izq;
    nodo *T2=x->der;
    x->der=y;
    y->izq=T2;

    
    y->altura=maximo(altura(y->izq),altura(y->der))+ 1;
    x->altura=maximo(altura(x->izq),altura(x->der))+ 1;
    return x;
}

nodo *rotarIzquierda(nodo *x){
    nodo *y=x->der;
    nodo *T2= y->izq;
    
    y->izq = x;
    x->der = T2;

    x->altura=maximo(altura(x->izq),altura(x->der))+1;
    y->altura=maximo(altura(y->izq),altura(y->der))+1;
    return y;
}

nodo *insertarEnAVL(nodo *raiz, int dato) {
    if (raiz==NULL){
        return crear(dato);
    }
    if(dato < raiz->dato){
        raiz->izq=insertarEnAVL(raiz->izq,dato);
    } else if (dato>raiz->dato) {
        raiz->der = insertarEnAVL(raiz->der,dato);
    } else {
        return raiz;
    }

    raiz->altura = 1 + maximo(altura(raiz->izq), altura(raiz->der));
    int balance = obtenerBalance(raiz);

    if (balance>1 && dato<raiz->izq->dato) {
        return rotarDerecha(raiz);
    }
    if (balance<-1 && dato>raiz->der->dato) {
        return rotarIzquierda(raiz);
    }

    if (balance>1 && dato>raiz->izq->dato) {
        raiz->izq=rotarIzquierda(raiz->izq);
        return rotarDerecha(raiz);
    }

    if (balance<-1 && dato<raiz->der->dato) {
        raiz->der =rotarDerecha(raiz->der);
        return rotarIzquierda(raiz);
    }
    return raiz;
}

void mostrar(nodo *arbol, int cont) {
    if (arbol==NULL) {
        return;
    } else{
        mostrar(arbol->der,cont+1);
        for (int i= 0; i<cont;i++) {
            cout << "  ";
        }
        cout << arbol->dato << " (" << arbol->altura << ")" << endl;
        mostrar(arbol->izq, cont + 1);
    }
}

void menu(nodo *&arbol) {
    int cont = 0;
    int opc;
    
    do {
        system("cls");
        cout << "\tMENU" << endl;
        cout << "1.-Ingresar un nodo." << endl;
        cout << "2.-Mostrar." << endl;
        cout << "3.-Salir." << endl;

        opc = ingresar(3);

        switch (opc) {
            case 1:
                system("cls");
                cout << "Ingresa el dato que quieres ingresar : ";
                arbol= insertarEnAVL(arbol, ingresar(1000));
                system("pause");
                break;
            case 2:
                system("cls");
                mostrar(arbol, cont);
                system("pause");
                break;
            case 3:
                break;
        }
    } while (opc!=3);
}

int main() {
    nodo *arbol = NULL;
    menu(arbol);
    return 0;
}
