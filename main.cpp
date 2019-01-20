#include <iostream>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <string.h>
#include <unistd.h>

void get_data();
void calculations();

float height;
float horizontal_bomb_speed;
float airplane_speed;
float distance;
float atmo_pres;

int main(){
	std::cout << "BDC - Bomb Dropper Calculator v0.2" << std::endl << "By MD, MCD - Thessaloniki, Greece Oct. 2018" << std::endl;
	get_data();
	calculations();
	return 0;
}

void get_data(){
	std::cout << "\nFilename: values.txt ";
	char filename [30] = "values.txt";
	std::ifstream filestream;
	filestream.open(filename);

	if(!filestream.is_open()){
		exit(EXIT_FAILURE);
	}
	float value;
	filestream >> value;
	int vline = 0;
	while(filestream.good()){
		filestream >> value;
		std::cout << std::endl;
		if (vline == 0) {
			std::cout << "Height = " << value << " m" << std::endl;
			height = value;
		} else if (vline == 1) {
			std::cout << "Horizontal Bomb Speed = " << value << "m/s" << std::endl;
			horizontal_bomb_speed = value;
		} else if (vline == 2) {
			std::cout << "Airplane speed = " << value << "m/s" << std::endl;
			airplane_speed = value;
		} else if (vline == 3) {
			std::cout << "Distance = " << value << " m" << std::endl;
			distance = value;
		} else if (vline == 4) {
			std::cout << "Atmospheric pressure = " << value << "m/s^2" << std::endl;
			atmo_pres = value;
		}
		vline = vline + 1;
	}

}
void calculations() {
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	std::cout << "[-] Assuming target remains in the same position;" << std::endl;
	std::cout << "[-] Assuming airplane is heading towards the target's position;" << std::endl;
	float t = sqrt(2*height) / sqrt(atmo_pres);
	horizontal_bomb_speed = horizontal_bomb_speed + airplane_speed;
	float s2 = horizontal_bomb_speed * t;
	float s1 = distance - s2;
	std::cout << "[+] Distance: " << s1 << "m" << std::endl;
	float t1 = s1 / airplane_speed;
	std::cout << "[!] Explosives will be dropped in " << t1 << "seconds. " << std::endl;
	std::cout << "[-] Please, wait . . ." << std::endl;
	float split = t1 / 4;
	sleep(split);
	std::cout << "[!] 3" << std::endl;
	sleep(split);
	std::cout << "[!] 2" << std::endl;
	sleep(split);
	std::cout << "[!] 1" << std::endl;
	sleep(split);
	std::cout << "[!] Explosives dropped!" << std::endl;
}
