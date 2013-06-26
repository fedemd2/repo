#include <stdio.h>
#include <stdlib.h>
# define max 20
# define r 10


char mat[r][max], indice[r]={0}, cont[r]={0};
char s_conc[max*r];

// prototipi di funzione
void in();
void conteggio();
void stampa();
void conc();
void search();

// implementazioni di funzione
void in(){
			int i, flag=0;
			for(i=0; i<r && flag==0; i++){
				printf("\n\nInserisci la stringa %d:   ", i+1);
				fflush(stdin);
				
				scanf("%[^\n]s", &mat[i]);
				indice[i]=1;
				if(mat[i][0]== '0'){
					flag=1;
					mat[i][0]='\0';
					indice[i]=0;
				}
											
			}
}

void stampa(){
				int i;
				for(i=0; i<r && indice[i]==1; i++){
					printf("\n\nStringa %d: %s\n\n", i+1, mat[i]);														
				}				
				system("pause");
}

void conteggio(){
	int i,j;
	for(i=0; i<r && indice[i]==1; i++){
		for(j=0; j<max ; j++){
					if(mat[i][j]!='\0')																								
						cont[i]++;
		}
		
									
	}
}


void conc(){
			int i, j=0, x ;
			
			conteggio();
			for(i=0; i<r; i++){
				for(x=0; x<cont[i]; x++){
					s_conc[j]=mat[i][x];
					j++;
				}
				
			}
			printf("\n\nLa stringa concatenata e':  %s\n\n", s_conc);
			system("pause");

}

void search(){
              int i, j, ok=1, s=0, lun=0;
              char vet[max];
              
              printf("\nInserisci la parola da ricercare. Ricorda massimo 20 caratteri:  ");
              scanf("%s\n", vet);
              for(i=0; vet[i]!='\0'; i++){
                       lun++;
              }
              for(i=0; i<r && indice[i]==1 && ok==1; i++){
                    for(j=0; j<max && mat[i][j]!='\0' && ok==1; j++){
                             if(vet[j]==mat[i][j]){
                                                   s++;                                                   
                             }
                             else
                                 ok=0;
                    }                   
              }
              
              if(s==lun){
                         printf("\nLa parola ricercata e' presente!");
              }
              else 
                   printf("\nLa parola ricercata non e' presente!");
              
              system("pause");    
}



int main(){
			int scelta=0, exit=0;
			while (exit!=1){
			system("cls");
			printf("\n\n");
			printf("1) Inserisci delle stringhe\n\n");
			printf("2) Stampa delle stinghe inserite\n\n");
			printf("3) Stampa tutte le stringhe concatenate\n\n");
			printf("4) Ricerca una parola nella stringa concatenata\n\n");
			printf("5) Esci\n");
			printf("\nScelta:  ");
			scanf("%d", &scelta);
			
			switch(scelta){
							case 1: system("cls");
									in();
									break;

							case 2: system("cls");
									stampa();
									break;
							case 3: system("cls");
									conc();
									break;
							case 4:
                                    system ("cls");
                                    search();
                                    break;
                                    
							case 5: exit=1;
							        break;
							default:
									printf("Selezione non valida !");
									break;
			}
			printf("\n\n");			
			}
			getchar();
			getchar();
			return 0;
}
