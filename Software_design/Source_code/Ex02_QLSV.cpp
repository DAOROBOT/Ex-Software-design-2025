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
        wstring getHoTen()
        {
            return this -> ho_ten;
        }
        wstring getNgaySinh()
        {
            return this -> ngay_sinh;
        }
        wstring getGioiTinh()
        {
            return this -> gioi_tinh;
        }
        wstring getKhoa()
        {
            return this -> khoa;
        }
        wstring getKhoaHoc()
        {
            return this -> khoa_hoc;
        }
        wstring getChuongTrinh()
        {
            return this -> chuong_trinh;
        }
        wstring getDiaChi()
        {
            return this -> dia_chi;
        }
        wstring getEmail()
        {
            return this -> email;
        }
        wstring getSDT()
        {
            return this -> so_dien_thoai;
        }
        wstring getTinhTrang()
        {
            return this -> tinh_trang;
        }


        void set_ho_ten(wstring ho_ten_update)
        {
            this -> ho_ten = ho_ten_update;
        }
        void set_ngay_sinh(wstring ngay_sinh_update)
        {
            this -> ngay_sinh = ngay_sinh_update;
        }
        void set_gioi_tinh(wstring gioi_tinh_update)
        {
            this -> gioi_tinh = gioi_tinh_update;
        }
        void set_khoa(wstring khoa_update)
        {
            this -> khoa = khoa_update;
        }
        void set_khoa_hoc(wstring khoa_hoc_update)
        {
            this -> khoa_hoc = khoa_hoc_update;
        }
        void set_chuong_trinh(wstring chuong_trinh_update)
        {
            this -> chuong_trinh = chuong_trinh_update;
        }
        void set_dia_chi(wstring dia_chi_update)
        {
            this -> dia_chi = dia_chi_update;
        }
        void set_email(wstring email_update)
        {
            this -> email = email_update;
        }
        void set_so_dien_thoai(wstring so_dien_thoai_update)
        {
            this -> so_dien_thoai = so_dien_thoai_update;
        }
        void set_tinh_trang(wstring tinh_trang_update)
        {
            this -> tinh_trang = tinh_trang_update;
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
    void CapNhatSinhVien()
    {
        wstring mssv;
        wstring ho_ten_update;
        wstring ngay_sinh_update;
        wstring gioi_tinh_update;
        wstring khoa_update;
        wstring khoa_hoc_update;
        wstring chuong_trinh_update;
        wstring dia_chi_update;
        wstring email_update;
        wstring so_dien_thoai_update;
        wstring tinh_trang_update;
        wcout << L"MSSV cần cập nhật: ";
        getline(wcin >> ws, mssv);
        for(int i = 0; i < dsSinhVien.size(); i++)
        {
            if (mssv == dsSinhVien[i].getMSSV())
            {
                wcout << L"Nhập họ tên: ";
                getline(wcin >> ws, ho_ten_update);
                wcout << L"Nhập ngày sinh: ";
                getline(wcin >> ws, ngay_sinh_update);
                wcout << L"Nhập giới tính: ";
                getline(wcin >> ws, gioi_tinh_update);
                wcout << L"Nhập khoa: ";
                getline(wcin >> ws, khoa_update);
                wcout << L"Nhập khóa: ";
                getline(wcin >> ws, khoa_hoc_update);
                wcout << L"Nhập chương trình: ";
                getline(wcin >> ws, chuong_trinh_update);
                wcout << L"Nhập địa chỉ: ";
                getline(wcin >> ws, dia_chi_update);
                wcout << L"Nhập email: ";
                getline(wcin >> ws, email_update);
                wcout << L"Nhập số điện thoại liên hệ: ";
                getline(wcin >> ws, so_dien_thoai_update);
                wcout << L"Nhập tình trạng sinh viên: ";
                getline(wcin >> ws, tinh_trang_update);
                
                dsSinhVien[i].set_ho_ten(ho_ten_update);
                dsSinhVien[i].set_ngay_sinh(ngay_sinh_update);
                dsSinhVien[i].set_gioi_tinh(gioi_tinh_update);
                dsSinhVien[i].set_khoa(khoa_update);
                dsSinhVien[i].set_khoa_hoc(khoa_hoc_update);
                dsSinhVien[i].set_chuong_trinh(chuong_trinh_update);
                dsSinhVien[i].set_dia_chi(dia_chi_update);
                dsSinhVien[i].set_email(email_update);
                dsSinhVien[i].set_so_dien_thoai(so_dien_thoai_update);
                dsSinhVien[i].set_tinh_trang(tinh_trang_update);
            }

        }
    }
    void TimKiemSinhVien_HoTen(wstring ho_ten_input)
    {
        for(int i = 0; i < dsSinhVien.size(); i++)
        {
            if(dsSinhVien[i].getHoTen() == ho_ten_input)
            {
                wcout << L"Mã số sinh viên: " << dsSinhVien[i].getMSSV() << endl;
                wcout << L"Họ tên: " << dsSinhVien[i].getHoTen() << endl;
                wcout << L"Ngày sinh: " << dsSinhVien[i].getNgaySinh() << endl;
                wcout << L"Giới tính: " << dsSinhVien[i].getGioiTinh() << endl;
                wcout << L"Khoa: " << dsSinhVien[i].getKhoa() << endl;
                wcout << L"Khóa học: " << dsSinhVien[i].getKhoaHoc() << endl;
                wcout << L"Chương trình: " << dsSinhVien[i].getChuongTrinh() << endl;
                wcout << L"Địa chỉ: " << dsSinhVien[i].getDiaChi() << endl;
                wcout << L"Email: " << dsSinhVien[i].getEmail() << endl;
                wcout << L"Số điện thoại: " << dsSinhVien[i].getSDT() << endl;
                wcout << L"Tình trạng: " << dsSinhVien[i].getTinhTrang() << endl;
            }
        }
    }
    void TimKiemSinhVien_MSSV(wstring MSSV_input)
    {
        for(int i = 0; i < dsSinhVien.size(); i++)
        {
            if(dsSinhVien[i].getMSSV() == MSSV_input)
            {
                wcout << L"Mã số sinh viên: " << dsSinhVien[i].getMSSV() << endl;
                wcout << L"Họ tên: " << dsSinhVien[i].getHoTen() << endl;
                wcout << L"Ngày sinh: " << dsSinhVien[i].getNgaySinh() << endl;
                wcout << L"Giới tính: " << dsSinhVien[i].getGioiTinh() << endl;
                wcout << L"Khoa: " << dsSinhVien[i].getKhoa() << endl;
                wcout << L"Khóa học: " << dsSinhVien[i].getKhoaHoc() << endl;
                wcout << L"Chương trình: " << dsSinhVien[i].getChuongTrinh() << endl;
                wcout << L"Địa chỉ: " << dsSinhVien[i].getDiaChi() << endl;
                wcout << L"Email: " << dsSinhVien[i].getEmail() << endl;
                wcout << L"Số điện thoại: " << dsSinhVien[i].getSDT() << endl;
                wcout << L"Tình trạng: " << dsSinhVien[i].getTinhTrang() << endl;
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