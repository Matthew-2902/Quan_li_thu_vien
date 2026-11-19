// Đầu sách(DSTT):(Dau_Sach)(Danh sách đầu sách luôn tăng dần theo tên sách)
// {danh sách tuyến tính là 1 mảng con trỏ}
//------------------ Thuộc Tính -----------------//
// - String,ISBN,Ten_Sach,Tac_Gia,The_Loai;
// - int So_Trang,Nam_Xuat_Ban;
// - Danh_Muc_Sach dms;(đối tuọng danh mục sách)
// - int soluong,soluongmuon;
//--------------------Hành vi--------------------//
// - Nhập thông tin đầu sách 
// - In danh sách các đầu sách trong thư viện theo từng thể loại, trong từng thể loại thì in theo thứ tự tên sách tăng dần.(duyệt tuyến tính dựa vào mã sách để phân loại nhanh để in ra)
// - Tìm thông tin sách dựa vào tên sách : in ra các thông tin mã ISBN, tên sách, tác giả, năm xuất bản, thể loại, các mã sách , trạng thái mã sách trong thư viện.(tìm kiếm dựa vào bảng chữ cái tương đương cách viết tắt)
// - In 10 sách có số lượt mượn nhiều nhất.
// - 
// - Danh_Muc_Sach tạo mã sách dựa vào Ten_Sach So_Trang Nam_Xuat_Ban sach thu may trong soluong và tăng soluong khi nhap sach loai đó.
//-----------------------------------------------//


const int MAX_DAUSACH=10000;
struct Nodell
{
    string data;
    Nodell* next;
    Nodell(string val):data(val)
    {
        next=nullptr;
    }
}
struct setll{
    Nodell*head=nullptr;
    void push(string val)
    {
        if(head == nullptr)
        {
            head = new Node(val);
            return ;
        }
        Nodell* current = head;
        while(current!=nullptr)
        {
            if(current->data==val)
            {return;}
            if(current->next == nullptr)
            {break;}
            current=current->next;
        }
        current->next=new Nodell(val);
    }
    string pop()
    {
        if(head==nullptr)
        {return"";}
        string val=head->data;
        Nodell*temp=head;
        head=head->next;
        delete temp;
        return val;
    }
};
struct Dau_Sach
{
    string ISBN,Ten_Sach,Tac_Gia,The_Loai;
    int So_Trang,Nam_Xuat_Ban;
    int soluongmuon=0;
    Danh_Muc_Sach *head=nullptr;
    Dau_Sach(string ISBN,string Ten_Sach,string Tac_Gia,
             string The_Loai, int So_Trang,int Nam_Xuat_Ban):
             ISBN(ISBN),Ten_Sach(Ten_Sach),Tac_Gia(Tac_Gia),
             The_Loai(The_Loai),So_Trang(So_Trang),Nam_Xuat_Ban(Nam_Xuat_Ban)
             {}
    void in()
    {
        cout << "ISBN: " << ISBN << " | "
     << "Ten sach: " << Ten_Sach << " | "
     << "Tac gia: " << Tac_Gia << " | "
     << "The loai: " << The_Loai << " | "
     << "So trang: " << So_Trang << " | "
     << "Nam XB: " << Nam_Xuat_Ban << endl;
    }
             
};

struct Danh_Sach_Dau_Sach
{
    Dau_Sach* node[MAX_DAUSACH];
    int n=0;
    setll theloai;
    void push(string ISBN,string Ten_Sach,string Tac_Gia,
             string The_Loai, int So_Trang,int Nam_Xuat_Ban)
             {
                theloai.push(The_Loai);
                node[n++]=new Dau_Sach(ISBN,Ten_Sach,Tac_Gia,The_Loai,So_Trang,Nam_Xuat_Ban);
             }
    void sort()
    {
        int k=0;
        for(int i=0;i<n;i++)
        {
            k=i;
            for(int j=i;j<n;j++)
            {
                if(node[k]->Ten_Sach>node[j]->Ten_Sach) k=j;
            }

            Dau_Sach* temp=node[k];
            node[k]=node[i];
            node[i]=temp;
        }
    }
    void inds()
    {
        // cout<<the loai;
        for(Nodell* p=theloai.head;p!=nullptr;p=p->next)
        {
        for(int i=0;i<n;i++)
        {
            if(node[i]->The_Loai==p->data)
            {
                node[i]->in();
            }
        }
        }
    }
    void find(string Ten_Sach)
    {
        int begin=0,end=n-1;
        bool found=false;
        while(begin<=end)
        {
            int giua=(begin+end)/2;
            if(node[giua]->Ten_Sach==Ten_Sach)
            {
                node[giua]->in();
                for(int i = 1; i <= 25; i++)
                {
                    if(giua - i >= 0 && node[giua - i]->Ten_Sach == Ten_Sach)
                        node[giua - i]->in();

                    if(giua + i < n && node[giua + i]->Ten_Sach == Ten_Sach)
                        node[giua + i]->in();

                    if(giua - i < 0 && giua + i >= n)
                        break;
                }
                found=true;
                break;
            }
            else if(node[giua]->Ten_Sach>Ten_Sach)
            {
                end=giua-1;
            }
            else
            {
                begin=giua+1;
            }
        }
        if(!found)
        {
            cout<<"khong timt hay cuon sach nao co ten: "<<Ten_Sach<<endl;
        }
    }

};

// Danh Mục Sách(DSLKD):(Danh_Muc_Sach)
//------------------ Thuộc Tính -----------------//
// - string Ma_Sach(lưu dưới dạng set ko cho trùng)// dùng lại cấu trúng setll
// - Enum TrangThai(0: cho mượn được, 1: đã có độc giả mượn, 2: sách đã thanh lý)
// - String Vi_Tri;)
// - Danh_Muc_Sach *Node;
//--------------------Hành vi--------------------//
// đánh mã sách tự động sao cho tìm thông tin sách theo mã sách nhanh nhất.( mã sách đc đánh theo viết tắt sách, thể loại, ... / có thể thêm thông tin để tìm kiếm viết 1 cái struct nx để sinh mã sách/ mã tuân thủ sắp xếp từ A-Z)
// - Thêm 
// - Xóa. bất kỳ đâu.
//-----------------------------------------------//

enum TrangThai(CHO_MUON_DUOC,DA_CO_DOC_GIA_MUON,SACH_DA_THANH_LY);

struct nodedms
{
    string Ma_Sach;
    TrangThai trangthai;
    string vitri;
    nodedms* next;
    nodedms(string Ma_Sach,TrangThai tt,string vitri):Ma_Sach(Ma_Sach),trangthai(tt),vitri(vitri),next(nullptr){}
};

struct Danh_Muc_Sach{
    nodedms*head=nullptr;
    ~Danh_Muc_Sach(){nodedms*p=head; 
        if(head==nullptr) return;
        while(true)
    {
        nodedms* del=p;
        p=p->next;
        delete del;
        if(p==nullptr) break;
    }
    }
    nodedms* find(string Ma_Sach)
    {
        for(nodedms* p;p!=nullptr;p=p->next)
        if(Ma_Sach==p->Ma_Sach) return p;
        return nullptr;
    }
    void push(string Ma_Sach,TrangThai tt,string vitri)
    {
        if(head==nullptr)
        {
            head=new nodedms(Ma_Sach,tt,vitri);
        }
        if(find(Ma_Sach)== nullptr) return;
        nodedms*p=new nodedms(Ma_Sach,tt,vitri);
        p->next=head;
        head=p;
    }
    void change_trangthai(nodedms *ndms,TrangThai tt)
    {
        ndms->trangthai=tt;
    } 
    void change_vitri(nodedms* ndms,string vitri)
    {
        ndms->vitri=vitri;
    }
};

// Danh sách thẻ độc giả(BST):
//------------------ Thuộc Tính -----------------//
// - long long Ma_The;(thuật toán sinh cho cân bằng 2 nhánh cây.)
// - String Ho,Ten,enum Gioi_Tinh(Nam,Nu),enum Trang_Thai_The(trạng thái thẻ = 0 khi thẻ bị khóa, trạng thái thẻ = 1 khi thẻ  đang hoạt động (được quyền mượn sách))
// - DSLKD * Node;


// - BST * left;
// - BST * right;


//--------------------Hành vi--------------------//
// - Thêm 
// - Xóa
// - Hiệu Chỉnh
// - In danh sách độc giả : in ra màn hình theo thứ tự tên+họ tăng dần hoặc theo thứ tự mã độc giả tăng dần theo yêu cầu của thủ thư.
// - Mượn sách : nhập vào mã thẻ độc giả, chương trình sẽ liệt kê các sách mà độc giả đang mượn. 
//   Mỗi độc giả chỉ được mượn tối đa 3 cuốn, không cho mượn khi giữ 1 sách quá hạn (7 ngày)
// - Trả sách 
// - Liệt kê danh sách các mã sách, tên sách mà 1 độc giả có số thẻ X đang mượn
//-----------------------------------------------//



// Danh sách mượn trả(DSLKD):
//------------------ Thuộc Tính -----------------//
// - string Ma_Sach
// - String Ngay_Muon,Ngay_Tra;(struct)
// - enum Trang_Thai(trạng thái =0 là sách đang mượn (chưa trả), =1 là đã trả, =2 : làm mất sách )
// - DsLKD *Node;


//--------------------Hành vi--------------------//
// - Thêm
// - Xóa
//-----------------------------------------------//







#include<iostream>
using namespace std;

int main()
{


}