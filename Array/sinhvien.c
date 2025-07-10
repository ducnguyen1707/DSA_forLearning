#include <stdio.h>

// Nguoi ta can quan ly diem thi mon Cau truc du lieu cua cac sinh vien trong lop (toi da 40 sinh vien)
// bang mot danh sach dac. Moi sinh vien (cau truc SinhVien) la mot phan tu trong danh sach dac co cac thong tin:
// - Ma so sinh vien (chuoi 10 ky tu)
// - Ho va ten (chuoi 50 ky tu)
// - Diem thi ly thuyet (float)
// - Diem thi thuc hanh 1 (float)
// - Diem thi thuc hanh 2 (float)

struct SinhVien{
   char MSSV[10];
   char HoTen[50];
   float DiemLT, DiemTB1, DiemTB2;
};

// Khi bieu dien bang danh sach dac DanhSach, nguoi ta dung mot cau truc co 2 truong:
// - Mang A chua cac sinh vien
// - So phan tu trong danh sach: n
typedef struct {
	struct SinhVien A[100];
	int n;
}DanhSach;


void makenullList (DanhSach *pL) {
	pL->n = 0; // n la so cuoi cung, tuong trung cho do dai cua List
}
int emptyList (DanhSach L) { // dung de check do dai list
	return L.n ==0; // neu true thi se return ve 0
}

// Ham tim vi tri sinh vien co ma so x trong danh sach L
// Neu tim thay tra ve vi tri tinh tu 1
// Neu khong tim thay tra ve L.n + 1
int tim(char x[10], DanhSach L) {
	int i, j ,temp;
	for(i=L.n-1 ;i>=0;i--) {  //khi ngta nhap la bat dau tu 1 chu ko phai 0 nen phai -1
		temp =1;
		for(j=0;j<=10;j++) {
			if(x[j] != L.A[i].MSSV[j]) { // so sanh ky tu thu j cua chuoi x voi ky tu thu j cua MSSV cua sinh vien thu i trong danh sach
				temp =0;
				break;
			}
			if (x[j] == '\0' && L.A[i].MSSV[j] == '\0') break; // cuoi char cua C la \0
		}
		
		if(temp) {
				return i+1;
		}
	}
	return L.n +1;
}

//Logic:
// neu vi tri laf 1 bien int thi ok, neu la chuoi input thi nhot nho vao bien
//c
void xoaSinhVien(char x[10], DanhSach *pL) {
	int temp = tim(x, *pL); // dat temp nhu 1 bien 
	if(temp <1 || temp > pL->n) {
		printf("Vi tri khong hop le");
	}else if(emptyList(*pL)) {
		printf("Danh sach rong!");
	}else {
		xoaTai(temp, pL);
		}
	}
}

// Ham xoa phan tu tai vi tri p trong danh sach dac
void xoaTai(int p, DanhSach *pL) {
    int i;
    // Dich cac phan tu tu vi tri p+1 ve truoc 1 vi tri
    for(i = p - 1; i < pL->n - 1; i++) {
        pL->A[i] = pL->A[i + 1];
    }
    // Giam so luong phan tu cua danh sach di 1
    pL->n--;
}

