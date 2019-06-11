#include <iostream>
#include <stdlib.h>
using namespace std;

struct USER
{
    string nama,username,password,bagian;
    USER *next;
    USER *prev;
};

struct MATKUL
{
    string mata_kuliah, sks, semester;
    MATKUL *next;
    MATKUL *prev;
};

struct MAHASISWA
{
    string nama_mhs, jurusan, npm;
    MAHASISWA *next;
    MAHASISWA *prev;
};

//user
void user(USER *head, USER *tail,string nama,string username,string password,string bagian);
void trace_user(USER *head,USER *tail,USER *temp,string username,string password);
void halaman_login(USER *head, USER *tail,string username,string password);
void cetak_user(USER *head);
void admin(USER *head,USER *tail,USER *temp);
void hapus(USER *head,USER *tail,string username);

//mata kuliah
void input_matkul(MATKUL *head_matkul,MATKUL *tail_matkul,string mata_kuliah,string sks,string semester);

//mahasiswa
void input_mhs(MAHASISWA *head_mhs,MAHASISWA *tail_mhs,string nama_mhs,string npm,string jurusan);

int main()
{
    string username,password,bagian;
    USER head, tail;
    MAHASISWA head_mhs,tail_mhs;
    MATKUL head_matkul, tail_matkul;

    head.next = NULL;
    head.prev = NULL;
    tail.next = NULL;
    tail.prev = NULL;

    head_mhs.next = NULL;
    head_mhs.prev = NULL;
    tail_mhs.next = NULL;
    tail_mhs.prev = NULL;

    head_matkul.next = NULL;
    head_matkul.prev = NULL;
    tail_matkul.next = NULL;
    tail_matkul.prev = NULL;

    user(&head,&tail,"irul","irule","123","admin" );
    user(&head,&tail,"ilham","hamham","321","admin" );
    user(&head,&tail,"huda","huda","huda","operator" );

    halaman_login(&head,&tail,username,password);
}

// user
void halaman_login(USER *head, USER *tail,string username,string password)
{
    USER *temp;
    cout << "=======================================" << endl;
    cout << "username   : "; cin >> username;
    cout << "password   : "; cin >> password;
    cout << "=======================================" << endl;
    trace_user(head,tail,temp,username,password);
}

void user(USER *head, USER *tail,string nama,string username,string password,string bagian)
{
    USER *baru;
    baru = new USER;
    baru->nama = nama;
    baru->username = username;
    baru->password = password;
    baru->bagian = bagian;
    if(head->next==NULL)
    {
        head->next=baru;
        baru->prev=head->prev;
    }
    else
    {
        baru->prev=tail->prev;
        tail->prev->next=baru;
    }
    tail->prev=baru;
    baru->next=tail->next;
}

void cetak_user(USER *head)
{
    USER *cetak;
    cetak = head->next;
    while(cetak != NULL)
    {
        cout << cetak->nama << endl;
        cout << cetak->username << endl;
        cout << cetak->password << endl;
        cout << cetak->bagian << endl;
        cetak = cetak->next;
    }
}

void trace_user(USER *head,USER *tail,USER *temp,string username,string password)
{
    string bagian;

    USER *kunku;
    kunku = head->next;
    while((username != kunku->username) && (password != kunku->password))
    {
        kunku = kunku->next;
        if (kunku == NULL)
        {
            cout << "login gagal" << endl;
            halaman_login(head,tail,username,password);
        }
    }
    if((username == kunku->username) && (password == kunku->password))
    {
        temp = kunku;
        cout << "login sukses" << endl;
        if (kunku->bagian == "admin")
        {
            admin(head,tail,temp);
        }
        else if (kunku->bagian == "operator")
        {
            cout << "operator" << endl;
        }
    }
}

void update_user(USER *head,USER *temp,string username,string password,string bagian)
{
    USER *kunku;
    kunku = head->next;
    while(kunku != temp)
    {
        kunku = kunku->next;
    }
    if (kunku == temp)
    {
        kunku->username = username;
        kunku->password = password;
        kunku->bagian = bagian;
    }
}

void hapus(USER *head,USER *tail,string username)
{
    USER *hapus;
    hapus = head->next;
    while(hapus->username != username){
        hapus = hapus->next;
    }
    if(hapus->prev==NULL){
        hapus->next->prev=head->prev;
        head->next=head->next->next;
    }
    else if(hapus->next==NULL){
        hapus->prev->next=tail->next;
        tail->prev=hapus->prev;
    }
    else{
        hapus->prev->next=hapus->next;
        hapus->next->prev=hapus->prev;
    }
}

// mata kuliah
void input_matkul(MATKUL *head_matkul,MATKUL *tail_matkul,string mata_kuliah,string sks,string semester)
{
    MATKUL *baru;
    baru = new MATKUL;
    baru->mata_kuliah = mata_kuliah;
    baru->sks = sks;
    baru->semester = semester;
    if(head_matkul->next == NULL)
    {
        baru->prev = head_matkul->next;
        baru->next = tail_matkul->prev;
        head_matkul->next = baru;
        tail_matkul->prev = baru;
    }
    else
    {
        tail_matkul->prev->next = baru;
        baru->prev = tail_matkul->prev;
        baru->next = tail_matkul->next;
        tail_matkul->prev = baru;
    }
}

void admin(USER *head,USER *tail,USER *temp)
{
 int pil;
 string username, password, bagian;
 MATKUL *head_matkul;MATKUL *tail_matkul;
 MAHASISWA *head_mhs;MAHASISWA *tail_mhs;
    a:
    cout<<"======MENU ADMIN======"<<endl;
    cout<<"1. USER"<<endl;
    cout<<"2. Matakuliah"<<endl;
    cout<<"3. Mahasiswa"<<endl;
    cout<<"4. view Matakuliah"<<endl;
    cout<<"5. view Mahasiswa"<<endl;
    cout<<"6. Logout"<<endl;
    cout<<"Pilih menu admin = "; cin>>pil;
    system("cls");
    switch(pil){

    case 1:
        int pilih;
        b:
        cout<<"=====MENU ADMIN->User======"<<endl;
        cout<<"1. Insert "<<endl;
        cout<<"2. Update "<<endl;
        cout<<"3. Delete "<<endl;
        cout<<"4. View "<<endl;
        cout<<"5. Kembali ke Menu Admin"<<endl;
        cout<<"Pilih menu user = "; cin>>pilih;
        switch(pilih){
        case 1:{
            char lagi;
            do{
            string nama,username,password,bagian;
            cout << "masukan nama user  : "; cin >> nama;
            cout << "masukan username   : "; cin >> username;
            cout << "masukan password   : "; cin >> password;
            cout << "masukan bagian     : "; cin >> bagian;
            user(head,tail,nama,username,password,bagian);
            cout << endl << "apakah anda mau mengisi data lagi? (y/n)   : ";cin >> lagi;
            }
            while(lagi=='y');
        goto b;
        break;
        }
        case 2:{
            cout << "masukan username baru  : "; cin >> username;
            cout << "masukan password baru  : "; cin >> password;
            cout << "masukan bagian baru    : "; cin >> bagian;
            update_user(head,temp,username,password,bagian);
        goto b;
        break;
        }
        case 3:{
            string username;
            cout<<"User Yang Akan Dihapus"<<endl;
            cout<<"Masukkan username user = "; cin>>username;
            hapus(head,tail,username);
        goto b;
        break;
        }
        case 4:{
            cetak_user(head);
        goto b;
        break;
        }
        case 5:
        system("cls");
        goto a;
        break;
        }
    goto a;
    break;
    case 2:
            char lagi;
            do{
            string mata_kuliah, sks, semester;
            cout << "=======MATA KULIAH=======" << endl;
            cout << "masukan nama mata kuliah   : "; cin >> mata_kuliah;
            cout << "masukan jumlah sks         : "; cin >> sks;
            cout << "masukan semester           : "; cin >> semester;
            input_matkul(head_matkul,tail_matkul,mata_kuliah,sks,semester);
            cout << endl << "apakah anda mau mengisi data lagi? (y/n)   : ";cin >> lagi;
            }
            while(lagi=='y');
    goto a;
    break;
    case 3:{
            char lagi;
            do{
            string nama_mhs,npm,jurusan;
            cout<<"====MAHASISWA===="<<endl;
            cout<<"Nama    : "; cin>>nama_mhs;
            cout<<"NPM     : "; cin>>npm;
            cout<<"Jurusan : "; cin>>jurusan;
            input_mhs(head_mhs,tail_mhs,nama_mhs,npm,jurusan);
            cout<<"Apakah anda mau mengisi data lagi ?(y/n) :"; cin>>lagi;
            }
            while(lagi=='y');
    goto a;
    break;
    }
    case 4:{
    //cetak_mat(&headmat);
    goto a;
    break;
    }
    case 5:{
    //cetak_mhs(&headmah);
    goto a;
    break;
    }
    default:
        cout<<"Yang dimasukkan tidak ada di menu"<<endl;
        goto a;
}
}

// input belakang
void input_mhs(MAHASISWA *head_mhs,MAHASISWA *tail_mhs,string nama_mhs,string npm,string jurusan)
{
    MAHASISWA *baru;
    baru = new MAHASISWA;
    baru->nama_mhs = nama_mhs;
    baru->npm = npm;
    baru->jurusan = jurusan;
    if(head_mhs->next == NULL)
    {
        head_mhs->next=baru;
        head_mhs->prev=head_mhs;
    }else {
        baru->prev=tail_mhs->prev;
        tail_mhs->prev->next=baru;
    }
    baru->next=tail_mhs->next;
    tail_mhs->prev=baru;
    cout<<"Data Berhasil di Tambahkan"<<endl;
    cout<<endl;

}

void cetak_mat(MATKUL *head)
{
    MATKUL *cetak_mat;
    cetak_mat = head->next;
    while(cetak_mat != NULL){
        cout<<cetak_mat->mata_kuliah<<endl;
        cout<<cetak_mat->sks<<endl;
        cout<<cetak_mat->semester<<endl;
        cetak_mat = cetak_mat->next;
    }
}

void cetak_mhs(MAHASISWA *head)
{
    MAHASISWA *cetak_mhs;
    cetak_mhs = head->next;
    while(cetak_mhs != NULL)
    {
        cout<<cetak_mhs->nama_mhs<<endl;
        cout<<cetak_mhs->npm<<endl;
        cout<<cetak_mhs->jurusan<<endl;
        cetak_mhs = cetak_mhs->next;
    }
}
