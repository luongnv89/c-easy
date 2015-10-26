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
    if(str == NULL) return NULL;

    if(start_index < 0) return NULL;

    if(end_index >= strlen(str)) return NULL;

    if( start_index >= end_index) return NULL;

 	int len = end_index - start_index + 1;
    char * sub;
 	sub = (char *)malloc(len + 1);
 	memcpy(sub,(str + start_index), len);
    sub[len]='\0';
 	return sub;
 }

 char * str_combine(char * str1, char * str2){
 	char * comb;
    int len = 0;
 	if(str1 == NULL && str2 != NULL) {
        len = strlen(str2);
 		comb = (char *)malloc(len + 1);
 		memcpy(comb,str2,len);
        comb[len]='\0';
 	}else if(str2 == NULL && str1 != NULL){
        len = strlen(str1);
 		comb = (char *)malloc(len + 1);
 		strcpy(comb,str1);
 	}else if(str2 != NULL && str1 != NULL){
        len = strlen(str1) + strlen(str2);
 		comb = (char*)malloc(len + 1);
 		strcpy(comb,str1);
 		strcat(comb,str2);
 	}
 	return comb;
 }

char ** str_split(char * str, char * spliter){
    if(str != NULL && spliter !=NULL){
        char *str_input = str;
        char * array_string[strlen(str_input)];
        int start_index = 0;
        int s_index;
        s_index = str_index(str_input,spliter);
        int index_of_string = 0;
        while(s_index != -1){
            if(s_index == 0){
                start_index = start_index + strlen(spliter);
            }else{
                char *new_string;
                new_string = str_sub(str_input,start_index,start_index + s_index-1);
                array_string[index_of_string] = new_string;
                start_index = start_index + s_index + strlen(spliter);
                index_of_string++; 
            }
            s_index = str_index(str_input + start_index,spliter);   
        }

        if(str_input + start_index != NULL){
            char *last_string;
            last_string = str_sub(str_input, start_index, strlen(str_input)-1);
            array_string[index_of_string] = last_string;
        }
        array_string[index_of_string+1]=NULL;
        return array_string;
     }
    return NULL;
    
 }


 char * str_replace(char * str, char * str1, char * rep){
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
	 	int j=0;
	 	new_string = (char *)malloc(size);
	 	while(array_string[j] !=NULL){
	 		strcat(new_string,array_string[j]);
	 		j++;
	 	}
	 	return new_string;	
 	}
 	return NULL;
 	
 }

 char * str_subvalue(char *str, char* begin, char * end){
    if(str == NULL) return NULL;
    
    if(begin == NULL && end == NULL) return NULL;

    int begin_index = str_index(str,begin);
    int end_index = str_index(str,end);

    if(begin == NULL){
        return str_sub(str,0,end_index - 1);
    }

    if(end == NULL){
        return str_sub(str,begin_index + strlen(begin),strlen(str)-1);
    }
    

    if(begin_index == -1 ) return NULL;

    
    if(end_index == -1) return NULL;

    if(begin_index + strlen(begin) >= end_index) return NULL;

    int start_index = begin_index + strlen(begin);

    return str_sub(str,start_index,end_index - 1);
}

char * str_subend(char *str, char* begin){
	if(str != NULL && begin !=NULL){
        char *fromBegin;
        fromBegin = (char*)malloc(sizeof(str));

        fromBegin = strstr(str,begin);
        fromBegin = fromBegin + strlen(begin);

        if(fromBegin == NULL){
            return NULL;
        }else{
            int len;
            len = strlen(fromBegin);
            char *ret;
            ret = (char * )malloc((len+1)*sizeof(char));
            strncpy(ret,fromBegin,len);
            ret[len]='\0';
            return ret;
        }
    }
    return NULL;
}

char ** str_add_new_string(char **array,char *str){
  if(str == NULL) return 0;
  int i=0;
  while(array[i] != NULL){
    i++;
  }

  array[i] = (char*)malloc(strlen(str)+1);
  strcpy(array[i],str);
  array[i][strlen(array[i])]='\0';
  return array;
}

void str_print_array(char **array){
    int i=0;
    while(array[i] != NULL){
        printf("Array[%d]: %s\n",i,array[i]);
        i++;
    }
}


char * cmd_run_command(char *cmd){
    if(cmd==NULL){
        return NULL;
    }else{
        FILE *pp;
        char *output;
        output=(char*)malloc(255*sizeof(char));
        pp = popen(cmd, "r");
        if (pp != NULL) {
            while (1) {
                char *line;
                char buf[255];
                line = fgets(buf, sizeof(buf), pp);
                if (line != NULL) {
                    if(output==NULL){
                        output=line;
                    }else{
                        int len = strlen(output)+strlen(line)+1; 
                        output=realloc(output,len);
                        strcat(output,line);
                        output[len]='\0';    
                    }
                }else{
                    // End of output
                    break;
                }
            }
        }
        // pclose(pp);
        return output;
    }
    return NULL;
}

int * str_get_indexes(char *str,int c){
    if(str==NULL) return NULL;
    int *indexes;
    indexes = (int*)malloc((strlen(str)+1)*sizeof(int));
    int i=0;
    int current_index = 0;
    for(i=0;i<strlen(str);i++){
        if((int)str[i]==c){
            indexes[current_index]=i;
            current_index++;
        }
    }
    indexes[current_index]=-1;
    return indexes;
}

char * str_replace_all_char(char *str,int c1, int c2){
    if(str==NULL) return NULL;
    char *new_str;
    new_str = (char*)malloc(strlen(str)+1);
    memcpy(new_str,str,strlen(str));
    new_str[strlen(str)] = '\0';
    int i;
    for(i=0;i<strlen(str);i++){
        if((int)new_str[i]==c1){
            new_str[i]=(char)c2;
        }
    }
    return new_str;
}

char * str_sub_index(char *str, int start, int end){
    
    int len = end - start-1;

    char *substr;
    substr = (char*)malloc(len);
    memcpy(substr,str + start + 1,len);
    substr[len]='\0';
    return substr;    
}