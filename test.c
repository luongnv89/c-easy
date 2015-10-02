#include <stdlib.h>
#include <stdio.h>
#include "easy.h"

char *str1= "Je suis en train de tester. Je suis tres content maintenant";

char *str2= "Il est dimanche. Il pleux";

char * str_array[10];

int main(int argc, char const *argv[])
{
	// printf("str_compare[TRUE]: %s\n",str_compare(str1,str1)==1?"Passed":"Failed");

	// printf("str_compare[FALSE]: %s\n",str_compare(str1,str2)==0?"Passed":"Failed");

	// printf("str_index[-1]: %s\n",str_index(str1,"il")==-1?"Passed":"Failed");

	// printf("str_index[0]: %s\n",str_index(str1,"Je")==0?"Passed":"Failed");

	// printf("str_index[>0]: %s\n",str_index(str1,"suis")>0?"Passed":"Failed");

	// print("str_sub(0,10): %s\n",str_sub(str1,0,10));

	char *test;
	test = str_subvalue(str1,"suis ",".");
	printf("result:\n%s\n",test);

	char *test2;
	test2 = str_subvalue(str2,"Il est ",".");
	printf("result:\n%s\n",test2);

	char *test3;
	test3 = str_subvalue(str1,"tester. Je suis "," maintenant");
	printf("result:\n%s\n",test3);

	char *test4;
	test4 = str_subend(str1,"suis");
	printf("result: \n%s\n",test4);

	str_print_array(str_array);
	str_add_new_string(str_array,"ABC");
	str_print_array(str_array);
	str_add_new_string(str_array,"ABCD");
	str_print_array(str_array);
	str_add_new_string(str_array,"ABCE");
	str_print_array(str_array);
	str_add_new_string(str_array,"ABCF");
	str_print_array(str_array);
	str_array[2]=NULL;
	str_print_array(str_array);
	str_add_new_string(str_array,"ABCF-hehe");
	str_print_array(str_array);

	if(strlen(str1)>strlen(str2)){
		str1 = str2;
	}

	printf("result: \n%s\n",str1);
	
	char *cmd;
	cmd = (char*)malloc(255*sizeof(char));
	printf("Enter command to be executed: \n");
	scanf("%s",cmd);
	char *output = str_exe_command(cmd);
	printf("Output: %s",output);
	return 0;
}