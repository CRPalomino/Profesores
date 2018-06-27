#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
  int dia;
  int mes;
  int anio;
}fecha;

typedef struct{
  int id;
  char Nom[50];
  char Ap[50];
  char Am[50];
  fecha nac;
}cliente;

typedef struct{
  int idc;
  int id;
  float sld;
  fecha ap;
}cuenta;

typedef struct{
  int idt;
  char *to;
  int co;
  int cd;
  fecha dt;
  float mnt;
}Transaccion;

FILE *Direccion;
FILE *Clientes;
FILE *Cuentas;
FILE *Transacciones;

char *d;
char *c;
char *ct;
char *t;
char lp[]={"cls"};

void guardar();
void menuPrincipal();
void menuCliente();
void nuevoCliente();
void buscarCliente();
void eliminarCliente();
void imprimirClientes();
void menuCuenta();
void menuTransaccion();
void sclientes(cliente);

int main(){
  guardar();
  menuPrincipal();
  free(d);
  free(c);
  free(ct);
  free(t);
  fclose(Clientes);
  fclose(Cuentas);

  return 0;
}

void menuPrincipal(){
  int p;
  system(lp);
  printf("<<MyBD>>\n");
  printf("Seleccione una opcion:\n1. Clientes \n2. Cuentas \n3. Transacciones \n4. Salir\n");
  fflush(stdin);
  scanf("%d",&p);
  switch (p) {
    case 1:{menuCliente();break;}
    case 2:{menuCuenta();break;}
    case 3:{menuTransaccion();}
  }
}

void menuCliente(){
  int o, ID;
  do{
  system(lp);
  printf("<<Clientes>>\n");
  printf("Seleccione una opcion:\n1. Nuevo Cliente \n2. Buscar Cliente \n3. Eliminar Cliente \n4. Imprimir Cliente\n5. Menu Principal\n");
  scanf("%d",&o);
  fflush(stdin);
    switch (o) {
      case 1:{nuevoCliente();break;}
      case 2:{buscarCliente();break;}
      case 3:{eliminarCliente();break;}
      case 4:{imprimirClientes();break;}
    }
  } while (o<=4);
  menuPrincipal();
}

void nuevoCliente(){
  cliente ncliente;
  cliente clientes;
  int i=1, j=1, idc;
  printf("Nombre: ");
  fflush(stdin);
  gets(ncliente.Nom);
  printf("Apellido Paterno: ");
  fflush(stdin);
  gets(ncliente.Ap);
  printf("Apellido Materno: ");
  fflush(stdin);
  gets(ncliente.Am);
  printf("Fecha de nacimiento (dd mm aaaa): ");
  fflush(stdin);
  scanf("%d %d %d",&ncliente.nac.dia,&ncliente.nac.mes,&ncliente.nac.anio);
  while(fread(&clientes,sizeof(cliente),1,Clientes)==1&&j==1){
    if(strcmp(clientes.Nom,"")){
      ncliente.id=i;
      idc=i;
      sclientes(ncliente);
      j--;
    }
    else
      i++;
  }
  if(j==1){
    ncliente.id=i;
    idc=1;
    fwrite(&ncliente,sizeof(cliente),1,Clientes);
  }
  printf("%d\n",idc);
  system("pause");
}

void buscarCliente(){
  int idb;
  int j=0;
  cliente clientes;
  printf("ID de usario a buscar: ");
  scanf("%d",&idb);
  while(fread((&clientes),sizeof(cliente),1,Clientes)==1-j){
    if(clientes.id==idb){
      if(strcmp(clientes.Nom,"")){
        printf("Este ID no esta vinculado con ningun usuario");
      }
      else{
        puts(clientes.Nom);
        puts(clientes.Ap);
        puts(clientes.Am);
        printf("%d/%d/%d\n",clientes.nac.dia,clientes.nac.mes,clientes.nac.anio);
      }
      j++;
    }
  }
  if(j==0)
    printf("ID no existente");
    system("pause");
}

void eliminarCliente(){
  int idb;
  cliente clientes;
  printf("ID de usario a eliminar: ");
  scanf("%d",&idb);
  clientes.id=idb;
  strcpy(clientes.Nom,"");
  strcpy(clientes.Ap,"");
  strcpy(clientes.Am,"");
  clientes.nac.dia=0;
  clientes.nac.mes=0;
  clientes.nac.anio=0;
  sclientes(clientes);
}

void imprimirClientes(){
  cliente clientes;
  while(fread(&clientes,sizeof(cliente),1,Clientes)==1){
    if(strcmp(clientes.Nom,"")==1){
        puts(clientes.Nom);
        puts(clientes.Ap);
        puts(clientes.Am);
        printf("%d/%d/%d\n",clientes.nac.dia,clientes.nac.mes,clientes.nac.anio);
      }
    }
    system("pause");
  }

void sclientes(cliente who){
  cliente cpia;
  fclose(Clientes);
  FILE *Copia;
  Copia=fopen("aux.dat","wb");
  Clientes=fopen(c,"rb");
  while(fread(&cpia, sizeof(cliente),1,Clientes)==1){
    if (cpia.id!=who.id)
      fwrite(&cpia, sizeof(cliente),1,Copia);
    else
      fwrite(&who, sizeof(cliente),1,Copia);
  }
  fclose(Clientes);
  fclose(Copia);
  Copia=fopen("aux.dat","rb");
  Clientes=fopen(c,"wb");
  while(fread(&cpia,sizeof(cliente),1,Copia)==1)
    fwrite(&cpia, sizeof(cliente),1, Clientes);
  fclose(Clientes);
  fclose(Copia);
  remove("aux.dat");
  Clientes=fopen(c,"ab+");
}

void menuCuenta(){
  int o;
  do{
  fflush(stdin);
  printf("<<Cuentas>>\n");
  printf("Seleccione una opcion:\n1. Nueva Cuenta \n2. Buscar Cuenta \n3. Eliminar Cuenta \n4. Imprimir Cuenta\n5. Menu Principal\n");
  scanf("%d",&o);
  switch (o) {
    case 1:{printf("Nuevo\n");break;}
    case 2:{printf("Buscar\n");break;}
    case 3:{printf("Eliminar\n");break;}
    case 4:{printf("Imprimir\n");break;}
  }
} while (o<5);
menuPrincipal();
}

void nuevaCuenta(){
  cuenta ncuenta;
  cuenta cuentas;
  int i=1, j=1, idc;
  printf("ID Cliente: ");
  fflush(stdin);
  scanf("%d\n",ncuenta.id);
  printf("Saldo: ");
  scanf("%d",ncuenta.sld);
  printf("Fecha de apertura (dd mm aaaa): ");
  fflush(stdin);
  scanf("%d %d %d",&ncliente.ap.dia,&ncliente.ap.mes,&ncliente.ap.anio);
  //buscarCliente1
  while(fread(&cuentas,sizeof(cuenta),1,Cuentas)==1&&j==1){
    if(cuentas.id==0){
      ncuenta.idc=i;
      idc=i;
      scuentas(ncuenta);
      j--;
    }
    else
      i++;
  }
  if(j==1){
    ncuenta.idc=i;
    idc=1;
    fwrite(&ncuenta,sizeof(cuenta),1,Cuentas);
  }
  printf("%d\n",idc);
  system("pause");
}

void buscarCuenta(){
  int idb;
  int j=0;
  cuenta cuentas;
  printf("ID de cuenta a buscar: ");
  scanf("%d",&idb);
  while(fread((&cuentas),sizeof(cuenta),1,Cuentas)==1-j){
    if(cuentas.idc==idb){
      if(cuentas.id==0){
        printf("Este ID no esta vinculado con ningun usuario");
      }
      else{
        printf("%d\n",clientes.id);
        printf("%d\n",cuentas.sld);
        printf("%d/%d/%d\n",clientes.ap.dia,clientes.ap.mes,clientes.ap.anio);
      }
      j++;
    }
  }
  if(j==0)
    printf("ID no existente");
    system("pause");
}

void eliminarCuenta(){
  int idb;
  cuenta cuentas;
  printf("ID de cuenta a eliminar: ");
  scanf("%d",&idb);
  cuentas.idc=idb;
  cuentas.id=0;
  cuentas.sld=0.0;
  cuentas.ap.dia=0;
  cuentas.ap.mes=0;
  cuentas.ap.anio=0;
  scuentas(Cuentas);
}

void scuentas(cuenta who){
  cuenta cpia;
  fclose(Cuentas);
  FILE *Copia;
  Copia=fopen("aux.dat","wb");
  Cuentas=fopen(ct,"rb");
  while(fread(&cpia, sizeof(cuenta),1,Cuentas)==1){
    if (cpia.idc!=who.idc)
      fwrite(&cpia, sizeof(cuenta),1,Copia);
    else
      fwrite(&who, sizeof(cuenta),1,Copia);
  }
  fclose(Cuentas);
  fclose(Copia);
  Copia=fopen("aux.dat","rb");
  Cuentas=fopen(c,"wb");
  while(fread(&cpia,sizeof(cuenta),1,Copia)==1)
    fwrite(&cpia, sizeof(cuenta),1, Cuentas);
  fclose(Cuentas);
  fclose(Copia);
  remove("aux.dat");
  Cuenta=fopen(ct,"ab+");
}

void menuTransaccion(){
  int o;
  do{
  system(lp);
  printf("<<Transacciones>>\n");
  printf("Seleccione una opcion:\n1. Deposito \n2. Retiro \n3. Transferencia \n4. Menu Principal\n");
  scanf("%d",&o);
  switch (o) {
    case 1:{printf("Deposito\n");break;}
    case 2:{printf("Retiro\n");break;}
    case 3:{printf("Transferencia\n");break;}
  }
} while(o<5);
  menuPrincipal();
}

void guardar(){
  d=(char *)malloc(100*sizeof(char));
  c=(char *)malloc(100*sizeof(char));
  ct=(char *)malloc(100*sizeof(char));
  t=(char *)malloc(100*sizeof(char));
  Direccion=fopen("mydb.sys","r");
  if (Direccion==NULL){
    fclose(Direccion);
    printf("Seleccione en que carpeta desea guardar el archivo:\n");
    revalidacion:
    Direccion=fopen("mydb.sys","w");
    scanf("%s",d);
    fputs(d,Direccion);
  }
  else{
    fgets(d,100,Direccion);
  }
  strcpy(c,d);
  strcpy(ct,d);
  strcpy(t,d);
  strcat(c,"\\clientes.dat");
  strcat(ct,"\\cuentas.dat");
  strcat(t,"\\Transacciones.dat");
  Clientes=fopen(c,"ab+");
  if (Clientes==NULL){
    printf("Carpeta no existe o ingresada incorrectamente. Intente de nuevo:\n");
    fclose(Direccion);
    goto revalidacion;
  }
  Cuentas=fopen(ct,"ab+");
  Transacciones=fopen(t,"ab+");
  fclose(Direccion);
}
