#ifndef _BUILDING_H_INCLUDED_
#define _BUILDING_H_INCLUDED_


using namespace std;

class Building{
protected:
    string identifier; 
    string generatedMaterial; 
    int generatedMaterialAmount; 

public:
    //PRE:
    //POST: Constructor de la clase. Se inicializan los atributos de la clase
    Building();
    
    
    //PRE:
    //POST: Constructor de la clase. Se copian los atributos de la instancia de Building recibida en los atributos
    Building(const Building &);
    

    //PRE:
    //POST: Destructor de la clase.  
    ~Building();


    //PRE:
    //POST: Sobrecarga de operador "<<". Se establecen las instrucciones para la impresion de la clase
    friend ostream & operator<< (ostream &outputStream, const Building & Building);
    

    //PRE:
    //POST: Sobrecarga de operador "==". Se establecen las instrucciones para comparar dos instancias de la clase
    bool operator==(const Building &);


    //PRE:
    //POST: Este metodo devuelve el atributo Identifier (identficador del edificio).
    string getIdentifier()const;


    //PRE: - 
    //POST: Este metodo devuelve el atributo generatedMaterial (nombre del material que genera el edificio que se encuentra en el mapa construido).
    string getGeneratedMaterial()const;
    
    
    //PRE:
    //POST: Este metodo devuelve el atributo generatedMaterialAmount (cantidad del material que genera el edificio que se encuentra en el mapa construido).
    int getGeneratedMaterialAmount()const;

    
    //PRE:
    //POST: Este metodo setea el atributo Identifier (identficador del edificio).
    void setIdentifier(string);
    
    
    //PRE:
    //POST: Este metodo setea el atributo generatedMaterial (nombre del material que genera el edificio que se encuentra en el mapa construido).
    void setGeneratedMaterial(string);
    
    
    //PRE:
    //POST: Este metodo setea el atributo generatedMaterialAmount (cantidad del material que genera el edificio que se encuentra en el mapa construido).
    void setGeneratedMaterialAmount(int);
};

#endif






