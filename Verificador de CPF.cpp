#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
   int c , x , y , dig , dig1 , d1 , d2 , pen , resp, result, soma1, soma2;
   float resto, porval, porinv, tot , val , inv ;
   char retorno;
	main(){
 setlocale (LC_ALL, "Portuguese");
 	printf ("Projeto de LE - Validador de n�mero de CPF\n\n");
 	do{
 		x = 10;
		y = 11;
 		for (c = 1; c<=11; c++){
 			
			printf ("Digite o %d� digito do CPF:\n", c);
			scanf ("%d", &dig);
			while ((dig>9)||(dig<0)){
				printf ("Digito inv�lido, digite o %d� n�mero de 0 a 9:\n", c);
				scanf ("%d", &dig);
			}
			if (c <= 9) {
				result = dig*x;
				soma1 = soma1 + result;
				x = x-1;
				result = dig*y;
				soma2 = soma2 + result;
				y = y-1;
			}
			
			if (c == 10){
				resto = soma1 % 11;
				pen = dig;
				if (resto < 2) {
					d1 = 0;
				}else{
					d1 = 11 - resto;
				}
				soma2 = soma2 + (d1*2);
			}
			
			if (c == 11) {
				resto = soma2%11;
				if (resto < 2) {
					d2 = 0;
				}else{
					d2 = 11 - resto;
				}
				printf ("\n=========================\n");
				if ((d1 == pen) && (d2 == dig)) {
					printf ("Seu CPF � v�lido\n");
					val = val + 1;
					tot = tot + 1;
				}else{
					printf ("Seu CPF � inv�lido!\n");
					printf ("Os dois ultimos digitos corretos s�o: %d e %d\n", d1, d2);
					inv = inv+1;
					tot = tot + 1;
				}                                                                  
			}
			
		 }
		 	  printf ("Gostaria de repetir? ( s = 1 e n = 2)\n");
	          printf ("Resposta: ");
	          retorno = scanf ("%d", &resp);
	          while ((resp != 1)&&(resp != 2)&&(retorno == 0)){
	          	printf ("Resposta inv�lida, digite 1 para sim e 2 para n�o:\n");
                fflush (stdin);
	          	scanf ("%d", &resp);
	         
			  }
	          soma1 = 0;
	          soma2 = 0;
     }while (resp == 1);
     		   porval = (val*100)/tot;
	           porinv = (inv*100)/tot;
	           printf ("N�mero de CPF's testados: %d \n",  int (tot));
	           printf ("CPF's v�lidos: %d \n", int (val));
	           printf ("Porcentagem de CPF's v�lidos: %f%% \n" , porval);
	           printf ("CPF's inv�lidos: %d \n", int (inv));
	           printf ("Porcentagem de CPF's inv�lidos: %f%% \n" , porinv);
}
