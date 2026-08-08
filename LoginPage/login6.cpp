/**
 * Program Simulasi Halaman Login Berbasis CLI (Command Line Interface).
 * Program ini memfasilitasi pembuatan akun tunggal dan proses autentikasi (login) 
 * dengan sistem pembatasan maksimal tiga kali percobaan.
 */

#include <iostream> //: Pustaka standar untuk operasi input dan output (std::cin, std::cout).
#include <string>   //: Pustaka standar untuk manipulasi tipe data teks (std::string).

int main(){
	// Deklarasi variabel penyimpanan kredensial.
	std::string name1, pw1; //: Menyimpan username dan password saat proses registrasi.
	std::string name2, pw2; //: Menyimpan input username dan password saat proses login.
	
	// Flag indikator status ketersediaan akun.
	//: false = belum ada akun teregistrasi; true = akun sudah teregistrasi.
	bool namePw = false;	

	// Variabel penyimpan input menu pilihan pengguna.
	std::string yesNo;

	// Variabel penghitung sisa batas percobaan login.
	int batasLogin;

	// Perulangan utama program (Main Menu Loop). 
	//: Berjalan tanpa henti hingga diputus oleh instruksi return 0 pada menu keluar.
	while(true){
		std::cout << "\n===Login Page===" << std::endl;
		std::cout << "Have you login before? (Y/N): ";
		std::cin >> yesNo;

		//: Membersihkan satu karakter (umumnya newline '\n') di dalam buffer memori input.
		//: Mencegah fungsi std::getline menangkap input kosong secara tidak sengaja.
		std::cin.ignore(); 

		// ==========================================
		// KODE REGISTRASI AKUN (Menu 'N' atau 'n')
		// ==========================================
		if(yesNo == "N" || yesNo == "n"){
			//: Validasi ketersediaan akun. Eksekusi ditolak jika akun sudah pernah dibuat.
			if(namePw){
				std::cout << "Account already exist.\n";
			}
			else{
				//: Pengambilan dan penyimpanan data kredensial baru.
				std::cout << "Username	: ";
				std::getline(std::cin, name1);
				std::cout << "Password	: ";
				std::getline(std::cin, pw1);
				std::cout << "Thankyou for your response!" << std::endl;

				//: Pembaruan status flag untuk mengunci menu registrasi.
				namePw = true;
				std::cout << "\nSuccess creating account!\n";
			}
		}	
		// ==========================================
		// KODE AUTENTIKASI/LOGIN (Menu 'Y' atau 'y')
		// ==========================================
		else if(yesNo == "Y" || yesNo == "y"){
			//: Validasi ketersediaan akun. Eksekusi ditolak jika flag masih false.
			if(!namePw){
				std::cout << "No login detected" << std::endl;
			}
			else{
				//: Inisialisasi ulang kuota percobaan ke nilai 3 setiap kali blok login diakses.
				batasLogin = 3;

				//: Perulangan form login. Aktif selama batas percobaan belum mencapai 0.
				while(batasLogin > 0){
					std::cout << "Username	: ";
					std::getline(std::cin, name2);
					std::cout << "Password	: ";
					std::getline(std::cin, pw2);
				
					//: Proses komparasi data input (name2, pw2) dengan data sistem (name1, pw1).
					if(name2 != name1 || pw2 != pw1){
						//: Eksekusi jika terjadi ketidakcocokan kredensial (Login gagal).
						std::cout << "Login failed.\n\n";
						batasLogin--; //: Pengurangan sisa kuota percobaan.
					}
					else{
						//: Eksekusi jika kredensial valid (Login sukses).
						std::cout << "\n===Login Page Response===" << std::endl;
						std::cout << "Username	: " << name2 << std::endl;
						std::cout << "Password	: " << pw2 << std::endl;
						std::cout << "\nLogin successful.\n";
						
						//: Instruksi break memaksa program keluar dari loop while(batasLogin > 0)
						//: secara instan, mengembalikan pengguna ke perulangan menu utama.
						break;
					}
				}
			}
		}
		// ==========================================
		// KODE TERMINASI/QUIT (Menu 'Q' atau 'q')
		// ==========================================
		else if(yesNo == "Q" || yesNo =="q"){
			//: Menghentikan fungsi main() sepenuhnya.
			return 0; 
		}
		// ==========================================
		// KODE PENANGANAN INPUT INVALID
		// ==========================================
		else{
			std::cout << "Input is not valid.\n";
		}
	}
	
	return 0;
}
