#include <stdio.h>
#include <stdbool.h>
#include <string.h>
/**
 * Palindromo
 * @author Vinicius Francisco da Silva
 * @version 1 08/2017
 */
bool igual(char* str);
int main(){
	char str[10000];
	for(scanf("%[^\n]\n",str); !igual(str); scanf("%[^\n]\n",str)){
		bool isPalindromo(char* str);
		bool resp = isPalindromo(str);
		if(resp == true){
			printf("SIM\n");
		}// End if
		else{
			printf("NAO\n");
		}// End else
		//setbuf(stdin, NULL);
	}// End for
	return 0;
}// End main()

/**
 * Verifica se é um palindromo ou não.
 * @return true caso seja um palindromo
 * false caso não seja
 */
bool isPalindromo(char* str){
	int i = 0;
	int j = strlen(str)-1;
	bool resp = false;
	while(i < j && j > i){
		if(str[i] == str[j]){
			resp = true;
		}// End if
		else{
			return false;
		}// End else
		i++;
		j--;
	}// End while
	return resp;
}// End ehPalindromo()

/**
 * Verifica se é a string que está como
 * parametro é igual a string "FIM".
 * @return true caso seja igual
 * false caso contrário
 */
bool igual(char str[]){
	bool resp = false;
	if(strlen(str) == 3){
		if(str[0] == 'F' && str[1] == 'I' && str[2] == 'M'){
			resp = true;
		}// End if
		else{
			return false;
		}// End else
	}// End if
		else{
			return false;
		}// End else	
		return resp;
}// End igual()
