#include <stdlib.h>
#include <stdio.h>
#include "easy.h"

const char str1[] = "Je suis en train de tester. Je suis tres content maintenant";

const char str2[] = "Il est dimanche. Il pleux";

int main(int argc, char const *argv[])
{
	printf("str_compare[TRUE]: %s\n",str_compare(str1,str1)==1?"Passed":"Failed");

	printf("str_compare[FALSE]: %s\n",str_compare(str1,str2)==0?"Passed":"Failed");

	printf("str_index[-1]: %s\n",str_index(str1,"il")==-1?"Passed":"Failed");

	printf("str_index[0]: %s\n",str_index(str1,"Je")==0?"Passed":"Failed");

	printf("str_index[>0]: %s\n",str_index(str1,"suis")>0?"Passed":"Failed");

	print("str_sub(0,10): %s\n",str_sub(str1,0,10));

	return 0;
}