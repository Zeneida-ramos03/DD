#include <iostream>
#include <cstring> 
using namespace std;

struct Producto {
    int id;
    char nombre[30];
};

Producto* productos = nullptr; 
int capacidad = 0; 
int cantidad = 0;  

void agregarProducto() {
    if (cantidad >= capacidad) {
        capacidad = (capacidad == 0) ? 1 : capacidad * 2; 
        Producto* temp = new Producto[capacidad];
        for (int i = 0; i < cantidad; i++) {
            temp[i] = productos[i];
        }
        delete[] productos;
        productos = temp;
    }

    cout << "ingrese el ID del producto: " << endl;
    cin >> productos[cantidad].id;
    cout << "ingrese el nombre del producto: " << endl;
    cin.ignore(); 
    cin.getline(productos[cantidad].nombre, 30);
    cantidad++;
    cout << "el producto fue agregado correctamente!" << endl;
    cout << endl;
}

void mostrarProductos() {
    if (cantidad == 0) {
        cout << "No hay productos registrados." << endl;
        return;
    }

    cout << "lista de los  productos:" << endl;
    for (int i = 0; i < cantidad; i++) {
        cout << "ID: " << productos[i].id << ", Nombre: " << productos[i].nombre << endl;
    }
    cout << endl;
}

void buscarProducto() {
    int id;
    if (cantidad == 0) {
        cout << "no hay registro de productos." << endl;
        return;
    }
    cout << "ingrese el ID del producto a buscar: " << endl;
    cin >> id;

    for (int i = 0; i < cantidad; i++) {
        if (productos[i].id == id) {
            cout << "el producto fue encontrado:" << endl;
            cout << "ID: " << productos[i].id << ", Nombre: " << productos[i].nombre << endl;
            return;
        }
    }
    cout << "el producto no fue encontrado." << endl;
    cout << endl;
}

void eliminarProducto() {
    int id;
    if (cantidad == 0) {
        cout << "no hay productos registrados." << endl;
        return;
    }
    cout << "ingrese el ID del producto que desea eliminar: " << endl;
    cin >> id;

    int pos = -1;
    for (int i = 0; i < cantidad; i++) {
        if (productos[i].id == id) {
            pos = i;
            break;
        }
    }

    if (pos == -1) {
        cout << "Producto no encontrado." << endl;
        return;
    }

    for (int i = pos; i < cantidad - 1; i++) {
        productos[i] = productos[i + 1];
    }
    cantidad--;
    cout << "Producto eliminado correctamente!" << endl;
}

void contarProductos() {
    cout << "cantidad de productos registrados: " << cantidad << "\n\n";
}

void modificarProducto() {
    int id;
    if (cantidad == 0) {
        cout << "no hay productos registrados." << endl;
        return;
    }
    cout << "ingrese el ID del producto que desea modificar: " << endl;
    cin >> id;

    for (int i = 0; i < cantidad; i++) {
        if (productos[i].id == id) {
            cout << "ingrese nuevo nombre del producto: " << endl;
            cin.ignore();
            cin.getline(productos[i].nombre, 30);
            cout << "nombre del producto actualizado correctamente!" << endl;
            return;
            cout << endl;
        }
    }
    cout << "Producto no encontrado." << endl;
}

void liberarMemoria() {
    if (productos != nullptr) {
        delete[] productos;
        productos = nullptr;
        cantidad = 0;
        capacidad = 0;
        cout << "la memoria se a liberado correctamente." << endl;
    }
}

int main() {
    int opcion;
    do {
        cout << "--bienvenido al menu--\n";
        cout << "1. agregar producto\n";
        cout << "2. mostrar productos\n";
        cout << "3. buscar producto\n";
        cout << "4. eliminar producto\n";
        cout << "5. contar productos\n";
        cout << "6. modificar producto\n";
        cout << "7. salir\n";
        cout << "ingrese una opcion: ";
        cin >> opcion;
        cout << endl;

        switch (opcion) {
        case 1: agregarProducto();
        break;
        case 2: mostrarProductos(); 
        break;
        case 3: buscarProducto(); 
        break;
        case 4: eliminarProducto();
        break;
        case 5: contarProductos(); 
        break;
        case 6: modificarProducto();
        break;
        case 7: liberarMemoria(); 
        cout << "saliendo del sistema" << endl;
        break;
        default: 
        cout << "opcion no valida. intente de nuevo." << endl;
        }
    } while (opcion != 7);

    return 0;
}