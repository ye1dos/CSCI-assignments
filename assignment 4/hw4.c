#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct _Node{
    char strData[50];
    struct _Node *next;
}Node;


void appendNode(Node **oLinkedList, char outputLine[]) {
    if(*oLinkedList == NULL){
        *oLinkedList = (Node*)malloc(sizeof(Node));
        strcpy((*oLinkedList)->strData, outputLine);
        (*oLinkedList)->next = NULL;
    }
    else {
        Node* this = *oLinkedList;
        Node* next = (*oLinkedList)->next;
        for(;;) {
            if(next==NULL) {
                this->next = (Node*) malloc(sizeof(Node));
                strcpy(this->next->strData, outputLine);
                this->next->next = NULL;
                break;
            }
            this = this->next;
            next = this->next;
        }
    }
}
void printLinkedlist(Node *head) {
    Node* this=head;
    for(;;) {
        if(this->next == NULL) {
            printf("%s", this->strData);
            break;
        }
        else {
            printf("%s", this->strData);
            this = this->next;
        }
    }
}
void freeLinkedlist(Node *head) {
    Node* this = head;
    Node* prev = NULL;
    for(;;) {
        if(this == NULL) {
            free(prev);
            break;
        }
        if(prev != NULL) {
            free(prev);
        }
        prev = this;
        this = this->next;
    }
}
int isPalindrome(char str[]){
    int i=0,a=0;
    int l=strlen(str);
    while(i<l-1){
        if(str[i]==str[l-i-1]){	//checks until the end of string
            a=1;
        }
        else{
            a=0;
        }
        i++;
    }
    return a;
}
char *getPalindrome(char str[]){
    char *palindrome;
    if(isPalindrome(str)==1){
        palindrome = "Is_Palindrome";
    }
    else{
        palindrome = "Not_Palindrome";
    }
    return palindrome;
}
int howManySubstrings(char subStr[], char str[]){
    int i;
    int sum=0;

    for(i=0; i<strlen(str)-2; i++){
        if(str[i]==subStr[0] && str[i+1]==subStr[1] && str[i+2]==subStr[2]){//comparing chars of str and substr then counting occurance of substr
            sum++;
            i=i+2;
        }
    }
    return sum;
}
void checkSubstringPalindrome2(char subStr[], char* iStringData[], Node** oLinkedList, int nrIOfileLines) {
    char* new = (char*)malloc(123*sizeof(char));
	int i;
	printf("%s\n",subStr);//printing substrs to the console
    for (i = 0; i < nrIOfileLines; i++) {
        strcpy(new, iStringData[i]);
        strcat(new, "\t");
        char ch[50];
        snprintf(ch, 256, "%d", howManySubstrings(subStr, iStringData[i]));	//storing chars to ch with size 64
        strcat(new, ch);
        strcat(new, "\t");
        strcat(new, getPalindrome(iStringData[i]));
        strcat(new, "\n");
        appendNode(oLinkedList, new);
    }
    free(new);
}


void readFile2(char filename[], char *ArrayPtr[]){
    FILE *ifile;
    char* str = (char*) malloc(50*sizeof(char));
    int i=0;
    ifile = fopen(filename , "r");
    if(ifile == NULL){
        printf("Problem");
        exit;
    }
    while(!feof(ifile)){
        if( fgets (str, 50, ifile)!=NULL ) {
            str[strlen(str)-1] = '\0';
            ArrayPtr[i] = malloc(strlen(str)*sizeof(char));
            strcpy(ArrayPtr[i],str);
            i++;
        }
    }
    free(str);
    fclose(ifile);
}
void writeFile2(char fileName[], char ssData[], Node **oLinkedList){
	int count=0;
    FILE *ostring;
    Node* this = *oLinkedList;
    ostring = fopen(fileName,"a");
    fprintf(ostring, "%s\n", ssData);
    for(;;) {
        fprintf(ostring, "%s", this->strData);
        this = this->next;
        if(this == NULL) 
		break;
    }
    fputc('\n',ostring);// putting blank line
	printf("\n"); //putting blank line to the console
    
    freeLinkedlist(*oLinkedList);
    *oLinkedList = NULL;
    fclose(ostring);
}

int countFileLines(char filename[20]){
    int count=0;
    char ch;
    FILE* istring;
    istring = fopen(filename, "r");
    while(!feof(istring)){
        ch = fgetc(istring);	//getting characters from files
        if(ch=='\n'){
            count++; 	//counting until the end of file
        }
    }
    fclose(istring);
    return count;
}
int main(){
    char *array[50];
    char *array2[50];
    char filename[] = "iStrings.txt";
    char filename2[] = "subStrings.txt";
    char filename3[] = "oStrings.txt";
    FILE *f1 = fopen(filename3, "w");
    if (f1 == NULL) {					//checking the file
        printf("CANNOT open file\n");
        return 1;
    }
    int a = countFileLines(filename);
    Node *head = NULL;
    int i;
    int b = countFileLines(filename2);
    readFile2(filename, array);
    readFile2(filename2, array2);
    for (i=0; i<b; i++){
        checkSubstringPalindrome2(array2[i], array, &head, a);
        printLinkedlist(head);
        
        writeFile2(filename3, array2[i], &head);
    }

    return 0;
}

/*START_CITE

http://www.tutorialspoint.com/c_standard_library/c_function_fgets

#include <stdio.h>

int main () {
   FILE *fp;
   char str[60];

   fp = fopen("file.txt" , "r");
   if(fp == NULL) {
      perror("Error opening file");
      return(-1);
   }
   if( fgets (str, 60, fp)!=NULL ) {
      puts(str);
   }
   fclose(fp);

   return(0);
}

https://www.allinterview.com/showanswers/122339/how-to-palindrom-string-in-c-language.html

#include<stdio.h>
#include<conio.h>
void main()
{
char n[6];
int i,l;
clrscr();
printf("enter string");
scanf("%s",n);
l=strlen(n);
if((l%2)==0)
exit(0);//length of string is even and cant be a palindrome
for(i=1;i<l/2;i++)
{
if(n[i]==n([l/2+i)])
i++;
else
printf("string is not palindrome");
}
getch();
}

END_CITE*/
