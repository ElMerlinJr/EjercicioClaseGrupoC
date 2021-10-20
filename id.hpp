#include <iostream>
#include <string>
using namespace std;

struct GenLista{
    string na;
    int id;
};

GenLista solicitarGenList(void){
    GenLista gl;
    cout << "Ingrese el Id: ";
    cin >> gl.id; cin.ignore();
    cout << "(Nota: En su perfil ingrese si usted es administrador, cliente o trabajador)" << endl;
    cout << "Ingrese nombre, apellido y perfil: ";
    getline(cin, gl.na);
    return gl;
}

void mostrarPelicula(GenLista gl){
    cout << " (" << gl.id << ") ";
    cout << "Nombres y Apellidos: " << gl.na << endl;
}

typedef GenLista T;
const T noValido = {"",0};

struct nodo{
    T dato;
    nodo *sig;
    nodo *ant;
};

class ListaDoble{
    private:
        nodo *pInicio;
    public:
        ListaDoble();
        ~ListaDoble();
        void insertFront(T);
        void insertBack(T);
        void traversalForwardDirection(void);
        void traversalReverseDirection(void);
};

ListaDoble::ListaDoble(void){
    pInicio = NULL;
}

ListaDoble::~ListaDoble(void){
    nodo *p;
    while(pInicio){
        p = pInicio;
        pInicio = pInicio->sig;
        delete p;
    }
}

void ListaDoble::insertFront(T dato){
    nodo *nuevo = new nodo;
    nuevo->dato = dato;
    nuevo->sig = pInicio;
    if(pInicio != NULL)
        pInicio->ant = nuevo;
    pInicio = nuevo;
}

/*void ListaDoble::insertBack(T dato){
    nodo *nuevo = new nodo;
    nuevo->dato = dato;
    if(!pInicio){
        pInicio = nuevo;
        pInicio->sig = pInicio->ant = NULL;
    }
    else{
        nodo *saltarin = pInicio;
        while(saltarin->sig != NULL)
            saltarin = saltarin->sig;
        saltarin->sig = nuevo;
        nuevo->ant = saltarin;
        nuevo->sig = NULL;
    }
}*/

/*void ListaDoble::traversalForwardDirection(void){
    nodo *saltarin = pInicio;
    while(saltarin != NULL){
        mostrarPelicula(saltarin->dato);
        saltarin = saltarin->sig;
    }
}*/

void ListaDoble::traversalReverseDirection(void){
    if(!pInicio)
        return;
    nodo *p = pInicio;
    nodo *q = NULL;
    while(p){
        q = p;
        p = p->sig;
    }
    while(q){
        mostrarPelicula(q->dato);
        q = q->ant;
    }
}