int listProduct(Product *p[],int count); // 제품 리스트 출력 (R)
void searchProductWeight(Product *p[],int count); // 제품 찾기 (무게)
void searchProductPrice(Product *p[],int count); // 제품 찾기 (가격)
void searchProductnumstar(Product *p[],int count); // 제품 찾기 (별점개수)
int selectProductno(Product *p[],int count); // 수정할 제품 번호 선택
void saveFile(Product *p[], int count); // 파일저장하기
void readFile(Product *p[], int *count); // 파일 불러오기 
