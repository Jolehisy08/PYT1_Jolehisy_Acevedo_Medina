#include <iostream> 

extern "C" {
    #include "Controlador.h"
}

int main() {
// 1. Inicializamos (t = 0)
    Controlador_initialize();

    // 2. Metemos el error que veías en el segundo 3
    Controlador_U.ThrustsetpointN = 8000.0; 
    Controlador_U.ThrustmedidoN = 75.47; 

    Controlador_step();
    Controlador_step();

    // 4. Imprimimos el resultado exacto en t = 3s
    std::cout << "--- Validacion SIL del Controlador (t = 0.01s) ---" << std::endl;
    std::cout << "Consigna de Empuje : " << Controlador_U.ThrustsetpointN << " N" << std::endl;
    std::cout << "Empuje Medido      : " << Controlador_U.ThrustmedidoN << " N" << std::endl;
    std::cout << "--> Comando de Valvula (Throttle): " << Controlador_Y.Sealdecontrol << std::endl;

    return 0;
}