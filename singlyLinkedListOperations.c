// by Omkar Ajagunde
// 	{SINGLY LINKED LIST} CODE DEMONSTRATION THROUGH REAL LIFE USE CASE SCENARIO OF EMPLOYEE DATABASE ... 

#include<stdio.h>				// standard input output for printf(const char *,...),scanf(const char *,...) etc ...
#include<stdlib.h>				// standard library [Almost every program needs this library as our 
								// code calls internally stdlib functions] here used for exit(int status)

// Function prototype declaration, definations below ...

// Functions related to input or inserting data 
struct employee *addNewEmployee(char *name, float heightInFoot, int salary, struct employee *fisrtEmployee);
struct employee *addFirstEmployee(char *name, float heightInFoot, int salary, struct employee *firstEmployee);
struct employee *addEmployeeInBetween(char *name, float heightInFoot, int salary,int position, struct employee *firstEmployee);

// Functions related to creating a new object for employee
struct employee *createEmployeeNode(char *name, float heightInFoot, int salary);

// Functions related to deletion or truncating data 
struct employee *removeFirstEmployee(struct employee *firstEmployee);
struct employee *removeLastEmployee(struct employee *firstEmployee);
struct employee *removeEmployeeInBetween(int position, struct employee *firstEmployee);

// Function realted to show the table of employees and their respective node address [Dont forget we are learning SLL]
void printAllEmployees(struct employee *firstEmployee);

// Our Employee data-structure ...
struct  employee{
	
	float htInFoot;
	int sal;


	struct employee *nextEmp;
	char nm[50];
};

// counting Total employee nodes
int countEmployees = 1;

// Custom function to copy data from one char[] array to another char[] array
/*
*	in-params : char[], char[]
* 	out-params : None	
*/
void copy_string(char d[], char s[]) {
  int c = 0;
   
  while (s[c] != '\0') {
    d[c] = s[c];
    c++;
  }
  d[c] = '\0';
}


// Driver code
int main(void){

	struct employee *headEmployee = NULL;
	int choice;
	char name[50];
	float ht;
	int salary;
	int position;

			printf("============================================================\n");
			printf("             Employee Record Using Linked-List              \n");
			printf("============================================================\n");

	// Displaying Menu like structure using do...while() loop ...

	do{


			printf("\n\t1] Add new Employee ?\n");
			printf("\t2] Add First Employee ?\n");
			printf("\t3] Add Last Employee ?\n");
			printf("\t4] Add In Between Employee ?\n");

			printf("\t5] Remove Fisrt Employee ?\n");
			printf("\t6] Remove Last Employee ?\n");
			printf("\t7] Remove In Between Employee ?\n");

			printf("\t8] Display Employee Record ?\n");

			printf("\t9] Exit ... \n");
			printf("\n\t\t\tEnter a Choice :: ");
			scanf("%d",&choice);

			switch(choice){

				// Adding new Employee/ Node
				case 1:	
						printf("\n\tEnter name :: ");
						scanf("%s",name);
						printf("\tEnter height in foot :: ");
						scanf("%f",&ht);
						printf("\tEnter salary :: ");
						scanf("%d",&salary);
						headEmployee = addNewEmployee(name, ht, salary, headEmployee);
						printf("\n\t\033[1;35mSuccessfully added ...\033[0m\n");
						break;

				// Adding new employee at first
				case 2:	printf("\tEnter name :: ");
						scanf("%s",name);
						printf("\tEnter height in foot :: ");
						scanf("%f",&ht);
						printf("\tEnter salary :: ");
						scanf("%d",&salary);
						headEmployee = addFirstEmployee(name, ht, salary, headEmployee);
						printf("\n\t\033[1;35mSuccessfully added ...\033[0m\n");
						break;
				
				// Adding new Employee at last
				case 3:	printf("\tEnter name :: ");
						scanf("%s",name);
						printf("\tEnter height in foot :: ");
						scanf("%f",&ht);
						printf("\tEnter salary :: ");
						scanf("%d",&salary);
						headEmployee = addNewEmployee(name, ht, salary, headEmployee);
						printf("\n\t\033[1;35mSuccessfully added ...\033[0m\n");
						break;

				// Adding new Employee in-between to Employees/Nodes
				case 4:	printf("\tEnter name :: ");
						scanf("%s",name);
						printf("\tEnter height in foot :: ");
						scanf("%f",&ht);
						printf("\tEnter salary :: ");
						scanf("%d",&salary);
						printf("\tEnter position to add :: ");
						scanf("%d",&position);
						headEmployee = addEmployeeInBetween(name, ht, salary, position, headEmployee);
						printf("\n\t\033[1;35mSuccessfully added ...\033[0m\n");
						break;
				
				// Removal of first Employee/Node
				case 5:	headEmployee = removeFirstEmployee(headEmployee);
						printf("\n\t\033[1;35mSuccessfully Fired Out ...\033[0m\n");
						break;

				// Removal of Last Employee.Node
				case 6:	headEmployee = removeLastEmployee(headEmployee);
						printf("\n\t\033[1;35mSuccessfully Fired Out...\033[0m\n");
						break;

				// Removal of Employee/Node in-between to Employees/Nodes
				case 7: printf("\nEnter position to remove :: ");
						scanf("%d",&position);
						headEmployee = removeEmployeeInBetween(position, headEmployee);
						printf("\n\t\033[1;35mSuccessfully Fired Out...\033[0m\n");
						break;

				// Displaying Tabular structure of existing Employees/Nodes with their respective Node addressing
				case 8:	printAllEmployees(headEmployee);
						break;

				// Exit from Demonstration
				case 9:	exit(0);
						break;

				default:
						printf("Please enter a valid Option :: \n");																		

			}


	}while(1);

	// Successfull termination to Operating System ...
	return 0;
}


// Adding new Employee/ Node
/*
*	in-params : char*, float, int 
*	out-params : struct employee*
*/
struct employee *createEmployeeNode(char *name, float heightInFoot, int salary){

	struct employee *newEmp = (struct employee *)malloc(sizeof(struct employee));	// void* malloc(size) => internally calls growreg to allocate pages to 
																					// our structure Employee
	copy_string(newEmp -> nm,name);
	newEmp -> htInFoot = heightInFoot;
	newEmp -> sal = salary;
	newEmp -> nextEmp = NULL;

	return newEmp;
}

// Adding new employee/ at first
/*
*	in-params : char*, float, int, struct employee* 
*	out-params : struct employee*
*
*/
struct employee *addNewEmployee(char *name, float heightInFoot, int salary, struct employee *firstEmployee){

	if (firstEmployee == NULL){
		
		countEmployees += 1;
		return createEmployeeNode(name,heightInFoot,salary);
		
	}else{
		struct employee *tempEmp = firstEmployee;
		while(tempEmp -> nextEmp != NULL)
			tempEmp = tempEmp -> nextEmp;

		tempEmp -> nextEmp = createEmployeeNode(name,heightInFoot,salary);
		countEmployees += 1;
		return firstEmployee;
	}
}

// Adding new Employee at last
/*
*	in-params : char*, float, int, struct employee* 
*	out-params : struct employee*
*/
struct employee *addFirstEmployee(char *name, float heightInFoot, int salary, struct employee *firstEmployee){
	
	if (firstEmployee == NULL){
		countEmployees += 1;
		return createEmployeeNode(name,heightInFoot,salary);
		
	}else{
		struct employee *tempEmp = createEmployeeNode(name,heightInFoot,salary);
		tempEmp -> nextEmp = firstEmployee;
		firstEmployee = tempEmp;
		countEmployees += 1;
		return tempEmp;
	}
}

// Chech weather the position enter is less than the total Count ...
/*
*	in-parameters : int
*	out-parameters : int
*  	
* 	1 => if true
*	-1 => if false Return err...
*/ 
int checkPositionValid(int position){

	if (position > 0 && position <= countEmployees)
		return 1;
	else
		return -1;
}

// Adding new Employee in-between to Employees/Nodes
/*
*	in-params : char*, float, int, struct employee* 
*	out-params : struct employee*
*
*/
struct employee *addEmployeeInBetween(char *name, float heightInFoot, int salary,int position, struct employee *firstEmployee){
	
	struct employee *newEmp = createEmployeeNode(name,heightInFoot,salary);
    struct employee *tempEmp = firstEmployee;

    countEmployees += 1;

	if (position == 1)
		return addFirstEmployee(name,heightInFoot,salary,firstEmployee);
	else if (checkPositionValid(position)){
		
		int traverseCount = 2;
		while (traverseCount < position){
			tempEmp = tempEmp -> nextEmp;
			traverseCount += 1;
		}

		newEmp -> nextEmp = tempEmp -> nextEmp;
		tempEmp -> nextEmp = newEmp;
		return firstEmployee;

	}else if (countEmployees == position)
		return addNewEmployee(name, heightInFoot, salary, firstEmployee);
	else{
		printf("\n\n\tPlease Provide a legal Position !!! ");
		return firstEmployee;
	}
}

// Removal of first Employee/Node
/*
*	in-params : struct employee*
*	out-params : struct employee*
*
*/
struct employee *removeFirstEmployee(struct employee *firstEmployee){

	struct employee *tempEmp = firstEmployee;
	firstEmployee = tempEmp -> nextEmp;
	free(tempEmp);

	countEmployees -= 1;

	return firstEmployee;
}

// Removal of Last Employee/Node
/*
*	in-params : struct employee*
*	out-params : struct employee*
*
*/
struct employee *removeLastEmployee(struct employee *firstEmployee){

	struct employee *tempEmp = firstEmployee;
	while (tempEmp -> nextEmp -> nextEmp != NULL)
		tempEmp = tempEmp -> nextEmp;

	free(tempEmp -> nextEmp);
	tempEmp -> nextEmp = NULL;

	countEmployees -= 1;

	return firstEmployee;
}

// Removal of first Employee/Node
/*
*	in-params : int, struct employee*
*	out-params : struct employee*
*
*/
struct employee *removeEmployeeInBetween(int position, struct employee *firstEmployee){

    struct employee *tempEmp = firstEmployee;
    struct employee *newEmp;

    countEmployees -= 1;

	if (position == 1)
		return removeFirstEmployee(firstEmployee);
	else if (checkPositionValid(position)){
		
		int traverseCount = 2;
		while (traverseCount < position){
			tempEmp = tempEmp -> nextEmp;
			traverseCount += 2;
		}

		newEmp = tempEmp -> nextEmp -> nextEmp;
		free(tempEmp -> nextEmp);
		tempEmp -> nextEmp = newEmp;

		return firstEmployee;

	}else if (countEmployees == position)
		return removeLastEmployee(firstEmployee);
	else{
		printf("\n\n\tPlease Provide a legal Position !!! ");
		return firstEmployee;
	}
}

// Displaying Tabular structure of existing Employees/Nodes with their respective Node addressing
/*
*	in-params : struct employee*
*	out-params : None
*/
void printAllEmployees(struct employee *firstEmployee){

	struct employee *tempEmp = firstEmployee;
	printf("==========================================================================no of emp = %d ==========\n",countEmployees-1);
	printf("\033[0;34m%-30s\t%-4s\t%-6s\t\t%-14s  %-14s\n\033[0m", "Name", "Height in ft", "Salary", "Node self address", "Node next address");
	while (tempEmp != NULL){
		printf("%-30s\t%-4f\t%-6d\t\t", tempEmp -> nm, tempEmp -> htInFoot, tempEmp -> sal);
		printf("\033[1;35m%-18p%-16p\n\033[0m",tempEmp, tempEmp -> nextEmp );
		tempEmp = tempEmp -> nextEmp;
	}
	printf("==================================================================================================\n\n");


}
