#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ST_NUMBER_LEN 	11
#define MAX_ST_FIRST_NAME_LEN 	80
#define MAX_ST_LAST_NAME_LEN 	80

#define MAX_STUDENTS 		300

#define FILE_NAME  		"myStudent.bin"



struct s_StudentInfo
{
	char studentNumber[MAX_ST_NUMBER_LEN];
	char firstName[MAX_ST_FIRST_NAME_LEN];
	char lastName[MAX_ST_LAST_NAME_LEN];
	float avr;
} ;



int main()
{
	struct s_StudentInfo st[MAX_STUDENTS]; 
	FILE *fptr;

	puts("#################################################################################################################################################");
	puts("#################################################################################################################################################");
	puts("#################################################################################################################################################");
	puts("######################################              WELCOME               #######################################################################");
	puts("#################################################################################################################################################");
	puts("#################################################################################################################################################");
	puts("###########################################  full screan your terminal  #########################################################################"); 




	stpcpy(st[1].studentNumber,"123456789A");
	stpcpy(st[1].firstName,"ata");
	stpcpy(st[1].lastName,"babaei");
	st[1].avr=15.5;

	stpcpy(st[2].studentNumber,"99999999");
	stpcpy(st[2].firstName,"Ali");
	stpcpy(st[2].lastName,"rahimi");
	st[2].avr=19;





	if ((fptr = fopen(FILE_NAME,"wb")) == NULL){
		printf("Error! opening file");

		return 1;

	}

	for(int i = 1; i < MAX_STUDENTS; ++i)
	{
		fwrite(&st[i], sizeof(struct s_StudentInfo), 1, fptr); 
	}
	fclose(fptr); 







	if ((fptr = fopen(FILE_NAME,"rb")) == NULL)
	{
		printf("Error! opening file");

		return 1;
	}
	printf("hi i am ata babaei\n");

	for(int i = 1; i < MAX_ST_FIRST_NAME_LEN; ++i)
	{
		fread(&st[i], sizeof(struct s_StudentInfo), 1, fptr); 
		if(!strcmp(st[i].firstName,""))
			break;
		printf("studentNumber: %-11s firstName: %-20s lastName: %-35s avr: %2.2f\n", st[i].studentNumber, st[i].firstName, st[i].lastName,st[i].avr);
	}

	fclose(fptr);    

	return 0;
}


