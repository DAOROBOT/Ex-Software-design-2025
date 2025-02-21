#include <iostream>
#include <string>
#include <vector>
#include <io.h>
#include <fcntl.h>
#include <fstream>
#include <sstream>

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
    SinhVien() {}
    
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

    // Getter methods (thêm const để tránh lỗi "discards qualifiers")
    wstring getMSSV() const { return ma_so; }
    wstring getHoTen() const { return ho_ten; }
    wstring getNgaySinh() const { return ngay_sinh; }
    wstring getGioiTinh() const { return gioi_tinh; }
    wstring getKhoa() const { return khoa; }
    wstring getKhoaHoc() const { return khoa_hoc; }
    wstring getChuongTrinh() const { return chuong_trinh; }
    wstring getDiaChi() const { return dia_chi; }
    wstring getEmail() const { return email; }
    wstring getSDT() const { return so_dien_thoai; }
    wstring getTinhTrang() const { return tinh_trang; }

    // Setter methods
    void set_ho_ten(wstring ho_ten) { this->ho_ten = ho_ten; }
    void set_ngay_sinh(wstring ngay_sinh) { this->ngay_sinh = ngay_sinh; }
    void set_gioi_tinh(wstring gioi_tinh) { this->gioi_tinh = gioi_tinh; }
    void set_khoa(wstring khoa) { this->khoa = khoa; }
    void set_khoa_hoc(wstring khoa_hoc) { this->khoa_hoc = khoa_hoc; }
    void set_chuong_trinh(wstring chuong_trinh) { this->chuong_trinh = chuong_trinh; }
    void set_dia_chi(wstring dia_chi) { this->dia_chi = dia_chi; }
    void set_email(wstring email) { this->email = email; }
    void set_so_dien_thoai(wstring so_dien_thoai) { this->so_dien_thoai = so_dien_thoai; }
    void set_tinh_trang(wstring tinh_trang) { this->tinh_trang = tinh_trang; }
};

class LopHoc {
private:
    vector<SinhVien> dsSinhVien;

    bool KiemTraEmail(wstring email) {
        return (email.find(L"@") != wstring::npos && email.find(L".") != wstring::npos);
    }

    bool KiemTraSDT(wstring sdt) {
        if (sdt.length() != 10 || sdt[0] != L'0') return false;
        for (int i = 0; i < sdt.length(); i++) {
            if (!iswdigit(sdt[i])) return false;
        }
        return true;
    }

    bool KiemTraKhoa(wstring khoa) {
        vector<wstring> dsKhoa = {L"Khoa Luật", L"Khoa Tiếng Anh thương mại", L"Khoa Tiếng Nhật", L"Khoa Tiếng Pháp"};
        for (const auto& k : dsKhoa) {
            if (khoa == k) return true;
        }
        return false;
    }

    bool KiemTraTinhTrang(wstring tinh_trang) {
        vector<wstring> dsTinhTrang = {L"Đang học", L"Đã tốt nghiệp", L"Đã thôi học", L"Tạm dừng học"};
        for (const auto& tt : dsTinhTrang) {
            if (tinh_trang == tt) return true;
        }
        return false;
    }

public:
    void themSinhVien() {
        wstring ma_so, ho_ten, ngay_sinh, gioi_tinh, khoa, khoa_hoc, chuong_trinh, dia_chi, email, so_dien_thoai, tinh_trang;

        wcout << L"Nhập mã số sinh viên: "; wcin >> ma_so; wcin.ignore();
        wcout << L"Nhập họ tên: "; getline(wcin, ho_ten);
        wcout << L"Nhập ngày sinh (dd/mm/yyyy): "; getline(wcin, ngay_sinh);
        wcout << L"Nhập giới tính: "; getline(wcin, gioi_tinh);
        do {
            wcout << L"Nhập khoa: "; getline(wcin, khoa);
            if (!KiemTraKhoa(khoa)) wcout << L"Khoa không hợp lệ! Nhập lại.\n";
        } while (!KiemTraKhoa(khoa));
        wcout << L"Nhập khóa: "; getline(wcin, khoa_hoc);
        wcout << L"Nhập chương trình: "; getline(wcin, chuong_trinh);
        wcout << L"Nhập địa chỉ: "; getline(wcin, dia_chi);
        do {
            wcout << L"Nhập email: "; getline(wcin, email);
            if (!KiemTraEmail(email)) wcout << L"Email không hợp lệ! Nhập lại.\n";
        } while (!KiemTraEmail(email));
        do {
            wcout << L"Nhập số điện thoại: "; getline(wcin, so_dien_thoai);
            if (!KiemTraSDT(so_dien_thoai)) wcout << L"Số điện thoại không hợp lệ! Nhập lại.\n";
        } while (!KiemTraSDT(so_dien_thoai));
        do {
            wcout << L"Nhập tình trạng: "; getline(wcin, tinh_trang);
            if (!KiemTraTinhTrang(tinh_trang)) wcout << L"Tình trạng không hợp lệ! Nhập lại.\n";
        } while (!KiemTraTinhTrang(tinh_trang));

        SinhVien sv(ma_so, ho_ten, ngay_sinh, gioi_tinh, khoa, khoa_hoc, chuong_trinh, dia_chi, email, so_dien_thoai, tinh_trang);
        dsSinhVien.push_back(sv);
        wcout << L"Đã thêm sinh viên thành công!\n";
    }

    void xoaSinhVien() {
        wstring mssv;
        wcout << L"Nhập MSSV cần xóa: "; getline(wcin >> ws, mssv);
        for (int i = 0; i < dsSinhVien.size(); i++) {
            if (mssv == dsSinhVien[i].getMSSV()) {
                dsSinhVien.erase(dsSinhVien.begin() + i);
                wcout << L"Đã xóa sinh viên!\n";
                return;
            }
        }
        wcout << L"Không tìm thấy sinh viên với MSSV này!\n";
    }

    void capNhatSinhVien() {
        wstring mssv;
        wcout << L"Nhập MSSV cần cập nhật: "; getline(wcin >> ws, mssv);
        for (int i = 0; i < dsSinhVien.size(); i++) {
            if (mssv == dsSinhVien[i].getMSSV()) {
                wstring ho_ten, ngay_sinh, gioi_tinh, khoa, khoa_hoc, chuong_trinh, dia_chi, email, so_dien_thoai, tinh_trang;
                wcout << L"Nhập họ tên: "; getline(wcin, ho_ten);
                wcout << L"Nhập ngày sinh (dd/mm/yyyy): "; getline(wcin, ngay_sinh);
                wcout << L"Nhập giới tính: "; getline(wcin, gioi_tinh);
                do {
                    wcout << L"Nhập khoa: "; getline(wcin, khoa);
                    if (!KiemTraKhoa(khoa)) wcout << L"Khoa không hợp lệ! Nhập lại.\n";
                } while (!KiemTraKhoa(khoa));
                wcout << L"Nhập khóa: "; getline(wcin, khoa_hoc);
                wcout << L"Nhập chương trình: "; getline(wcin, chuong_trinh);
                wcout << L"Nhập địa chỉ: "; getline(wcin, dia_chi);
                do {
                    wcout << L"Nhập email: "; getline(wcin, email);
                    if (!KiemTraEmail(email)) wcout << L"Email không hợp lệ! Nhập lại.\n";
                } while (!KiemTraEmail(email));
                do {
                    wcout << L"Nhập số điện thoại: "; getline(wcin, so_dien_thoai);
                    if (!KiemTraSDT(so_dien_thoai)) wcout << L"Số điện thoại không hợp lệ! Nhập lại.\n";
                } while (!KiemTraSDT(so_dien_thoai));
                do {
                    wcout << L"Nhập tình trạng: "; getline(wcin, tinh_trang);
                    if (!KiemTraTinhTrang(tinh_trang)) wcout << L"Tình trạng không hợp lệ! Nhập lại.\n";
                } while (!KiemTraTinhTrang(tinh_trang));

                dsSinhVien[i].set_ho_ten(ho_ten);
                dsSinhVien[i].set_ngay_sinh(ngay_sinh);
                dsSinhVien[i].set_gioi_tinh(gioi_tinh);
                dsSinhVien[i].set_khoa(khoa);
                dsSinhVien[i].set_khoa_hoc(khoa_hoc);
                dsSinhVien[i].set_chuong_trinh(chuong_trinh);
                dsSinhVien[i].set_dia_chi(dia_chi);
                dsSinhVien[i].set_email(email);
                dsSinhVien[i].set_so_dien_thoai(so_dien_thoai);
                dsSinhVien[i].set_tinh_trang(tinh_trang);
                wcout << L"Đã cập nhật sinh viên!\n";
                return;
            }
        }
        wcout << L"Không tìm thấy sinh viên với MSSV này!\n";
    }

    void timKiemSinhVien_HoTen(wstring ho_ten_input) {
        bool found = false;
        for (int i = 0; i < dsSinhVien.size(); i++) {
            if (dsSinhVien[i].getHoTen() == ho_ten_input) {
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
                wcout << L"Tình trạng: " << dsSinhVien[i].getTinhTrang() << endl << endl;
                found = true;
            }
        }
        if (!found) wcout << L"Không tìm thấy sinh viên với họ tên này!\n";
    }

    void timKiemSinhVien_MSSV(wstring mssv_input) {
        bool found = false;
        for (int i = 0; i < dsSinhVien.size(); i++) {
            if (dsSinhVien[i].getMSSV() == mssv_input) {
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
                found = true;
            }
        }
        if (!found) wcout << L"Không tìm thấy sinh viên với MSSV này!\n";
    }

    void docFile(wstring filePath) {
        wifstream file(filePath.c_str()); // Sử dụng .c_str() để chuyển wstring thành const wchar_t*
        if (!file.is_open()) {
            wcout << L"Không thể mở file để đọc!\n";
            return;
        }
        dsSinhVien.clear();
        wstring line;
        while (getline(file, line)) {
            wstringstream ss(line);
            wstring ma_so, ho_ten, ngay_sinh, gioi_tinh, khoa, khoa_hoc, chuong_trinh, dia_chi, email, so_dien_thoai, tinh_trang;
            getline(ss, ma_so, L',');
            getline(ss, ho_ten, L',');
            getline(ss, ngay_sinh, L',');
            getline(ss, gioi_tinh, L',');
            getline(ss, khoa, L',');
            getline(ss, khoa_hoc, L',');
            getline(ss, chuong_trinh, L',');
            getline(ss, dia_chi, L',');
            getline(ss, email, L',');
            getline(ss, so_dien_thoai, L',');
            getline(ss, tinh_trang, L',');
            SinhVien sv(ma_so, ho_ten, ngay_sinh, gioi_tinh, khoa, khoa_hoc, chuong_trinh, dia_chi, email, so_dien_thoai, tinh_trang);
            dsSinhVien.push_back(sv);
        }
        file.close();
        wcout << L"Đã đọc dữ liệu từ file!\n";
    }

    void ghiFile(wstring filePath) {
        wofstream file(filePath.c_str()); // Sử dụng .c_str() để chuyển wstring thành const wchar_t*
        if (!file.is_open()) {
            wcout << L"Không thể mở file để ghi!\n";
            return;
        }
        for (const SinhVien& sv : dsSinhVien) { // Không cần auto để tránh lỗi
            file << sv.getMSSV() << L"," << sv.getHoTen() << L"," << sv.getNgaySinh() << L","
                 << sv.getGioiTinh() << L"," << sv.getKhoa() << L"," << sv.getKhoaHoc() << L","
                 << sv.getChuongTrinh() << L"," << sv.getDiaChi() << L"," << sv.getEmail() << L","
                 << sv.getSDT() << L"," << sv.getTinhTrang() << L"\n";
        }
        file.close();
        wcout << L"Đã ghi dữ liệu vào file!\n";
    }
};

int main() {
    _setmode(_fileno(stdin), _O_U16TEXT);
    _setmode(_fileno(stdout), _O_U16TEXT);

    LopHoc lop;
    wstring filePath = L"sinhvien.txt"; // Đường dẫn file, bạn có thể thay đổi
    lop.docFile(filePath); // Đọc dữ liệu từ file khi khởi động

    int luaChon;
    while (true) {
        wcout << L"\n=== QUẢN LÝ SINH VIÊN ===\n";
        wcout << L"1. Thêm sinh viên mới\n";
        wcout << L"2. Xóa sinh viên\n";
        wcout << L"3. Cập nhật thông tin sinh viên\n";
        wcout << L"4. Tìm kiếm sinh viên theo họ tên\n";
        wcout << L"5. Tìm kiếm sinh viên theo MSSV\n";
        wcout << L"6. Ghi dữ liệu vào file\n";
        wcout << L"0. Thoát\n";
        wcout << L"Nhập lựa chọn: "; wcin >> luaChon; wcin.ignore();

        if (luaChon == 0) break;
        switch (luaChon) {
            case 1: lop.themSinhVien(); break;
            case 2: lop.xoaSinhVien(); break;
            case 3: lop.capNhatSinhVien(); break;
            case 4: {
                wstring ho_ten;
                wcout << L"Nhập họ tên cần tìm: "; getline(wcin, ho_ten);
                lop.timKiemSinhVien_HoTen(ho_ten);
                break;
            }
            case 5: {
                wstring mssv;
                wcout << L"Nhập MSSV cần tìm: "; getline(wcin, mssv);
                lop.timKiemSinhVien_MSSV(mssv);
                break;
            }
            case 6: lop.ghiFile(filePath); break;
            default: wcout << L"Lựa chọn không hợp lệ!\n";
        }
    }
    return 0;
}