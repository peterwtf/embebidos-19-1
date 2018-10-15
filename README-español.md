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

## RaspberryPi 3 como computadora de escritorio. 🚀

_Para este  modo  de  operación  conectamos un monitor mediante  una  cable  HDMI,  un teclado  y un ratón.  Después  conectamos  el  eliminador  y  esperamos  al  arranque  del sistema  operativo._

_Debimos configurar la interfaz de red Inalambrica (WIFI), haciendo lo siguiente._

_$  sudo  nano /etc/wpa_supplicant/wpa_supplicant.conf_

```
Especificamos el archivo para la configuración del router al que nos conectamos.
```

_network={ssid="Tenda_80AFF0"key_mgmt=NONE}_

```
Agregamos nuestro router al archivo.
```
_$  sudo  reboot_

```
Reiniciamos nuestro sistema. 
```

## RaspberryPi  3  mediante  SSH ⚙️

_Explica como ejecutar las pruebas automatizadas para este sistema_

```
Da un ejemplo
```

### Capturas de resultado 🔩

![alt tag](hostname.jpg)
![alt tag](ssh.jpg)

## RaspberryPi  3  mediante  VNC ⌨️

_Explica que verifican estas pruebas y por qué_

```
Da un ejemplo
```

### Capturas del proceso 📦

![alt tag](dev115.jpg)
![alt tag](tty0.jpg)
![alt tag](general.jpg)

## Autores ✒️📌

* **López Rivera Aiko Dallane** - *Documentación* - [MikeyMcDon](https://github.com/MikeyMcDon)
* **Maldonado Carpio Jorge Enrique** - *Documentación* - [JorgeMaldonado](https://github.com/JorgeMaldonado)


## Victor Hugo García Ortega ❤️⌨️ 

* **Profesor** [Victor Hugo García Ortega](https://github.com/vgarciaortega)
