#include <stdio.h>
#include <time.h>
int main(){
	int i,my,c=0,x,d=0,f,y=9999;
	char s,n,q,m,name;
	srand (time(NULL));
	printf("WELCOME to the guessing game!\n");
	printf("MENU: (s) to start a game, (n) to set a new range, or (q) to quit:\n");
	while(m!='s' || m!='n' || m!='q'){
	scanf(" %c",&m);
	if (m=='s'){
		printf("The secret number is BETWEEN 0 AND %i. Guess:\n",y);
		name='s';
		}
	else if (m=='n'){
		printf("Enter a new MAXIMUM:\n");
		name='n';
		}
	else if (m=='q'){
		name='q';
		printf("Thanks for playing. ");
		if(d==0){
			printf("Your guess count AVERAGE %i.0 ",d);
		}
		}
	else{
		printf("UNRECOGNIZED command.\n");
		printf("MENU: (s) to start a game, (n) to set a new range, or (q) to quit:\n");
	}
	
	if(name=='s'){
		i=rand() % (y+1);
		d++;
		f=0;
		while(my!=i){
			scanf("%i",&my);
			if(my>i){
				printf("Too HIGH! ");
				printf("Guess:\n");
			}
			if(my<i){
				printf("Too LOW! ");
				printf("Guess:\n");
			}
			c++;
			f++;
		}
		printf("Correct: ");
		printf("You TOOK %i guesses!\n",f);
		printf("MENU: (s) to start a game, (n) to set a new range, or (q) to quit:\n");
	}
	
	if(name == 'n'){
		scanf("%i",&y);
		printf("MENU: (s) to start a game, (n) to set a new range, or (q) to quit:\n");
		i = rand()%(y+1);
	}
	else if(name=='q'){
		float e;
		e = c/d;
		printf("Your guess count AVERAGE %.1f ",e);
		break;
		}
	}
	return 0;
}
