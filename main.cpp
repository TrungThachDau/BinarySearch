
#include <iostream>
#include <fstream>
using namespace std;

struct PhanSo
{
    int tu,mau;
};
typedef PhanSo ItemType;
struct Node
{
    ItemType Data;
    Node* Left,*Right;
};
typedef Node* Tree;
Tree root;
void createTree(Tree& root)
{
    {
        root = NULL;
    }
}
Node* createNode(ItemType x)
{
    Node *p = new Node; //Xin cấp phát một TNode mới
    p->Data = x;
    p->Left = NULL;		//vì nút chưa liên kết với bất kỳ nút con trái nào khác
    p->Right = NULL;	//vì nút chưa liên kết với bất kỳ nút con phải nào khác
    return p;
}
int soSanhPhanSo(ItemType p1, ItemType p2)
{
    double gt = p1.tu*p2.mau - p1.mau*p2.tu;
    if (gt == 0)
        return 0;	//2 phân số bằng nhau
    else if (gt > 0)
        return 1;	//2 phân số 1 lớn hơn phân số 2
    else
        return -1;	//2 phân số 1 nhỏ hơn phân số 2
}
void addNode(Tree& root, ItemType x)
{
    Node*p= createNode(x);
    if (root != nullptr)
    {
        if (soSanhPhanSo(root->Data,p->Data)==0 )
            return;
        else if (soSanhPhanSo(root->Data,p->Data)>0)
            addNode(root->Left, x);
        else
            addNode(root->Right, x);
    }
    else
        root = p;
}
void createTreeFromFile(Tree& root, string filename)
{
    PhanSo a;
    ifstream f;
  f.open(filename);
   if (f.eof()) cout << "Không tìm thấy file";
   else
   {
     createTree(root);
      for (int i = 1; i <= 10; i++)
    {
          f >> a.tu;

           addNode(root, a);
       }
       for (int i = 1; i <= 10; i++)
       {
           f >> a.mau;
           addNode(root, a);
       }
    }
    f.close();
}
void showNode(Node*p)
{
    cout<<p->Data.tu<<"/"<<p->Data.mau<<" ";
}
void NLR(Tree root)
{
    if (root != nullptr)
    {
        showNode(root);
        NLR(root->Left);
        NLR(root->Right);
    }
}
Node* findNode(Tree root, ItemType x)
{
    if (root == nullptr) return nullptr;

    if (soSanhPhanSo(root->Data, x) > 0)
        findNode(root->Left, x);
    else if (soSanhPhanSo(root->Data, x) < 0)
        findNode(root->Right, x);
    else
        return root;

}
void findNodeReplace(Tree &root,Tree q)
{//Node q là node thế mạng
    if (q->Left != NULL)//duyệt bên trái nhất
        findNodeReplace(root, q->Left);//tìm node trái nhất
    else
    {
        root->Data = q->Data;//cập nhật data node cần xóa chính là node thế mạng
        root = q;//trỏ root đến node thế mạng
        q = q->Right;//cập nhật mối liên kết
    }
}
void deleteNode(Tree& root, ItemType x)
{
    if (root == NULL)
        return;
    else
    {
        if (soSanhPhanSo(root->Data,x) > 0)
            deleteNode(root->Left, x);
        else if (soSanhPhanSo(root->Data,x) < 0)
            deleteNode(root->Right, x);
        else
        {
            Node* p = root;
            if (root->Left == NULL)
                root = root->Right;
            else if (root->Right == NULL)
                root = root->Left;
            else
                findNodeReplace(root, p);
            delete p;
        }
    }
}
void maxNode(Tree root)
{
    Node* p = root;
    while (p->Right != NULL)
    {
        p = p->Right;
    }
    showNode(p);
}
void minNode(Tree root)
{
    Node* p = root;
    while (p->Left != NULL)
    {
        p = p->Left;
    }
    showNode(p);
}
void showNodeOfLevelK(Tree root, int k)
{
    if (root == NULL)
        return;
    else if (k == 0)
        showNode(root);
    else
    {
        k--;
        showNode(root);
        showNodeOfLevelK(root->Left, k);
        showNodeOfLevelK(root->Right, k);
    }
}
int countFactionLevelK(Tree root,int k)
{
    if (root)
    {
        k--;
        int a = countFactionLevelK(root->Left, k);
        int b = countFactionLevelK(root->Right, k);
        if (k == 0)
            return 1 + a + b;
        return a + b;
    }
    return 0;
}
void showNodeIsLeafOfLevelK(Tree root, int k)
{
    if (root == NULL)
        return;
    else
    {

        if (k == 0 && root->Left == NULL && root->Right == NULL)
            showNode(root);
        else
        {
            k--;
            showNode(root);
            showNodeIsLeafOfLevelK(root->Left, k);
            showNodeIsLeafOfLevelK(root->Right, k);
        }
    }
}
void NodeLeaf(Tree root)
{
    if (root != NULL)
    {
        if (root->Left == NULL && root->Right == NULL)
            showNode(root);
        NodeLeaf(root->Left);
        NodeLeaf(root->Right);
    }
}
void deleteTree(Tree& root)
{
    if (root == NULL) return;
    deleteTree(root->Left);
    deleteTree(root->Right);
    delete root;
}
//int maxDistance(Tree root, int x)
//{
//    if (root == NULL) return -1;
//    else
//    {
//        Node* minLeft = root;
//        while (minLeft->Left != NULL)
//            minLeft = minLeft->left;
//        Node* maxRight = root;
//        while (maxRight->Right != NULL)
//            maxRight = maxRight->Right;
//        int dis1 = abs(x - minLeft->Data);
//        int dis2 = abs(x - maxRight->Data);
//        if (dis1 > dis2)
//            return minLeft->Data;
//        else
//            return maxRight->Data;
//    }
//}
int timUCLN(int a, int b)
{
    a = abs(a);
    b = abs(b);
    if (a == 0 || b == 0) return 1;
    while (a != b)
    {
        if (a > b) a -= b;
        else b -= a;
    }
    return a; //Hoặc b
}
void rutGonPhanSo(ItemType &p)
{
    int ucln = timUCLN(p.tu, p.mau);
    p.tu/= ucln;
    p.mau /= ucln;
}
ItemType congPhanSo(ItemType p1, ItemType p2)
{
    ItemType kq = { 0, 1 };
    kq.tu = p1.tu*p2.mau + p1.mau*p2.tu;
    kq.mau = p1.mau*p2.mau;
    rutGonPhanSo(kq);
    return kq;
}
ItemType sumOfNode(Tree root)
{ //Dùng phép duyệt cây LRN
    if (!root) return{ 0, 1 }; //Trả về phân số 0/1
    ItemType sl = sumOfNode(root->Left);		//Tổng giá trị các nút trên cây con trái
    ItemType sr = sumOfNode(root->Right);	//Tổng giá trị các nút trên cây con phải
    return congPhanSo(root->Data, congPhanSo(sl, sr));	//Cộng thêm giá trị của nút gốc
}
//bool kiemTraSoHoanThien(int n)
//{
//    int sum = 0;
//    for (int i = 1; i <= n / 2; i++)
//    {
//        if (n % i == 0)
//            sum += i;
//    }
//    if (sum == n) return true;
//    return false;
//}
//void xuatSoHoanThien(Tree root)
//{
//    if (root != NULL)
//    {
//        if (kiemTraSoHoanThien(root->Data) == 1)
//            cout << root->data << " ";
//        xuatSoHoanThien(root->left);
//        xuatSoHoanThien(root->right);
//    }
//}
void xuatTangDan(Tree root)
{
    if (root != NULL)
    {
        xuatTangDan(root->Left);
        showNode(root);
        xuatTangDan(root->Right);
    }
}
void menu()
{
    //system("pause");
    //system("cls");
    cout << "\n1. Nhap cay tu file";
    cout << "\n2. Duyet NLR";
    cout << "\n3. Tim kiem nut";
    cout << "\n4. Xoa nut";
    cout << "\n5. Tim nut lon nhat va nho nhat";
    cout << "\n6. Xuat nut muc k";
    cout << "\7. Xuat nut la nut K";
    cout << "\n8. Xuat nut la";
    cout << "\n9. Tong cac nut";
    cout << "\n10.Xuat cac so hoan thien";
    cout << "\11. Xuat cac nut tang dan";
    cout << "\nChon chuc nang: ";
}
int main()
{
    Tree root;
    createTree(root);
    ItemType a[] = { {4,7},{12,5},{3,5},{14,18},{16,17} };
    int cn;
    do
    {
        menu();
        cin >> cn;
        switch (cn)
        {
            case 1:
            {
                int n = 5;
                createTree(root);
                for (int i = 0; i < n; i++)
                {
                    addNode(root, a[i]);
                    cout << "\n Sau khi them nut: ";
                    NLR(root);
                }
                break;
            }
            case 2:
            {
                NLR(root); break;
            }
            case 3:
            {
                PhanSo a;
                int x;
                cout << "Nhap nut de tim: ";
                cin >> a.tu>>a.mau;
                Node* p = findNode(root,a);
                if (p == NULL)
                    cout << "Khong tim thay nut";
                else
                    cout << "Tim thay nut!";
                break;
            }
            case 4:
            {
                PhanSo a;
                int x;
                cout << "Nhap nut can xoa: ";
                cin >> a.tu>>a.mau;
                deleteNode(root,a);
                NLR(root);
                break;
            }
            case 5:
            {
                cout << "MAX=";
                maxNode(root);
                cout << "\nMIN= ";
                minNode(root); break;
            }
            case 6:
            {
                int k;
                cout << "Nhap muc cua cay(NLR): ";
                cin >> k;
                showNodeOfLevelK(root, k); break;
            }
            case 7:
            {
                int k;
                cout << "Nhap muc cua cay(NLR): ";
                cin >> k;
                showNodeIsLeafOfLevelK(root, k); break;
            }
            case 8:
            {
                NodeLeaf(root);
            }
            case 9:
            {
                cout << "Tong la: " << sumOfNode(root).tu<<"/"<<sumOfNode(root).mau ;break;
            }
            case 10:
            {
//                cout << "\nCac so hoan thien la: ";
//                xuatSoHoanThien(root); break;
            }
            case 11:
            {
                xuatTangDan(root);
                break;
            }
            default:
                break;
        }
    } while (cn!=0);
}