typedef struct {
    char name[100];
    int weight;
    int price;
    int star;
    int numstar;
}Product;

int createProduct(Product *p); // 제품 만들기 (C)
int readProduct(Product p); // 제품 출력 (R)
int updateProduct(Product *p); // 제품 업데이트 (U)
void deleteProduct(Product *p); // 제품 삭제 (D)

