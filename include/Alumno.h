#ifndef ALUM_H_
#define ALUM_H_

class Alumno : public Usuario 
{
  private: 
  string carrera;
  string cursos; 
  string periodoIngreso;
  string semestre;
  string creditosSemestre;
  string creditosAcumulados;
  string notas;
  string mensualidad; 
  
  public:
  Alumno();
  Alumno(int, string ,string ,string ,string ,string ,string ,string ,string,string, string, string, string,string,string,string);
  ~Alumno();
  void datos();
  //Getters
  string getCarrera(){return this->carrera;}
  string getCursos(){return this->cursos;}
  string getPeriodoIngreso(){return this->periodoIngreso;}
  string getSemestre(){return this->semestre; } 
  string getCreditosSemestre(){return this->creditosSemestre;}
  string getCreditosAcumulados(){return this->creditosAcumulados;}
  string getMensualidad(){ return this->mensualidad;}

  //Setters
  void setDatosPer( string ,string ,string ,string ,string ,string);
  void setAlumno( string, string, string ,string ,string ,string ,string ,string ,string, string, string, string, string, string,string);
  void setCodigo(int);
};

#endif