# REGISTRO DE ERRORES Y EXCEPCIONES
## Sistema de Matriculación Vehicular

### Documento de Soporte Técnico
**Fecha:** Julio 2025  
**Versión:** 3.1

---

## ÍNDICE DE ERRORES

1. [Errores de Validación de Entrada](#errores-de-validación-de-entrada)
2. [Errores de Autenticación](#errores-de-autenticación)
3. [Errores de Archivo](#errores-de-archivo)
4. [Errores de Cálculo](#errores-de-cálculo)
5. [Errores de Sistema](#errores-de-sistema)
6. [Errores de Flujo del Programa](#errores-de-flujo-del-programa)
7. [Códigos de Error Internos](#códigos-de-error-internos)

---

## ERRORES DE VALIDACIÓN DE ENTRADA

### **ERROR_001: Entrada Inválida - Datos Alfanuméricos**
```
Mensaje: "Error: Entrada invalida. Intente nuevamente."
Contexto: Al ingresar avalúo o cilindraje
```
**Causa:** Usuario ingresa letras en campos numéricos  
**Ejemplo:**
```
Ingrese el avaluo del vehiculo a matricular: 
> abc123
Error: Entrada invalida. Intente nuevamente.
```
**Solución:** Ingresar solo números válidos

---

### **ERROR_002: Formato de Placa Incorrecto**
```
Mensaje: "Ingrese placa valida (ABC1234 sin guion)."
Contexto: Validación de placa vehicular
```
**Causa:** Placa no cumple formato ABC1234  
**Ejemplos de entrada incorrecta:**
```
> AB1234     (Solo 2 letras)
> ABC12345   (5 números)
> ABC-1234   (Con guión)
> 123ABC4    (Números antes que letras)
> abc1234    (Letras minúsculas)
```
**Solución:** Usar exactamente 3 letras mayúsculas seguidas de 4 números

---

### **ERROR_003: Cédula Inválida**
```
Mensaje: "Ingrese una cedula valida (10 digitos-solo numeros)."
Contexto: Validación de cédula del propietario
```
**Causa:** Cédula no tiene exactamente 10 dígitos numéricos  
**Ejemplos incorrectos:**
```
> 123456789    (9 dígitos)
> 12345678901  (11 dígitos)
> 123ABC7890   (Contiene letras)
> 123-456-789  (Con guiones)
```
**Solución:** Ingresar exactamente 10 dígitos numéricos

---

### **ERROR_004: Nombre con Caracteres Inválidos**
```
Mensaje: "Ingrese solo letras."
Contexto: Validación de nombre del propietario
```
**Causa:** Nombre contiene números o símbolos  
**Ejemplos incorrectos:**
```
> Juan123
> María@García
> Pedro-Luis
> Ana_Sofia
```
**Solución:** Usar solo letras y espacios

---

### **ERROR_005: Año de Fabricación Fuera de Rango**
```
Mensaje: "Ingrese un anio valido 1900-2025."
Contexto: Validación del año del vehículo
```
**Causa:** Año menor a 1900 o mayor a 2025  
**Ejemplos incorrectos:**
```
> 1899
> 2026
> 85    (Año incompleto)
```
**Solución:** Ingresar año entre 1900 y 2025

---

### **ERROR_006: Avalúo Fuera de Rango**
```
Mensaje: "Ingrese un avaluo valido."
Contexto: Validación del valor del vehículo
```
**Causa:** Avalúo menor o igual a 0, o mayor a $900,000  
**Ejemplos incorrectos:**
```
> 0
> -5000
> 1000000
```
**Solución:** Ingresar valor entre $1 y $900,000

---

### **ERROR_007: Cilindraje Inválido**
```
Mensaje: "Ingrese un cilindraje valido."
Contexto: Validación del cilindraje del motor
```
**Causa:** Cilindraje menor o igual a 0, o mayor a 110,000 cc  
**Ejemplos incorrectos:**
```
> 0
> -100
> 150000
```
**Solución:** Ingresar valor entre 1 y 110,000 cc

---

### **ERROR_008: Revisiones Técnicas Inválidas**
```
Mensaje: "Ingreso un valor no permitido"
Contexto: Validación de revisiones técnicas anuales
```
**Causa:** Número de revisiones menor a 0 o mayor a 366  
**Ejemplos incorrectos:**
```
> -1
> 400
```
**Solución:** Ingresar valor entre 0 y 366

---

## ERRORES DE AUTENTICACIÓN

### **ERROR_101: Administrador No Encontrado**
```
Mensaje: "Admin no encontrado."
Contexto: Intento de inicio de sesión
```
**Causa:** Credenciales incorrectas o administrador no existe  
**Escenarios:**
- Usuario no registrado en el sistema
- Contraseña incorrecta
- Nombre de usuario mal escrito
- Espacios extra en el nombre

**Ejemplo de log:**
```
Usuario ingresado: "Juan Perez"
Contraseña: "admin123"
Estado: FALLO - Usuario no existe en admins.txt
```

---

### **ERROR_102: Administrador Duplicado**
```
Mensaje: "El nombre ya esta registrado."
Contexto: Intento de registrar administrador existente
```
**Causa:** El nombre de administrador ya existe en el sistema  
**Ejemplo:**
```
Intento de registro: "María García"
Estado: FALLO - Nombre ya existe en admins.txt
```

---

### **ERROR_103: Contraseña Muy Corta**
```
Mensaje: "La contrasenia debe tener al menos 6 caracteres."
Contexto: Registro de nuevo administrador
```
**Causa:** Contraseña tiene menos de 6 caracteres  
**Ejemplos incorrectos:**
```
> 123
> admin
> abc12
```
**Solución:** Usar mínimo 6 caracteres

---

## ERRORES DE ARCHIVO

### **ERROR_201: Error de Apertura de Archivo**
```
Mensaje: "Error al abrir el archivo."
Contexto: Operaciones de lectura/escritura
```
**Causa Posible:**
- Permisos insuficientes
- Disco lleno
- Archivo en uso por otro programa
- Ruta inexistente

**Archivos afectados:**
- `admins.txt`
- `vehiculos_registrados.txt`
- `comprobante_[PLACA].txt`

---

### **ERROR_202: Archivo No Disponible**
```
Mensaje: "Archivo no disponible."
Contexto: Lectura de credenciales de administrador
```
**Causa:** El archivo `admins.txt` no existe o no se puede leer  
**Solución:** Verificar que el archivo existe en la carpeta del programa

---

### **ERROR_203: Error en Generación de Comprobante**
```
Mensaje: "Error al abrir el archivo para escritura."
Contexto: Generación de comprobante de matrícula
```
**Causa:** No se puede crear el archivo de comprobante  
**Posibles razones:**
- Disco lleno
- Permisos de escritura denegados
- Caracteres inválidos en nombre de archivo

---

## ERRORES DE CÁLCULO

### **ERROR_301: Desbordamiento Numérico**
```
Contexto: Cálculos de impuestos muy grandes
```
**Causa:** Valores de avalúo o cilindraje extremadamente altos  
**Ejemplo:**
```
Avalúo: $900,000
Cilindraje: 110,000 cc
Resultado: Cálculo puede exceder límites de float
```

---

### **ERROR_302: División por Cero**
```
Contexto: Cálculos internos del sistema
```
**Causa:** Errores en fórmulas matemáticas (raramente ocurre)

---

## ERRORES DE SISTEMA

### **ERROR_401: Memoria Insuficiente**
```
Mensaje: "Se alcanzo el numero maximo de registros."
Contexto: Intento de registrar más de 135 vehículos
```
**Causa:** Límite del array de registros alcanzado  
**Solución:** Guardar datos y reiniciar el programa

---

### **ERROR_402: Desbordamiento de Buffer**
```
Contexto: Entrada de datos muy larga
```
**Causa:** Entrada de texto excede el tamaño del buffer  
**Prevención:** El sistema trunca automáticamente entradas largas

---

## ERRORES DE FLUJO DEL PROGRAMA

### **ERROR_501: Opción de Menú Inválida**
```
Mensaje: "Opcion no valida.(1-5)."
Contexto: Selección de menú principal
```
**Causa:** Usuario selecciona número fuera del rango válido  
**Ejemplos:**
```
> 6
> 0
> 99
```

---

### **ERROR_502: Entrada Inválida en Menú**
```
Mensaje: "Entrada invalida. Use solo numeros (0-2)."
Contexto: Menú de administración
```
**Causa:** Usuario ingresa texto en lugar de número  
**Ejemplos:**
```
> abc
> salir
> menu
```

---

### **ERROR_503: No Hay Registros**
```
Mensaje: "No hay registros."
Contexto: Intento de calcular matrícula sin vehículos registrados
```
**Causa:** Base de datos vacía  
**Solución:** Registrar al menos un vehículo primero

---

### **ERROR_504: Vehículo No Encontrado**
```
Mensaje: "No se encontro un auto con la placa [PLACA]."
Contexto: Búsqueda o cálculo por placa
```
**Causa:** Placa buscada no existe en registros  
**Ejemplo:**
```
Placa buscada: "XYZ9999"
Estado: No encontrada en base de datos
```

---

### **ERROR_505: Nada para Guardar**
```
Mensaje: "No hay nada para guardar en un archivo"
Contexto: Intento de exportar datos sin registros
```
**Causa:** No hay vehículos registrados para exportar

---

## CÓDIGOS DE ERROR INTERNOS

### **Tabla de Códigos de Retorno**
```
Código | Significado
-------|------------
0      | Operación exitosa
1      | Error de validación
2      | Error de archivo
3      | Error de autenticación
-1     | Error general/desconocido
```

---

## EJEMPLOS DE SESIONES CON ERRORES

### **Sesión Típica con Errores de Validación:**
```
=== INICIO DE SESIÓN ===
Tiempo: 2025-07-20 14:30:15

[INPUT] Seleccione una opcion: abc
[ERROR] ERROR_502: Entrada invalida. Use solo numeros (0-2).

[INPUT] Seleccione una opcion: 2
[INPUT] Ingrese nombre: Juan
[INPUT] Ingrese contrasenia: 123
[ERROR] ERROR_101: Admin no encontrado.

[INPUT] Seleccione una opcion: 1
[INPUT] Nombre del administrador: Juan123
[ERROR] ERROR_004: Ingrese solo letras.

[INPUT] Nombre del administrador: Juan Pérez
[INPUT] Ingrese la contrasenia: 12345
[ERROR] ERROR_103: La contrasenia debe tener al menos 6 caracteres.

[INPUT] Ingrese la contrasenia: admin123
[SUCCESS] Admin guardado exitosamente.

=== FIN DE SESIÓN ===
```

### **Sesión con Errores de Registro de Vehículo:**
```
=== REGISTRO DE VEHÍCULO ===
Tiempo: 2025-07-20 15:45:30

[INPUT] Ingrese el nombre del propietario: María García
[SUCCESS] Nombre válido

[INPUT] Ingrese cedula: 123456789
[ERROR] ERROR_003: Ingrese una cedula valida (10 digitos-solo numeros).

[INPUT] Ingrese cedula: 1234567890
[SUCCESS] Cédula válida

[INPUT] Ingrese placa: abc1234
[ERROR] ERROR_002: Ingrese placa valida (ABC1234 sin guion).

[INPUT] Ingrese placa: ABC1234
[SUCCESS] Placa válida

[INPUT] Ingrese el anio: 1850
[ERROR] ERROR_005: Ingrese un anio valido 1900-2025.

[INPUT] Ingrese el anio: 2020
[SUCCESS] Año válido

[INPUT] Ingrese el avaluo: abc
[ERROR] ERROR_001: Entrada invalida. Intente nuevamente.

[INPUT] Ingrese el avaluo: 1000000
[ERROR] ERROR_006: Ingrese un avaluo valido.

[INPUT] Ingrese el avaluo: 25000
[SUCCESS] Avalúo válido

=== REGISTRO EXITOSO ===
```

---

## RECOMENDACIONES PARA DEPURACIÓN

### **1. Registro de Errores Automático**
```c
// Función sugerida para logging
void log_error(const char* error_code, const char* message) {
    FILE* log_file = fopen("error_log.txt", "a");
    if (log_file) {
        fprintf(log_file, "[%s] %s: %s\n", 
                get_timestamp(), error_code, message);
        fclose(log_file);
    }
}
```

### **2. Validación de Estado del Sistema**
- Verificar existencia de archivos antes de operaciones
- Validar rangos de memoria antes de accesos
- Confirmar estados de entrada antes de procesamiento

### **3. Manejo de Excepciones**
- Implementar verificaciones de retorno de funciones
- Manejar casos edge en validaciones
- Proporcionar mensajes de error descriptivos

---

## PREVENCIÓN DE ERRORES

### **Buenas Prácticas para Usuarios:**
1. **Leer mensajes cuidadosamente** antes de ingresar datos
2. **Seguir formatos exactos** especificados en prompts
3. **Usar caracteres ASCII** estándar
4. **Evitar espacios extra** al inicio o final de entradas
5. **Cerrar el programa correctamente** usando la opción "Salir"

### **Mantenimiento del Sistema:**
1. **Respaldar archivos** `.txt` regularmente
2. **Verificar permisos** de escritura en carpeta del programa
3. **Monitorear espacio en disco** disponible
4. **Actualizar datos** de prueba periódicamente

---

**© 2025 - Documento de Errores - Sistema de Matriculación Vehicular**
