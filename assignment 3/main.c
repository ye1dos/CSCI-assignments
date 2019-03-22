	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>

	void writeFile(char fileName[], char ssData[], char oStringData[][50], int nrIOfileLines){
	int count=0;
	FILE *ostring;
	ostring = fopen(fileName,"a");
	fprintf(ostring, "%s\n", ssData);
	while(count<nrIOfileLines){
		
	fprintf(ostring, "%s", oStringData[count]);
	count++;
	
	} 
	fputc('\n', ostring); 
	
	fclose(ostring); 
	 
}

	int isPalindrome(char str[]){
		int i=0,a=0;
		int l=strlen(str);
		while(i<=l/2){
		if(str[i]==str[l-i-1]){
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
			if(str[i]==subStr[1] && str[i+1]==subStr[2] && str[i+2]==subStr[3]){
				sum++;
				i=i+2;
			}
		}
			return sum;
	}

	void checkSubstringPalindrome(char subStr[], char iStringData[][50], char oStringData[][50], int nrIOfileLines){
		int i=0,count=0,numofsub;
		char a[50];
		while(i<nrIOfileLines){
		numofsub = howManySubstrings(subStr, iStringData[i]);
		strcpy(a,getPalindrome(iStringData[i]));
		sprintf(oStringData[count], "%s\t%i\t%s\n",iStringData[i],numofsub,a);
			count++;
			i++;
			}
		}

	void readFile(char filename[], char twoDimArr[][50]){
	FILE *ifile;
   char str[999];
   int i=0;
   ifile = fopen(filename , "r");
   	while(!feof(ifile)){
   if( fgets (str, 999, ifile)!=NULL ) {
      strcpy(twoDimArr,str);
	   }
   }
   fclose(ifile);
}
	int countFileLines(char filename[20]){
		int count=0;
		char ch;
		FILE* istring; 
		istring = fopen(filename, "r");
		while(!feof(istring)){
			ch = fgetc(istring);
			if(ch=='\n'){
				count++;
			}
		}
		fclose(istring);
		return count;
	}
	int main(){
		char filename[] = "iStrings.txt";
		char filename2[] = "subStrings.txt";
		char filename3[] = "oStrings.txt";

		int a = countFileLines(filename);
		//printf("%i",a);
		char twoDimArr[256][50];
		int i;
		int b = countFileLines(filename2);
		char subStr[256][50];
		char oStringData[256][50];
		char iStringData[256][50];
		readFile(filename, twoDimArr);
		readFile(filename2, subStr);
		int c = howManySubstrings( subStr, twoDimArr);
		//printf("%i",c);
		for (i=0; i<b; i++){
			checkSubstringPalindrome(subStr[i], iStringData, oStringData, b); 
			writeFile(filename3, subStr[i], oStringData, b); 
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
