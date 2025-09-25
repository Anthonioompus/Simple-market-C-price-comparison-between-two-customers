#include <iostream>
#include <string>
#include <limits>

using namespace std;

double hitungTotalBelanja() {
	string namaBarangInput;
	int jumlahInput;
	double hargaSatuan = 0.0;
	double subtotalBelanja = 0.0;
	double diskon = 0.0;

	cout << "\nMasukkan barang belanjaan Anda (ketik 'selesai' untuk berhenti):\n";

	while (true) {
		cout << "\nMasukkan Nama Barang: ";
		getline(cin, namaBarangInput);

		if (namaBarangInput == "selesai") {
			break;
		}

		cout << "Masukkan Jumlah       : ";
		cin >> jumlahInput;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		hargaSatuan = 0.0;

		if (namaBarangInput == "Indomie Goreng") {
			hargaSatuan = 3000.0;
		} else if (namaBarangInput == "Kecap Bango") {
			hargaSatuan = 8500.0;
		} else if (namaBarangInput == "Teh Pucuk") {
			hargaSatuan = 3500.0;
		} else if (namaBarangInput == "Malboro") {
			hargaSatuan = 20500.0;
		} else if (namaBarangInput == "Indomilk") {
			hargaSatuan = 5000.0;
		}

		if (hargaSatuan > 0) {
			double hargaItem = hargaSatuan * jumlahInput;
			subtotalBelanja += hargaItem;
			cout << "-> Berhasil ditambahkan! Total sementara: Rp " << subtotalBelanja << endl;
		} else {
			cout << "-> Maaf, barang '" << namaBarangInput << "' tidak ditemukan." << endl;
		}
	}

	if (subtotalBelanja >= 25000) {
		diskon = subtotalBelanja * 0.05;
	}

	return subtotalBelanja - diskon;
}

int main() {
	cout << "Selamat Datang di Warung AnthoRmx!" << endl;
	cout << "---------------------------------------" << endl;
	cout << "===Pelanggan 1 Berbelanja===" << endl;

	double totalPelanggan1 = hitungTotalBelanja();

	cout << "\n===Pelanggan 2 Berbelanja===" << endl;
	double totalPelanggan2 = hitungTotalBelanja();

	cout << "\n======= Perbandingan Belanja =======\n";
	cout << "Total belanja pelanggan 1: Rp " << totalPelanggan1 << endl;
	cout << "Total belanja pelanggan 2: Rp " << totalPelanggan2 << endl;

	if (totalPelanggan1 > totalPelanggan2) {
		cout << "Pelanggan 1 berbelanja lebih banyak dari pelanggan 2.\n";
	} else if (totalPelanggan2 > totalPelanggan1) {
		cout << "Pelanggan 2 berbelanja lebih banyak dari pelanggan 1.\n";
	} else {
		cout << "Kedua pelanggan berbelanja dalam jumlah yang sama.\n";
	}

	cout << "\nTerima kasih telah berbelanja di Warung AnthoRmx!" << endl;
	return 0;
}