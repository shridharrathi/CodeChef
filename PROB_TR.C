#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct btree{
int Age;
int Reporting;
int Reportee;
char Shift;
struct btree * rn, * ln;
};
typedef struct btree node;

node * searchNode(int reporting, node * tree)
{
	if(tree)
	{
		if(tree->Reportee == reporting)
		{
			return tree;
		}
		searchNode(reporting,tree->rn);
		searchNode(reporting,tree->ln);
	}

}

int check(node *root, node *subTree)
{
	if(root && subTree)
	{
		if(root->Age == subTree->Age)
		{
		    if( check(root->ln, subTree->ln))
			if(check(root->rn, subTree->rn))
				return 1;
		}
		else
		{
			return 0;
		}
	}
	else if((root==NULL && subTree!=NULL) || (root!=NULL && subTree==NULL))
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

void createNode(node *root, int reporting, int reportee, char shift, int age)
{
	node * temp;
	node *ptr = searchNode(reporting, root);
	if(root == NULL)
	{
		printf("\nFailed to initialise the tree\n");
		return;
	}


	temp = (node *)malloc(sizeof(node));
	temp ->rn = temp->ln = NULL;
	temp ->Age = age;
	temp ->Reporting = reporting;
	temp ->Reportee = reportee;
	temp ->Shift = shift;

	if(ptr->Reportee == reporting)
	{
		if(shift == 'E' && ptr->rn == NULL)
		{
			ptr->rn = temp;
		}
		else if(shift == 'M' && ptr->ln == NULL)
		{
			ptr->ln = temp;
		}
	}
}

void printTree(node *tree)
{
	if(tree)
	{
		printf("%d, %c, %d\n",tree->Reportee, tree->Shift, tree->Age);
		printTree(tree->ln);
		printTree(tree->rn);
	}
}

int checkTree(node *tree , node * subTree)
{
	if(!tree || !subTree)
	{
		return 0;
	}

	if(check(tree, subTree))
	{
	      return 1;
	}
	else
	{    if(checkTree(tree->ln,subTree))
		return 1;

	     if(checkTree(tree->rn,subTree))
		return 1;
	}

	return 0;
}

node * createTree()
{
	int n, counter, age;
	node *root;
	int *arr;
	int reporting, reportee;
	char shift;

	printf("\nPlease enter the number of chef: ");
	scanf("%d", &n );

	arr = (int * ) malloc( n * sizeof(int ));
	for (counter =0; counter < n; counter++)
	{
		printf("\nPlease enter the age: ");
		scanf("%d", &arr[counter]);
	}

	root = (node *)malloc(sizeof(node));
	root ->rn = root -> ln = NULL;
	root ->Age = arr[0];
	root ->Reportee = 1;
	root ->Shift = NULL;

	for (counter =0; counter<n-1; counter++)
	{
	     printf("\nPlease enter the Reporting, Reportee and Shift(M/E): ");
	     scanf("%d %d %c",&reporting, &reportee, &shift);
	     createNode(root, reporting, reportee, shift, arr[reportee-1]);

	}
	return root;
}

int main(																																																																																								){
	node * mainTree, * subTree;
	node ** array;

	int spec, counter;

	mainTree = createTree();

	printf("\nEnter the number of new specs: ");
	scanf("%d",&spec);
	array = (node ** ) malloc( spec * sizeof(node *));

	for(counter = 0; counter <spec; counter++)
	{
		subTree = createTree();
		array[counter] = subTree;
	}

	printf("\nThis is the main Tree\n");
	printTree(mainTree);

	printf("\nThese are the Sub-Trees \n");
	for(counter = 0; counter <spec; counter++)
	{
	  printf("\nSubTree %d : \n", counter+1);
	  printTree(array[counter]);
	  if(checkTree(mainTree->ln, array[counter]))
	  {
		printf("\nYes\n");
	  }
	  else if(checkTree(mainTree->rn, array[counter]))
	  {
		printf("\nYes\n");
	  }
	  else
	  {
		printf("\nNo\n");
	  }

	}

}