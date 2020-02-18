#include "bmp.h"

using namespace std;

int main() {
	BMP f;
	char filename[20];
	cout << "Open file:" << flush; // force output
	cin >> filename;

	f.OpenBmp(filename);
	f.PrintHeader();
}