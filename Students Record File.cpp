#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
 int roll;
 char name [50];
 float marks;
};

// This is a function which help us to add a new students record to the file 
void addStudent(){
	FILE *fp = fopen ("students.data", "ab");
	struct Student S;
	 
	 printf("Enter Roll No:");
	 scanf("%d",&S.roll);
	 printf("Enter Name :");
	 scanf("%[^\n]",S.name); // for reading strig like eg Swastika sah with space
	 
	 printf("Enter Marks:");
	 scanf("%f", &S.marks);
	 
	 fwrite (&S,sizeof(S), 1, fp); // write the structure s to file in binary format
	 fclose(fp);  // takes input from user and saves it in a binary file
	 printf("Student record added succesfully !\n\n");
	 
}

void viewStudent(){
	FILE *fp = fopen ("students,data","rb");
	struct Student s;
	
	printf("\n--- All Students ---\n");
	
	while (fread(&s, sizeof(s),1,fp)){
		printf("Roll No: %d\n", s.roll); //display each students name, roll , marks
		printf("Name: %s\n",s.name);
		printf("marks: %.2f\n\n", s.marks);
		
	}
	fclose(fp);

}

// this function will search students by help of roll number

void searchStudent(){
	FILE *fp = fopen ("Students.data", "rb");
	struct Student s;
	int targetRoll , Found = 0;
	
	printf("Enter roll number to search the student :");
	scanf("%d", &targetRoll);
	
	while (fread(&s ,sizeof(s), 1, fp)) {
		if(s.roll == targetRoll){ // compare each read record 
		// if found that record then
		printf("Student found:\n");
		printf("Name: %s\n",s.marks);
		Found = 1;
		break;
	}
	}
	if(!Found)
	printf("Student with roll no %d not found.\n", targetRoll);
	
	fclose(fp);
}

// menu system 
int main(){
int choice;
  do{
  	printf("\n--- Student record system ---\n");
  	printf("1. Add student\n");
  	printf("2. View All Students \n");
  	printf("3. Search Student by roll no\n");
  	printf("4. Exit\n");
  	printf("enter your choice : ");
  	scanf("%d", &choice);
  	
  	switch (choice){
  		case 1: addStudent (); break;
  		case 2: viewStudent (); break;
  		case 3: searchStudent ();break;
		case 4: printf ("Exiting the program \n"); break;
		deafult: printf("invalid choice . Try Again.\n");
	  }
  }  while (choice != 4);
  return 0;
}
	









