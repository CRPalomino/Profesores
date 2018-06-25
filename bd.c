#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXIMO 20

typedef struct{
	int dia;
	int mes;
	int anio;
}fecha;

typedef struct{
	int id;
	char nombre[25];
	char apat[25];
	char amat[25];
	fecha nacimiento;
}Cliente;

typedef struct{
	int idc;
	int id_cliente;
	int saldo;
	fecha apertura;
}Cuenta;

typedef struct{
	int idt;
	char ttrans[15];
	int origen;
	int destino;
	int monto;
	fecha ftrans;
}Transaccion;




enum MenuPrincipal {Cero, Clientes, Cuentas, transs, Salir};

void mCliente();
void mCuentas();
void mtrans();

void nCliente (Cliente clientes[MAXIMO], int pos, Cliente *arrp[]);
void bCliente (Cliente clientes[MAXIMO], Cliente *arrp[]);
void eCliente (Cliente clientes[MAXIMO], Cliente *arrp[]);
void iClientes(Cliente clientes[MAXIMO], Cliente *arrp[]);

int aCuenta (Cuenta cuentas[MAXIMO], int posC, Cuenta *apc[]);
void bCuenta (Cuenta cuentas[MAXIMO], Cuenta *apc[]);
void eCuenta (Cuenta cuentas[MAXIMO], Cuenta *apc[], int valor);
void iCuentas(Cuenta cuentas[MAXIMO], Cuenta *apc[]);

int Trans (Transaccion transs[MAXIMO], int ptrans, Transaccion *apt[]);

Cliente clientes[MAXIMO];
int pos = 0;
Cliente *arrp[MAXIMO];


Cuenta cuentas[MAXIMO];
int posC = 0;
Cuenta *apc[MAXIMO];

Transaccion transs[MAXIMO];
int ptrans = 0;
Transaccion *apt[MAXIMO];


FILE *Direccion;
FILE *Clientesa = NULL, *Cuentasa = NULL, *transa = NULL;
char rClientes[35] = "";
char rCuentas[35] = "";
char rTrans[35] = "";
void leer (FILE *archivo, char arr[]);
void Bin ();

int main(void) {
	setvbuf(stdout, NULL, _IONBF, 0);

	Bin ();


	int i;
	for(i=0; i<MAXIMO; i++){
		arrp[i] = NULL;
	}

	for(i=0; i<MAXIMO; i++){
		apc[i] = NULL;
	}

	for(i=0; i<MAXIMO; i++){
		apt[i] = NULL;
	}


	int o;
	    do{
	    	printf("\n \t <<MENU PRINCIPAL>>");
	        printf("\n1. Clientes");
	        printf("\n2. Cuentas");
	        printf("\n3. transs");
	        printf("\n4. Salir");

	        printf("\nEscoja su opción (1-4):");
	        scanf("%d", &o);

	        switch(o)
	           {
	               case Clientes: mCliente();
	                       break;

	               case Cuentas: mCuentas();
	                       break;

	               case transs: mtrans();
	                       break;

	               default:
	            	   if(o != Salir)
	            		   printf( "\n-----NO válido-----");
	           }

	    }while(o != Salir);

	return 0;
}




void bCliente (Cliente clientes[MAXIMO], Cliente *arrp[]){
	Cliente *apunArr = clientes;
	int ID=0;
	printf("\nBuscar por ID: \n");
	scanf("%d", &ID);

	int band = 0;

	for(int i=0; i < MAXIMO; i++){
		if( ((apunArr + i)->id == ID) && (arrp[i] != NULL) )
		{
			printf("\n***Cliente %d*", i+1);
			printf("\nEl ID es: %d", (apunArr + i)->id);
			printf("\nEl nombre del cliente es: %s", (*(apunArr + i)).nombre);
			printf("\nEl apellido apat del cliente es: %s", (*(apunArr + i)).apat);
			printf("\nEl apellido amat del cliente es: %s", (*(apunArr + i)).amat);
			printf("\nSu fecha de Nacimiento es: %d / %d / %d \n", (apunArr + i)->nacimiento.dia, (apunArr + i)->nacimiento.mes, (apunArr + i)->nacimiento.anio);
			band = 1;
		}
	}

	if(ID != 0)
	{
		if(band == 0)
			printf("\nNo se encontro ningun cliente en su búsqueda\n");
	}


}

void nCliente (Cliente clientes[MAXIMO], int pos, Cliente *arrp[]){
	Cliente *arrCliente = clientes;
	int IDx = pos + 1;
	char auxNombre[20];
	char auxamat[25];
	char auxapat[25];
	int dia, mes, anio;

	printf("Su ID de cliente es --- %d --- \n", IDx);

	setbuf(stdin, 0);
	printf("Dame el nombre:\n");
	gets(auxNombre);

	setbuf(stdin, 0);
	printf("Dame el apellido apat:\n");
	gets(auxapat);

	setbuf(stdin, 0);
	printf("Dame el apellido amat:\n");
	gets(auxamat);

	setbuf(stdin, 0);
	printf("Dame la fecha de nacimiento dd/mm/aa:\n");
	scanf("%d %d %d", &dia, &mes, &anio);


	(arrCliente + pos)->id = IDx;
	strcpy(((arrCliente + pos)->nombre),"");
	strcpy( ((arrCliente + pos)->nombre), auxNombre );

	strcpy(((arrCliente + pos)->apat),"");
	strcpy( ((arrCliente + pos)->apat), auxapat );

	strcpy(((arrCliente + pos)->amat),"");
	strcpy( ((arrCliente + pos)->amat), auxamat );


	(arrCliente + pos)->nacimiento.dia = dia;
	(arrCliente + pos)->nacimiento.mes = mes;
	(arrCliente + pos)->nacimiento.anio = anio;

	arrp[pos] = (arrCliente + pos);

	Clientesa = fopen(rClientes, "a+b");
	fwrite(&arrCliente[pos], sizeof( Cliente ), 1, Clientesa);
	fclose(Clientesa);

}

void eCliente (Cliente clientes[MAXIMO], Cliente *arrp[]){
	Cliente *apunArr = clientes;
	int idBorrar;
	int band = 0;
	printf("\nID del Cliente que desea borrar:");
	scanf("%d", &idBorrar);

	for(int i=0; i < MAXIMO; i++){
		if ((apunArr + i)->id == idBorrar)
		{
			arrp[i] = NULL;
			(apunArr + i)->id = 0;
			printf("Cliente eliminado\n");
			band = 1;
			eCuenta (cuentas, apc, 2);
		}
	}
	if(band == 0)
		printf("No existe ese no. de ID\n");


	//
	Clientesa = fopen(rClientes,"r+b");
	if (Clientesa==NULL){
		printf("Error al abrir archivo Clientesa\n");
	}
	else{/
		rewind(Clientesa);
		Cliente arrLeerClientes[250];
		int i = 0;
		int borr = 0;
		fread(&arrLeerClientes[i], sizeof(Cliente), 1, Clientesa);

		while( ! feof(Clientesa) )
		{
			if( (apunArr + i)->id == idBorrar){
				int retorno = fseek(Clientesa, 0, SEEK_CUR);

				if(retorno == 0){
					fwrite(&borr, sizeof( int ), 1, Clientesa);
					printf("El cursor se movió correctamente y ya borramos");
				}
				i++;
				fread(&arrLeerClientes[i], sizeof(Cliente), 1, Clientesa);
			}
		}
		fclose(Clientesa);
	}
}

void iClientes(Cliente clientes[MAXIMO], Cliente *arrp[]){
	Cliente *apunArr = clientes;
	printf("\nLos clientes registrados al momento son:");
	for(int i=0; i < MAXIMO; i++){
		if ( (arrp[i] != NULL) && ((apunArr + i)->id != 0) )
		{
			printf("\n***Cliente %d*", i+1);
			printf("\nEl ID es: %d", (apunArr + i)->id);
			printf("\nEl nombre del cliente es: %s", (*(apunArr + i)).nombre);
			printf("\nEl apellido apat del cliente es: %s", (*(apunArr + i)).apat);
			printf("\nEl apellido amat del cliente es: %s", (*(apunArr + i)).amat);
			printf("\nSu fecha de Nacimiento es: %d / %d / %d \n", (apunArr + i)->nacimiento.dia, (apunArr + i)->nacimiento.mes, (apunArr + i)->nacimiento.anio);
		}
	}

  Clientesa = fopen(rClientes,"rb");
  if (Clientesa==NULL){
    printf("Error al abrir archivo Clientesa\n");
  }
  else{
    printf("\nTodos los datos almacenados en el archivo Clientesa.");
    Cliente arrLeerClientes[250];
    i = 0;
    fread(&arrLeerClientes[i], sizeof(Cliente), 1, Clientesa);
    while( !feof(Clientesa) )
    {
        printf("\n***Cliente %d*", i+1);
        printf("\nEl ID es: %d", arrLeerClientes[i].id);
        printf("\nEl nombre del cliente es: %s",  arrLeerClientes[i].nombre);
        printf("\nEl apellido apat del cliente es: %s",  arrLeerClientes[i].apat);
        printf("\nEl apellido amat del cliente es: %s",  arrLeerClientes[i].amat);
        printf("\nSu fecha de Nacimiento es: %d / %d / %d \n",  arrLeerClientes[i].nacimiento.dia,  arrLeerClientes[i].nacimiento.mes,  arrLeerClientes[i].nacimiento.anio);
        i++;
        fread(&arrLeerClientes[i], sizeof(Cliente), 1, Clientesa);
    }
    fclose(Clientesa);
  }


}

void iCuentas(Cuenta cuentas[MAXIMO], Cuenta *apc[]){
	Cuenta *apunArr = cuentas;
	printf("\nLas cuentas registradas al momento son:");
	for(int i=0; i < MAXIMO; i++){
		if ( (apc[i] != NULL) && ((apunArr + i)->idc != 0) )
		{
			printf("\n***Cuenta %d*", i+1);
			printf("\nEl ID de cuenta es: %d", (apunArr + i)->idc);
			printf("\nEl ID de cliente es: %d", (apunArr + i)->id_cliente);
			printf("\nEl saldo de la cuenta es: %d", (apunArr + i)->saldo);
			printf("\nSu fecha de Apertura de la cuenta es: %d / %d / %d \n", (apunArr + i)->apertura.dia, (apunArr + i)->apertura.mes, (apunArr + i)->apertura.anio);
		}
	}

}

void eCuenta (Cuenta cuentas[MAXIMO], Cuenta *apc[], int valor){
	Cuenta *apunArr = cuentas;
	int idBorrar;
	int band = 0;
	int i;
	Cliente *arrp = clientes;

	if(valor == 1){
		printf("\nID de la Cuenta que desea borrar:");
		scanf("%d", &idBorrar);

		for(i= 0; i < MAXIMO; i++){
			if ( (apunArr + i)->idc == idBorrar )
			{
				apc[i] = NULL;
				(apunArr + i)->idc = 0;
				printf("Cuenta eliminada\n");
				band = 1;
			}
		}
		if(band == 0)
			printf("No existe ese no. de ID de cuenta\n");
	}
	else if (valor == 2){
		for(i= 0; i < MAXIMO; i++){
			if ((arrp + i)->id == 0)
			{
				apc[i] = NULL;
				(apunArr + i)->idc = 0;
				printf("Cuenta eliminada\n");
				band = 1;
			}
		}
		if(band == 0)
			printf("No existe ese no. de ID de cuenta\n");
	}
}

int aCuenta (Cuenta cuentas[MAXIMO], int posC, Cuenta *apc[]){
	Cuenta *arrCuenta = cuentas;
	int IDx_cuenta = posC + 1;
	int IDx_cliente;
	int auxSaldo;
	int dia, mes, anio;

	printf("\nintroduzca su ID de cliente: ");
	scanf("%d", &IDx_cliente);

	Cliente *apunArr = clientes;
	int i, band = 0;
	for(i=0; i < MAXIMO; i++){
		if( (apunArr + i)->id == IDx_cliente )
		{
			printf("Su idc es --- %d ---\n", IDx_cuenta);

			(arrCuenta)->id_cliente = (apunArr + i)->id;

			printf("saldo inicial:\n");
			scanf("%d", &auxSaldo);

			setbuf(stdin, 0);
			printf("fecha de apertura de la cuenta dd/mm/aa:\n");
			scanf("%d %d %d", &dia, &mes, &anio);

			(arrCuenta + posC)->idc = IDx_cuenta;
			(arrCuenta + posC)->id_cliente = IDx_cliente;
			(arrCuenta + posC)->saldo = auxSaldo;

			(arrCuenta + posC)->apertura.dia = dia;
			(arrCuenta + posC)->apertura.mes = mes;
			(arrCuenta + posC)->apertura.anio = anio;

			apc[posC] = (arrCuenta + posC);
			band = 1;
			Cuentasa = fopen(rCuentas, "a+b");
			fwrite(&arrCuenta[posC], sizeof( Cliente ), 1, Clientesa);
			fclose(Cuentasa);
			return 1;
		}
	}
	if(band == 0)
	{
		printf("\nNo se pudo crear la cuenta, el ID de cliente no existe\n");
		return 0;
	}
	return -1;
}

void bCuenta (Cuenta cuentas[MAXIMO], Cuenta *apc[]){
	Cuenta *apunArr = cuentas;
	int idc;
	printf("\nBuscar por id cuenta: \n");
	scanf("%d", &idc);

	int band = 0;

	for(int i=0; i < MAXIMO; i++){
		if( ((apunArr + i)->idc == idc) && (apc[i] != NULL) )
		{
			printf("\n***Cuenta %d*", i+1);
			printf("\nEl id cuenta es: %d", (apunArr + i)->idc);
			printf("\nEl id cliente es: %d", (apunArr + i)->id_cliente);
			printf("\nEl saldo de la cuenta es: %d", (apunArr + i)->saldo);
			printf("\nSu fecha de Apertura de la cuenta es: %d / %d / %d \n", (apunArr + i)->apertura.dia, (apunArr + i)->apertura.mes, (apunArr + i)->apertura.anio);
			band = 1;
		}
	}

	if(idc != 0)
	{
		if(band == 0)
			printf("\nNo se encontro ningun cliente en su búsqueda\n");
	}
}

int Trans (Transaccion transs[MAXIMO], int ptrans, Transaccion *apt[]){
	Transaccion *aTrans = transs;
	int IDx = ptrans + 1;
	char auxttrans[15];
	int o;
	int cOrigen;
	int cDestino;
	int maux;
	int dia, mes, anio;


	setbuf(stdin, 0);
	printf("Seleccione ttrans a realizar:\n");
	printf("\n1. Deposito");
	printf("\n2. Retiro");
	printf("\n3. Transferencia");
	scanf("%d", &o);

	int i=0, band = 0;
	Cuenta *apunArr = cuentas;



	if (o == 1){
		printf("\nintroduzca su ID de cuenta: ");
		scanf("%d", &cOrigen);
		for(i=0; i < MAXIMO; i++){
			if( (apunArr + i)->idc == cOrigen )
			{
				printf("Su ID de Transaccion es --- %d --- \n", IDx);

				printf("Dame el monto del depósito:\n");
				scanf("%d", &maux);

				(apunArr + i)->saldo = (apunArr + i)->saldo + maux;

				setbuf(stdin, 0);
				printf("Dame la fecha de la transaccion dd/mm/aa:\n");
				scanf("%d %d %d", &dia, &mes, &anio);

				(aTrans + ptrans)->idt = IDx;

				strcpy(((aTrans + ptrans)->ttrans),"");
				strcpy( auxttrans , "Deposito");
				strcpy( ((aTrans + ptrans)->ttrans), auxttrans );

				(aTrans + ptrans)->origen = cOrigen;
				(aTrans + ptrans)->destino = 0;
				(aTrans + ptrans)->monto = maux;

				(aTrans + ptrans)->ftrans.dia = dia;
				(aTrans + ptrans)->ftrans.mes = mes;
				(aTrans + ptrans)->ftrans.anio = anio;
				apt[ptrans] = (aTrans + ptrans);
				band = 1;

				transa = fopen(rTrans, "a+b");
				fwrite(&aTrans[ptrans], sizeof( Transaccion ), 1, transa);
				fclose(transa);

				Cuentasa = fopen(rCuentas, "wb");
				fclose(Cuentasa);

				Cuentasa = fopen(rCuentas, "a+b");
				for(i=0; i<posC; i++)
					fwrite(&cuentas[i], sizeof( Cuenta ), 1, Cuentasa);
				fclose(Cuentasa);

				return 1;
			}
		}
	}

	if (o == 2){
		printf("\nintroduzca su ID de cuenta: ");
		scanf("%d", &cOrigen);
		for(i=0; i < MAXIMO; i++){
			if( (apunArr + i)->idc == cOrigen )
			{
				printf("Su ID de Transaccion es --- %d --- \n", IDx);

				printf("Dame el monto del retiro:\n");
				scanf("%d", &maux);

				while((apunArr + i)->saldo <= maux){
					printf("No hay dinero suficiente:\n");
					scanf("%d", &maux);
				}

				(apunArr + i)->saldo = (apunArr + i)->saldo - maux;

				setbuf(stdin, 0);
				printf("fecha de la transaccion dd/mm/aa:\n");
				scanf("%d %d %d", &dia, &mes, &anio);

				(aTrans + ptrans)->idt = IDx;

				strcpy(((aTrans + ptrans)->ttrans),"");
				strcpy( auxttrans , "Retiro");
				strcpy( ((aTrans + ptrans)->ttrans), auxttrans );

				(aTrans + ptrans)->origen = cOrigen;
				(aTrans + ptrans)->destino = 0;
				(aTrans + ptrans)->monto = maux;

				(aTrans + ptrans)->ftrans.dia = dia;
				(aTrans + ptrans)->ftrans.mes = mes;
				(aTrans + ptrans)->ftrans.anio = anio;
				apt[ptrans] = (aTrans + ptrans);
				band = 1;


				transa = fopen(rTrans, "a+b");
				fwrite(&aTrans[ptrans], sizeof( Transaccion ), 1, transa);
				fclose(transa);


				Cuentasa = fopen(rCuentas, "wb");
				fclose(Cuentasa);

				Cuentasa = fopen(rCuentas, "a+b");
				for(i=0; i<posC; i++)
					fwrite(&cuentas[i], sizeof( Cuenta ), 1, Cuentasa);
				fclose(Cuentasa);

				return 1;
			}
		}
	}

	if (o == 3){
		printf("\nintroduzca su ID de cuenta: ");
		scanf("%d", &cOrigen);

		printf("\nla cuenta de destino: ");
		scanf("%d", &cDestino);
		int j;
		for(i=0; i < MAXIMO; i++)
			for(j = 0; j < MAXIMO; j++)
				if ( ((apunArr + i)->idc == cOrigen) && (apunArr + j)->idc == cDestino)
				{
					printf("Su ID de Transaccion es --- %d --- \n", IDx);

					printf("monto a transferir:\n");
					scanf("%d", &maux);

					while((apunArr + i)->saldo <= maux){
						printf("No tiene fondos:\n");
						scanf("%d", &maux);
					}

					(apunArr + i)->saldo = (apunArr + i)->saldo - maux;
					(apunArr + j)->saldo = (apunArr + j)->saldo + maux;

					setbuf(stdin, 0);
					printf("fecha de la transaccion dd/mm/aa:\n");
					scanf("%d %d %d", &dia, &mes, &anio);

					(aTrans + ptrans)->idt = IDx;

					strcpy(((aTrans + ptrans)->ttrans),"");
					strcpy( auxttrans , "Retiro");
					strcpy( ((aTrans + ptrans)->ttrans), auxttrans );

					(aTrans + ptrans)->origen = cOrigen;
					(aTrans + ptrans)->destino = 0;
					(aTrans + ptrans)->monto = maux;

					(aTrans + ptrans)->ftrans.dia = dia;
					(aTrans + ptrans)->ftrans.mes = mes;
					(aTrans + ptrans)->ftrans.anio = anio;
					apt[ptrans] = (aTrans + ptrans);
					band = 1;


					transa = fopen(rTrans, "a+b");
					fwrite(&aTrans[ptrans], sizeof( Transaccion ), 1, transa);
					fclose(transa);


					Cuentasa = fopen(rCuentas, "wb");
					fclose(Cuentasa);

					Cuentasa = fopen(rCuentas, "a+b");
					for(i=0; i<posC; i++)
						fwrite(&cuentas[i], sizeof( Cuenta ), 1, Cuentasa);
					fclose(Cuentasa);

					return 1;
				}
	}

	if(band == 0)
	{
		printf("\nNo se pudo realizar la transaccion, el ID de cuenta no existe\n");
		return 0;
	}
	return -1;
}

void mCliente(){
	int o;
	do{
		printf("\n\t\t  \t -> Submenu CLIENTES...");
		printf("\n\t\t1. Nuevo cliente");
		printf("\n\t\t2. Buscar cliente");
		printf("\n\t\t3. Eliminar cliente");
		printf("\n\t\t4. Imprimir clientes");
		printf("\n\t\t5. Salir");

		printf("\n\t\tOpción CLIENTES, escoja (10) un número válido:");
		scanf("%d", &o);

		switch(o)
			{
				case 1: nCliente (clientes, pos, arrp);
        	   	   	    pos++;
        	   	   	    break;

				case 2: bCliente (clientes, arrp);
						break;

				case 3:	eCliente (clientes, arrp);
						break;

				case 4: iClientes (clientes, arrp);
						break;

				default:
					if(o != 5)
						printf( "\n\t\t  -------Número NO válido, escoja de nuevo\n");
			}

	}while(o != 5);
}

void mCuentas(){
	int valor, o;
	do{
		printf("\n\t\t  \t -> Submenu CUENTAS...");
		printf("\n\t\t1. Nueva cuenta");
		printf("\n\t\t2. Buscar cuenta");
		printf("\n\t\t3. Eliminar cuenta");
		printf("\n\t\t4. Imprimir cuentas");
		printf("\n\t\t5. Salir");

		printf("\n\t\tOpción CUENTAS, escoja (10) un número válido:");
		scanf("%d", &o);

		switch(o)
			{
				case 1: valor = aCuenta (cuentas, posC, apc);
						if(valor == 1){
							posC++;
						}
						break;

				case 2: bCuenta (cuentas , apc);
						break;

				case 3: eCuenta (cuentas, apc, 1);
						break;

				case 4: iCuentas(cuentas, apc);
						break;

				default:
					if(o != 5)
						printf( "\n\t\t  -------Número NO válido, escoja de nuevo\n");
			}

	}while(o != 5);
}

void mtrans(){
	int valor, o;
	do{
		printf("\n\t\t  \t -> Submenu transs...");
		printf("\n\t\t1. Depósito");
		printf("\n\t\t2. Retiro");
		printf("\n\t\t3. Transferencia");
		printf("\n\t\t4. Salir");

		printf("\n\t\tOpción transs, escoja (1-4) un número válido:");
		scanf("%d", &o);

		switch(o)
			{
				case 1: valor = Trans (transs, ptrans, apt);
					if(valor == 1){
						ptrans++;
					}
					break;

				case 2:

					break;

				case 3:

					break;

				default:
					if(o != 4)
						printf( "\n\t\t  -------Número NO válido, escoja de nuevo\n");
			}

	}while(o != 4);
}



void Bin (){
		char rAcceso[50], VerificarR[50], rBase[50];
		strcpy(VerificarR , "");
		Direccion = fopen("mydb.sys", "rt");


		if(Direccion == NULL){
			printf("Introduce Ruta de acceso ...  \n");
			Direccion = fopen("mydb.sys", "wt");
			scanf("%s", rAcceso);
			fputs( rAcceso ,  Direccion);
			fclose(Direccion);
			Direccion = fopen("mydb.sys", "rt");
			leer(Direccion, VerificarR);
			fclose(Direccion);
			printf("\nLinea del IF: %s", VerificarR);

		}
		else{
			fclose(Direccion);
			Direccion = fopen("mydb.sys", "rt");
			leer(Direccion, VerificarR);
		    fclose(Direccion);
		}

		int valor = strcmp(VerificarR, "Carpeta\\\\");

		while(valor != 0)
		{
			printf("\n\nError...\n");
			printf("Introduce Ruta de acceso\n");
			scanf("%s", rAcceso);
			Direccion = fopen("mydb.sys", "wt");
			fputs( rAcceso ,  Direccion);
			fclose(Direccion);
			Direccion = fopen("mydb.sys", "rt");
			leer(Direccion, VerificarR);
			fclose(Direccion);
			printf("\nLinea del WHILE: %s", VerificarR);
			valor = strcmp(VerificarR, "Carpeta1\\\\");
		}
		printf("\nVerificarR: %s", VerificarR);
		printf("\nrAcceso: %s", rAcceso);
		printf("\nrBase: %s", rBase);

		strcpy(rBase, VerificarR);

		strcpy(rClientes, rBase);
		strcat(rClientes, "clientes.dat");
		Clientesa = fopen(rClientes, "a+b");

		strcpy(rCuentas, rBase);
		strcat(rCuentas, "cuentas.dat");
		Cuentasa = fopen(rCuentas, "a+b");

		strcpy(rTrans, rBase);
		strcat(rTrans, "transs.dat");
		transa = fopen(rTrans, "a+b");

		fclose(Clientesa);
		fclose(Cuentasa);
		fclose(transa);
}

void leer (FILE *archivo, char arr[35]){
	char l;
	int i = 0;
	printf("Funcion leer: ");
	while ((l = fgetc(archivo)) != EOF) {
		arr[i] = l;
		printf( "%c",l );
		i++;
	}
	arr[i] = '\0';
}
