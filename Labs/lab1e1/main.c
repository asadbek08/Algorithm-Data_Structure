#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXW 20 + 1
#define MAXR 100
typedef struct{
	char *word;
	int occurances;
} index_t;

index_t *read_words(char *name, int *ptr);
void read_file(char *name, index_t *index, int n);
void display(index_t *index, int n);
int compare(char *src, char *dst);

int main(int argc, char *argv[]){
	index_t *index;
	int n;

	if (argc!=3) {
		printf("Run as <main> <input.file>, <output.file>\n " );
		exit(EXIT_FAILURE);
	}
	index = read_words(argv[2], &n);
	read_file(argv[1], index, n);
	display(index, n);
	for (int i=0; i<n; i++){
		free(index[i].word);
	}
	free(index);
	return EXIT_SUCCESS;

}

index_t *read_words(char *name, int *ptr){
	index_t *index;
	FILE *fp;
	char words[MAXW];
	int n, i;
	fp = fopen(name, "r");

	if(fp==NULL){
		printf("FILE opening error --> %s", name);
		exit(EXIT_FAILURE);
	} 

	if (fscanf(fp, "%d", &n)== EOF){
		printf("End of file");
		exit(EXIT_FAILURE);
	}
	
	index = (index_t *) malloc(n*sizeof(index_t));

	if (index == NULL) {
    fprintf (stderr, "Memory allocation error.\n");
    exit (EXIT_FAILURE);
  }	
	i = 0;
	while (i<n && fscanf(fp, "%s", words)!= EOF){
#if 1
		index[i].word = (char *) malloc((strlen(words)+1)* sizeof(char));
		if (index[i].word==NULL){
			printf("Memory allocation error");	
			exit(EXIT_FAILURE);
		}
		strcpy(index[i].word , words);
#else
		index[i].word = strdup(words);
	  
#endif 
		index[i].occurances = 0;
		i++;
	}
  *ptr = i;
	fclose(fp);
	return index;
}

void read_file(char *name, index_t *index, int n){
	FILE *fp;
	char wordss[MAXW];
	int i, j;
	fp = fopen(name, "r");
	if(fp==NULL) {
		printf("FILE opening error --> %s", name);
	}
	i=1;
	while (fscanf(fp, "%s", wordss)!= EOF) {
		for (j=0; j<n;j++){
			if (compare(wordss, index[j].word)==1){
				index[j].occurances++;
				
		  }
		}
	  i++;
	}
	fclose(fp);
}
void display(index_t *index, int n){
	int i;
	for(i=0; i<n; i++){
		fprintf(stdout, "%s is %d occurances\n", index[i].word, index[i].occurances);
		
	}
	return;
}
int compare(char *str1, char *str2) {
  int i;

  if (strlen(str1) != strlen(str2)) {
    return 0;
  }

  for (i=0; i<strlen(str1); i++) {
    if (tolower(str1[i]) != tolower(str2[i])) {
      return 0;
    }
  }
	return 1;
}