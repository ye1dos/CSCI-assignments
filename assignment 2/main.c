#include <stdio.h>
#include <string.h>


//Encryption function
void encrypt ( FILE *file, FILE *file1, unsigned char subarr[256], char pass[256] ){
	//initialization of variables
	int i=0,k=0,j=0;
	int ch,array[9999],indexofpass[9999],sum[9999];
	char str[256];
	int length = strlen(pass);					
	do {
	ch = fgetc(file);
	array[i] = ch;			//Counting the number of symbols in the text
	i++;
	}while (!feof(file));
	while(j<i){
		pass[j]=pass[j%length];
		indexofpass[k] = pass[j];
		j++;
		k++;
	}
	j=0;
	while(j<i){
		sum[j] = (array[j]+indexofpass[j])%254; // formula of encrypting 
		fputc(subarr[sum[j]],file1); // putting encrypted symbols into file
		j++;
	}

}

//Decryption function
void decrypt( FILE *file, FILE *file1, unsigned char subarr[256], char pass[256] ){
	//initialization of variables
	char ch,i=0,k=0;
	int decr,array[9999],indexofpass[9999],g=0,j=0,array1[9999];
	int length = strlen(pass);
	
	do { 		//Counting the number of symbols in the text
	ch = fgetc(file);
	array[i] = ch;	// i is a total number of characters in the file
	i++;
	}while (!feof(file));
	
	while(j<i){
		pass[j]=pass[j%length];
		indexofpass[k] = pass[j];
		j++;
		k++;
	}
	j=0;
	k=0;
	while(j<i){
		for (k=0; k<255; k++){
			 if (array[j] == subarr[k]){
     			array1[j] = k;
     			j++;
			}
		}
		
	}
	while(g<i){
		decr = (array1[g]-pass[g])%254; 	// formula of decrypting 
		fputc(decr,file1); // putting decrypted symbols into file
		g++;
	}
		
}

int main(){
	//initialization of variables
	char pass[255],str[255];
	int i,j=0;
	char ch,infile[100],outfile[100];
	unsigned char arrofkey[254],arrofkey1[254];
	int subarr[256];
	FILE *fin;
	FILE *fout;
	printf("WELCOME to encryption service.\n");
	printf("ENTER your password: ");
	scanf("%s",&pass);
	do{
	printf("MENU: <e>ncode, <d>ecode, or <q>uit\n");
	scanf("%s",&str);
		//Encryption process
	if (str[0]=='e'){
		// getting characters of "key.254" file
		FILE *keyfile;
		keyfile = fopen("key.254","r");
		for(i=0; i<255; i++){
		arrofkey[i] = getc(keyfile);
		j++;
		}
	
		printf("ENTER a filename to encrypt\n");
		scanf("%s", &infile);
		fin = fopen(infile,"r");
		// Processing of error
		if (fin == NULL) {
	 		printf("CANNOT open %s\n", infile);
	 		continue;
			 }
		//Encrypted file	 
		printf("ENTER a filename for the encrypted file\n");
		scanf("%s", &outfile);
		fout = fopen(outfile,"w");
		encrypt(fin, fout, arrofkey, pass); // function of encription
		fclose(fin);	// closing encrypted file
        fclose(fout); 	// closing decrypted file
	}

	// Decryption process
	else if (str[0]=='d'){
		// getting characters of "key.254" file
		FILE *keyfile;
		keyfile = fopen("key.254","r");
		for(i=0; i<255; i++){
		arrofkey1[i] = getc(keyfile);
		j++;
		}

		//Decrypt file
		printf("ENTER a file to decrypt\n");
		scanf("%s", &infile);
		fin = fopen(infile,"r");
		if (fin == NULL) {
	 		printf("CANNOT open %s\n", infile);
	 		continue;
			 }
		//Decrypted file	 
		printf("ENTER a filename for the decrypted file.\n");
		scanf("%s", &outfile);
		fout = fopen(outfile,"w");
		
		decrypt(fin, fout, arrofkey1, pass); 	// function of decription
		fclose(fin); // closing encrypted file
        fclose(fout); // closing decrypted file
		}
	//Quitting
	else if (str[0]=='q'){
		printf("BYE!");
		break;
	}
	else{
		//processing of unrecognised command
		printf("UNRECOGNIZED %s\n", str);
		printf("MENU: <e>ncode, <d>ecode, or <q>uit\n");
		scanf("%s",&str);
	}
}while(1);
	return 0;
}
