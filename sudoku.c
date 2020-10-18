#include <stdio.h>
#include <stdlib.h>
#include "list.h"


typedef struct
{
  int sudo[9][9];
}Node;

Node* createNode()
{
  Node* n=(Node*) malloc(sizeof(Node));
  return n;
}

Node* copy(Node* n)
{
  Node* new=(Node*) malloc(sizeof(Node));
  *new = *n;
  return new;
}

Node* read_file (char* file_name)
{
  Node* n = createNode();
  FILE* file = fopen (file_name, "r");
  int i,j;
  for(i=0;i<9;i++)
  {
    for(j=0;j<9;j++)
    {
      fscanf (file, "%d", &n->sudo[i][j]);
    }
  }

  fclose (file);
  return n;
}

void print_node(Node* n)
{
  int i,j;
  for(i=0;i<9;i++)
  {
    for(j=0;j<9;j++)
    {
      printf("%d ", n->sudo[i][j]);
      printf("\n");
    }
  }
  printf("\n");
}

int is_valid(Node* n)
{



  return 1;
}


List* get_adj_nodes(Node* n)
{
  int f;
  int g;
  int numero;
  List* list=createList();
  
  for( f=0 ; f<9 ;f++ )
  {
    for( g=0 ; g<9 ; g++ )
    {
      if(n->sudo[f][g]==0)
      {
        for( numero=1 ; numero<10 ; numero++)
        {
          while(numero<10)
          {
            n->sudo[f][g]=numero;
            if(is_valid(n))
            {
              Node* nuevo=copy(n);
              pushBack(list, nuevo);        
            }
            numero++;
          }
          n->sudo[f][g]=0;
        }
      }
    }
  }
  return list;
}


int is_final(Node* n)
{
  int f;
  int g;
  
  for( f=0 ; f<9 ;f++ )
  {
    while(g<9)
    {
      if(n->sudo[f][g] == 0)
      {
        return 0;
      }
      g++;
    }
  }
  return 1;
}

Node* DFS(Node* initial, int* cont)
{
 /* Stack *S = createStack;
  push(S,n);

  while (size(S != 0)
  {
    n = top(S);
    node * n= pop(S);
    if (n.finalS == true) return n;
  }

List * adj = get_adj_node(n);


  
  */
  return NULL;
}



/*
int main( int argc, char *argv[] ){

  Node* initial= read_file("s12a.txt");;

  int cont=0;
  Node* final = DFS(initial, &cont);
  printf("iterations:%d\n",cont);
  print_node(final);

  return 0;
}*/