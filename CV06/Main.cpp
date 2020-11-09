#include "GrowingContainer.h"

using namespace std;

int main(int argc, char** argv) {
	GrowingContainer<string,5,2> gr{};
	gr.AddElement("ahoj");
	gr.AddElement("cau");
	gr.AddElement("nazdar");
	gr.AddElement("aaa");
	gr.AddElement("bbb");
	gr.AddElement("ccc");
	gr.AddElement("aaa");
	//cout << gr.ReturnNumberOfValidElements();
	gr.DeleteElement(6);
	gr.DeleteElement(4);
	gr.AddElementOnIndex(0, "jsem na 0 miste");
	gr.AddElementOnIndex(5, "jsem na 5 miste");
	gr.AddElementOnIndex(7, "jsem na 7 miste");
	gr.DeleteElement(7);

	for (size_t i = 0; i < gr.ReturnNumberOfValidElements()+2; i++)
	{
		cout << gr.operator[](i) << endl;
	}
	
}