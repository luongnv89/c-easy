/**
 * c-easy library implementation
 */

#include "easy.h"

 int str_compare(char * str1, char * str2){
 	if(str1!=NULL && str2!=NULL){
 		return strcmp(str1,str2)==0;	
 	}
 	return 0;
 }

 int str_index(char * str, char *  substr){
 	if(str!=NULL && substr!=NULL){
 		char *p_index;
	 	p_index = strstr(str,substr);
	 	if(p_index==NULL) return -1;
	 	return (strlen(str)-strlen(p_index));	
 	}
 	return -1;
 }
	
 char * str_sub(char * str, int start_index, int end_index){
 	if(str != NULL && start_index >= 0 && end_index > start_index){
 		if(end_index >= strlen(str)) return NULL;
 		char * sub;
 		sub = (char *)malloc(end_index - start_index + 1);
 		memcpy(sub,(str + start_index), start_index - end_index);
 		return sub;
 	}
 	return NULL;
 	
 }

 char * str_combine(char * str1, char * str2){
 	char * comb;
 	if(str1 == NULL && str2 == NULL){
 		comb == NULL;
 	}else if(str1 == NULL && str2 != NULL) {
 		comb = (char *)malloc(sizeof(str2));
 		strcpy(comb,str2);
 	}else if(str2 == NULL && str1 != NULL){
 		comb = (char *)malloc(sizeof(str1));
 		strcpy(comb,str1);
 	}else{
 		comb = (char*)malloc(sizeof(str1)+sizeof(str2));
 		strcpy(comb,str1);
 		strcpy(comb,str2);
 	}
 	return comb;
 }

 int str_replace(char * str, char * str1, char * rep){
 	if(str != NULL && str1 != NULL && rep !=NULL){
 		char * new_string;
	 	char ** array_string;
	 	array_string = str_split(str,str1);
	 	int i=0;
	 	int size = 0;
	 	while(array_string[i] !=NULL){
	 		size += sizeof(array_string[i]);
	 		size += sizeof(rep);
	 		i++;
	 	}
	 	i=0;
	 	new_string = (char *)malloc(size);
	 	while(array_string[i] !=NULL){
	 		strcat(new_string,array_string[i]);
	 		i++;
	 	}
	 	return new_string;	
 	}
 	return 0;
 	
 }

 char ** str_split(char * str, char * spliter){

 	if(str != NULL && spliter !=NULL){
 		char * array_string[255];

	 	int start_index = 0;
	 	int s_index;
	 	s_index = str_index(str,spliter);
	 	int index_of_string = 0;
	 	while(s_index != -1){
	 		char *new_string;
	 		new_string = str_sub(str + start_index,start_index,s_index);
	 		array_string[index_of_string] = new_string;
	 		start_index = s_index + strlen(spliter);
	 		index_of_string++;
	 		s_index = str_index(str + start_index,spliter);
	 	}

	 	if(str + start_index != NULL){
	 		char *last_string;
	 		last_string = str_sub(str + start_index, start_index, strlen(str)-1);
	 		array_string[index_of_string] = last_string;
	 	}
	 	return array_string;
	 }
 	return NULL;
 	
 }