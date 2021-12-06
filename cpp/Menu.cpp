#include "../include/liberman.h"

Menu :: Menu(/*int nAdmins, int nAlumns, int nProf*/)
{
  ptr_admins = new Admin[30];
  ptr_profes = new Profesor[100];
  ptr_alumns = new Alumno[100];
  contD = 1;
  contA = 0;
  contP = 0;
  var1=0;
  var2=0;
  var3=0;
  
  ptr_admins[0] = Admin(0, "Admin god", "admingoddd", "563746298", "admin.god@ucsp.edu.pe", "976453433", "urb el cielo", "Solterosky");
}

Menu :: ~Menu()
{
  delete []ptr_admins;
  delete []ptr_alumns;
  delete []ptr_profes;
}

bool Menu:: loginAdmin(int auxcodigo, string auxcontra)
{
  std::cout << "\033[H\033[2J\033[3J";
  if (ptr_admins[(auxcodigo)].getContrasena() == auxcontra)
  {
    return true;
  }
  return false;
}

bool Menu::loginAlumno(int auxcodigo, string auxcontra)
{
  std::cout << "\033[H\033[2J\033[3J";  
  if(ptr_alumns[(auxcodigo-1)].getContrasena()==auxcontra)
  {
    return true;
  }
  return false;
}

bool Menu::loginProf(int auxcodigo, string auxcontra)
{
  std::cout << "\033[H\033[2J\033[3J";  
  if (ptr_profes[(auxcodigo-1)].getContrasena() == auxcontra)
  {
    return true;
  }
  return false;
}

void Menu::cargarDatosA()
{
  ifstream alumnos_carga;
  alumnos_carga.open("alumns.txt",ios::in);
  string auxContrasena, auxNombres,auxCorreoInsti, auxApellidos,auxDNI,auxCelular,auxDireccion,auxEstadoCiv,auxCarrera,auxCursos,auxPeriodoIngreso,auxSemestre,auxCreditosSemestre,auxCreditosAcumulados,auxMensualidad;
  int auxCodigo;

  if(alumnos_carga.fail())
  {
    exit(1);
  }

  if (alumnos_carga.is_open()){
    int indice = 0;
    while(!alumnos_carga.eof())
    { 
      alumnos_carga>>contA;
      alumnos_carga>>auxCodigo;
      alumnos_carga>>auxContrasena;
      alumnos_carga>>auxNombres;
      alumnos_carga>>auxApellidos;
      alumnos_carga>>auxDNI;
      alumnos_carga>>auxCorreoInsti;
      alumnos_carga>>auxCelular;
      alumnos_carga>>auxDireccion;
      alumnos_carga>>auxEstadoCiv;
      alumnos_carga>>auxCarrera;
      alumnos_carga>>auxCursos;
      alumnos_carga>>auxPeriodoIngreso;
      alumnos_carga>>auxSemestre;
      alumnos_carga>>auxCreditosSemestre;
      alumnos_carga>>auxCreditosAcumulados;
      alumnos_carga>>auxMensualidad;

      if (indice <= contA) {
        ptr_alumns[indice] = Alumno(auxCodigo,auxContrasena, auxNombres, auxApellidos, auxDNI, auxCorreoInsti,auxCelular,auxDireccion, auxEstadoCiv,auxCarrera,auxCursos,auxPeriodoIngreso,auxSemestre,auxCreditosSemestre,auxCreditosAcumulados,auxMensualidad);
      }
      indice++;
    }
      alumnos_carga.close();
  }

  
  // for(int i = 0; i < contaA; i++)
  // {
  //   ptr_alumns[i] = Alumno(auxCodigo,auxContrasena, auxNombres, auxApellidos, auxDNI, auxCorreoInsti,auxCelular,auxDireccion, auxEstadoCiv,auxCarrera,auxCursos,auxPeriodoIngreso,auxSemestre,auxCreditosSemestre,auxCreditosAcumulados,auxMensualidad);
  // }
  // var2=contA+contA;
  // }
  // alumnos_carga.close();
}

void Menu::cargarDatosP()
{
  ifstream profesor_carga;
  profesor_carga.open("profesores.txt",ios::in);
  string auxContrasena, auxNombres,auxCorreoInsti, auxApellidos,auxDNI,auxCelular,auxDireccion,auxEstadoCiv,auxCursoEnsena,auxSueldo,auxPerfilProf,auxSuplente;
  int auxCodigo;

  if(profesor_carga.fail())
  {
    exit(1);
  }

  if (profesor_carga.is_open()){
    int indice = 0;
    while(!profesor_carga.eof())
    { 
      profesor_carga >> contP;
      profesor_carga >> auxCodigo;
      profesor_carga >> auxContrasena;
      profesor_carga >> auxNombres;
      profesor_carga >> auxApellidos;
      profesor_carga >> auxDNI;
      profesor_carga >> auxCorreoInsti;
      profesor_carga >> auxCelular;
      profesor_carga >> auxDireccion;
      profesor_carga >> auxEstadoCiv;
      profesor_carga >> auxCursoEnsena;
      profesor_carga >> auxSueldo;
      profesor_carga >> auxPerfilProf;
      profesor_carga >> auxSuplente;

      if (indice <= contP) {
        ptr_profes[indice] = Profesor(auxCodigo,auxContrasena, auxNombres, auxApellidos, auxDNI, auxCorreoInsti,auxCelular,auxDireccion, auxEstadoCiv,auxCursoEnsena,auxSueldo,auxPerfilProf,auxSuplente);
      }
      indice++;
    }
    profesor_carga.close();
  }
  //for(int i = 0; i < contaP; i++)
  /*{
    ptr_profes[i] = Profesor(auxCodigo,auxContrasena, auxNombres, auxApellidos, auxDNI, auxCorreoInsti,auxCelular,auxDireccion, auxEstadoCiv,auxCursoEnsena,auxSueldo,auxPerfilProf,auxSuplente);
  }*/
  // var3=contP+contP;
}

void Menu::cargarDatosD()
{
  ifstream admins_carga;
  admins_carga.open("admins.txt",ios::in);
  string auxContrasena, auxNombres,auxCorreoInsti, auxApellidos,auxDNI,auxCelular,auxDireccion,auxEstadoCiv;
  int contaD, auxCodigo;
  
  if(admins_carga.fail())
  {
    exit(1);
  }

  if (admins_carga.is_open()){
    int indice = 0;
    while(!admins_carga.eof())
    { 
      admins_carga>>contaD;
      admins_carga>>auxCodigo;
      admins_carga>>auxContrasena;
      admins_carga>>auxNombres;
      admins_carga>>auxApellidos;
      admins_carga>>auxDNI;
      admins_carga>>auxCorreoInsti;
      admins_carga>>auxCelular;
      admins_carga>>auxDireccion;
      admins_carga>>auxEstadoCiv;

      if (indice <= contD) {
        ptr_admins[indice] = Admin(auxCodigo, auxNombres, auxApellidos, auxDNI, auxCorreoInsti,auxCelular,auxDireccion, auxEstadoCiv);
      }
      indice++;
    }
    admins_carga.close();
  }
  //var1=contaD+contaD;
}

void Menu::cargarDatos()
{
  cargarDatosA();
  cargarDatosD();
  cargarDatosP(); 
}

void Menu :: guardarDatosA()
{
  ofstream auxiliar;
  auxiliar.open("auxiliar.txt",ios::out);
  for(int i = 0; i < contA; i++)
  {
    auxiliar<< contA <<endl;
    auxiliar<< ptr_alumns[i].getCodigo()<<endl;
    auxiliar<< ptr_alumns[i].getContrasena()<<endl;
    auxiliar<< ptr_alumns[i].getNombres()<<endl;
    auxiliar<< ptr_alumns[i].getApellidos()<<endl;
    auxiliar<< ptr_alumns[i].getDNI()<<endl;
    auxiliar<< ptr_alumns[i].getCorreoInsti()<<endl;
    auxiliar<< ptr_alumns[i].getCelular()<<endl;
    auxiliar<< ptr_alumns[i].getDireccion()<<endl;
    auxiliar<< ptr_alumns[i].getEstadoCiv()<<endl;
    auxiliar<< ptr_alumns[i].getCarrera()<<endl;
    auxiliar<< ptr_alumns[i].getCursos()<<endl;
    auxiliar<< ptr_alumns[i].getPeriodoIngreso()<<endl;
    auxiliar<< ptr_alumns[i].getSemestre()<<endl;
    auxiliar<< ptr_alumns[i].getCreditosSemestre()<<endl;
    auxiliar<< ptr_alumns[i].getCreditosAcumulados()<<endl;
    auxiliar<< ptr_alumns[i].getMensualidad()<<endl;
  }
  auxiliar.close();
  remove("alumns.txt");
  rename("auxiliar.txt","alumns.txt");
}

void Menu :: guardarDatosP()
{
  ofstream auxiliar;
  auxiliar.open("auxiliar.txt",ios::out);
  for(int i = 0; i < contP; i++)
  {
    auxiliar<< contP <<endl;
    auxiliar<< ptr_profes[i].getCodigo()<<endl;
    auxiliar<< ptr_profes[i].getContrasena()<<endl;
    auxiliar<< ptr_profes[i].getNombres()<<endl;
    auxiliar<< ptr_profes[i].getApellidos()<<endl;
    auxiliar<< ptr_profes[i].getDNI()<<endl;
    auxiliar<< ptr_profes[i].getCorreoInsti()<<endl;
    auxiliar<< ptr_profes[i].getCelular()<<endl;
    auxiliar<< ptr_profes[i].getDireccion()<<endl;
    auxiliar<< ptr_profes[i].getEstadoCiv()<<endl;
    auxiliar<< ptr_profes[i].getCursoEnsena()<<endl;
    auxiliar<< ptr_profes[i].getSueldo()<<endl;
    auxiliar<< ptr_profes[i].getPerfilProf()<<endl;
    auxiliar<< ptr_profes[i].getSuplente()<<endl;
  }
  auxiliar.close();
  remove("profesores.txt");
  rename("auxiliar.txt","profesores.txt");
}

void Menu :: guardarDatosD()
{
  ofstream auxiliar;
  auxiliar.open("auxiliar.txt",ios::out);
  for(int i = 1; i < contD; i++)
  {
    auxiliar<< contD <<endl;
    auxiliar<< ptr_admins[i].getCodigo()<<endl;
    auxiliar<< ptr_admins[i].getContrasena()<<endl;
    auxiliar<< ptr_admins[i].getNombres()<<endl;
    auxiliar<< ptr_admins[i].getApellidos()<<endl;
    auxiliar<< ptr_admins[i].getDNI()<<endl;
    auxiliar<< ptr_admins[i].getCorreoInsti()<<endl;
    auxiliar<< ptr_admins[i].getCelular()<<endl;
    auxiliar<< ptr_admins[i].getDireccion()<<endl;
    auxiliar<< ptr_admins[i].getEstadoCiv()<<endl;
  }
  auxiliar.close();
  remove("admins.txt");
  rename("auxiliar.txt","admins.txt");
}

void Menu :: guardarDatos()
{
  guardarDatosA();
  guardarDatosP();
  guardarDatosD();
}

void Menu :: menuAdmin()
{
  int auxcodigo; string auxcontra;
  cout <<endl << "Ingrese su código: " ;
  cin >> auxcodigo;
  cout <<endl << "Ingrese su contraseña: " ;
  cin >> auxcontra;
  
  if(loginAdmin(auxcodigo,auxcontra))
  {
    int op;
    do
    {
      cout << "***********************************************************"<<endl;
      cout << "****       Universidad las chicas superpoderosas       ****"<<endl;
      cout << "****                  ADMINISTRADOR                    ****"<<endl;
      cout << "****  Número de admin: " << contD <<"                               ****"<< endl;
      cout << "****  Número de alumns: " << contA<<"                              ****" << endl;
      cout << "****  Número de profes: " << contP <<"                              ****"<< endl;
      cout << "****  [1] Crear Usuario                                ****" << endl;
      cout << "****  [2] Modificar Usuario                            ****" << endl;
      cout << "****  [3] Mostrar Lista de Usuarios                    ****" << endl;
      cout << "****  [4] Eliminar Usuario                             ****" << endl;
      cout << "****  [5] Buscar Usuario                               ****" << endl;    
      cout << "****  [6] Salir                                        ****" << endl;
      cout << "****  Elija una opción...                              ****" << endl;
      cout << "***********************************************************";
      cin >> op;
      
      std::cout << "\033[H\033[2J\033[3J";

      switch (op)
      {
        case 1:
        {
          crearUsuario();
          break;
        }
        case 2:
        {
          modificarUsuario();
          break;
        }
        case 3:
        {
          verUsuario();
          break;
        }
        case 4:
        {
          eliminarUsuario();
          break;
        }
        case 5:
        {
          buscarUsuario();
          break;
        }
        case 6:
        {
          break;
        }
        default:
        {
          cout << "Opción no válida" << endl;
          break;
        }
      }
    }
    while(op != 6 );
  }

}

void Menu :: menuProf()
{ 
  int auxcodigo; string auxcontra; 
  cout<<endl<<"Ingrese su código: ";
  cin>>auxcodigo;
  cout<<endl<<"ingrese su contraseña: ";
  cin>>auxcontra;

  if(loginProf(auxcodigo,auxcontra ))
  {
    int opc;
    do
    {
      cout << "***********************************************************"<<endl;
      cout << "****       Universidad las chicas superpoderosas       ****"<<endl;
      cout << "****                   PROFESOR                        ****"<<endl;
      cout << "****  [1] Modificar datos personales                   ****" << endl;
      cout << "****  [2] Modificar notas                              ****" << endl;
      cout << "****  [3] Mostrar Usuario                              ****" << endl;
      cout << "****  [4] Mostrar datos Propios                        ****" << endl;
      cout << "****  [5] Salir                                        ****" << endl;
      cout << "****  Elija una opción...                              ****" << endl;
      cout << "***********************************************************"<<endl;
      cin >> opc;
      std::cout << "\033[H\033[2J\033[3J";

      switch (opc)
      {
        case 1:
        {
          modificarDatosP(auxcodigo);
          break;
        }
        case 2:
        {
          //modificarNotas();
          break;
        }
        case 3:
        {
          mostrarDatosUsu();
          break;
        }
        case 4:
        {
          mostrarDatosP(auxcodigo);
        }
        case 5:
        {
          break;
        }
        default:
        {
          cout << "Opción no válida" << endl;

          break;
        }
      }
    }
    while(opc != 5 );
  }

}

void Menu :: menuAlumno()
{
  int auxcodigo; string auxcontra;
  cout<<endl<<"Ingrese su código: ";
  cin >> auxcodigo;
  cout<<endl<<"Ingrese su contraseña: " ;
  cin>>auxcontra;
  if(loginAlumno(auxcodigo, auxcontra))
  {
    int opc;
    do
    {
      cout << "***********************************************************"<<endl;
      cout << "****       Universidad las chicas superpoderosas       ****"<<endl;
      cout << "****                    ALUMNO                         ****"<<endl;
      cout << "****  [1] Modificar datos personales                   ****" << endl;
      cout << "****  [2] Mostrar Datos Personales                     ****" << endl;
      cout << "****  [3] Mostrar Usuario                              ****" << endl;
      cout << "****  [4] Salir                                        ****" << endl;
      cout << "****  Elija una opción...                              ****" << endl;
      cout << "***********************************************************"<<endl;
      cin >> opc;
      std::cout << "\033[H\033[2J\033[3J";
      switch (opc)
      {
        case 1:
        {
          modificarDatosA(auxcodigo);
          break;
        }
        case 2:
        {
          mostrarDatosA(auxcodigo);
          break;
        }
        case 3:
        {
          mostrarDatosUsu();
          break;
        }
        case 4:
        {
          break;
        }
        default:
        {
          cout << "Opción no válida" << endl;

          break;
        }
      }
    }
    while(opc != 4 );
  }
}

void Menu :: menuPrincipal()
{
  int opc;
  do
  {
    cout << "***********************************************************"<<endl;
    cout << "****       Universidad las chicas superpoderosas       ****"<<endl;
    cout << "****    [1] Administrador                              ****" << endl;
    cout << "****    [2] Profesor                                   ****" << endl;
    cout << "****    [3] Alumno                                     ****" << endl;
    cout << "****    [4] Salir                                      ****" << endl;
    cout << "****    Elija una opción...                            ****" << endl;
    cout << "***********************************************************"<<endl;
    cin >> opc;
    std::cout << "\033[H\033[2J\033[3J";
    
    switch  (opc)
		{
      case 1:
      {
        menuAdmin();
        break;
      }
      case 2:
      {
        menuProf();
        break;
      }
      case 3:
      {
        menuAlumno();
        break;
      }
      case 4:
      {
        cout << "\t\t**BASE DE DATOS FINALIZADA\t\t**";
        guardarDatos();
        break;
      }
      default:
      {
        cout << "Opción no válida" << endl;
        break;
      }
    }
  }
  while(opc != 4 );
}

