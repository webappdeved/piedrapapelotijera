# **📕 GUÍA DE USUARIO Y OPERACIÓN DEL SISTEMA**

**Proyecto:** Mini Juego "Piedra, Papel o Tijera" con Persistencia en Disco

**Institución:** E.E.S.T. N° 999 "Österreichische Schule der Nationalökonomie" — Vicente López

**Asignatura:** Laboratorio de Programación (LPR) — 5° Año

**Docente:** Mansilla Muñoz York Elías (Grupo 99\)

**Autor / Grupo:** Carl Menger (Grupo 99\)

**Versión:** v1.0.0 | **Fecha:** 9 de octubre de 2026

## **📄 CONTROL DE VERSIONES**

| Versión | Fecha | Descripción |
| :---- | :---- | :---- |
| **v1.0.0** | 09/09/2026 | Emisión de la guía inicial del usuario para la versión ejecutable en consola. |

## **💻 1\. REQUISITOS MÍNIMOS DEL SISTEMA**

* **Sistema Operativo:** Windows 10 / Windows 11 (64-bit) o GNU/Linux.  
* **Consola:** Windows PowerShell, Terminal de VS Code o Símbolo del Sistema (CMD).  
* **Memoria RAM:** 512 MB libres.  
* **Almacenamiento Secundario:** 10 MB de espacio libre en disco.

## 

## **🚀 2\. PASO A PASO PARA EJECUTAR Y OPERAR EL JUEGO**

### **Paso 1: Apertura de la Terminal**

Abra la carpeta del proyecto juegopiedra en VS Code o abra una ventana de PowerShell en la dirección física del proyecto.

### **Paso 2: Ejecución del Programa**

Ingrese el comando de ejecución y presione Enter:

.\\src\\repasogeneral.exe

### **Paso 3: Interacción con el Menú Principal**

El sistema mostrará el siguiente menú interactivo en pantalla:

\=====================================================  
  LPR 2026 \- ACTIVIDAD 7: PIEDRA, PAPEL O TIJERA  
  Resolucion de Catedra \- Modelo de Replicacion        
  Estudiante / Grupo: Carl Menger        
\=====================================================

\--- MENU PRINCIPAL DE JUEGO Y PERSISTENCIA \---  
1\. Jugar (Piedra, Papel o Tijera)  
2\. Ver Partidas Guardadas en el Historial del Disco (.txt)  
3\. Salir del Sistema  
Ingresa una opcion (1-3): 

### **Paso 4: Jugar (Opción 1\)**

1. Ingrese 1 y presione Enter.  
2. Escriba su nombre o apodo (ej. Cazador01).  
3. Seleccione su jugada (1. Piedra, 2\. Papel, 3\. Tijera).  
4. El sistema generará la jugada de la IA, mostrará el resultado en pantalla y confirmará la escritura física en disco:

\[DISCO\] Partida resguardada con exito en 'historial\_partidas.txt'.

### **Paso 5: Consultar el Historial (Opción 2\)**

1. Seleccione la Opción 2 para recuperar y visualizar todas las partidas anteriores guardadas en el archivo historial\_partidas.txt.  
2. Verifique que al cerrar y reabrir el programa, el historial permanece intacto.

## 

## **❓ 3\. PREGUNTAS FRECUENTES Y SOLUCIÓN DE PROBLEMAS (FAQ)**

### **1\. ¿Por qué se saltea la pregunta del Nombre del Jugador?**

**Causa:** Falta de limpieza en el búfer de entrada.

**Solución:** Verifique que la función jugarPartida() contenga la llamada cin.ignore() antes de ejecutar getline(cin, p.jugador).

### **2\. ¿Dónde se guardan mis partidas?**

Los datos se almacenan automáticamente en el archivo plano src/historial\_partidas.txt en formato separado por comas (CSV).