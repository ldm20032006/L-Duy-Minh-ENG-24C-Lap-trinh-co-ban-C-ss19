#include <stdio.h>
#include<string.h>

struct sinhVien {
    int id;
    char name[100];
    int age;
    char phoneNumber[100];
};
typedef struct sinhVien sinhVien;
void sapXep(sinhVien *user, int soSinhVien){
    for(int i = 0; i < soSinhVien - 1; i++){
        for(int j = 0; j < soSinhVien - 1 - i; j++){
            if(strcmp(user[j].name, user[j + 1].name) > 0) {
                sinhVien temp = user[j];
                user[j] = user[j + 1];
                user[j + 1] = temp;
            }
        }
    }
    printf("da sap xep ten sinh vien A -> Z\n");
}
int main(){
    sinhVien user[100]={
            {1, "Minh", 18, "0987654321"},
            {2, "Bang", 20, "0987654321"},
            {3, "Bach", 21, "0987654321"},
            {4, "Thuong", 22, "0987654321"},
            {5, "Tuan", 23, "0987654321"}
    };
    sapXep(user, 5);
    printf("danh sach sinh vien khi da sap xep la\n");
    for(int i = 0; i < 5; i++){
        printf("id: %d | Ten: %s | Tuoi: %d | Sdt: %s\n", user[i].id, user[i].name, user[i].age, user[i].phoneNumber);
    }
    return 0;
}
