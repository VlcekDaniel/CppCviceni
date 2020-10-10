#include "Receipt.h"
#include "CashRegister.h"

using namespace std;

int main(int argc, char** argv) {

	Receipt* receipt = new Receipt();
	receipt->SetId(1001);
	Receipt receipt2 = Receipt();
	receipt->SetId(1002);

	return 0;
}