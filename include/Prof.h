#ifndef PROFESOR_H_
#define PROFESOR_H_

class Profesor : public Usuario
{
  private: 
  string	cursosEnsena;
	string	sueldo;
	string	perfilProf;
	string	suplente;

  public:
  Profesor();
  Profesor(int, string,string ,string ,string ,string ,string ,string ,string, string, string, string, string);
  ~Profesor();

  //getter
    string getCursoEnsena(){return this->cursosEnsena;}
    string getSueldo(){return this->sueldo;}
    string getPerfilProf(){return this->perfilProf;}
    string getSuplente(){return this->suplente;} 

  //setter
  void datos();
  void setProfesor(string, string ,string ,string ,string ,string ,string, string, string, string, string);
  void setDatosPer( string ,string ,string ,string ,string ,string);
  void setCodigo(int);
};

#endif