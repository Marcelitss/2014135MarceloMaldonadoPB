#include <iostream>
#include <conio.h>
#include <string.h>
#include <string>
#include <stdio.h>
#include <fstream>
#include <stdlib.h>
using namespace std;

struct Orden
{
    int numeroTicket;
    char nombreVendedor[100];
    char fecha[20];
    char articulos[50][50];
    int preciosArticulos[50];
    int totalArticulos;
    double precioUnitarioTotal;
    double descuentosOPromociones;
    double propina;
    double impuesto;
    double total;
};

Orden ordenes[100];

void mostrarMenu()
{
    printf("---- Restaurante Barry: Ordenes ----\n");
    printf("1. Alta de Orden\n");
    printf("2. Modificar Orden\n");
    printf("3. Eliminar o Cancelar Orden\n");
    printf("4. Lista de Ordenes\n");
    printf("5. Limpiar Pantalla\n");
    printf("6. Salir\n");
    printf("Ingrese su opcion: ");
}

void altaOrden()
{
    int menu;
    printf("Ingrese el numero de la orden: ");
    scanf_s("%d", &menu);
    menu--;

    if (menu >= 0 && menu < 100 && ordenes[menu].numeroTicket == 0)
    {
        ordenes[menu].numeroTicket = menu + 1;

        printf("Ingrese el nombre del vendedor: ");
        scanf_s(" %99[^\n]", ordenes[menu].nombreVendedor, 100);

        printf("Ingrese la fecha: ");
        scanf_s(" %19[^\n]", ordenes[menu].fecha, 20);

        printf("Ingrese la cantidad de articulos: ");
        scanf_s("%d", &ordenes[menu].totalArticulos);

        printf("Ingrese los nombres de los articulos:\n");
        for (int i = 0; i < ordenes[menu].totalArticulos; ++i)
        {
            printf("Articulo #%d: ", i + 1);
            scanf_s(" %49[^\n]", ordenes[menu].articulos[i], 50);

            printf("Precio de %s: ", ordenes[menu].articulos[i]);
            if (scanf_s("%d", &ordenes[menu].preciosArticulos[i]) != 1)
            {
                printf("Precio inválido.\n");
                while (getchar() != '\n');
                i--; //Para corregir 
            }
        }

        //precio total
        ordenes[menu].precioUnitarioTotal = 0;
        for (int i = 0; i < ordenes[menu].totalArticulos; ++i)
        {
            ordenes[menu].precioUnitarioTotal += ordenes[menu].preciosArticulos[i];
        }
        //propina 
        ordenes[menu].propina = ordenes[menu].precioUnitarioTotal * 0.15;

        //impuesto 
        ordenes[menu].impuesto = ordenes[menu].precioUnitarioTotal * 0.10;

        //suma de todo
        ordenes[menu].total = ordenes[menu].precioUnitarioTotal + ordenes[menu].impuesto - ordenes[menu].descuentosOPromociones + ordenes[menu].propina;

        printf("Orden agregada exitosamente.\n");
    }
    else
    {
        printf("Opción no válida.\n");
    }
}
void modificarOrden()
{
    int numeroTicketModificar;
    printf("Ingrese el numero de la orden a modificar: ");
    scanf_s("%d", &numeroTicketModificar);

    for (int i = 0; i < 100; ++i) {
        if (ordenes[i].numeroTicket == numeroTicketModificar)
        {
            printf("Orden encontrada. Se puede modificar:\n");
            printf("Ingrese el nuevo nombre: ");
            scanf_s(" %99[^\n]", ordenes[i].nombreVendedor, 100);

            printf("Ingrese la nueva fecha: ");
            scanf_s(" %19[^\n]", ordenes[i].fecha, 20);

            printf("Ingrese la nueva cantidad de articulos: ");
            scanf_s("%d", &ordenes[i].totalArticulos);

            printf("Ingrese los nuevos nombres de los articulos:\n");
            for (int j = 0; j < ordenes[i].totalArticulos; ++j)
            {
                printf("Nuevo Articulo #%d: ", j + 1);
                scanf_s(" %49[^\n]", ordenes[i].articulos[j], 50);

                printf("Nuevo Precio de %s: ", ordenes[i].articulos[j]);
                if (scanf_s("%d", &ordenes[i].preciosArticulos[j]) != 1)
                {
                    printf("Precio invalido.\n");
                    while (getchar() != '\n');
                    j--;
                }
            }
            printf("Orden modificada.\n");
            return;
        }
    }
    printf("No se encontro ninguna orden.\n");
}

void eliminarOrden()
{
    int numeroTicketEliminar;
    printf("Ingrese el numero de ticket de la orden a eliminar: ");
    scanf_s("%d", &numeroTicketEliminar);

    for (int i = 0; i < 100; ++i)
    {
        if (ordenes[i].numeroTicket == numeroTicketEliminar)
        {
            ordenes[i].numeroTicket = 0;
            printf("Orden eliminada exitosamente.\n");
            return;
        }
    }
    printf("No se encontro ninguna orden.\n");
}

void listaOrdenes()
{
    printf("---- Lista de Ordenes ----\n");
    for (int i = 0; i < 100; ++i) {
        if (ordenes[i].numeroTicket != 0)
        {
            printf("Orden #%d\n", i + 1);
            printf("Numero de Ticket: %d\n", ordenes[i].numeroTicket);
            printf("Nombre del Vendedor: %s\n", ordenes[i].nombreVendedor);
            printf("Fecha: %s\n", ordenes[i].fecha);
            printf("Cantidad total de Articulos: %d\n", ordenes[i].totalArticulos);
            printf("Detalles de los articulos:\n");
            for (int j = 0; j < ordenes[i].totalArticulos; ++j)
            {
                printf("Articulo #%d: %s Precio: %d\n", j + 1, ordenes[i].articulos[j], ordenes[i].preciosArticulos[j]);
            }
            printf("Precio Total: %.2f\n", ordenes[i].precioUnitarioTotal);
            printf("Propina: %.2f\n", ordenes[i].propina);
            printf("Impuesto: %.2f\n", ordenes[i].impuesto);
            printf("Total: %.2f\n", ordenes[i].total);

            printf("\n");
        }
    }
}
void guardarOrdenes(Orden ordenes[], int cantidadOrdenes) //Guardar el txt
{
    ofstream archivo;
    string nombreArchivo = "ordenes.txt";
    archivo.open(nombreArchivo.c_str(), ios::binary);

    if (!archivo.is_open())
    {
        cout << "NO se pudo abrir el archivo 'ordenes.txt'." << endl;
        return;
    }

    archivo << "----Lista de Ordenes----" << endl;

    for (int i = 0; i < cantidadOrdenes; ++i)
    {
        if (ordenes[i].numeroTicket != 0)
        {
            archivo << "Orden #" << i + 1 << endl;
            archivo << "Numero de Ticket: " << ordenes[i].numeroTicket << endl;
            archivo << "Nombre: " << ordenes[i].nombreVendedor << endl;
            archivo << "Fecha: " << ordenes[i].fecha << endl;
            archivo << "Cantidad de Articulos: " << ordenes[i].totalArticulos << endl;
            archivo << "Detalles de los articulos:" << endl;
            for (int j = 0; j < ordenes[i].totalArticulos; ++j)
            {
                archivo << "Articulo #" << j + 1 << ": " << ordenes[i].articulos[j] << " Precio: " << ordenes[i].preciosArticulos[j] << endl;
            }
            archivo << "Precio Total: " << ordenes[i].precioUnitarioTotal << endl;
            archivo << "Propina: " << ordenes[i].propina << endl;
            archivo << "Impuesto: " << ordenes[i].impuesto << endl;
            archivo << "Total: " << ordenes[i].total << endl;

            archivo << endl;
        }
    }

    archivo.close();
    cout << "Ordenes guardadas en 'ordenes.txt'." << endl;
}
void limpiarPantalla()
{
    system("cls");
}

int main()
{
    int opcion;

    do
    {
        mostrarMenu();
        scanf_s("%d", &opcion);

        switch (opcion)
        {
        case 1:
            altaOrden();
            break;
        case 2:
            modificarOrden();
            break;
        case 3:
            eliminarOrden();
            break;
        case 4:
            listaOrdenes();
            break;
        case 5:
            limpiarPantalla();
            break;
        case 6:
            guardarOrdenes(ordenes, 100);
            printf("Orden lista en 'ordenes.txt'.\n");
            return 0;
        default:
            printf("Opción inválida.\n");
            break;
        }
    } while (opcion != 6);

    return 0;
}
    