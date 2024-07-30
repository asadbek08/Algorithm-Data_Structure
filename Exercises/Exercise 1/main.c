#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_R 101
#define MAX_L 21
#define MAX_N 100

typedef struct{
    char *word;
    int occurances;
}out;


void read_words(char *, out [], int *);
void read_text(char *, out [], int );
void display(out [], int );
int compare(char *, char *);

int main(int argc, char *argv[])
{
    out new[MAX_N];
    int n;
    if (argc<3){
        printf("Error: missing parameter.\n");
        printf("Run as: %s <text_file> <word_file>\n", argv[0]);
        return EXIT_FAILURE;
    }
    read_words(argv[2], new, &n);
    read_text(argv[1], new, n);
    display(new, n);

    EXIT_SUCCESS;

}

void read_words(char *name, out new[], int *num_ptr){
    FILE *fp;
    int i = 0;
    fp = fopen(name, "r");
    if (fp==NULL){
        printf("Error file memory %s\n", name);
        exit(EXIT_FAILURE);
    }
		int n;
		fscanf(fp, "%d",  &n);
    while(i < MAX_N && fscanf(fp, "%s",  new[i].word)!=EOF){
        new[i].occurances = 0;
        i++;
    }
    *num_ptr = i;
    fclose(fp);
    return;
}

void read_text(char *name, out new[], int n){
    FILE *fp;
		int i, j;
    char word[MAX_L];
    fp = fopen(name, "r");
    if (fp==NULL){
        printf("Error file memory\n");
        exit(EXIT_FAILURE);
    }
    i=1;
    while(fscanf(fp, "%s",  word)!=EOF ){
        for (j=0; j<n; j++ ){
            if (compare(word, new[j].word)==1){
                new[j].occurances++;
            }
        }
    i++;
    }
    fclose(fp);
}

void display(out new[], int n ){
    int i;
    for(i=0; i<n; i++){

        printf("%s - %d occurrence(s)\n", new[i].word, new[i].occurances);
    }
}

int compare(char *str1, char *str2){
    int i;
    if (strlen(str1)!=strlen(str2)){
        return 0;
        }
    for (i=0; i<strlen(str1); i++){
        if (tolower(str1[i])!=tolower(str2[i])){
          return 0;
        }
    }
    return 1;
}













