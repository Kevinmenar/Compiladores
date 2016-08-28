
#include <sys/types.h>
#include <sys/param.h>

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#include "node.h"


//struct node *head = NULL;
//struct node *curr = NULL;

struct node* create_list(struct node *head, char * name, long long value)
{
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    if(NULL == ptr)
    {
        printf("\n Node creation failed \n");
        return NULL;
    }
    ptr->value = value;
    ptr->name = name;
    ptr->next = NULL;

    head = ptr;
    return ptr;
}

struct node* add_to_list(struct node *head, char * name, long long value, bool add_to_end)
{
    struct node *curr = last_node(head);
    if(NULL == head)
    {
        return (create_list(head, name, value));
    }

    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    if(NULL == ptr)
    {
        printf("\n Node creation failed \n");
        return NULL;
    }
    ptr->name = name;
    ptr->value = value;
    ptr->next = NULL;

    if(add_to_end)
    {
        curr->next = ptr;
        curr = ptr;
    }
    else
    {
        ptr->next = head;
        head = ptr;
    }
    return head;
}

struct node * last_node(struct node *head)
{
    struct node *ptr = head;
    struct node *tmp = NULL;
    bool found = false;

    while(ptr != NULL)
    {
        tmp = ptr;
        ptr = ptr->next;
    }
    
    return tmp;
};

void writeRoman (char * caracter){
    FILE *f = fopen("file.txt", "a");
    if (f == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }
    fprintf(f, "The Roman number is %s \n", caracter);
    fprintf(f, "------------------------ \n");
    fclose(f);
}

void writeOutPut (long long  caracter){
    FILE *f = fopen("file.txt", "a");
    if (f == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }
    fprintf(f, "The Total is %lu \n", caracter);
    fclose(f);
}

void writeError (int cont, char * token){
    FILE *f = fopen("file.txt", "a");
    if (f == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }
    fprintf(f, "Error in the token %d ", cont);
    fprintf(f, "Token con inconsistencias %s \n", token);
    fprintf(f, "------------------------ \n");
    fclose(f);
}

//struct node* search_in_list(struct node *head, int value, struct node **prev)
struct node* search_in_list(struct node *head, long long value)
{
    struct node *ptr = head;
    struct node *tmp = NULL;
    bool found = false;

    printf("\n Searching the list for value [%d] \n",value);

    while(ptr != NULL)
    {
        if(ptr->value == value)
        {
            found = true;
            break;
        }
        else
        {
            tmp = ptr;
            ptr = ptr->next;
        }
    }

    if(true == found)
    {
        //if(prev)
            //*e = tmp;
        return ptr;
    }
    else
    {
        return NULL;
    }
}

void printNames (struct node *list_numbers, struct node *txt)
{
    struct node *ptr = txt;
    struct node *tmp = NULL;
    bool found = false;

    while(ptr != NULL)
    {
        char c2[200];
        strcpy(c2, ptr->name);
        if (c2[0] == '0' || c2[0] == '1' || c2[0] == '2' || c2[0] == '3' || c2[0] == '4' || c2[0] == '5' || c2[0] == '6' || c2[0] == '7' || c2[0] == '8' || c2[0] == '9' ){
            words_numbers(ptr->name);
        }
        else{
            createStringNumber (list_numbers, ptr->name);
        }
        tmp = ptr;
        ptr = ptr->next;
    }

}

char * lower_conver (char * name){
    int i = 0;
    char name2[15];
    strcpy(name2, name);

    while( name2[i] ) 
    {
      name2[i] = (tolower(name2[i]));
      i++;
    }

    char * copy = malloc(strlen(name2) + 1);
    strcpy(copy, name2);
    return copy;
}

int int_lenght (int number){
    return floor(log10(abs(number))) + 1;
}


void decimalromanstr(long long number){
    long long delete[] = { 500000000000, 100000000000, 50000000000, 10000000000, 5000000000, 1000000000, 500000000 ,100000000, 50000000, 10000000, 5000000 ,1000000, 500000, 100000, 50000, 10000, 5000, 1000,900,500,400,100,90,50,40,10,9,5,4,1};
    char * symbol[] = { "D|||" ,"C|||", "L|||", "X|||", "V|||","M||","D||", "C||", "L||", "X||","V||","M|","D|","C|","L|","X|","V|","M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
    char result[256] = "\0";         
    long long i = 0;                  
    while (number){
        while (number/delete[i]){
            strcat(result, symbol[i]); 
            number -= delete[i];       
        }
        i++;                
    }
    char * copy = malloc(strlen(result) + 1);
    strcpy(copy, result);
    writeRoman (copy);
    printf("The Roman Total is %s \n", result);
}

char * createStringNumber (struct node *list_numbers, char * line){
    int cont = 0;
    int flag = 0;
    const char s[1] = " ";
    char *token_anterior;
    char *token;
    long long temp = 0;
    long long tempMax = 0;
    long long total = 0;
    long long ultraTotal = 0;

    token = strtok(line, " ");
    while(token != NULL)
    {
        token = lower_conver (token);
        if (strcmp(token, "y") == 0 && (30 < temp < 100)) {
            cont = cont + 1;
            token = strtok(NULL,s);
            continue;
        }
        else {
            if ((is_in_list(list_numbers, token) == 1)) {
                int number = search_name(list_numbers, token);
                if (temp == 0) {
                    temp = number;
                    total = number;
                    if(number == 1000000){ //Para este caso deberia escribir una lista donde este tipo de saltos, ya esta implementado en funcion
                        ultraTotal = total + ultraTotal;
                        total = 0;
                        tempMax = 0;
                        temp = 0;
                    }
                }
                else {
                    if (number >= 1000 && number > temp){
                        if (tempMax < temp*number){
                            tempMax = total*number;
                            total = total*number;
                            temp = number;
                            if(number == 1000000){ //Para este caso deberia escribir una lista donde este tipo de saltos, ya esta implementado en funcion
                                ultraTotal = total + ultraTotal;
                                total = 0;
                                tempMax = 0;
                                temp = 0;
                            }
                            if (((strcmp(token_anterior, "uno") == 0) && (strcmp(token, "millones") == 0)) || ((strcmp(token_anterior, "un") == 0) && (strcmp(token, "millones") == 0)) || ((strcmp(token_anterior, "uno") == 0) && (strcmp(token, "mil") == 0)) || ((strcmp(token_anterior, "uno") == 0) && (strcmp(token, "millon") == 0)) || ((strcmp(token_anterior, "veintiuno") == 0) && (strcmp(token, "millones") == 0)) || ((strcmp(token_anterior, "ciento") == 0) && ( (strcmp(token, "mil") == 0))) || ((strcmp(token_anterior, "ciento") == 0) && ( (strcmp(token, "millones") == 0))) || ( (1000000>temp>1) && ( (strcmp(token, "millon") == 0)))) {
                                flag = 1;
                                printf("Error in the token %d ", cont);
                                printf(" Token con inconsistencias %s \n",token);
                                writeError (cont, token);
                                break;
                            }
                        }
                        else{
                            flag = 1;
                            printf("Error in the token %d ", cont);
                            printf(" Token con inconsistencias %s \n",token);
                            writeError (cont, token);
                            break;
                        }
                    }
                    else{
                        if (number < 1000 && (int_lenght (temp) > int_lenght (number))){
                            total = total + number;
                            temp = number;
                            if (((strcmp(token_anterior, "cien") == 0) && ( 0 < number < 100))) {
                                flag = 1;
                                printf("Error in the token %d ", cont);
                                printf(" Token con inconsistencias [%s] \n",token);
                                writeError (cont, token);
                                break;
                            }
                        }
                        else{
                            flag = 1;
                            printf("Error in the token %d ", cont);
                            printf(" Token con inconsistencias [%s] \n",token);
                            writeError (cont, token);
                            break;
                        }
                    }
                }
            }
            else {
                flag = 1;
                printf("Error in the token %d ", cont);
                printf("  Token con inconsistencias [%s] \n",token);
                writeError (cont, token);
                break;
            }
        }
        cont = cont + 1;
        token_anterior = token;
        token = strtok(NULL,s);
    }
    if ((strcmp(token_anterior, "ciento") != 0)) {
        if (flag != 1){
            ultraTotal = total + ultraTotal;
            printf("The Total is %lu \n", ultraTotal);
            writeOutPut (ultraTotal);
            decimalromanstr(ultraTotal);
        }
    }
    else {
        printf("Error in the token %d ", cont);
        printf("  Token con inconsistencias [%s] \n",token_anterior);
        writeError (cont, token_anterior);
    }
}


int is_in_list(struct node *head, char * name)
{
    struct node *ptr = head;
    struct node *tmp = NULL;
    bool found = false;

    while(ptr != NULL)
    {
        
        if(strcmp(ptr->name, name) == 0)
        {
            return 1;
        }
        else
        {
            tmp = ptr;
            ptr = ptr->next;
        }
    }

    return 0;
}

long long  search_name(struct node *head, char * name)
{
    struct node *ptr = head;
    struct node *tmp = NULL;
    bool found = false;

    while(ptr != NULL)
    {
        if(strcmp(ptr->name, name) == 0)
        {
            return ptr->value;
        }
        else
        {
            tmp = ptr;
            ptr = ptr->next;
        }
    }

    return 0;
}

void print_list(struct node *head)
{
    struct node *ptr = head;

    printf("\n -------Printing list Start------- \n");
    while(ptr != NULL)
    {
        printf("\n [%d] \n",ptr->value);
        printf("\n [%s] \n",ptr->name);
        ptr = ptr->next;
    }
    printf("\n -------Printing list End------- \n");

    return;
}


char * my_strcat(const char * s1, const char * s2)
{
    size_t len1 = strlen(s1);
    size_t len2 = strlen(s2);
    char *result = malloc(len1+len2+1);
    memcpy(result, s1, len1);
    memcpy(result+len1, s2, len2+1);
    return result;
    
}

void reverse(char *begin, char *end);
 

void reverseWords(char *s)
{
  char *word_begin = s;
  char *temp = s;
 
  while( *temp )
  {
    temp++;
    if (*temp == '\0')
    {
      reverse(word_begin, temp-1);
    }
    else if(*temp == ' ')
    {
      reverse(word_begin, temp-1);
      word_begin = temp+1;
    }
  } 
  reverse(s, temp-1);
}
 
void reverse(char *begin, char *end)
{
  char temp;
  while (begin < end)
  {
    temp = *begin;
    *begin++ = *end;
    *end-- = temp;
  }
}

void words_numbers(char * numeroEntrada)
{
    
    int i = 0;
    //==================Tomar fila y analizar por Numeros===============================*/
    int counter=0;
    char* resultado;
    
    int cantidadNumeros;
    //char * numeroEntrada="999999";
    printf ("B2) Generando palabras-------------------------\n");
    cantidadNumeros=strlen(numeroEntrada);
    
    counter=cantidadNumeros-1;
    
    printf ("B2) Generando palabras-------------------------\n");
    printf ("B2) Generando palabras-------------------------\n");
    
    char * result="";
    printf ("B2) Generando palabras-------------------------\n");
    int PosicionNumeral=1;
    
    int flagMil=0;
    int flagMillon=0;
    int flagUnique=0;
    int auxiliarN=0;
    int validar100=0;
    
    printf ("B2) Generando palabras-------------------------\n");

    char lastValue='x';
    char lastValue2='x';
    char lastValue3='x';
    char c;
    printf ("B6) Generando palabras-------------------------\n");
    
    while(counter>=0 )
    {
        //printf ("B6 \n");
        //printf("Cont [%d] \n",counter);
        c = numeroEntrada[counter];
        switch( PosicionNumeral)
        {
            case 1:
                printf("Cont case 1[%d] %d \n",counter, PosicionNumeral);
                lastValue=c;
                if(flagMillon==1 && counter==0)
                {
                    switch (c) 
                    {
                        case '0': break;
                        case '1':
                        
                            if(flagUnique==0)
                            {
                                printf("uno");
                                flagUnique=1;
                            }
                            else
                            {
                                if(counter==0){printf("un");}
                            }
                        break;
                        case '2':resultado = my_strcat(resultado,"dos");printf("dos");break;
                        case '3':resultado = my_strcat(resultado,"tres");printf("tres");break;
                        case '4':resultado = my_strcat(resultado,"cuatro");printf("cuatro");break;
                        case '5':resultado = my_strcat(resultado,"cinco");printf("cinco");break;
                        case '6':resultado = my_strcat(resultado,"seis");printf("seis");break;
                        case '7':resultado = my_strcat(resultado,"siete");printf("siete");break;
                        case '8':resultado = my_strcat(resultado,"ocho");printf("ocho");break;
                        case '9':resultado = my_strcat(resultado,"nueve");printf("nueve");break;
                        default:resultado = my_strcat(resultado,"#ERROR : %c #");printf("ERROR - %c - \n",numeroEntrada[counter]);break;
                    }
                    flagMillon=0;
                }
                if((counter-1)>=0 )
                {
                    if(numeroEntrada[counter-1] !='1')
                    {
                        switch (c) 
                        {
                            case '0': break;
                            case '1':
                            
                                if(flagUnique==0)
                                {
                                    resultado = my_strcat(resultado,"uno");printf("uno");
                                    flagUnique=1;
                                }
                                else
                                {
                                    resultado = my_strcat(resultado,"un");printf("un");
                                }
                            break;
                            case '2':resultado = my_strcat(resultado," dos ");printf("dos");break;
                            case '3':resultado = my_strcat(resultado," tres ");printf("tres");break;
                            case '4':resultado = my_strcat(resultado," cuatro ");printf("cuatro");break;
                            case '5':resultado = my_strcat(resultado," cinco ");printf("cinco");break;
                            case '6':resultado = my_strcat(resultado," seis ");printf("seis");break;
                            case '7':resultado = my_strcat(resultado," siete ");printf("siete");break;
                            case '8':resultado = my_strcat(resultado," ocho ");printf("ocho");break;
                            case '9':resultado = my_strcat(resultado," nueve ");printf("nueve");break;
                            default:resultado = my_strcat(resultado,"ERROR - %c - \n");printf("ERROR - %c - \n",numeroEntrada[counter]);break;
                        }
                    }
                    else if(numeroEntrada[counter-1] =='1')
                    {
                        switch (c) 
                        {
                            case '0':resultado = my_strcat(resultado,"diez");printf("diez");break;
                            case '1':resultado = my_strcat(resultado,"once");printf("once");break;
                            case '2':resultado = my_strcat(resultado,"doce");printf("doce");break;
                            case '3':resultado = my_strcat(resultado,"trece");printf("trece");break;
                            case '4':resultado = my_strcat(resultado,"catorce");printf("catorce");break;
                            case '5':resultado = my_strcat(resultado,"quince");printf("quince");break;
                            case '6':resultado = my_strcat(resultado,"dieciseis");printf("dieciseis");break;
                            case '7':resultado = my_strcat(resultado,"diecisiete");printf("diecisiete");break;
                            case '8':resultado = my_strcat(resultado,"dieciocho");printf("dieciocho");break;
                            case '9':resultado = my_strcat(resultado,"diecinueve");printf("diecinueve");break;
                            default:resultado = my_strcat(resultado,"ERROR - %c - \n");printf("ERROR - %c - \n",numeroEntrada[counter]);break;
                        }
                    }
                    
                }
                
            break;
            case 2:
                printf("Cont case 2[%d] \n",counter);
                lastValue2=c;
                switch (c) 
                {
                    case '0': break;
                    case '1': break;
                    case '2':
                        if(lastValue=='0'){resultado = my_strcat(resultado," veinte ");printf(" veinte ");}
                        else{resultado = my_strcat(resultado," veinti ");printf(" veinti ");}
                    break;
                    case '3':resultado = my_strcat(resultado," y treinta ");printf(" y treinta ");break;
                    case '4':resultado = my_strcat(resultado," y cuarenta ");printf(" y cuarenta ");break;
                    case '5':resultado = my_strcat(resultado," y cincuenta ");printf(" y cincuenta ");break;
                    case '6':resultado = my_strcat(resultado," y sesenta ");printf(" y sesenta ");break;
                    case '7':resultado = my_strcat(resultado," y setenta ");printf(" y setenta ");break;
                    case '8':resultado = my_strcat(resultado," y ochenta ");printf(" y ochenta ");break;
                    case '9':resultado = my_strcat(resultado," y noventa ");printf(" y noventa ");break;
                    default:resultado = my_strcat(resultado," ERROR - %c - \n ");printf("ERROR - %c - \n",numeroEntrada[counter]);break;
                }
            break;
            case 3:
                printf("Cont case 3[%d] \n",counter);
                lastValue3=c;
                switch (c)
                {
                    case '0':break;
                    case '1':resultado = my_strcat(resultado," ciento ");printf(" ciento ");break;
                    case '2':resultado = my_strcat(resultado," doscientos ");printf(" doscientos ");break;
                    case '3':resultado = my_strcat(resultado," trescientos ");printf(" trescientos ");break;
                    case '4':resultado = my_strcat(resultado," cuatrocientos ");printf(" cuatrocientos "); break;
                    case '5':resultado = my_strcat(resultado," quinientos ");printf(" quinientos ");break;
                    case '6':resultado = my_strcat(resultado," seiscientos ");printf(" seiscientos "); break;
                    case '7':resultado = my_strcat(resultado," setecientos ");printf(" setecientos "); break;
                    case '8':resultado = my_strcat(resultado," ochocientos ");printf(" ochocientos ");break;
                    case '9':resultado = my_strcat(resultado," novecientos ");printf(" novecientos "); break;    
                    default:resultado = my_strcat(resultado," ERROR - %c - \n ");printf("ERROR - %c - \n",numeroEntrada[counter]);break;
                }
            break;
            case 4:
                printf("Cont case 4[%d] \n",counter);
                if(flagMillon==1)
                {
                    if(counter==0 && c=='1'){resultado = my_strcat(resultado," millon ");printf(" millon ");}
                    else{resultado = my_strcat(resultado," millones ");printf(" millones ");}
                    PosicionNumeral=0;
                    flagMil=0;
                    counter++;
                    flagMillon=0;
                }
                
                else if(flagMil==0)
                {
                    if(c!='0' ){resultado = my_strcat(resultado," mil ");printf(" mil ");}
                    PosicionNumeral=0;
                    counter++;
                    flagMil=1;
                    flagMillon=1;
                    validar100=1;
                    flagUnique=0;
                }
                else
                {
                    PosicionNumeral=4;
                    flagMil=0;
                    flagMillon=0;
                }
            break;
        }   
        flagUnique=1;
        PosicionNumeral++;
        counter--;
    }
        reverseWords(resultado);
        printf("\n==============================================================\n");
        //printf("\n %s \n",resultado);
        //------------------------------------------------------------------------------------------
        //return resultado;
        //writeRoman (resultado);
}