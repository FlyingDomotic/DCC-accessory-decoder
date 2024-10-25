# Filter and decode DCC accessory messages/Filtre et décode des messages DCC de type accessoires

[English version and French version in the same document]

Reads DCC messages on rails, filter accessories ones and send them decoded on serial port.

[ Versions françaises et anglaises dans le même document]

Lit les messages DCC sur les rails, filtre les types accessoires et les envoie décodés sur le port série.

## What's for?/A quoi ça sert ?

Within "HO railway turntable project" (https://github.com/FlyingDomotic/Railway-turntable), we initially connected DCC opto coupler directly on ESP8266. This was running fine in almost all cases, but crashed MCU when using asynchronous Web server at the same time as receiving DCC messages, due to high count of interruptions to process. This was mainly due to permanent "Idle" DCC message.

In order to fix this issue, it was decided to use an external small MCU, to filter only accessories packets, and transmit them decoded on serial port, sending DCC cddress, DCC direction and DCC output power separated by a space and ended by a <CR><LF>.

Doing this allow to have a generic decoder, and to filter addresses into destination MCU, letting Arduino with general and small code.

Pendant le projet "HO railway turn table" (https://github.com/FlyingDomotic/Railway-turntable), la fonction de décodage des trames DCC a été initialement confiée à l'ESP8266 de gestion du pont tournant. Ceci fonctionnait bien dans la majorité des cas, mais plantait le MCU lorsqu'on utilisait le serveur Web pendant la réception de messages DCC, à cause du trop grand nombre d'interruptions à gérer. Ceci était dû aux messages "Idle" émis en permanence.

Pour corriger le problème, il a été décidé d'utiliser un petit MCU externe, pour filtrer les messages de type "accessoires", et les envoyer, décodés, sur le lien série, en poussant l'adresse DCC, la direction et le niveau de sortie, séparés par un espace et terminés par <CR><LF>.

## Prerequisites/Prérequis

VSCodium (or Visual Studio Code) with PlatformIO should be installed. You may also use Arduino IDE, as long as you read platformio.ini file to get the list of required libraries.

Vous devez avoir installé VSCodium (ou Visual Studio Code) avec PlatformIO. Vous pouvez également utiliser l'IDE Arduino, à condition d'extraire la liste des librairies requises indiquée dans le fichier platformio.ini.

## Installation

Follow these steps:

1. Use schema to build PCB
2. Clone repository in folder where you want to install it
```
cd <where_ever_you_want>
git clone https://github.com/FlyingDomotic/DCC-accessory-decoder DccAccessoryDecoder
```
3. Compile and load code into Arduino Nano
4. Connect opto-coupler on rails
5. You'll see accessories messages on monitor
6. Connect Arduino TX on your MCU RX and that's it!

Suivez ces étapes :

1. Utiliser le schéma pour construire le PCB
2. Cloner le répertoire là où vous souhaitez installer le code
```
cd <là où vous voulez>
git clone https://github.com/FlyingDomotic/DCC-accessory-decoder DccAccessoryDecoder
```
3. Compilez and chargez le code dans l'Arduino Nano
4. Connecter l'opto-coupleur sur les rails
5. Regarder les messages accessoires défiler sur la console
6. Connecter la pinoche TX de l'Arduino sur la pinoche RX de votre MCU et le tour est joué !