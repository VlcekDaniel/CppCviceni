#include "Automobil.h"
#include "JSON.h"

Automobil::Automobil(int id, std::string znacka, double vykon, bool jeNaBenzin)
{
    this->id = id;
    this->znacka = znacka;
    this->vykon = vykon;
    this->jeNaBenzin = jeNaBenzin;
}

Automobil::~Automobil()
{
}

std::string Automobil::getString()
{
    JSON json;
    std::string out;
    ObjectValue* ov = new ObjectValue{};
    ov->append(KeyValuePair{ "ID", new NumberValue{(double)id}});
    ov->append(KeyValuePair{ "Znacka", new StringValue{znacka}});
    ov->append(KeyValuePair{ "Vykon", new NumberValue{vykon}});
    ov->append(KeyValuePair{ "JeNaBenzin", new BoolValue{jeNaBenzin}});

    out = ov->serialize();

    delete ov;

    //out.append("{");
    //out.append("\"Automobil\":{");
    //out.append("\"ID\":" + std::to_string(id) +"," + "\"Znacka\":\"" + znacka + "\"," + "\"Vykon\":" +std::to_string(vykon) + "," +"\"JeNaBenzin\":" +(jeNaBenzin ? "true" : "false)"));
    //out.append("}");
    //out.append("}");

    //std::cout << out<<std::endl;
    //std::cout << ov->serialize() << std::endl;

    return out;
}
