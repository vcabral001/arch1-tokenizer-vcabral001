#ifndef _TOKENIZER_
#define _TOKENIZER_
#include "tokenizer.h"
#include <stdio.h>
#include <stdlib.h>


/* Return true (non-zero) if c is a whitespace characer
   ('\t' or ' ').  
   Zero terminators are not printable (therefore false) */
int space_char(char c){
   while(c != EOF){
      if(c == 0){
         return FALSE;
      }
      else if(c == '\t'  || ' ')
         return TRUE;
   }
}

/* Return true (non-zero) if c is a non-whitespace 
   character (not tab or space).  
   Zero terminators are not printable (therefore false) */ 
int non_space_char(char c){
   while(c != EOF){
      if(c==0){
         return FALSE;
      }
      else if(c != '\t' || ' ' || '\n')
         return TRUE;
   }
}

/* Returns a pointer to the first character of the next 
   space-separated word in zero-terminated str.  Return a zero pointer if 
   str does not contain any words. */
char word_start(char *str){
   while(*str){
      if(non_space_char(*str)){
         return *str;      
      }
      str++;
   }
   return 0;
} 

/* Returns a pointer terminator char following *word */
char *word_terminator(char *word){
   while(*word){
      if(space_char(*word)){
         return word;
      }
      word++;
   }
   return 0;
}

#define OUT 0
#define IN 1
/* Counts the number of words in the string argument. */
int count_words(char *str){
   int state = OUT
      int wc = 0; //Word Count
   
   //Now scan all characters
   while(*str){
      //If next character is a separator, set the state as OUT
      If(*str == ' ' || *str == '\n' || *str == '\t')
         state = OUT;
      else if(state == OUT){
         state = IN;
         ++wc;
      }
      //Move to next character 
      ++str;
   }
   return wc;
}

/* Returns a fresly allocated new zero-terminated string 
   containing <len> chars from <inStr> */
char *copy_str(char *inStr, short len){
   char *outSTR = malloc(len + 1);   //Creates a new string of length len and contains len chars from the string then returns it
   for(int i = 0; i < len; i++){
      outStr[i] = *&inStr[i];
   }
   outStr[len] = '\0';
   return outStr;
}

/* Returns a freshly allocated zero-terminated vector of freshly allocated 
   space-separated tokens from zero-terminated str.

   For example, tokenize("hello world string") would result in:
     tokens[0] = "hello"
     tokens[1] = "world"
     tokens[2] = "string" 
     tokens[3] = 0
*/
char **tokenize(char* str){
   int size = count_words(str);
   char **t = malloc(size + 1);
   char *tmp;
   for(int i = 0; i < size; i++){
      tmp = word_terminator(str);
      printf("tmp: %s\n", tmp);
      printf("%u: %u\n", (void*)&tmp, (void*)&str;
      t[i] = copy_str(str, (void*)&tmp - (void*)&str);
   }
   return t;
}

/* Prints all tokens. */
void print_tokens(char **tokens);

/* Frees all tokens and the vector containing themx. */
void free_tokens(char **tokens);

#endif
