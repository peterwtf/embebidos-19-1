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

_SSH.  Secure  shell,  es  un  protocolo  de  red  que  permite  el  intercambio  de  datos  sobre  uncanal  seguro  entre  dos  computadoras._

_$  sudo  systemctl  list-unit-files_

```
Da un ejemplo
```

_$  sudo  systemctl  status  ssh_

```
Da un ejemplo
```

_$  sudo  systemctl  start  ssh_

```
Da un ejemplo
```

_$  sudo  systemctl  enable  ssh_

```
Da un ejemplo
```

_$  ifconfig_

```
Da un ejemplo
```

_$  hostname  -I_

```
Da un ejemplo
```
_$  nmap  -p22  192.168.100.0/24_

```
Da un ejemplo
```

_$  arp  -v  |  grep  da:73_

```
Da un ejemplo
```

_$  ssh pi@192.168.100.13_

```
Da un ejemplo
```

```
Da un ejemplo
```

### Capturas de resultado 🔩

![alt tag](hostname.jpg)
![alt tag](ssh.jpg)

## RaspberryPi  3  mediante  VNC ⌨️

_VNC.  Virtual  Network  Computing,  es  un  programa  de  software  libre  basado  en  unaarquitectura  cliente-servidor  que  permite  tomar  el  control  de  un  ordenador  servidorremotamente  a  través  de  un  ordenador  cliente.  También  se  denomina  software  de  escritorioremoto._

_$  sudo  systemctl  list-unit-files_

```
Da un ejemplo
```

_$  sudo  systemctl  status  vncserver-x11-serviced_

```
Da un ejemplo
```
_$  sudo  systemctl  start  vncserver-x11-serviced_

```
Da un ejemplo
```
_$  sudo  systemctl  enable  vncserver-x11-serviced_

```
Da un ejemplo
```
_$  sudo  apt-get  install  realvnc-vnc-viewer_

```
Da un ejemplo
```
## RaspberryPi  3  mediante  Consola 📌

_¿Qué  pasa  si  no  cuento  con  teclado,  monitor  y  ratón  para  usar  mi  tarjeta  Raspberry  comocomputadora  de  escritorio  y  tampoco  tengo  conexión  en  red  para  conectarme  con  SSH  o VNC?_

_Conectarnos  a  nuestra  tarjeta  Raspberry  mediante  UART_

_$  sudo  nano /boot/config.txt_

```
Da un ejemplo
```
_enable_uart=1 core_freq=250_

```
Da un ejemplo
```
_$  ls  -l  /dev/ttyUSB0_

```
Da un ejemplo
```
_$  id_

```
Da un ejemplo
```
_$  sudo  usermod  -a  -G  dialout  “$(whoami)”_

```
Da un ejemplo
```
_$  screen  /dev/ttyUSB0  115200_

```
Da un ejemplo
```
_$  sudo  reboot_

```
Da un ejemplo
```
### Capturas del proceso 📦
![alt tag](terminal.JPG)
![alt tag](dev115.jpg)
![alt tag](tty0.jpg)
![alt tag](general.jpg)

## Autores ✒️

* **López Rivera Aiko Dallane** - *Documentación* - [MikeyMcDon](https://github.com/MikeyMcDon)
* **Maldonado Carpio Jorge Enrique** - *Documentación* - [JorgeEnrique12](https://github.com/JorgeEnrique12)

## Victor Hugo García Ortega ❤️⌨️ 

* **Profesor** [Victor Hugo García Ortega](https://github.com/vgarciaortega)

