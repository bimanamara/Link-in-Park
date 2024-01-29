#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <time.h>


typedef struct user_login{
	char username[10][10];
	char password[12];
	char pass[12];
	int charPosition;
	int status;
	int anim;
}Login;


typedef struct mtr_mbl {
	int count;
	int temp;
	int loop;
	char plat[50][50];
	char duplicatePlat[50][50];
	char karcis[50][50];
}kendaraan;


typedef struct data{
	int sentinel;
	int loop; 
	int x; 
	int y; 
	int jenis;
	int nominal;
	int bayar;
	float parkir;
	char tanya;
}Data;


void cetakStruk (kendaraan motor_mobil, Data input, int loop, char* kategori, int tagihan);
void resultTable(kendaraan motor_mobil, char* jenis, int kapasitas);
void menuAnimation(int a, int b, int c, int d, int e, int f);
void skipStruk();
void login_userPass();
void displayIntro();
void main_menu();
void guideUser();
void pilihan_menu();
void kendaraanKosong();
int validasiPlat(kendaraan motor_mobil, char *jenis, int kapasitas, int* temp, int* loop);
int stringAnimation_exitProgram();
int mtr (int a);
int mbl (int b);


//Main program
int main(){
	
	displayIntro();
	login_userPass();
	menuAnimation(2, 100, 100, 100, 100, 2);
	main_menu();
	
	return 0;
}


//Fungsi Opening Program
void displayIntro(){
	
	Data i;
	printf("\t\t\t");
	for (i.loop = 0; i.loop < 54; i.loop++){
		printf("=");
		Sleep(2); 
	}
	
    printf("\n");
    Sleep(100);
    printf("\t\t\t|  Selamat Datang di Proyek Akhir Dasar Komputer ^_^ |\n");
    Sleep(100);
    printf("\t\t\t|                    Created By :                    |\n");
    Sleep(100);
    printf("\t\t\t|                Kelompok 8 (Heatsink)               |\n");
    Sleep(100);
    
    printf("\t\t\t");
	for (i.loop = 0; i.loop < 54; i.loop++){
		printf("=");
		Sleep(2);
	}
    Sleep(100); // dalam milisekon 
    printf("\n\n");
}

// Fungsi Cek Username dan Password
void login_userPass(){
	
	Login log;
	log.status = 0;
	
	while(log.status != 3){
    	printf("Masukkan Username : ");
      	gets(*log.username);
      	printf("Masukkan Password : ");
      	
		while(1){
			*log.pass = getch(); // digunakan untuk menyimpan password (karakter satu persatu) 
			
			if (*log.pass == 13){	//ketika user menekan tombol enter maka akan langsung selesai looping
				log.password[log.charPosition] = '\0';
				break;
			}
			
			else if (*log.pass == 8){	//ketika user menekan tombol backspace maka akan terhapus satu huruf
				if (log.charPosition > 0){
					log.charPosition--;
					log.password[log.charPosition] = '\0';
					printf("\b \b"); //untuk menghilangkan karakter bintang (*)
				}
			}
			
			else if (*log.pass == 127){	//ketika user menekan tombol ctrl + Backspace maka akan terhapus semua
				if (log.charPosition > 0){
					for(log.status=0;log.status < log.charPosition;log.status++){
						printf("\b \b");
					}
					log.charPosition-=log.charPosition;
					log.password[log.charPosition] = '\0';
				}
			}
			
			else if(*log.pass > 0 && *log.pass < 33){	//ketika user menekan tombol (ASCII (1-32)) yang tidak terdapat keyboard akan skip
				continue;
			} 
			
			else {
				log.password[log.charPosition] = *log.pass;
				log.charPosition++;
				printf("*");
			}
		}
		
		log.password[log.charPosition]='\0';	//supaya dia null kembali atau menghindari adanya error
    	
      	if(strcmp(*log.username, "operator")==0 && strcmp (log.password, "operator")==0){
      		log.status = 3;
      		Sleep(5);
         	printf("\n\n\n\n\t\t\t\t\tAKSES DITERIMA\n\n");
         	Sleep(500);
         	printf("\t\t\t\t\tLoading");
         	
         	for (log.anim = 0; log.anim < 5; log.anim++){
         		Sleep(850);
				printf(".");
			}
      	} 
		
		else{
         	printf("\n---- Username dan Password Salah ----\n\n");
         	log.status++;
			if(log.status == 3){
				system ("cls");
				printf("\n\t\t\t##############################################################");
				printf("\n\t\t\t#   Anda Memasukkan User dan Password Lebih dari Tiga Kali!  #");
				printf("\n\t\t\t#   Akses ditolak                                            #");
				printf("\n\t\t\t##############################################################\n");
            	exit(0);
        	} 
      	}
    	
		log.charPosition-=log.charPosition;	//agar password dapat tercetak jadi awal lagi
	}
   	system("cls");
}


//Fungsi Judul Program
void menuAnimation(int a, int b, int c, int d, int e, int f){
	Data j;
	
	printf("\t\t\t");
	for (j.loop = 0; j.loop < 70; j.loop++){
		printf("=");
		Sleep(a);
	}
	
	printf("\n");
    Sleep(b);
    printf("\t\t\t|                                                                    |\n");
    Sleep(c);
    printf("\t\t\t|                    -  PROGRAM LINK IN PARK  -                      |\n");
    Sleep(d);
    printf("\t\t\t|                                                                    |\n");
    Sleep(e);
    
    printf("\t\t\t");
    for (j.loop = 0; j.loop < 70; j.loop++){
		printf("=");
		Sleep(f);
	}
	
    printf("\n");
}

//Fungsi Pemrosesan Menu yang Dipilih User
void main_menu(){
	Data input;
	kendaraan motor;
	kendaraan mobil;
	
	char* input_karcis = calloc(4096,sizeof(char)); // 4096 untuk menyimpan karcis sebanyak 4096 yang kita cek pada
													// case 4 karena input karcis bisa > 100
	
	int *pilih, pilihan;
	pilih = &pilihan;
	motor.temp = 0;
	mobil.temp = 0;
	motor.count = 0;
	mobil.count = 0;
	motor.loop = 0;
	mobil.loop = 0;
	
	pilihan_menu();
    
	do{
    	printf(">> ");
    	scanf("%d", pilih);
    	
    	if (*pilih < 1 || *pilih > 6){
    		printf("\nMasukkan Angka yang Sesuai!\n");
		}
		
		switch (*pilih){

			case 1:
		        if(motor.count < 50 + motor.temp){
		        	motor.count++;
		            printf("Plat Motor\t: ");
		            scanf(" %255[^\n]s", &motor.plat[motor.count]);
					fflush(stdin);
					
					if(validasiPlat(motor, "Motor", 50, &motor.temp, &motor.count)){		
						strcpy(motor.duplicatePlat[motor.count], motor.plat[motor.count]); // untuk menyimpan plat motor ke duplikat plat
						srand(time('\0')); // untuk mendapatkan angka acak setiap waktunya
						snprintf(motor.karcis[motor.count], 20, "#karcis%d", rand()  % 99999 + 10000); //Tiket Random 10000...99999 (5 digit)
						// rand akan input angka acak sebanyak 5 digit (dari srand) >> #karcis... >> akan jadi char ( snprintf ) >> 20 ( untuk kuota tiap char )
						printf("Karcis Anda\t: %s", motor.karcis[motor.count]);
						printf("\n------------------------------\n");
						printf("Total Motor\t: %d\n\n", motor.count - motor.temp);
					}
					
		        }
		        else{
		            printf("Tempat Parkir Motor Penuh\n\n");
		        }
		        break;
		        
			case 2:
		        if(mobil.count < 10 + mobil.temp){
		        	mobil.count++;
		            printf("Plat Mobil\t: ");
		            scanf(" %255[^\n]s", &mobil.plat[mobil.count]);
		            fflush(stdin);
		            
			        if(validasiPlat(mobil, "Mobil", 10, &mobil.temp, &mobil.count)){		
						strcpy(mobil.duplicatePlat[mobil.count], mobil.plat[mobil.count]);
						snprintf(mobil.karcis[mobil.count], 20, "#karcis%d", rand() % 99999 + 10000); //Tiket Random 10000...99999 (5 digit)
						printf("Karcis Anda\t: %s", mobil.karcis[mobil.count]);
						printf("\n------------------------------\n");
						printf("Total Mobil\t: %d\n\n", mobil.count - mobil.temp);
					}
					
		        }
		        else{
		            printf("Tempat Parkir Mobil Penuh\n\n");
		        }
		        break;
		        
			case 3:
				if(motor.count == 0 && mobil.count == 0){
					system("cls");
					kendaraanKosong();
				    system("pause");
				}
				
				else if (motor.count > 0 && mobil.count == 0) {
					system("cls");
					resultTable(motor, "Motor", 50+motor.temp);
					system("pause");
				}
				
				else if (mobil.count > 0 && motor.count == 0){
					system("cls");
					resultTable(mobil, "Mobil", 10+mobil.temp);
					system("pause");
				}
				
				else {
					system("cls");
					resultTable(motor, "Motor", 50+motor.temp);
					resultTable(mobil, "Mobil", 10+mobil.temp);
					system("pause");
				}
				
				system("cls");
				menuAnimation(0, 0, 0, 0, 0, 0);
				pilihan_menu();
				
		        break;
		    
			//Payment Menu    
			case 4:
				if(motor.count != motor.temp || mobil.count != mobil.temp){
					system("cls");
		            printf ("\n		    ============================================================================   ");
		            printf ("\n					    Jenis Kendaraan dan Tarif Parkir                                   ");
		            printf ("\n			    1. Motor : Rp. 2000 untuk 1 Jam Pertama, Rp. 1000/jam berikutnya.          ");
		            printf ("\n			    2. Mobil : Rp. 5000 untuk 1 Jam Pertama, Rp. 4000/jam berikutnya.          ");
		            printf ("\n			    0. Kembali ke Menu Awal                                                    ");
		            printf ("\n		    ============================================================================   ");
		            printf ("\n		               Masukkan Kategori Kendaraan (Berdasarkan Nomor Pilihan)         \n\n");
		            
		            do{
		            	printf("Pilih : ");
		            	scanf("%d", &input.jenis);
		            	if(input.jenis<0 || input.jenis>2){
		            		printf("Masukkan Input yang Sesuai\n\n");
						}
					}while(input.jenis < 0 || input.jenis > 2);
					
		            switch (input.jenis){
		            	
		            	case 0:
		            		system("cls");
		            		menuAnimation(0, 0, 0, 0, 0, 0);
							pilihan_menu();
		            		break;
		            		
		            	case 1:
		            		if(motor.count==motor.temp){
					            kendaraanKosong();
				                system("pause");
								system("cls");
		            			menuAnimation(0, 0, 0, 0, 0, 0);
								pilihan_menu();
							}
							else {
								input.sentinel = 0;
								printf("\nMasukkan Karcis Anda (misal : #karcis24122) : ");
								
								do{
									input.sentinel++;
						        	scanf(" %255[^\n]s", input_karcis);
									for (input.loop = 1; input.loop <= 50 + motor.temp; input.loop++){
								       	if (strcmp(input_karcis, motor.karcis[input.loop])==0){
											printf ("Plat Motor\t\t\t\t    : %s\n", motor.plat[input.loop]);
											printf ("Lama Parkir (per jam)?\t\t\t    : ");
                        					scanf  ("%f", &input.parkir);
											printf ("Total Tagihan\t\t\t\t    : %d", mtr(input.parkir));
                        					printf ("\nTotal Pembayaran\t\t\t    : " );
                        					scanf  ("%d", &input.nominal);
											input.y = input.nominal - mtr(input.parkir);
											printf("\n");
											
				                            while (input.y < 0){
				                                printf ("Total Uang yang Dimasukkan\t\t    : %d\n", input.nominal);
				                                printf ("\n----------------- Maaf, Uang Tidak Mencukupi --------------------\n\n");
				                                printf ("Tambahkan Uang untuk Mencukupi Pembayaran   : " );
				                                scanf  ("%d", &input.x);
				                                printf("\n");
				                                input.nominal += input.x;
				                                input.y = input.nominal - mtr(input.parkir);
				                            }
				                            
				                            printf ("\nKembalian\t\t\t\t    : %d", input.y);
				                            printf("\n=================================================================");
				                            printf ("\nCetak Struk? (Y/N) : ");
				                            
											do{
				                            	scanf ("%s", &input.tanya);
					                            if (input.tanya=='Y' || input.tanya=='y'){
					                                system("cls");
					                                cetakStruk (motor, input, input.loop, "Motor", mtr(input.parkir));
	                                			}
	                               				else if(input.tanya == 'N' || input.tanya == 'n'){
					                                system("cls");
					                                skipStruk();
	                                			}
												else {
					                                printf("\nHuruf Tidak valid, Coba Lagi!");
					                                printf ("\nCetak Struk? (Y/N)\n>> ");
					                            }
											}while(input.tanya != 'y' && input.tanya != 'Y' && input.tanya != 'n' && input.tanya != 'N');
											
											//untuk mengganti di bagian situ menjadi (-) lalu mengeprintnya di case 3
											strncpy(motor.plat[input.loop],"   (-)",20);
											strncpy(motor.duplicatePlat[input.loop],"",20);
											strncpy(motor.karcis[input.loop],"    (-)",20);
											motor.temp++;
											input.sentinel = -1;
											break;
								      	}
										else {
											continue;
										}
									}
									if(input.loop == 51 + motor.temp && input.sentinel != 5){
								      	printf("\nKarcis Salah, Silakan Input Ulang Karcis (misal: #karcis24122)\n>> ");
									}
								}while(input.sentinel != 5 && input.sentinel != -1); 
								
								if(input.sentinel == 5){
									system("cls");
									printf("\n\t\t\t=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
									printf("\t\t\t|   Anda Salah Memasukkan Karcis Sebanyak Lima Kali   |\n");
									printf("\t\t\t|    Silakan Input Ulang Melalui Main Menu Kembali    |\n");
									printf("\t\t\t=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n");
									system("pause");
									system("cls");
			            			menuAnimation(0, 0, 0, 0, 0, 0);
									pilihan_menu();	
								} 
								else {
									system("pause");
									system("cls");
			            			menuAnimation(0, 0, 0, 0, 0, 0);
									pilihan_menu();
								}
							}
		            		break;
		            		
						case 2:
							
							if(mobil.count==mobil.temp){
					            kendaraanKosong();
				                system("pause");
								system("cls");
		            			menuAnimation(0, 0, 0, 0, 0, 0);
								pilihan_menu();
							}
							
							else {
								input.sentinel = 0;
								printf("\nMasukkan Karcis Anda (misal: #karcis24122) : ");
								do{
									input.sentinel++;
						        	scanf(" %255[^\n]s", input_karcis);
									for (input.loop = 1; input.loop <= 50 + motor.temp; input.loop++){
								       	
										if (strcmp(input_karcis, mobil.karcis[input.loop])==0){	
											printf ("Plat Mobil \t\t\t\t   : %s\n", mobil.plat[input.loop]);
											printf ("Lama Parkir (per jam)?\t\t\t   : ");
                        					scanf  ("%f", &input.parkir);
											printf ("Total Tagihan\t\t\t\t   : %d", mbl(input.parkir));
                        					printf ("\nTotal Pembayaran\t\t\t   : " );
                        					scanf  ("%d", &input.nominal);
											input.y = input.nominal - mbl(input.parkir);
											printf("\n");
				                            
											while (input.y < 0){
				                                printf ("Total Uang yang Dimasukkan\t\t   : %d\n", input.nominal);
				                                printf ("\n----------------- Maaf, Uang Tidak Mencukupi --------------------\n\n");
				                                printf ("Tambahkan Uang untuk Mencukupi Pembayaran  : " );
				                                scanf  ("%d", &input.x);
				                                printf("\n");
				                                input.nominal += input.x;
				                                input.y = input.nominal - mbl(input.parkir);
				                            }
				                            
											printf ("\nKembalian\t\t\t\t   : %d", input.y);
				                            printf("\n=================================================================");
				                            printf ("\nCetak Struk? (Y/N) : ");
				                            
											do{
				                            	scanf ("%s", &input.tanya);
					                            if (input.tanya=='Y' || input.tanya=='y'){
					                                system("cls");
					                                cetakStruk (mobil, input, input.loop, "Mobil", mbl(input.parkir));
	                                			}
	                               				else if(input.tanya == 'N' || input.tanya == 'n'){
					                                system("cls");
					                                skipStruk();
	                                			}
												else {
					                                printf("\nHuruf Tidak valid, Coba Lagi!");
					                                printf ("\nCetak Struk? (Y/N)\n>> ");
					                            }
											}while(input.tanya != 'y' && input.tanya != 'Y' && input.tanya != 'n' && input.tanya != 'N');
											
											strncpy(mobil.plat[input.loop],"   (-)",20);
											strncpy(mobil.duplicatePlat[input.loop],"",20);
											strncpy(mobil.karcis[input.loop],"    (-)",20);
											mobil.temp++;
											input.sentinel = -1;
											break;
								      	}
										else {
											continue;
										}
									}
									if(input.loop == 51 + motor.temp && input.sentinel != 5){
								      	printf("\nKarcis Salah, Silakan Input Ulang Karcis (Misal: #karcis24122)\n>> ");
									}
								}while(input.sentinel != 5 && input.sentinel != -1);
								
								if(input.sentinel == 5){
									system("cls");
									printf("\n\t\t\t=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
									printf("\t\t\t|   Anda Salah Memasukkan Karcis Sebanyak Lima Kali   |\n");
									printf("\t\t\t|    Silakan Input Ulang Melalui Main Menu Kembali    |\n");
									printf("\t\t\t=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n");
									system("pause");
									system("cls");
			            			menuAnimation(0, 0, 0, 0, 0, 0);
									pilihan_menu();	
								}
								else {
									system("pause");
									system("cls");
			            			menuAnimation(0, 0, 0, 0, 0, 0);
									pilihan_menu();	
								}
							}
		            		break;
		    			}
				}
				else {
					system("cls");
					kendaraanKosong();
					system("pause");
					system("cls");
	                menuAnimation(0, 0, 0, 0, 0, 0);
					pilihan_menu();
				}
				break;
				
			case 5:
				guideUser();
		    	menuAnimation(0, 0, 0, 0, 0, 0);
				pilihan_menu();
			    break;
			
			case 6:
		    	stringAnimation_exitProgram();
			    break;
			    
			}
					
	}while(*pilih != 6);
	
	free(input_karcis);
}

//Fungsi Pilihan Menu dalam Program
void pilihan_menu(){
	printf("\n\nBerikut daftar menu yang tersedia: \n");
    printf("[1]  Kendaraan Motor Masuk\n");
    printf("[2]  Kendaraan Mobil Masuk\n");
    printf("[3]  Daftar Kendaraan dan Kapasitas\n");
    printf("[4]  Kendaraan Keluar\n");
    printf("[5]  Panduan Penggunaan Program\n");
    printf("[6]  Keluar dari Program\n");
    printf("Pilih Angka yang Ingin Anda Masukkan:\n");
}

//Fungsi Pengecekan Plat Kendaraan
int validasiPlat(kendaraan motor_mobil, char *jenis, int kapasitas, int* temp, int* loop){
	Data input;
	for (input.loop = 1; input.loop <= kapasitas + *temp; input.loop++){
		if (strcmp(motor_mobil.plat[*loop], motor_mobil.duplicatePlat[input.loop])==0){
			printf("Plat %s Tidak Boleh Sama\n\n", jenis);
			*loop-=1;
			return 0;
			break;
		}		
		else {
			continue;
		}
	}
	return 1;
}

//Fungsi Output ketika User Memilih untuk Tidak Mencetak Struk Pembayaran
void skipStruk(){
	printf ("\n                    --------------------------------------------------------------------------\n");
	printf ("                                  TERIMAKASIH TELAH MENGGUNAKAN LINK IN PARK PROGRAM              ");
	printf ("\n                    --------------------------------------------------------------------------\n\n");
}

//Fungsi Pencetakan Struk Pembayaran Parkir
void cetakStruk (kendaraan motor_mobil, Data input, int loop, char* kategori, int tagihan){
	printf ("          --------------------------------------------------------------------------\n");
	printf ("                       Nomor Karcis                 : %s              \n", motor_mobil.karcis[loop]);
	printf ("                       Nomor Plat Kendaraan         : %s              \n", motor_mobil.plat[loop]);
	printf ("                       Jenis kendaraan               : %s              \n", kategori);
	printf ("                       Durasi Parkir (per jam)      : %.2f            \n", input.parkir);
	printf ("                       Total Tagihan Parkir         : %d              \n", tagihan);
	printf ("                       Total Pembayaran             : %d              \n", input.nominal);
	printf ("                       Kembalian                    : %d              \n", input.y);
	printf ("\n          --------------------------------------------------------------------------\n");
	printf ("                         TERIMAKASIH TELAH MENGGUNAKAN PELAYANAN KAMI                    ");
	printf ("\n          --------------------------------------------------------------------------\n\n");	
}

//Fungsi Panduan Penggunaan Program
void guideUser(){
    system("cls");
    printf ("\n\t\t+-------------------------------------------------------------------------------------------+\n");
    printf ("\t\t|                          PANDUAN PENGGUNAAN PROGRAM LINK-IN PARK                          |\n");
    printf ("\t\t|                                                                                           |\n");
    printf ("\t\t|   1. Program Berfungsi untuk Mengetahui Ketersediaan Lahan dan Menghitung Tarif Parkir.   |\n");
    printf ("\t\t|   2. Menu 1 untuk Memasukkan Data Motor Masuk.                                            |\n");
    printf ("\t\t|   3. Menu 2 untuk Memasukkan Data Mobil Masuk.                                            |\n");
    printf ("\t\t|   4. Menu 3 untuk Melihat Daftar Kendaraan yang Terparkir dan Kapasitas Tersisa.          |\n");
    printf ("\t\t|   5. Menu 4 untuk Menghitung Tarif Parkir dan Mendata Kendaraan Keluar.                   |\n");
    printf ("\t\t|   6. Menu 5 untuk Melihat Panduan Penggunaan                                              |\n");
    printf ("\t\t|   7. Menu 6 untuk Keluar Program.                                                         |\n");
    printf ("\t\t+-------------------------------------------------------------------------------------------+\n\n");

    system("pause");
    system("cls");
}

//Fungsi Output ketika Exit Program
int stringAnimation_exitProgram(){
	
	Data k;
	char* animationString = (char*) malloc (53 * sizeof(int));
	
	system ("cls");
	animationString = "\t\t\t   Terimakasih Telah Menggunakan Program Ini ^_^   \n";
	printf("\t\t\t");
    for (k.loop=0;k.loop<26;k.loop++){
    	printf("+-");
    	usleep(1000);
	}
	printf("+\n");
    for (k.loop=0;k.loop<53;k.loop++){
    	printf("%c", animationString[k.loop]);
   		usleep(10000);
	}
	printf("\n");
	printf("\t\t\t");
    for (k.loop=0;k.loop<26;k.loop++){
   		printf("+-");
    	usleep(1000);
	}
	printf("+\n\n");
	
	system ("pause");
	return 0;
	
	free(animationString);

}

// Fungsi Output Tabel Kendaraan 
void resultTable(kendaraan motor_mobil, char* jenis, int kapasitas){
	char change[kapasitas];
	printf("\n\nKapasitas %s yang Tersisa: %d", jenis, kapasitas - motor_mobil.count);
	printf("\nInformasi %s Terkini:\n", jenis);
	printf("+------------------------------------------------------------------------+\n");
	printf("|      No       |          Plat %s         |          Karcis          |\n", jenis);
	printf("+------------------------------------------------------------------------+\n");
	for (motor_mobil.loop=1;motor_mobil.loop <= motor_mobil.count;motor_mobil.loop++){
		snprintf(change, 10, "%d", motor_mobil.loop); 
		// untuk mengubah loop (int) menjadi char (snprintf) jadi tabel gak mencong >> variable change >> 10 guna untuk nyimpan sebanyak 10 char 
		printf("|%8.17s%-7.15s|%10.17s%-19.15s|%7.17s%-19.15s|\n", change, "", "", motor_mobil.plat[motor_mobil.loop],"", motor_mobil.karcis[motor_mobil.loop]);		
	}
	printf("+------------------------------------------------------------------------+\n");
}


//Fungsi Output ketika Tempat Parkir Kosong
void kendaraanKosong(){
	printf ("\n\t\t\t--------------------------------------------------------------------------\n");
	printf ("\t\t\t                   Tidak Ada Kendaraan di Tempat Parkir                       ");
	printf ("\n\t\t\t--------------------------------------------------------------------------\n\n");	
}


// Fungsi Perhitungan Pembayaran Parkir Motor
int mtr (int a){
	int bayar = 2000;
	int i;
	if (a == 1){
		bayar = 2000;
	}
    else{
	    for (i = 1; i < a; i++){
		    bayar += 1000;
	    }
    }
	return bayar;
}


// Fungsi Perhitungan Pembayaran Parkir Mobil
int mbl (int b){
	int bayar = 5000;
	int i;
	if (b == 1){
		bayar = 5000;
	}
    else{
	    for (i = 1; i < b; i++){
		    bayar += 4000;
	    }
    }
	return bayar;
}
