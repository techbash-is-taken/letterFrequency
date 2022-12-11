#include <stdio.h>
#include <ctype.h>
#define ARRAY_LENGTH 26

static int letterFrequencyArray[ARRAY_LENGTH] = {0};
const char letters[ARRAY_LENGTH] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

void letterCounter(char letter){
    char letterLowered = tolower(letter);
    if(letterLowered>=97 && letterLowered<=122){ // diğer karakterleri scope dışı bırakmış olduk a --> 97 ; z --> 122
    int indexOfLetter = letterLowered - 'a'; //gelen harfin ascII değerinin 'a' harfine göre göreli konumu
    letterFrequencyArray[indexOfLetter]++;
    }
}

void printLetterFrequencyArray(){
    FILE *datafptr = fopen("../count.dat", "w");

    if(datafptr == NULL) {
        perror("Error in opening data file");
        return;
    }

    printf("%9s%6s%10s\n","Character","Count","dot-graph"); //ekrana yazdırmak için
    fprintf(datafptr, "%9s%6s%10s\n","Character","Count","dot-graph"); //dosyaya yazdırmak için

    for (int i = 0; i < ARRAY_LENGTH; i++){
        printf("%9c%6d ",letters[i],letterFrequencyArray[i]);
        fprintf(datafptr, "%9c%6d ",letters[i],letterFrequencyArray[i]); //dosyaya yazdırmak için
        for (int j = 0; j < letterFrequencyArray[i]; j++){
            printf("*"); //ekrana yazdırmak için
            fprintf(datafptr, "*");
        }
        printf("\n"); //ekrana yazdırmak için
        fprintf(datafptr, "\n");
    }

    fclose(datafptr);
}



int main () {
    FILE *fptr;
    int c;
    int n = 0;

    fptr = fopen("../input.txt", "r");

    if(fptr == NULL) {
        perror("Error in opening input file");
        return(-1);
    } do {
        c = fgetc(fptr);

        if( feof(fptr) ) {
            break;
        }else
            letterCounter(c);

    } while(1);

    printLetterFrequencyArray();
    fclose(fptr);
    return(0);
}