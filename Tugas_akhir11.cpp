#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <math.h>
using namespace std;

int main()
{
    long pokok_pinjaman, angsuran, tenor, cicilan_pokok, cicilan_bulanan, bunga_bulanan;
    string nama, barang;
    char pilihan;
    double persen, bunga, bunga_pertahun;
    welcome:

    system("color E");
    cout << "================================================ \n";
    cout << "| Welcome Simulasi Perhitungan Pinjaman Online | \n";
    cout << "================================================ \n";
    cout << "Apakah kamu ingin melanjutkan..........(y/n): ";
    cin >> pilihan;
    system("cls");

    switch (pilihan) 
    {
        case 'y':
            system("cls");
            goto pendaftaran;
            break;

        case 'n':
            system("cls");
            cout << "Kamu keluar \n";
            cin.ignore();
            cout << "Tekan Enter Jika ingin kembali ke menu awal";
            cin.get();
            system("cls");
            goto welcome;
            break;
          
        default:
            cout << "Salah atuh ihh kamu :( \n";
            cin.ignore();
            cout << "Tekan Enter Jika ingin kembali \n";
            cin.get();
            system("cls");
            goto welcome;
            break;
    
    }
    pendaftaran:

    cout << "============================================================= \n";
    cout << "| Nama Pengguna dan barang yang ingin di hitung angsurannya | \n";
    cout << "============================================================= \n";
    cout << " Nama      : ";
    cin >> nama;
    cout << " Barang    : ";
    cin >> barang;
    system("cls");
    goto menu;

    menu:

    cout << "============================ \n";
    cout << "| Perhitungan Bunga Kredit | \n";
    cout << "============================ \n";
    cout << "Pilihan Menu : \n";
    cout << "A. Perhitungan Bunga Flat \n";
    cout << "B. Perhitungan Bunga Efektif \n";
    cout << "C. Perhitungan Bunga Anuitas \n";
    cout << "D. Exit\n";
    cout << "Masukkan Pilihan : ";

    cin >> pilihan;
    system("cls");

    
    switch (pilihan) 
    {
        case 'A':
            cout << "========> Perhitungan Bunga Flat <======== \n";
            cout << "Pokok pinjaman     : "; cin >> pokok_pinjaman;
            cout << "Bunga per tahun    : "; cin >> bunga_pertahun;
            cout << "Tenorr pinjaman    : "; cin >> tenor;
            //Perhitungan
            cicilan_pokok = pokok_pinjaman / tenor;
            persen = bunga_pertahun / 100;
            bunga = (pokok_pinjaman * persen) / tenor;
            angsuran = cicilan_pokok + bunga;
            //Jumlah angsuran
            cout << "========> Angsuran per-bulan yang harus di bayar <======== \n";
            cout << "Atas Nama                    = " << nama << endl;
            cout << "Barang yang di angsur        = " << barang << endl;
            cout << "Angsuran yang harus di bayar = " << angsuran << endl;
            
            pilihan:

            cout << "Pilihan Menu : \n";
            cout << "A. Kembali ke menu \n";
            cout << "B. Keluar \n";
            cout << "Masukan pilihan : ";
            cin >> pilihan;

            switch (pilihan)
            {
                case 'A':
                    system("cls");
                    goto menu;
                    break;

                case 'B':
                    cout << "Kamu keluar \n";
                    break;
            
                default:
                    cout << "Salah atuh ihh kamu :( \n";
                    cin.ignore();
                    cout << "Tekan Enter Jika ingin kembali \n";
                    cin.get();
                    system("cls");
                    goto pilihan;
                    break;
            }
            break;

        case 'B':
            cout << "========> Perhitungan Bunga Efektif <======== \n";
            cout << "Pokok pinjaman     : "; cin >> pokok_pinjaman;
            cout << "Bunga per tahun    : "; cin >> bunga_pertahun;
            cout << "Tenor pinjaman     : "; cin >> tenor;
            //Perhitungan
            cicilan_pokok = pokok_pinjaman / tenor;
            bunga_pertahun = bunga_pertahun / 100;
            //Mencari Bunga dan Cicilan Bulanan
            cout << "========> Bunga dan Cicilan per-bulan ke yang harus di bayar <======== \n";
            cout << "Atas Nama                   = " << nama << endl;
            cout << "Barang yang di angsur       = " << barang << endl;
            //Perhitungan dan Perulangan
            for (int i = 1; i <= tenor; ++i)
            {
                bunga_bulanan = (pokok_pinjaman - ((i-1) * cicilan_pokok)) * bunga_pertahun / tenor;
                cicilan_bulanan = cicilan_pokok + bunga_bulanan;
                cout <<"Bunga Bulan "<< i << "   = " << bunga_bulanan << endl;
                cout <<"Cicilan Bulan "<< i << " = " << cicilan_bulanan << endl;
                cicilan_bulanan = 0;
                bunga_bulanan= 0;
            }

            cout << "Pilihan Menu : \n";
            cout << "A. Kembali ke menu \n";
            cout << "B. Keluar \n";
            cout << "Masukan pilihan : ";
            cin >> pilihan;

            switch (pilihan)
            {
                case 'A':
                    system("cls");
                    goto menu;
                    break;

                case 'B':
                    cout << "Kamu keluar \n";
                    cout << endl;
                    break;
            
                default:
                    cout << "Salah atuh ihh kamu :( \n";
                    cin.ignore();
                    cout << "Tekan Enter Jika ingin kembali \n";
                    cin.get();
                    system("cls");
                    goto pilihan;
                    break;
            }
            break;
         
        case 'C':
            cout << "========> Perhitungan Bunga Efektif <======== \n";
            cout << "Pokok pinjaman     : "; cin >> pokok_pinjaman;
            cout << "Bunga per tahun    : "; cin >> bunga_pertahun;
            cout << "Tenor pinjaman     : "; cin >> tenor;
            //Perhitungan
            bunga_pertahun = bunga_pertahun/100;
            cicilan_pokok = pokok_pinjaman * (persen / 12)/((1 - pow((1 + persen / 12), - tenor)));
            cout << "========> Cicilan Pokok per-bulan yang harus di bayar <======== \n";
            cout << "Atas Nama                         = " << nama << endl;
            cout << "Barang yang di angsur             = " << barang << endl;
            cout << "Cicilan Pokok yang harus di bayar = "<< cicilan_pokok << endl;

            cout << "Pilihan Menu : \n";
            cout << "A. Kembali ke menu \n";
            cout << "B. Keluar \n";
            cout << "Masukan pilihan : ";
            cin >> pilihan;

            switch (pilihan)
            {
                case 'A':
                    system("cls");
                    goto menu;
                    break;

                case 'B':
                    cout << "Kamu keluar \n";
                    break;
            
                default:
                    cout << "Salah atuh ihh kamu :( \n";
                    cin.ignore();
                    cout << "Tekan Enter Jika ingin kembali \n";
                    cin.get();
                    system("cls");
                    goto pilihan;
                    break;
            }
            break;

        case 'D':
            cout << "Kamu meninggalkan modul \n";
		    cout << "Semoga hari mu menyenangkan \n";
            break;

        default:
            cout << "Salah atuh ihh kamu :( \n";
            cin.ignore();
            cout << "Tekan Enter Jika ingin kembali ke menu";
            cin.get();
            system("cls");
            goto menu;
            break;
            
    } 
    
}