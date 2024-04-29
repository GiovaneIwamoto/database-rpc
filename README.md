# DATABASE RPC

### **INSTALLATION GUIDE**

How to run RPC Generator

`rpcgen rbd.x`

Compile Server:

`$ gcc -o rbd_server rbd_sif.c rbd_svc.c rbd_srp.c rbd_xdr.c -I/usr/include/tirpc -ltirpc`

Compile Client:

`$ gcc -o rbd_client rbd_clnt.c rbd_client.c rbd_xdr.c -I/usr/include/tirpc -ltirpc` 
 
Portmap Error init service with:

`$ /etc/init.d/portmap start`

`$ service portmap start`
  
Install Portmap:

`$ sudo apt install portmap`


In Arch Linux and Debian-based distributions, portmap has been replaced by rpcbind.

`$ sudo systemctl start rpcbind`
