#include<iostream>
#include<string>
#include<vector>
#include <io.h>
#include<fcntl.h>
using namespace std;
class SinhVien {
    private:
        wstring ma_so;
        wstring ho_ten;
        wstring ngay_sinh;
        wstring gioi_tinh;
        wstring khoa;
        wstring khoa_hoc;
        wstring chuong_trinh;
        wstring dia_chi;
        wstring email;
        wstring so_dien_thoai;
        wstring tinh_trang;
    
    public:
        SinhVien()
        {
            wcout << L"Nhập mã số sinh viên: ";
            wcin >> ma_so;
            cin.ignore();
            wcout << L"Nhập họ tên: ";
            getline(wcin >> ws, ho_ten);
            wcout << L"Nhập ngày sinh: ";
            getline(wcin >> ws, ngay_sinh);
            wcout << L"Nhập giới tính: ";
            getline(wcin >> ws, gioi_tinh);
            wcout << L"Nhập khoa: ";
            getline(wcin >> ws, khoa);
            wcout << L"Nhập khóa: ";
            getline(wcin >> ws, khoa_hoc);
            wcout << L"Nhập chương trình: ";
            getline(wcin >> ws, chuong_trinh);
            wcout << L"Nhập địa chỉ: ";
            getline(wcin >> ws, dia_chi);
            wcout << L"Nhập email: ";
            getline(wcin >> ws, email);
            wcout << L"Nhập số điện thoại liên hệ: ";
            getline(wcin >> ws, so_dien_thoai);
            wcout << L"Nhập tình trạng sinh viên: ";
            getline(wcin >> ws, tinh_trang);

        }
        SinhVien(wstring ma_so, wstring ho_ten, wstring ngay_sinh, wstring gioi_tinh, wstring khoa, 
                 wstring khoa_hoc, wstring chuong_trinh, wstring dia_chi, wstring email, 
                 wstring so_dien_thoai, wstring tinh_trang) {
            this->ma_so = ma_so;
            this->ho_ten = ho_ten;
            this->ngay_sinh = ngay_sinh;
            this->gioi_tinh = gioi_tinh;
            this->khoa = khoa;
            this->khoa_hoc = khoa_hoc;
            this->chuong_trinh = chuong_trinh;
            this->dia_chi = dia_chi;
            this->email = email;
            this->so_dien_thoai = so_dien_thoai;
            this->tinh_trang = tinh_trang;
        }
        wstring getMSSV()
        {
            return this -> ma_so;
        }
    };
    
class LopHoc
{
    vector<SinhVien> dsSinhVien;
    void themSinhVien()
    {
        SinhVien a;
        this -> dsSinhVien.push_back(a);
    }
    void xoaSinhVien()
    {
        wstring mssv;
        wcout << L"MSSV cần xóa: ";
        getline(wcin >> ws, mssv);
        for(int i = 0; i < dsSinhVien.size(); i++)
        {
            if (mssv == dsSinhVien[i].getMSSV())
            {
                dsSinhVien.erase(dsSinhVien.begin() + i);
                break;
            }
        }
    }
};
int main()
{
    _setmode(_fileno(stdin), _O_U16TEXT);
    _setmode(_fileno(stdout), _O_U16TEXT);
    return 0;

}