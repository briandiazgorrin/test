//Crear una lista de articulos para una tienda, dar al usuario la opcion de elegir que articulos desea comprar, mostrar el precio total de su compra y
//aplicar un descuento de 10% con un cupon valido.

 
// LIBRERIAS
#include <stdio.h>
#include <string.h> // COMPARAR CON strcmp strcpy
 
 
// VARIABLES GLOBALES
int opc; //opcion del usuario del articulo que quiere comprar
float suma_total;
float lista_precios[] = { 50 , 10 , 80 , 0 };
char cupon[15] = "verano"; // CODIGO DEL CUPON
char cuponUser[15]; // LO QUE EL USUARIO DIGITE
 
 
 
// PROTOTIPOS
void menu();
void detalles_compra();
 
//si
 
// FUNCION PRINCIPAL
int main()
{
	menu();
}
 
void menu()
{
	// MENU DE OPCIONES DE ARTICULOS
	printf("0. Monitor \t\t$50 USD");
	printf("\n1. Teclado \t\t$10 USD");
	printf("\n2. Impresora \t\t$80 USD");
	printf("\n3. Finalizar la compra");
 
	do
	{
	printf("\nDigite el numero del articulo: ");
	scanf("%i", &opc);
 
	// SUMA ITERATIVA
	suma_total += lista_precios[opc];
 
	}
	while (opc != 3 );
	if (opc==3) { detalles_compra(); } // SI LA OPCION ES 3, FINALZIAMOS LA COMPRA Y VAMOS A LOS DETALLES DE LA MISMA
}
 
void detalles_compra()
{
	int tieneCupon;
 
	// PREGUNTAMOS SI TIENE CUPON 
	printf("\nTenes un cupon de descuento? SI=1 | NO=0");
	scanf("%i", &tieneCupon);
 
	// SI NO TIENE CUPON
	if (tieneCupon == 0) // NO TIENE
	{
		printf("\nNo tienes un cupon, debes pagar el total de %f " , suma_total); // EL TOTAL A PAGAR SIN CUPON
	}
 
	// SI TIENE UN CUPON
	if (tieneCupon == 1) // SI TIENE
	{
		printf("\nDigite el cupon de descuento: ");
		scanf("%s" , &cuponUser); // ALMACENAMOS EL CUPON QUE TIENE EL USUARIO
 
		// CONDICIONAL ANIDADO PARA COMPARAR AMBOS CUPONES
		if ( strcmp(cupon, cuponUser) == 0 ) // COINCIDEN Y APLICAMOS EL DESCUENTO
		{
			float suma_total_descuento = suma_total * 0.90; // aplicamos el 10%
			printf("\nTu descuento ha sido aplicado, en lugar de pagar %f , pagaras %f ", suma_total , suma_total_descuento);
		}
 
		else // SI EL CUPON DIGITADO NO ES VALIDO
		{
			printf("\nEl cupon digitado es invalido, pagaras el original de %f " , suma_total);
		}
 
	}
 
 
}