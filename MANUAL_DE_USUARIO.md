# MANUAL DE USUARIO
## Sistema de Matriculación Vehicular

### Proyecto de Programación I
**Fecha:** Julio 2025  
**Versión:** 3.1

---

## TABLA DE CONTENIDOS

1. [Introducción](#introducción)
2. [Características del Sistema](#características-del-sistema)
3. [Requisitos del Sistema](#requisitos-del-sistema)
4. [Instalación y Ejecución](#instalación-y-ejecución)
5. [Guía de Uso](#guía-de-uso)
6. [Funcionalidades Principales](#funcionalidades-principales)
7. [Cálculos del Sistema](#cálculos-del-sistema)
8. [Archivos Generados](#archivos-generados)
9. [Solución de Problemas](#solución-de-problemas)
10. [Especificaciones Técnicas](#especificaciones-técnicas)

---

## INTRODUCCIÓN

El **Sistema de Matriculación Vehicular** es una aplicación desarrollada en C/C++ que permite gestionar el proceso de matriculación de vehículos, calcular los costos asociados y generar comprobantes de pago. El sistema está diseñado para ser utilizado por administradores autorizados en entidades de tránsito.

### Objetivos del Sistema
- Automatizar el proceso de matriculación vehicular
- Calcular tarifas e impuestos de manera precisa
- Generar comprobantes oficiales
- Mantener registros organizados de vehículos matriculados
- Implementar un sistema de autenticación seguro

---

## CARACTERÍSTICAS DEL SISTEMA

### ✅ **Funcionalidades Principales**
- **Gestión de Administradores:** Registro y autenticación de usuarios
- **Registro de Vehículos:** Captura completa de datos vehiculares
- **Cálculo Automático:** Determinación de tarifas e impuestos
- **Búsqueda de Vehículos:** Localización por número de placa
- **Generación de Comprobantes:** Documentos oficiales de matriculación
- **Persistencia de Datos:** Almacenamiento en archivos de texto

### ✅ **Validaciones Implementadas**
- Validación de formato de placa vehicular (ABC1234)
- Verificación de cédulas (10 dígitos numéricos)
- Validación de rangos de avalúo y cilindraje
- Control de años de fabricación (1900-2025)
- Verificación de revisiones técnicas

---

## REQUISITOS DEL SISTEMA

### **Hardware Mínimo**
- Procesador: Intel Pentium 4 o equivalente
- Memoria RAM: 512 MB
- Espacio en disco: 50 MB
- Sistema operativo: Windows 7 o superior

### **Software Requerido**
- Compilador C/C++ (MinGW, GCC, o Visual Studio)
- Windows PowerShell (incluido en Windows)

---

## INSTALACIÓN Y EJECUCIÓN

### **Opción 1: Usar Ejecutable Precompilado**
```powershell
# Navegar a la carpeta del proyecto
cd "c:\Users\Jorge\Downloads\Proyecto-Programacion-1-Avance-3.1\Debug"

# Ejecutar el programa
.\MyProject.exe
```

### **Opción 2: Compilar desde Código Fuente**
```powershell
# Navegar a la carpeta del proyecto
cd "c:\Users\Jorge\Downloads\Proyecto-Programacion-1-Avance-3.1"

# Compilar (requiere compilador instalado)
g++ -o programa main.cpp libfunciones.c login_de_usuario.c menuprincipal.c

# Ejecutar
.\programa.exe
```

---

## GUÍA DE USO

### **1. Inicio del Sistema**

Al ejecutar el programa, aparecerá el menú principal de administración:

```
------------------------------------
Sistema de Administracion
------------------------------------
0. Salir
1. Registrar administrador
2. Iniciar sesion como administrador
------------------------------------
Seleccione una opcion:
```

### **2. Primer Uso - Registro de Administrador**

**Paso 1:** Seleccionar opción `1` para registrar un nuevo administrador

**Paso 2:** Ingresar los datos solicitados:
- **Nombre del administrador:** Solo letras y espacios
- **Contraseña:** Mínimo 6 caracteres

**Validaciones:**
- El nombre no puede contener números o símbolos
- No se permiten nombres duplicados
- La contraseña debe tener al menos 6 caracteres

### **3. Inicio de Sesión**

**Paso 1:** Seleccionar opción `2` para iniciar sesión

**Paso 2:** Ingresar credenciales:
- Nombre del administrador registrado
- Contraseña correspondiente

**Resultado:** Si las credenciales son correctas, accederá al menú principal del sistema.

---

## FUNCIONALIDADES PRINCIPALES

### **🚗 1. REGISTRAR VEHÍCULO**

Esta función permite ingresar un nuevo vehículo al sistema.

#### **Datos Requeridos:**

**A. Datos del Propietario:**
- **Nombre:** Solo letras y espacios
- **Cédula:** Exactamente 10 dígitos numéricos

**B. Datos del Vehículo:**
- **Placa:** Formato ABC1234 (3 letras + 4 números, sin guión)
- **Año de fabricación:** Entre 1900 y 2025
- **Avalúo:** Valor entre $1 y $900,000
- **Cilindraje:** Entre 1 y 110,000 centímetros cúbicos

**C. Clasificación del Vehículo:**
- **Tipo de combustible:**
  - `0` = Eléctrico
  - `1` = Combustible
- **Peso del vehículo:**
  - `0` = Liviano
  - `1` = Pesado
- **Revisiones técnicas anuales:** Entre 0 y 366

#### **Ejemplo de Registro:**
```
Nombre del propietario: Juan Carlos Pérez
Cédula: 1234567890
Placa: ABC1234
Año: 2020
Avalúo: 25000.00
Cilindraje: 1800
Tipo: 1 (Combustible)
Peso: 0 (Liviano)
Revisiones técnicas: 2
```

### **💰 2. CALCULAR MATRÍCULA**

Esta función calcula el costo total de matriculación para un vehículo específico.

#### **Proceso:**
1. Ingresar la placa del vehículo a consultar
2. El sistema busca el vehículo en los registros
3. Se calculan automáticamente todos los impuestos y tarifas
4. Se muestra el desglose completo de costos
5. Opción de generar comprobante de pago

#### **Ejemplo de Cálculo:**
```
--- DETALLES DE MATRICULA ---
Placa: ABC1234
Año: 2020 (Edad: 5 años)
Cilindraje: 1800
Avalúo: 25000.00
Tipo: Combustible
Impuesto verde: 24.00 $
Multa por falta de revisiones técnicas: 50 $
Total a pagar: 306.00 $
```

### **🔍 3. BUSCAR VEHÍCULO POR PLACA**

Permite localizar un vehículo específico usando su número de placa.

#### **Información Mostrada:**
- Nombre del propietario
- Cédula del propietario
- Placa del vehículo
- Año de fabricación
- Avalúo
- Cilindraje
- Tipo de combustible
- Clasificación por peso

### **💾 4. GUARDAR LISTA DE DATOS**

Exporta todos los registros del sistema a un archivo de texto.

#### **Características:**
- Archivo generado: `vehiculos_registrados.txt`
- Formato organizado con separadores
- Incluye todos los datos de propietarios y vehículos
- Útil para respaldos y reportes

### **🚪 5. SALIR**

Cierra el sistema de manera segura.

---

## CÁLCULOS DEL SISTEMA

### **📊 Fórmulas de Cálculo**

#### **1. Tarifa por Cilindraje**
```
≤ 1500 cc     = 0.0%
1501-2000 cc  = 8.0%
2001-2500 cc  = 9.0%
2501-3000 cc  = 11.0%
3001-3500 cc  = 12.0%
3501-4000 cc  = 24.0%
> 4000 cc     = 35.0%
```

#### **2. Tarifa por Edad del Vehículo**
```
≤ 5 años      = 0.0%
6-10 años     = 5.0%
11-15 años    = 10.0%
16-20 años    = 15.0%
> 20 años     = 20.0%
```

#### **3. Impuesto Verde**
- **Vehículos Eléctricos:** $0 (exentos)
- **Vehículos de Combustible:** 
  ```
  Impuesto Verde = ((Cilindraje - 1500) × Tarifa_Cilindraje) × (1 + Tarifa_Edad)
  ```

#### **4. Multa por Revisiones Técnicas**
```
Si revisiones < 3:
Multa = $50 × (3 - número_de_revisiones)
```

#### **5. Cálculo Total**
```
Total = Impuesto Verde + (Avalúo ÷ 100) + $22 + $10 + Multa_Revisiones
```

**Donde:**
- $22 = Tasa administrativa
- $10 = Seguro obligatorio

---

## ARCHIVOS GENERADOS

### **📁 Archivos del Sistema**

#### **1. admins.txt**
- **Propósito:** Almacena credenciales de administradores
- **Formato:** `nombre|contraseña`
- **Ejemplo:**
  ```
  Juan Pérez|admin123
  María García|segura456
  ```

#### **2. vehiculos_registrados.txt**
- **Propósito:** Registro completo de vehículos matriculados
- **Contenido:** Datos del propietario y vehículo
- **Formato:** Texto estructurado con separadores

#### **3. comprobante_[PLACA].txt**
- **Propósito:** Comprobante oficial de matriculación
- **Nombre:** Se genera con la placa del vehículo
- **Ejemplo:** `comprobante_ABC1234.txt`
- **Contenido:**
  ```
  --- COMPROBANTE DE MATRÍCULA ---
  Nombre: Juan Carlos Pérez
  Cédula: 1234567890
  Placa: ABC1234
  Año: 2020 (Edad: 5 años)
  Avalúo: 25000.00
  Cilindraje: 1800
  Tipo: Combustible
  Peso: Liviano
  Impuesto verde: 24.00 $
  Total a pagar: 306.00 $
  -------------------------------
  ```

---

## SOLUCIÓN DE PROBLEMAS

### **❗ Errores Comunes y Soluciones**

#### **1. "Error: Entrada inválida"**
- **Causa:** Datos ingresados no cumplen con el formato requerido
- **Solución:** Verificar el formato correcto según las validaciones del sistema

#### **2. "Admin no encontrado"**
- **Causa:** Credenciales incorrectas o administrador no registrado
- **Solución:** Verificar nombre de usuario y contraseña, o registrar nuevo administrador

#### **3. "No se encontró un auto con la placa..."**
- **Causa:** La placa buscada no existe en el sistema
- **Solución:** Verificar que la placa esté correctamente escrita y que el vehículo haya sido registrado

#### **4. "Error al abrir el archivo"**
- **Causa:** Problemas de permisos o espacio en disco
- **Solución:** Verificar permisos de escritura en la carpeta del programa

#### **5. "Ingrese una placa válida"**
- **Causa:** Formato de placa incorrecto
- **Solución:** Usar formato ABC1234 (3 letras mayúsculas + 4 números, sin guión)

### **🔧 Consejos de Uso**

1. **Respaldo Regular:** Copie los archivos .txt generados periódicamente
2. **Validación de Datos:** Revise cuidadosamente los datos antes de confirmar
3. **Comprobantes:** Guarde los comprobantes generados para registros oficiales
4. **Cierre Seguro:** Use siempre la opción "Salir" para cerrar el programa

---

## ESPECIFICACIONES TÉCNICAS

### **🔧 Arquitectura del Sistema**

#### **Archivos Principales:**
- **`main.cpp`** - Función principal y lógica de negocio
- **`libfunciones.h/c`** - Funciones de validación y estructuras de datos
- **`menuprincipal.c`** - Interface de usuario y menús
- **`login_de_usuario.c`** - Funciones de autenticación

#### **Estructuras de Datos:**
```c
// Estructura para vehículos
typedef struct {
    char nombre[50];        // Nombre del propietario
    char placa[12];         // Placa del vehículo
    char anio[10];          // Año de fabricación
    char cedula[20];        // Cédula del propietario
    float avaluo;           // Valor del vehículo
    int cilindraje;         // Cilindraje en cc
    int tipo;               // 0=Eléctrico, 1=Combustible
    int peso;               // 0=Liviano, 1=Pesado
    int revisionesTecnicas; // Número de revisiones anuales
} matricula;

// Estructura para administradores
typedef struct {
    char nombre_del_registrador[50]; // Nombre del administrador
    char contrasenia[20];            // Contraseña
} PQR;
```

#### **Límites del Sistema:**
- Máximo de registros simultáneos: 135 vehículos
- Longitud máxima de nombre: 50 caracteres
- Longitud de contraseña: 6-20 caracteres
- Rango de avalúo: $1 - $900,000
- Rango de cilindraje: 1 - 110,000 cc

---

## INFORMACIÓN ADICIONAL

### **📞 Soporte Técnico**
Para consultas técnicas o reportes de errores, contacte al equipo de desarrollo del proyecto.

### **📋 Historial de Versiones**
- **v3.1** - Versión actual con todas las funcionalidades implementadas
- Incluye validaciones mejoradas y generación de comprobantes

### **⚖️ Consideraciones Legales**
Este sistema es un proyecto académico. Para uso en producción, considere:
- Implementación de base de datos
- Cifrado de contraseñas
- Auditoría de transacciones
- Cumplimiento de normativas locales

---

**© 2025 - Sistema de Matriculación Vehicular - Proyecto de Programación I**
