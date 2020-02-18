#pragma once
#include <iostream>
#include <fstream>
#include <inttypes.h>

using namespace std;

class BmpHeader {

private:
	char bufferHeader[54];
	void Unpack();
	void Init();

public:
	char BmpType[3];
	unsigned long BmpSize;
	unsigned long Reservado1;
	unsigned long Reservado2;
	unsigned long offset;
	unsigned long Tamano_Header;
	unsigned int width;     
	unsigned int height;    
	unsigned int  Planos;    
	unsigned int Tamano_puntos;
	unsigned long compresion;
	unsigned long Tamano_Imagen;
	unsigned long ResolucionHorizontal;
	unsigned long ResolucionVertical;
	unsigned long Tamano_TablaColor;
	unsigned long ColoresImportantes;
	
	void SetHeaderBuffer(const char*);
	
};



class BMP {
private:
	char* file_name;
	char buffer[54];
	ifstream file_bmp;
	BmpHeader bmp_header;
	void ReadHeader();

public:
	void OpenBmp(const char* filename);
	void PrintHeader();
};