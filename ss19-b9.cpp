#include <stdio.h>
#include <string.h>

struct sinhVien {
    int id;
    char name[100];
    int age;
    char phoneNumber[100];
};
typedef struct sinhVien sinhVien;
void hienThiDanhSach(sinhVien user[],int soLuongSinhVien){
    for(int i = 0; i < soLuongSinhVien; i++){
        printf("id: %d | ten: %s | tuoi: %d | sdt: %s\n", user[i].id, user[i].name, user[i].age, user[i].phoneNumber);
    }
}
void thenSinhVien(sinhVien user[],int *soLuongSinhVien){
    int vtriThem;
    printf("nhap vi tri them sinh vien: ");
    scanf("%d", &vtriThem); 
    fflush(stdin);
    if(vtriThem < 0 || vtriThem >= *soLuongSinhVien){
        printf("vi tri them khong hop le");
        return;
    }
    for(int i = *soLuongSinhVien; i > vtriThem; i--){
        user[i] = user[i - 1];
    }
    (*soLuongSinhVien)++;
    
    user[vtriThem].id = *soLuongSinhVien;
    printf("nhap ten  cho sinh vien moi: ");
    fgets(user[vtriThem].name, sizeof(user[vtriThem].name), stdin);
    user[vtriThem].name[strlen(user[vtriThem].name) - 1] = '\0';
    fflush(stdin);
    printf("nhap tuoi  cho sinh vien moi: ");
    scanf("%d", &user[vtriThem].age);
    fflush(stdin);
    printf("nhap so dien thoai cho sinh vien moi: ");
    fgets(user[vtriThem].phoneNumber, sizeof(user[vtriThem].phoneNumber), stdin);
    user[vtriThem].phoneNumber[strlen(user[vtriThem].phoneNumber) - 1] = '\0';
    printf("da them sinh vien vao trong danh sach");
}
void suaThongTin(sinhVien user[], int soLuongSinhVien){
    int vtriSua;
    printf("nhap vi tri sinh vien can sua: ");
    scanf("%d", &vtriSua);
    fflush(stdin);
    if(vtriSua < 0 || vtriSua >= soLuongSinhVien){
        printf("vi tri nhap khong hop le");
        return;
    }

    printf("nhap ten sinh vien can sua: ");
    fgets(user[vtriSua].name, sizeof(user[vtriSua].name), stdin);
    user[vtriSua].name[strlen(user[vtriSua].name) - 1] = '\0';
    fflush(stdin);
    printf("nhap tuoi cua sinh vien can sua: ");
    scanf("%d", &user[vtriSua].age);
    fflush(stdin);
    printf("nhap so dien thoai sinh vien can sua: ");
    fgets(user[vtriSua].phoneNumber, sizeof(user[vtriSua].phoneNumber), stdin);
    user[vtriSua].phoneNumber[strlen(user[vtriSua].phoneNumber) - 1] = '\0';
    fflush(stdin);
    printf("da sua thong tin cua sinh vien");
}
void xoaSinhVien(sinhVien user[],int *soLuongSinhVien){
    int vtriXoa;
    printf("nhap vi tri xoa can xoa: ");
    scanf("%d", &vtriXoa);
    if(vtriXoa < 0 || vtriXoa >= *soLuongSinhVien){
        printf("vi tri xoa khong hop le");
        return;
    }
    for(int i = vtriXoa; i < *soLuongSinhVien; i++){
        user[i] = user[i + 1];
    }
    (*soLuongSinhVien)--;

    printf("da xoa sinh vien");
}
void timKiemSinhVien(sinhVien user[],int soLuongSinhVien){
    char tenTimKiem[100];
    int checkTimKiem = 0;
    printf("nhap ten sinh vien can tim kiem: ");
    fflush(stdin);
    fgets(tenTimKiem, sizeof(tenTimKiem), stdin);
    fflush(stdin);
    tenTimKiem[strlen(tenTimKiem) - 1] = '\0';
    for(int i = 0; i < soLuongSinhVien; i++){
        if(strcmp(user[i].name, tenTimKiem) == 0){
            printf("sinh vien can tim id la: %d\n", i + 1);
            checkTimKiem = 1;
        }
    }
    if(!checkTimKiem){
        printf("khong tim thay ten sinh vien");
    }
}
void sapXepSinhVien(sinhVien user[], int soLuongSinhVien){
    for(int i = 0; i < soLuongSinhVien - 1; i++){
        for(int j = 0; j < soLuongSinhVien - 1 - i; j++){
            if(strcmp(user[j].name, user[j + 1].name) > 0){
                struct sinhVien temp = user[j];
                user[j] = user[j + 1];
                user[j + 1] = temp;
            }
        }
    }
    printf("da sap xep sinh vien A -> Z");
}
int main(){
    sinhVien user[100]={
            {1, "Minh", 18, "0987654321"},
            {2, "Bang", 20, "0987654321"},
            {3, "Bach", 21, "0987654321"},
            {4, "Thuong", 22, "0987654321"},
            {5, "Tuan", 23, "0987654321"}
    };
    int soLuongSinhVien = 5;
    int luaChon;
    while(1){
        printf("\n1. Hien thi danh sach sinh vien\n");
        printf("2. Them sinh vien\n");
        printf("3. Sua thong tin sinh vien\n");
        printf("4. Xoa sinh vien\n");
        printf("5. Tim kiem sinh vien\n");
        printf("6. sap xep danh sach sinh vien\n");
        printf("7. Thoat\n");
        printf("Lua chon: ");
        scanf("%d", &luaChon);
        switch(luaChon){
            case 1: //Hien thi danh sach sinh vien
                hienThiDanhSach(user, soLuongSinhVien);
                break;
            case 2: //Them sinh vien
            	thenSinhVien(user, &soLuongSinhVien);
				break;
            case 3: //Sua thong tin sinh vien
                suaThongTin(user, soLuongSinhVien);
                break;
            case 4: //Xoa sinh vien
                xoaSinhVien(user, &soLuongSinhVien);
                break;
            case 5: //Tim kiem sinh vien
                timKiemSinhVien(user, soLuongSinhVien);
                break;
            case 6: // sap xep danh sach sinh vien
                sapXepSinhVien(user, soLuongSinhVien);
                break;
            case 7: //Thoat
                return 0;
            default:
                printf("nhap sai lua chon");
        }
    }
}
