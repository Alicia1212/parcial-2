#include <iostream>

using namespace std;

struct nodo{
    int dato;
    nodo *ant;
    nodo *sig;
};

class ListaDoble{
    private:
        nodo *pInicio;
        nodo *pFinal;
    
    public:
        ListaDoble();
        ~ListaDoble();
        void insertarEnLista(void);
        void mostrarLista(void);
        void insertarAntesDeElemento(int, int); // Función a elaborar.
        void buscarRec(int);
        bool buscarRecAux(nodo *, int); // Función a elaborar.
        void sumaypromedio(void); // Función a elaborar.
};

ListaDoble::ListaDoble(void)
{
    pInicio = NULL;
    pFinal = NULL;
}

ListaDoble::~ListaDoble(void)
{
    nodo *p;

    while(pInicio){
        p = pInicio;
        pInicio = pInicio->sig;
        delete p;
    }
}

void ListaDoble::insertarEnLista(void)
{
    int dato, datoRef;

    cout << "Digite un entero o Ctrl-Z para terminar: ";
    while(cin >> dato){
        cout << "Digite el elemento antes del cual insertara: ";
        cin >> datoRef;
        insertarAntesDeElemento(dato, datoRef);
        cout << "Digite un entero o Ctrl-Z para terminar: ";
    }
}

// ESCRIBA AQUÍ LA FUNCIÓN DE INSERTAR NODOS ANTES DE UN ELEMENTO DETERMINADO:
void ListaDoble::insertarAntesDeElemento(int dato, int datoRef) {
    nodo *nuevo = new nodo;
    nodo *fin = new nodo;
    nuevo->dato = dato;

    if(!pInicio){                           
        pInicio = nuevo;
        pInicio->sig = NULL;
        pInicio->ant = NULL;
    }
    else
        if(pInicio->dato == datoRef){       
            nuevo->ant = NULL;
            nuevo->sig = pInicio;     
            pInicio = nuevo;
        }
       else{                                 
            nodo *aux = pInicio;            
            while(aux->sig && aux->sig->dato != datoRef){
                aux = aux->sig;
            }
            if(aux){
            nuevo->sig = aux->sig;
            aux->sig = nuevo;
            nuevo->ant = aux;
            }
            else{
                nuevo->sig = NULL;
                nuevo->ant = NULL;
            }
        }
}

void ListaDoble::mostrarLista(void)
{
    nodo *p;
    cout << "Los elementos de la lista son:" << endl;
    p = pInicio;
    while(p->sig){
        cout << p->dato << endl;
        p = p->sig;
    }
    while(p->ant){
        cout << p->dato << endl;
        p = p->ant;
    }
    cout << "Fin de mostrar lista" << endl;
}

void ListaDoble::buscarRec(int datoB)
{
    if(buscarRecAux(pInicio, datoB))
        cout << "Si lo encontre" << endl;
    else
        cout << "No lo encontre" << endl;
}

// ESCRIBA AQUÍ LA FUNCIÓN DE BÚSQUEDA RECURSIVA:
bool ListaDoble::buscarRecAux(nodo *p, int datoB) {
    if (p && p->dato != datoB)
        buscarRecAux(p->sig, datoB);
    else if (p)
        return true;
    else
        return false;
}


// ESCRIBA AQUÍ LA FUNCIÓN QUE CALCULA LA SUMA Y EL PROMEDIO:
void ListaDoble::sumaypromedio(void) {
    nodo *aux;
    aux = pInicio;
    int contador = 0;
    float suma = 0, promedio = 0; 

    while (aux) {
        suma += aux->dato;
        aux = aux->sig;
        contador++;
    }
    promedio = suma/contador;

    cout << "\nLa Suma es: " << suma << endl;
    cout << "El promedio es: " << promedio << endl;
}


int main(void)
{
    ListaDoble objListaDoble;

    cout << endl;
    cout << "PROGRAMA DEL SEGUNDO EXAMEN PARCIAL" << endl << endl;

    cout << "Insercion de datos en la lista:" << endl;
    objListaDoble.insertarEnLista();

    objListaDoble.mostrarLista();

    cin.clear();
    int datoB;
    cout << "Que dato desea buscar? ";
    cin >> datoB;
    objListaDoble.buscarRec(datoB);

    objListaDoble.sumaypromedio();
    
    cout << endl;
    return 0;
}
