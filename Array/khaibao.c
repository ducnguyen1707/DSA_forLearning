#include <stdio.h>

// Mot diem trong khong gian 2 chieu duoc mo ta la mot cau truc gom 2 truong x, y kieu so nguyen int.
//
// Mot da giac duoc cau thanh tu nhieu diem, chang han da giac ben duoi duoc cau thanh tu 6 diem:
// A(xA, yA), B(xB, yB), C(xC, yC), D(xD, yD), E(xE, yE), G(xG, yG).
//
// Gia su nguoi ta bieu dien mot da giac bang mot danh sach dac co toi da la 100 diem.
//
// Hay viet khai bao cho kieu du lieu Polygon bieu dien cac da giac theo mo ta tren.

#define MaxL 100

typedef int Position;

typedef struct{
	int x;
	int y;
} Point ;

typedef struct  {
	Point p[MaxL];
	Position Last;
}Polygon;

typedef struct {
	DonThuc A[MaxL];
	Position so_luong;
}DaThuc;
