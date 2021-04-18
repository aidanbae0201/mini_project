#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "product.h"
#include "manager.h"

int listProduct(Product *p[],int count){
	printf("번호   제품이름      무게   가격   별점  리뷰개수\n");
	for(int i=0;i<count;i++){
		if(p[i]==NULL) continue;
		printf("%2d   ",i+1);
		readProduct(*p[i]);
	}
	printf("\n");
	return 0;
}

void searchProductWeight(Product *p[],int count){
	float weight;
	int sc=0;
	printf("원하는 제품의 무게를 입력하시오> ");
	scanf("%f",&weight);
	printf("번호   제품이름      무게   가격   별점  리뷰개수\n");
	for(int i=0;i<count;i++){
		if(p[i]==NULL) continue;
		if(p[i]->weight == weight){
			printf("%2d   ",i+1);
			readProduct(*p[i]);
			sc++;
		}
	}
	printf("%d개의 제품이 검색되었습니다.\n",sc);
}
	

	
void searchProductPrice(Product *p[],int count){
	int price;
	int sc=0;
	printf("원하는 제품의 가격을 입력하시오> ");
	scanf("%d",&price);
	printf("번호   제품이름      무게   가격   별점  리뷰개수\n");
	for(int i=0;i<count;i++){
		if(p[i]==NULL) continue;
		if(p[i]->price == price){
			printf("%2d   ",i+1);
			readProduct(*p[i]);
			sc++;
		}
	}
	printf("%d개의 제품이 검색되었습니다.\n",sc);
}
void searchProductnumstar(Product *p[],int count){
	int numstar;
	int sc=0;
	printf("원하는 제품의 리뷰개수를 입력하시오> ");
	scanf("%d",&numstar);
	printf("번호   제품이름      무게   가격   별점  리뷰개수\n");
	for(int i=0;i<count;i++){
		if(p[i]==NULL) continue;
		if(p[i]->numstar == numstar){
			printf("%2d   ",i+1);
			readProduct(*p[i]);
			sc++;
		}
	}
	printf("%d개의 제품이 검색되었습니다.\n",sc);
}
int selectProductno(Product *p[],int count){
	int no;
	listProduct(p,count);
	printf("번호는? > ");
	scanf("%d",&no);
	return no;
}
void readFile(Product *p[], int *count){
	FILE *fp;
	int n=0;
	fp = fopen("product.txt","rt");
	if(fp==NULL)
		printf("==>파일없음!\n");
	else
	{
		while(!feof(fp))
		{
			p[n] = (Product*)malloc(sizeof(Product));
			int result = fscanf(fp,"%s %d %d %d %d",p[n]->name, &p[n]->weight, &p[n]->price, &p[n]->star, &p[n]->numstar);
		      	if(result<1) break;
			n++;
		}
		*count=n;
		printf("===> 로딩성공! \n");
	}
}
void saveFile(Product *p[],int count){
	FILE *fp;
	fp = fopen("product.txt","wt");
	for(int i=0;i<count;i++){
		if(p[i]==NULL) continue;
		fprintf(fp,"%s %d %d %d %d\n",p[i]->name, p[i]->weight,p[i]->price, p[i]->star,p[i]->numstar);
	}
	fclose(fp);
	printf("===> 저장됨!\n");
}
