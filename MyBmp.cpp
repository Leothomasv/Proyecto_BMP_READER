#pragma warning(disable : 4996)
#include <cstring>
#include "bmp.h"


using namespace std;


void BmpHeader::SetHeaderBuffer(const char* buffer) {
	memcpy(bufferHeader, buffer, 54);
	Unpack();
}

void BMP::ReadHeader() {
	file_bmp.seekg(0, ios_base::beg);
	file_bmp.read(buffer, sizeof(buffer));
	bmp_header.SetHeaderBuffer(buffer);
}

void BMP::OpenBmp(const char* filename) {
	file_name = (char*) filename;
	file_bmp.open(filename, ifstream::in | ifstream::binary);
	ReadHeader();
}

void BmpHeader::Init() {

	BmpType[2] = '\0';
	BmpSize = 0;
	Reservado1 = 0;
	Reservado2 = 0;
	offset = 0;
}

void BmpHeader::Unpack() {
	char* pos = bufferHeader;
	memcpy(&BmpType, pos, 2);
	memcpy(&BmpSize, pos+=2, 4);
	memcpy(&Reservado1, pos+=4, 2);
	memcpy(&Reservado2, pos+=2, 2);
	memcpy(&offset, pos += 2, 4);
	memcpy(&Tamano_Header, pos += 4, 4);
	memcpy(&width, pos += 4, 4);
	memcpy(&height, pos += 4, 4);
}

void BMP::PrintHeader() {
	cout << "********************************************" << endl;
	cout << "Tipo: " << bmp_header.BmpType << endl;
	cout << "Size: " << bmp_header.BmpSize << endl;
	cout << "Reservado 1: " << bmp_header.Reservado1 << endl;
	cout << "Reservado 2: " << bmp_header.Reservado2 << endl;
	cout << "Offset: " << bmp_header.offset << endl;
	cout << "Tamano Header: " << bmp_header.Tamano_Header << endl;
	cout << "Anchura (Pixeles): " << bmp_header.width << endl;
	cout << "Altura (Pixeles): " << bmp_header.height << endl;
	cout << "********************************************" << endl;
}