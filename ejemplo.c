#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

typedef struct{
	int inicios;
	int fins;
	double serieParcial=0;
}R;

DWORD WINAPI serie(void *p);

int main(){
	int h;
	printf("cuantos hilos desea?(max 16)\n");
	scanf("%d",&h);
  clock_t inicio = clock();
  double rs;
  switch (h) {
  	case 1:
		R r[1]={{0,50000000000,0}};break;
		case 2:
		R r[2]={{0,25000000,0},{250000001,50000000,0}};break;
		case 3:
		R r[3]={{0,16666666666,0},{16666666667,33333333333,0},{33333333334,50000000000,0}};break;
		case 4:
		R r[4]={{0,12500000000,0},{12500000001,25000000000,0},{25000000001,37500000000,0},{37500000001,50000000000,0}};break;
		case 5:
		R r[5]={{0,10000000000,0},{10000000001,20000000000,0},{20000000001,30000000000,0},{30000000001,40000000000,0},{40000000001,50000000000,0}};break;
		case 6:
		R r[6]={{0,8333333333,0},{8333333334,16666666666,0},{16666666667,25000000000,0},{25000000001,33333333333,0},{33333333334,41666666666,0},{41666666667,50000000000,0}};break;
		case 7:
		R r[7]={{0,7142857142,0},{7142857143,14285714285,0},{14285714286,21428571428,0},{21428571429,28571428571,0},{28571428572,35714285714,0},{35714285715,42857142857,0},{42857142858,50000000000,0}};break;
		case 8:
		R r[8]={{0,6250000000,0},{6250000001,12500000000,0},{12500000001,18750000000,0},{18750000001,25000000000,0},{25000000001,31250000000,0},{31250000001,37500000000,0},{37500000001,43750000000,0},{43750000001,50000000000,0}};break;
		case 9:
		R r[9]={{0,5555555555,0},{5555555555,11111111111,0},{11111111112,16666666666,0},{16666666667,22222222222,0},{22222222223,27777777777,0},{27777777778,33333333333,0},{33333333334,38888888888,0},{38888888889,44444444444,0},{44444444445,50000000000,0}};break;
		case 10:
		R r[10]={{0,5000000000,0},{5000000001,10000000000,0},{10000000001,15000000000,0},{15000000001,20000000000,0},{20000000001,25000000000,0},{25000000001,30000000000,0},{30000000001,35000000000,0},{35000000001,40000000000,0},{40000000001,45000000000,0},{45000000001,50000000000,0}};break;
		case 11:
		R r[11]={{0,4545454545,0},{4545454545,9090909090,0},{9090909091,13636363636,0},{13636363637,18181818181,0},{18181818182,22727272727,0},{22727272728,27272727272,0},{27272727273,31818181818,0},{31818181819,36363636363,0},{36363636364,40909090909,0},{40909090910,45454545454,0},{45454545454,50000000000,0}};break;
		case 12:
		R r[12]={{0,4166666666,0},{4166666667,8333333333,0},{8333333334,12500000000,0},{12500000001,16666666666,0},{16666666667,20833333333,0},{20833333334,25000000000,0},{25000000001,29166666666,0},{29166666667,33333333333,0},{33333333334,37500000000,0},{37500000001,41666666666,0},{41666666667,45833333333,0},{45833333334,50000000000,0}};break;
		case 13:
		R r[13]={{0,3846153846,0},{3846153847,7692307692,0},{7692307693,11538461538,0},{11538461539,15384615384,0},{15384615385,19230769230,0},{19230769231,23076923076,0},{23076923077,26923076923,0},{26923076924,30769230769,0},{30769230770,34615384615,0},{34615384616,38461538461,0},{38461538462,42307692307,0},{42307692308,46153846153,0},{46153846153,50000000000,0}};break;
		case 14:
		R r[14]={{0,3571428571,0},{3571428572,7142857142,0},{7142857143,10714285714,0},{10714285715,14285714285,0},{14285714286,17857142857,0},{17857142858,21428571428,0},{21428571429,25000000000,0},{25000000001,28571428571,0},{28571428572,32142857142,0},{32142857143,35714285714,0},{35714285715,39285714285,0},{39285714286,42857142857,0},{42857142858,46428571428,0},{46428571429,50000000000,0}};break;
		case 15:
		R r[15]={{0,3333333333,0},{3333333334,6666666666,0},{6666666667,10000000000,0},{10000000001,13333333333,0},{13333333334,16666666666,0},{16666666667,20000000000,0},{20000000001,23333333333,0},{23333333334,26666666666,0},{26666666667,30000000000,0},{30000000001,33333333333,0},{33333333334,36666666666,0},{36666666667,40000000000,0},{40000000001,43333333333,0},{43333333333,46666666666,0},{46666666666,50000000000,0}};break;
		default:
		R r[16]={{0,3125000000,0},{3125000001,6250000000,0},{6250000001,9375000000,0},{9375000001,12500000000,0},{12500000001,15625000000,0},{15625000001,18750000000,0},{18750000001,21875000000,0},{21875000001,25000000000,0},{25000000001,28125000000,0},{28125000001,31250000000,0},{31250000001,34375000000,0},{34375000001,37500000000,0},{37500000001,40625000000,0},{40625000001,43750000000,0},{43750000001,46875000000,0},{46875000000,50000000000,0}};
  }
	switch (h) {
		case 1:{
			HANDLE h1=NULL;
			h1=CreateThread(NULL, 0, serie, (void *)&r[0], 0, NULL);
			WaitForSingleObject(h1, INFINITE);
			rs=r[0].serieParcial;
		}break;
		case 2:{
			HANDLE h1=NULL, h2=NULL;
			h1=CreateThread(NULL, 0, serie, (void *)&r[0], 0, NULL);
			h2=CreateThread(NULL, 0, serie, (void *)&r[1], 0, NULL);
			WaitForSingleObject(h1, INFINITE);
			WaitForSingleObject(h2, INFINITE);
			rs=r[0].serieParcial+r[1].serieParcial;
		}break;
		case 3:{
			HANDLE h1=NULL, h2=NULL, h3=NULL;
			h1=CreateThread(NULL, 0, serie, (void *)&r[0], 0, NULL);
			h2=CreateThread(NULL, 0, serie, (void *)&r[1], 0, NULL);
			h3=CreateThread(NULL, 0, serie, (void *)&r[2], 0, NULL);
			WaitForSingleObject(h1, INFINITE);
			WaitForSingleObject(h2, INFINITE);
			WaitForSingleObject(h3, INFINITE);
			rs=r[0].serieParcial+r[1].serieParcial+r[2].serieParcial;
		}break;
		case 4:{
			HANDLE h1=NULL, h2=NULL, h3=NULL, h4=NULL;
			h1=CreateThread(NULL, 0, serie, (void *)&r[0], 0, NULL);
			h2=CreateThread(NULL, 0, serie, (void *)&r[1], 0, NULL);
			h3=CreateThread(NULL, 0, serie, (void *)&r[2], 0, NULL);
			h4=CreateThread(NULL, 0, serie, (void *)&r[4], 0, NULL);
			WaitForSingleObject(h1, INFINITE);
			WaitForSingleObject(h2, INFINITE);
			WaitForSingleObject(h3, INFINITE);
			WaitForSingleObject(h4, INFINITE);
			rs=r[0].serieParcial+r[1].serieParcial+r[2].serieParcial+r[3].serieParcial;
		}break;
		case 5:{
			HANDLE h1=NULL, h2=NULL, h3=NULL, h4=NULL, h5=NULL;
			h1=CreateThread(NULL, 0, serie, (void *)&r[0], 0, NULL);
			h2=CreateThread(NULL, 0, serie, (void *)&r[1], 0, NULL);
			h3=CreateThread(NULL, 0, serie, (void *)&r[2], 0, NULL);
			h4=CreateThread(NULL, 0, serie, (void *)&r[3], 0, NULL);
			h5=CreateThread(NULL, 0, serie, (void *)&r[4], 0, NULL);
			WaitForSingleObject(h1, INFINITE);
			WaitForSingleObject(h2, INFINITE);
			WaitForSingleObject(h3, INFINITE);
			WaitForSingleObject(h4, INFINITE);
			WaitForSingleObject(h5, INFINITE);
			rs=r[0].serieParcial+r[1].serieParcial+r[2].serieParcial+r[3].serieParcial+r[4].serieParcial;
		}break;
		case 6:{
			HANDLE h1=NULL, h2=NULL, h3=NULL, h4=NULL, h5=NULL, h6=NULL;
			h1=CreateThread(NULL, 0, serie, (void *)&r[0], 0, NULL);
			h2=CreateThread(NULL, 0, serie, (void *)&r[1], 0, NULL);
			h3=CreateThread(NULL, 0, serie, (void *)&r[2], 0, NULL);
			h4=CreateThread(NULL, 0, serie, (void *)&r[3], 0, NULL);
			h5=CreateThread(NULL, 0, serie, (void *)&r[4], 0, NULL);
			h6=CreateThread(NULL, 0, serie, (void *)&r[5], 0, NULL);
			WaitForSingleObject(h1, INFINITE);
			WaitForSingleObject(h2, INFINITE);
			WaitForSingleObject(h3, INFINITE);
			WaitForSingleObject(h4, INFINITE);
			WaitForSingleObject(h5, INFINITE);
			WaitForSingleObject(h6, INFINITE);
			rs=r[0].serieParcial+r[1].serieParcial+r[2].serieParcial+r[3].serieParcial+r[4].serieParcial+r[5].serieParcial;
		}break;
		case 7:{
			HANDLE h1=NULL, h2=NULL, h3=NULL, h4=NULL, h5=NULL, h6=NULL, h7=NULL;
			h1=CreateThread(NULL, 0, serie, (void *)&r[0], 0, NULL);
			h2=CreateThread(NULL, 0, serie, (void *)&r[1], 0, NULL);
			h3=CreateThread(NULL, 0, serie, (void *)&r[2], 0, NULL);
			h4=CreateThread(NULL, 0, serie, (void *)&r[3], 0, NULL);
			h5=CreateThread(NULL, 0, serie, (void *)&r[4], 0, NULL);
			h6=CreateThread(NULL, 0, serie, (void *)&r[5], 0, NULL);
			h7=CreateThread(NULL, 0, serie, (void *)&r[6], 0, NULL);
			WaitForSingleObject(h1, INFINITE);
			WaitForSingleObject(h2, INFINITE);
			WaitForSingleObject(h3, INFINITE);
			WaitForSingleObject(h4, INFINITE);
			WaitForSingleObject(h5, INFINITE);
			WaitForSingleObject(h6, INFINITE);
			WaitForSingleObject(h7, INFINITE);
			rs=r[0].serieParcial+r[1].serieParcial+r[2].serieParcial+r[3].serieParcial+r[4].serieParcial+r[5].serieParcial+r[6].serieParcial;
		}break;
		case 8:{
			HANDLE h1=NULL, h2=NULL, h3=NULL, h4=NULL, h5=NULL, h6=NULL, h7=NULL, h8=NULL;
			h1=CreateThread(NULL, 0, serie, (void *)&r[0], 0, NULL);
			h2=CreateThread(NULL, 0, serie, (void *)&r[1], 0, NULL);
			h3=CreateThread(NULL, 0, serie, (void *)&r[2], 0, NULL);
			h4=CreateThread(NULL, 0, serie, (void *)&r[3], 0, NULL);
			h5=CreateThread(NULL, 0, serie, (void *)&r[4], 0, NULL);
			h6=CreateThread(NULL, 0, serie, (void *)&r[5], 0, NULL);
			h7=CreateThread(NULL, 0, serie, (void *)&r[6], 0, NULL);
			h8=CreateThread(NULL, 0, serie, (void *)&r[7], 0, NULL);
			WaitForSingleObject(h1, INFINITE);
			WaitForSingleObject(h2, INFINITE);
			WaitForSingleObject(h3, INFINITE);
			WaitForSingleObject(h4, INFINITE);
			WaitForSingleObject(h5, INFINITE);
			WaitForSingleObject(h6, INFINITE);
			WaitForSingleObject(h7, INFINITE);
			WaitForSingleObject(h8, INFINITE);
			rs=r[0].serieParcial+r[1].serieParcial+r[2].serieParcial+r[3].serieParcial+r[4].serieParcial+r[5].serieParcial+r[6].serieParcial+r[7].serieParcial;
		}break;
		case 9:{
			HANDLE h1=NULL, h2=NULL, h3=NULL, h4=NULL, h5=NULL, h6=NULL, h7=NULL, h8=NULL, h9=NULL;
			h1=CreateThread(NULL, 0, serie, (void *)&r[0], 0, NULL);
			h2=CreateThread(NULL, 0, serie, (void *)&r[1], 0, NULL);
			h3=CreateThread(NULL, 0, serie, (void *)&r[2], 0, NULL);
			h4=CreateThread(NULL, 0, serie, (void *)&r[3], 0, NULL);
			h5=CreateThread(NULL, 0, serie, (void *)&r[4], 0, NULL);
			h6=CreateThread(NULL, 0, serie, (void *)&r[5], 0, NULL);
			h7=CreateThread(NULL, 0, serie, (void *)&r[6], 0, NULL);
			h8=CreateThread(NULL, 0, serie, (void *)&r[7], 0, NULL);
			h9=CreateThread(NULL, 0, serie, (void *)&r[8], 0, NULL);
			WaitForSingleObject(h1, INFINITE);
			WaitForSingleObject(h2, INFINITE);
			WaitForSingleObject(h3, INFINITE);
			WaitForSingleObject(h4, INFINITE);
			WaitForSingleObject(h5, INFINITE);
			WaitForSingleObject(h6, INFINITE);
			WaitForSingleObject(h7, INFINITE);
			WaitForSingleObject(h8, INFINITE);
			WaitForSingleObject(h9, INFINITE);
			rs=r[0].serieParcial+r[1].serieParcial+r[2].serieParcial+r[3].serieParcial+r[4].serieParcial+r[5].serieParcial+r[6].serieParcial+r[7].serieParcial+r[8].serieParcial;
		}break;
		case 10:{
			HANDLE h1=NULL, h2=NULL, h3=NULL, h4=NULL, h5=NULL, h6=NULL, h7=NULL, h8=NULL, h9=NULL, h10=NULL;
			h1=CreateThread(NULL, 0, serie, (void *)&r[0], 0, NULL);
			h2=CreateThread(NULL, 0, serie, (void *)&r[1], 0, NULL);
			h3=CreateThread(NULL, 0, serie, (void *)&r[2], 0, NULL);
			h4=CreateThread(NULL, 0, serie, (void *)&r[3], 0, NULL);
			h5=CreateThread(NULL, 0, serie, (void *)&r[4], 0, NULL);
			h6=CreateThread(NULL, 0, serie, (void *)&r[5], 0, NULL);
			h7=CreateThread(NULL, 0, serie, (void *)&r[6], 0, NULL);
			h8=CreateThread(NULL, 0, serie, (void *)&r[7], 0, NULL);
			h9=CreateThread(NULL, 0, serie, (void *)&r[8], 0, NULL);
			h10=CreateThread(NULL, 0, serie, (void *)&r[9], 0, NULL);
			WaitForSingleObject(h1, INFINITE);
			WaitForSingleObject(h2, INFINITE);
			WaitForSingleObject(h3, INFINITE);
			WaitForSingleObject(h4, INFINITE);
			WaitForSingleObject(h5, INFINITE);
			WaitForSingleObject(h6, INFINITE);
			WaitForSingleObject(h7, INFINITE);
			WaitForSingleObject(h8, INFINITE);
			WaitForSingleObject(h9, INFINITE);
			WaitForSingleObject(h10, INFINITE);
			rs=r[0].serieParcial+r[1].serieParcial+r[2].serieParcial+r[3].serieParcial+r[4].serieParcial+r[5].serieParcial+r[6].serieParcial+r[7].serieParcial+r[8].serieParcial+r[9].serieParcial;
		}break;
		case 11:{
			HANDLE h1=NULL, h2=NULL, h3=NULL, h4=NULL, h5=NULL, h6=NULL, h7=NULL, h8=NULL, h9=NULL, h10=NULL, h11=NULL;
			h1=CreateThread(NULL, 0, serie, (void *)&r[0], 0, NULL);
			h2=CreateThread(NULL, 0, serie, (void *)&r[1], 0, NULL);
			h3=CreateThread(NULL, 0, serie, (void *)&r[2], 0, NULL);
			h4=CreateThread(NULL, 0, serie, (void *)&r[3], 0, NULL);
			h5=CreateThread(NULL, 0, serie, (void *)&r[4], 0, NULL);
			h6=CreateThread(NULL, 0, serie, (void *)&r[5], 0, NULL);
			h7=CreateThread(NULL, 0, serie, (void *)&r[6], 0, NULL);
			h8=CreateThread(NULL, 0, serie, (void *)&r[7], 0, NULL);
			h9=CreateThread(NULL, 0, serie, (void *)&r[8], 0, NULL);
			h10=CreateThread(NULL, 0, serie, (void *)&r[9], 0, NULL);
			h11=CreateThread(NULL, 0, serie, (void *)&r[10], 0, NULL);
			WaitForSingleObject(h1, INFINITE);
			WaitForSingleObject(h2, INFINITE);
			WaitForSingleObject(h3, INFINITE);
			WaitForSingleObject(h4, INFINITE);
			WaitForSingleObject(h5, INFINITE);
			WaitForSingleObject(h6, INFINITE);
			WaitForSingleObject(h7, INFINITE);
			WaitForSingleObject(h8, INFINITE);
			WaitForSingleObject(h9, INFINITE);
			WaitForSingleObject(h10, INFINITE);
			WaitForSingleObject(h11, INFINITE);
			rs=r[0].serieParcial+r[1].serieParcial+r[2].serieParcial+r[3].serieParcial+r[4].serieParcial+r[5].serieParcial+r[6].serieParcial+r[7].serieParcial+r[8].serieParcial+r[9].serieParcial+r[10].serieParcial;
		}break;
		case 12:{
			HANDLE h1=NULL, h2=NULL, h3=NULL, h4=NULL, h5=NULL, h6=NULL, h7=NULL, h8=NULL, h9=NULL, h10=NULL, h11=NULL, h12=NULL;
			h1=CreateThread(NULL, 0, serie, (void *)&r[0], 0, NULL);
			h2=CreateThread(NULL, 0, serie, (void *)&r[1], 0, NULL);
			h3=CreateThread(NULL, 0, serie, (void *)&r[2], 0, NULL);
			h4=CreateThread(NULL, 0, serie, (void *)&r[3], 0, NULL);
			h5=CreateThread(NULL, 0, serie, (void *)&r[4], 0, NULL);
			h6=CreateThread(NULL, 0, serie, (void *)&r[5], 0, NULL);
			h7=CreateThread(NULL, 0, serie, (void *)&r[6], 0, NULL);
			h8=CreateThread(NULL, 0, serie, (void *)&r[7], 0, NULL);
			h9=CreateThread(NULL, 0, serie, (void *)&r[8], 0, NULL);
			h10=CreateThread(NULL, 0, serie, (void *)&r[9], 0, NULL);
			h11=CreateThread(NULL, 0, serie, (void *)&r[10], 0, NULL);
			h12=CreateThread(NULL, 0, serie, (void *)&r[11], 0, NULL);
			WaitForSingleObject(h1, INFINITE);
			WaitForSingleObject(h2, INFINITE);
			WaitForSingleObject(h3, INFINITE);
			WaitForSingleObject(h4, INFINITE);
			WaitForSingleObject(h5, INFINITE);
			WaitForSingleObject(h6, INFINITE);
			WaitForSingleObject(h7, INFINITE);
			WaitForSingleObject(h8, INFINITE);
			WaitForSingleObject(h9, INFINITE);
			WaitForSingleObject(h10, INFINITE);
			WaitForSingleObject(h11, INFINITE);
			WaitForSingleObject(h12, INFINITE);
			rs=r[0].serieParcial+r[1].serieParcial+r[2].serieParcial+r[3].serieParcial+r[4].serieParcial+r[5].serieParcial+r[6].serieParcial+r[7].serieParcial+r[8].serieParcial+r[9].serieParcial+r[10].serieParcial+r[11].serieParcial;
		}break;
		case 13:{
			HANDLE h1=NULL, h2=NULL, h3=NULL, h4=NULL, h5=NULL, h6=NULL, h7=NULL, h8=NULL, h9=NULL, h10=NULL, h11=NULL, h12=NULL, h13=NULL;
			h1=CreateThread(NULL, 0, serie, (void *)&r[0], 0, NULL);
			h2=CreateThread(NULL, 0, serie, (void *)&r[1], 0, NULL);
			h3=CreateThread(NULL, 0, serie, (void *)&r[2], 0, NULL);
			h4=CreateThread(NULL, 0, serie, (void *)&r[3], 0, NULL);
			h5=CreateThread(NULL, 0, serie, (void *)&r[4], 0, NULL);
			h6=CreateThread(NULL, 0, serie, (void *)&r[5], 0, NULL);
			h7=CreateThread(NULL, 0, serie, (void *)&r[6], 0, NULL);
			h8=CreateThread(NULL, 0, serie, (void *)&r[7], 0, NULL);
			h9=CreateThread(NULL, 0, serie, (void *)&r[8], 0, NULL);
			h10=CreateThread(NULL, 0, serie, (void *)&r[9], 0, NULL);
			h11=CreateThread(NULL, 0, serie, (void *)&r[10], 0, NULL);
			h12=CreateThread(NULL, 0, serie, (void *)&r[11], 0, NULL);
			h13=CreateThread(NULL, 0, serie, (void *)&r[12], 0, NULL);
			WaitForSingleObject(h1, INFINITE);
			WaitForSingleObject(h2, INFINITE);
			WaitForSingleObject(h3, INFINITE);
			WaitForSingleObject(h4, INFINITE);
			WaitForSingleObject(h5, INFINITE);
			WaitForSingleObject(h6, INFINITE);
			WaitForSingleObject(h7, INFINITE);
			WaitForSingleObject(h8, INFINITE);
			WaitForSingleObject(h9, INFINITE);
			WaitForSingleObject(h10, INFINITE);
			WaitForSingleObject(h11, INFINITE);
			WaitForSingleObject(h12, INFINITE);
			WaitForSingleObject(h13, INFINITE);
			rs=r[0].serieParcial+r[1].serieParcial+r[2].serieParcial+r[3].serieParcial+r[4].serieParcial+r[5].serieParcial+r[6].serieParcial+r[7].serieParcial+r[8].serieParcial+r[9].serieParcial+r[10].serieParcial+r[11].serieParcial+r[12].serieParcial;
		}break;
		case 14:{
			HANDLE h1=NULL, h2=NULL, h3=NULL, h4=NULL, h5=NULL, h6=NULL, h7=NULL, h8=NULL, h9=NULL, h10=NULL, h11=NULL, h12=NULL, h13=NULL, h14=NULL;
			h1=CreateThread(NULL, 0, serie, (void *)&r[0], 0, NULL);
			h2=CreateThread(NULL, 0, serie, (void *)&r[1], 0, NULL);
			h3=CreateThread(NULL, 0, serie, (void *)&r[2], 0, NULL);
			h4=CreateThread(NULL, 0, serie, (void *)&r[3], 0, NULL);
			h5=CreateThread(NULL, 0, serie, (void *)&r[4], 0, NULL);
			h6=CreateThread(NULL, 0, serie, (void *)&r[5], 0, NULL);
			h7=CreateThread(NULL, 0, serie, (void *)&r[6], 0, NULL);
			h8=CreateThread(NULL, 0, serie, (void *)&r[7], 0, NULL);
			h9=CreateThread(NULL, 0, serie, (void *)&r[8], 0, NULL);
			h10=CreateThread(NULL, 0, serie, (void *)&r[9], 0, NULL);
			h11=CreateThread(NULL, 0, serie, (void *)&r[10], 0, NULL);
			h12=CreateThread(NULL, 0, serie, (void *)&r[11], 0, NULL);
			h13=CreateThread(NULL, 0, serie, (void *)&r[12], 0, NULL);
			h14=CreateThread(NULL, 0, serie, (void *)&r[13], 0, NULL);
			WaitForSingleObject(h1, INFINITE);
			WaitForSingleObject(h2, INFINITE);
			WaitForSingleObject(h3, INFINITE);
			WaitForSingleObject(h4, INFINITE);
			WaitForSingleObject(h5, INFINITE);
			WaitForSingleObject(h6, INFINITE);
			WaitForSingleObject(h7, INFINITE);
			WaitForSingleObject(h8, INFINITE);
			WaitForSingleObject(h9, INFINITE);
			WaitForSingleObject(h10, INFINITE);
			WaitForSingleObject(h11, INFINITE);
			WaitForSingleObject(h12, INFINITE);
			WaitForSingleObject(h13, INFINITE);
			WaitForSingleObject(h14, INFINITE);
			rs=r[0].serieParcial+r[1].serieParcial+r[2].serieParcial+r[3].serieParcial+r[4].serieParcial+r[5].serieParcial+r[6].serieParcial+r[7].serieParcial+r[8].serieParcial+r[9].serieParcial+r[10].serieParcial+r[11].serieParcial+r[12].serieParcial+r[13].serieParcial;
		}break;
		case 15:{
			HANDLE h1=NULL, h2=NULL, h3=NULL, h4=NULL, h5=NULL, h6=NULL, h7=NULL, h8=NULL, h9=NULL, h10=NULL, h11=NULL, h12=NULL, h13=NULL, h14=NULL, h15=NULL;
			h1=CreateThread(NULL, 0, serie, (void *)&r[0], 0, NULL);
			h2=CreateThread(NULL, 0, serie, (void *)&r[1], 0, NULL);
			h3=CreateThread(NULL, 0, serie, (void *)&r[2], 0, NULL);
			h4=CreateThread(NULL, 0, serie, (void *)&r[3], 0, NULL);
			h5=CreateThread(NULL, 0, serie, (void *)&r[4], 0, NULL);
			h6=CreateThread(NULL, 0, serie, (void *)&r[5], 0, NULL);
			h7=CreateThread(NULL, 0, serie, (void *)&r[6], 0, NULL);
			h8=CreateThread(NULL, 0, serie, (void *)&r[7], 0, NULL);
			h9=CreateThread(NULL, 0, serie, (void *)&r[8], 0, NULL);
			h10=CreateThread(NULL, 0, serie, (void *)&r[9], 0, NULL);
			h11=CreateThread(NULL, 0, serie, (void *)&r[10], 0, NULL);
			h12=CreateThread(NULL, 0, serie, (void *)&r[11], 0, NULL);
			h13=CreateThread(NULL, 0, serie, (void *)&r[12], 0, NULL);
			h14=CreateThread(NULL, 0, serie, (void *)&r[13], 0, NULL);
			h15=CreateThread(NULL, 0, serie, (void *)&r[14], 0, NULL);
			WaitForSingleObject(h1, INFINITE);
			WaitForSingleObject(h2, INFINITE);
			WaitForSingleObject(h3, INFINITE);
			WaitForSingleObject(h4, INFINITE);
			WaitForSingleObject(h5, INFINITE);
			WaitForSingleObject(h6, INFINITE);
			WaitForSingleObject(h7, INFINITE);
			WaitForSingleObject(h8, INFINITE);
			WaitForSingleObject(h9, INFINITE);
			WaitForSingleObject(h10, INFINITE);
			WaitForSingleObject(h11, INFINITE);
			WaitForSingleObject(h12, INFINITE);
			WaitForSingleObject(h13, INFINITE);
			WaitForSingleObject(h14, INFINITE);
			WaitForSingleObject(h15, INFINITE);
			rs=r[0].serieParcial+r[1].serieParcial+r[2].serieParcial+r[3].serieParcial+r[4].serieParcial+r[5].serieParcial+r[6].serieParcial+r[7].serieParcial+r[8].serieParcial+r[9].serieParcial+r[10].serieParcial+r[11].serieParcial+r[12].serieParcial+r[13].serieParcial+r[14].serieParcial;
		}break;
		default{
			HANDLE h1=NULL, h2=NULL, h3=NULL, h4=NULL, h5=NULL, h6=NULL, h7=NULL, h8=NULL, h9=NULL, h10=NULL, h11=NULL, h12=NULL, h13=NULL, h14=NULL, h15=NULL, h16=NULL;
			h1=CreateThread(NULL, 0, serie, (void *)&r[0], 0, NULL);
			h2=CreateThread(NULL, 0, serie, (void *)&r[1], 0, NULL);
			h3=CreateThread(NULL, 0, serie, (void *)&r[2], 0, NULL);
			h4=CreateThread(NULL, 0, serie, (void *)&r[3], 0, NULL);
			h5=CreateThread(NULL, 0, serie, (void *)&r[4], 0, NULL);
			h6=CreateThread(NULL, 0, serie, (void *)&r[5], 0, NULL);
			h7=CreateThread(NULL, 0, serie, (void *)&r[6], 0, NULL);
			h8=CreateThread(NULL, 0, serie, (void *)&r[7], 0, NULL);
			h9=CreateThread(NULL, 0, serie, (void *)&r[8], 0, NULL);
			h10=CreateThread(NULL, 0, serie, (void *)&r[9], 0, NULL);
			h11=CreateThread(NULL, 0, serie, (void *)&r[10], 0, NULL);
			h12=CreateThread(NULL, 0, serie, (void *)&r[11], 0, NULL);
			h13=CreateThread(NULL, 0, serie, (void *)&r[12], 0, NULL);
			h14=CreateThread(NULL, 0, serie, (void *)&r[13], 0, NULL);
			h15=CreateThread(NULL, 0, serie, (void *)&r[14], 0, NULL);
			h16=CreateThread(NULL, 0, serie, (void *)&r[15], 0, NULL);
			WaitForSingleObject(h1, INFINITE);
			WaitForSingleObject(h2, INFINITE);
			WaitForSingleObject(h3, INFINITE);
			WaitForSingleObject(h4, INFINITE);
			WaitForSingleObject(h5, INFINITE);
			WaitForSingleObject(h6, INFINITE);
			WaitForSingleObject(h7, INFINITE);
			WaitForSingleObject(h8, INFINITE);
			WaitForSingleObject(h9, INFINITE);
			WaitForSingleObject(h10, INFINITE);
			WaitForSingleObject(h11, INFINITE);
			WaitForSingleObject(h12, INFINITE);
			WaitForSingleObject(h13, INFINITE);
			WaitForSingleObject(h14, INFINITE);
			WaitForSingleObject(h15, INFINITE);
			WaitForSingleObject(h16, INFINITE);
			rs=r[0].serieParcial+r[1].serieParcial+r[2].serieParcial+r[3].serieParcial+r[4].serieParcial+r[5].serieParcial+r[6].serieParcial+r[7].serieParcial+r[8].serieParcial+r[9].serieParcial+r[10].serieParcial+r[11].serieParcial+r[12].serieParcial+r[13].serieParcial+r[14].serieParcial+r[15].serieParcial;
		}
	}
  long long seg=1000*(fin-inicio)/CLOCKS_PER_SEC;
  printf("%d\n",seg);
  printf("%.10f\n", 4*rs);
  system("pause");
  return 0;
}


DWORD WINAPI serie(void *){
	Rango *r=(R*)p;
	int i;
	for(i=r->inicios;i<=r->fins;i++)
		r->serieParcial+=(i&1?-1.0:1.0)/(2.0*i+1);
	return 0;
}
