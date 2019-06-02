#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <conio.h>

int stch;
int arr[10]={0};

FILE *database;

int generate(char);
int addQuestions(char);
int *random(int);
int countlines(char);

void gotoxy(int x,int y){
    COORD coord={0,0};
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void main(void){
	system("color e3");
	gotoxy(45,7);
	printf("QUESTION PAPER GENERATOR");
	sleep(1);
	
papermenu: system("cls");
	gotoxy(45,8);
	printf("SELECT ONE OF THE FOLLOWING:-");
	gotoxy(45,9);
	printf("1) Generate Question Paper.");
	gotoxy(45,10);
	printf("2) Add Questions.");
	gotoxy(45,12);
	printf("Enter the option:-");
	scanf("%d",&stch);
	
	switch(stch){
		case 1:
ppr_gen_menu: system("cls");
			gotoxy(45,8);
			printf("GENERATE PAPER OF SUBJECT:-");
			gotoxy(45,9);
			printf("1) Physics");
			gotoxy(45,10);
			printf("2) Chemistry");
			gotoxy(45,11);
			printf("3) Maths");
			gotoxy(45,12);
			printf("4) GO BACK.");
			gotoxy(45,14);
			printf("Enter the option:-");
			scanf("%d",&stch);
			switch(stch){
				case 1:
					generate('p');
					break;
				case 2:
					generate('c');
					break;
				case 3:
					generate('m');
					break;
				case 4:
					goto papermenu;
					break;
				default:
					system("cls");
					gotoxy(45,12);
					printf("value Entered is wrong.");
					sleep(2);
					goto ppr_gen_menu;	
					break;
			} 
			break;
		case 2:
add_qsn_menu: system("cls");
			gotoxy(45,8);
			printf("SELECT SUBJECT:-");
			gotoxy(45,9);
			printf("1) Physics");
			gotoxy(45,10);
			printf("2) Chemistry");
			gotoxy(45,11);
			printf("3) Maths");
			gotoxy(45,12);;
			printf("4) GO BACK.");
			gotoxy(45,14);
			printf("Enter the option:-");
			scanf("%d",&stch);
			switch(stch){
				case 1:
					addQuestions('p');
					break;
				case 2:
					addQuestions('c');
					break;
				case 3:
					addQuestions('m');
					break;
				case 4:
					goto papermenu;
					break;
				default:
					system("cls");
					gotoxy(45,12);
					printf("value Entered is wrong.");
					sleep(2);
					goto add_qsn_menu;	
					break;
			}
			break;
		default:
			system("cls");
			gotoxy(45,10);
			printf("Value entered is incorrect.");
			sleep(2);
			goto papermenu;
			break;
	}
}

int addQuestions(char subject){
	char data[200],re;
	
re_add: if(subject=='p'){
		system("cls");
		database=fopen("physics.txt","a");
    	if(database==NULL){
    		gotoxy(45,12);
       		printf("Could not open physics database");
        	return 1;
    	}
    	gotoxy(45,12);
    	printf("Enter question.");
    	gotoxy(45,13);
    	gets(data);
    	while(strlen(gets(data))>0){
        	fputs(data, database) ;   
        	fputs("\n", database) ;
    	}
    }
    else if(subject=='c'){
    	system("cls");
		database=fopen("chemistry.txt","a");
    	if(database==NULL){
    		gotoxy(45,12);
       		printf("Could not open chemistry database");
        	return 1;
    	}
    	gotoxy(45,12);
    	printf("Enter question.\n");
    	gotoxy(45,13);
    	gets(data);
    	while(strlen(gets(data))>0){
        	fputs(data, database) ;   
        	fputs("\n", database) ;
    	}
    }
    else if(subject=='m'){
    	system("cls");
		database=fopen("maths.txt","a");
    	if(database==NULL){
    		gotoxy(45,12);
       		printf("Could not open maths database");
    	}
    	gotoxy(45,12);
    	printf("Enter question.\n");
    	gotoxy(45,13);
    	gets(data);
    	while(strlen(gets(data))>0){
        	fputs(data,database);   
        	fputs("\n",database);
    	}
    }
    gotoxy(38,15);
    printf("DO YOU WANT TO ADD MORE QUESTIONS(Y/N):- ");
    scanf("%c",&re);
    
    if(re=='y'||re=='Y'){
    	goto re_add;
	}
	else if(re=='n'||re=='N'){
		system("cls");
		gotoxy(45,12);
    	printf("Closing database.");
    	fclose(database);
	}
	getch();
}

int generate(char subject){
	int no_of_lines,*ran_pointer,i,j,line=1,val=0;
	char data[200],filename[20];

	if(subject=='p'){
		database = fopen("physics.txt", "r");
		system("cls");
		no_of_lines=countlines(subject);
		ran_pointer=random(no_of_lines);
		fclose(database);
		
		gotoxy(44,4);
		printf("CHANDIGARH UNIVERSITY");
		gotoxy(47,5);
		printf("physics paper");
		gotoxy(40,6);
		printf("max marks-10");
		gotoxy(56,6);
		printf("max time-30 min");
		
		for(i=0;i<10;i++){
			val=0;
			val=*(ran_pointer+i)+1;
			int count=0;
    		database = fopen("physics.txt", "r");
    		fseek(database,0,SEEK_SET);
    		while(fgets(data,sizeof data,database)!=NULL){   
        	    if(count==val){ 
					gotoxy(41,8+i);  
         		   	printf("%d) %s ",i+1,data);
            		fclose(database);
            	}   
            	else{   
                	count++;
            	}   
        	}	
		}
	}
	else if (subject=='c'){
		database = fopen("chemistry.txt", "r");
	
		no_of_lines=countlines(subject);
		ran_pointer=random(no_of_lines);
		fclose(database);

		system("cls");
		
		gotoxy(44,4);
		printf("CHANDIGARH UNIVERSITY");
		gotoxy(47,5);
		printf("chemistry paper");
		gotoxy(40,6);
		printf("max marks-10");
		gotoxy(56,6);
		printf("max time-30 min");
		
		for(i=0;i<10;i++){
			val=0;
			val=*(ran_pointer+i)+1;
    		int count=0;
    		database = fopen("chemistry.txt", "r");
    		fseek(database,0,SEEK_SET);
    		while(fgets(data,sizeof data,database)!=NULL){   
        	    if(count==val){  
					gotoxy(41,8+i);  
        	    	printf("%d) %s ",i+1,data);
        	    	fclose(database);
        	    }   
        	    else{   
        	        count++;
        	    }   
        	}	
		}
	}
	else if (subject=='m'){
		database = fopen("maths.txt", "r");
	
		no_of_lines=countlines(subject);
		ran_pointer=random(no_of_lines);
		fclose(database);

		system("cls");
		
		gotoxy(44,4);
		printf("CHANDIGARH UNIVERSITY");
		gotoxy(47,5);
		printf("maths paper");
		gotoxy(40,6);
		printf("max marks-10");
		gotoxy(56,6);
		printf("max time-30 min");
		
		for(i=0;i<10;i++){
			val=0;
			val=*(ran_pointer+i)+1;
    		int count=0;
    		database = fopen("maths.txt", "r");
    		fseek(database,0,SEEK_SET);
    		while(fgets(data,sizeof data,database)!=NULL){   
    	        if(count==val){ 
				gotoxy(41,8+i);   
    	        	printf("%d) %s ",i+1,data);
    	        	fclose(database);
    	        }   
    	        else{   
    	            count++;
    	        }   
    	    }
		}
	}
	getch();
	return 0;
}

int *random(int lines){
	int i,j,number;
	
	srand(time(NULL));
	
	for(i=0;i<10;i++){
		number=rand()%(lines);
		for(j=0;j<=i-1;j++){
			if(number==arr[j]){break;}
		}
		if(i==j){
			arr[i]=number;
		}
		else{i--;}
	}
	return arr;	
}

int countlines(char subject){
	int count=0;
	char filename[20],c;
	
	if(subject=='p'){
		strcpy(filename,"physics.txt");
	}
	else if (subject=='c'){
		strcpy(filename,"chemistry.txt");
	}
	else if (subject=='m'){
		strcpy(filename,"maths.txt");
	}
	
	database = fopen(filename, "r"); 
	
	if (database == NULL) { 
        printf("Could not open file %s", filename); 
        return 0; 
    }
    for(c=getc(database);c!=EOF;c=getc(database)){
        if(c=='\n'){
            count+=1; 
        }
    }
    
    fclose(database);
    
  	return count;
}
