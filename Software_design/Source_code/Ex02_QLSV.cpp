#include<iostream>
#include<string>
#include<fcntl.h>
#include<io.h>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
using namespace std;
class sinhVien
{
	private:
		wstring studentID;
		wstring name;
		wstring birthday;
		wstring gender;
		wstring faculty;
		wstring schoolYear;
		wstring program;
		wstring address;
		wstring email;
		wstring phoneNumber;
		wstring studentStatus;
		
	public:
		void noUserInputHandler(wstring& info)
		{
			while (info == L"")
			{
				wcout << L"\nBạn chưa nhập thông tin, xin hãy nhập thông tin tương ứng: ";
				wcin.ignore();
				getline(wcin, info);
			}
			
		}
		void validateUserInput(wstring& info, int mode)
		{
			while(mode == 1)
			{
				bool isNumber = true;
				for(int i = 0; i < info.length(); i++)
				{
					if(!isdigit(info[i]))
					{
						if(info[i] == '-')
							continue;
						
						isNumber = false;
						break;
					}
				}
				if(isNumber == false)
				{
					wcout << L"\nBạn nhập thông tin chưa chính xác, xin hãy nhập lại thông tin: ";
					wcin.ignore();
					getline(wcin, info);
					if(info == L"")
						noUserInputHandler(info);
				}
				else
					break;
			}
			
			
			while(mode == 0)
			{
				bool isOnlyLetter = true;
				for(int i = 0; i < info.length(); i++)
				{
					if(isdigit(info[i]))
					{
						isOnlyLetter = false;
						break;
					}
				}
				if(isOnlyLetter == false)
				{
					wcout << L"\nBạn nhập thông tin chưa chính xác, xin hãy nhập lại thông tin: ";
					wcin.ignore();
					getline(wcin, info);
					if(info == L"")
						noUserInputHandler(info);
				}
				else
					break;
			}
			
		}
		
		void inputBirthday(wstring& day, wstring& month, wstring& year)
		{
			while(1)
			{
				wcout << L"\nNhập ngày sinh: ";
				getline(wcin, day);
				noUserInputHandler(day); 
				validateUserInput(day, 1); 
				wcin.ignore();
				int day_int = stoi(day);
				while(day_int < 0 || day_int > 31)
				{
					wcout << L"\nBạn nhập ngày sinh không hợp lệ, xin hãy nhập lại ngày sinh: ";
					getline(wcin, day);
					if(day == L"")
						noUserInputHandler(day);
					
					validateUserInput(day, 1); 
					day_int = stoi(day);
					wcin.ignore();
				}
				
				wcout << L"\nNhập tháng sinh: ";
				getline(wcin, month);
				noUserInputHandler(month); 
				validateUserInput(month, 1); 
				wcin.ignore();
				int month_int = stoi(month);
				while(month_int < 0 || month_int > 12)
				{
					wcout << L"\nBạn nhập tháng sinh không hợp lệ, xin hãy nhập lại tháng sinh: ";
					getline(wcin, month);
					if(month == L"")
						noUserInputHandler(month);
					
					validateUserInput(month, 1); 
					month_int = stoi(month);
					wcin.ignore();
				}
				
				wcout << L"\nNhập năm sinh(tối đa đến năm 2025): ";
				getline(wcin, year);
				noUserInputHandler(year); 
				validateUserInput(year, 1); 
				wcin.ignore();
				int year_int = stoi(year);
				while(year_int < 0 || year_int > 2025)
				{
					wcout << L"\nBạn nhập năm sinh không hợp lệ, xin hãy nhập lại năm sinh: ";
					getline(wcin, year);
					if(year == L"")
						noUserInputHandler(year);
					
					validateUserInput(year, 1); 
					year_int = stoi(year);
					wcin.ignore();
				}
				
				bool isValidBirthday = true;
				bool isLeapYear = true;
				if(((year_int % 4 == 0) && (year_int % 100 != 0)) || (year_int % 400 == 0))
				{
					isLeapYear = true;
				}
				else
					isLeapYear = false;
				
				if(month_int == 4 || month_int == 6 || month_int == 9 || month_int == 11)
				{
					if(day_int == 31)
					{
						wcout << L"\nNgày tháng năm sinh không hợp lệ vì " << month << L" không có ngày thứ 31." << endl;
						isValidBirthday = false;
					}
				}
				else if(month_int == 2)
				{
					if(day_int > 29)
					{
						wcout << L"\nNgày tháng năm sinh không hợp lệ vì tháng " << month << L" không thể có ngày " << day << "!" << endl;
						isValidBirthday = false;
					}
					else
					{
						if(isLeapYear == false)
						{
							if(day_int == 29)
							{
								wcout << L"\nNgày tháng năm sinh không hợp lệ vì năm " << year << L" là năm không nhuận nên không có ngày " << day << "." << endl;
								isValidBirthday = false;
							}
						}
					}
				}
				
				if(isValidBirthday == true)
					break;
			}
	
		}
		void input(wstring& userInput, int mode)
		{
			getline(wcin, userInput);
			noUserInputHandler(userInput); 
			if(mode == 1 || mode == 0)
				validateUserInput(userInput, mode); 
			wcin.ignore();
		}
		
		
		void inputGender(wstring& gender)
		{
			wcout << L"\nNhập giới tính (nam hoặc nữ): ";
			input(gender, 0);
			if(gender == L"nỮ" || gender == L"NỮ" || gender == L"Đàn bà" || gender == L"ĐÀN BÀ" || gender == L"đàn bà" || gender == L"Phụ Nữ" || gender == L"PHỤ NỮ" 
			|| gender == L"phụ nữ" || gender == L"Con Gái" || gender == L"CON GÁI" || gender == L"con gái")
			{
				gender = L"Nữ";
			}
			else if(gender == L"NAM" || gender == L"Nam" || gender == L"Con trai" || gender == L"CON TRAI" || gender == L"con trai" || gender == L"Đàn ông" || gender == L"ĐÀN ÔNG" || gender == L"đàn ông" || gender == L"Đàn Ông")
			{
				gender = L"Nam";
			}
			
			while(gender != L"Nam" && gender != L"Nữ")
			{
				wcout << L"\nGiới tính không hợp lệ. Xin hãy nhập lại giới tính: ";
				input(gender, 0);
				if(gender == L"nỮ" || gender == L"NỮ" || gender == L"Đàn bà" || gender == L"ĐÀN BÀ" || gender == L"đàn bà" || gender == L"Phụ Nữ" || gender == L"PHỤ NỮ" 
				|| gender == L"phụ nữ" || gender == L"Con Gái" || gender == L"CON GÁI" || gender == L"con gái")
				{
					gender = L"Nữ";
				}
				else if(gender == L"NAM" || gender == L"Nam" || gender == L"Con trai" || gender == L"CON TRAI" || gender == L"con trai" || gender == L"Đàn ông" || gender == L"ĐÀN ÔNG" || gender == L"đàn ông" || gender == L"Đàn Ông")
				{
					gender = L"Nam";
				}
					
					
			}
		}
		
		void inputFaculty(wstring& faculty)
		{
			wstring faculty_list[4] = {L"Khoa Luật", L"Khoa Tiếng Anh thương mại", L"Khoa Tiếng Nhật", L"Khoa Tiếng Pháp"};
			while(1)
			{
				wcout << L"\nDanh sách khoa hợp lệ: " << endl;
				wcout << L"- Khoa Luật" << endl;
				wcout << L"- Khoa Tiếng Anh thương mại" << endl;
				wcout << L"- Khoa Tiếng Nhật" << endl;
				wcout << L"- Khoa Tiếng Pháp" << endl;
				wcout << L"Nhập khoa: ";
				input(faculty, 0);
				if(faculty == L"Luật" || faculty == L"luật" || faculty == L"LUẬT")
					faculty = L"Luật";
				else if(faculty == L"Tiếng Anh thương mại" || faculty == L"tiếng anh thương mại" || faculty == L"TIẾNG ANH THƯƠNG MẠI")
					faculty = L"Tiếng Anh thương mại";
				else if(faculty == L"Tiếng Nhật" || faculty == L"tiếng Nhật" || faculty == L"TIẾNG NHẬT" || faculty == L"tiếng nhật" || faculty == L"Nhật ngữ" || faculty == L"NHẬT NGỮ" || faculty == L"nhật ngữ")
					faculty = L"Tiếng Nhật";
				else if(faculty == L"Tiếng Pháp" || faculty == L"tiếng Pháp" || faculty == L"TIẾNG PHÁP" || faculty == L"tiếng pháp" || faculty == L"Pháp ngữ" || faculty == L"PHÁP NGỮ" || faculty == L"pháp ngữ")
					faculty = L"Tiếng Pháp";
				
				bool isValidFaculty = false;
				for(int i = 0; i < 4; i++)
				{
					wstring faculty_check = L"Khoa " + faculty;
					if(faculty_check == faculty_list[i])
					{
						isValidFaculty = true;
						break;
					}
				}
				if (isValidFaculty == true)
					break;
				else
					wcout << L"\nKhoa không hợp lệ" << endl;
			}
		}
		
		
		void inputSchoolYear(wstring& schoolYear)
		{
			while(1)
			{
				wcout << L"\nNhập niên khoá (K19, K20, K21, K22, K23, K24): ";
				input(schoolYear, 2);
				if(schoolYear == L"k19")
					schoolYear = L"K19";
				else if(schoolYear == L"k20")
					schoolYear = L"K20";
				else if(schoolYear == L"k21")
					schoolYear = L"K21";
				else if(schoolYear == L"k22")
					schoolYear = L"K22";
				else if(schoolYear == L"k23")
					schoolYear = L"K23";
				else if(schoolYear == L"k24")
					schoolYear = L"K24";
				if(schoolYear != L"K19" && schoolYear != L"K20" && schoolYear != L"K21" && schoolYear != L"K22" && schoolYear != L"K23" && schoolYear != L"K24")
				{
					wcout << L"\nNiên khoá không hợp lệ" << endl;
				}
				else
					break;
			}
		}
		
		void inputProgram(wstring& program)
		{
			while(1)
			{
				wstring program_list[] = {L"Chất lượng cao", L"Việt Pháp", L"Liên kết", L"Chính quy"};
				wcout << L"\n4 chương trình học: " << endl;
				wcout << L"- Chất lượng cao" << endl;
				wcout << L"- Việt Pháp" << endl;
				wcout << L"- Liên kết" << endl;
				wcout << L"- Chính quy" << endl;
				wcout << L"Nhập chương trình học: ";
				input(program, 0);
				if(program == L"Chất Lượng Cao" || program == L"CHẤT LƯỢNG CAO" || program == L"chất lượng cao" || program == L"CLC" || program == L"clc")
					program = L"Chất lượng cao";
				else if(program == L"Việt pháp" || program == L"VIỆT PHÁP" || program == L"việt pháp" || program == L"VP" || program == L"vp")
					program = L"Việt Pháp";
				else if(program == L"Liên Kết" || program == L"LIÊN KẾT" || program == L"liên kết" || program == L"LK" || program == L"lk")
					program = L"Liên kết";
				else if(program == L"Chính Quy" || program == L"CHÍNH QUY" || program == L"chính quy" || program == L"CQ" || program == L"cq")
					program = L"Chính quy";
				
				bool isValidProgram = false;
				for(int i = 0; i < sizeof(program_list) / sizeof(program_list[0]); i++)
				{
					if(program == program_list[i])
					{
						isValidProgram = true;
						break;
					}
				}
				
				if (isValidProgram == false)
				{
					wcout << L"\nChương trình học không hợp lệ" << endl;
				}
				else 
					break;
			}
		}
		
		void inputAddress(wstring& address)
		{
			wcout << L"\nNhập địa chỉ: ";
			input(address, 2);
		}
		
		
		void inputEmail(wstring& email)
		{
			while(1)
			{
				wcout << L"\nNhập email: ";
				input(email, 2);
				bool isValidEmail = false;
				for(int i = 0; i < email.length(); i++)
				{
					if(i > 0)
					{
						if(email[i] == '@')
						{
							wstring email_signature = email.substr(i, email.length() - i);
							if(email_signature == L"@gmail.com" || email_signature == L"@yahoo.com.vn" || email_signature == L"@hcmus.edu.vn" || email_signature == L"@clc.fitus.edu.vn")
							{
								isValidEmail = true;
								break;
							}
						}
					}
				}
				if(isValidEmail == false)
					wcout << L"\nEmail không hợp lệ" << endl;
				else
					break;
			}
		}
		
		void inputPhoneNumber(wstring& phoneNumber)
		{
			while(1)
			{
				wcout << L"\nNhập số điện thoại: ";
				input(phoneNumber, 1);
				wstring vnHeaderPhoneNumber[] = {L"032", L"033", L"034", L"035", L"036", L"037", L"038", L"039", L"096", L"097", L"098", L"086", L"083", L"084", L"085", L"081", L"082", L"088", L"091", L"094", L"070", L"079", L"077", L"076", L"078", L"090", L"093", L"089", L"056", L"058", L"092", L"059", L"099"};
				bool isValidPhoneNumber = false;
				if(phoneNumber.length() == 10)
				{
					wstring phoneNumberHeader = phoneNumber.substr(0, 3);
					for(int i = 0; i < sizeof(vnHeaderPhoneNumber) / sizeof(vnHeaderPhoneNumber[0]); i++)
					{
						if(phoneNumberHeader == vnHeaderPhoneNumber[i])
						{
							isValidPhoneNumber = true;
							break;
						}
					}
				}
				if(isValidPhoneNumber == false)
				{
					unsigned short countHeaderPhoneNumber = 0;
					wcout << L"Số điện thoại không hợp lệ." << endl;
					wcout << L"Số điện thoại hợp lệ ở Việt Nam là số điện thoại có 10 chữ số và có đầu số bắt đầu từ: " << endl;
					for(int i = 0; i < sizeof(vnHeaderPhoneNumber) / sizeof(vnHeaderPhoneNumber[0]); i++)
					{
						if(countHeaderPhoneNumber == 4)
						{
							wcout << endl;
							countHeaderPhoneNumber = 0;
						}
						wcout << vnHeaderPhoneNumber[i] << "\t";
						++countHeaderPhoneNumber;
					}
					wcout << endl;
				}
				else
					break;
			}
		}
		
		void inputStudentStatus(wstring& studentStatus)
		{
			while(1)
			{
				wcout << L"\nTình trạng sinh viên hợp lệ: " << endl;
				wcout << L"- Đang học" << endl;
				wcout << L"- Đã tốt nghiệp" << endl;
				wcout << L"- Đã thôi học" << endl;
				wcout << L"- Tạm dừng học" << endl;
				wcout << L"Nhập tình trạng sinh viên: ";
				input(studentStatus, 0);
				bool isValidStudentStatus = false;
				wstring validStudentStatus[] = {L"Đang học", L"Đã tốt nghiệp", L"Đã thôi học", L"Tạm dừng học"};
				if(studentStatus == L"đang học" || studentStatus == L"ĐANG HỌC" || studentStatus == L"Đang Học" || studentStatus == L"Học chưa xong" || studentStatus == L"học chưa xong")
					studentStatus = L"Đang học";
				else if(studentStatus == L"đã tốt nghiệp" || studentStatus == L"ĐÃ TỐT NGHIỆP" || studentStatus == L"Đã Tốt Nghiệp" || studentStatus == L"học xong rồi" || studentStatus == L"Học xong rồi" || studentStatus == L"HỌC XONG RỒI" || studentStatus == L"Học Xong Rồi")
					studentStatus = L"Đã tốt nghiệp";
				else if(studentStatus == L"đã thôi học" || studentStatus == L"Đã Thôi Học" || studentStatus == L"ĐÃ THÔI HỌC" || studentStatus == L"Nghỉ học rồi" || studentStatus == L"Nghỉ Học Rồi" || studentStatus == L"NGHỈ HỌC RỒI" || studentStatus == L"nghỉ học rồi" || studentStatus == L"nghỉ rồi" || studentStatus == L"Nghỉ rồi" || studentStatus == L"NGHỈ RỒI" || studentStatus == L"Nghỉ Rồi")
					studentStatus = L"Đã thôi học";
				else if(studentStatus == L"tạm dừng học" || studentStatus == L"TẠM DỪNG HỌC" || studentStatus == L"Tạm Dừng Học" || studentStatus == L"Nghỉ tạm thời" || studentStatus == L"NGHỈ TẠM THỜI" || studentStatus == L"nghỉ tạm thời" || studentStatus == L"Nghỉ Tạm Thời")
					studentStatus = L"Tạm dừng học";
				
				for(int i = 0; i < sizeof(validStudentStatus) / sizeof(validStudentStatus[0]); i++)
				{
					if(studentStatus == validStudentStatus[i])
					{
						isValidStudentStatus = true;
						break;
					}
				}
				if(isValidStudentStatus == false)
					wcout << L"Tình trạng sinh viên không hợp lệ" << endl;
				else 
					break;
			}
		}
		void inputStudentID(wstring& studentID)
		{
			wcout << L"Nhập mã số sinh viên: ";
			input(studentID, 1); // Mode 1 là yêu cầu input chỉ được số
		}
		
		void inputName(wstring& name)
		{
			wcout << L"\nNhập họ tên: ";
			input(name, 0); // Mode 0 là yêu cầu input chỉ được ký tự, không được là số
		}
		sinhVien()
		{
			
			inputStudentID(studentID);
			inputName(name);
			
			wstring day;
			wstring month;
			wstring year;
			inputBirthday(day, month, year);
			birthday = day + L"/" + month + L"/" + year;
			
			inputGender(gender);
			
			inputFaculty(faculty);
			
			inputSchoolYear(schoolYear);
			
			inputProgram(program);
			
			inputAddress(address);
			
			inputEmail(email);
			
			inputPhoneNumber(phoneNumber);
			
			inputStudentStatus(studentStatus);
			
		}
		void showInfo()
		{
			system("cls");
			wcout << L"Mã số sinh viên: " << studentID << endl;
			wcout << L"Họ tên: " << name << endl;
			wcout << L"Ngày sinh: " << birthday << endl;
			wcout << L"Giới tính: " << gender << endl;
			wcout << L"Khoa: " << faculty << endl;
			wcout << L"Niên khoá: " << schoolYear << endl;
			wcout << L"Chương trình: " << program << endl;
			wcout << L"Địa chỉ: " << address << endl;
			wcout << L"Email: " << email << endl;
			wcout << L"Số điện thoại: " << phoneNumber << endl;
			wcout << L"Tình trạng sinh viên: " << studentStatus << endl;
		}
    
};

int main()
{
	_setmode(_fileno(stdin), _O_U16TEXT);
	_setmode(_fileno(stdout), _O_U16TEXT);
	sinhVien a;
	a.showInfo();

	
	
	return 0;
}