#include <QCoreApplication>
#include <iostream>
#include <stdlib.h>

using namespace std;

class Base{

private:    //atributos
    string nombre;
    string apellidos;
    string DNI;
public:
    Base(string,string,string);
    Base();
    ~Base();
    string getNombre();
    string getApellidos();
    string getDNI();
    void setNombre(string name);
    void setApellidos(string apellidos);
    void setDNI(string DNI);
};
Base::Base(string nombre,string apellidos,string DNI){
    this->nombre=nombre;
    this->apellidos=apellidos;
    this->DNI=DNI;
}
Base::Base(){
}
Base::~Base(){
}

void Base::setNombre(string nombre){
    this->nombre=nombre;
}
void Base::setApellidos(string apellidos){
    this->apellidos=apellidos;
}
void Base::setDNI(string DNI){
    this->DNI=DNI;
}
string Base::getNombre(){
    return this->nombre;
}
string Base::getApellidos(){
    return this->apellidos;
}
string Base::getDNI(){
    return this->DNI;
}













class Alumno : public Base{
private:
    list <float> notas;

public:
    Alumno(string,string,string);
    Alumno();
    ~Alumno();
    float getNotaMedia();
    void obtenerNota(float nota);
    int devolverNumeroNotas();
    float notaMediaAlumno();
    void imprimirNotas();

};
Alumno::Alumno(string nombre,string apellidos,string DNI) : Base (nombre ,apellidos ,DNI ){

}
Alumno::Alumno(){
}

Alumno::~Alumno(){
}

void Alumno::imprimirNotas(){
    list <float> :: iterator it;

        for (it = notas.begin();it !=notas.end();++it) {

            cout<<" "<< *it<<" ";

        }
}

void Alumno::obtenerNota(float nota){
    notas.push_back(nota);
}
int Alumno::devolverNumeroNotas(){
    return notas.size();
}
float Alumno::getNotaMedia(){
    float media=notaMediaAlumno();
    return media;
}
float Alumno::notaMediaAlumno(){
    if(notas.size()==3){

        float total=0;
        float media;
        list <float> :: iterator it;
        for (it = notas.begin();it != notas.end();++it) {
            total=total+*it;
        }
        media=total/3;
        return media;

    }else if(notas.size()==2){
        float total=0;
        float media;
        list <float> :: iterator it;
        for (it = notas.begin();it != notas.end();++it) {
            total=total+*it;
        }
        media=total/2;
        return media;

    }else if(notas.size()==1){
        float total=0;
        float media;
        list <float> :: iterator it;
        for (it = notas.begin();it != notas.end();++it) {
            total=total+*it;
        }
        media=total/1;
        return media;

    }

}















class Profesor : public Base{
private:
    list <Alumno> alumnos;
    list <Alumno> mejores;
public:
    Profesor(string,string,string);
    Profesor();
    ~Profesor();
    void anyadirAlumno(Alumno *a);
    void asignarNota(Alumno *a,float nota1);
    void asignarNota2(Alumno *a,float nota1,float nota2);
    void asignarNota3(Alumno *a,float nota1,float nota2,float nota3);
    float notaMedia(Alumno *a);
    void imprimirListado();
    void imprimirMejorNota();
};
Profesor::Profesor(string nombre,string apellidos,string DNI) : Base(nombre,apellidos,DNI){

}
Profesor::Profesor(){

}
Profesor::~Profesor(){

}


void Profesor::anyadirAlumno(Alumno *a){
    alumnos.push_back(*a);
}

void Profesor::asignarNota(Alumno *a,float nota1){
    list <Alumno> :: iterator it;
    for (it = alumnos.begin();it !=alumnos.end();++it) {
        if(strcmp(a->getDNI().c_str(),it->getDNI().c_str())==0){
            it->obtenerNota(nota1);

        }
   }

}
void Profesor::asignarNota2(Alumno *a,float nota1,float nota2){
    list <Alumno> :: iterator it;
    for (it = alumnos.begin();it !=alumnos.end();++it) {
        if(strcmp(a->getDNI().c_str(),it->getDNI().c_str())==0){
            it->obtenerNota(nota1);
            it->obtenerNota(nota2);
        }
   }
}
void Profesor::asignarNota3(Alumno *a,float nota1,float nota2,float nota3){

    list <Alumno> :: iterator it;

    for (it = alumnos.begin();it !=alumnos.end();++it) {
        if(strcmp(a->getDNI().c_str(),it->getDNI().c_str())==0){
            it->obtenerNota(nota1);
            it->obtenerNota(nota2);
            it->obtenerNota(nota3);
        }
    }

}
float Profesor::notaMedia(Alumno *a){
    return  a->notaMediaAlumno();
}

void Profesor::imprimirListado(){
    alumnos.size();
    int numeroDeNotas;

    list <Alumno> :: iterator it2;
    cout<<"**************************************************"<<endl;
    cout<<"Soy el Profesor/a: "<<this->getNombre();
    cout<<"  "<<this->getApellidos()<<endl;
    cout<<"Mi DNI es: "<<this->getDNI()<<endl;
    cout<<"Esta es la lista de mis alumnos:"<<endl;
    cout<<""<<endl;
    for (it2 = alumnos.begin();it2 != alumnos.end();++it2) {
        numeroDeNotas=it2->devolverNumeroNotas();
        string nombre=it2->getNombre();
        string apellidos=it2->getApellidos();
        string DNI=it2->getDNI();
        float media=it2->notaMediaAlumno();
        cout<<"Soy:"<<nombre<<endl;
        cout<<"Me apellido: "<<apellidos<<endl;
        cout<<"Y mi DNI es: "<<DNI<<endl;
        cout<<"Numero de notas: "<<numeroDeNotas<<endl;
        cout<<"Y mis notas son: ";
        it2->imprimirNotas();
        cout<<"Y mi media es: "<<media<<endl;
        cout<<""<<endl;

    }
     cout<<"**************************************************"<<endl;

}
void Profesor::imprimirMejorNota(){
    list <Alumno> :: iterator it;
    float max=0;
    float media;
   // int iterador;
    for (it = alumnos.begin();it !=alumnos.end();++it) {
        if(it->devolverNumeroNotas()==3){
            media=it->notaMediaAlumno();
            if(max<media){
                 max=media;

            }

        }

    }
    for (it = alumnos.begin();it !=alumnos.end();++it) {
    if(max==it->getNotaMedia()){
        string nombre=it->getNombre();
        string apellidos=it->getApellidos();
        string DNI=it->getDNI();
        float media=it->notaMediaAlumno();
       // it2->mejores3();
        cout<<"**************************************************"<<endl;
        cout<<"Soy el alumn@ con mayor media del Profesor: "<<this->getNombre()<<endl;
        cout<<"Soy:"<<nombre<<endl;
        cout<<"Me apellido: "<<apellidos<<endl;
        cout<<"Y mi DNI es: "<<DNI<<endl;
        cout<<"Y mi media es: "<<media<<endl;
        cout<<"**************************************************"<<endl;
     }
}

    }






















void calificando(){
    Alumno *student1= new Alumno("Ismael","Martinez","70891542D");
    Alumno *student2= new Alumno("Luisa","Lorenzana","73291542D");
    Alumno *student3= new Alumno("Marcos","Fernandez","70893488J");
    Alumno *student4= new Alumno("Maria","Garcia","70943488J");
    Profesor *Profesor1=new Profesor("Julia","Alonso","65991150P");
    Profesor *Profesor2=new Profesor("Fernando","Alvarez","60891888X");
    Profesor1->anyadirAlumno(student1);
    Profesor1->anyadirAlumno(student2);
    Profesor1->anyadirAlumno(student3);
    Profesor2->anyadirAlumno(student4);
    Profesor1->asignarNota3(student1, 2, 2, 2);
    Profesor1->asignarNota3(student2, 3, 3, 3);
    Profesor1->asignarNota2(student3, 3, 5);
    Profesor2->asignarNota3(student4, 7.5, 3.5, 4.5);
    Profesor1->imprimirListado();
    Profesor2->imprimirListado();
    Profesor1->imprimirMejorNota();
    Profesor2->imprimirMejorNota();



}


int main()
{
   calificando();
   return 0;
}
