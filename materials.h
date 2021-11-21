#ifndef _MATERIALS_H_INCLUDED_
#define _MATERIALS_H_INCLUDED_

using namespace std;

class Materials {

    string material;
    string identifier;
    int amount;

public:

    //PRE: -
    //POST: Constructor la clase Materials. Inicializa sus atributos.
    Materials();
    
    //PRE: -
    //POST: Constructor de la clase Material. Se copian los parametros recibidos.
    Materials(string, int);

    //PRE: - 
    //POST: Contructor de la clase Material. Se copian los atributos de la instancia recibida. 
    Materials(const Materials&);

    //PRE:
    //POST: Destructor de la clase Materials.
    ~Materials();

    //PRE: -
    //POST: Sobrecarga del operador <<.
    friend ostream& operator<< (ostream& outputStream, const Materials& Material);

    //PRE: -
    //POST: Sobrecarga del operador ==. Si son iguales, devuelve true. Sino, false.
    bool operator==(const Materials&);

    //PRE:
    //POST: Devuelve el atributo material.
    string getMaterial()const;

    //PRE:
    //POST: Devuelve el atributo identifier.
    string getIdentifier()const;

    //PRE:
    //POST: Devuelve el atributo amount.
    int getAmount()const;

    //PRE: -
    //POST: Setea el atributo material.
    void setMaterial(string);

    //PRE: -
    //POST: Setea el identificador del material.
    void setIdentifier(string);

    //PRE: -
    //POST: Setea el atributo amount.
    void setAmount(int);
};

#endif
