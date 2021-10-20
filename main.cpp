#include "id.hpp"

int menu(){
    int opcion = 0;
    cout << endl << "\tLista de perfiles" << endl << endl;
    cout << "1) Agregar una id, nombre, apellido y perfil." << endl;
    /*cout << "2) Agregar una secuela." << endl;*/
    cout << "2) Mostrar lista." << endl;
    /*cout << "4) Mostrar saga de fin a inicio." << endl;*/
    cout << "3) Salir." << endl;
    cout << "Opcion: ";
    cin >> opcion; cin.ignore();
    return opcion;
}

int main(void){
    ListaDoble list;
    
    bool continuar = true;
    GenLista gl;
    do{
        switch(menu()){
            case 1:
                gl = solicitarGenList();
                list.insertFront(gl);
                cout << "Datos almacenados exitosamente!" << endl;
                break;
            /*case 2:
                gl = solicitarGenList();
                list.insertBack(p);
                cout << "Datos almacenados exitosamente!" << endl;
                break;*/
            /*case 2:
                list.traversalForwardDirection();
                break;*/
            case 2:
                cout << endl;
                list.traversalReverseDirection();
                break;
            case 3:
                continuar = false;
                break;
            default:
                cout << "La opcion no es valida, favor intente denuevo." << endl;
                break;
        }
    }while(continuar);
    
    return 0;
}