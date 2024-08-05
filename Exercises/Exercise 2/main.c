#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


#define D 100
typedef struct{
	int a;
	int b;
} prod;

void prodCartOrd(int *v1, int d1, int *v2, int d2) ;



int main(void) {
	int v1[] =  {1,3,5,6,7,8,8}, v2[]= {2,4,6,7,8,99,0};
	int d1= 7, d2=7;
	prodCartOrd(v1, d1, v2 ,d2);
  return 0;
}
void sorter(prod p[], int n){
	int i, j, imin;
	prod tmp;
	for (i = 0; i < n-1; i++){
		imin = i;
		for (j= i+1; j<n; j++){
			if (p[j].a+p[j].b< p[imin].a+p[imin].b){
				imin = j;
			}
		}
		tmp = p[i];
        p[i] = p[imin];
        p[imin]=tmp;
	}
}
void prodCartOrd(int *v1, int d1, int *v2, int d2){
	prod pv[D];
	int i, j;
	int n=0;
	for (i=0; i<d1; i++){
		for (j=0; j<d2; j++){
			pv[n].a=v1[i];
			pv[n].b=v2[j];
			n++;
		}
	}
	sorter(pv, n);

	for (int k=0; k<n; k++){
		printf("(%d, %d)\n", pv[k].a, pv[k].b);
	}

}
