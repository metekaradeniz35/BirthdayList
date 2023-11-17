#include <stdio.h>
#include <stdlib.h>

struct Human{
	int month;
	int day;
	int year;
	int age;
	char name[50];
	char gender[15];
};

void create(){
	struct Human human1;
	printf("\t\tName: ");
	scanf("%s",&human1.name);
	printf("\t\tGender: ");
	scanf("%s",&human1.gender);
	printf("\t\tAge: ");
	scanf("%d",&human1.age);
	printf("\t\tBirthday day: ");
	scanf("%d",&human1.day);
	printf("\t\tBirthday month: ");
	scanf("%d",&human1.month);
	printf("\t\tBirthday year: ");
	scanf("%d",&human1.year);
	
	FILE *birthdayList = fopen("birthdayList.txt", "a");
	fprintf(birthdayList, "%s\t", human1.name);
	fprintf(birthdayList, "%d\t", human1.age);
	fprintf(birthdayList, "%s\t", human1.gender);
	fprintf(birthdayList, "%d\t", human1.day);
	fprintf(birthdayList, "%d\t", human1.month);
	fprintf(birthdayList, "%d\n", human1.year);
	fclose(birthdayList);
	printf("Succsefly created new person");
		
}

void display() {
	printf("Name   Age     Gender   Day   Month     Year\n");
	FILE *display = fopen("birthdayList.txt", "r");
	if(display != NULL ){
		char c;
		while((c = fgetc(display)) != EOF)
			putchar(c);
			
		fclose(display);
		
	} else printf("\t\tError");
}

int main() {
	int option;
	printf("\t\tBirthday List\n");
	printf("\t\t1.Display Birthday List\n");
	printf("\t\t2.Create new persons birthday\n");
	printf("\t\tOption: ");
	scanf("%d",&option);
	switch(option){
		case 1:
			display();
			break;
		case 2:
			create();
			break;
	}
	
	return 0;
}
