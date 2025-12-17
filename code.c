#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char fever();
char vommitting();
char stomachache();
char diarrohea();
char bodypain();
char itching();
char jaundice();
char cold();

void customer();
void lowstock();
void receipt(k);
int key = 0, no_stock = 0;// Counter for purchases ;
int *k = &key;

struct customer {
    char name[20];
    int age;
    char gender;
    double mobile_no;
}a;

struct medicine {
    char name[15];
    int quantity;
    int price;
    int total_cost;
}purchase[100] /* Array to store medicine purchases*/;

int main() {
    
    printf("---------------------------------------  WELCOME TO IIT JODHPUR PHC PHARMA  ---------------------------------------");
    printf("\n\n\n");
    printf("We have medicines for : Fever | Vommitting | Stomachache | Diarrohea | Bodypain | Itching | Jaundice | Cold");
    printf("\n\n");

        printf("Are you a customer ? Press 1\n\n");
        printf("Checking Low Stock in Inventory ? Press 2\n\n");

        int function;
        scanf("%d",&function);
        getchar();

        if (function == 1) 
        {
            customer();
            printf("Do you want the Receipt ? Press 1\n");
            scanf("%d",&function);
            if (function == 1)
            {
                receipt(k);
            }

            printf("\n\n");
            printf("Checking low stock in Inventory ? Press 2\n");
            scanf("%d",&function);
            if (function == 2)
            {
                lowstock();
            }

        }
        if (function == 2)
        {
            lowstock();
        }
        

    return 0;
}

char stomachache(){
    
    char line[256]; // Buffer to hold each line

    // Open the file in read mode
    FILE *file = fopen("stomachache.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1; // Return an error code if the file cannot be opened
    }
     printf("\n");
    // Read and print each line of the file
        while (fgets(line, sizeof(line), file) != NULL) {
        printf("%s", line);
        }
        fclose(file);
    
        char medicine_name[15];
        printf("\n");
        printf("_________________");
        printf("\033[4m\n|Enter your name|\033[0m");
        fgets(medicine_name, 15, stdin);
        medicine_name[strcspn(medicine_name, "\n")] = '\0';  // Remove newline

        // Check if user wants to exit the input loop
        if (strcmp(medicine_name, "END") == 0) {
            printf("Processing you request...\n");
        }

        int quantity;
        printf("\n");
        printf("__________________________");
        printf("\033[4m\n|Enter number of medicines|\033[0m");
        scanf("%d", &quantity);
        getchar();  // Consume newline left by scanf

        FILE *fll = fopen("stomachache.txt","r+");
        char new_line[256];
        int line_number = 0;
        char ch;
        int check = 0;
        while (fgets(new_line, sizeof(new_line), fll)!= NULL) {
            if (strstr(new_line,medicine_name) != NULL) { 
                printf("%s", new_line);
                check = 1;
                break;

            }
            line_number++;
        }
        

        //printf("line is %s",line);
        if (check != 1)
        {
            printf("\n---------------------------------------Sorry We do not have this medicine---------------------------------------\n");
            fclose(fll);
            return 1;
        }

        int current_quantity;
        if (sscanf(line, "%*[^q]quantity available - %d", &current_quantity) == 1)
        {
        if (current_quantity>quantity)
        {
            int new_quantity = current_quantity - quantity;
            fseek(file, -(strlen(line) - (strstr(line, "quantity available - ")- line) - 19), SEEK_CUR);
            
            fprintf(file, "%d \n", new_quantity);
            //break;`
        }
        else
        {
            printf("\n---------------------------------------Not enough stock available---------------------------------------");
            no_stock=5;
        }
        }

        else 
        {
            printf("Error in quantity calculation");
        }

        fclose(file);

        FILE *pr = fopen("price.txt","r+");
        if (pr == NULL) {
            perror("Error opening price file");
            return 1;
        }

        int price_linenum = 0;
        int price = 0;
        // Getting the price of the medicine
        while ((fscanf(pr, "%d", &price) == 1)&& (no_stock!=5)) {
            if (price_linenum == line_number) {
                printf("\nPrice of one %s is %d\n", medicine_name, price);
                //printf("\n k is %d",*k);
                purchase[*k].price = price;
                purchase[*k].quantity = quantity;
                purchase[*k].total_cost = price*quantity;
                printf("Total cost for %d of %s is %d\n", quantity, medicine_name, purchase[*k].total_cost);
                strcpy(purchase[*k].name, medicine_name);  // Store medicine name
                 *k = *k+1;  // Increment purchase counter
                break;
            }
            price_linenum++;
        }
        no_stock=0;
}

char fever(){
    
    char line[256]; //to hold each line

    // Open the file in read mode
    FILE *file = fopen("fever.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1; 
    }
    printf("\n");
    // Read and print each line of the file
        while (fgets(line, sizeof(line), file) != NULL) {
        printf("%s", line);
        }
        fclose(file);
    
        char medicine_name[15];
        printf("\n");
        printf("____________________________");
        printf("\033[4m\n|Enter the name of medicine|\033[0m");
        fgets(medicine_name, 15, stdin);
        medicine_name[strcspn(medicine_name, "\n")] = '\0';  // Remove newline

        if (strcmp(medicine_name, "END") == 0) { 
            printf("Processing you request...\n");
        }

        int quantity;
        printf("\n");
        printf("___________________________");
        printf("\033[4m\n|Enter number of medicines|\033[0m");
        scanf("%d", &quantity);
        getchar();  // Consume newline left by scanf

        FILE *fll = fopen("fever.txt","r+");
        char new_line[256];
        int line_number = 0;
        char ch;
        int check = 0;
        while (fgets(new_line, sizeof(new_line), fll)!= NULL) {
            if (strstr(new_line,medicine_name) != NULL) { 
                printf("%s", new_line);
                check = 1;
                break;

            }
            line_number++;
        }
        

        //printf("line is %s",line);
        if (check != 1)
        {
            printf("\n---------------------------------------Sorry We do not have this medicine---------------------------------------\n");
            fclose(fll);
            return 1;
        }

        int current_quantity;
        if (sscanf(line, "%*[^q]quantity available - %d", &current_quantity) == 1)
        {
        if (current_quantity>quantity)
        {
            int new_quantity = current_quantity - quantity;
            fseek(file, -(strlen(line) - (strstr(line, "quantity available - ")- line) - 19), SEEK_CUR);
            
            fprintf(file, "%d \n", new_quantity);
            //break;`
        }
        else
        {
            printf("\n---------------------------------------Not enough stock available---------------------------------------");
            no_stock=5;
        }
        }

        else 
        {
            printf("Error in quantity calculation");
        }

        fclose(file);

        FILE *pr = fopen("price.txt","r+");
        if (pr == NULL) {
            perror("Error opening price file");
            return 1;
        }

        int price_linenum = 0;
        int price = 0;
        // Getting the price of the medicine
       while ((fscanf(pr, "%d", &price) == 1)&& (no_stock!=5)) {
            if (price_linenum == line_number) {
                printf("\nPrice of one %s is %d\n", medicine_name, price);
                //printf("\n k is %d",*k);
                purchase[*k].price = price;
                purchase[*k].quantity = quantity;
                purchase[*k].total_cost = price*quantity;
                printf("Total cost for %d of %s is %d\n", quantity, medicine_name, purchase[*k].total_cost);
                strcpy(purchase[*k].name, medicine_name);  // Store medicine name
                 *k = *k+1;  // Increment purchase counter
                break;
            }
            price_linenum++;
        }
        no_stock=0;
}

char vommitting(){
    
    char line[256]; // Buffer to hold each line

    // Open the file in read mode
    FILE *file = fopen("vommitting.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1; 
    }
     printf("\n");
    // Read and print each line of the file
        while (fgets(line, sizeof(line), file) != NULL) {
        printf("%s", line);
        }
        fclose(file);
    
        char medicine_name[15];
        printf("\n");
        printf("____________________________");
        printf("\033[4m\n|Enter the name of medicine|\033[0m");
        fgets(medicine_name, 15, stdin);
        medicine_name[strcspn(medicine_name, "\n")] = '\0'; 

        // Check if user wants to exit the input loop
        if (strcmp(medicine_name, "END") == 0) {
            printf("Processing you request...\n");
        }

        int quantity;
        printf("\n");
        printf("___________________________");
        printf("\033[4m\n|Enter number of medicines|\033[0m");
        scanf("%d", &quantity);
        getchar(); 

        FILE *fll = fopen("vommitting.txt","r+");
        char new_line[256];
        int line_number = 0;
        char ch;
        int check = 0;
        while (fgets(new_line, sizeof(new_line), fll)!= NULL) {
            if (strstr(new_line,medicine_name) != NULL) { 
                printf("%s", new_line);
                check = 1;
                break;

            }
            line_number++;
        }
        

        //printf("line is %s",line);
        if (check != 1)
        {
            printf("\n---------------------------------------Sorry We do not have this medicine---------------------------------------\n");
            fclose(fll);
            return 1;
        }

        int current_quantity;
        if (sscanf(line, "%*[^q]quantity available - %d", &current_quantity) == 1)
        {
        if (current_quantity>quantity)
        {
            int new_quantity = current_quantity - quantity;
            fseek(file, -(strlen(line) - (strstr(line, "quantity available - ")- line) - 19), SEEK_CUR);
            
            fprintf(file, "%d \n", new_quantity);
            //break;`
        }
        else
        {
            printf("\n---------------------------------------Not enough stock available---------------------------------------");
            no_stock=5;
        }
        }

        else 
        {
            printf("Error in quantity calculation");
        }

        fclose(file);

        FILE *pr = fopen("price.txt","r+");
        if (pr == NULL) {
            perror("Error opening price file");
            return 1;
        }

        int price_linenum = 0;
        int price = 0;
        // Getting the price of the medicine
       while ((fscanf(pr, "%d", &price) == 1)&& (no_stock!=5)) {
            if (price_linenum == line_number) {
                printf("\nPrice of one %s is %d\n", medicine_name, price);
                //printf("\n k is %d",*k);
                purchase[*k].price = price;
                purchase[*k].quantity = quantity;
                purchase[*k].total_cost = price*quantity;
                printf("Total cost for %d of %s is %d\n", quantity, medicine_name, purchase[*k].total_cost);
                strcpy(purchase[*k].name, medicine_name);  // Store medicine name
                 *k = *k+1;  // Increment purchase counter
                break;
            }
            price_linenum++;
        }
        no_stock=0;
}


char diarrohea(){
    
    char line[256]; // Buffer to hold each line

    // Open the file in read mode
    FILE *file = fopen("diarrohea.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1; // Return an error code if the file cannot be opened
    }
    printf("\n");
    // Read and print each line of the file
        while (fgets(line, sizeof(line), file) != NULL) {
        printf("%s", line);
        }
        fclose(file);
    
        char medicine_name[15];
        printf("\n");
        printf("____________________________");
        printf("\033[4m\n|Enter the name of medicine|\033[0m");
        fgets(medicine_name, 15, stdin);
        medicine_name[strcspn(medicine_name, "\n")] = '\0';  // Remove newline

        // Check if user wants to exit the input loop
        if (strcmp(medicine_name, "END") == 0) {
            printf("Processing you request...\n");
        }

        int quantity;
        printf("\n");
        printf("___________________________");
        printf("\033[4m\n|Enter number of medicines|\033[0m");
        scanf("%d", &quantity);
        getchar();  // Consume newline left by scanf

        FILE *fll = fopen("diarrohea.txt","r+");
        char new_line[256];
        int line_number = 0;
        char ch;
        int check = 0;
        while (fgets(new_line, sizeof(new_line), fll)!= NULL) {
            if (strstr(new_line,medicine_name) != NULL) { 
                printf("%s", new_line);
                check = 1;
                break;

            }
            line_number++;
        }
        

        //printf("line is %s",line);
        if (check != 1)
        {
            printf("\n---------------------------------------Sorry We do not have this medicine---------------------------------------\n");
            fclose(fll);
            return 1;
        }

        int current_quantity;
        if (sscanf(line, "%*[^q]quantity available - %d", &current_quantity) == 1)
        {
        if (current_quantity>quantity)
        {
            int new_quantity = current_quantity - quantity;
            fseek(file, -(strlen(line) - (strstr(line, "quantity available - ")- line) - 19), SEEK_CUR);
            
            fprintf(file, "%d \n", new_quantity);
            //break;`
        }
        else
        {
            printf("\n---------------------------------------Not enough stock available---------------------------------------");
            no_stock=5;
        }
        }

        else 
        {
            printf("Error in quantity calculation");
        }

        fclose(file);

        FILE *pr = fopen("price.txt","r+");
        if (pr == NULL) {
            perror("Error opening price file");
            return 1;
        }

        int price_linenum = 0;
        int price = 0;
        // Getting the price of the medicine
       while ((fscanf(pr, "%d", &price) == 1)&& (no_stock!=5)) {
            if (price_linenum == line_number) {
                printf("\nPrice of one %s is %d\n", medicine_name, price);
                //printf("\n k is %d",*k);
                purchase[*k].price = price;
                purchase[*k].quantity = quantity;
                purchase[*k].total_cost = price*quantity;
                printf("Total cost for %d of %s is %d\n", quantity, medicine_name, purchase[*k].total_cost);
                strcpy(purchase[*k].name, medicine_name);  // Store medicine name
                 *k = *k+1;  // Increment purchase counter
                break;
            }
            price_linenum++;
        }
        no_stock=0;
}


char bodypain(){
    
    char line[256]; // Buffer to hold each line

    // Open the file in read mode
    FILE *file = fopen("bodypain.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1; // Return an error code if the file cannot be opened
    }
     printf("\n");
    // Read and print each line of the file
        while (fgets(line, sizeof(line), file) != NULL) {
        printf("%s", line);
        }
        fclose(file);
    
        char medicine_name[15];
       printf("\n");
        printf("____________________________");
        printf("\033[4m\n|Enter the name of medicine|\033[0m");
        fgets(medicine_name, 15, stdin);
        medicine_name[strcspn(medicine_name, "\n")] = '\0';  // Remove newline

        // Check if user wants to exit the input loop
        if (strcmp(medicine_name, "END") == 0) {
            printf("Processing you request...\n");
        }

        int quantity;
        printf("\n");
        printf("___________________________");
        printf("\033[4m\n|Enter number of medicines|\033[0m");
        scanf("%d", &quantity);
        getchar();  // Consume newline left by scanf

        FILE *fll = fopen("bodypain.txt","r+");
        char new_line[256];
        int line_number = 0;
        char ch;
        int check = 0;
        while (fgets(new_line, sizeof(new_line), fll)!= NULL) {
            if (strstr(new_line,medicine_name) != NULL) { 
                printf("%s", new_line);
                check = 1;
                break;

            }
            line_number++;
        }
        

        //printf("line is %s",line);
        if (check != 1)
        {
            printf("\n---------------------------------------Sorry We do not have this medicine---------------------------------------\n");
            fclose(fll);
            return 1;
        }

        int current_quantity;
        if (sscanf(line, "%*[^q]quantity available - %d", &current_quantity) == 1)
        {
        if (current_quantity>quantity)
        {
            int new_quantity = current_quantity - quantity;
            fseek(file, -(strlen(line) - (strstr(line, "quantity available - ")- line) - 19), SEEK_CUR);
            
            fprintf(file, "%d \n", new_quantity);
            //break;`
        }
        else
        {
            printf("\n---------------------------------------Not enough stock available---------------------------------------");
            no_stock=5;
        }
        }

        else 
        {
            printf("Error in quantity calculation");
        }

        fclose(file);

        FILE *pr = fopen("price.txt","r+");
        if (pr == NULL) {
            perror("Error opening price file");
            return 1;
        }

        int price_linenum = 0;
        int price = 0;
        // Getting the price of the medicine
        while ((fscanf(pr, "%d", &price) == 1)&& (no_stock!=5)) {
            if (price_linenum == line_number) {
                printf("\nPrice of one %s is %d\n", medicine_name, price);
                //printf("\n k is %d",*k);
                purchase[*k].price = price;
                purchase[*k].quantity = quantity;
                purchase[*k].total_cost = price*quantity;
                printf("Total cost for %d of %s is %d\n", quantity, medicine_name, purchase[*k].total_cost);
                strcpy(purchase[*k].name, medicine_name);  // Store medicine name
                 *k = *k+1;  // Increment purchase counter
                break;
            }
            price_linenum++;
        }
        no_stock=0;
}

char itching(){
    
    char line[256]; // Buffer to hold each line

    // Open the file in read mode
    FILE *file = fopen("itching.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1; // Return an error code if the file cannot be opened
    }
      printf("\n");
    // Read and print each line of the file
        while (fgets(line, sizeof(line), file) != NULL) {
        printf("%s", line);
        }
        fclose(file);
    
        char medicine_name[15];
        printf("\n");
        printf("____________________________");
        printf("\033[4m\n|Enter the name of medicine|\033[0m");
        fgets(medicine_name, 15, stdin);
        medicine_name[strcspn(medicine_name, "\n")] = '\0';  // Remove newline

        // Check if user wants to exit the input loop
        if (strcmp(medicine_name, "END") == 0) {
            printf("Processing you request...\n");
        }

        int quantity;
        printf("\n");
        printf("___________________________");
        printf("\033[4m\n|Enter number of medicines|\033[0m");
        scanf("%d", &quantity);
        getchar();  // Consume newline left by scanf

        FILE *fll = fopen("itching.txt","r+");
        char new_line[256];
        int line_number = 0;
        char ch;
        int check = 0;
        while (fgets(new_line, sizeof(new_line), fll)!= NULL) {
            if (strstr(new_line,medicine_name) != NULL) { 
                printf("%s", new_line);
                check = 1;
                break;

            }
            line_number++;
        }
        

        //printf("line is %s",line);
        if (check != 1)
        {
            printf("\n---------------------------------------Sorry We do not have this medicine---------------------------------------\n");
            fclose(fll);
            return 1;
        }

        int current_quantity;
        if (sscanf(line, "%*[^q]quantity available - %d", &current_quantity) == 1)
        {
        if (current_quantity>quantity)
        {
            int new_quantity = current_quantity - quantity;
            fseek(file, -(strlen(line) - (strstr(line, "quantity available - ")- line) - 19), SEEK_CUR);
            
            fprintf(file, "%d \n", new_quantity);
            //break;`
        }
        else
        {
            printf("\n---------------------------------------Not enough stock available---------------------------------------");
            no_stock=5;
        }
        }

        else 
        {
            printf("Error in quantity calculation");
        }

        fclose(file);

        FILE *pr = fopen("price.txt","r+");
        if (pr == NULL) {
            perror("Error opening price file");
            return 1;
        }

        int price_linenum = 0;
        int price = 0;
        // Getting the price of the medicine
        while ((fscanf(pr, "%d", &price) == 1)&& (no_stock!=5)) {
            if (price_linenum == line_number) {
                printf("\nPrice of one %s is %d\n", medicine_name, price);
                //printf("\n k is %d",*k);
                purchase[*k].price = price;
                purchase[*k].quantity = quantity;
                purchase[*k].total_cost = price*quantity;
                printf("Total cost for %d of %s is %d\n", quantity, medicine_name, purchase[*k].total_cost);
                strcpy(purchase[*k].name, medicine_name);  // Store medicine name
                 *k = *k+1;  // Increment purchase counter
                break;
            }
            price_linenum++;
        }
        no_stock=0;
}


char jaundice(){
    
    char line[256]; // Buffer to hold each line

    // Open the file in read mode
    FILE *file = fopen("jaundice.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1; // Return an error code if the file cannot be opened
    }
     printf("\n");
    // Read and print each line of the file
        while (fgets(line, sizeof(line), file) != NULL) {
        printf("%s", line);
        }
        fclose(file);
    
        char medicine_name[15];
        printf("\n");
        printf("____________________________");
        printf("\033[4m\n|Enter the name of medicine|\033[0m");
        fgets(medicine_name, 15, stdin);
        medicine_name[strcspn(medicine_name, "\n")] = '\0';  // Remove newline

        // Check if user wants to exit the input loop
        if (strcmp(medicine_name, "END") == 0) {
            printf("Processing you request...\n");
        }

        int quantity;
        printf("\n");
        printf("___________________________");
        printf("\033[4m\n|Enter number of medicines|\033[0m");
        scanf("%d", &quantity);
        getchar();  // Consume newline left by scanf

        FILE *fll = fopen("jaundice.txt","r+");
        char new_line[256];
        int line_number = 0;
        char ch;
        int check = 0;
        while (fgets(new_line, sizeof(new_line), fll)!= NULL) {
            if (strstr(new_line,medicine_name) != NULL) { 
                printf("%s", new_line);
                check = 1;
                break;

            }
            line_number++;
        }
        

        //printf("line is %s",line);
        if (check != 1)
        {
            printf("\n---------------------------------------Sorry We do not have this medicine---------------------------------------\n");
            fclose(fll);
            return 1;
        }

        int current_quantity;
        if (sscanf(line, "%*[^q]quantity available - %d", &current_quantity) == 1)
        {
        if (current_quantity>quantity)
        {
            int new_quantity = current_quantity - quantity;
            fseek(file, -(strlen(line) - (strstr(line, "quantity available - ")- line) - 19), SEEK_CUR);
            
            fprintf(file, "%d \n", new_quantity);
            //break;`
        }
        else
        {
            printf("\n---------------------------------------Not enough stock available---------------------------------------");
            no_stock = 5;
        }
        }

        else 
        {
            printf("Error in quantity calculation");
        }

        fclose(file);

        FILE *pr = fopen("price.txt","r+");
        if (pr == NULL) {
            perror("Error opening price file");
            return 1;
        }

        int price_linenum = 0;
        int price = 0;
        // Getting the price of the medicine
        while ((fscanf(pr, "%d", &price) == 1)&& (no_stock!=5)){
            if (price_linenum == line_number) {
                printf("\nPrice of one %s is %d\n", medicine_name, price);
                purchase[*k].price = price;
                purchase[*k].quantity = quantity;
                purchase[*k].total_cost = price*quantity;
                printf("Total cost for %d of %s is %d\n", quantity, medicine_name, purchase[*k].total_cost);
                strcpy(purchase[*k].name, medicine_name);  // Store medicine name
                 *k = *k+1;  // Increment purchase counter
                break;
            }
            price_linenum++;
        }
        no_stock=0;
}

char cold(){
    
    char line[256]; // Buffer to hold each line

    // Open the file in read mode
    FILE *file = fopen("cold.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1; // Return an error code if the file cannot be opened
    }
    printf("\n");
    // Read and print each line of the file
        while (fgets(line, sizeof(line), file) != NULL) {
        printf("%s", line);
        }
        fclose(file);
    
        char medicine_name[15];
        printf("\n");
        printf("____________________________");
        printf("\033[4m\n|Enter the name of medicine|\033[0m");
        fgets(medicine_name, 15, stdin);
        medicine_name[strcspn(medicine_name, "\n")] = '\0';  // Remove newline

        // Check if user wants to exit the input loop
        if (strcmp(medicine_name, "END") == 0) {
            printf("Processing you request...\n");
        }

        int quantity;
        printf("\n");
        printf("___________________________");
        printf("\033[4m\n|Enter number of medicines|\033[0m");
        scanf("%d", &quantity);
        getchar();  // Consume newline left by scanf

        FILE *fll = fopen("cold.txt","r+");
        char new_line[256];
        int line_number = 0;
        char ch;
        int check = 0;
        while (fgets(new_line, sizeof(new_line), fll)!= NULL) {
            if (strstr(new_line,medicine_name) != NULL) { 
                printf("%s", new_line);
                check = 1;
                break;

            }
            line_number++;
        }
        

        //printf("line is %s",line);
        if (check != 1)
        {
            printf("\n---------------------------------------Sorry We do not have this medicine---------------------------------------\n");
            fclose(fll);
            return 1;
        }

        int current_quantity;
        if (sscanf(line, "%*[^q]quantity available - %d", &current_quantity) == 1)
        {
        if (current_quantity>quantity)
        {
            int new_quantity = current_quantity - quantity;
            fseek(file, -(strlen(line) - (strstr(line, "quantity available - ")- line) - 19), SEEK_CUR);
            
            fprintf(file, "%d \n", new_quantity);
            //break;`
        }
        else
        {
            printf("\n---------------------------------------Not enough stock available---------------------------------------");
            no_stock = 5;
        }
        }

        else 
        {
            printf("Error in quantity calculation");
        }

        fclose(file);

        FILE *pr = fopen("price.txt","r+");
        if (pr == NULL) {
            perror("Error opening price file");
            return 1;
        }

        int price_linenum = 0;
        int price = 0;
        // Getting the price of the medicine
        while ((fscanf(pr, "%d", &price) == 1)&& (no_stock!=5)) {
            if (price_linenum == line_number) {
                printf("\nPrice of one %s is %d\n", medicine_name, price);
                printf("\n k is %d",*k);
                purchase[*k].price = price;
                purchase[*k].quantity = quantity;
                purchase[*k].total_cost = price*quantity;
                printf("Total cost for %d of %s is %d\n", quantity, medicine_name, purchase[*k].total_cost);
                strcpy(purchase[*k].name, medicine_name);  // Store medicine name
                 *k = *k+1;  // Increment purchase counter
                break;
            }
            price_linenum++;
        }
        no_stock=0;
}


void customer()
{
    printf("\n");
    printf("_________________");
    printf("\033[4m\n|Enter your name|\033[0m");
    fgets(a.name, 20, stdin);
    a.name[strcspn(a.name, "\n")] = '\0';  // Remove newline character
    printf("\n");
    printf("________________");
    printf("\033[4m\n|Enter your age|\033[0m");
    scanf("%d", &a.age);
    getchar();  // Consume newline left by scanf
    printf("\n");
    printf("___________________");
    printf("\033[4m\n|Enter your gender|\033[0m");
    scanf("%c", &a.gender);
    getchar();  // Consume newline left by scanf
    printf("\n");
    printf("__________________________");
    printf("\033[4m\n|Enter your mobile number|\033[0m");
    scanf("%lf", &a.mobile_no);
    getchar();  // Consume newline left by scanf 

    while (1) {

        printf("\n");
        printf("__________________________");
        printf("\033[4m\n|Enter the name of disease|\033[0m");
        char str[100];
        fgets(str, 100, stdin);
        str[strcspn(str, "\n")] = '\0'; // Remove newline character

        if (strcmp("exit", str) == 0) {
            printf("----------Thank you----------\n");
            break;
        }
        else if (strcmp("fever", str) == 0) {
            fever();
        } 
        else if (strcmp("vommitting", str) == 0)
        {
            vommitting();
        }
        else if (strcmp("stomachache", str) == 0) {
            stomachache();
        } 
        else if (strcmp("diarrohea", str) == 0) {
            diarrohea();
        } else if (strcmp("bodypain", str) == 0) {
            bodypain();
        } else if (strcmp("itching", str) == 0) {
            itching();
        } else if (strcmp("jaundice", str) == 0) {
            jaundice();
        } else if (strcmp("cold", str) == 0) {
            cold();
        }
        else{
            printf("\nsorry this is not available\n");
        }

        // Ask user if they want to continue or exit
        char continue_input[10];
        printf("Do you want to continue? (Type 'END' to stop): ");
        fgets(continue_input, sizeof(continue_input), stdin);
        continue_input[strcspn(continue_input, "\n")] = '\0';  // Remove newline

        if (strcmp(continue_input, "END") == 0) {
            printf("Exiting program...\n");
            break;
        }
    }
}


void receipt(int *k)
{
    // Print the bill for all purchases
    printf("------------ PHARMA STORE MANAGEMENT ------------\n");
    printf("Customer Name: %s\n", a.name);
    printf("Age: %d\n", a.age);
    printf("Gender: %c\n", a.gender);
    printf("Mobile No: %.0lf\n", a.mobile_no);
    printf("\n------------------------------------------------\n");
    printf("Name of Medicines    | Quantity | Rate | Cost\n");
    printf("------------------------------------------------\n");

    int total_bill = 0;
    for (int i = 0; i < *k; i++) {
        printf("%-20s | %-8d | %-4d | %-4d\n", purchase[i].name, purchase[i].quantity, purchase[i].price, purchase[i].total_cost);
        total_bill += purchase[i].total_cost;  // Add to total bill
    }

    printf("\nTotal Bill: %d\n", total_bill);
    printf("\n\n");
    printf("Thank You for Visiting Us %s",a.name);

}

void lowstock() {
    // For the "fever.txt" file
    FILE *ptr = fopen("fever.txt", "r");  // Open the file for reading
    if (ptr == NULL) {
        printf("Error opening fever.txt file.\n");
        return;  
    }

    char line[256];  
    int threshold = 50;  
    int line_number = 0; 
    int current_quantity;

    
    while (fgets(line, sizeof(line), ptr) != NULL) {
        // Attempt to extract the quantity from the line
        if (sscanf(line, "%*[^q]quantity available - %d", &current_quantity) == 1) {
            // Check if the current quantity is below the threshold
            if (current_quantity < threshold) {
                printf("Low stock detected in 'fever.txt' on line %d: %s\n", line_number + 1, line);
            }
        }

        line_number++; 
    }

    fclose(ptr);  


    // For the "vommitting.txt" file
    FILE *p = fopen("vommitting.txt", "r");  // Open the file for reading
    if (p == NULL) {
        printf("Error opening vommitting.txt file.\n");
        return;  // Exit if the file can't be opened
    }

    line_number = 0;  

    
    while (fgets(line, sizeof(line), p) != NULL) {
    
        if (sscanf(line, "%*[^q]quantity available - %d", &current_quantity) == 1) {
        
            if (current_quantity < threshold) {
                printf("Low stock detected in 'vommitting.txt' on line %d: %s\n", line_number + 1, line);
            }
        }

        line_number++;  
    }

    fclose(p);  

FILE *q = fopen("jaundice.txt", "r"); 
    if (q == NULL) {
        printf("Error opening jaundice.txt file.\n");
        return;  // 
    }

    line_number = 0;  // Reset line number for the second file

    // Read the "vommitting.txt" file line by line
    while (fgets(line, sizeof(line), q) != NULL) {
        // Attempt to extract the quantity from the line
        if (sscanf(line, "%*[^q]quantity available - %d", &current_quantity) == 1) {
            // Check if the current quantity is below the threshold
            if (current_quantity < threshold) {
                printf("Low stock detected in 'jaundice.txt' on line %d: %s\n", line_number + 1, line);
            }
        }

        line_number++;  // Increment line number after processing each line
    }

    fclose(q);
    FILE *c = fopen("cold.txt", "r");  // Open the file for reading
    if (c == NULL) {
        printf("Error opening cold.txt file.\n");
        return;  // Exit if the file can't be opened
    }

    line_number = 0;  // Reset line number for the second file

    // Read the "vommitting.txt" file line by line
    while (fgets(line, sizeof(line), c) != NULL) {
        // Attempt to extract the quantity from the line
        if (sscanf(line, "%*[^q]quantity available - %d", &current_quantity) == 1) {
            // Check if the current quantity is below the threshold
            if (current_quantity < threshold) {
                printf("Low stock detected in 'cold.txt' on line %d: %s\n", line_number + 1, line);
            }
        }

        line_number++;  // Increment line number after processing each line
    }

    fclose(c);  // Close the file after reading

    FILE *d = fopen("diarrohea.txt", "r");  // Open the file for reading
    if (d == NULL) {
        printf("Error opening diarrohea.txt file.\n");
        return;  // Exit if the file can't be opened
    }

    line_number = 0;  // Reset line number for the second file

    // Read the "vommitting.txt" file line by line
    while (fgets(line, sizeof(line), d) != NULL) {
        // Attempt to extract the quantity from the line
        if (sscanf(line, "%*[^q]quantity available - %d", &current_quantity) == 1) {
            // Check if the current quantity is below the threshold
            if (current_quantity < threshold) {
                printf("Low stock detected in 'vommitting.txt' on line %d: %s\n", line_number + 1, line);
            }
        }

        line_number++;  // Increment line number after processing each line
    }

    fclose(d);
    
    FILE *s = fopen("stomachache.txt", "r");  // Open the file for reading
    if (s == NULL) {
        printf("Error opening stomachache.txt file.\n");
        return;  // Exit if the file can't be opened
    }

    line_number = 0;  
    while (fgets(line, sizeof(line), s) != NULL) {
    
        if (sscanf(line, "%*[^q]quantity available - %d", &current_quantity) == 1) {
        
            if (current_quantity < threshold) {
                printf("Low stock detected in 'stomachache.txt' on line %d: %s\n", line_number + 1, line);
            }
        }

        line_number++;  
    }

    fclose(s);
    
    FILE *i = fopen("itching.txt", "r"); 
    if (i == NULL) {
        printf("Error opening itching.txt file.\n");
        return;  // Exit if the file can't be opened
    }

    line_number = 0;  // Reset line number for the second file

    // Read the "vommitting.txt" file line by line
    while (fgets(line, sizeof(line), i) != NULL) {
        // Attempt to extract the quantity from the line
        if (sscanf(line, "%*[^q]quantity available - %d", &current_quantity) == 1) {
        
            if (current_quantity < threshold) {
                printf("Low stock detected in 'itching.txt' on line %d: %s\n", line_number + 1, line);
            }
        }

        line_number++;  
    }

    fclose(i); 
    
    FILE *bo = fopen("bodypain.txt", "r");  // Open the file for reading
    if (bo == NULL) {
        printf("Error opening bodypain.txt file.\n");
        return;  
    }

    line_number = 0;  // Reset line number for the second file

    // Read the "vommitting.txt" file line by line
    while (fgets(line, sizeof(line), bo) != NULL) {
        // Attempt to extract the quantity from the line
        if (sscanf(line, "%*[^q]quantity available - %d", &current_quantity) ==1){
            if (current_quantity < threshold) {
                printf("Low stock detected in 'bodypain.txt' on line %d: %s\n", line_number + 1, line);
            }
        }

        line_number++;  
    }

    fclose(bo);  
}