#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "product.h"

int createProduct(Product*p)
{
	fgetc(stdin);
	printf("제품의 이름은? ");
	fgets(p->name,100,stdin);
	p->name[strlen(p->name)-1]='\0';
	printf("제품의 무게는(그램)? ");
	scanf("%d",&p->weight);
	printf("제품의 가격은? ");
	scanf("%d",&p->price);
	printf("제품의 별점은? ");
	scanf("%d",&p->star);
	printf("리뷰의 개수는? ");
	scanf("%d",&p->numstar);
	return 1;
}

int readProduct(Product p)
{
	printf("%10s     %5d   %7d  %3d %6d\n",p.name,p.weight,p.price,p.star,p.numstar);
	return 0;
}

int updateProduct(Product *p)
{

	fgetc(stdin);
	printf("제품의 이름은? ");
	fgets(p->name,100,stdin);
	p->name[strlen(p->name)-1]='\0';
	printf("제품의 무게는(그램)? ");
	scanf("%d",&p->weight);
	printf("제품의 가격은? ");
	scanf("%d",&p->price);
	printf("제품의 별점은? ");
	scanf("%d",&p->star);
	printf("별점의 개수는? ");
	scanf("%d",&p->numstar);
	printf("==> 수정성공!!\n");
	return 1;
}

void deleteProduct(Product *p)
{
	p->price=0;
}

