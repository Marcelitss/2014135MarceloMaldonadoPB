#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>

using namespace std;

struct Ticket
{
	int numero;
	int precio;
};

int main()
{
	const int MAX_TICKETS = 3;
		Ticket tickets[MAX_TICKETS]; 
	int opcion;

	do {
		printf("Menu:\n");
		printf("1. Alta de Tickets\n");
		printf("2. Lista \n");
		printf("3. Salir\n");
		printf("Ingrese su opcion: ");
		scanf_s("%d", &opcion);

		switch (opcion)
		{
		case 1:
			for (int i = 0; i < MAX_TICKETS; i++)
			{
				printf("Ingrese el numero del ticket %d:", i + 1);
				scanf_s("%d", &tickets[i].numero);
				printf("Ingrese el precio del ticket %d:", i + 1);
				scanf_s("%d", &tickets[i].precio);

			}
			printf("Alta de tickets exitosa!!\n");
			break;

		case 2:
			
	        printf("Lista de Tickets:\n");
			for (int i = 0; i < MAX_TICKETS; i++)
			{
				printf("Ticket %d: Numero %d, Precio %d\n", i + 1, tickets[i].numero, tickets[i].precio);
			}
			break;

		case 3:
			printf("Saliendo del programa. ¡Hasta luego!\n");
			break;

		default:
			printf("Opcion invalida. Por favor escoja otra opcion.\n");
			break;
		}
	} while (opcion != 3);

	return 0;

}