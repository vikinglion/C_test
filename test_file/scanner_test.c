#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

//TokenType
// Take math expression as an example
// number, ID, (, ), +, -, *, /
enum tokenType {ASSIGN, NUMBER, ID, LPARN, RPARN, PLUS, MINUS, TIME, DIV};

/*
enum tokenType x;
x = ID;
*/

typedef enum tokenType TokenType;

// Token
// token type + token string

struct token{
	TokenType type;
    const char * str;
};

typedef struct token Token;


struct tokenNode{
	Token token;
	struct tokenNode * next;
	struct tokenNode * prev;
};

typedef struct tokenNode TokenNode;

struct tokenList{
	struct tokenNode * firstNode;
	struct tokenNode * lastNode;
	int len;
};

typedef struct tokenList TokenList;

void link(TokenNode * node,TokenList * list){
	node->prev = list->lastNode;
	if (list->lastNode != NULL){
		list->lastNode->next = node;
	}
	list->lastNode = node;
	if (list->len == 0){
		list->firstNode = node;
	}
	list->len++;
}


TokenNode * scan(TokenList * list,char * inputf){
	int currentState = 0; // 0 means the start state
  	char tokenString [30]; 
  	char tokenStringPos = 0; // the position to write the next character
  	int i = 0;
  	char c;
	while(1){
			if(currentState == 3){
	   			currentState = 0;
	   			tokenStringPos = 0;
	   			*tokenString = '\0';
	   		}
			if(currentState == 4){ //error
        		printf("Something wrong with %c", c);
    			exit(1);
	   		}
			c = *(inputf + i);
		/*
	    for each state, and each character, decide 3 things 
         1. what is the next state?
         2. Should the character be saved into a token string?
         3. Is a token fully received? If yes, what is the token type.
         4. Should the input position be moved back one place? 
         */
	   
			if (currentState == 0){
	   	   		if(isspace(c))
	   	   	  		; // do nothing
	   	      /* space like \r \n \t ' ' */
	   	   		else if( isalpha(c)){
					currentState = 1 ;// InID
	   			}
	   	   		else if( isdigit(c)){
	   	   			currentState = 2 ;// InID
	   			}
	   	   		else if(c == '('){
            		// create a token
	   	   			currentState = 3;
            		TokenNode * node= (TokenNode *) malloc(sizeof(TokenNode));
            		node->token.type = LPARN;
            		node->token.str = "(";
	   			}
	   	   		else if(c == ')'){
	   	   			currentState = 3;
	   	   			TokenNode * node= (TokenNode *) malloc(sizeof(TokenNode));
                	node->token.type = RPARN;
                	node->token.str = ")";
	   			}
	   			else if(c == '='){
	   	   			currentState = 3;
	   	   			TokenNode * node= (TokenNode *) malloc(sizeof(TokenNode));
                	node->token.type = ASSIGN;
                	node->token.str = "=";
	   			}
	   	   		else if(c == '+'){
	   	   			currentState = 3;
	   	   			TokenNode * node= (TokenNode *) malloc(sizeof(TokenNode));
                	node->token.type = PLUS;
                	node->token.str = "+";
                	link(node,list);
            	}
           		else if(c == '*'){
	   	   			currentState = 3;
	   	   			TokenNode * node= (TokenNode *) malloc(sizeof(TokenNode));
                	node->token.type = TIME;
                	node->token.str = "*";
				}
				else if(c == '/'){
	   	   			currentState = 3;
	   	   			TokenNode * node= (TokenNode *) malloc(sizeof(TokenNode));
                	node->token.type = DIV;
                	node->token.str = "/";
				}
				else if(c == '-'){
	   	   			currentState = 3;
	   	   			TokenNode * node= (TokenNode *) malloc(sizeof(TokenNode));
                	node->token.type = MINUS;
                	node->token.str = "-";
				}
	   			else { // wrong
              		currentState = 4;
	   			}
	   		} // end of state 0

	   		if(currentState == 1){ // InID
           		if( isalpha(c) ){
           	   		tokenString[tokenStringPos++] = c;
           	   		//printf("%s", tokenString);
           		}
           		else{
           	  		char * addr;
           	  		int k;
           	  		currentState = 3;
           	  		TokenNode * node= (TokenNode *) malloc(sizeof(TokenNode));
              		node->token.type = ID;
              		addr = (char *) malloc(tokenStringPos+1);
              		for(k=0; k < tokenStringPos; k++)
              	 		addr[k] = tokenString[k];
              		addr[k] = '\0'; // make a true string
               		// append the tokenNode to the list
              		node->token.str = addr;
              		link(node,list);
           		}
	   		}
	   		else if(currentState == 2 ){ // InNUM
	   			if( isdigit(c)){
	   				tokenString[tokenStringPos++] = c;
	   				//printf("%s", tokenString);
	   			}
	   			else{
	   				char * addr;
           	  		int k;
           	  		currentState = 3;
           	  		TokenNode * node= (TokenNode *) malloc(sizeof(TokenNode));
              		node->token.type = NUMBER;
              		addr = (char *) malloc(tokenStringPos+1);
              		for(k=0; k < tokenStringPos; k++)
              	 		addr[k] = tokenString[k];
					addr[k] = '\0';
					node->token.str = addr;
					link(node,list);
					//int ungetc(int c, inputf);
					i--;	
	   			}
	   		}
	i++;
	if(c == '\0')
		break;
	}
}

 




/* 
Assume some DFA for the scanner is created. It can tell
1.) given the current state and the current symbol, 
what is the next current state. 
2.) When it is ready to obtain a token 
   (all characters of the token is received).
3.) Whether the last symbol read should be put back into the input stream. 
*/


static void print_token_list(TokenList * list){
	printf("len = %d\n", list->len);
	int i = 0;
	TokenNode * node = list->firstNode;
	while(i != list->len){
		if (node == NULL)
			break;
		printf("list[%d]: %s\n", i, node->token.str);
		node = node->next;
		i++;
	}
}

int main(void){
	char* inputf ="123+2+3+hello world";
	TokenList * list = (TokenList*)malloc(sizeof(TokenList));
	list->firstNode = NULL;
	list->lastNode = NULL;
	list->len = 0;
	scan(list, inputf);
	printf("%s\n", inputf);
	print_token_list(list);
	return 0;
}
