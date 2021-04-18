#include <stdio.h>
#include <stdlib.h>
#include "product.h"
#include "manager.h"

int main()
{

#ifdef DEBUG
	printf("===> DEBUGMODE\n");
#endif
	int menu;
	int count=0;
	Product *p[100];
	int index=0;
	readFile(p,&count);
	index = count;
	while(1)
	{

		printf("입력하실 메뉴는?\n");
		printf("1. 제품 등록\n");
		printf("2. 제품 출력\n");
		printf("3. 제품 수정\n");
		printf("4. 제품 삭제\n");
		printf("5. 제품 검색\n");
		printf("6. 파일 저장\n");
		printf("0. 종료\n");
		scanf("%d",&menu);
		if(menu==0)
		{
			printf("종료되었습니다!\n");
			break;
		}
		if(menu == 2 || menu == 3 || menu == 4)
      			if(count==0) continue;
		if(menu==1)
		{
			p[index] = (Product *)malloc(sizeof(Product));
			count += createProduct(p[index++]);
		}
		if(menu==2)
		{	if(count>0)
				listProduct(p,index);
			else
				printf("데이터가 없습니다!\n");
		}
		if(menu==3)
		{
			int no = selectProductno(p,index);
			if(no==0){
				printf("취소됨!");
				continue;
			}

			updateProduct(p[no-1]);		
		}
		if(menu==4)
		{
			int no = selectProductno(p,index);
			int yn;
			printf("정말로 삭제하시겠습니까?(1:예 0:아니요) " );
			scanf("%d",&yn);
			if(yn==1)
			{
				if(p[no-1]) free(p[no-1]);
				p[no-1]=NULL;
				printf("삭제되었습니다!\n");
			}
			else if(yn==0)
				printf("취소되었습니다!\n");
		}
		if(menu==5)
		{
			int num;
			printf("제품 검색 방법은? (1:무게 2:가격 3:리뷰개수) > ");
			scanf("%d",&num);
			if(num==1)
				searchProductWeight(p,index);
			if(num==2)
				searchProductPrice(p,index);
			if(num==3)
				searchProductnumstar(p,index);
		}
		if(menu==6)
		{
			saveFile(p,index);
		}


	}	
	return 0;
}
