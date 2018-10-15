# INSTITUTO POLITÉCNICO NACIONAL 
# ESCUELA SUPERIOR DE CÓMPUTO 

## EMBEDDED SYSTEMS
## _Reporte RaspberryPi 3_ 

![alt tag](14643-Raspberry_Pi_3_B_-05.jpg)


### Pre-requisitos 📋

_Memoria  micro  SD  clase  10  de  almenos  8Gb_

_Cargar sistema operativo_

```
 Sistema  operativo  Raspbian  Stretch  de  4.9  Gb
```
### Instalación 🔧

_Insertamos la memoria a la computadora_

_Ejecutamos una serie de comandos para montar el Sistema Operativo_

_$  lsblk_

```
Verificamos  el  nombre  de  dispositivo  asignado  ala  memoria,  así  como  las  particiones.
```

_$  sudo  umount  /dev/sdc1_

```
Desmontamos todas las  particiones  de  nuestra  memoria  SD.
```
_$  sudo  dd  bs=4M  if=2017-11-29-raspbian-stretch.img  of=/dev/sdc  conv=sync_

```
Hacemos  la  copia  de  la  imagen  del  sistema  operativo  a  la  memoria  micro  SD.
```
_$  sync_

```
  Limpiamos  la  memoria  cache  para  desmontar  la  memoria  micro  SD
```

_Para este  modo  de  operación  conectamos un monitor mediante  una  cable  HDMI,  un teclado  y un ratón.  Después  conectamos  el  eliminador  y  esperamos  al  arranque  del sistema  operativo._

## RaspberryPi 3 como computadora de escritorio. 🚀

_Estas instrucciones te permitirán obtener una copia del proyecto en funcionamiento en tu máquina local para propósitos de desarrollo y pruebas._


## Ejecutando las pruebas ⚙️

_Explica como ejecutar las pruebas automatizadas para este sistema_

### Analice las pruebas end-to-end 🔩

_Explica que verifican estas pruebas y por qué_

```
Da un ejemplo
```

### Y las pruebas de estilo de codificación ⌨️

_Explica que verifican estas pruebas y por qué_

```
Da un ejemplo
```

## Deployment 📦

_Agrega notas adicionales sobre como hacer deploy_

## Construido con 🛠️

_Menciona las herramientas que utilizaste para crear tu proyecto_

* [Dropwizard](http://www.dropwizard.io/1.0.2/docs/) - El framework web usado
* [Maven](https://maven.apache.org/) - Manejador de dependencias
* [ROME](https://rometools.github.io/rome/) - Usado para generar RSS

## Contribuyendo 🖇️

Por favor lee el [CONTRIBUTING.md](https://gist.github.com/villanuevand/xxxxxx) para detalles de nuestro código de conducta, y el proceso para enviarnos pull requests.

## Versionado 📌

Usamos [SemVer](http://semver.org/) para el versionado. Para todas las versiones disponibles, mira los [tags en este repositorio](https://github.com/tu/proyecto/tags).

## Autores ✒️

_Menciona a todos aquellos que ayudaron a levantar el proyecto desde sus inicios_

* **Andrés Villanueva** - *Trabajo Inicial* - [villanuevand](https://github.com/villanuevand)
* **Fulanito Detal** - *Documentación* - [fulanitodetal](#fulanito-de-tal)

También puedes mirar la lista de todos los [contribuyentes](https://github.com/your/project/contributors) quíenes han participado en este proyecto. 

## Licencia 📄

Este proyecto está bajo la Licencia (Tu Licencia) - mira el archivo [LICENSE.md](LICENSE.md) para detalles

## Expresiones de Gratitud 🎁

* Comenta a otros sobre este proyecto 📢
* Invita una cerveza 🍺 a alguien del equipo. 
* Da las gracias públicamente 🤓.
* etc.



---
⌨️ con ❤️ por [Villanuevand](https://github.com/Villanuevand) 😊
