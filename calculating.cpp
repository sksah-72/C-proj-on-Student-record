#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void showMenu(){  // this is all the content availabe which user want to perform their calculation
	printf("\n --- Scientific Calculator ---\n");
	printf("1.Addition\n2. Subtraction\n3. Multiplication\n4. Division\n");
	printf("5.Power\n6. square root\n7. Logarithm\n");
	printf("8.sine\n9. Cosine\n10. tangent\n");
	printf("11.Factorial\n12. Exit\n");
	printf("Choose an Option which you want to perform: ");
	
}

int factorial (int a){    // this will to perform to find the factorial of any number
	if(a == 0 || a == 1)
	return 1;
	return a*factorial(a-1);
	
}

int main(){
	int yourChoice;  // user choice
	double e,f;  // user can take more precise value eg 2.33
	
	do{
		showMenu();  // list of all operations
		scanf("%d", &yourChoice);
		switch(yourChoice){
			case 1:
				printf("Enter two numbers:");
				scanf("%lf %lf", &e,&f);
				printf("Result: %.2lf\n", e+f);
				break;
				
				case 2:
				printf("enter two numbers:");
				scanf("%lf %lf ", &e,&f);
				printf("result: %.2lf\n", e-f);
				break;
				
				case 3:
				printf("Enter two numbers:");
				scanf("%lf %lf", &e,&f);
				printf("Result: %.2lf\n", e*f);
				break;
				
				case 4:
			    printf("Enter two numbers:");
			    scanf("%lf %lf", &e,&f);
			    if (f!=0)
			    printf("Result: %.2lf\n", e/f);
			    else
			    printf("Error: Division by zero\n");
			    break;
			    
			    case 5:
			    printf("Enter number:");
			    scanf("%lf %lf", &e,&f);
			    printf("Result: %.2lf\n", pow(e,f));
			    break;
			    
			    case 6:
			    	printf("Enter number:");
			    	scanf("%lf %lf ", &e,&f);
			    	printf("Result: %.2lf\n", sqrt(e));
			    	break;
			    	
			   	case 7:
			   		printf("Enter number:");
			    	scanf("%lf %lf ", &e,&f);
			    	printf("Result: %.2lf\n", log(e));
			    	break;
			    	
			    case 8:
			    	printf("Enter number:");
			    	scanf("%lf ", &e);
			    	printf("Result: %.2lf\n",sin(e));
			    	break;
			    	
			   	case 9:
			   		printf("Enter angle in radians:");
			    	scanf("%lf ", &e);
			    	printf("Result: %.2lf\n", cos(e));
			    	break;
			    	
			    case 10:
			    	printf("Enter angle in radians:");
			    	scanf("%lf ", &e);
			    	printf("Result: %.2lf\n", tan(e));
			    	break;
			    	
			   	case 11:
			    	printf("Enter integer:");
			    	scanf("%lf ", &e);
			    	printf("Result: %d\n",factorial((int)e));
			    	break;
			    	
			   	case 12:
			   		printf("Exiting calculator ---\n");
			    	break;
			    	default:  // if user put invalid numbers
			    		printf("Invalid Choice!\n");
					
		}
	} while (yourChoice!= 12);  // it will repeat unntil exit option is choosen
	return 0;
}