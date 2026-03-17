# Proyecto Controlador - Validación SIL de Turbina

Autor: Jolehisy Acevedo Medina

Este repositorio contiene el código C++ generado a partir de un Gemelo Digital en Simulink para el control de empuje de una turbina.

## Estructura del Proyecto
- `Controlador.c / .h`: Algoritmo de control PID exportado.
- `main.cpp`: Entorno de validación Software-in-the-Loop.
- `parche.c`: Implementación de funciones stub para compatibilidad de librerías.

## Instrucciones de Compilación
Para compilar el proyecto en Windows (usando el compilador de Visual Studio), ejecute:
```cmd
cl /EHsc main.cpp Controlador.c Controlador_data.c rt_nonfinite.c parche.c