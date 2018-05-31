#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct{
	char nombre[15];
	float calificacion;
}Profesor;

void averageArray(Profesor a[] , int n);
void readArray(Profesor a[], int n);
void mergeArrays(Profesor a[] , int n, Profesor b[], int m, Profesor ab[], int mn);
void sortArray(Profesor a[], int n);
void printArray(Profesor a[], int n);

int main(){
    setbuf(stdin, NULL);
    setbuf(stdout, NULL);
	Profesor arr1[20];  //Primer arreglo
	Profesor arr2[20];  //Segundo arreglo
	Profesor arrF[40];  //Arreglo final, con elementos fusionados y ordenados
	int n1, n2; //Longitud de los arreglos
    printf("Ingenieros ");
  scanf("%d", &n1);
  fflush(stdin);
  readArray(arr1, n1);//leer el primer arreglo
  printf("Profesores ");
  scanf("%d", &n2);
  fflush(stdin);
  readArray(arr2, n2);//leer el segundo arreglo
  mergeArrays(arr1, n1, arr2, n2, arrF, n1+n2);//Fusionar los dos arreglos en un tercer arreglo
  sortArray(arrF, n1+n2);//Ordenar los elementos del tercer arreglo, recuerde que pueden
  //existir profesores repetidos
  printArray(arrF, n1+n2);//Imprimir el resultado final
  return 0;
}

void readArray(Profesor a[], int n){
  Profesor *p=a;
    char an[15];
	float ac;
	int i = 0;
	for (i=0; i < n; i++){
		setbuf(stdin, 0);
		gets(an);
		strcpy((p + i)->nombre , "");
		strcpy((p + i)->nombre , an);
		scanf("%f", &ac);
		(p + i)->calificacion = ac;
	}
}

void mergeArrays(Profesor a[] , int n, Profesor b[], int m, Profesor ab[], int mn){
  Profesor *p1=a, *p2=b, *p3=ab;
  int i, j;
  for (i=0;i<n;i++){
    for (j=0;(p1+i)->nombre[j]=='\0';j++){
      (p3+i)->nombre[j]=(p1+i)->nombre[j];
    }
    (p3+i)->nombre[j]='\0';
    (p3+i)->calificacion=(p1+i)->calificacion;
  }
  for (;i<n+m;i++){
    for (j=0;(p1+i)->nombre[j]=='\0';j++){
      (p3+i)->nombre[j]=(p1+i)->nombre[j];
    }
    (p3+i)->nombre[j]='\0';
    (p3+i)->calificacion=(p2+i)->calificacion;
  }
}

void sortArray(Profesor a[], int n){
  averageArray(a, n);
  Profesor *p=a;
  Profesor aux;
  for (int i=0;i<n-1;i++){
    for (int j=0;j<n-i-1;j++){
      if((p+j)->calificacion>(p+j+1)->calificacion){
        aux=*(p+j);
        (p+j)->calificacion=(p+j+1)->calificacion;
        *(p+j+1)=aux;
      }
    }
  }
}
void averageArray(Profesor a[], int n){
  Profesor *p=a;
  Profesor aux;
  for (int i=0;i<n-1;i++){
    for (int j=0;j<n-i-1;j++){
      int x;
      repetir:
      if((p+j)->nombre[x]>(p+j+1)->nombre[x]){
        aux=*(p+j);
        (p+j)->calificacion=(p+j+1)->calificacion;
        *(p+j+1)=aux;
      }
      else if(x==15){
        (p+j)->calificacion=((p+j)->calificacion+(p+j+1)->calificacion)/2;
        (p+j+1)->calificacion=-1;
      }
      else{
        x++;
        goto repetir;
      }
    }
  }
}

void printArray(Profesor a[], int n){
  Profesor *p=a;
  for(int i=0; i<=n; i++){
    if((p+i)->calificacion>-1){
      printf("%s\n",(p+i)->nombre);
    printf("%f\n",((p+i)->calificacion));
    }
  }
}
