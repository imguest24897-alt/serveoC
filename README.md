# serveoC
Serveo port forwarder, ngrok alternative. powered by serveo.net.

> [!WARNING]
> This project is not owned by me. This project is a fork of milio48/serveo, and this project was rewritten on C.

```
parameter : [http/tcp] [local port] [option]

      parameter [option] : 0      = request random port
      parameter [option] : change = change http subdomain forwarded
      parameter [option] : 4869   = custom port number to forwarding (using tcp)

  http  80 0             //localhost:80 forward to public https

  tcp 4869 0             //random tcp port forwarding
  tcp 4869 1945          //custom tcp port forwarding
  ```
  
  
 ## Example
request random http subdomain
`serveo http 80 0` 
  
request change http subdomain
`serveo http 80 change` 
  
request custom port
`serveo http 80 4869` 

### Install (Linux only)
`curl https://raw.githubusercontent.com/imguest24897-alt/serveoC/master/install.sh | bash`

if u run from source, u can run with arg. but u must run in same folder with library.
