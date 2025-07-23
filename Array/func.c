#include <stdio.h>

/*
 * Ham member
 * ----------
 * Yeu cau:
 *   - Kiem tra xem phan tu x co ton tai trong danh sach L hay khong.
 *   - Neu co x trong danh sach L, tra ve 1.
 *   - Neu khong co, tra ve 0.
 *
 * Tham so:
 *   x: gia tri can tim (kieu int)
 *   L: danh sach (kieu List, duoc dinh nghia o noi khac)
 *
 * Logic cua ham:
 *   - Duyet tuan tu tat ca phan tu trong danh sach L.
 *   - So sanh tung phan tu L.Elements[i] voi x.
 *   - Neu tim thay phan tu bang x, tra ve 1 ngay lap tuc.
 *   - Neu duyet het ma khong thay, tra ve 0.
 */

int member(int x, List L) {
    int i;
    for (i = 0; i < L.Last; i++) {
        // So sanh phan tu thu i voi x
        if (L.Elements[i] == x) {
            return 1; // Tim thay x
        }
    }
    return 0; // Khong tim thay x
}


// Ham: removeAll
// Muc dich: Xoa tat ca cac phan tu co gia tri x trong danh sach
// Tham so:
//   x - gia tri can xoa
//   pL - con tro den danh sach
// Logic:
//   1. Tim vi tri dau tien cua phan tu co gia tri x
//   2. Neu tim thay (i >= 0) thi xoa phan tu tai vi tri i
//   3. Goi ham locate de tim tiep vi tri cua x (dang con loi logic vi chi goi ma khong xoa tiep)

void removeAll(int x, List* pL) {
    // Tim vi tri dau tien cua x trong danh sach
    int i = locate(x, *pL);
    if(i >= 0) {
        // Neu tim thay thi xoa phan tu tai vi tri i
        deleteList(i, pL);
        // Goi locate de tim tiep (hien tai chi goi chu khong lap nen chi xoa duoc 1 phan tu)
        locate(i, *pL);
    }
}



// Ham: unionSet
// Muc dich: Tinh tap hop hop cua hai tap hop bieu dien boi hai danh sach L1 va L2
//            Ket qua duoc luu vao danh sach ma con tro pL chi den
// Tham so:
//   L1, L2 - hai danh sach dau vao bieu dien hai tap hop
//   pL - con tro den danh sach ket qua
// Logic:
//   1. Khoi tao danh sach ket qua rong
//   2. Dua tat ca cac phan tu cua L1 vao danh sach ket qua
//   3. Duyet tung phan tu cua L2:
//        - Neu chua co trong danh sach ket qua thi them vao
// Gia su:
//   - Da co san cac ham ho tro:
//       void makenullList(List*);
//       void insertSet(ElementType, List*);
//       int member(ElementType, List);

void unionSet(List L1, List L2, List* pL) {
    // Buoc 1: khoi tao danh sach ket qua rong
    makenullList(pL);

    // Buoc 2: dua tat ca phan tu cua L1 vao danh sach ket qua
    for(int i=0; i<L1.Last; i++) {
        insertSet(L1.Elements[i], pL);
    }

    // Buoc 3: duyet tung phan tu cua L2, neu chua co trong ket qua thi them vao
    for(int i=0; i<L2.Last; i++) {
        if(!member(L2.Elements[i], *pL)) {
            insertSet(L2.Elements[i], pL);
        }
    }
}


// Ham xoa phan tu tai vi tri p trong danh sach
// Ten ham: deleteList
// Tham so:
//   - p: vi tri can xoa (kieu so nguyen, danh so tu 1)
//   - pL: con tro den danh sach kieu List
// Dieu kien: neu p khong hop le thi thong bao loi
// Neu hop le thi xoa phan tu tai vi tri do va cap nhat lai danh sach

void deleteList(int p, List *pL)
{
    // Kiem tra vi tri xoa co nam trong pham vi danh sach hay khong
    if(p < 1 || p > pL->Last)
        printf("Vi tri khong hop le \n");
    else 
    {
        // Duyet tu vi tri can xoa (p-1 vi danh sach dung chi so 0)
        // Dich cac phan tu sau len mot vi tri
        for(int i = p - 1; i < pL->Last ; i++)
        {
            pL->Elements[i] = pL->Elements[i + 1];
        }
        // Giam so luong phan tu trong danh sach sau khi xoa
        pL->Last--;
    }
}



// Ham readSet dung de nhap mot tap hop tu ban phim
// Su dung cac ham da cho: makenullList, member, insertSet

void readSet(List* pL) {
    // Khoi tao danh sach rong
    makenullList(pL);

    int i, n;
    // Nhap so luong phan tu cua tap hop
    scanf("%d", &n);

    // Lap n lan de nhap phan tu
    for(i = 0; i < n; i++) {
        // Nhap phan tu vao vi tri i cua mang
        scanf("%d", &pL->Elements[i]);

        // Neu phan tu chua co trong tap hop thi them vao
        if(!member(pL->Elements[i], *pL)) {
            insertSet(pL->Elements[i], pL);
        }
    }
}


// Ham: intersection
// Muc dich: Tinh tap hop giao cua hai tap hop bieu dien boi hai danh sach L1 va L2
//            Ket qua duoc luu vao danh sach ma con tro pL chi den
// Tham so:
//   L1, L2 - hai danh sach dau vao bieu dien hai tap hop
//   pL - con tro den danh sach ket qua
// Logic:
//   1. Khoi tao danh sach ket qua rong
//   2. Duyet tung phan tu cua L1
//       - Neu phan tu do co trong L2 thi them vao danh sach ket qua
// Gia su:
//   - Da co san cac ham ho tro:
//       void makenullList(List*);
//       void insertSet(ElementType, List*);
//       int member(ElementType, List);

void intersection(List L1, List L2, List *pL)
{
    // Buoc 1: khoi tao danh sach ket qua rong
    makenullList(pL);

    // Buoc 2: duyet tung phan tu cua L1
    for (int i = 0; i < L1.Last; i++)
    {
        // Neu phan tu do co trong L2 thi them vao danh sach ket qua
        if (member(L1.Elements[i], L2))
            insertSet(L1.Elements[i], pL);
    }
}


// Ham: copyEvenNumbers
// Muc dich: Sao chep cac so chan tu danh sach L1 sang danh sach L2
// Tham so:
//   L1 - danh sach dau vao
//   L2 - con tro den danh sach ket qua
// Logic:
//   1. Khoi tao danh sach L2 rong
//   2. Duyet tung phan tu cua L1
//       - Neu phan tu do la so chan thi chen vao cuoi danh sach L2
// Gia su:
//   - Da co san cac ham ho tro:
//       void makenullList(List*);
//       void insertList(ElementType, int, List*);

void copyEvenNumbers(List L1, List *L2)
{
    // Buoc 1: khoi tao danh sach L2 rong
    makenullList(L2);

    // Buoc 2: duyet tung phan tu cua L1
    for(int i = 0; i < L1.Last; i++)
    {
        // Neu phan tu la so chan thi chen vao cuoi L2
        if(L1.Elements[i] % 2 == 0)
            insertList(L1.Elements[i], L2->Last + 1, L2);
    }
}


// Ham: erase
// Muc dich: Xoa phan tu dau tien co gia tri x trong danh sach
// Tham so:
//   x - gia tri can xoa
//   pL - con tro den danh sach
// Logic:
//   1. Tim vi tri dau tien cua x trong danh sach bang ham locate
//   2. Goi ham deleteList de xoa phan tu tai vi tri do
// Gia su:
//   - Da co san cac ham ho tro:
//       int locate(ElementType, List);
//       void deleteList(int, List*);

void erase(int x, List *pL)
{
    // Tim vi tri dau tien cua x va xoa tai vi tri do
    deleteList(locate(x, *pL), pL);
}



// Ham: locate
// Muc dich: Tim vi tri cua phan tu dau tien co gia tri x trong danh sach L
// Tham so:
//   x - gia tri can tim
//   L - danh sach can tim
// Tra ve:
//   Chi so (index) cua phan tu x (bat dau tu 1) neu tim thay
//   Neu khong tim thay thi tra ve L.Last + 1 (tuc la vi tri ngoai danh sach)
// Logic:
//   1. Duyet tung phan tu cua danh sach
//   2. Neu tim thay x thi tra ve vi tri (i+1)
//   3. Neu duyet het ma khong tim thay thi tra ve L.Last+1

int locate(int x, List L)
{
    int p = 0;
    for(int i = 0; i < L.Last; i++)
    {
        if(L.Elements[i] == x)
            return p = i + 1;  // tra ve vi tri tim thay
    }
    return p = L.Last + 1;    // khong tim thay
}


// Ham: printOddNumbers
// Muc dich: In ra cac phan tu le trong danh sach L
// Tham so:
//   L - danh sach dau vao
// Logic:
//   1. Duyet tung phan tu cua L
//   2. Neu phan tu do la so le thi in ra

void printOddNumbers(List L)
{
    for (int i = 0; i < L.Last; i++)
    {
        // Neu phan tu le thi in ra
        if (L.Elements[i] % 2 != 0)
            printf("%d ", L.Elements[i]);
    }
}


// Ham: sort
// Muc dich: Sap xep danh sach tang dan
// Tham so:
//   pL - con tro den danh sach
// Logic:
//   Su dung thuat toan sap xep noi bot (bubble sort)
//   1. Duyet tung phan tu tu trai sang
//   2. So sanh voi cac phan tu dung sau no
//   3. Neu lon hon thi hoan doi vi tri
//   Lap den het danh sach

void sort(List *pL)
{   
    int s;
    for(int i = 0; i < pL->Last; i++)
    {
        for(int z = i + 1; z < pL->Last; z++)
        {
            // Neu phan tu thu i > phan tu thu z thi doi cho
            if(pL->Elements[i] > pL->Elements[z])
            {
                s = pL->Elements[z];
                pL->Elements[z] = pL->Elements[i];
                pL->Elements[i] = s;
            }
        }
    }
}


// Ham: locate1
// Muc dich: Tim vi tri xuat hien cuoi cung cua phan tu x trong danh sach L
// Tham so:
//   x - gia tri can tim
//   L - danh sach can tim
// Tra ve:
//   Vi tri (index bat dau tu 1) cua x neu tim thay
//   Neu khong tim thay thi tra ve L.Last + 1
// Logic:
//   Duyet danh sach tu dau den cuoi
//   Luu lai vi tri moi nhat tim thay x
//   Ket thuc vong lap, neu co thi tra ve vi tri do, neu khong thi tra ve L.Last+1

int locate1(int x, List L)
{
    int pos = L.Last + 1; // mac dinh la khong tim thay

    for (int i = 0; i < L.Last; i++)
    {
        if (L.Elements[i] == x)
        {
            pos = i + 1; // cap nhat vi tri moi nhat tim thay
        }
    }

    return pos;
}



// Ham: printList
// Muc dich: In ra toan bo danh sach L tren mot dong
// Tham so:
//   L - danh sach can in
// Logic:
//   1. Duyet tung phan tu cua danh sach
//   2. In tung phan tu cach nhau boi dau cach
//   3. Ket thuc in xuong dong moi

void printList(List L) {
	for(int i = 0; i < L.Last; i++) {
		printf("%d ", L.Elements[i]);
	}
	printf("\n");
}



// Ham: makenullList
// Muc dich: Khoi tao (hoac lam rong) danh sach
// Tham so:
//   pL - con tro den danh sach
// Logic:
//   Gan gia tri Last = 0 de danh sach tro thanh rong

void makenullList(List *pL)
{
    pL->Last = 0;
}


