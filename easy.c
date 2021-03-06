/**
 * c-easy library implementation
 */

#include "easy.h"

 int str_compare(char * str1, char * str2){

 	if(str1 == NULL && str2 == NULL) return 1;

    if(str1!=NULL && str2!=NULL){
 		return strcmp(str1,str2)==0;
 	}
 	return 0;
 }

 int str_index(char * str, char *  substr){

 	if(str!=NULL && substr!=NULL){
 		char *p_index;
	 	p_index = strstr(str,substr);
	 	if(p_index == NULL) return -1;
	 	return (strlen(str)-strlen(p_index));
 	}
 	return -1;
 }
	
 char * str_sub(char * str, int start_index, int end_index){
    if(str == NULL) return NULL;

    if(start_index < 0) return NULL;

    if(end_index >= strlen(str)) return NULL;

    if( start_index > end_index) return NULL;

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
    if(str2 == NULL && str1 == NULL) return NULL;

 	if(str1 == NULL && str2 != NULL) {
        len = strlen(str2);
 		comb = (char *)malloc(len + 1);
 		memcpy(comb,str2,len);
        comb[len]='\0';
 	}else if(str2 == NULL && str1 != NULL){
        len = strlen(str1);
 		comb = (char *)malloc(len + 1);
 		strcpy(comb,str1);
 	}else {
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
                // free(new_string);
            }
            s_index = str_index(str_input + start_index,spliter);   
        }

        if(str_input + start_index != NULL){
            char *last_string;
            last_string = str_sub(str_input, start_index, strlen(str_input)-1);
            array_string[index_of_string] = last_string;
            // free(last_string);
        }
        array_string[index_of_string+1]=NULL;
        return array_string;
     }
    return NULL;
    
 }

int * str_get_indexes(char *str, char* str1){
    if(str ==  NULL || str1 == NULL) return NULL;

    int str1_index = str_index(str,str1);
    if(str1_index == -1) return NULL;

    int *indexes;
    indexes = (int*)malloc((strlen(str)+1)*sizeof(int));

    int start_index = 0;
    int current_index = 0;
    while(str1_index != -1){
        indexes[current_index] = start_index + str1_index;
        start_index = start_index + str1_index + strlen(str1);
        str1_index = str_index(str + start_index,str1);
        current_index++;
    }

    indexes[current_index]=-1;

    int *res;
    res = (int*)malloc((current_index + 1)*sizeof(int));
    int i = 0;
    for(i = 0;i <current_index + 1;i++){
        res[i]=indexes[i];
    }
    free(indexes);
    return res;
}


 char * str_replace(char * str, char * str1, char * rep){

    if(str == NULL) return NULL;

    if(str1 == NULL || rep == NULL) {
        return str_copy(str);
    }

    int * array_index = str_get_indexes(str,str1);

    if(array_index == NULL) {
        return str_copy(str);
    }
    int current_index = 0;

    int nb_element =0;
    while(array_index[nb_element] != -1){
        nb_element++;
    }

    int new_string_len = strlen(str) + nb_element * strlen(rep) - nb_element * strlen(str1)+1;
    char * new_string;
    new_string = (char * )malloc(new_string_len);
    new_string[0] = '\0';

    if(array_index[current_index] != 0){
        char * str_substr = str_sub(str,0,array_index[current_index]-1);
        strcpy(new_string,str_substr);
        free(str_substr);
    }

    while(array_index[current_index + 1] != -1){

        char * str_substr = str_sub(str,array_index[current_index] + strlen(str1),array_index[current_index + 1] -1);
        
        if(strlen(new_string)==0){
            strcpy(new_string,rep);
        }else{
            strcat(new_string,rep);
        }
        strcat(new_string,str_substr);
        free(str_substr);
        current_index ++;
    }

    // The spliter is at the end of string
    if(strlen(str) >= array_index[current_index] + strlen(str1)){
        char * str_substr = str_sub(str,array_index[current_index] + strlen(str1),strlen(str) -1);
        strcat(new_string,rep);    
        if(str_substr != NULL){
            strcat(new_string,str_substr);
            free(str_substr);
        }
    }

    new_string[new_string_len-1] = '\0';

    free(array_index);
    
    return new_string;

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

char ** str_add_string_to_array(char **array,char *str){
  
  if(str == NULL) return array;

  if(array == NULL){
    char **ret = (char** )malloc(C_EASY_STR_MAX_ARRAY_SIZE);
    ret[0] = str_copy(str);
    ret[1] = NULL;
    return ret;
  }

  int i=0;
  while(array[i] != NULL){
    i++;
  }
  array[i] = str_copy(str);
  array[i+1] = NULL;
  return array;
}

char * str_copy(char *str2){
    
    char *str1 = NULL;
    
    if(str2 != NULL){
        int length = strlen(str2);

        str1 = malloc(length + 1);

        memcpy(str1,str2,length);

        str1[length] = '\0';
    }
    
    return str1;
}

void str_print_array(char **array){
    int i=0;
    while(array[i] != NULL){
        printf("Array[%d]: %s\n",i,array[i]);
        i++;
    }
}


// char * cmd_run_command(char *cmd){
//     if(cmd==NULL){
//         return NULL;
//     }else{
//         FILE *pp;
//         char *output;
//         output=(char*)malloc(255*sizeof(char));
//         pp = popen(cmd, "r");
//         if (pp != NULL) {
//             char *line = NULL;
//             while (1) {
//                 char buf[255];
//                 line = fgets(buf, sizeof(buf), pp);
//                 if (line != NULL) {
//                     if(output==NULL){
//                         output=line;
//                     }else{
//                         int len = strlen(output)+strlen(line)+1; 
//                         output=realloc(output,len);
//                         strcat(output,line);
//                         output[len]='\0';
//                     }
//                 }else{
//                     // End of output
//                     break;
//                 }
//             }
//             if(line != NULL) free(line);
//         }
//         pclose(pp);
//         return output;
//     }
//     return NULL;
// }