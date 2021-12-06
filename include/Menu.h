#ifndef MENU_H_
#define MENU_H_

class Menu
{
  private:
  Admin* ptr_admins ;
  Alumno* ptr_alumns ;
  Profesor* ptr_profes ;
  int contD, contA, contP, var1,var2,var3;

  public:
  Menu(/*int, int, int*/);
  ~Menu();
  bool loginAdmin(int, string);
  bool loginAlumno(int, string);
  bool loginProf(int, string);
  void menuPrincipal();
  void menuAdmin();
  void menuProf();
  void menuAlumno();
  void cargarDatos();
  void cargarDatosA();
  void cargarDatosP();
  void cargarDatosD();
  void guardarDatos();
  void guardarDatosA();
  void guardarDatosD();
  void guardarDatosP();

  //ADMIN
    //CREAR_NUEVO_USUARIO
      void crearAdmin();
      void crearProf();
      void crearAlumno();
      void crearUsuario();
    //ELIMINAR_USUARIO
      void eliminarUsuario();
      void eliminarAdmin();
      void eliminarAlumno();
      void eliminarProf();
    //VER_USUARIO
      void verUsuario();
      void verAdmin();
      void verAlumno();
      void verProf();
    //MODIFICAR_DATOS_TODO_USUARIO
      void modificarUsuario();
      void modificarAdmin();
      void modificarAlumno();
      void modificarProf();
    //BUSCAR_USUARIO
      void buscarAdmin();
      void buscarAlumno();
      void buscarProf();
      void buscarUsuario();

  //PROF
    //MODIFICAR_DATOS_PER
      void modificarDatosP(int);
    //MODIFICAR_NOTAS
      void modificarNotas();
    //VER_DATOS_PER
      void mostrarDatosP(int); 

  //ALUMNO
    //MODIFICAR_DATOS_PER
      void modificarDatosA(int);
    //VER_DATOS_PER
      void mostrarDatosA(int);

  //VER_DATOS_USUARIO_ALUM_PROFE
      void mostrarDatosD();
      void mostrarDatosA();
      void mostrarDatosP(); 
      void mostrarDatosUsu(); 
  
};

void error();

#endif